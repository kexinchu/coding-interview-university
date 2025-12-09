"""
即使有了 Attention 和 FFN，但是现在的self-attention机制有一个关键缺陷：
   它只知道 token 之间的关系，但是它是“无序列位置信息”的，不知道“谁在前谁在后”
原始Transformer采用了一种固定的cos/sin位置编码：“Simusoidal Position Encoding”
"""

import torch
import torch.nn as nn

class PositionalEncoding(nn.Module):
    def __init__(self, d_model, dropout=0.1,max_len=4096):
        super().__init__()
        self.dropout = nn.Dropout(dropout)

        # 创建一个足够长的matrix
        self.pe = torch.zeros(max_len,d_model)
        # 位置索引： [0, 1, 2, ..., max_len-1]
        position = torch.arange(0, max_len, dtype=torch.float32).unsqueeze(1)
        # 计算每个维度对应的频率
        # div_term[0] = 10000^(2*0/d_model) = 1
        # div_term[1] = 10000^(2*1/d_model)
        # ...
        # $\frac{1}{10000^{2i/d_{model}}​} ​= e^{−log(10000)⋅2i/d_{model}}​$
        div_term = torch.exp(
            # 2i * (-log(10000.0)/d_model)
            torch.range(0, d_model, 2, dtype=torch.float32) * (-math.log(10000.0)/d_model)
        )
        # postion 奇数位置 使用 sin 编码
        self.pe[0, 0::2] = torch.sin(position * div_term)
        # postion 偶数位置 使用 cos 编码
        self.pe[0, 1::2] = torch.cos(position * div_term)

        # 将 pe 从 [max_len, d_model] 扩展为 [batch_size, max_len, d_model]
        # 适配 输入的形状 [batch_size, seq_len, d_model]
        self.pe = self.pe.unsqueeze(0)

        # register_buffer 的作用: a method in PyTorch's torch.nn.Module class
        #   - 告诉 PyTorch: 这是模型的一部分，但不是可训练参数
        #   - 会随着模型一起移动到 cuda/cpu，也会一起保存/加载
        self.register_buffer('pe', self.pe)

    def forward(self, x):
        """
        x : [batch_size, seq_len, d_model]
        """
        seq_len = x.size(1)
        # 从预先计算好的 pe 中取出 seq_len 个位置
        pos_emb = self.pe[:, :seq_len, :]

        x = x + pos_emb # 直接将位置信息加载embedding上

        return self.dropout(x) # 再做一次dropout

"""
在实际 LLM 中，position encoding 通常是作为 input embedding 的一部分，而不是单独的一个模块。
因为 position encoding 的计算是固定的，所以可以提前计算好，然后作为 input embedding 的一部分，这样就不需要每次都计算。
但是，如果需要动态计算 position encoding，那么就需要单独作为一个模块。
"""
class InputEmbedding(nn.Module):
    def __init__(self, vocab_size, d_model, dropout=0.1, max_len=4096):
        super().__init__()
        self.embedding = nn.Embedding(vocab_size, d_model)
        self.positional_encoding = PositionalEncoding(d_model, dropout, max_len)

    def forward(self, input_ids):
        x = self.embedding(input_ids)
        x = self.positional_encoding(x)
        return x
        