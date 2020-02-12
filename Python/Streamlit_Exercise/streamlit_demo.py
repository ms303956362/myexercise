import streamlit as st
import pandas as pd
import numpy as np

@st.cache
def load_chart():
    chart_data = pd.DataFrame(
        np.random.randn(20, 3),
        columns=['a', 'b', 'c'])
    return chart_data
    

if __name__ == '__main__':
    # 添加标题（st.write还可以显示markdown语法）
    st.title('测试页面')

    '''
    ## 特性说明
    streamlit会自动监听改变，不需要重新跑程序，刷新网页即可；
    用引号注释的方式可以直接添加文字, 可使用markdown语法；
    '''
    '直接输入文本也是允许的的'

    '''
    ## 滑动窗口
    '''
    x = st.slider('灵敏度选择')
    st.write(x, '灵敏度参数显示：', x * x)

    '''
    ## 表格展示
    '''
    st.write("创建数据表:")
    df = pd.DataFrame({
        'first column': [1, 2, 3, 4],
        'second column': [10, 20, 30, 40]
    })
    df # 等同于st.write(df)

    '''
    ## 地图展示
    '''
    map_data = pd.DataFrame(
        np.random.randn(1000, 2) / [50, 50] + [37.76, -122.4],
        columns=['lat', 'lon'])
    st.map(map_data)

    '''
    ## 条件语句复选框
    '''
    if st.checkbox('Show dataframe'):
        chart_data = load_chart()
        st.line_chart(chart_data)  # 折线图

    '''
    ## 折线图绘制
    '''
    chart_data = load_chart()
    st.line_chart(chart_data)  # 折线图

    '''
    ## 中间列表选框
    '''
    option = st.selectbox(
        '对数据进行选择?',
        pd.Series([1,2,3,4]))
    '你选择的数字是: ', option


    '''
    ## 侧栏选框
    '''
    option = st.sidebar.selectbox(
        '对数据进行选择?',
        pd.Series([11, 12, 13, 14])
    )

    '你选择的数字是: ', option

    '''
    ## 进度展示
    '''
    'Starting a long computation...'
    import time
    # Add a placeholder
    latest_iteration = st.empty()
    bar = st.progress(0)
    for i in range(100):
        # Update the progress bar with each iteration.
        latest_iteration.text('Iteration {}'.format(i + 1))
        bar.progress(i + 1)
        time.sleep(0.1)

    '...and now we\'re done!'