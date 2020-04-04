import dgl
import h5py
import torch
import torch.optim as optim
import torch.nn as nn
import torch.nn.functional as F
from dgl.nn.pytorch import GraphConv
from torch.utils.data import DataLoader, Dataset
from pypower.api import case24_ieee_rts
from pypower.idx_brch import F_BUS, T_BUS


class RTSDataset(Dataset):
    def __init__(self, ppc, filepath):
        self.graphs = []
        self.labels = []
        src = ppc['branch'][:, F_BUS] - 1
        dst = ppc['branch'][:, T_BUS] - 1
        g2b = ppc['gen'][:, 0] - 1
        with h5py.File(filepath, 'r') as f :
            m = f['bus'].shape[0]
            n_bus = f['bus'].shape[1]
            n_gen = f['gen'].shape[1]
            # 同一节点发电机出力求和
            gen2bus = torch.tensor(g2b, dtype=torch.long).reshape((-1, 1))
            gen2bus_matrix = torch.zeros(n_gen, n_bus, dtype=torch.float).scatter(1, gen2bus, 1.0)
            pg_bus = torch.matmul(torch.tensor(f["gen"][:, :, 0], dtype=torch.float), gen2bus_matrix)
            qg_bus = torch.matmul(torch.tensor(f["gen"][:, :, 1], dtype=torch.float), gen2bus_matrix)
            for i in range(m):
                graph = dgl.DGLGraph()
                graph.add_nodes(n_bus)  # 添加节点
                graph.add_edges(src, dst)  # 添加边
                graph.add_edges(dst, src) 
                pd = torch.tensor(f["bus"][i, :, 0], dtype=torch.float).reshape((-1, 1))
                qd = torch.tensor(f["bus"][i, :, 1], dtype=torch.float).reshape((-1, 1))
                vm = torch.tensor(f["bus"][i, :, 2], dtype=torch.float).reshape((-1, 1))
                va = torch.tensor(f["bus"][i, :, 3], dtype=torch.float).reshape((-1, 1))
                pg = pg_bus[i, :].reshape((-1, 1))
                qg = qg_bus[i, :].reshape((-1, 1))
                graph.ndata['x'] = torch.cat([pd, qd, vm, va, pg, qg], dim=1)
                self.graphs.append(graph)
                self.labels.append(f["risk"][i])
    
    def __len__(self):
        return len(self.labels)
    
    def __getitem__(self, idx):
        return self.graphs[idx], self.labels[idx]


def collate(samples):
    # The input `samples` is a list of pairs
    #  (graph, label).
    graphs, labels = map(list, zip(*samples))
    batched_graph = dgl.batch(graphs)
    return batched_graph, torch.tensor(labels)


class GCN(nn.Module):
    def __init__(self, in_dim, hidden_dim, out_dim):
        super(GCN, self).__init__()
        self.conv1 = GraphConv(in_dim, hidden_dim)
        self.conv2 = GraphConv(hidden_dim, hidden_dim)
        self.linear = nn.Linear(hidden_dim, out_dim)

    def forward(self, g):
        h = g.ndata['x']
        # Perform graph convolution and activation function.
        h = F.relu(self.conv1(g, h))
        h = F.relu(self.conv2(g, h))
        g.ndata['h'] = h
        # Calculate graph representation by averaging all the node representations.
        hg = dgl.mean_nodes(g, 'h')
        return F.relu(self.linear(hg))


if __name__ == "__main__":
    learning_rate = 0.01
    batch_size = 150
    num_epoches = 200
    input_size = 6
    output_size = 1
    hidden_size = 20

    # 载入电网模型
    ppc = case24_ieee_rts()
    dataset = RTSDataset(ppc, 'case24RTS_train.h5')
    data_loader = DataLoader(dataset, batch_size=batch_size, shuffle=True, collate_fn=collate)

    # Create model
    device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
    model = GCN(input_size, hidden_size, output_size)
    if torch.cuda.device_count() > 1:
        print("Let's use", torch.cuda.device_count(), "GPUs!")
        model = nn.DataParallel(model)
    model.to(device)
    loss_func = nn.MSELoss()
    optimizer = optim.Adam(model.parameters(), lr=learning_rate)
    model.train()

    epoch_losses = []
    for epoch in range(num_epoches):
        epoch_loss = 0
        for i, (bg, label) in enumerate(data_loader):
            bg = bg.to(device)
            label = label.reshape((-1,1)).to(device)
            prediction = model(bg)
            loss = loss_func(prediction, label)
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()
            epoch_loss += loss.detach().item()
        epoch_loss /= (i + 1)
        if (epoch + 1) % 10 == 0:
            print('Epoch {}, loss {:.4f}'.format(epoch + 1, epoch_loss))
        epoch_losses.append(epoch_loss)
