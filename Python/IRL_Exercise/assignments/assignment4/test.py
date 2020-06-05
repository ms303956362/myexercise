import gym
import competitive_pong

competitive_pong.register_competitive_envs()

env_single = gym.make("cPong-v0")

env_single.observation_space  # Box(210, 160, 3)
env_single.action_space  # Discrete(3)

env_double = gym.make("cPongDouble-v0")

env_double.observation_space  # Tuple(Box(210, 160, 3), Box(210, 160, 3))
env_double.action_space  # Tuple(Discrete(3), Discrete(3))