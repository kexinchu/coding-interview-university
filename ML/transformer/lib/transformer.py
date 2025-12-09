"""
基于pytorch的transformer实现
study the details of transformer architecture
Scaled Dot-Product Attention & Multi-Head Attention

Attention(Q,K,V)=softmax(QK^T / sqrt(d_k) + mask)V

解释：
QK^T: 每个 query 向量和所有 key 做点积，点积大 → 方向相近 → 相似度高 → 说明 query 更“关注”这个 key。这样就得到一个 相似度矩阵，形状是 [L_q, L_k]。
/sqrt(d_k): 缩放因子，防止点积过大，导致 softmax 非常“尖”，梯度容易消失。（=归一化）
softmax: 把相似度变成一个概率分布：每个 query 对所有 key 的注意力权重和为 1。这样可以解释为“对每个 query，注意力是一个在所有 token 上的加权平均”。
*V: 用注意力权重对 value 向量做加权求和，得到对 query 的“上下文表示”。
mask(可选): 对 padding 的位置、或对未来 token（在 decoder 里）做遮挡，使这些位置的权重变成 0。实现上通常把 mask 的禁止位置加上一个很大的负数（例如 -1e9），经过 softmax 就接近 0。
"""
import math
import torch
import torch.nn as nn



class ScaledDotProductAttention(nn.Module):
    def __inti__(self, dropout=0.1):
        super().__init__() ## 调用父类的属性和方法
        self.dropout = nn.Dropout(dropout)

        """
        dropout: 丢弃概率 p
        self.dropout(input: Tensot, p, training=self.training, inplace=False):
        training: 是否在训练模式下进行丢弃
        _VF.dropout_(input, p, training) if inplace else _VF.dropout(input, p, training)
        路由到 at::native::dropout (CPU C++ / CUDA实现)
            aten/src/ATen/native/Dropout.cpp
            aten/src/ATen/native/cuda/Dropout.cu

        C++ version:
        Tensor dropout_cpu(const Tensor& input: Tensor, double p: float, bool train: bool) -> Tensor:
            if (!train) {
                return input;
            }
            // 随机bernoulli掩码
            auto mask = at::bernoulli(input.sizes(), 1 - p);
            auto output = input * mask;
            output = output / (1 - p); 
            return output;
        }
        """

    def forward(self, Q, K, V, mask=None):
        """
        QKV: [batch_size, n_heads, seq_len, d_k]
        mask: [batch_size, 1, 1, seq_len]
        """
        d_k = q.shape[-1]

        # calculate dot
        scores = torch.matmul(Q, K.transpose(-2, -1)) / math.sqrt(d_k)
        """
        torch.matmul 入口在 Python，但真正的核心实现全部在 C++。
        流程如下：

        torch.matmul:
            ↓
        aten::matmul (C++ API)
            ↓
        Dispatcher 根据张量类型选择后端：
            CPU → MKL/OpenBLAS（gemm/gemv/...）
            CUDA → cuBLAS（cublasSgemm/cublasGemmEx/...）
            GPU(batched) → cuBLAS batched kernels
            broadcasting → 内部 expand + reshape + 调整 strides


        关键：
        PyTorch 并不是自己写矩阵乘，而是高度依赖成熟的 BLAS/cuBLAS 库。
        而且matmul 不是单一操作，而是一组规则：

        输入形状	实际操作
        2D x 2D	普通矩阵乘 gemm
        1D x 1D	内积 dot
        1D x 2D	几何意义：向量视为 (1×N)
        2D x 1D	几何意义：向量视为 (N×1)
        >2D	broadcasting → batched gemm
        """

        if mask is not None:
            # mask == 0 的位置被设置为一个很小的值
            scores = scores.masked_full(mask == 0, float('-inf'))

        # softmax attention
        attention = nn.funtional.softmax(scores, dim=-1)

        # dropout
        attention = self.dropout(attention)

        # mul V
        output = torch.matmul(attention, V)

        return output, attention
"""
单头注意力：每个 token 用一个 d_model 维的向量表示，做注意力；
多头注意力：我们把 d_model 切分成 n_heads 份，每份维度是 d_k = d_model / n_heads，然后：
    - 用不同的线性变换，把输入 𝑋 映射到每个头的 𝑄𝑖, 𝐾𝑖, 𝑉𝑖；
    - 每个头独立地做 Scaled Dot-Product Attention；
    - 把所有头的输出在最后一维拼起来（concatenate），再乘一个线性层 W_o 合并成 d_model 维。
为什么要多头？
    多头 = 多个子空间上的注意力，不同的头可以学习到不同的“关系模式”：有的头关注局部邻近词，有的头捕捉长距离依赖，有的头关注语法结构/实体等
"""
class MultiHeadAttention(nn.Module):
    def __init__(self, d_model, n_heads,dropout=0.1):
        super().__init__()
        assert d_model % n_heads == 0, "d_model must be divisible by n_heads"

        self.d_model = d_model
        self.n_heads = n_heads
        self.d_k = d_model // n_heads

        # q,k,v
        self.w_q = nn.Linear(d_model, d_model)
        self.w_k = nn.Linear(d_model, d_model)
        self.w_v = nn.Linear(d_model, d_model)

        self.w_o = nn.Linear(d_model, d_model)

        self.attention = ScaledDotProductAttention(dropout)
        self.dropout = nn.Dropout(dropout)

    def forward(self, query, key, value, mask=None):
        """
        query, key, value: [batch_size, seq_len, d_model]
        mask: [batch_size, 1, 1, seq_len]
        """
        batch_size = query.size(0)

        # 1, 线性映射 Q， K， V
        Q = self.w_q(query)
        K = self.w_k(key)
        V = self.w_v(value)
        
        Q = split_heads(Q) # [batch_size, n_heads, seq_len, d_k]
        K = split_heads(K)
        V = split_heads(V)

        # attention
        context, attention = self.attention(Q, K, V, mask)
        # context: [batch_size, n_heads, seq_len, d_k]

        # merge multi-head
        context = concat_heads(context)

        output = self.w_o(context)
        output = self.dropout(output)

        return output, attention

# 2, 拆分成多头, d_model -> n_heads * d_k
def split_heads(x):
    # [batch_size, seq_len, d_model] -> [batch_size, seq_len, n_heads, d_k]
    # [batch_size, seq_len, n_heads, d_k] -> [batch_size, n_heads, seq_len, d_k]
    return x.view(batch_size, -1, self.n_heads, self.d_k).transpose(1,2)

# 5. merge multi-head: [B, H, L, d_k] -> [B, L, H, d_k] -> [B, L, d_model]
def comcat_heads(x):
    # exchange L and H 
    x = x.transpose(1, 2)  # [B, L, H, d_k]
    # 再合并最后两维：H * d_k = d_model
    return x.contiguous().view(batch_size, -1, self.d_model)