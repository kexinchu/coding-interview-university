# 软件工程师学习清单
清单来源：https://github.com/jwasham/coding-interview-university/blob/main/translations/README-cn.md  
结合自己的学习过程做了写整理

---

## 目录
- [如何使用它](#如何使用它)
- [不要觉得自己不够聪明](#不要觉得自己不够聪明)
- [面试过程 & 通用的面试准备](#面试过程--通用的面试准备)
- [为你的面试选择一种语言](#为你的面试选择一种语言)
- [书单](#书单)
- [在你开始之前](#在你开始之前)
- [没有包含的内容](#没有包含的内容)
- [必备知识](#必备知识)
- [日常计划](#日常计划)
- [算法复杂度 / Big-O / 渐进分析法](#算法复杂度--big-o--渐进分析法)
- [数据结构](#数据结构)
    - [数组（Arrays）](#数组arrays)
    - [链表（Linked Lists）](#链表linked-lists)
    - [堆栈（Stack）](#堆栈stack)
    - [队列（Queue）](#队列queue)
    - [哈希表（Hash table）](#哈希表hash-table)
- [更多的知识](#更多的知识)
    - [二分查找（Binary search）](#二分查找binary-search)
    - [按位运算（Bitwise operations）](#按位运算bitwise-operations)
- [树（Trees）](#树trees)
    - [树 —— 笔记 & 背景](#树--笔记--背景)
    - [二叉查找树（Binary search trees）：BSTs](#二叉查找树binary-search-treesbsts)
    - [平衡查找树 (Balanced search trees)]
    - [堆（Heap） / 优先级队列（Priority Queue） / 二叉堆（Binary Heap）](#堆heap--优先级队列priority-queue--二叉堆binary-heap)
- [排序](#排序sorting)
    - 选择排序（selection）
    - 插入排序（insertion）
    - 堆排序（heapsort）
    - 快速排序（quicksort）
    - 归并排序（merge sort）
- [图（Graphs）](#图graphs)
    - 有向图（directed）
    - 无向图（undirected）
    - 邻接矩阵（adjacency matrix）
    - 邻接表（adjacency list）
    - 遍历：广度优先(BFS), 深度优先(DFS)
- [更多知识](#更多知识)
    - [递归](#递归recursion)
    - [动态规划](#动态规划dynamic-programming)
    - [面向对象编程](#面向对象编程)
    - [设计模式](#设计模式)
    - [组合 & 概率](#组合combinatorics-n-中选-k-个--概率probability)
    - [NP, NP-完全和近似算法](#np-np-完全和近似算法)
    - [缓存](#缓存cache)
    - [进程和线程](#进程processe和线程thread)
    - [测试](#测试)
    - [调度](#调度)
    - [字符串搜索和操作](#字符串搜索和操作)
    - [字典树（Tries）](#字典树tries)
    - [浮点数](#浮点数)
    - [Unicode](#unicode)
    - [字节顺序](#字节序Endianness)
    - [网络](#网络视频)
- [终面](#终面)
- [编程问题练习](#编程问题练习)
- [编程练习和挑战](#编程练习和挑战)
- [当你临近面试时](#当你临近面试时)
- [你的简历](#你的简历)
- [当面试来临的时候](#当面试来临的时候)
- [问面试官的问题](#问面试官的问题)
- [当你获得了梦想的职位](#当你获得了梦想的职位)

---

## 如何使用它

下面所有的东西都只是一个概述。因此，你需要由上而下逐一地去处理它。
在学习过程中，使用 markdown 去检查计划的进展，包括使用包含任务进度的任务列表。
    在你完成了一些修改后，在框框中打 x

## 不要觉得自己不够聪明

- 大多数成功的软件工程师都非常聪明，但他们都有一种觉得自己不够聪明的不安全感。加油！！！
- [天才程序员的神话](https://www.youtube.com/watch?v=0SARbwvhupQ)
- [不要单打独斗：面对技术中的隐形怪物](https://www.youtube.com/watch?v=1i8ylq4j_EY)

## 面试过程 & 通用的面试准备

- [x] [ABC：不要停止编程（Always Be Coding）](https://medium.com/always-be-coding/abc-always-be-coding-d5f8051afce2#.4heg8zvm4)
- [x] [白板编程（Whiteboarding）](https://medium.com/@dpup/whiteboarding-4df873dbba2e#.hf6jn45g1)
- [ ] [揭秘技术招聘](https://www.youtube.com/watch?v=N233T0epWTs)
- [ ] 如何在科技四强企业中获得一份工作：
    - [ ] [“如何在科技四强企业中获得一份工作 —— Amazon、Facebook、Google 和 Microsoft”（视频）](https://www.youtube.com/watch?v=YJZCUhxNCv8)
- [ ] 解密开发类面试第一集：
    - [ ] [Gayle L McDowell —— 解密开发类面试（视频）](https://www.youtube.com/watch?v=rEJzOhC5ZtQ)
    - [ ] [解密开发类面试 —— 作者 Gayle Laakmann McDowell（视频）](https://www.youtube.com/watch?v=aClxtDcdpsQ)
- [ ] 解密 Facebook 编码面试：
    - [方法](https://www.youtube.com/watch?v=wCl9kvQGHPI)
    - [问题演练](https://www.youtube.com/watch?v=4UWDyJq8jZg)
- [ ] 准备课程：
    - [ ] [软件工程师面试发布（收费课程）](https://www.udemy.com/software-engineer-interview-unleashed)：
        - 从前 Google 面试官身上学习如何准备自己，让自己能够应付软件工程师的面试。
    - [ ] [Python 数据结构，算法和面试（收费课程）](https://www.udemy.com/python-for-data-structures-algorithms-and-interviews/)：
        - Python 面试准备课程，内容涉及数据结构，算法，模拟面试等。
    - [ ] [Python 的数据结构和算法简介（Udacity 免费课程）](https://www.udacity.com/course/data-structures-and-algorithms-in-python--ud513)：
        - 免费的 Python 数据结构和算法课程。
    - [ ] [数据结构和算法纳米学位！（Udacity 收费纳米学位）](https://www.udacity.com/course/data-structures-and-algorithms-nanodegree--nd256)：
        - 获得超过100种数据结构和算法练习以及指导的动手练习，专门导师帮助你在面试和职场中做好准备。
    - [ ] [探究行为面试（Educative 免费课程）](https://www.educative.io/courses/grokking-the-behavioral-interview)：
        - 很多时候，不是你的技术能力会阻碍你获得理想的工作，而是你在行为面试中的表现。

## 为你的面试选择一种语言

你可以在编程这一环节，使用一种自己用起来较为舒适的语言去完成编程，但对于大公司，你只有三种固定的选择：

- C++
- Java
- Python

我之前写过一篇关于在面试时选择编程语言的文章：[为编程面试选择一种语言](https://startupnextdoor.com/important-pick-one-language-for-the-coding-interview/)。

你需要对你所选择的语言感到非常舒适且足够了解。

更多关于语言选择的阅读：

- http://www.byte-by-byte.com/choose-the-right-language-for-your-coding-interview/
- http://blog.codingforinterviews.com/best-programming-language-jobs/

[在此查看相关语言的资源](../programming-language-resources.md)

由于我正在学习C、C++ 和 Python，因此在下面你会看到部分关于它们的学习资料。相关书籍请看文章的底部。

## 书单

为了节省你的时间，以下是比我使用过的更缩减的书单。

### 面试准备

- [ ] [Programming Interviews Exposed: Coding Your Way Through the Interview, 4th Edition](https://www.amazon.com/Programming-Interviews-Exposed-Through-Interview/dp/111941847X/)
    - 附有 C++ 和 Java 解答
    - 这是在练习 Cracking the Coding Interview 之前一个很好的热身
    - 不太困难，大多数问题可能比你在面试中看到的要容易（根据我的阅读）
- [ ] [Cracking the Coding Interview, 6th Edition](http://www.amazon.com/Cracking-Coding-Interview-6th-Programming/dp/0984782850/)
    - 附有 Java 答案

### 如果你有额外的时间：

选择以下之一：

- [ ] [Elements of Programming Interviews (C++ version)](https://www.amazon.com/Elements-Programming-Interviews-Insiders-Guide/dp/1479274836)
- [ ] [Elements of Programming Interviews in Python](https://www.amazon.com/Elements-Programming-Interviews-Python-Insiders/dp/1537713949/)
- [ ] Elements of Programming Interviews (Java version)
    - [书](https://www.amazon.com/Elements-Programming-Interviews-Java-Insiders/dp/1517435803/)
    - [配套项目──书中每个问题的方法和测试用例](https://github.com/gardncl/elements-of-programming-interviews)

### 编程语言精选

**你需要选择面试语言（请参见上文）。**

这是我按语言给出的建议。我没有所有语言的资源，欢迎贡献。

如果你通读其中之一，你应该具备了开始解决编程问题所需的所有数据结构和算法知识。除非你需要复习，否则**你可以跳过此项目中的所有视频讲座**。

[额外编程语言的精选资源](https://github.com/jwasham/coding-interview-university/blob/main/programming-language-resources.md)

### C++

我没有读过这两本书，但是它们颇受好评，作者是 Sedgewick，他非常厉害。

- [ ] [Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching](https://www.amazon.com/Algorithms-Parts-1-4-Fundamentals-Structure/dp/0201350882/)
- [ ] [Algorithms in C++ Part 5: Graph Algorithms](https://www.amazon.com/Algorithms-Part-Graph-3rd-Pt-5/dp/0201361183/)
- [ ] [Open Data Structures in C++](https://opendatastructures.org/ods-cpp.pdf)
    - 丰富而详细的数据结构和算法集合
    - 非常适合初学者

如果你有更好的 C++ 书籍，请告诉我。我正在搜集全面的资源。

### Python

- [ ] [Python数据结构和算法](https://www.amazon.com/Structures-Algorithms-Python-Michael-Goodrich/dp/1118290275/)
    - 作者：Goodrich、Tamassia、Goldwasser
    - 我非常喜爱这本书，它包含了所有东西
    - 很 Python 的代码
    - 我的读书报告：[startupnextdoor.com/book-report-data-structures-and-algorithms-in-python](https://startupnextdoor.com/book-report-data-structures-and-algorithms-in-python/)
- [ ] [Open Data Structures in Python](https://opendatastructures.org/ods-python.pdf)

## 在你开始之前

该列表已经持续更新了很长的一段时间，所以，我们的确很容易会对其失去控制。

这里列出了一些我所犯过的错误，希望你不要重滔覆辙。

### 1. 你不可能把所有的东西都记住

就算我观看了数小时的视频，并记录了大量的笔记，几个月后的我，仍然会忘却其中大部分的东西。所以，我花了3天翻阅我的笔记，并制作成抽认卡（flashcard）帮助我复习：

请阅读以下的文章以免重蹈覆辙:

[记住计算机科学知识](https://startupnextdoor.com/retaining-computer-science-knowledge/)。

有人推荐给我的课程（但我还沒看过）：[学习如何学习](https://www.coursera.org/learn/learning-how-to-learn)。

### 2. 使用抽认卡

为了解决善忘的问题，我制作了一个抽认卡的网页，用于添加两种抽认卡：一般的及带有代码的。每种卡都会有不同的格式设计。
而且，我还以移动设备为先去设计这些网页，以使得在任何地方，我都能通过我的手机及平板去回顾知识。
你也可以免费制作属于你自己的抽认卡网站：

- [抽认卡页面的代码仓库](https://github.com/jwasham/computer-science-flash-cards)
- [我的抽认卡数据库 ── 旧 1200 张](https://github.com/jwasham/computer-science-flash-cards/blob/main/cards-jwasham.db)
- [我的抽认卡数据库 ── 新 1800 张](https://github.com/jwasham/computer-science-flash-cards/blob/main/cards-jwasham-extreme.db)

有一点需要记住的是，我做事有点过头，以至于卡片都覆盖到所有的东西上，从汇编语言和 Python 的细枝末节，到机器学习和统计都被覆盖到卡片上。而这种做法，对于要求来说是多余的。

**在抽认卡上做笔记：** 若你第一次发现你知道问题的答案时，先不要急着把其标注成“已知”。反复复习这张抽认卡，直到每次都能答对后才是真正学会了这个问题。反复地问答可帮助你深刻记住该知识点。

### 3. 复习，复习，再复习

我留有一组 ASCII 码表、OSI 堆栈、Big-O 记号及更多的抽认卡，以便在空余的时候可以学习。
编程累了就休息半个小时，并去复习你的抽认卡。

### 4. 专注

在学习的过程中，往往会有许多令人分心的事占据着我们宝贵的时间。因此，专注和集中注意力是非常困难的。放点纯音乐能帮上一些忙。

## 没有包含的内容

有一些熟悉且普遍的技术在此未被谈及到：

- SQL
- Javascript
- HTML、CSS 和其他前端技术

## 日常计划

部分问题可能会花费一天的时间去学习，而有些则会花费多天。当然，有些学习并不需要我们懂得如何实现。

因此，每一天我都会在下面所列出的列表中选择一项，并观看相关的视频。然后，使用以下的一种语言去实现：

- C —— 使用结构体和函数，该函数会接受一个结构体指针 * 及其他数据作为参数。
- C++ —— 不使用内建的数据类型。
- C++ —— 使用内建的数据类型，如使用 STL 的 std::list 来作为链表。
- Python ——  使用内建的数据类型（为了持续练习 Python），并编写一些测试去保证自己代码的正确性。有时，只需要使用断言函数 assert() 即可。

你不需要学会所有的编程语言，你只需要专注在[一种编程语言](##为你的面试选择一种语言)上。

为何要在这些语言上分别实现一次？

- 练习，练习，练习，直至我厌倦它，并正确无误地实现出来。（若有部分边缘条件没想到时，我会用书写的形式记录下来并去记忆）
- 在纯原生的条件下工作（不需垃圾回收机制的帮助下，手动分配/释放内存（除了 Python））
- 利用语言内建的数据类型，之后在实际工作的时候才能得心应手（在生产环境中，我不会去实现自己的链表）

就算我没有时间去每一项都这么做，但我也会尽我所能。

在这里你可以查看到我的代码：

- [C](https://github.com/jwasham/practice-c)
- [C++](https://github.com/jwasham/practice-cpp)
- [Python](https://github.com/jwasham/practice-python)

你不需要记住每一个算法的内部原理。
在一个白板上写代码，而不要直接在计算机上编写。在测试完部分简单的输入后，到计算机上再测试一遍。

## 终面

    这一部分有一些短视频，你可以快速的观看和复习大多数重要概念。
    这对经常性的巩固很有帮助。

- [ ] 2-3分钟的简短主题视频系列（23个视频）
    - [视频](https://www.youtube.com/watch?v=r4r1DZcx1cM&list=PLmVb1OknmNJuC5POdcDv5oCS7_OUkDgpj&index=22)
- [ ] 2-5分钟的简短主题视频系列──Michael Sambol（18个视频）：
    - [视频](https://www.youtube.com/channel/UCzDJwLWoYCUQowF_nG3m5OQ)
- [ ] [Sedgewick 视频 ── 算法I](https://www.coursera.org/learn/algorithms-part1)
- [ ] [Sedgewick 视频 ── 算法II](https://www.coursera.org/learn/algorithms-part2)

## 编程问题练习

现在你已经了解了上面所有的计算机科学主题，是时候练习回答编程问题了。

**编程问题的实践并不是要记住编程问题的答案**。

为什么需要练习编程问题：

- 快速识别问题，以及如何应用正确的数据结构及算法
- 收集问题的要求
- 像在面试中一样谈论问题
- 在白板或纸上而非计算机上编码
- 计算解决方案的时间和空间的复杂性
- 测试你的解决方案

这里有个很棒的入门教学，内容是如何在面试中有条不紊，并且有互动沟通地解决问题。这种能力可以从面试书籍中获得，但我觉得这个也很棒：[算法设计画布](http://www.hiredintech.com/algorithm-design/)。

家里没有白板？那讲得通。我是一个怪人，有一个很大的白板。从白板商店买了一个大的绘图板，而不是白板。你可以坐在沙发上练习。这是我的“沙发白板”。我在照片中添加了笔以便进行缩放。如果你使用笔，则希望可以擦除。快速变得凌乱。我用铅笔和橡皮擦。

补充：

- [Topcoder的数学](https://www.topcoder.com/community/competitive-programming/tutorials/mathematics-for-topcoders/)
- [动态编程──从新手到高级](https://www.topcoder.com/community/competitive-programming/tutorials/dynamic-programming-from-novice-to-advanced/)
- [MIT 面试材料](https://web.archive.org/web/20160906124824/http://courses.csail.mit.edu/iap/interview/materials.php)

**阅读并练习编程问题（按此顺序）**：

- [ ] [编程面试公开：下一份工作的秘密，第二版](http://www.wiley.com/WileyCDA/WileyTitle/productCd-047012167X.html)
    - C，C ++ 和 Java 的答案
- [ ] [破解编码面试，第六版](http://www.amazon.com/Cracking-Coding-Interview-6th-Programming/dp/0984782850/)
    - Java 答案

请参阅上方的[书单](#书单)。

## 编程练习和挑战

一旦你学会了理论基础，就应该把它们拿出来练练。
尽量坚持每天做编码练习，越多越好。

- [如何找到解决方案](https://www.topcoder.com/community/competitive-programming/tutorials/how-to-find-a-solution/)
- [如何剖析 Topcoder 题目描述](https://www.topcoder.com/community/competitive-programming/tutorials/how-to-dissect-a-topcoder-problem-statement/)

编码面试问题视频：

- [IDeserve（88个视频）](https://www.youtube.com/watch?v=NBcqBddFbZw&list=PLamzFoFxwoNjPfxzaWqs7cZGsPYy0x_gI)
- [Tushar Roy（5个播放列表）](https://www.youtube.com/user/tusharroy2525/playlists?shelf_id=2&view=50&sort=dd)
    - 超级解决问题的方法
- [Nick White──LeetCode 解题（187个视频）](https://www.youtube.com/playlist?list=PLU_sdQYzUj2keVENTP0a5rdykRSgg9Wp-)
    - 良好的解决方案和代码解释
    - 你可以在短时间内看好几个
- [FisherCoder──LeetCode 解题](https://youtube.com/FisherCoder)

编码练习平台:

- [LeetCode](https://leetcode.com/)
    - 我最喜欢的编码问题网站，值得你准备的1-2个月的订阅费用
    - [FisherCoder 的 LeetCode 解题](https://github.com/fishercoder1534/Leetcode)
    - 请参阅上面的 Nick White 视频，以获得简短的代码
- [HackerRank](https://www.hackerrank.com/)
- [TopCoder](https://www.topcoder.com/)
- [InterviewCake](https://www.interviewcake.com/)
- [http://www.geeksforgeeks.org/](http://www.geeksforgeeks.org/)
- [InterviewBit](https://www.interviewbit.com)
- [Project Euler (数学方向为主)](https://projecteuler.net/index.php?section=problems)
- [Code Exercises](https://code-exercises.com/)

语言学习网站，附带编码挑战：

- [Codewars](http://www.codewars.com)
- [Codility](https://codility.com/programmers/)
- [HackerEarth](https://www.hackerearth.com/)
- [Sphere Online Judge (spoj)](http://www.spoj.com/)
- [Codechef](https://www.codechef.com/)

编码挑战项目：

- [Python 交互式编码面试挑战](https://github.com/donnemartin/interactive-coding-challenges)

模拟面试：

- [Gainlo.co：来自大公司的模拟面试官](http://www.gainlo.co/#!/)──我使用了它，它帮助我减轻了电话屏幕和现场面试的压力
- [Pramp：模拟来自/与同行的面试](https://www.pramp.com/)──点对点方式练习面试
- [Refdash：模拟面试和加急面试](https://refdash.com/)──跳过与科技公司的多次面试，帮助求职者快速追踪
- [interviewing.io：与高级工程师进行模拟面试](https://interviewing.io/)──与来自 FAANG（译者注：Facebook, Amazon, Apple, Netflix and Google） 的高级工程师进行匿名算法/系统设计面试。

## 当你临近面试时

- 搞定代码面试──第二集 (视频):
    - [Cracking The Code Interview](https://www.youtube.com/watch?v=4NIb9l3imAo)
    - [Cracking the Coding Interview - 全栈系列](https://www.youtube.com/watch?v=Eg5-tdAwclo)

## 你的简历

- 请参阅“破解编码面试”和“编程面试的背面”中的建立准备项。

## 当面试来临的时候

随着下面列举的问题思考下你可能会遇到的 20 个面试问题，每个问题准备 2-3 种回答。准备点故事，不要只是摆一些你完成的事情的数据，相信我，人人都喜欢听故事。

- 你为什么想得到这份工作？
- 你解决过的最有难度的问题是什么？
- 面对过的最大挑战是什么?
- 见过的最好或者最坏的设计是怎么样的?
- 对某个产品提出改进建议。
- 你作为一个个体同时也是团队的一员，如何达到最好的工作状态?
- 你的什么技能或者经验是你的角色中不可或缺的，为什么？
- 你在某份工作或某个项目中最享受的是什么?
- 你在某份工作或某个项目中面临过的最大挑战是什么?
- 你在某份工作或某个项目中遇到过的最硬的 Bug 是什么样的？
- 你在某份工作或某个项目中学到了什么？
- 你在某份工作或某个项目中哪些地方还可以做的更好？

## 问面试官的问题

    我会问的一些：(可能我已经知道了答案但我想听听面试官的看法或者了解团队的前景):

- 团队多大规模?
- 开发周期是怎样的? 会使用瀑布流/极限编程/敏捷开发么?
- 经常会为截止日期（deadlines）加班么? 或者是有弹性的?
- 团队里怎么做技术选型?
- 每周平均开多少次会?
- 你觉得工作环境有助于员工集中精力吗?
- 目前正在做什么工作?
- 喜欢这些事情吗?
- 工作期限是怎么样的?
- 工作生活怎么平衡?