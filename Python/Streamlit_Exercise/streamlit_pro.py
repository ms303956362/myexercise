import streamlit as st
import matplotlib.pyplot as plt
import datetime

if __name__ == '__main__':
    import pandas as pd
    import numpy as np
    import altair as alt

    df = pd.DataFrame(
    np.random.randn(200, 3),
    columns = ['a', 'b', 'c'])

    c = alt.Chart(df).mark_circle().encode(
        x = 'a', y = 'b', size = 'c', color = 'c')
    st.write(c)


    df = pd.DataFrame(
       np.random.randn(10, 20),
       columns=('col %d' % i for i in range(20)))
    st.dataframe(df.style.highlight_max(axis=0))
    st.table(df)


    arr = np.random.normal(1, 1, size=100)
    plt.hist(arr, bins=20)
    st.pyplot()

    chart_data = pd.DataFrame(
    np.random.randn(20, 3),
    columns = ['a', 'b', 'c'])

    st.line_chart(chart_data)
    st.area_chart(chart_data)
    st.bar_chart(chart_data)

    '''
    # 输入部分
    '''
    '按钮'
    if st.button('Say hello'):
        st.write('Why hello there')
    else:
        st.write('Goodbye')

    '单勾选框'
    agree = st.checkbox('I agree')
    if agree:
        st.write('Great!')

    '单选框'
    sel = st.radio(
        '你喜欢什么？',
        ['糖果','盐', '蛋糕']
    )
    if sel == '糖果':
        st.write('小心糖尿病')
    elif sel == '盐':
        st.write('小心高血压')
    else:
        st.write('小心肺结核')

    # '列表复选框'
    options = st.multiselect(
        'What are your favorite colors',
        ['Yellow', 'Red', 'Green',  'Blue']
    )
    st.write('You selected:', options)


    '文本输入'
    title = st.text_input(label='Movie title', value='Life of Brian')
    st.write('The current movie title is', title)

    '数字输入'
    number = st.number_input('Insert a number', max_value=100, min_value=10, value=50)
    st.write('The current number is ', number)

    '多行文本输入'
    txt = st.text_area(label='Text to analyze',value =  '''
        It was the best of times, it was the worst of times, it was
        the age of wisdom, it was the age of foolishness, it was
        the epoch of belief, it was the epoch of incredulity, it
        was the season of Light, it was the season of Darkness, it
        was the spring of hope, it was the winter of despair, (...)
        ''')
    st.write('length:', len(txt))

    '日期输入'
    d = st.date_input(
        label='When is your birthday',
        value= datetime.date(2019, 7, 6))
    st.write('Your birthday is:', d)

    '时间输入'
    t = st.time_input('Set an alarm for', datetime.time(8, 45))
    st.write('Alarm is set for', t)

    '庆祝气球'
    st.balloons()

    '占位符'
    zw = st.empty()
    zw.text('占位符测试成功')