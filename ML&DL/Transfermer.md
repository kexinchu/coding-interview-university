## QKV分别指的是啥？
当输入token被记作X, 那么QKV分别通过以下方式计算得到
- 
Q = W_Q * X: 表示查询向量
K = W_K * X: 表示被查询信息V 与 所有其他信息之间的相关性，也是向量表示的
V = W_V * X: 表示被查询信息的向量

=> Attention函数表示：
    在高维空间中，Q，K，V都是点；此时Attention表示：如果Q和V之间有关系, 那么就让Q向着V所在的方向靠近一点; 靠近多少由Q和K做内积来决定.


https://www.zhihu.com/question/325839123/answer/2473804749