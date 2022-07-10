## 必备知识

- [ ] **学习C语言**
    - C 语言无处不在。在学习的过程中，你会在书籍，讲座，视频等任何地方看到它的身影
    - [ ] [C程序设计语言，第二版](https://www.amazon.com/Programming-Language-Brian-W-Kernighan/dp/0131103628)
        - 这是一本简短的书，但是它将使你更好地使用 C 语言，并且如果你稍加练习，就会很快熟练。理解 C 可帮助你了解程序和内存的工作方式
        - 问题答案

- [x] **计算机是如何处理一段程序：**
    - [x] [CPU 是如何执行代码（视频）](https://www.youtube.com/watch?v=XM4lGflQFvA)
    - [x] [计算机如何计算（视频）](https://youtu.be/1I5ZMmrOfnA)
    - [x] [寄存器和内存（视频）](https://youtu.be/fpnE6UAfbtU)
    - [x] [中央处理单元（视频）](https://youtu.be/FZGugFqdr60)
    - [x] [指令和程序（视频）](https://youtu.be/zltgXvg6r3k)

## 算法复杂度 / Big-O / 渐进分析法

- 并不需要实现
- [x] [速查表（Cheat sheet）](http://bigocheatsheet.com/)

<img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/bigO-for-common-data-structure-ops.jpg" width="450px">        

<img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/bigO-array-sorting-algorithms.jpg" width="300px"> 

## 数据结构
- ### 数组（Arrays）
    - 实现一个可自动调整大小的动态数组。
    - [x] 介绍：
        - [数组（视频）](https://www.coursera.org/learn/data-structures/lecture/OsBSF/arrays)
        - [UC Berkeley CS61B - 线性数组和多维数组（视频）](https://archive.org/details/ucberkeley_webcast_Wp8oiO_CZZE)（从15分32秒开始）
        - [动态数组（视频）](https://www.coursera.org/learn/data-structures/lecture/EwbnV/dynamic-arrays)
        - [不规则数组（视频）](https://www.youtube.com/watch?v=1jtrQqYpt7g)
    - [ ] 实现一个动态数组（可自动调整大小的可变数组）：
        - [ ] 练习使用数组和指针去编码，并且指针是通过计算去跳转而不是使用索引
        - [ ] 通过分配内存来新建一个原生数据型数组
            - 可以使用 int 类型的数组，但不能使用其语法特性
            - 从大小为16或更大的数（使用2的倍数 —— 16、32、64、128）开始编写
        - [ ] size() —— 数组元素的个数
        - [ ] capacity() —— 可容纳元素的个数
        - [ ] is_empty()
        - [ ] at(index) —— 返回对应索引的元素，且若索引越界则愤然报错
        - [ ] push(item)
        - [ ] insert(index, item) —— 在指定索引中插入元素，并把后面的元素依次后移
        - [ ] prepend(item) —— 可以使用上面的 insert 函数，传参 index 为 0
        - [ ] pop() —— 删除在数组末端的元素，并返回其值
        - [ ] delete(index) —— 删除指定索引的元素，并把后面的元素依次前移
        - [ ] remove(item) —— 删除指定值的元素，并返回其索引（即使有多个元素）
        - [ ] find(item) —— 寻找指定值的元素并返回其中第一个出现的元素其索引，若未找到则返回 -1
        - [ ] resize(new_capacity) // 私有函数
            - 若数组的大小到达其容积，则变大一倍
            - 获取元素后，若数组大小为其容积的1/4，则缩小一半
    - [ ] 时间复杂度
        - 在数组末端增加/删除、定位、更新元素，只允许占 O(1) 的时间复杂度（平摊（amortized）去分配内存以获取更多空间）
        - 在数组任何地方插入/移除元素，只允许 O(n) 的时间复杂度
    - [ ] 空间复杂度
        - 因为在内存中分配的空间邻近，所以有助于提高性能
        - 空间需求 = （大于或等于 n 的数组容积）* 元素的大小。即便空间需求为 2n，其空间复杂度仍然是 O(n)

- ### 链表（Linked Lists）
    - [x] 介绍：
        - [x] [单向链表（视频）](https://www.coursera.org/learn/data-structures/lecture/kHhgK/singly-linked-lists)
        - [x] [CS 61B —— 链表（一）（视频）](https://archive.org/details/ucberkeley_webcast_htzJdKoEmO0)
        - [x] [CS 61B —— 链表（二）（视频）](https://archive.org/details/ucberkeley_webcast_-c4I3gFYe3w)
    - [x] [C 代码（视频）](https://www.youtube.com/watch?v=QN6FPiD0Gzo) ── 并非看完整个视频，只需要看关于节点结构和内存分配那一部分即可
    - [ ] 链表 vs 数组：
        - 链表&数组 关于 插入、查找、删除操作 的复杂度，详见BigO章节处的比较。
        - 链表更便于写；数组更便于读。
        - [基本链表 Vs 数组（视频）](https://www.coursera.org/lecture/data-structures-optimizing-performance/core-linked-lists-vs-arrays-rjBs9)
        - [在现实中，链表 Vs 数组（视频）](https://www.coursera.org/lecture/data-structures-optimizing-performance/in-the-real-world-lists-vs-arrays-QUaUd)
    - [x] [为什么你需要避免使用链表（视频）](https://www.youtube.com/watch?v=YQs6IC-vgmo)
        - array是连续存储的，这是的array比链表快很多。
    - [ ] 的确：你需要关于“指向指针的指针”的相关知识：（因为当你传递一个指针到一个函数时，该函数可能会改变指针所指向的地址）该页只是为了让你了解“指向指针的指针”这一概念。但并不推荐这种链式遍历的风格。因为，这种风格的代码，其可读性和可维护性太低。
        - [指向指针的指针](https://www.eskimo.com/~scs/cclass/int/sx8.html)
    - [ ] 实现（我实现了使用尾指针以及没有使用尾指针这两种情况）：
        - [ ] size() —— 返回链表中数据元素的个数
        - [ ] empty() —— 若链表为空则返回一个布尔值 true
        - [ ] value_at(index) —— 返回第 n 个元素的值（从0开始计算）
        - [ ] push_front(value) —— 添加元素到链表的首部
        - [ ] pop_front() —— 删除首部元素并返回其值
        - [ ] push_back(value) —— 添加元素到链表的尾部
        - [ ] pop_back() —— 删除尾部元素并返回其值
        - [ ] front() —— 返回首部元素的值
        - [ ] back() —— 返回尾部元素的值
        - [ ] insert(index, value) —— 插入值到指定的索引，并把当前索引的元素指向到新的元素
        - [ ] erase(index) —— 删除指定索引的节点
        - [ ] value_n_from_end(n) —— 返回倒数第 n 个节点的值
        - [ ] reverse() —— 逆序链表
        - [ ] remove_value(value) —— 删除链表中指定值的第一个元素
    - [x] 双向链表
        - [介绍（视频）](https://www.coursera.org/learn/data-structures/lecture/jpGKD/doubly-linked-lists)
        - 并不需要实现

- ### 堆栈（Stack）
    - [x] [堆栈（视频）](https://www.coursera.org/learn/data-structures/lecture/UdKzQ/stacks)
    - [x] 可以不实现，因为使用数组来实现并不重要

- ### 队列（Queue）
    - [x] [队列（视频）](https://www.coursera.org/learn/data-structures/lecture/EShpq/queue)
    - [x] [原型队列/先进先出（FIFO）](https://en.wikipedia.org/wiki/Circular_buffer)
    - [ ] 使用含有尾部指针的链表来实现:
        - enqueue(value) —— 在尾部添加值
        - dequeue() —— 删除最早添加的元素并返回其值（首部元素）
        - empty()
    - [ ] 使用固定大小的数组实现：
        - enqueue(value) —— 在可容的情况下添加元素到尾部
        - dequeue() —— 删除最早添加的元素并返回其值
        - empty()
        - full()
    - [ ] 花销：
        - 在糟糕的实现情况下，使用链表所实现的队列，其入列和出列的时间复杂度将会是 O(n)。因为，你需要找到下一个元素，以致循环整个队列
        - enqueue：O(1)（平摊（amortized）、链表和数组 [探测（probing）]）
        - dequeue：O(1)（链表和数组）
        - empty：O(1)（链表和数组）

- ### 哈希表（Hash table）
    - [x] [背景](https://zhuanlan.zhihu.com/p/268866673)
        - 链表查找复杂度O(n)，如何优化？
        - 借助二分查找的思想 => 跳表(在链表中隔一段建立一个索引)
        - 更进一步 => 为每个元素建立索引  => 哈希表

        <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/hash-map-sample.jpg" width="300px">   

        - 定义
            - 哈希函数: 计算key得到唯一的非负整数；when key1 = key2，那hash(key1) = hash(key2); when key1 != key2，那hash(key1) != hash(key2);
            - 散列冲突: 因为现实中存储数据的空间有限 => 散列冲突无法避免
                - 开放寻址法(open address): 
                    - 线性探测法：从当前位置开始，依次向后查找，看是否有空闲位置，直到找到为止;
                    - 二次探测法：将线性探测的步长变为原来的二次方：hash(key)+0 ... hash(key)+1^i 或 hash(key)-1^i
                    - 双重散列法：double hash： h_{i}(key) = (h1(key)+i*h2(key))%m ; 0≤i≤m-1 
                    即探查序列为：d=h1(key)，(d+h2(key))%m，(d+2h2(key))%m，…，等。
                    - 缺点明显: 随着插入的数据越多，散列冲突的概率越大
                - 链表法(chaining):     
                <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/hash-map-chaining-sample.jpg" width="400px">       

    - [ ] 视频：
        - [x] [链式哈希表（视频）](https://www.youtube.com/watch?v=0M_kIqhwbFo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=8)
        - [x] [Table Doubling 和 Karp-Rabin（视频）](https://www.youtube.com/watch?v=BRO7mVIFt08&index=9&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
            - Karp-Rabin算法 - 字符串匹配算法 (给定字符串text和模式串pat，输出text中所有与pat相等的子串)
            - 算法思路：滚动计算子串的hash，再通过与pat的hash只进行比较来得到 O(n)
            <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/rabin-karp.png" width="400px">     
        - [x] [Open Addressing 和密码型哈希（Cryptographic Hashing）（视频）](https://www.youtube.com/watch?v=rvdJDijO2Ro&index=10&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
            - 注意删除操作：删除造成的空格，可能会影响 开放寻址的 Search操作<一次查找到第一个空格为止>
            - 用一个标记delete的标记标记这个空格
            - open addressing 需要保持装载因子保持在0.5左右<不超过0.5>
        - [ ] [PyCon 2010：The Mighty Dictionary（视频）](https://www.youtube.com/watch?v=C4Kc8xzcA68)
        - [ ] [（进阶）随机取样（Randomization）：全域哈希（Universal Hashing）& 完美哈希（Perfect Hashing）（视频）](https://www.youtube.com/watch?v=z0lJ2k0sl1g&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=11)
        - [ ] [（进阶）完美哈希（Perfect hashing）（视频）](https://www.youtube.com/watch?v=N0COwN14gt0&list=PL2B4EEwhKD-NbwZ4ezj7gyc_3yNrojKM9&index=4)
        - [ ] [电话薄问题（Phone Book Problem）（视频）](https://www.coursera.org/learn/data-structures/lecture/NYZZP/phone-book-problem)
        - [ ] 分布式哈希表：
            - [Dropbox 中的瞬时上传及存储优化（视频）](https://www.coursera.org/learn/data-structures/lecture/DvaIb/instant-uploads-and-storage-optimization-in-dropbox)
            - [分布式哈希表（视频）](https://www.coursera.org/learn/data-structures/lecture/tvH8H/distributed-hash-tables)

    - [ ] 使用线性探测的数组去实现
        - hash(k, m) —— m 是哈希表的大小
        - add(key, value) —— 如果 key 已存在则更新值
        - exists(key)
        - get(key)
        - remove(key)

## 更多的知识

- ### 二分查找（Binary search）
    - [x] [二分查找（视频）](https://www.youtube.com/watch?v=D5SrAga1pno)
    - [x] [二分查找（视频）](https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search)
    - [x] [详情](https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/)
    - [ ] 实现：
        - 二分查找（在一个已排序好的整型数组中查找）
        - 迭代式二分查找

- ### 按位运算（Bitwise operations）
    - [ ] [Bits 速查表](https://github.com/jwasham/coding-interview-university/blob/main/extras/cheat%20sheets/bits-cheat-sheet.pdf) ── 你需要知道大量2的幂数值（从2^1 到 2^16 及 2^32）
    - [x] 好好理解位操作符的含义：&、|、^、~、>>、<<
        - [x] [字码（words）](https://en.wikipedia.org/wiki/Word_(computer_architecture))
        - [x] 好的介绍：
            [位操作（视频）](https://www.youtube.com/watch?v=7jkIUgLC29I)
        - [x] [C 语言编程教程 2-10：按位运算（视频）](https://www.youtube.com/watch?v=d0AwjSpNXR0)
        - [x] [位操作](https://en.wikipedia.org/wiki/Bit_manipulation)
        - [x] [按位运算](https://en.wikipedia.org/wiki/Bitwise_operation)
        - [ ] [Bithacks](https://graphics.stanford.edu/~seander/bithacks.html)  -- 位运算优秀示例代码
        - [ ] [位元抚弄者（The Bit Twiddler）](http://bits.stephan-brumme.com/)  -- 位运算完整C代码
        - [ ] [交互式位元抚弄者（The Bit Twiddler Interactive）](http://bits.stephan-brumme.com/interactive.html)
        - [ ] [位操作技巧（Bit Hacks）（视频）](https://www.youtube.com/watch?v=ZusiKXcz_ac)
        - [x] [练习位操作](https://pconrad.github.io/old_pconrad_cs16/topics/bitOps/)   -- 练习网页
    - [x] 一补数和补码
         - [二进制：利 & 弊（为什么我们要使用补码）（视频）](https://www.youtube.com/watch?v=lKTsv6iVxV4) 
        > 1、正数和0的补码就是该数字本身再补上最高位元0。负数的补码则是将其对应正数按位取反再加1。  
        > 2、补码系统的最大优点是可以在加法或减法处理中，不需因为数字的正负而使用不同的计算方式。只要一种加法电路就可以处理各种有号数加法，而且减法可以用一个数加上另一个数的补码来表示，因此只要有加法电路及补码电路即可完成各种有号数加法及减法，在电路设计上相当方便。  
        > 3、在n位元的补码加减法中，忽略第n+1个位元的作法在各种有号数加法下都适用（不过在判断是否溢出（overflow）时，仍然会用到第n+1个位元)

        ```
           0011 (3)
         + 1111 (-1)
        --------------
          10010 (2)
        ```
        - [补数（1s Complement）](https://zh.wikipedia.org/zh-sg/%E8%A1%A5%E6%95%B0)
        - [补码（2s Complement）](https://zh.wikipedia.org/zh-sg/%E4%BA%8C%E8%A3%9C%E6%95%B8)
    - [x] 计算比特位（Set Bits）
        - [计算比特位](https://youtu.be/Hzuzo9NJrlc)
        ```
        1，位运算屏蔽其他位 + count
        2，mask方法
           byte i = -1
           byte mask1 = 0b01010101
           byte mask2 = 0b00110011
           byte mask3 = 0b00001111  // 到 Byte/2 为止
           i = i & mask1 + (i >> 1) & mask1
           i = i & mask2 + (i >> 2) & mask2
           i = i & mask3 + (i >> 3) & mask3  // 此时i的值即为1的数量
        ```
        - [计算比特位](https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan)
        - [如何在一个 32 位的整型中计算置位（Set Bits）的数量](http://stackoverflow.com/questions/109023/how-to-count-the-number-of-set-bits-in-a-32-bit-integer)
        ```
        // 上面mask方法的实现
        int numberOfSetBits(uint32_t i){
             // C or C++: use uint32_t
             i = i - ((i >> 1) & 0x55555555);        // add pairs of bits
             i = (i & 0x33333333) + ((i >> 2) & 0x33333333);  // quads
             i = (i + (i >> 4)) & 0x0F0F0F0F;        // groups of 8
             return (i * 0x01010101) >> 24;          // horizontal sum of bytes
        }
        ```
    - [x] 交换值：
        - [交换（Swap）](http://bits.stephan-brumme.com/swap.html)
        ```
        // 与同一个值进行两次异或处理，能回到原值
        void swapXor(int& a, int& b){
            a ^= b;
            b ^= a;
            a ^= b;
        }

        void swapTemp(int& a, int& b){
            int temp = a;
            a = b;
            b = temp;
        }
        ```
    - [x] 绝对值：
        - [绝对整型（Absolute Integer）](http://bits.stephan-brumme.com/absInteger.html)
        ```
        // 利用正负数补码的逻辑处理的
        int myAbs(int x){
            const int bit31 = x >> 31;  // 正数为0，负数为-1
            return (x ^ bit31) - bit31;
        }
        ```

## 树（Trees）

- ### 树 —— 笔记 & 背景
    - [x] [树](https://zh.wikipedia.org/wiki/%E6%A0%91_(%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84))
    - 基本的树形结构
        - [x] 完全二叉树 : 一棵深度为d的二叉树，除d层以外的其它各层节点数目均已达最大值，且第d层所有节点从左向右连续地紧密排列
        - [x] 平衡二叉树(AVL树) : 当且仅当任何节点的两棵子树的高度差不大于1的二叉树
        - [x] Binary Search Tree
    - [x] 深度&高度:  
        - 深度：任意子节点到根节点的唯一路径长度  
        - 高度：全部叶子节点到根节点路径中最长路径的长度
    - [x] [BFS（广度优先检索，breadth-first search）和 DFS（深度优先检索，depth-first search）](https://www.youtube.com/watch?v=uWL6FJhq5fM)
        - BFS 笔记
            - 层序遍历（使用队列的 BFS 算法）
            - 时间复杂度： O(n)
            - 空间复杂度：
                - 最好情况：O(1)
                - 最坏情况：O(n/2)=O(n)
        - DFS 笔记：
            - 时间复杂度：O(n)
            - 空间复杂度：
                - 最好情况：O(log n) - 树的平均高度
                - 最坏情况：O(n)
            - 中序遍历（DFS：左、节点本身、右）
            - 后序遍历（DFS：左、右、节点本身）
            - 先序遍历（DFS：节点本身、左、右）


- ### 二叉查找树（Binary search trees）：BSTs
    - [x] [二叉查找树概览（视频）](https://www.youtube.com/watch?v=x6At0nzX92o&index=1&list=PLA5Lqm4uh9Bbq-E0ZnqTIa8LRaL77ica6)
    - [x] [MIT视频课程（视频）](https://www.youtube.com/watch?v=9Jry5-82I68)
    - C/C++:
        - [x] [二叉查找树 —— 在 C/C++ 中实现（视频）](https://www.youtube.com/watch?v=COZK7NATh4k&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=28)
        - [ ] [BST 的实现 —— 在堆栈和堆中的内存分配（视频）](https://www.youtube.com/watch?v=hWokyBoo0aI&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=29)
        - [x] [在二叉查找树中找到最小和最大的元素（视频）](https://www.youtube.com/watch?v=Ut90klNN264&index=30&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P)
            - min: 持续寻找左子节点: 左子节点 < 根节点 < 右子节点
            - max: 持续寻找右子节点
        - [x] [寻找二叉树的高度（视频）](https://www.youtube.com/watch?v=_pnqMz5nrRs&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=31)
            - height(root) = max(height(root->left), height(root->right)) + 1
        - [x] [判断一棵二叉树是否为二叉查找树（视频）](https://www.youtube.com/watch?v=yEwSGhSsT0U&index=35&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P)
            - 判断是否 左子树 < 根节点 < 右子树  for the hole tree and all sub-tree
    - [x] **[代码实现](https://github.com/kexinchu/algo/tree/master/C-Cplusplus/binary_search_tree)**：
        - [x] insert         // 往树上插值
        - [x] get_node_count // 查找树上的节点数
        - [x] print_values   // 实现 BFS<层序> DFS<前序，中序，后序>
        - [x] delete_tree
        - [x] get_height     // 返回节点所在的高度（如果只有一个节点，那么高度则为1）
        - [x] get_min        // 返回树上的最小值
        - [x] get_max        // 返回树上的最大值
        - [x] is_binary_search_tree
        - [x] delete_value
        - [x] get_successor  // 返回给定值的后继者，若没有则返回-1

- ### 平衡查找树 (Balanced search trees)
    - [x] 掌握至少一种平衡查找树(并懂得如何实现 - 主要关注插入，删除之后的自平衡方法)
    - “在各种平衡查找树当中，AVL树和2-3树已经成为了过去，而红黑树（red-black trees），伸展树（splay tree）看似变得越来越受人青睐。
        - 伸展树：插入、查找、删除函数的实现，而如果你最终实现了红黑树，那么请尝试一下：
        - 跳过删除函数，直接实现搜索和插入功能
    - [x] [自平衡二叉查找树](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)  

    - [x] **[AVL 树](https://zh.m.wikipedia.org/zh-hans/AVL%E6%A0%91)**
        - 实际中：我能告诉你的是，该种树并无太多的用途，但我能看到有用的地方在哪里：AVL 树是另一种平衡查找树结构。其可支持时间复杂度为 O(log n) 的查询、插入及删除。它比红黑树严格意义上更为平衡，从而导致插入和删除更慢，但遍历却更快。正因如此，才彰显其结构的魅力。只需要构建一次，就可以在不重新构造的情况下读取，适合于实现诸如语言字典（或程序字典，如一个汇编程序或解释程序的操作码）。
        - 高度平衡树: 任一节点的两个子树的高度差不超过1;  
        - LL/RR/LR/RL  
        ![LL/RR/RL/LR](https://github.com/kexinchu/coding-interview-university/blob/main/pictures/avl-tree_rebalancing.png)
        - [x] **自平衡的实现**   
        ```
        // 节点左子树高度 > 右子树高度
        // LL: 左子树的左子树高度 > 左子树的右子树  =>  右旋
        // LR: 左子树的右子树高度 > 左子树的左子树  =>  先对左子树左旋，转换成LL，再右旋
        // 节点右子树高度 > 左子树高度
        // RR: 右子树的右子树高度 > 右子树的左子树  =>  左旋
        // RL: 右子树的左子树高度 > 右子树的右子树  =>  先对右子树右旋，转换成RR，再左旋
        
        NodePtr left_left_rotation(NodePtr node) {
            NodePtr p = node->left;
            node->left = p->right;
            p->right = node;
        }
    
        NodePtr right_right_rotation(NodePtr node) {
            NodePtr p = node->right;
            node->right = p->left;
            p->left = node;
        }
    
        NodePtr left_right_rotation(NodePtr node) {
            node->left = right_right_rotation(node->left);
            return left_left_rotation(node);
        }
    
        NodePtr right_left_rotation(NodePtr node) {
            node->right = left_left_rotation(node->right);
            return right_right_rotation(node);
        }
        ```

        - [x] **[实现代码](https://github.com/kexinchu/algo/tree/master/C-Cplusplus/binary_search_tree)**   

        
    - [x] **[伸展树](https://zh.wikipedia.org/wiki/%E4%BC%B8%E5%B1%95%E6%A0%91)**  
        - 实际中：伸展树一般用于缓存、内存分配者、路由器、垃圾回收者、数据压缩、ropes(字符串的一种替代品，用于存储长串的文本字符)、Windows NT（虚拟内存、网络及文件系统）等的实现。
        - 能在均摊{\displaystyle O(\log n)}O(\log n)的时间内完成基于伸展（Splay）操作的插入、查找、修改和删除操作
        - 定义&原理：参考LRU，假设想要对一个二叉查找树执行一系列的查找操作，为了使整个查找时间更小，被查频率高的那些条目就应当经常处于靠近树根的位置。=> 于是想到设计一个简单方法，在每次查找/插入之后对树进行调整，把被查找/新插入的条目搬移到离树根近一些的地方。
        - 优点：存储所需的内存少 —— 伸展树无需记录额外的什么值来维护树的信息，相对于其他平衡树，内存占用要小。(PS: AVL树需要记录节点高度，红黑树需要记录节点颜色)
        - [x] **[代码实现](https://github.com/kexinchu/algo/tree/master/C-Cplusplus/binary_search_tree)**:
            - 伸展(Splay)操作：当节点x被访问后，将x移动到根节点
            ```
            // 利用一系列的左旋(Zag)和右旋(Zig)操作实现
            // 每次旋转都由三个因素决定：
            //   x是其父节点p的左儿子还是右儿子；
            //   p是否为根；
            //   p是其父节点g（x的祖父节点）的左儿子还是右儿子。
            可以分为一下6中情况
            case1, Zig: x是p的左子节点，p为根节点，右旋
            case2, Zig-Zig: x是p的左子节点，p为g的左子节点，先绕g右旋，再绕p右旋
            case3, Zig-Zag: x是p的左子节点，p为g的右子节点，先绕p右旋，再绕g左旋
            case4, Zag: x是p的右子节点，p为根节点，左旋
            case5, Zag-Zag: x是p的右子节点，p为g的右子节点，先绕g左旋，再绕p左旋
            case6, Zag-Zig: x是p的右子节点，p为g的左子节点，先绕p左旋，再绕g右旋
            ```
            - 插入: 先插入，再Splay
            - 删除: 先Splay到根节点 => 删除根节点
            ```
            case1, 只有一个子节点，直接用该子节点替换根节点，删除根节点
            case2, 左右子树均存在，将左子树中的最大节点Splay到左子节点处(此时左子节点无右孩子)，把根结点的右孩子挂接到左孩子的右孩子位置,删除跟节点
            ```
            - 查找: 先查找，再Splay
        
        - [CS 61B：伸展树（Splay trees）（视频）](https://www.youtube.com/watch?v=Najzh1rYQTo&index=23&list=PL-XXv-cvA_iAlnI-BQr9hjqADPBtujFJd)
        - MIT 教程：伸展树（Splay trees）：
            - 该教程会过于学术，但请观看到最后的10分钟以确保掌握。
            - [视频](https://www.youtube.com/watch?v=QnPl_Y6EqMo)
            
    - [x] **[红黑树](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)**
        - [x] 定义:满足以下四个条件即为红黑树
        ```
        1，根节点为黑;
        2，叶子节点为黑色 null节点;
        3，约束红节点不能相邻放置;
        4，约束根->叶子路径中黑节点个数相等
        ```
        <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/red-black_tree_example.png" width="350px">   

        - [x] 实际中，**红黑树的高度不会超过 2*log2n；这保证了最坏情况下插入、删除和查找操作的时间复杂度**。
        - [x] 适用场景：用到动态插入，删除，查找数据的场景都可以 —— 例如，目前 Linux 内核所采用的完全公平调度器（the Completely Fair Scheduler）也使用到了红黑树树。在 Java 8中，Collection HashMap也从原本用Linked List实现，储存特定元素的哈希码，改为用红黑树实现。
        - [Aduni —— 算法 —— 课程4（该链接直接跳到开始部分）（视频）](https://youtu.be/1W3x0f_RmUo?list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&t=3871)
        - [Aduni —— 算法 —— 课程5（视频）](https://www.youtube.com/watch?v=hm2GHwyKF1o&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=5)
        - [二分查找及红黑树的介绍](https://www.topcoder.com/community/data-science/data-science-tutorials/an-introduction-to-binary-search-and-red-black-trees/)  
        - [x] **[代码实现](https://github.com/kexinchu/algo/tree/master/C-Cplusplus/binary_search_tree)**
            - 插入操作 - 插入节点设为红色 & 新插入的节点都放在叶子节点上 & 设a为关注节点  <平衡红色节点不相邻>
                - case1，a为根节点，直接变颜色为黑
                - case2，a的父节点颜色为黑色，什么都不用做
                - case3，a的父节点为红色，叔节点也为红色   =>  父/叔变黑，祖父变红，设祖父节点为新的关注节点      

                <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/red-black-tree-insert-case3.png" width="200px">       

                - 下面父节点为红，叔节点为黑，需要根据 祖父->父节点->a 的关系来判断
                    - case4，父节点是祖父节点的左子节点，且a为父节点的右子节点 (LR结构) =>  围绕父节点左旋，设置父节点为关注节点<形成LL结构>     

                    <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/red-black-tree-insert-case4.png" width="200px">    

                    - case5，父节点是祖父节点的左子节点，且a为父节点的左子节点 (LL结构)  =>  围绕祖父节点右旋，交换父节点与祖父节点的颜色；结束     

                    <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/red-black-tree-insert-case5.png" width="200px">    

                    - case6，父节点是祖父节点的右子节点，且a为父节点的左子节点 (RL结构) =>  围绕父节点右旋，设置父节点为关注节点<形成RR结构>     

                    - case7，父节点是祖父节点的右子节点，且a为父节点的右子节点 (RR结构)  =>  围绕祖父节点左旋，交换父节点与祖父节点的颜色；结束     

            - 删除操作
                - 1，待删除节点的三种情况分类
                ```
                1，待删除节点为叶子节点；
                2，待删除节点只有一个子节点，(此时根据红黑树定义4，其子节点为红色，且不可能是子树)；
                3，待删除节点两个子节点/子树均非空，交换待删除节点与其后继节点，构造情况1或情况2；
                
                // 情况2，可以交换删除节点与子节点，再删除子节点即可
                // 情况1较复杂，涉及删除后的再平衡
                ```
                - 2，删除叶子节点   
                <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/red-black-tree_delete-tree-pic.png" width="500px">   

                ```
                1、P为红色, 令P为黑色，继续
                2、P为黑色
                   2.1、if 目标节点P 是 父节点F 的左孩子
                      case1, P的兄弟节点B为红色 => 交换父节点F 和 B的颜色, 并围绕F左旋
                      case2, B为黑色，且B无子节点 => 使F为红色，并围绕F左旋 <if F本来就是红色，结束，else 黑色深度-1 需要re-balance>
                      case3, B为黑色，B只有左子节点BL => 令BL颜色=F; P为红色，F为黑色， 删除节点P & 围绕B右旋得到RR & 围绕F左旋
                      case4, B为黑色，B只有右子节点BR => 交换F和B的颜色; P为红色，BR为黑色(RR) & 围绕P左旋
                      case5, B为黑色，且有2个子节点 => 交换B和F, 令BR为黑色， 删除P，围绕F左旋(操作与case4一致)
                   2.2、else P 是 父节点F 的右孩子
                      情况同上，旋转方向相反即可
                ```

                - 当P为F左子节点是，case1到case5 示例图：       

                <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/red-black-tree_delete-left.png" width="200px">   

                - 3，重新平衡 <平衡 左右子树黑色高度一致>
                   - 仅当删除叶子节点的case2时才会破坏平衡，以case2中的父节点B为关注节点开始逐步向上re-balance
                   - if P 是 父节点F 的左子节点
                        - case1, 关注节点P的兄弟节点B为红 => 交换B F颜色，绕F左旋
                        - case2, 兄弟节点B为黑色，且其左右子节点均为黑 => 令B为红，F为黑，若F原本就是黑色，则以F为目标节点继续
                        - case3, B为黑色，且其左子节点BL为红，右子节点BR为黑  => (BL)交换BL 和 B的颜色，绕B右旋，得到(RR)case4
                        - case4, B为黑色，BR为红色，BL任意 => (RR)交换B和F的颜色，令BR为黑，绕F左旋,结束
                   - else (P是F的右节点)
                        - case1 ~ 4, 旋转方向相反

                   <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/red-black-tree-re-balance-pic.jpg" width="350px">   

- ### 堆（Heap） / 优先级队列（Priority Queue） / 二叉堆（Binary Heap）
    - 可视化是一棵树，但通常是以线性的形式存储（数组、链表）
    - 小根堆：根节点值小于等于左右子节点值 (所有节点满足)
    - 大根堆：根节点值大于等于左右子节点值
    ```
    // C++中，优先队列是通过堆实现的，默认使用大根堆
    // https://cplusplus.com/reference/queue/priority_queue/?kw=priority_queue
    
    priority_queue<int> tmp1;
    // 等价于:
    // priority_queue<int, vector<int>, less<int> > tmp1;
    
    // 使用小根堆 <队列首元素最小>
    priority_queue<int, vector<int>, greater<int> > tmp1;
    ```
    - [x] [堆](https://en.wikipedia.org/wiki/Heap_(data_structure))
    - [x] [介绍（视频）](https://www.coursera.org/learn/data-structures/lecture/2OpTs/introduction)
    - [x] 基本操作
        | op       | Description              | 时间复杂度 |
        | -------- | ------------------------ | ---------- |
        | build    | 新建                     | O(n)       |
        | insert   | 插入                     | O(log n)   |
        | get      | 获取堆顶值               | O(1)       |
        | delate   | 删除堆顶值               | O(log n)   |
        | heapify  | 是删除堆顶值的堆恢复成堆 | O(log n)   |
    - [ ] [堆排序 —— 跳到起点（视频）](https://youtu.be/odNJmw5TOEE?list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&t=3291)
    - [ ] [堆排序](https://zh.m.wikipedia.org/zh-hans/%E5%A0%86%E6%8E%92%E5%BA%8F)
    - [ ] [构建一个堆（视频）](https://www.coursera.org/learn/data-structures/lecture/dwrOS/building-a-heap)
    - [ ] [MIT：堆与堆排序（视频）](https://www.youtube.com/watch?v=B7hVxCmfPtM&index=4&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [ ] [CS 61B Lecture 24：优先级队列（视频）](https://www.youtube.com/watch?v=yIUFT6AKBGE&index=24&list=PL4BBB74C7D2A1049C)
    - [ ] [构建线性时间复杂度的堆（大顶堆）](https://www.youtube.com/watch?v=MiyLo8adrWw)
    - [ ] 实现一个大顶堆：
        - [ ] insert
        - [ ] sift_up —— 用于插入元素
        - [ ] get_max —— 返回最大值但不移除元素
        - [ ] get_size() —— 返回存储的元素数量
        - [ ] is_empty() —— 若堆为空则返回 true
        - [ ] extract_max —— 返回最大值并移除
        - [ ] sift_down —— 用于获取最大值元素
        - [ ] remove(i) —— 删除指定索引的元素
        - [ ] heapify —— 构建堆，用于堆排序
        - [ ] heap_sort() —— 拿到一个未排序的数组，然后使用大顶堆或者小顶堆进行就地排序

## 排序（Sorting）

- [ ] 笔记:
    - 实现各种排序，知道每种排序的最坏、最好和平均的复杂度分别是什么场景:
        - 不要用冒泡排序 - 效率太差 - 时间复杂度 O(n^2), 除非 n <= 16
    - [ ] 排序算法的稳定性 ("快排是稳定的么?")
        - [排序算法的稳定性](https://en.wikipedia.org/wiki/Sorting_algorithm#Stability)
        - [排序算法的稳定性](http://stackoverflow.com/questions/1517793/stability-in-sorting-algorithms)
        - [排序算法的稳定性](http://www.geeksforgeeks.org/stability-in-sorting-algorithms/)
        - [排序算法 - 稳定性](http://homepages.math.uic.edu/~leon/cs-mcs401-s08/handouts/stability.pdf)
    - [ ] 哪种排序算法可以用链表？哪种用数组？哪种两者都可？
        - 并不推荐对一个链表排序，但归并排序是可行的.
        - [链表的归并排序](http://www.geeksforgeeks.org/merge-sort-for-linked-list/)

- 关于堆排序，请查看前文堆的数据结构部分。堆排序很强大，不过是非稳定排序。
- [ ] [Sedgewick ── 归并排序（5个视频）](https://www.coursera.org/learn/algorithms-part1/home/week/3)
    - [ ] 1. 归并排序
    - [ ] 2. 自下而上的归并排序
    - [ ] 3. 排序复杂度
    - [ ] 4. 比较器
    - [ ] 5. 稳定性
- [ ] [Sedgewick ── 快速排序（4个视频）](https://www.coursera.org/learn/algorithms-part1/home/week/3)
    - [ ] 1. 快速排序
    - [ ] 2. 选择
    - [ ] 3. 重复键值
    - [ ] 4. 系统排序
- [ ] [冒泡排序（视频）](https://www.youtube.com/watch?v=P00xJgWzz2c&index=1&list=PL89B61F78B552C1AB)
- [ ] [冒泡排序分析（视频）](https://www.youtube.com/watch?v=ni_zk257Nqo&index=7&list=PL89B61F78B552C1AB)
- [ ] [插入排序 & 归并排序（视频）](https://www.youtube.com/watch?v=Kg4bqzAqRBM&index=3&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
- [ ] [插入排序（视频）](https://www.youtube.com/watch?v=c4BRHC7kTaQ&index=2&list=PL89B61F78B552C1AB)
- [ ] [归并排序（视频）](https://www.youtube.com/watch?v=GCae1WNvnZM&index=3&list=PL89B61F78B552C1AB)
- [ ] [快排（视频）](https://www.youtube.com/watch?v=y_G9BkAm6B8&index=4&list=PL89B61F78B552C1AB)
- [ ] [选择排序（视频）](https://www.youtube.com/watch?v=6nDMgr0-Yyo&index=8&list=PL89B61F78B552C1AB)

- [ ] 归并排序代码：
    - [ ] [使用外部数组（C语言）](http://www.cs.yale.edu/homes/aspnes/classes/223/examples/sorting/mergesort.c)
    - [ ] [使用外部数组（Python语言）](https://github.com/jwasham/practice-python/blob/master/merge_sort/merge_sort.py)
    - [ ] [对原数组直接排序（C++）](https://github.com/jwasham/practice-cpp/blob/master/merge_sort/merge_sort.cc)
- [ ] 快速排序代码：
    - [ ] [实现（C语言）](http://www.cs.yale.edu/homes/aspnes/classes/223/examples/randomization/quick.c)
    - [ ] [实现（C语言）](https://github.com/jwasham/practice-c/blob/master/quick_sort/quick_sort.c)
    - [ ] [实现（Python语言）](https://github.com/jwasham/practice-python/blob/master/quick_sort/quick_sort.py)

- [ ] 实现:
    - [ ] 归并：平均和最差情况的时间复杂度为 O(n log n)。
    - [ ] 快排：平均时间复杂度为 O(n log n)。
    - 选择排序和插入排序的最坏、平均时间复杂度都是 O(n^2)。
    - 关于堆排序，请查看前文堆的数据结构部分。

- [ ] 有兴趣的话，还有一些补充，但并不是必须的:
    - [Sedgewick──基数排序 (6个视频)](https://www.coursera.org/learn/algorithms-part2/home/week/3)
        - [ ] [1. Java 中的字符串](https://www.coursera.org/learn/algorithms-part2/lecture/vGHvb/strings-in-java)
        - [ ] [2. 键值索引计数（Key Indexed Counting）](https://www.coursera.org/learn/algorithms-part2/lecture/2pi1Z/key-indexed-counting)
        - [ ] [3. Least Significant Digit First String Radix Sort](https://www.coursera.org/learn/algorithms-part2/lecture/c1U7L/lsd-radix-sort)
        - [ ] [4. Most Significant Digit First String Radix Sort](https://www.coursera.org/learn/algorithms-part2/lecture/gFxwG/msd-radix-sort)
        - [ ] [5. 3中基数快速排序](https://www.coursera.org/learn/algorithms-part2/lecture/crkd5/3-way-radix-quicksort)
        - [ ] [6. 后继数组（Suffix Arrays）](https://www.coursera.org/learn/algorithms-part2/lecture/TH18W/suffix-arrays)
    - [ ] [基数排序](http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#radixSort)
    - [ ] [基数排序（视频）](https://www.youtube.com/watch?v=xhr26ia4k38)
    - [ ] [基数排序, 计数排序 (线性时间内)（视频）](https://www.youtube.com/watch?v=Nz1KZXbghj8&index=7&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [ ] [随机算法: 矩阵相乘, 快排, Freivalds' 算法（视频）](https://www.youtube.com/watch?v=cNB2lADK3_s&index=8&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp)
    - [ ] [线性时间内的排序（视频）](https://www.youtube.com/watch?v=pOKy3RZbSws&list=PLUl4u3cNGP61hsJNdULdudlRL493b-XZf&index=14)

总结一下，这是[15种排序算法](https://www.youtube.com/watch?v=kPRA0W1kECg)的可视化表示。如果你需要有关此主题的更多详细信息，请参阅“[一些主题的额外内容](#一些主题的额外内容)”中的“排序”部分。

## 图（Graphs）

图论能解决计算机科学里的很多问题，所以这一节会比较长，像树和排序的部分一样。

- 笔记:
    - 有4种基本方式在内存里表示一个图:
        - 对象和指针
        - 邻接矩阵
        - 邻接表
        - 邻接图
    - 熟悉以上每一种图的表示法，并了解各自的优缺点
    - 广度优先搜索和深度优先搜索：知道它们的计算复杂度和设计上的权衡以及如何用代码实现它们
    - 遇到一个问题时，首先尝试基于图的解决方案，如果没有再去尝试其他的。

- MIT（视频）：
    - [广度优先搜索](https://www.youtube.com/watch?v=s-CYnVz-uh4&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=13)
    - [深度优先搜索](https://www.youtube.com/watch?v=AfSk24UTFS8&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=14)

- [ ] Skiena 教授的课程 - 很不错的介绍:
    - [ ] [CSE373 2012 - 课程 11 - 图的数据结构（视频）](https://www.youtube.com/watch?v=OiXxhDrFruw&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&index=11)
    - [ ] [CSE373 2012 - 课程 12 - 广度优先搜索（视频）](https://www.youtube.com/watch?v=g5vF8jscteo&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&index=12)
    - [ ] [CSE373 2012 - 课程 13 - 图的算法（视频）](https://www.youtube.com/watch?v=S23W6eTcqdY&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&index=13)
    - [ ] [CSE373 2012 - 课程 14 - 图的算法 (1)（视频）](https://www.youtube.com/watch?v=WitPBKGV0HY&index=14&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b)
    - [ ] [CSE373 2012 - 课程 15 - 图的算法 (2)（视频）](https://www.youtube.com/watch?v=ia1L30l7OIg&index=15&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b)
    - [ ] [CSE373 2012 - 课程 16 - 图的算法 (3)（视频）](https://www.youtube.com/watch?v=jgDOQq6iWy8&index=16&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b)

- [ ] 图 (复习和其他):

    - [ ] [6.006 单源最短路径问题（视频）](https://www.youtube.com/watch?v=Aa2sqUhIn-E&index=15&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [ ] [6.006 Dijkstra 算法（视频）](https://www.youtube.com/watch?v=2E7MmKv0Y24&index=16&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [ ] [6.006 Bellman-Ford 算法（视频）](https://www.youtube.com/watch?v=ozsuci5pIso&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=17)
    - [ ] [6.006 Dijkstra 效率优化（视频）](https://www.youtube.com/watch?v=CHvQ3q_gJ7E&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=18)
    - [ ] [Aduni: 图的算法 I - 拓扑排序，最小生成树，Prim 算法 - 第六课（视频）](https://www.youtube.com/watch?v=i_AQT_XfvD8&index=6&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm)
    - [ ] [Aduni: 图的算法 II - 深度优先搜索, 广度优先搜索, Kruskal 算法, 并查集数据结构 - 第七课（视频）](https://www.youtube.com/watch?v=ufj5_bppBsA&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=7)
    - [ ] [Aduni: 图的算法 III: 最短路径 - 第八课（视频）](https://www.youtube.com/watch?v=DiedsPsMKXc&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=8)
    - [ ] [Aduni: 图的算法. IV: 几何算法介绍 - 第九课（视频）](https://www.youtube.com/watch?v=XIAQRlNkJAw&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=9)
    - [ ] <del>[CS 61B 2014 (从 58:09 开始)（视频）](https://youtu.be/dgjX4HdMI-Q?list=PL-XXv-cvA_iAlnI-BQr9hjqADPBtujFJd&t=3489)</del>
    - [ ] [CS 61B 2014: 加权图（视频）](https://www.youtube.com/watch?v=aJjlQCFwylA&list=PL-XXv-cvA_iAlnI-BQr9hjqADPBtujFJd&index=19)
    - [ ] [贪心算法: 最小生成树（视频）](https://www.youtube.com/watch?v=tKwnms5iRBU&index=16&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp)
    - [ ] [图的算法之强连通分量 Kosaraju 算法（视频）](https://www.youtube.com/watch?v=RpgcYiky7uw)

- 完整的 Coursera 课程:
    - [ ] [图的算法（视频）](https://www.coursera.org/learn/algorithms-on-graphs/home/welcome)

- 我会实现:
    - [ ] DFS 邻接表 (递归)
    - [ ] DFS 邻接表 (栈迭代)
    - [ ] DFS 邻接矩阵 (递归)
    - [ ] DFS 邻接矩阵 (栈迭代)
    - [ ] BFS 邻接表
    - [ ] BFS 邻接矩阵
    - [ ] 单源最短路径问题 (Dijkstra)
    - [ ] 最小生成树
    - 基于 DFS 的算法 (根据上文 Aduni 的视频):
        - [ ] 检查环 (我们会先检查是否有环存在以便做拓扑排序)
        - [ ] 拓扑排序
        - [ ] 计算图中的连通分支
        - [ ] 列出强连通分量
        - [ ] 检查双向图

可以从 Skiena 的书（参考下面的书推荐小节）和面试书籍中学习更多关于图的实践。

## 更多知识

- ### 递归（Recursion）
    - [ ] Stanford 大学关于递归 & 回溯的课程:
        - [ ] [课程 8 | 抽象编程（视频）](https://www.youtube.com/watch?v=gl3emqCuueQ&list=PLFE6E58F856038C69&index=8)
        - [ ] [课程 9 | 抽象编程（视频）](https://www.youtube.com/watch?v=uFJhEPrbycQ&list=PLFE6E58F856038C69&index=9)
        - [ ] [课程 10 | 抽象编程（视频）](https://www.youtube.com/watch?v=NdF1QDTRkck&index=10&list=PLFE6E58F856038C69)
        - [ ] [课程 11 | 抽象编程（视频）](https://www.youtube.com/watch?v=p-gpaIGRCQI&list=PLFE6E58F856038C69&index=11)
    - 什么时候适合使用
    - 尾递归会更好么?
        - [ ] [什么是尾递归以及为什么它如此糟糕?](https://www.quora.com/What-is-tail-recursion-Why-is-it-so-bad)
        - [ ] [尾递归（视频）](https://www.coursera.org/lecture/programming-languages/tail-recursion-YZic1)
    - [x] 回溯算法
        - 按选优条件向前搜索，以达到目标。但当探索到某一步时，发现原先选择并不优或达不到目标，就退回一步重新选择
        - 剪枝 => 避免无效搜索
        - 递归回溯 和 迭代回溯(非递归)；递归用的更多
        - excample: [字符串的排列](https://github.com/kexinchu/LeetCode/blob/master/the_sword_refers_to_the_offer/reback-37.cpp)

- ### 动态规划（Dynamic Programming）
    - 在你的面试中或许没有任何动态规划的问题，但能够知道一个题目可以使用动态规划来解决是很重要的。
    - 这一部分会有点困难，每个可以用动态规划解决的问题都必须先定义出递推关系，要推导出来可能会有点棘手。
    - 我建议先阅读和学习足够多的动态规划的例子，以便对解决 DP 问题的一般模式有个扎实的理解。
    - [ ] 视频:
        - Skiena 的视频可能会有点难跟上，有时候他用白板写的字会比较小，难看清楚。
        - [ ] [Skiena: CSE373 2012 - 课程 19 - 动态规划介绍（视频）](https://youtu.be/Qc2ieXRgR0k?list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&t=1718)
        - [ ] [Skiena: CSE373 2012 - 课程 20 - 编辑距离（视频）](https://youtu.be/IsmMhMdyeGY?list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&t=2749)
        - [ ] [Skiena: CSE373 2012 - 课程 21 - 动态规划举例（视频）](https://youtu.be/o0V9eYF4UI8?list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&t=406)
        - [ ] [Skiena: CSE373 2012 - 课程 22 - 动态规划应用（视频）](https://www.youtube.com/watch?v=dRbMC1Ltl3A&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&index=22)
        - [ ] [Simonson: 动态规划 0 (starts at 59:18)（视频）](https://youtu.be/J5aJEcOr6Eo?list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&t=3558)
        - [ ] [Simonson: 动态规划 I - 课程 11（视频）](https://www.youtube.com/watch?v=0EzHjQ_SOeU&index=11&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm)
        - [ ] [Simonson: 动态规划 II - 课程 12（视频）](https://www.youtube.com/watch?v=v1qiRwuJU7g&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=12)
        - [ ] 单独的 DP 问题 (每一个视频都很短)：[动态规划（视频）](https://www.youtube.com/playlist?list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr)
    - [ ] 耶鲁课程笔记:
        - [ ] [动态规划](http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#dynamicProgramming)
    - [ ] Coursera 课程:
        - [ ] [RNA 二级结构问题（视频）](https://www.coursera.org/learn/algorithmic-thinking-2/lecture/80RrW/the-rna-secondary-structure-problem)
        - [ ] [动态规划算法（视频）](https://www.coursera.org/learn/algorithmic-thinking-2/lecture/PSonq/a-dynamic-programming-algorithm)
        - [ ] [DP 算法描述（视频）](https://www.coursera.org/learn/algorithmic-thinking-2/lecture/oUEK2/illustrating-the-dp-algorithm)
        - [ ] [DP 算法的运行时间（视频）](https://www.coursera.org/learn/algorithmic-thinking-2/lecture/nfK2r/running-time-of-the-dp-algorithm)
        - [ ] [DP vs 递归实现（视频）](https://www.coursera.org/learn/algorithmic-thinking-2/lecture/M999a/dp-vs-recursive-implementation)
        - [ ] [全局成对序列排列（视频）](https://www.coursera.org/learn/algorithmic-thinking-2/lecture/UZ7o6/global-pairwise-sequence-alignment)
        - [ ] [本地成对序列排列（视频）](https://www.coursera.org/learn/algorithmic-thinking-2/lecture/WnNau/local-pairwise-sequence-alignment)

- ### 面向对象编程
    - 可选：[UML 2.0系列（视频）](https://www.youtube.com/watch?v=OkC7HKtiZC0&list=PLGLfVvz_LVvQ5G-LdJ8RLqe-ndo7QITYc)
    - SOLID 面向对象编程原则：[SOLID 原则（视频）](https://www.youtube.com/playlist?list=PL4CE9F710017EA77A)

- ### 设计模式
    - [ ] [UML 统一建模语言概览 (视频)](https://www.youtube.com/watch?v=3cmzqZzwNDM&list=PLGLfVvz_LVvQ5G-LdJ8RLqe-ndo7QITYc&index=3)
    - [ ] 主要有如下的设计模式:
        - [ ] 策略模式（strategy）
        - [ ] 单例模式（singleton）
        - [ ] 适配器模式（adapter）
        - [ ] 原型模式（prototype）
        - [ ] 装饰器模式（decorator）
        - [ ] 访问者模式（visitor）
        - [ ] 工厂模式，抽象工厂模式（factory, abstract factory）
        - [ ] 外观模式（facade）
        - [ ] 观察者模式（observer）
        - [ ] 代理模式（proxy）
        - [ ] 委托模式（delegate）
        - [ ] 命令模式（command）
        - [ ] 状态模式（state）
        - [ ] 备忘录模式（memento）
        - [ ] 迭代器模式（iterator）
        - [ ] 组合模式（composite）
        - [ ] 享元模式（flyweight）
    - [ ] [第六章 (第 1 部分 ) - 设计模式 (视频)](https://youtu.be/LAP2A80Ajrg?list=PLJ9pm_Rc9HesnkwKlal_buSIHA-jTZMpO&t=3344)
    - [ ] [第六章 (第 2 部分 ) - Abstraction-Occurrence, General Hierarchy, Player-Role, Singleton, Observer, Delegation (视频)](https://www.youtube.com/watch?v=U8-PGsjvZc4&index=12&list=PLJ9pm_Rc9HesnkwKlal_buSIHA-jTZMpO)
    - [ ] [第六章 (第 3 部分 ) - Adapter, Facade, Immutable, Read-Only Interface, Proxy（视频）](https://www.youtube.com/watch?v=7sduBHuex4c&index=13&list=PLJ9pm_Rc9HesnkwKlal_buSIHA-jTZMpO)
    - [ ] [系列视频（27个）](https://www.youtube.com/playlist?list=PLF206E906175C7E07)
    - [ ] [Head First 设计模型](https://www.amazon.com/Head-First-Design-Patterns-Freeman/dp/0596007124)
        - 尽管《设计模式：可复用面向对象软件的基础》才是这方面的经典，但是我还是认为Head First对于新手更加友好。
    - [ ] [实际操作：设计模式和对入门开发者的建议](https://sourcemaking.com/design-patterns-and-tips)
    - [ ] [Design patterns for humans](https://github.com/kamranahmedse/design-patterns-for-humans#structural-design-patterns)

- ### 组合（Combinatorics） (n 中选 k 个) & 概率（Probability）
    - [ ] [数据技巧: 如何找出阶乘、排列和组合(选择)（视频）](https://www.youtube.com/watch?v=8RRo6Ti9d0U)
    - [ ] [来点学校的东西: 概率（视频）](https://www.youtube.com/watch?v=sZkAAk9Wwa4)
    - [ ] [来点学校的东西: 概率和马尔可夫链（视频）](https://www.youtube.com/watch?v=dNaJg-mLobQ)
    - [ ] 可汗学院:
        - 课程设置:
            - [ ] [概率理论基础](https://www.khanacademy.org/math/probability/probability-and-combinatorics-topic)
        - 只有视频 - 41 (每一个都短小精悍):
            - [ ] [概率解释（视频）](https://www.youtube.com/watch?v=uzkc-qNVoOk&list=PLC58778F28211FA19)

- ### NP, NP-完全和近似算法
    - 知道最经典的一些 NP 完全问题，比如**旅行商问题**和**背包问题**，而且能在面试官试图忽悠你的时候识别出他们。
    - 知道 NP 完全是什么意思.
    - [ ] [计算复杂度（视频）](https://www.youtube.com/watch?v=moPtwq_cVH8&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=23)
    - [ ] Simonson:
        - [ ] [贪心算法. II & 介绍 NP-完全性（视频）](https://youtu.be/qcGnJ47Smlo?list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&t=2939)
        - [ ] [NP-完全性 II & 归约（视频）](https://www.youtube.com/watch?v=e0tGC6ZQdQE&index=16&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm)
        - [ ] [NP-完全性 III（视频）](https://www.youtube.com/watch?v=fCX1BGT3wjE&index=17&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm)
        - [ ] [NP-完全性 IV（视频）](https://www.youtube.com/watch?v=NKLDp3Rch3M&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=18)
    - [ ] Skiena:
        - [ ] [CSE373 2012 - 课程 23 - 介绍 NP-完全性 IV（视频）](https://youtu.be/KiK5TVgXbFg?list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&t=1508)
        - [ ] [CSE373 2012 - 课程 24 - NP-完全性证明（视频）](https://www.youtube.com/watch?v=27Al52X3hd4&index=24&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b)
        - [ ] [CSE373 2012 - 课程 25 - NP-完全性挑战（视频）](https://www.youtube.com/watch?v=xCPH4gwIIXM&index=25&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b)
    - [ ] [复杂度: P, NP, NP-完全性, 规约（视频）](https://www.youtube.com/watch?v=eHZifpgyH_4&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=22)
    - [ ] [复杂度: 近视算法 Algorithms（视频）](https://www.youtube.com/watch?v=MEz1J9wY2iM&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=24)
    - [ ] [复杂度: 固定参数算法（视频）](https://www.youtube.com/watch?v=4q-jmGrmxKs&index=25&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp)
    - Peter Norvik 讨论旅行商问题的近似最优解:
        - [Jupyter 笔记本](http://nbviewer.jupyter.org/url/norvig.com/ipython/TSP.ipynb)
    - 《算法导论》（CLRS）的第 1048 - 1140 页。
    - [ ] 背包问题(动态规划)
        - [x] 背包问题分类
        <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/knapsack-problem.png" width="300px">    
        - [ ] 0/1背包
            - eg: 有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。
            - 方法：二维dp数组:  递归 dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            - 
        - [ ] 完全背包
        - [ ] 多重背包


- ### 缓存（Cache）
    - [ ] LRU 缓存:
        - [ ] [LRU 的魔力 (100 Days of Google Dev)（视频）](https://www.youtube.com/watch?v=R5ON3iwx78M)
        - [ ] [实现 LRU（视频）](https://www.youtube.com/watch?v=bq6N7Ym81iI)
        - [ ] [LeetCode - 146 LRU Cache (C++)（视频）](https://www.youtube.com/watch?v=8-FZRAjR7qU)
    - [ ] CPU 缓存:
        - [ ] [MIT 6.004 L15: 存储体系（视频）](https://www.youtube.com/watch?v=vjYF_fAZI5E&list=PLrRW1w6CGAcXbMtDFj205vALOGmiRc82-&index=24)
        - [ ] [MIT 6.004 L16: 缓存的问题（视频）](https://www.youtube.com/watch?v=ajgC3-pyGlk&index=25&list=PLrRW1w6CGAcXbMtDFj205vALOGmiRc82-)

- ### 进程（Processe）和线程（Thread）
    - [ ] 计算机科学 162 - 操作系统 (25 个视频):
        - 视频 1-11 是关于进程和线程
        - [操作系统和系统编程（视频）](https://archive.org/details/ucberkeley-webcast-PL-XXv-cvA_iBDyz-ba4yDskqMDY6A1w_c)
    - [进程和线程的区别是什么?](https://www.quora.com/What-is-the-difference-between-a-process-and-a-thread)
    - 涵盖了:
        - 进程、线程、协程
            - 进程和线程的区别
            - 进程
            - 线程
            - 锁
            - 互斥
            - 信号量
            - 监控
            - 他们是如何工作的
            - 死锁
            - 活锁
        - CPU 活动, 中断, 上下文切换
        - 现代多核处理器的并发式结构
        - [分页（paging），分段（segmentation）和虚拟内存（视频）](https://www.youtube.com/watch?v=LKe7xK0bF7o&list=PLCiOXwirraUCBE9i_ukL8_Kfg6XNv7Se8&index=2)
        - [中断（视频）](https://www.youtube.com/watch?v=uFKi2-J-6II&list=PLCiOXwirraUCBE9i_ukL8_Kfg6XNv7Se8&index=3)
        - 进程资源需要（内存：代码、静态存储器、栈、堆、文件描述符、I/O）
        - 线程资源需要（在同一个进程内和其他线程共享以上（除了栈）的资源，但是每个线程都有独立的程序计数器、栈计数器、寄存器和栈）
        - Fork 操作是真正的写时复制（只读），直到新的进程写到内存中，才会生成一份新的拷贝。
        - 上下文切换
            - 操作系统和底层硬件是如何初始化上下文切换的？
    - [ ] [C++ 的线程 (系列 - 10 个视频)](https://www.youtube.com/playlist?list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M)
    - [ ] Python 的并发 (视频):
        - [ ] [线程系列](https://www.youtube.com/playlist?list=PL1H1sBF1VAKVMONJWJkmUh6_p8g4F2oy1)
        - [ ] [Python 线程](https://www.youtube.com/watch?v=Bs7vPNbB9JM)
        - [ ] [理解 Python 的 GIL (2010)](https://www.youtube.com/watch?v=Obt-vMVdM8s)
            - [参考](http://www.dabeaz.com/GIL)
        - [ ] [David Beazley - Python 协程 - PyCon 2015](https://www.youtube.com/watch?v=MCs5OvhV9S4)
        - [ ] [Keynote David Beazley - 兴趣主题 (Python 异步 I/O)](https://www.youtube.com/watch?v=ZzfHjytDceU)
        - [ ] [Python 中的互斥](https://www.youtube.com/watch?v=0zaPs8OtyKY)

- ### 测试
    - 涵盖了:
        - 单元测试是如何工作的
        - 什么是模拟对象
        - 什么是集成测试
        - 什么是依赖注入
    - [ ] [James Bach 讲敏捷软件测试（视频）](https://www.youtube.com/watch?v=SAhJf36_u5U)
    - [ ] [James Bach 软件测试公开课（视频）](https://www.youtube.com/watch?v=ILkT_HV9DVU)
    - [ ] [Steve Freeman - 测试驱动的开发（视频）](https://vimeo.com/83960706)
        - [slides](http://gotocon.com/dl/goto-berlin-2013/slides/SteveFreeman_TestDrivenDevelopmentThatsNotWhatWeMeant.pdf)
    - [ ] [Python：测试驱动的 Web 开发](http://www.obeythetestinggoat.com/pages/book.html#toc)
    - [ ] 依赖注入:
        - [ ] [视频](https://www.youtube.com/watch?v=IKD2-MAkXyQ)
        - [ ] [测试之道](http://jasonpolites.github.io/tao-of-testing/ch3-1.1.html)
    - [ ] [如何编写测试](http://jasonpolites.github.io/tao-of-testing/ch4-1.1.html)

- ### 调度
    - 在操作系统中是如何运作的
    - 在操作系统部分的视频里有很多资料

- ### 字符串搜索和操作
    - [ ] [Sedgewick──后缀数组（Suffix Arrays）（视频）](https://www.coursera.org/learn/algorithms-part2/lecture/TH18W/suffix-arrays)
    - [ ] [Sedgewick──子字符串搜寻（视频）](https://www.coursera.org/learn/algorithms-part2/home/week/4)
        - [ ] [1. 子字符串搜寻导论](https://www.coursera.org/learn/algorithms-part2/lecture/n3ZpG/introduction-to-substring-search)
        - [ ] [2. 子字符串搜寻──暴力法](https://www.coursera.org/learn/algorithms-part2/lecture/2Kn5i/brute-force-substring-search)
        - [ ] [3. KMP算法](https://www.coursera.org/learn/algorithms-part2/lecture/TAtDr/knuth-morris-pratt)
        - [ ] [4. Boyer-Moore算法](https://www.coursera.org/learn/algorithms-part2/lecture/CYxOT/boyer-moore)
        - [ ] [5. Rabin-Karp算法](https://www.coursera.org/learn/algorithms-part2/lecture/3KiqT/rabin-karp)
    - [ ] [文本的搜索模式（视频）](https://www.coursera.org/learn/data-structures/lecture/tAfHI/search-pattern-in-text)

如果你需要有关此主题的更多详细信息，请参阅“[一些主题的额外内容](#一些主题的额外内容)”中的“字符串匹配”部分。

- ### 字典树（Tries）
    - 需要注意的是，字典树各式各样。有些有前缀，而有些则没有。有些使用字符串而不使用比特位来追踪路径。
    - 阅读代码，但不实现。
    - [Sedgewick──字典树（3个视频）](https://www.coursera.org/learn/algorithms-part2/home/week/4)
        - [ ] [1. R Way字典树](https://www.coursera.org/learn/algorithms-part2/lecture/CPVdr/r-way-tries)
        - [ ] [2. 三元搜索树](https://www.coursera.org/learn/algorithms-part2/lecture/yQM8K/ternary-search-tries)
        - [ ] [3. 基于字符串的操作](https://www.coursera.org/learn/algorithms-part2/lecture/jwNmV/character-based-operations)
    - [ ] [数据结构笔记及编程技术](http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#Tries)
    - [ ] 短课程视频：
        - [ ] [对字典树的介绍（视频）](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/08Xyf/core-introduction-to-tries)
        - [ ] [字典树的性能（视频）](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/PvlZW/core-performance-of-tries)
        - [ ] [实现一棵字典树（视频）](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/DFvd3/core-implementing-a-trie)
    - [ ] [字典树：一个被忽略的数据结构](https://www.toptal.com/java/the-trie-a-neglected-data-structure)
    - [ ] [TopCoder —— 使用字典树](https://www.topcoder.com/community/data-science/data-science-tutorials/using-tries/)
    - [ ] [标准教程（现实中的用例）（视频）](https://www.youtube.com/watch?v=TJ8SkcUSdbU)
    - [ ] [MIT，高阶数据结构，字符串（视频中间有点困难）（视频）](https://www.youtube.com/watch?v=NinWEPPrkDQ&index=16&list=PLUl4u3cNGP61hsJNdULdudlRL493b-XZf)

- ### 平衡搜索树
    - **AVL树，伸展树，红黑树**: 详见二叉树章节
    - [ ] **2-3查找树**
        - 实际中：2-3树的元素插入非常快速，但却有着查询慢的代价（因为相比较 AVL 树来说，其高度更高）。
        - 你会很少用到2-3树。这是因为，其实现过程中涉及到不同类型的节点。因此，人们更多地会选择红黑树。
        - [2-3树的直感与定义（视频）](https://www.youtube.com/watch?v=C3SsdUqasD4&list=PLA5Lqm4uh9Bbq-E0ZnqTIa8LRaL77ica6&index=2)
        - [2-3树的二元观点](https://www.youtube.com/watch?v=iYvBtGKsqSg&index=3&list=PLA5Lqm4uh9Bbq-E0ZnqTIa8LRaL77ica6)
        - [2-3树（学生叙述）（视频）](https://www.youtube.com/watch?v=TOb1tuEZ2X4&index=5&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp)
        
    - [ ] **2-3-4树 (亦称2-4树)**
        - 实际中：对于每一棵2-4树，都有着对应的红黑树来存储同样顺序的数据元素。在2-4树上进行插入及删除操作等同于在红黑树上进行颜色翻转及轮换。这使得2-4树成为一种用于掌握红黑树背后逻辑的重要工具。这就是为什么许多算法引导文章都会在介绍红黑树之前，先介绍2-4树，尽管**2-4树在实际中并不经常使用**。
        - [CS 61B Lecture 26：平衡查找树（视频）](https://www.youtube.com/watch?v=zqrqYXkth6Q&index=26&list=PL4BBB74C7D2A1049C)
        - [自底向上的2-4树（视频）](https://www.youtube.com/watch?v=DQdMYevEyE4&index=4&list=PLA5Lqm4uh9Bbq-E0ZnqTIa8LRaL77ica6)
        - [自顶向下的2-4树（视频）](https://www.youtube.com/watch?v=2679VQ26Fp4&list=PLA5Lqm4uh9Bbq-E0ZnqTIa8LRaL77ica6&index=5)
        
    - [ ] **N 叉树（K 叉树、M 叉树）**
        - 注意：N 或 K 指的是分支系数（即树的最大分支数）：
        - 二叉树是一种分支系数为2的树
        - 2-3树是一种分支系数为3的树
        - [K 叉树](https://en.wikipedia.org/wiki/K-ary_tree)
        
    - [ ] **B 树**
        - 有趣的是：为啥叫 B 仍然是一个神秘。因为 B 可代表波音（Boeing）、平衡（Balanced）或 Bayer（联合创造者）
        - 实际中：B 树会被广泛适用于数据库中，而现代大多数的文件系统都会使用到这种树（或变种)。除了运用在数据库中，B 树也会被用于文件系统以快速访问一个文件的任意块。但存在着一个基本的问题，那就是如何将文件块 i 转换成一个硬盘块（或一个柱面-磁头-扇区）上的地址。
        - [B 树](https://en.wikipedia.org/wiki/B-tree)
        - [B 树数据结构](http://btechsmartclass.com/data_structures/b-trees.html)
        - [B 树的介绍（视频）](https://www.youtube.com/watch?v=I22wEC1tTGo&list=PLA5Lqm4uh9Bbq-E0ZnqTIa8LRaL77ica6&index=6)
        - [B 树的定义及其插入操作（视频）](https://www.youtube.com/watch?v=s3bCdZGrgpA&index=7&list=PLA5Lqm4uh9Bbq-E0ZnqTIa8LRaL77ica6)
        - [B 树的删除操作（视频）](https://www.youtube.com/watch?v=svfnVhJOfMc&index=8&list=PLA5Lqm4uh9Bbq-E0ZnqTIa8LRaL77ica6)
        - [MIT 6.851 —— 内存层次模块（Memory Hierarchy Models）（视频）](https://www.youtube.com/watch?v=V3omVLzI0WE&index=7&list=PLUl4u3cNGP61hsJNdULdudlRL493b-XZf)
            - 覆盖有高速缓存参数无关型（cache-oblivious）B 树和非常有趣的数据结构
            - 头37分钟讲述的很专业，或许可以跳过（B 指块的大小、即缓存行的大小）

- ### 浮点数
    - 双精度浮点数 & 单精度浮点数
    - 二进制表示 => 0.1这种的小数是近似存储的
    - [x] Express计数方法：
    <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/float-express.png" width="300px">

    - [ ] 简单8位：[浮点数的表示形式-1（视频──计算中存在错误，请参见视频说明）](https://www.youtube.com/watch?v=ji3SfClm8TU)
    - [ ] 32位：[IEEE754 32位浮点二进制（视频）](https://www.youtube.com/watch?v=50ZYcZebIec)

- ### Unicode
    - [ ] [每一个软件开发者的绝对最低限度，必须要知道的关于 Unicode 和字符集知识](http://www.joelonsoftware.com/articles/Unicode.html)
    - [ ] [关于处理文本需要的编码和字符集，每个程序员绝对需要知道的知识](http://kunststube.net/encoding/)

- ### 字节序（Endianness）
    - [大/小端序](https://web.archive.org/web/20180107141940/http://www.cs.umd.edu:80/class/sum2003/cmsc311/Notes/Data/endian.html)
    - [大端序 Vs 小端序（视频）](https://www.youtube.com/watch?v=JrNF0KRAlyo)
    - [由里入内的大端序与小端序（视频）](https://www.youtube.com/watch?v=oBSuXP-1Tc0)
        - 对于内核开发非常具有技术性，如果大多数的内容听不懂也没关系。
        - 前半部就已经足够了。

- ### 网络（视频）
    - **如果你具有网络经验或想成为可靠性工程师或运维工程师，期待你的问题**
    - 知道这些有益无害，多多益善!
    - [ ] [可汗学院](https://www.khanacademy.org/computing/computer-science/computers-and-internet-code-org)
    - [ ] [UDP 和 TCP：网络传输协议中的数据压缩（视频）](https://www.youtube.com/watch?v=Vdc8TCESIg8)
    - [ ] [TCP/IP 和 OSI 模型解释！（视频）](https://www.youtube.com/watch?v=e5DEVa9eSN0)
    - [ ] [互联网上的数据包传输。网络和 TCP/IP 教程。（视频）](https://www.youtube.com/watch?v=nomyRJehhnM)
    - [ ] [HTTP（视频）](https://www.youtube.com/watch?v=WGJrLqtX7As)
    - [ ] [SSL 和 HTTPS（视频）](https://www.youtube.com/watch?v=S2iBR2ZlZf0)
    - [ ] [SSL/TLS（视频）](https://www.youtube.com/watch?v=Rp3iZUvXWlM)
    - [ ] [HTTP 2.0（视频）](https://www.youtube.com/watch?v=E9FxNzv1Tr8)
    - [ ] [视频系列（21个视频）](https://www.youtube.com/playlist?list=PLEbnTDJUr_IegfoqO4iPnPYQui46QqT0j)
    - [ ] [子网络解密 - 第五部分 经典内部域名指向 CIDR 标记（视频）](https://www.youtube.com/watch?v=t5xYI0jzOf4)
    - [ ] 套接字（Sockets）：
        - [Java──套接字──介绍（视频）](https://www.youtube.com/watch?v=6G_W54zuadg&t=6s)
        - [套接字编程（视频）](https://www.youtube.com/watch?v=G75vN2mnJeQ)
