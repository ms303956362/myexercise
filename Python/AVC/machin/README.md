# Autonomous Voltage Control Using Reinforcement Learning

## Description
This project is a demo that shows how to use multi-agent reinforcement learning algorithm to control the voltage in power system. Power system is divided into specific number of areas and each area is assigned to an agent. The agent in each area observes the active power, reactive power, volatage magnitude, and voltage phase of the buses in the area and adjusts the voltage magnitude of the generators in the area to maintain the voltage magnitude  of each bus within 0.95 to 1.05.   
The power system environment is implemented by using `pypower` and `gym`. The reinforment learning algorithm and deep nerual network model is implemented by using `machin` based on `pytorch`.  

## Structure
`./powerenv.py`: The power system environment.  
`./voltage_controller.py`: autonomous voltage control using MADDPG algorithm.

## Dependencies
Quoted from the github repo of [Machin](https://github.com/iffiX/machin)
>Machin is hosted on PyPI. Python >= 3.5 and PyTorch >= 1.5.0 is required. You may install the Machin library by simply typing
>```bash
>pip install machin
>```
>You are suggested to create a virtual environment first if you are using conda to manage your environments, to prevent PIP changes your packages without letting conda know.
>```
>conda create -n some_env pip
>conda activate some_env
>pip install machin
>```

## Usage 
Firstly, define `Actor` and `Critic` Class, and pass the state and action dimemsion to the class to create model.
```python
class Actor(nn.Module):
    def __init__(self, state_dim, action_dim):
        super(Actor, self).__init__()
        ...

    def forward(self, state):
        ...

class Critic(nn.Module):
    def __init__(self, state_dim, action_dim):
        super(Actor, self).__init__()
        ...

    def forward(self, state):
        ...
```
Then, create `pypower` powernet standard case model and the buses and generators numbers controlled by each agent.
```python
    # powernet environement configuration
    ppc = case...()
    # the number of buses controled by each agent
    agentBuses = [
        [...],
        [...],
        ...
    ] # numbers of bus start from 0
    
    # the number of generators controled by each agent
    agentGens = [
        [...],
        [...],
        ...
    ]
```
Finally, pass the pypower case model and agent infomation to the `VoltageController` class, and use `train` function to train the model.

```python
vc = VoltageController(ppc, agentBuses, agentGens, Actor, Critic)
vc.train()
```

