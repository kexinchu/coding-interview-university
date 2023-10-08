# CPU&进程管理 (多进程图像)

### 大纲
- 基础原理
- 读写PCB，OS中最重要的数据结构，贯穿始终 L9
- 要操作寄存器完成进程的切换            L10,L11,L12
- 要写调度程序，更好的调度不同的进程     L13, L14
- 要有进程同步与合作                  L16, L17
- 要有地址映射，避免进程之间的干扰      L20


### CPU的工作原理
- 自动的取指 -- 执行
  - 设置PC初值(为程序段的初始地址)即可，后面CPU会自动按顺序去取指 -- 执行
  - IO操作非常耗时
  - 为了提高CPU的利用率，使多个程序交替执行  -- 并发

### PCB (Process Control Block)
- 为每个程序分配的存放返回地址，变量信息的结构
- 在程序交替执行期间，保存程序自身的状态，避免相互干扰

<img src="https://github.com/kexinchu/coding-interview-university/blob/master/OperatingSystem%26Linux/pictures/process_control_block.jpg" width="450px">

- 进程状态图
  ```
  // 新建态 -> 就绪态 <-> 运行态 -> 终止态
  //              \     /
  //               V   V
  //               阻塞态
  ```

### 进程的概念
- 进程是执行中的程序
  - 操作系统通过管理进程来管理用户对CPU等计算机资源的使用
- init/main.c中fork()了第一个进程，执行了shell程序/bin/sh
- 在shell中再启动其他的进程
```
// 下面fork()用于创建一个子进程(任务2)。对于被创建的子进程，fork()将返回0值，对于
// 原进程(父进程)则返回子进程的进程号pid。该子进程关闭了句柄0(stdin)、以只读方式打开
// /etc/rc文件，并使用execve()函数将进程自身替换成/bin/sh程序(即shell程序)，然后
// 执行/bin/sh程序。然后执行/bin/sh程序。所携带的参数和环境变量分别由argv_rc和envp_rc
// 数组给出。关闭句柄0并立即打开/etc/rc文件的作用是把标准输入stdin重定向到/etc/rc文件。
// 这样shell程序/bin/sh就可以运行rc文件中的命令。由于这里的sh的运行方式是非交互的，
// 因此在执行完rc命令后就会立刻退出，进程2也随之结束。
// _exit()退出时出错码1 - 操作未许可；2 - 文件或目录不存在。
if (!(pid=fork())) {
    close(0);
    if (open("/etc/rc",O_RDONLY,0))
        _exit(1);                       // 如果打开文件失败，则退出(lib/_exit.c)
    execve("/bin/sh",argv_rc,envp_rc);  // 替换成/bin/sh程序并执行
    _exit(2);                           // 若execve()执行失败则退出。
}
// 下面还是父进程(1)执行语句。wait()等待子进程停止或终止，返回值应是子进程的进程号(pid).
// 这三句的作用是父进程等待子进程的结束。&i是存放返回状态信息的位置。如果wait()返回值
// 不等于子进程号，则继续等待。
if (pid>0)
    while (pid != wait(&i))
        /* nothing */;
// 如果执行到这里，说明刚创建的子进程的执行已停止或终止了。下面循环中首先再创建
// 一个子进程，如果出错，则显示“初始化程序创建子进程失败”信息并继续执行。对于所
// 创建的子进程将关闭所有以前还遗留的句柄(stdin, stdout, stderr),新创建一个会话
// 并设置进程组号，然后重新打开/dev/tty0作为stdin,并复制成stdout和sdterr.再次
// 执行系统解释程序/bin/sh。但这次执行所选用的参数和环境数组另选了一套。然后父
// 进程再次运行wait()等待。如果子进程又停止了执行，则在标准输出上显示出错信息
// “子进程pid挺直了运行，返回码是i”,然后继续重试下去....，形成一个“大”循环。
// 此外，wait()的另外一个功能是处理孤儿进程。如果一个进程的父进程先终止了，那么
// 这个进程的父进程就会被设置为这里的init进程(进程1)，并由init进程负责释放一个
// 已终止进程的任务数据结构等资源。
while (1) {
    if ((pid=fork())<0) {
        printf("Fork failed in init\r\n");
        continue;
    }
    if (!pid) {                                 // 新的子进程
        close(0);close(1);close(2);
        setsid();                               // 创建一新的会话期
        (void) open("/dev/tty0",O_RDWR,0);
        (void) dup(0);
        (void) dup(0);
        _exit(execve("/bin/sh",argv,envp));
    }
    while (1)
        if (pid == wait(&i))
            break;
    printf("\n\rchild %d died with code %04x\n\r",pid,i);
    sync();                                     // 同步操作，刷新缓冲区。
}
```

### 进程切换 - 通过操作寄存器实现
- 进程切换的一个例子
  ```
  // 启动磁盘读写
  pCur.state = 'W';  // 阻塞态
  将pCur放到DiskWaitQueue中
  schedule();

  // scedule函数 - 很重要
  schedule() {
    pNew = getNext(ReadyQueue);
    switch_to(pCur, pNew);
  }

  // example pf switch
  switch_to(pCur, pNew) {
    pCur.ax = CPU.ax;
    pCur.bx = CPU.bx;
        ...
    pCur.cs = CPU.cs;
    pCur.retpc = CPU.pc;

    // 切换
    CPU.ax = pNew.ax;
    CPU.bx = pNew.bx;
       ...
    CPU.cs = pNew.cs;
    CPU.pc = pNew.retpc;
  }
  ```

- 用户级线程(User Thread)
  - 进程 = 一个资源 + 多个指令执行序列;  是否能将进程中的资源与指令执行分开, 使得在切换时仅进行指令的切换，提高切换效率
    - 线程: 保留了并发的优点，又避免了进程切换的代价
    - 资源的切换在内存部分会讲，这里先将指令的切换(分治)

<img src="https://github.com/kexinchu/coding-interview-university/blob/master/OperatingSystem%26Linux/pictures/process_user_thread.jpg" width="450px">

  - 线程的切换：主动释放 yield + 同时触发 pthread_create
    - 问题1：如果多个应用程序执行时，共用一个栈；会造成当PC从线程B跳回到线程A且线程A需要弹栈时，因为此时栈尾是线程B的地址，所以会出bug。
      - 怎么解决：每个线程维护自己的栈空间，且每个线程仅允许在自己的栈空间操作
      - TCB (Thread Control Block): 存放栈数据的数据结构 =》切换之前先换栈
      ```
      // sample
      void Yeild() {
        TCB2.esp = esp;   // esp - CPU中的一个寄存器，存放的是执行程序的TCB地址
        esp = TCB1.esp;   
      }                   // yeild函数返回时，ret从站中弹出栈；线程A从栈中获取下一条指令的地址(例如：栈尾存放的是地址204，就执行204) 
      ```
      - 总结：两个线程的样子 = 两个TCB + 两个栈 + 切换的指令地址存放在栈中
      - CreateThread就是用程序做到这三个东西
      ```
      void CreateThread(A) {
        TCB *tcb = malloc();
        *stack = malloc();
        *stack = A;
        tcb.esp = stack;
      }
      ```
  - 汇总

<img src="https://github.com/kexinchu/coding-interview-university/blob/master/OperatingSystem%26Linux/pictures/process_user_thread_sample.jpg", width="450px">

  - 用户级线程的问题：
    - Yield是用户程序，CPL=3；所以当某个线程进入内核执行并阻塞时(比如浏览器这里例子中，如果线程A进入内核执行，并申请IO下载数据)；此时内核不知道还有其他线程可以切换，而会直接进行进程的切换；导致用户级线程间的并发毫无作用。

<img src="https://github.com/kexinchu/coding-interview-university/blob/master/OperatingSystem%26Linux/pictures/process_user_thread_weakness.jpg", width="450px"> 

    - 所以需要核心级线程，将TCB注册到内核中，内核管理TCB，实现内核在线程间切换 (并发性更好)
      - 核心级线程的切换(Schedule：有用户级线程的Yield区分开)，用户完全不可见，由系统来决定调度点

- 核心级线程(Kernel Thread)
  - 并发 与 并行的区别： 并发：同时触发，交替执行； 并行：真正意义上的并行处理。
  - 内核级线程才能发挥多核处理器的性能（共享Cache和MMU(Memory Management Unit)，多核同时计算）
  - 因为执行的代码仍然在用户态，还是要进行函数调用的，所以用户栈还需要保留 => 需要两套栈 (两套栈要同步切换)
  ```
      |         |
      |  用户栈  |
      |         |
  用户 |代码和数据|
  -------------
  内核 |  内核栈  |
      |         |
      |线程控制块|
  ```
  - 什么时候启用内核栈 - INT中断; 用户栈和内核栈之间的关联

<img src="https://github.com/kexinchu/coding-interview-university/blob/master/OperatingSystem%26Linux/pictures/userstack_to_kernelstack.jpg", width="450px">  


### 进程调度

### 进程合作&同步

### 地址映射

### 多进程 && 内存
- 多个进程同时存在于内存中会有什么问题？ - 内存竞争与覆盖

<img src="https://github.com/kexinchu/coding-interview-university/blob/master/OperatingSystem%26Linux/pictures/process_memory_contention.jpg" width="250px">

- 解决方法：
  - 虚拟内存(内存管理): 不同进程保存各自的虚拟内存，通过虚拟内存 -> 物理内存的映射来将不同进程的物理内存区分开

<img src="https://github.com/kexinchu/coding-interview-university/blob/master/OperatingSystem%26Linux/pictures/process_memory_mapping.jpg" width="450px">

### 多进程如何合作
- 多进程交替直行时，会出现竞争；
  - 生产者-消费者实例中：因为交替执行，可能会导致任务队列的错误。(如下图的例子中，因为生产者和消费者交替执行，最后导致共享数据counter=4，而不是正确结果5)

<img src="https://github.com/kexinchu/coding-interview-university/blob/master/OperatingSystem%26Linux/pictures/process_producer-consumer_sample.jpg" width="450px">

 - 需要**进程同步**(合理的推进顺序)
   - 本例中，写共享数据counter时，应该阻断其他进程访问counter —— "锁"的引入
 
