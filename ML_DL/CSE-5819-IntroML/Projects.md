- Please note that the papers provided are only the references as well as inspirations for you to think about your research project topics. Please think about what problem you want to study, what methods you plan to use, and whether the project can be done within one semesters.  Please do not hesitate to contact me if you have any questions. 


### Localised Adaptive Spatial-Temporal Graph Neural Network
Conference: ACM KDD 2023
Authers: Wenying Duan, Xiaoxi He, Zimu Zhou, Lothar Thiele, Hong Rao
Paper Link：https://dl.acm.org/doi/pdf/10.1145/3580305.3599418
中文博客： https://blog.csdn.net/m0_55333280/article/details/140473993

#### Key Point
- This paper focus on: 能否以及在多大程度上对时空图模型进行局部化，并且将研究领域集中到ASTGNNs上
- 为什么要研究时空图模型的局部化呢？
    - 更深入的理解数据中的时间，空间依赖性：如果说局部化导致精度下降，则说明空间依赖性所提供的信息已经在很大程度上和时间依赖性重叠了，说明对于推理而言已经不必要了
    - 设计资源搞笑的ASTGNNs： 因为空间图的大小随着顶点的数量呈二次方增长，所以ASTGNN的计算量很大，使用局部化可以减少时空图模型的资源需求
    - 时空模型的分布式部署：传统的时空图模型预测依赖传感器节点之间的数据交换，使用局部化，可以是各个传感器节点能够完成自主预测而无需彼此通信，能节省带宽并保护分布式系统中的隐私。

- 作者发现： 在推理过程中可以很大程度上忽略空间依赖性而不会降低准确性，因为空间依赖性提供的信息主要包含在时间依赖性中；然而空间依赖性对于ASTGNN的有效训练至关重要，在训练过程中不能被忽略。

##### Basic Informations
- Spatial-temporal data: 既有时间，也有空间的数据，如城市中的交通流量，人流量，地铁乘客量等
- ASTGNNs： 
    - ASTGNNs通常使用 自适应图卷积层 来对空间依赖性进行建模，通过学习图邻接矩阵来捕获空间依赖性；
    - 因此，ASTGNNs的局部化是通过邻接矩阵（仅捕获空间依赖性）的稀疏化来实现的，这也可以理解成空间图中的剪枝

### MSGNet: Learning Multi-Scale Inter-series Correlations for Multivariate Time Series Forecasting
Conference: AAAI, 2024
Authors: Wanlin Cai, Yuxuan Liang, Xianggen Liu, Jianshuai Feng, Yuankai Wu


### A Reinforcement Learning Framework for Explainable Recommendation
Conference: ICDM 2018.
Authers: Xiting Wang, Yiru Chen, Jie Yang, Le Wu, Zhengtao Wu, and Xing Xie
中文解析：https://blog.csdn.net/qq_38871942/article/details/104696124

##### Key Point
针对个性化推荐，基于知识图谱进行推理的方法主要有两大类：利用知识图谱的embedding模型 或者 基于路径(path-based)的推荐