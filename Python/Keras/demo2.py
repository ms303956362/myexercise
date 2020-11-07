import numpy as np
from tensorflow import keras
from tensorflow.keras import layers
import utils.dnn_app_utils_v2 as dutils

train_x_orig, train_y, test_x_orig, test_y, classes = dutils.load_data()

m_train = train_x_orig.shape[0]
num_px = train_x_orig.shape[1]
m_test = test_x_orig.shape[0]

train_x_flatten = train_x_orig.reshape(train_x_orig.shape[0], -1)   # The "-1" makes reshape flatten the remaining dimensions
test_x_flatten = test_x_orig.reshape(test_x_orig.shape[0], -1)

train_x = (train_x_flatten/255).astype(np.float32)          
test_x = (test_x_flatten/255).astype(np.float32)
train_y = train_y.astype(np.float32).squeeze()
test_y = test_y.squeeze()

layers.Dense(20, activation="relu", name="layer1"),
layers.Dense(7, activation="relu", name="layer2"),
layers.Dense(5, activation="relu", name="layer3"),
layers.Dense(1, activation="sigmoid", name="layer4")