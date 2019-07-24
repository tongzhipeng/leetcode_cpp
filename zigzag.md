```flow
st=>start: 开始
e=>end
init_row_and_colum=>operation: 初始化行列号
cond_iter_string=>condition: 遍历字符串
cond_column_value=>condition: 判断列号

cond_iter_string(no)->e
cond_iter_string(yes)

st->init_row_and_colum->cond_iter_string


```