import torch
import torch.nn as nn

from position_encoding import InputEmbedding
from ffn import PositionwiseFeedForward
from attention import MultiHeadAttention


class EncoderLayer(nn.Module):
    def __init__(self, d_model, num_heads, d_ff, dropout=0.1):
        super().__init__()

        self.attention = MultiHeadAttention(d_model, num_heads, dropout)
        self.ffn = PositionwiseFeedForward(d_model, d_ff, dropout)
        
        # 每个子层前一个 LN，确保输入分布稳定。
        self.norm1 = nn.LayerNorm(d_model)
        self.norm2 = nn.LayerNorm(d_model)

        # 用于残差连接
        self.dropout1 = nn.Dropout(dropout)
        self.dropout2 = nn.Dropout(dropout)

    def forward(self, x, src_mask=None):
        # self-attention
        # Pre_LN
        x_norm = self.norm1(x)
        # Q=K=V=x_norm, 因为是self-attention
        attn_output, _ = self.attention(x_norm, x_norm, x_norm, mask=src_mask)
        # 残差连接
        x = x + self.dropout1(attn_output)

        x_norm = self.norm2(x)
        ffn_output = self.ffn(x_norm)
        x = x + self.dropout2(ffn_output)

        return x


class Encoder(nn.Module):
    def __init__(
        self, vocab_size, d_model, num_heads, d_ff, num_layers, dropout=0.1,
        max_length=4096, padding_idx=0,
    ):
        super().__init__()

        # 1. 词嵌入：把token id 转换为 d_model 维度的向量
        self.tokenizer = InputEmbedding(vocab_size, d_model, dropout, max_length)

        self.layers = nn.ModuleList(
            [EncoderLayer(d_model, num_heads, d_ff, dropout) for _ in range(num_layers)]
        )

        self.norm = nn.LayerNorm(d_model)
        self.d_model = d_model
        self.padding_idx = padding_idx

    def make_src_mask(self, src):
        """
        src: [batch_size, seq_len] token_ids
        return: [batch_size, 1, 1, seq_len]
        约定 padding_idx 位置的 token 不参与注意力计算(mask=0)
        """
        mask = (src != self.padding_idx).unsqueeze(1).unsqueeze(2)
        return mask


    def forward(self, src):
        # 构造mask
        src_mask = self.make_src_mask(src)
        # 词嵌入
        #     乘上 sqrt(d_model) 进行缩放，因为 d_model 是词嵌入的维度，而词嵌入的维度是 d_model，
        #     所以需要乘上 sqrt(d_model) 进行缩放。
        x = self.tokenizer(src) * math.sqrt(self.d_model)

        for layer in self.layers:
            x = layer(x, src_mask)

        x = self.norm(x)

        return x, src_mask