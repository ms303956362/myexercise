from LAC import LAC

# 装载LAC模型
lac = LAC(mode='lac')

# 单个样本输入，输入为Unicode编码的字符串
text = u"玉泉变1号主变因雷击过电流保护动作切断发生停运"
lac_result = lac.run(text)
print(lac_result)

# 批量样本输入, 输入为多个句子组成的list，平均速率更快
texts = [u"LAC是个优秀的分词工具", u"百度是一家高科技公司"]
lac_result = lac.run(texts)
print(lac_result)
