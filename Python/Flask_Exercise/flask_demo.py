import json
from flask import Flask, request


app = Flask(__name__)

# app route中的路径为本机IP:PORT后面跟的后缀
# app正式启动在main函数中，端口是可以自己设置的
# 本机运行时，对应访问127.0.0.1:5000/flask_demo
# 在服务器运行时，对应访问10.15.194.44:5000/flask_demo
@app.route('/flask_demo', methods=['GET', 'POST'])
def flask_demo():
    """
    功能：将得到的数加100返回，请下载一个postman模拟输入输出的交互过程
    输入示例：
    {
        "request_id": 1,
        "data": 10
    }
    输出示例：
    {
        "request_id": 1,
        "result": 110
    }
    """
    # 1. 输入解析部分：网页传来的请求为json形式，在此对获得的内容进行解析
    tmp = request.get_data(as_text=True)
    data = json.loads(tmp)
    request_id = data.get("request_id", "")
    data = data.get("data", None)

    # 2. 核心功能部分：利用得到的输入进行算法处理，得到结果
    if data is not None:
        result = data + 100
    else:
        result = -1

    # 3. 结果封装部分：这边理论上可以回传各种形式的数据，但建议用dict形式
    result_json = \
        {"request_id" : request_id,
         "result": result}
    return result_json

if __name__ == '__main__':
    app.run(host='0.0.0.0',port=5000)