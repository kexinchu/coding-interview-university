"""
对一个批次 + 序列来说 [batch_size, seq_len, d_model]，它
- 对每一个位置 t, 单独做一个MLP; 不看其他位置，只对该token的向量做线性变换
- 注意：位置之间不共享计算

为什么要这么设计？
- Multi-Head Attention 负责在不同 token 之间“交流信息”；
- FFN 则是对每个 token 的特征做更复杂的非线性变换，提高表达能力；
- 本质上：Attention = 把信息混在一起，FFN = 对混合后的表示做非线性变换。
"""
import torch.nn as nn

class PositionwiseFeedForward(nn.Module):
    def __init__(self, d_model, d_ff, dropout=0.1):
        super().__init__()
        # 将每个token的表示从 d_model 提升到更高维度的隐空间 d_ff
        self.linear1 = nn.Linear(d_model, d_ff)
        self.linear2 = nn.Linear(d_ff, d_model)
        self.dropout = nn.Dropout(dropout)
        self.activation = nn.ReLU()

    def forward(self, x):
        """[batch_size, seq_len, d_model]"""
        x = self.linear1(x)
        # 引入非线性，否则两个线性层叠起来仍然等价于一个线性变化，表达力不会增强
        # 这里使用ReLU，后面的GPT/BERT模型中进场用GeLU
        x = self.activation(x) 
        x = self.dropout(x) # 随机失活，防止过拟合
        x = self.linear2(x)

        return x