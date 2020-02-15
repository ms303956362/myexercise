import streamlit as st
import pandas as pd
import numpy as np

df = pd.DataFrame(np.random.randn(10, 20), 
    columns=('col %d'%i for i in range(20)))
st.dataframe(df.style.highlight_max(axis=0))
st.table(df)

st.text('first')
txt = st.empty()
chrt = st.empty()
st.text('last')
txt.text('second')
chrt.line_chart(np.random.randn(20, 2))

import time
progress_bar = st.progress(0)
progress_text = st.empty()
chart = st.line_chart(np.random.randn(1, 2))
for i in range(100):
    new_rows = np.random.randn(1, 2)
    progress_text.text('The latest random number is %s' 
        % new_rows[-1, 1])
    chart.add_rows(new_rows)
    progress_bar.progress(i + 1)
    time.sleep(0.1)
progress_text.text('Done!')
st.balloons()
