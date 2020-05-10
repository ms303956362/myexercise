from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from xgboost import XGBClassifier
from xgboost import plot_importance
import matplotlib.pyplot as plt

digits = datasets.load_digits()
x_train, x_test, y_train, y_test = train_test_split(digits.data, digits.target, test_size=0.3, random_state=33)
model = XGBClassifier(max_depth=6, n_estimators=1000, subsample=0.8, colsample_bytree=0.8, 
                        objective="multi:softmax", random_state=27)
model.fit(x_train, y_train, eval_set=[(x_test, y_test)], eval_metric="mlogloss", early_stopping_rounds=10)
fig, ax = plt.subplots(figsize=(15, 15))
plot_importance(model, height=0.5, ax=ax, max_num_features=64)
plt.show()

y_pred = model.predict(x_test)
ac = accuracy_score(y_test, y_pred)
print("Accuracy: {:.2f}%".format(ac*100))
