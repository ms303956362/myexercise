import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
import utils.dnn_app_utils_v2 as dutils #读取datasets文件夹中的数据


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

# Define Sequential model with 3 layers
model = keras.Sequential(
    [
        layers.Dense(20, activation="relu", name="layer1"),
        layers.Dense(7, activation="relu", name="layer2"),
        layers.Dense(5, activation="relu", name="layer3"),
        layers.Dense(1, activation="sigmoid", name="layer4")
    ]
)

y = model(test_x)
model.summary()

model.compile(loss=keras.losses.binary_crossentropy,
              optimizer=keras.optimizers.SGD(lr=0.01, momentum=0.9, nesterov=True), metrics= ['accuracy'])

model.fit(train_x, train_y, epochs=100)
loss_and_metrics = model.evaluate(test_x, test_y)
classes = model.predict(test_x)
