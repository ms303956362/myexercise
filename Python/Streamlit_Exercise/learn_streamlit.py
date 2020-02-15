import streamlit as st
import numpy as np
import pandas as pd
import time


@st.cache
def slow_func(a):
    time.sleep(3)
    return a

'''
# Streamlit测试
## 主要概念
Streamlit库简介
'''
a = 1
b = slow_func(a)
'b: ', b

'按钮'
btn = st.button('press me')
'滑块'
sld = st.slider('choose a number', -50, 50)
sld
'侧滑菜单'
sd_slide = st.sidebar.selectbox('select your hers', ('Tracer','Genji','Hanzo'))
'表格'
df = pd.DataFrame(np.random.rand(15, 3), columns=('a', 'b', 'c'))
df
'图表'
st.line_chart(df)
'地图'
map_data = pd.DataFrame(np.random.randn(2000, 2) / [30, 30] +  [39.90967, 116.39032], columns=['lat', 'lon'])
st.map(map_data)
'复选框'
if (st.checkbox('Show dataframe')):
    chart_data = pd.DataFrame(np.random.rand(15, 3), columns=('a', 'b', 'c'))
    st.line_chart(chart_data)
st.sidebar.markdown('选择框')
option = st.sidebar.selectbox('Which number do you like best?', (1,2,3,4,5))
'You selected: ', option
st.sidebar.warning('notice the number')
'Starting a long computation...'
import time
# Add a placeholder
latest_iteration = st.empty()
bar = st.progress(0)

for i in range(100):
  # Update the progress bar with each iteration.
  latest_iteration.text(f'Iteration {i+1}')
  bar.progress(i + 1)
  time.sleep(0.1)

'...and now we\'re done!'
