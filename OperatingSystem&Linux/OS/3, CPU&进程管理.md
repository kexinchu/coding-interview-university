### CPU的工作原理
- 自动的取指 -- 执行
  - 设置PC初值(为程序段的初始地址)即可，后面CPU会自动按顺序去取指 -- 执行
  - IO操作非常耗时
  - 为了提高CPU的利用率，使多个程序交替执行  -- 并发

- PCB (Process Control Block): 为每个程序分配的存放返回地址，变量信息的结构
  - 在程序交替执行期间，保存程序自身的状态，避免相互干扰
  <img src="https://github.com/kexinchu/coding-interview-university/blob/main/OperatingSystem&Linux/pictures/process_control_block.jpg" width="450px">
  - 进程状态图
  ```
  // 新建态 -> 就绪态 <-> 运行态 -> 终止态
  //              \     /
  //               V   V
  //               阻塞态
  ```
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


### 进程
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

### 多进程如何实现切换
