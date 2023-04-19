## 当你获得了梦想的职位

恭喜你！

继续学习。

活到老，学到老。

---

    *****************************************************************************************************
    *****************************************************************************************************

    下面的内容都是可选的。
    通过学习这些内容，你将会得到更多的有关 CS 的概念，并将为所有的软件工程工作做更好的准备。你将会成为一个更全面的软件工程师。

    *****************************************************************************************************
    *****************************************************************************************************

---

- [额外书籍](#额外书籍)
- [附加学习](#附加学习)
    - [编译器](#编译器)
    - [Emacs and vi(m)](#emacs-and-vim)
    - [Unix 命令行工具](#unix-命令行工具)
    - [信息论](#信息论-视频)
    - [奇偶校验位 & 汉明码 (视频)](#奇偶校验位--汉明码-视频)
    - [系统熵值](#系统熵值Entropy)
    - [密码学](#密码学)
    - [压缩](#压缩)
    - [计算机安全](#计算机安全)
    - [垃圾回收](#垃圾回收)
    - [并行编程](#并行编程)
    - [消息传递，序列化和队列化的系统](#消息传递序列化和队列系统)
    - [A*搜索算法](#A搜索算法)
    - [快速傅里叶变换](#快速傅里叶变换)
    - [布隆过滤器](#布隆过滤器)
    - [HyperLogLog](#HyperLogLog)
    - [局部敏感哈希](#局部敏感哈希)
    - [van Emde Boas 树](#van-emde-boas-树)
    - [增强数据结构](#增强数据结构)
    - [平衡查找树](#平衡查找树balanced-search-trees)
        - AVL 树
        - 伸缩树（Splay tree）
        - 红黑树
        - 2-3 查找树
        - 2-3-4 树(也称 2-4 树)
        - N-ary (K-ary, M-ary)树
        - B 树
    - [k-D 树](#k-D树)
    - [跳表](#跳表)
    - [网络流](#网络流)
    - [不相交集 & 联合查找](#不相交集--联合查找)
    - [快速处理的数学](#快速处理的数学)
    - [树堆 (Treap)](#树堆-treap)
    - [线性规划](#线性规划linear-programming视频)
    - [几何：凸包（Geometry, Convex hull）](#几何凸包geometry-convex-hull视频)
    - [离散数学](#离散数学)
    - [机器学习](#机器学习machine-learning)
- [一些主题的额外内容](#一些主题的额外内容)
- [视频系列](#视频系列)
- [计算机科学课程](#计算机科学课程)
- [论文](#论文)


## 额外书籍

    你可以从以下的书单挑选你有兴趣的主题来研读。

- [UNIX环境高级编程](https://www.amazon.com/dp/013937681X)
    - 老，但却很棒
- [Linux 命令行大全](https://www.amazon.com/dp/1593273894/)
    - 现代选择
- [TCP-IP详解系列](https://en.wikipedia.org/wiki/TCP/IP_Illustrated)
- [Head First 设计模式](https://www.amazon.com/gp/product/0596007124/)
    - 设计模式入门介绍
- [设计模式：可复用面向对象软件的基础](https://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)
    - 也被称为“四人帮”（Gang of Four(GOF)）
    - 经典设计模式书籍
- [Linux 和 UNIX 系统管理技术手册（第五版）](https://www.amazon.com/UNIX-Linux-System-Administration-Handbook/dp/0134277554/)
- [算法设计手冊（Skiena）](http://www.amazon.com/Algorithm-Design-Manual-Steven-Skiena/dp/1849967202)
    - 作为复习以及问题辨别
    - 这本书中算法的部分难度已经超过面试会出现的
    - 本书分为两个部分:
        - 数据结构和算法课本
            - 优点:
                - 跟其他算法课本一样是个很棒的复习素材
                - 包含作者以往解决工业及学术上问题的经验的故事
                - 含C语言代码示例
            - 缺点:
                - 某些地方跟《算法导论》（CLRS）一样艰深，但在某些主题，算法导论或许是更好的选择。
                - 第7、8、9章有点难以消化，因为某些地方并没有解释得很清楚，或者根本上我就是个学渣
                - 别会错意了，我很喜欢 Skiena 的教学方法以及他的风格。
        - 算法目录:
            - 这个部分是买这本书的最大原因
            - 我即将着手进行这部分，一旦完成这部分我会再更新上来
    - 可以在 kindle 上租
    - 解答：
        - [解答](http://www.algorithm.cs.sunysb.edu/algowiki/index.php/The_Algorithms_Design_Manual_(Second_Edition))
        - [解答](http://blog.panictank.net/category/algorithmndesignmanualsolutions/page/2/)
    - [勘误表](http://www3.cs.stonybrook.edu/~skiena/algorist/book/errata)

- [编程卓越之道（第一卷）：深入理解计算机](https://www.amazon.com/Write-Great-Code-Understanding-Machine/dp/1593270038)

    - 该书于2004年出版，虽然有些过时，但是对于简单了解计算机而言，这是一个了不起的资源
    - 作者发明了[高阶组合语言 HLA](https://en.wikipedia.org/wiki/High_Level_Assembly)，所以提到，并且举了一些HLA的例子。里面没有用到很多，但都是很棒的组合语言的例子。
    - 这些章节值得阅读，为你提供良好的基础：
        - 第2章──数字表示
        - 第3章──二进制算术和位运算
        - 第4章──浮点表示
        - 第5章──字符表示
        - 第6章──内存组织和访问
        - 第7章──组合数据类型和内存对象
        - 第9章──CPU体系结构
        - 第10章──指令集架构
        - 第11章──内存体系结构和组织

- [算法导论](https://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844)
    - **重要提示**：读这本书的价值有限。本书很好地回顾了算法和数据结构，但不会教你如何编写良好的代码。你必须能够有效地编写一个不错的解决方案
    - 又称 CLR，有时是 CLRS，因为 Stein 最后才加入

- [计算机体系结构：量化研究方法（第6版）](https://www.amazon.com/dp/0128119055)
    - 更丰富、更新（2017年），但篇幅较长
- [编程珠矶](http://www.amazon.com/Programming-Pearls-2nd-Jon-Bentley/dp/0201657880)
    - 前几章介绍了解决编程问题（非常古老，甚至还用数据磁带）的巧妙解决方案，但这只是一个介绍。这是关于程序设计和体系结构的指南

## 附加学习

    我把它们加进来是为了让你成为更全方位的软件工程师，并且留意一些技术以及算法，让你拥有更大的工具箱。

- ### 编译器

    - [编译器的工作方式，约1分钟（视频）](https://www.youtube.com/watch?v=IhC7sdYe-Jg)
    - [Harvard CS50-编译器（视频）](https://www.youtube.com/watch?v=CSZLNYF4Klo)
    - [C ++（视频）](https://www.youtube.com/watch?v=twodd1KFfGk)
    - [了解编译器优化（C ++）（视频）](https://www.youtube.com/watch?v=FnGCDLhaxKU)

- ### Emacs and vi(m)
    - 熟悉基于 unix 的代码编辑器
    - vi(m):
        - [使用 vim 进行编辑 01 - 安装, 设置和模式 (视频)](https://www.youtube.com/watch?v=5givLEMcINQ&index=1&list=PL13bz4SHGmRxlZVmWQ9DvXo1fEg4UdGkr)
        - [VIM 的冒险之旅](http://vim-adventures.com/)
        - 4 个视频集:
            - [vi/vim 编辑器 - 课程 1](https://www.youtube.com/watch?v=SI8TeVMX8pk)
            - [vi/vim 编辑器 - 课程 2](https://www.youtube.com/watch?v=F3OO7ZIOaJE)
            - [vi/vim 编辑器 - 课程 4](https://www.youtube.com/watch?v=1lYD5gwgZIA)
            - [vi/vim 编辑器 - 课程 3](https://www.youtube.com/watch?v=ZYEccA_nMaI)
        - [使用 Vi 而不是 Emacs](http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#Using_Vi_instead_of_Emacs)
    - emacs:
        - [基础 Emacs 教程 (视频)](https://www.youtube.com/watch?v=hbmV1bnQ-i0)
        - 3 个视频集:
            - [Emacs 教程 (初学者) -第 1 部分- 文件命令, 剪切/复制/粘贴,  自定义命令](https://www.youtube.com/watch?v=ujODL7MD04Q)
            - [Emacs 教程 (初学者 -第 2 部分- Buffer 管理, 搜索, M-x grep 和 rgrep 模式](https://www.youtube.com/watch?v=XWpsRupJ4II)
            - [Emacs 教程 (初学者 -第 3 部分- 表达式, 声明, ~/.emacs 文件和包机制](https://www.youtube.com/watch?v=paSgzPso-yc)
        - [Evil 模式: 或许, 我是怎样对 Emacs 路人转粉的 (视频)](https://www.youtube.com/watch?v=JWD1Fpdd4Pc)
        - [使用 Emacs 开发 C 程序](http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#Writing_C_programs_with_Emacs)
        - [(或许) 深度组织模式:管理结构 (视频)](https://www.youtube.com/watch?v=nsGYet02bEk)

- ### Unix 命令行工具
    - 下列内容包含优秀工具
    - bash
    - cat
    - grep
    - sed
    - awk
    - curl or wget
    - sort
    - tr
    - uniq
    - [strace](https://en.wikipedia.org/wiki/Strace)
    - [tcpdump](https://danielmiessler.com/study/tcpdump/)

- ### 信息论 (视频)
    - [Khan Academy 可汗学院](https://www.khanacademy.org/computing/computer-science/informationtheory)
    - 更多有关马尔可夫的内容:
        - [马尔可夫内容生成（Core Markov Text Generation）](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/waxgx/core-markov-text-generation)
        - [Core Implementing Markov Text Generation马尔可夫内容生成实现](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/gZhiC/core-implementing-markov-text-generation)
        - [一个马尔可夫内容生成器的项目（Project = Markov Text Generation Walk Through）](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/EUjrq/project-markov-text-generation-walk-through)
    - 关于更多信息，请参照下方 MIT 6.050J 信息和系统复杂度的内容。

- ### 奇偶校验位 & 汉明码 (视频)
    - [入门](https://www.youtube.com/watch?v=q-3BctoUpHE)
    - [奇偶校验位](https://www.youtube.com/watch?v=DdMcAUlxh1M)
    - 汉明码(Hamming Code):
        - [发现错误](https://www.youtube.com/watch?v=1A_NcXxdoCc)
        - [修正错误](https://www.youtube.com/watch?v=JAMLuxdHH8o)
    - [检查错误](https://www.youtube.com/watch?v=wbH2VxzmoZk)

- ### 系统熵值（Entropy）
    - 请参考下方视频
    - 观看之前，请先确定观看了信息论的视频
    - [信息理论, 克劳德·香农, 熵值, 系统冗余, 数据比特压缩 (视频)](https://youtu.be/JnJq3Py0dyM?t=176)

- ### 密码学
    - 请参考下方视频
    - 观看之前，请先确定观看了信息论的视频
    - [可汗学院](https://www.khanacademy.org/computing/computer-science/密码学)
    - [密码学: 哈希函数](https://www.youtube.com/watch?v=KqqOXndnvic&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=30)
    - [密码学: 加密](https://www.youtube.com/watch?v=9TNI2wHmaeI&index=31&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp)

- ### 压缩
    - 观看之前，请先确定观看了信息论的视频
    - Computerphile (视频)：
        - [压缩](https://www.youtube.com/watch?v=Lto-ajuqW3w)
        - [压缩熵值](https://www.youtube.com/watch?v=M5c_RFKVkko)
        - [由上而下的树 (霍夫曼编码树)](https://www.youtube.com/watch?v=umTbivyJoiI)
        - [额外比特 - 霍夫曼编码树](https://www.youtube.com/watch?v=DV8efuB3h2g)
        - [优雅的压缩数据 (无损数据压缩方法)](https://www.youtube.com/watch?v=goOa3DGezUA)
        - [Text Compression Meets Probabilities](https://www.youtube.com/watch?v=cCDCfoHTsaU)
    - [数据压缩的艺术](https://www.youtube.com/playlist?list=PLOU2XLYxmsIJGErt5rrCqaSGTMyyqNt2H)
    - [(可选) 谷歌开发者：GZIP 还差远了呢!](https://www.youtube.com/watch?v=whGwm0Lky2s)

- ### 计算机安全
    - [MIT（23个视频）](https://www.youtube.com/playlist?list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh)
        - [威胁模型：入门](https://www.youtube.com/watch?v=GqmQg-cszw4&index=1&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh)
        - [控制劫持攻击](https://www.youtube.com/watch?v=6bwzNg5qQ0o&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh&index=2)
        - [缓冲区溢出漏洞攻击和防御](https://www.youtube.com/watch?v=drQyrzRoRiA&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh&index=3)
        - [优先权区分](https://www.youtube.com/watch?v=6SIJmoE9L9g&index=4&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh)
        - [能力](https://www.youtube.com/watch?v=8VqTSY-11F4&index=5&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh)
        - [在沙盒中运行原生代码](https://www.youtube.com/watch?v=VEV74hwASeU&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh&index=6)
        - [网络安全模型](https://www.youtube.com/watch?v=chkFBigodIw&index=7&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh)
        - [网络安全应用](https://www.youtube.com/watch?v=EBQIGy1ROLY&index=8&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh)
        - [标志化执行](https://www.youtube.com/watch?v=yRVZPvHYHzw&index=9&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh)
        - [网络安全](https://www.youtube.com/watch?v=SIEVvk3NVuk&index=11&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh)
        - [网络协议](https://www.youtube.com/watch?v=QOtA76ga_fY&index=12&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh)
        - [旁路攻击](https://www.youtube.com/watch?v=PuVMkSEcPiI&index=15&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh)

- ### 垃圾回收
    - [ ] [Python 中的垃圾回收 (视频)](https://www.youtube.com/watch?v=iHVs_HkjdmI)
    - [ ] [深度解析：论垃圾回收在 JAVA 中的重要性](https://www.infoq.com/presentations/garbage-collection-benefits)
    - [ ] [深度解析：论垃圾回收在 Python 中的重要性(视频)](https://www.youtube.com/watch?v=P-8Z0-MhdQs&list=PLdzf4Clw0VbOEWOS_sLhT_9zaiQDrS5AR&index=3)

- ### 并行编程
    - [ ] [Coursera (Scala)](https://www.coursera.org/learn/parprog1/home/week/1)
    - [ ] [用于高性能并行计算的高效Python（视频）](https://www.youtube.com/watch?v=uY85GkaYzBk)

- ### 消息传递，序列化和队列系统
    - [Thrift](https://thrift.apache.org/)
        - [教程](http://thrift-tutorial.readthedocs.io/en/latest/intro.html)
    - [协议缓冲](https://developers.google.com/protocol-buffers/)
        - [教程](https://developers.google.com/protocol-buffers/docs/tutorials)
    - [gRPC](http://www.grpc.io/)
        - [gRPC 对于JAVA开发者的入门教程（视频）](https://www.youtube.com/watch?v=5tmPvSe7xXQ&list=PLcTqM9n_dieN0k1nSeN36Z_ppKnvMJoly&index=1)
    - [Redis](http://redis.io/)
        - [教程](http://try.redis.io/)
    - [Amazon的 SQS 系统 (队列)](https://aws.amazon.com/sqs/)
    - [Amazon的 SNS 系统 (pub-sub)](https://aws.amazon.com/sns/)
    - [RabbitMQ](https://www.rabbitmq.com/)
        - [入门教程](https://www.rabbitmq.com/getstarted.html)
    - [Celery](http://www.celeryproject.org/)
        - [Celery入门](http://docs.celeryproject.org/en/latest/getting-started/first-steps-with-celery.html)
    - [ZeroMQ](http://zeromq.org/)
        - [入门教程](http://zeromq.org/intro:read-the-manual)
    - [ActiveMQ](http://activemq.apache.org/)
    - [Kafka](http://kafka.apache.org/documentation.html#introduction)
    - [MessagePack](http://msgpack.org/index.html)
    - [Avro](https://avro.apache.org/)

- ### A*搜索算法

    - [A 搜索算法](https://en.wikipedia.org/wiki/A*_search_algorithm)
    - [A* 路径搜索教程（教程）](https://www.youtube.com/watch?v=KNXfSOx4eEE)
    - [A* 路径搜索（E01：算法解释）（视频）](https://www.youtube.com/watch?v=-L-WgKMFuhE)

- ### 快速傅里叶变换
    - [傅立叶变换的交互式指南](https://betterexplained.com/articles/an-interactive-guide-to-the-fourier-transform/)
    - [什么是傅立叶变换？论傅立叶变换的用途](http://www.askamathematician.com/2012/09/q-what-is-a-fourier-transform-what-is-it-used-for/)
    - [什么是傅立叶变换？ (视频)](https://www.youtube.com/watch?v=Xxut2PN-V8Q)
    - [分而治之：FFT（视频）](https://www.youtube.com/watch?v=iTMn0Kt18tg&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=4)
    - [FTT 是什么](http://jakevdp.github.io/blog/2013/08/28/understanding-the-fft/)

- ### 布隆过滤器
    - 给定布隆过滤器m比特位和k个哈希函数，插入和成员检测都会是 O(k)。
    - [布隆过滤器（视频）](https://www.youtube.com/watch?v=-SuTGoFYjZs)
    - [布隆过滤器 | 数据挖掘 | Stanford University（视频）](https://www.youtube.com/watch?v=qBTdukbzc78)
    - [教程](http://billmill.org/bloomfilter-tutorial/)
    - [如何写一个布隆过滤器应用](http://blog.michaelschmatz.com/2016/04/11/how-to-write-a-bloom-filter-cpp/)

- ### HyperLogLog
    - [如何仅使用1.5KB内存计算十亿个不同的对象](http://highscalability.com/blog/2012/4/5/big-data-counting-how-to-count-a-billion-distinct-objects-us.html)

- ### 局部敏感哈希
    - 用于确定文件的相似性
    - MD5 或 SHA 的反义词，用于确定2个文档/字符串是否完全相同
    - [Simhashing（希望如此）变得简单](http://ferd.ca/simhashing-hopefully-made-simple.html)

- ### van Emde Boas 树
    - [分而治之：van Emde Boas 树 (视频)](https://www.youtube.com/watch?v=hmReJCupbNU&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=6)
    - [MIT课堂笔记](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-design-and-analysis-of-algorithms-spring-2012/lecture-notes/MIT6_046JS12_lec15.pdf)

- ### 增强数据结构
    - [CS 61B 第 39 课: 增强数据结构](https://youtu.be/zksIj9O8_jc?list=PL4BBB74C7D2A1049C&t=950)

- ### k-D树
    - 非常适合在矩形或更高维度的对象中查找点数
    - 最适合k近邻
    - [Kd树（视频）](https://www.youtube.com/watch?v=W94M9D_yXKk)
    - [kNN K-d树算法（视频）](https://www.youtube.com/watch?v=Y4ZgLlDfKDg)

- ### 跳表
    - "有一种非常迷幻的数据类型" - Skiena
    - [随机化: 跳表 (视频)](https://www.youtube.com/watch?v=2g9OSRKJuzM&index=10&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp)
    - [更生动详细的解释](https://en.wikipedia.org/wiki/Skip_list)

- ### 网络流
    - [5分钟简析 Ford-Fulkerson──一步步示例 (视频)](https://www.youtube.com/watch?v=v1VgJmkEJW0)
    - [Ford-Fulkerson 算法 (视频)](https://www.youtube.com/watch?v=v1VgJmkEJW0)
    - [网络流 (视频)](https://www.youtube.com/watch?v=2vhN4Ice5jI)

- ### 不相交集 & 联合查找
    - [UCB 61B - 不相交集；排序 & 选择(视频)](https://www.youtube.com/watch?v=MAEGXTwmUsI&list=PL-XXv-cvA_iAlnI-BQr9hjqADPBtujFJd&index=21)
    - [Sedgewick算法──Union-Find（6视频）](https://www.coursera.org/learn/algorithms-part1/home/week/1)

- ### 快速处理的数学
    - [整数运算, Karatsuba 乘法 (视频)](https://www.youtube.com/watch?v=eCaXlAaN2uE&index=11&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [中国剩余定理 (在密码学中的使用) (视频)](https://www.youtube.com/watch?v=ru7mWZJlRQg)

- ### 树堆 (Treap)
    - 一个二叉搜索树和一个堆的组合
    - [树堆](https://en.wikipedia.org/wiki/Treap)
    - [数据结构：树堆的讲解（视频）](https://www.youtube.com/watch?v=6podLUYinH8)
    - [集合操作的应用(Applications in set operations)](https://www.cs.cmu.edu/~scandal/papers/treaps-spaa98.pdf)

- ### 线性规划（Linear Programming）（视频）
    - [线性规划](https://www.youtube.com/watch?v=M4K6HYLHREQ)
    - [寻找最小成本](https://www.youtube.com/watch?v=2ACJ9ewUC6U)
    - [寻找最大值](https://www.youtube.com/watch?v=8AA_81xI3ik)
    - [用 Python 解决线性方程式──单纯形算法](https://www.youtube.com/watch?v=44pAWI7v5Zk)

- ### 几何：凸包（Geometry, Convex hull）（视频）
    - [Graph Alg. IV: 几何算法介绍 - 第 9 课](https://youtu.be/XIAQRlNkJAw?list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&t=3164)
    - [Graham & Jarvis: 几何算法 - 第 10 课](https://www.youtube.com/watch?v=J5aJEcOr6Eo&index=10&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm)
    - [分而治之: 凸包, 中值查找](https://www.youtube.com/watch?v=EzeYI7p9MjU&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=2)

- ### 离散数学
    - 查看下面的视频

- ### 机器学习（Machine Learning）
    - 为什么学习机器学习？
        - [谷歌如何将自己改造成一家「机器学习优先」公司？](https://backchannel.com/how-google-is-remaking-itself-as-a-machine-learning-first-company-ada63defcb70)
        - [智能计算机系统的大规模深度学习 (视频)](https://www.youtube.com/watch?v=QSaZGT4-6EY)
        - [Peter Norvig：深度学习和理解与软件工程和验证的对比](https://www.youtube.com/watch?v=X769cyzBNVw)
    - [谷歌云机器学习工具（视频）](https://www.youtube.com/watch?v=Ja2hxBAwG_0)
    - [谷歌开发者机器学习清单 (Scikit Learn 和 Tensorflow) (视频)](https://www.youtube.com/playlist?list=PLOU2XLYxmsIIuiBfYad6rFYQU_jL2ryal)
    - [Tensorflow (视频)](https://www.youtube.com/watch?v=oZikw5k_2FM)
    - [Tensorflow 教程](https://www.tensorflow.org/versions/r0.11/tutorials/index.html)
    - [Python 实现神经网络实例教程（使用 Theano）](http://www.analyticsvidhya.com/blog/2016/04/neural-networks-python-theano/)
    - 课程:
        - [很棒的初级课程：机器学习](https://www.coursera.org/learn/machine-learning)
            - [视频教程](https://www.youtube.com/playlist?list=PLZ9qNFMHZ-A4rycgrgOYma6zxF4BZGGPW)
            - 看第 12-18 集复习线性代数（第 14 集和第 15 集是重复的）
        - [机器学习中的神经网络](https://www.coursera.org/learn/neural-networks)
        - [Google 深度学习微学位](https://www.udacity.com/course/deep-learning--ud730)
        - [Google/Kaggle 机器学习工程师微学位](https://www.udacity.com/course/machine-learning-engineer-nanodegree-by-google--nd009)
        - [无人驾驶工程师微学位](https://www.udacity.com/drive)
    - 资源:
        - 书籍：
            - [Python 机器学习](https://www.amazon.com/Python-Machine-Learning-Sebastian-Raschka/dp/1783555130/)
            - [Data Science from Scratch: First Principles with Python](https://www.amazon.com/Data-Science-Scratch-Principles-Python/dp/149190142X)
            - [Python 机器学习简介](https://www.amazon.com/Introduction-Machine-Learning-Python-Scientists/dp/1449369413/)
        - [软件工程师的机器学习](https://github.com/ZuzooVn/machine-learning-for-software-engineers)
        - Data School：http://www.dataschool.io/

--

## 一些主题的额外内容
 
    我为前面提到的某些主题增加了一些额外的内容，之所以没有直接添加到前面，是因为这样很容易导致某个主题内容过多。毕竟你想在本世纪找到一份工作，对吧？

- SOLID

    - [ ] [Bob Martin SOLID面向对象和敏捷设计的原理（视频）](https://www.youtube.com/watch?v=TMuno5RZNeE)
    - [ ] S ── [单一责任原则](http://www.oodesign.com/single-responsibility-principle.html) | [对每个对象的单一责任](http://www.javacodegeeks.com/2011/11/solid-single-responsibility-principle.html)
        - [更多](https://docs.google.com/open?id=0ByOwmqah_nuGNHEtcU5OekdDMkk)
    - [ ] O ── [开放/封闭原则](http://www.oodesign.com/open-close-principle.html) | [在生产级别上，可以扩展对象，但不能修改对象](https://en.wikipedia.org/wiki/Open/closed_principle)
        - [更多](http://docs.google.com/a/cleancoder.com/viewer?a=v&pid=explorer&chrome=true&srcid=0BwhCYaYDn8EgN2M5MTkwM2EtNWFkZC00ZTI3LWFjZTUtNTFhZGZiYmUzODc1&hl=en)
    - [ ] L ── [Liskov 替换原则](http://www.oodesign.com/liskov-s-substitution-principle.html) | [基本类别和派生类别遵循“IS A”原则](http://stackoverflow.com/questions/56860/what-is-the-liskov-substitution-principle)
        - [更多](http://docs.google.com/a/cleancoder.com/viewer?a=v&pid=explorer&chrome=true&srcid=0BwhCYaYDn8EgNzAzZjA5ZmItNjU3NS00MzQ5LTkwYjMtMDJhNDU5ZTM0MTlh&hl=en)
    - [ ] I ── [接口隔离原理](http://www.oodesign.com/interface-segregation-principle.html) | 不应强迫客户端实现不使用的接口
        - [5分钟了解接口隔离原理（视频）](https://www.youtube.com/watch?v=3CtAfl7aXAQ)
        - [更多](http://docs.google.com/a/cleancoder.com/viewer?a=v&pid=explorer&chrome=true&srcid=0BwhCYaYDn8EgOTViYjJhYzMtMzYxMC00MzFjLWJjMzYtOGJiMDc5N2JkYmJi&hl=en)
    - [ ] D ── [依赖倒置原理](http://www.oodesign.com/dependency-inversion-principle.html) | 减少对象组合中的依赖性。
        - [依赖倒置原理为何如此重要？](http://stackoverflow.com/questions/62539/what-is-the-dependency-inversion-principle-and-why-is-it-important)
        - [更多](http://docs.google.com/a/cleancoder.com/viewer?a=v&pid=explorer&chrome=true&srcid=0BwhCYaYDn8EgMjdlMWIzNGUtZTQ0NC00ZjQ5LTkwYzQtZjRhMDRlNTQ3ZGMz&hl=en)

- Union-Find
    - [概览](https://www.coursera.org/learn/data-structures/lecture/JssSY/overview)
    - [初级实践](https://www.coursera.org/learn/data-structures/lecture/EM5D0/naive-implementations)
    - [树状结构](https://www.coursera.org/learn/data-structures/lecture/Mxu0w/trees)
    - [合并树状结构](https://www.coursera.org/learn/data-structures/lecture/qb4c2/union-by-rank)
    - [路径压缩](https://www.coursera.org/learn/data-structures/lecture/Q9CVI/path-compression)
    - [分析选项](https://www.coursera.org/learn/data-structures/lecture/GQQLN/analysis-optional)

- **动态规划的更多内容** (视频)
    - [6.006: 动态规划 I: 斐波那契数列, 最短路径](https://www.youtube.com/watch?v=OQ5jsbhAv_M&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=19)
    - [6.006: 动态规划 II: 文本匹配, 二十一点/黑杰克](https://www.youtube.com/watch?v=ENyox7kNKeY&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=20)
    - [6.006: 动态规划 III: 最优加括号方式, 最小编辑距离, 背包问题](https://www.youtube.com/watch?v=ocZMDMZwhCY&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=21)
    - [6.006: 动态规划 IV: 吉他指法，拓扑，超级马里奥.](https://www.youtube.com/watch?v=tp4_UXaVyx8&index=22&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [6.046: 动态规划: 动态规划进阶](https://www.youtube.com/watch?v=Tw1k46ywN6E&index=14&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp)
    - [6.046: 动态规划: 所有点对最短路径](https://www.youtube.com/watch?v=NzgFUwOaoIw&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=15)
    - [6.046: 动态规划: 更多示例](https://www.youtube.com/watch?v=krZI60lKPek&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=12)

- **图形处理进阶** (视频)
    - [异步分布式算法: 对称性破缺，最小生成树](https://www.youtube.com/watch?v=mUBmcbbJNf4&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=27)
    - [异步分布式算法: 最小生成树](https://www.youtube.com/watch?v=kQ-UQAzcnzA&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=28)

- MIT **概率论** (过于数学，进度缓慢，但这对于数学的东西却是必要之恶) (视频):
    - [MIT 6.042J - 概率论概述](https://www.youtube.com/watch?v=SmFwFdESMHI&index=18&list=PLB7540DEDD482705B)
    - [MIT 6.042J - 条件概率 Probability](https://www.youtube.com/watch?v=E6FbvM-FGZ8&index=19&list=PLB7540DEDD482705B)
    - [MIT 6.042J - 独立](https://www.youtube.com/watch?v=l1BCv3qqW4A&index=20&list=PLB7540DEDD482705B)
    - [MIT 6.042J - 随机变量](https://www.youtube.com/watch?v=MOfhhFaQdjw&list=PLB7540DEDD482705B&index=21)
    - [MIT 6.042J - 期望 I](https://www.youtube.com/watch?v=gGlMSe7uEkA&index=22&list=PLB7540DEDD482705B)
    - [MIT 6.042J - 期望 II](https://www.youtube.com/watch?v=oI9fMUqgfxY&index=23&list=PLB7540DEDD482705B)
    - [MIT 6.042J - 大偏差](https://www.youtube.com/watch?v=q4mwO2qS2z4&index=24&list=PLB7540DEDD482705B)
    - [MIT 6.042J - 随机游走](https://www.youtube.com/watch?v=56iFMY8QW2k&list=PLB7540DEDD482705B&index=25)

- [Simonson: 近似算法 (视频)](https://www.youtube.com/watch?v=oDniZCmNmNw&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=19)

- **字符串匹配**

    - Rabin-Karp（视频）
        - [Rabin Karps 算法](https://www.coursera.org/learn/data-structures/lecture/c0Qkw/rabin-karps-algorithm)
        - [预计算](https://www.coursera.org/learn/data-structures/lecture/nYrc8/optimization-precomputation)
        - [优化：实施和分析](https://www.coursera.org/learn/data-structures/lecture/h4ZLc/optimization-implementation-and-analysis)
        - [表翻倍，Karp-Rabin](https://www.youtube.com/watch?v=BRO7mVIFt08&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=9)
        - [滚动哈希，摊销分析](https://www.youtube.com/watch?v=w6nuXg0BISo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=32)
    - Knuth-Morris-Pratt (KMP)：
        - [Knuth-Morris-Pratt（KMP）字符串匹配算法](https://www.youtube.com/watch?v=5i7oKodCRJo)
    - Boyer–Moore 字符串搜索算法
        - [Boyer–Moore 字符串搜索算法](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_string_search_algorithm)
        - [高级字符串搜索Boyer-Moore-Horspool算法（视频）](https://www.youtube.com/watch?v=QDZpzctPf10)
    - [Coursera：字符串算法](https://www.coursera.org/learn/algorithms-on-strings/home/week/1)
        - 刚开始时很棒，但是当它超过 KMP 时，它变得比需要复杂得多
        - 很好的字典树解释
        - 可以跳过

- **排序**

    - 斯坦福大学关于排序算法的视频:
        - [课程 15 | 编程抽象（视频）](https://www.youtube.com/watch?v=ENp00xylP7c&index=15&list=PLFE6E58F856038C69)
        - [课程 16 | 编程抽象（视频）](https://www.youtube.com/watch?v=y4M9IVgrVKo&index=16&list=PLFE6E58F856038C69)

    - Shai Simonson 视频，[Aduni.org](http://www.aduni.org/):
        - [算法 - 排序 - 第二讲（视频）](https://www.youtube.com/watch?v=odNJmw5TOEE&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=2)
        - [算法 - 排序2 - 第三讲（视频）](https://www.youtube.com/watch?v=hj8YKFTFKEE&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=3)

    - Steven Skiena 关于排序的视频:
        - [课程从 26:46 开始（视频）](https://youtu.be/ute-pmMkyuk?list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&t=1600)
        - [课程从 27:40 开始（视频）](https://www.youtube.com/watch?v=yLvp-pB8mak&index=8&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b)
        - [课程从 35:00 开始（视频）](https://www.youtube.com/watch?v=q7K9otnzlfE&index=9&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b)
        - [课程从 23:50 开始（视频）](https://www.youtube.com/watch?v=TvqIGu9Iupw&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&index=10)

## 视频系列

 坐下来享受一下吧。"netflix 和技能" :P

- [个人的动态规划问题列表 (都是短视频)](https://www.youtube.com/playlist?list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr)

- [x86 架构，汇编，应用程序 (11 个视频)](https://www.youtube.com/playlist?list=PL038BE01D3BAEFDB0)

- [MIT 18.06 线性代数，2005 年春季 (35 个视频)](https://www.youtube.com/playlist?list=PLE7DDD91010BC51F8)

- [绝妙的 MIT 微积分：单变量微积分](https://www.youtube.com/playlist?list=PL3B08AE665AB9002A)

- [计算机科学 70, 001 - 2015 年春季 - 离散数学和概率理论](https://www.youtube.com/playlist?list=PL-XXv-cvA_iD8wQm8U0gG_Z1uHjImKXFy)

- [离散数学 (19 个视频)](https://www.youtube.com/playlist?list=PLWX710qNZo_sNlSWRMVIh6kfTjolNaZ8t)

- [离散数学（第一部分），Sarada Herke （5个视频）](https://www.youtube.com/playlist?list=PLGxuz-nmYlQPOc4w1Kp2MZrdqOOm4Jxeo)

- CSE373 - 算法分析 (25 个视频)
    - [Skiena 的算法设计手册讲座](https://www.youtube.com/watch?v=ZFjhkohHdAA&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&index=1)

- [UC Berkeley 61B (2014 年春季): 数据结构 (25 个视频)](https://www.youtube.com/watch?v=mFPmKGIrQs4&list=PL-XXv-cvA_iAlnI-BQr9hjqADPBtujFJd)

- [UC Berkeley 61B (2006 年秋季): 数据结构 (39 个视频)](https://www.youtube.com/playlist?list=PL4BBB74C7D2A1049C)

- [UC Berkeley 61C：计算机结构 (26 个视频)](https://www.youtube.com/watch?v=gJJeUFyuvvg&list=PL-XXv-cvA_iCl2-D-FS5mk0jFF6cYSJs_)

- [OOSE：使用 UML 和 Java 进行软件开发 (21 个视频)](https://www.youtube.com/playlist?list=PLJ9pm_Rc9HesnkwKlal_buSIHA-jTZMpO)

- <del>[UC Berkeley CS 152: 计算机结构和工程 (20 个视频)](https://www.youtube.com/watch?v=UH0QYvtP7Rk&index=20&list=PLkFD6_40KJIwEiwQx1dACXwh-2Fuo32qr)</del>

- [MIT 6.004: 计算结构 (49 视频)](https://www.youtube.com/playlist?list=PLrRW1w6CGAcXbMtDFj205vALOGmiRc82-)

- [卡內基梅隆大学 - 计算机架构讲座 (39 个视频)](https://www.youtube.com/playlist?list=PL5PHm2jkkXmi5CxxI7b3JCL1TWybTDtKq)

- [MIT 6.006：算法介绍 (47 个视频)](https://www.youtube.com/watch?v=HtSuA80QTyo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&nohtml5=False)

- [MIT 6.033：计算机系统工程 (22 个视频)](https://www.youtube.com/watch?v=zm2VP0kHl1M&list=PL6535748F59DCA484)

- [MIT 6.034：人工智能，2010 年秋季 (30 个视频)](https://www.youtube.com/playlist?list=PLUl4u3cNGP63gFHB6xb-kVBiQHYe_4hSi)

- [MIT 6.042J：计算机科学数学, 2010 年秋季 (25 个视频)](https://www.youtube.com/watch?v=L3LMbpZIKhQ&list=PLB7540DEDD482705B)

- [MIT 6.046：算法设计与分析 (34 个视频)](https://www.youtube.com/watch?v=2P-yW7LQr08&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp)

- [MIT 6.050J：信息和熵, 2008 年春季 (19 个视频)](https://www.youtube.com/watch?v=phxsQrZQupo&list=PL_2Bwul6T-A7OldmhGODImZL8KEVE38X7)

- [MIT 6.851：高等数据结构 (22 个视频)](https://www.youtube.com/watch?v=T0yzrZL1py0&list=PLUl4u3cNGP61hsJNdULdudlRL493b-XZf&index=1)

- [MIT 6.854: 高等算法, 2016 年春季 (24 个视频)](https://www.youtube.com/playlist?list=PL6ogFv-ieghdoGKGg2Bik3Gl1glBTEu8c)

- [Harvard COMPSCI 224：高级算法（25个视频）](https://www.youtube.com/playlist?list=PL2SOU6wwxB0uP4rJgf5ayhHWgw7akUWSf)

- [MIT 6.858：计算机系统安全, 2014 年秋季](https://www.youtube.com/watch?v=GqmQg-cszw4&index=1&list=PLUl4u3cNGP62K2DjQLRxDNRi0z2IRWnNh)

- [斯坦福: 编程范例 (27 个视频)](https://www.youtube.com/playlist?list=PL9D558D49CA734A02)

- [密码学导论，Christof Paar](https://www.youtube.com/playlist?list=PL6N5qY2nvvJE8X75VkXglSrVhLv1tVcfy)
    - [课程网站以及幻灯片和问题集](http://www.crypto-textbook.com/)

- [大数据 - 斯坦福大学 (94 个视频)](https://www.youtube.com/playlist?list=PLLssT5z_DsK9JDLcT8T62VtzwyW9LNepV)

- [图论，Sarada Herke（67个视频）](https://www.youtube.com/user/DrSaradaHerke/playlists?shelf_id=5&view=50&sort=dd)

## 计算机科学课程

- [在线 CS 课程目录](https://github.com/open-source-society/computer-science)
- [CS 课程目录 (一些是在线讲座)](https://github.com/prakhar1989/awesome-courses)

## 论文

- [喜欢经典的论文？](https://www.cs.cmu.edu/~crary/819-f09/)
- [1978: 通信顺序处理](http://spinroot.com/courses/summer/Papers/hoare_1978.pdf)
    - [Go 实现](https://godoc.org/github.com/thomas11/csp)
- [2003: The Google 文件系统](http://static.googleusercontent.com/media/research.google.com/en//archive/gfs-sosp2003.pdf)
    - 2012 年被 Colossus 取代了
- [2004: MapReduce: Simplified Data Processing on Large Clusters](http://static.googleusercontent.com/media/research.google.com/en//archive/mapreduce-osdi04.pdf)
    - 大多被云数据流取代了?
- [2006年：Bigtable：结构化数据的分布式存储系统](https://static.googleusercontent.com/media/research.google.com/en//archive/bigtable-osdi06.pdf)
    - [深入了解Google BigQuery](https://cloud.google.com/files/BigQueryTechnicalWP.pdf)
- [2006年：针对松散耦合的分布式系统的Chubby Lock服务](https://research.google.com/archive/chubby-osdi06.pdf)
- [2007年：Dynamo：亚马逊的高可用键值存储](http://s3.amazonaws.com/AllThingsDistributed/sosp/amazon-dynamo-sosp2007.pdf)
    - Dynamo论文启动了NoSQL革命
- [2007: 每个程序员都应该知道的内存知识 (非常长，作者建议跳过某些章节来阅读)](https://www.akkadia.org/drepper/cpumemory.pdf)
- [2010年：Dapper，一个大型分布式系统跟踪基础结构](https://research.google.com/pubs/archive/36356.pdf)
- [2010年：Dremel：Web规模数据集的交互式分析](https://static.googleusercontent.com/media/research.google.com/en//pubs/archive/36632.pdf)
- [2012: Google 的 Colossus](https://www.wired.com/2012/07/google-colossus/)
    - 没有论文
- 2012: AddressSanitizer: 快速的内存访问检查器:
    - [论文](http://static.googleusercontent.com/media/research.google.com/en//pubs/archive/37752.pdf)
    - [视频](https://www.usenix.org/conference/atc12/technical-sessions/presentation/serebryany)
- 2013: Spanner: Google 的分布式数据库:
    - [论文](http://static.googleusercontent.com/media/research.google.com/en//archive/spanner-osdi2012.pdf)
    - [视频](https://www.usenix.org/node/170855)
- [2014: Machine Learning: The High-Interest Credit Card of Technical Debt](http://static.googleusercontent.com/media/research.google.com/en//pubs/archive/43146.pdf)
- [2015: Continuous Pipelines at Google](http://static.googleusercontent.com/media/research.google.com/en//pubs/archive/43790.pdf)
- [2015: 大规模高可用: 构建 Google Ads 的数据基础设施](https://static.googleusercontent.com/media/research.google.com/en//pubs/archive/44686.pdf)
- [2015: TensorFlow: 异构分布式系统上的大规模机器学习](http://download.tensorflow.org/paper/whitepaper2015.pdf )
- [2015: 开发者应该如何搜索代码：用例学习](http://static.googleusercontent.com/media/research.google.com/en//pubs/archive/43835.pdf)
- [2016: Borg, Omega, and Kubernetes](http://static.googleusercontent.com/media/research.google.com/en//pubs/archive/44843.pdf)