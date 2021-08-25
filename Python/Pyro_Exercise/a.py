import math
import torch
import pyro
import pyro.distributions as dist
from pyro.distributions import constraints
from pyro.optim import Adam
from pyro.infer import Trace_ELBO, SVI

def model(data):
    alpha = torch.tensor(10.0)
    beta = torch.tensor(10.0)
    f = pyro.sample('f', dist.Beta(alpha, beta))
    for i in range(len(data)):
        pyro.sample('obs_{}'.format(i), dist.Bernoulli(f), obs=data[i])

def guide(data):
    alpha = pyro.param('alpha', torch.tensor(15.0), constraint=constraints.positive)
    beta = pyro.param('beta', torch.tensor(15.0), constraint=constraints.positive)
    pyro.sample('f', dist.Beta(alpha, beta))

if __name__ == '__main__':
    data = [torch.tensor(1.0) if i < 6 else torch.tensor(0.0) for i in range(10)]
    adam_params = {'lr': 0.0005, 'betas': (0.90, 0.999)}
    optimizer = Adam(adam_params)
    svi  = SVI(model, guide, optimizer, Trace_ELBO())
    n_step = 2000
    for step in range(n_step):
        svi.step(data)
        if step % 100 == 0:
            print('.', end='')
    # grab the learned variational parameters
    alpha_q = pyro.param("alpha").item()
    beta_q = pyro.param("beta").item()

    # here we use some facts about the beta distribution
    # compute the inferred mean of the coin's fairness
    inferred_mean = alpha_q / (alpha_q + beta_q)
    # compute inferred standard deviation
    inferred_std = inferred_mean * math.sqrt(beta_q / (alpha_q * (1.0 + alpha_q + beta_q)))

    print("\nbased on the data and our prior belief, the fairness " +
        "of the coin is %.3f +- %.3f" % (inferred_mean, inferred_std))
