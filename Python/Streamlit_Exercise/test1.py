import streamlit as st
import numpy
import pandas as pd

st.title('my first app')

@st.cache
def load_data(filename):
    df = pd.read_csv(filename)
    return df

df = load_data('crime_data.csv')
crime_list = df['crime'].unique()
crime_type = st.sidebar.selectbox(
    "Which kind of crime do you want to explore?",
    crime_list
)

loc_list = df['locname'].unique()
loc_type = st.sidebar.selectbox(
    "Where do you want to explore?",
    loc_list
)

part_df = df[(df['crime']==crime_type) & (df['locname']==loc_type)]
st.table(part_df.tail(10))
st.write(f"根据你的筛选，数据包含{len(part_df)}行")
