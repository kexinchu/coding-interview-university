### 并行和并发的区别
- 并发指的是多个任务在同一个时间段内同时发生，一般是指多个任务互相抢占资源
- 并行指的是多个任务在同一时间点同时发生，只有在多CPU情况下才会发生

### Linux中最多有多少个进程 和 线程
- 进程限制
    - 软限制： ulimit -u 可以查看/修改系统中的线程上限
    - pid_t类型限制，linux中pid_t实际上是一个short类型变量 (16 bit)， 32768个
    - 实际上还有资源限制

- 线程限制
    - 文件描述符限制： ulimit -n 可以查看
    - 内存限制 (线程的调用栈占用资源 ulimit -s可查看)

- socket连接数
    - 理论上一个进程可以最多同时建立65535个TCP客户端连接
    - 线程的socket连接受到资源描述符限制 ulimit -n

### 调度
- 不支持抢占
    - FIFO/FCFS
    - SJF - shortest job first
- 支持抢占
    - SRTCF - shortest remaining time complete first
    - Round Robin

### linux多线程同步的方法
- 互斥锁（mutex）
- 读写锁（RWMutex）
- 信号量（semaphore）
    - sync.WaitGroup基于此实现
    - count - 非负的整数计数器
- 条件变量（condition variables）
    - wait
    - signal
    - 当条件不满足时，thread进入睡眠状态；一旦条件满足就唤醒线程

### 死锁的原因 和 怎么解决
- 死锁是指两个或两个以上的进程在执行时，由于资源竞争导致的相互等待对方释放资源，导致都无法继续推进下去
- 原因
    - 系统资源不足
    - 程序执行的顺序有问题
    - 资源分配不当等
- 死锁产生的必要条件
    - 互斥：一个资源每次只能被一个进程使用

### 循环锁


### Linux怎么执行线程和进程，区别是什么？