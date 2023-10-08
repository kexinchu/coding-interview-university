# 操作系统介绍

- Typical UNIX OS Structure
  - Application             : 程序员编写并编译好的程序，通过调用Libraries 提供的函数来使用OS
  - Libraries               : 公共的库，提供预编译好的interface，供程序员使用
  - Portable OS Layer       : OS system calls
  - Machine-dependent Layer : Bootstrap, System initialization, I/O device driver, Kernel/User mode switching, Interrupt and exception, Provessor Management
<img src="https://github.com/kexinchu/coding-interview-university/blob/main/OperatingSystem&Linux/pictures/typical_unix_os_structure.jpg", width="450px">

- 