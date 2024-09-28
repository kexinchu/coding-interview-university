# 操作系统启动

- 操作系统在内存中必须是：boot -> setup -> system; 供CPU按顺序执行

### Step1 将操作系统从磁盘读到内存里
- Start with bootsect.s  (引导扇区)
  - load setup (打印logo)
    ```
    load_setup:
        mov	dx,#0x0000		! drive 0, head 0
        mov	cx,#0x0002		! sector 2, track 0
        mov	bx,#0x0200		! address = 512, in INITSEG
        mov	ax,#0x0200+SETUPLEN	! service 2, nr of sectors
        int	0x13			! read it
        jnc	ok_load_setup		! ok - continue
        mov	dx,#0x0000
        mov	ax,#0x0000		! reset the diskette
        int	0x13			! 13号中断
        j	load_setup

    ok_load_setup:
    ```
  - load system
- jump to setup.s 并执行; 完成OS启动前的设置
  - Point1, 获取扩展内存大小，并存储在0x90002的内存地址处；方便后续OS对资源进行管理
  ```
  ! Get memory size (extended mem, kB)
      mov	ah,#0x88
      int	0x15
      mov	[2],ax    ! 获取扩展内存大小，并存储在0x90002的内存地址处; 方便后续进行管理
  ```
  - Point2, 将操作系统移动到0地址开始的内存块中
  ```
  do_move:
      mov	es,ax		! destination segment; 将操作系统移动到0地址开始内存块中
      add	ax,#0x1000
      cmp	ax,#0x9000
      jz	end_move
      mov	ds,ax		! source segment
      sub	di,di
      sub	si,si
      mov 	cx,#0x8000
      rep
      movsw
      jmp	do_move
  ```
  - Point3 从实模式进入保护模式：执行完jmpi 0,8
    ```
    mov ax,#0x0001
    mov cr0,ax
    jmpi 0,8
    ```
    - CS 和 IP 是086CPU中两个关键的寄存器，它们指示了CPU当前要读指令的地址; CS: 代码段寄存器; IP: 指令指针寄存器; 在8086机中，任意时刻，CPU将CS:IP指向的内容当做指令来执行; CS << 4 + IP; 例如在这里 8H * 16 + 0H, 得到的地址是80(H) - 这是实模式下
    - 保护模式下(GDT - global description table); 根据CS来查表 + IP
      - 所以在setup.s中会有一个gdt的初始化程序;
      - 这里因为进入了保护模式(cr0=#0x0001), 所以新的jmpi地址为：gdt地址为8H的基址 + 0H的偏移。结合setup.s中gdt初始化的地址；最终确定地址为0x0000
  - 为什么要进保护模式
    - CS和IP都是16位寄存器，只能管理最多20位的内存空间 - 即1M；无法管理现在4G甚至更大的空间
    - 16位机 -> 32位机
      - mov cr0,ax
      - cr0 寄存器，当cr0最后一位(PE)为1时，启动保护模式，第一位(PG)为1时启动分页
  
  |内存地址|长度|名称|
  |-|-|-|
  |0x90000|2|光标位置|
  |0x90002|2|拓展内存大小|
  |0x9000C|2|显卡参数|
  |0x901FC|2|根设备号|

- 跳到system模块(目标代码)执行
  - system模块中的第一部分是head.s
  - Makefile
    ```
    disk: Image
	    dd bs=8192 if=Image of=/dev/fd0
    Image: boot/bootsect boot/setup tools/system tools/build
	    tools/build boot/bootsect boot/setup tools/kernel $(ROOT_DEV) > Image
	tools/system:	boot/head.o init/main.o $(DRIVERS) $(MATH) ** 
        $(LD) boot/head.o init/main.o *** -o tools/system 
    ```
  - setup.s是进入保护模式，head是进入之后的初始化，再次setup idt和gdt表
  - setup.s中因为进入了保护模式，汇编语言也改变了，编委32为汇编语言
  - after_page_tables 设置页表
    ```
    after_page_tables:
        pushl $0		# These are the parameters to main :-)
        pushl $0
        pushl $0
        pushl $L6		# return address for main, if it decides to.
        pushl $main     # 调用的函数
        jmp setup_paging
    L6:
        jmp L6			# main should never return here, but just in case, we know what happens.
    setup_paging: 设置页表 ret
    ```
    - setup_paging执行到ret之后，会执行函数main(),main函数后的栈为0,0,0,L6，表示main()的三个参数是0，0，0；且当函数返回时，进入L6，死循环...
    - 从这里开始，**进入到main函数 - init/main.c**
    ```
    void main(void) {
      // 以下是内核进行所有方面的初始化工作
      mem_init(main_memory_start,memory_end); // 主内存区初始化。mm/memory.c
      trap_init();                            // 陷阱门(硬件中断向量)初始化，kernel/traps.c
      blk_dev_init();                         // 块设备初始化,kernel/blk_drv/ll_rw_blk.c
      chr_dev_init();                         // 字符设备初始化, kernel/chr_drv/tty_io.c
      tty_init();                             // tty初始化， kernel/chr_drv/tty_io.c
      time_init();                            // 设置开机启动时间 startup_time
      sched_init();                           // 调度程序初始化(加载任务0的tr,ldtr)(kernel/sched.c)                        // 缓冲管理初始化，建内存链表等。(fs/buffer.c)
      buffer_init(buffer_memory_end);
      hd_init();                              // 硬盘初始化，kernel/blk_drv/hd.c
      floppy_init();                          // 软驱初始化，kernel/blk_drv/floppy.c
      sti();                                  // 所有初始化工作都做完了，开启中断
      
      // 下面过程通过在堆栈中设置的参数，利用中断返回指令启动任务0执行。
      move_to_user_mode();                    // 移到用户模式下执行
      if (!fork()) {		/* we count on this going ok */
        init();                               // 在新建的子进程(任务1)中执行。
      }
      // pause系统调用会把任务0转换成可中断等待状态，再执行调度函数。但是调度函数只要发现系统中 没有其他任务可以运行是就会切换到任务0，而不依赖于任务0的状态。
      for(;;) pause();
    }
    ```
