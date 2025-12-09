# Multi-Head Attention 为什么有效？（原理 + 数学结构 + 维度变化）

## 1. Self-Attention 的核心目标
- Self-Attention 的作用是：
    - 让序列中每个位置的 token **根据上下文动态选择要关注的其他 token**；
    - 每个注意力分数代表 token 与 token 之间的 **关系（similarity）**；
    - 让模型可以自动学习“依赖结构”，而不是人工设计窗口或CNN卷积核大小。

- MHA的基础是Scaled Dot-Product Attention：
$$
\text{Attention}(Q, K, V) = \text{softmax}\left(\frac{QK^T}{\sqrt{d_k}}\right)V
$$

- 这是一个kernel method
$$
\alpha(Q, K) = \text{softmax}\left(\frac{QK^T}{\sqrt{d_k}}\right)
$$

- 实际上是学习一个：
    - token 与 token 之间的相似度函数（similarity kernel）
    - 让模型在生成新token时，自动从 context 中选择所需的信息

#### 补充：为什么需要Query，Key，Value
- Attention的目标是让 model 自己从 context 中选择所需的信息；如何实现这种“选择”呢？
    - 构造一个 search 过程： $$QK^T * V$$
- 从原理角度，Q/K/V 在search过程中承担着不同的数学角色：

    | 向量            | 数学含义             | 为什么需要           |
    | ------------- | -------------------- | -------------------- |
    | **Q (Query)** | 当前 token 的“检索需求” | 表示“我要找什么信息”     |
    | **K (Key)**   | 所有 token 的“内容标签” | 表示“当前token包含什么信息可被检索” |
    | **V (Value)** | 每个 token 最终输出的语义内容  | 真正被混合、加权、输出的特征  |

- 如果没有 Q/K 分离(比如使用 $X*X^T$), 只能够得到
    - 固定的similarity，即所有token都按照相同的方式被关注，无法满足“不同token想关注不同方面”的设计
- Q/K/V分离允许：
    - **Query 决定关注方向，Key 决定被匹配的内容，Value 决定被提取的内容**
    - 本质上是一个 可学习 的检索系统

---

## 2. 为什么要用 Multi-Head Attention？
- 单一 Attention head有局限：只有一个“关系空间”，只能学习到**一种类型的关系**（例如语义相关、位置相关、实体相关等）。

- 但语言中存在多种关系：
    - 语法：主谓关系、依存关系
    - 语义：核心词语义对齐
    - 指代：pronoun → entity
    - 位置/距离：near/far dependency
    - 风格/模式：情绪、槽位信息等

- Multi-Head Attention **每个attention head学习不同子空间中的注意力关系** 
    - 每个head 通过 $W_q/W_k/W_v$ 投影到不同的“关系空间”
    $$
    Q_i ​= XW_{Q_i}​​
    K_i​=XW_{K_i}​
    V_i​=XW_{V_i}​​
    $$


- Multi-Head Attention 的核心思想：  
$$
\text{head}_i = \text{Attention}(Q_i, K_i, V_i)
$$
$$
\text{MHA}(Q,K,V)=\text{Concat}(\text{head}_1, \dots, \text{head}_h)W^O
$$


- 为什么需要 W_o（输出线性变换）？
    - 每个 attention head 输出的 value 是在自己的子空间中学习的，多头拼接后：$Concat(head_1, ..., head_h)$ 得到的vector不一定与原 d_model 空间一致。
    - 所以必须再map回模型空间：$Output = Concat(heads)W_o$
    - $W_o$的作用就是将 multi-head 的结果投影回 Transformer 的主特征空间


## 3. 一句话总结 Multi-Head Attention

> Multi-Head Attention 之所以有效，是因为它学习了一种可微分的、数据驱动的检索机制。Q/K/V 投影让模型能在多个不同的抽象子空间内建立语义匹配关系；multi-head 使模型能从不同特征角度并行捕获复杂模式；W_o 让多头结果重新整合回统一的语义空间；维度分解保证了表达能力与计算效率之间的最佳平衡。


## 4. Positional Encoding 位置编码
- 即使有了 Attention 和 FFN，但是现在的self-attention机制有一个关键缺陷：
    - 它只知道 token 之间的关系，但是它是“无序列位置信息”的，不知道“谁在前谁在后”

- 原始Transformer采用了一种固定的cos/sin位置编码：**Simusoidal Position Encoding**; 对每个位置 $pos$ 和维度 $i$ 定义: 
$$
\text{PE}_{(pos, 2i)} = sin\left(\frac{pos}{10000^{2i/d_{model}}}\right)
$$
$$
\text{PE}_{(pos, 2i+1)} = cos\left(\frac{pos}{10000^{2i/d_{model}}}\right)
$$
    - 其中：$pos$ 是位置索引 (0, 1, 2, ..., max_len-1)
    - $i$ 是 channel 维度索引
    - $10000^{2i/d_{model}}$ 是控制不同维度使用不同频率的正弦/余弦波

- 为什么要这么复杂？
    - 多频率编码
        - 低维通道对应长周期（低频），高维通道对应短周期（高频）。
        - 这样，一个位置的编码是不同频率正弦波的“叠加”，能唯一区分大量位置。
    - 相对位置信息可由线性组合表示
        - 因为 sin/cos 有性质：$sin(a+b),cos(a+b)$ 可以用 $sin(a),cos(a),sin(b),cos(b)$ 的线性组合表示；
        - 这意味着模型可以在一定程度上通过线性操作“推理”出相对位置关系。
    - 不需要学习参数
        - 固定的编码，不需要额外训练；
        - 模型可以推到比训练时更长的序列（只要你提前生成足够长的编码），外推性还不错。