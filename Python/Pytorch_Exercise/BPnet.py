import torch
import torch.nn as nn
import torch.nn.functional as F

import numpy as np
import utils.dnn_app_utils_v2 as dutils #读取datasets文件夹中的数据

class BPnet_Cat_simple(nn.Module):
    def __init__(self, input_size):
        super(BPnet_Cat_simple, self).__init__()
        self.fc1 = nn.Linear(input_size, 20)
        self.fc2 = nn.Linear(20,7)
        self.fc3 = nn.Linear(7,5)
        self.fc4 = nn.Linear(5,1)
    
    def forward(self, x):
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = F.relu(self.fc3(x))
        x = torch.sigmoid(self.fc4(x))
        return x

if __name__ == "__main__":
    # 超参数
    num_epochs = 2500
    learning_rate = 0.0075

    # 加载数据
    train_x_orig, train_y, test_x_orig, test_y, classes = dutils.load_data()
    # 样本集和测试集参数
    m_train = train_x_orig.shape[0]
    num_px = train_x_orig.shape[1]
    m_test = test_x_orig.shape[0]
    # 重新整形数组
    train_x_flatten = train_x_orig.reshape(train_x_orig.shape[0], -1)   # The "-1" makes reshape flatten the remaining dimensions
    test_x_flatten = test_x_orig.reshape(test_x_orig.shape[0], -1)
    # 归一化为0-1之间，
    train_x = (train_x_flatten/255).astype(np.float32)          #TODO 输入化为float32
    test_x = (test_x_flatten/255).astype(np.float32)
    train_y = train_y.astype(np.float32)                        #TODO 输出也要化为float32
    # ndarray转化为tensor
    train_inputs = torch.from_numpy(train_x)
    train_labels = torch.from_numpy(train_y)
    test_inputs = torch.from_numpy(test_x)
    test_labels = torch.from_numpy(test_y)

    # 加载模型
    model = BPnet_Cat_simple(num_px*num_px*3)

    # 损失函数
    criterion = nn.BCELoss()

    # 梯度下降
    optimizer = torch.optim.SGD(model.parameters(), lr=learning_rate)   #TODO model.parameters()是方法! 不是属性

    #训练模型
    for epochs in range(num_epochs):
        # 前向传播
        prediction = model(train_inputs)                    #TODO 不用调用forward
        loss = criterion(prediction, train_labels)

        #反向传播
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        # 每迭代100次
        if (epochs+1) % 100 == 0:
            print('Epochs: ' + str(epochs+1) +'/'+ str(num_epochs) + ', Loss: ' + str(loss.item()))
    
    # 测试模型
    with torch.no_grad():
        correct = 0
        for i in range(m_test):
            pred = model(test_inputs[i])
            pred_test = 0
            if pred[0] > 0.5:
                pred_test = 1
            if pred_test == test_y[0][i]:
                correct += 1
        print('Accuracy: '+str(correct/m_test))
