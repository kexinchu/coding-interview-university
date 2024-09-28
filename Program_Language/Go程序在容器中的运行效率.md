程序要想获得更好的运行效率，一般需要针对运行环境进行一些参数调优。
Go 程序也不例外，通过设置合适的GOMAXPROCS值，可以提升Go程序在容器中的运行效率。


### 容器化环境的特点
- 通过Docker，百度的Matrix等容器技术，能提升RD对资源的利用率，更方便的管理资源。
- 容器和虚拟机类似，多个容器会共享同一台物理机上的资源。使一台物理机同时部署多个不同业务的APP。

<img src="https://github.com/kexinchu/coding-interview-university/blob/main/go-language/pictures/container.jpeg" width="350px"> 

补充：
- Matrix 是比虚拟机更轻量的容器技术，没有虚拟出 CPU 资源，而是直接使用宿主机的 CPU 资源，通过cgroup等技术来对cpu等资源进行分配和管理。但是，我们在Matrix容器里看到 cpu 的总核数 和直接在宿主机上看到的是一样的。
- 另外，为了尽可能的提高资源利用率，CPU资源一般都是软限制的，如物理机是24核，部署3个应用，每个应用分配8核，若在一段时间内，其中一个应用使用的CPU核数超过了8核也是允许的。

#### 注意
- 配置容器时，如果不固定在固定的核心上，会默认占用每个核心的 *%；(比如物理核心8核，设置容器2核，不会直接绑定2个核心，而是占用每个核心的25%)；**所以下面说的设置 GOMAXPROCS 需要要求容器设置在固定的核心上才有意义。** 否则，底层容器的machine还是在被CPU竞争。

### Go 程序的特点
Go 的一个特色就是具有轻量级协程 Goroutine，利用该特性，我们可以很轻松的写出具有高并发处理能力的程序。Go 程序通过其 GMP 调度模型来调度运行协程 Goroutine 。该模型大致如下：

<img src="https://github.com/kexinchu/coding-interview-university/blob/main/go-language/pictures/GMP_new.png" width="350px"> 

GMP分别的含义是：
* G：是协程 Goroutine，业务代码在此执行，数量可以非常多。
* M：是线程 Machine，是操作系统的线程，即逻辑线程，会通过P来执行G。
* P：是处理器Processor，用于是M和G的中间桥梁，负责调度执行Goroutine以及管理运行过程中的上下文、状态等信息。执行中的goroutines数量小于等于P的数量


我们可以从上面的图里看到3个线程 M，每个线程都拥有一个上下文 P，每个线程都正在运行一个goroutine（G）。为了运行goroutine，一个线程必须拥有一个上下文。

每个 P 未执行的就绪 goroutines 被安排在 RQ（runqueue）的队列中。当一个 goroutine 建立时就被添加到 RQ 的末端。P 运行到这个 goroutine 就会把它 从 RQ 中 pop 出来，设置栈和指令指针并且开始运行这个 goroutine。
为了降低mutex竞争，每一个上下文都有它自己的 RQ。如果正在运行的线程因为某种原因需要阻塞的时候，P 会把 M 交给其它 G。

**在绝大多数时候，其实P的数量和M的数量是相等。 每创建一个 P, 就会创建一个对应的 M。当容器的 P 设置比较小而就绪的 G 很大时候，处理器会频繁的上下文切换，严重消耗处理器的性能，服务的性能也就越差。**
当然这是针对 CPU 密集型的任务来说，对于大多数 I/O 密集型的任务 P 未必是越大越好，这就需要 RD 在申请容器时酌情考虑。

P 的数量直接决定了 M 执行 G 的数量，我们对逻辑线程数量的优化点也就变成对于 P 数量的优化。

### AutoMaxProcs机制
上下文 P 的数目在启动时被设置为环境变量 GOMAXPROCS 的值或者通过运行时函数 runtime.GOMAXPROCS(int) int 来设置，**从Go 1.5版本开始，为了提升Go程序在多核环境下的运行效率，Go 的 runtime 会自动的设置其 GOMAXPROCS 值为运行机器环境的CPU逻辑核数。**

在物理机多容器混部时会出现一个问题，运行在容器里的程序，每个Go程序都认为它是独享整台物理机的，下图以一个24个逻辑CPU核的机器部署3个应用为例说明：(检测到的实际core数目为24核)

<img src="https://github.com/kexinchu/coding-interview-university/blob/main/go-language/pictures/go_max_procs_24_core_actual.png" width="350px"> 

而若是按照实际分配的CPU QUOTA情况看，其最优分配情况应该是如下这样（分别设置P个数为9，9，6）：

<img src="https://github.com/kexinchu/coding-interview-university/blob/main/go-language/pictures/go_max_procs_24_core_target.png" width="350px"> 

这就导致了一个问题，活跃的 P 和 M 的个数超过了实际分配的 QUOTA，最优情况是一个 CPU 逻辑核运行一个线程，而实际是运行了2-3个线程。额外的线程的上下文切换成本导致了程序的性能有损，那么我们该怎么做呢？

问题已经明确了：**P 的数量和分配的 CPU 的 QUOTA 不匹配。那么我们要想办法获取 Matrix 容器分配给应用的 CPU QUOTA信息，然后设置上正确的P值即可**。

- 百度的容器Matrix提供了 MATRIX_RESOURCE_CPU_CORES 环境变量，可以获取CPU QUOTA值
```
// Get 获取Matrix容器可用cpu数量示例
func Get() (num int, err error) {
    coreNumStr := os.Getenv("MATRIX_RESOURCE_CPU_PHYSICAL_CORES")
    if coreNumStr == "" {
        return 0, fmt.Errorf("os.Getenv cpu num with empty value")
    }
    coreNum, _ := strconv.ParseFloat(coreNumStr, 32)
    if coreNum <= 0 {
		return 0, fmt.Errorf("os.Getenv cpu num with err value, coreNumStr: %s", coreNumStr)
    }
    // 四舍五入，最小值为1
    return int(math.Max(1, math.Round(coreNum))), nil
}

// Set 设置Matrix容器可用cpu数量示例
// Set 设置GOMAXPROCS值
// 若环境变量GOMAXPROCS有值将不进行设置（go自己会使用该值）
func Set(num int) (cpuNum int, ok bool) {
    if os.Getenv("GOMAXPROCS") != "" {
        return runtime.GOMAXPROCS(-1), false
    }
    return runtime.GOMAXPROCS(num), num >= 1
}
```

- Docker 和 Kubernetes 不支持区分获取服务真实占用的CPU QUOTA值，但是 Uber 提出了一种 Workaround [uber-go/automaxprocs](https://github.com/uber-go/automaxprocs)。利用这一个包，可以在运行时根据 cgroup 或者 runtime 来修改 GOMAXPROCS，来选择一个合适的取值.

