import h5py
import time
import numpy as np
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import GridSearchCV
from sklearn.ensemble import GradientBoostingRegressor as Reg
# from xgboost import XGBRegressor
# from lightgbm import LGBMRegressor
import matplotlib.pyplot as plt


def load_h5_data(filename):
    f = h5py.File(filename, "r")
    pd = np.array(f["bus"][:, :, 0])
    qd = np.array(f["bus"][:, :, 1])
    vm = np.array(f["bus"][:, :, 2])
    va = np.array(f["bus"][:, :, 3])
    pg = np.array(f["gen"][:, :, 0])
    qg = np.array(f["gen"][:, :, 1])
    pf = np.array(f["branch"][:, :, 0])
    qf = np.array(f["branch"][:, :, 1])
    x = np.concatenate((pd, qd, vm, va, pg, qg, pf, qf), axis=1)
    # x = np.concatenate((bus_data, gen_data, br_data), axis=1)
    y = np.array(f["risk"])
    f.close()
    return x, y

# 读取数据
x_train, y_train = load_h5_data("case24RTS_train.h5")
x_eval, y_eval = load_h5_data("case24RTS_eval.h5")

# 训练模型
# params = {'learning_rate': 0.1, 'n_estimators': 1000, 'max_depth': 6, 'min_child_weight': 1, 'seed': 0,
#                 'subsample': 0.8, 'colsample_bytree': 0.8, 'gamma': 0, 'reg_alpha': 0, 'reg_lambda': 1, 
#                 'objective': 'reg:squarederror'}
# model = SVR(**params)
model = Reg()
t1 = time.time()
model.fit(x_train, y_train)
t2 = time.time()
print("Training time cost: " + str(t2-t1))

# 测试
y_pred_train = model.predict(x_train)
t1 = time.time()
y_pred_eval = model.predict(x_eval)
t2 = time.time()
print("Evaluation time cost: " + str(t2-t1))
train_error = mean_absolute_error(y_train, y_pred_train)
eval_error = mean_absolute_error(y_eval, y_pred_eval)
print("Train error: {:.2f}, eval error: {:.2f}".format(train_error, eval_error))

# 作图
plt.rcParams['font.sans-serif'] = ['STSong']
plt.figure()
pd_sum_eval = np.sum(x_eval[:, 0:24], axis=1)
plt.scatter(pd_sum_eval, y_eval, label='实际值')
plt.scatter(pd_sum_eval, y_pred_eval, label='模型评估值')
plt.legend(prop={'family': 'STSong', 'size': 20})
plt.tick_params(labelsize=20)
plt.xlabel('系统总负荷 / MW', fontsize=20)
plt.ylabel('最小失负荷期望 / MW', fontsize=20)

plt.figure()
pd_sum_train = np.sum(x_train[:, 0:24], axis=1)
plt.scatter(pd_sum_train, y_train, label='实际值')
plt.scatter(pd_sum_train, y_pred_train, label='模型评估值')
plt.legend(prop={'family': 'STSong', 'size': 20})
plt.tick_params(labelsize=20)
plt.xlabel('系统总负荷 / MW', fontsize=20)
plt.ylabel('最小失负荷期望 / MW', fontsize=20)
plt.show()
