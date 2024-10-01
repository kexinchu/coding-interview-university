# 操作系统接口

### 什么是操作系统接口
    其实就是函数,一些系统提供的能调用硬件资源的函数，类似printf

- POSIX: Portable Operating System Interface of Unix (IEEE制定的一个标准族)
- 可以通过POSIX来查询操作系统接口
|分类|POSIX定义|描述|
|-|-|-|
|任务管理|fork|创建一个进程|
|任务管理|execl|运行一个可执行程序|
|任务管理|pthread_create|创建一个线程|
|文件系统|open|打开一个文件或目录|
|文件系统|EACCES|返回值，表示没有权限|
|文件系统|mode_t st_mode|文件头结构：文件属性|

### System Call的实现
- 不能随意的调用数据，不能随意的jmp，因为如果可以，用户A就可以随意访问用户B的数据
- 计算机通过"硬件设计"区分内核态和用户态，来支持内核程序和用户程序的隔离
  - 将内存分为内核段 和 用户段 (通过段寄存器CS的最低两位来表示：0表示当前程序执行在内核态，3表示执行在用户态)
  - DPL目标特权级 & CPL 当前特权级; 仅当DPL >= CPL时，程序才能够执行

### 硬件提供中断指令int 0x80来提供进入内核的方法
- int指令将CS的CPL改为0 进入内核；这是用户程序调起内核的唯一方式
- 核心
  - 用户程序中包含一段包含int 0x80指令的代码
  - 操作系统写中断处理，获取想调程序的编号 (将系统调用编号复制给eax寄存器) 
    - 系统调用号声明在 linux/include/unistd.h中
    - 比如：#define __NR_write	4 
  - 操作系统根据编号执行相应的代码
    - sys_call_table 全局函数数组，存放在include/linux/sys.h中

<img src="https://github.com/kexinchu/coding-interview-university/blob/master/OperatingSystem%26Linux/pictures/system_call_implementation.jpg" width="450px">
