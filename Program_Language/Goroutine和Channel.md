### 协程 Goroutines
- 协程 类似于一个线程，但是由 Go 而不是操作系统预定。在 协程 中运行的代码可以与其他代码同时运行。
- <font color=red>**go 关键字**</font>
- 协程 易于创建且开销很小。最终多个 协程 将会在同一个底层的操作系统线程上运行。这通常也称为 M:N 线程模型，因为我们有 M 个应用线程（ 协程 ）运行在 N 个操作系统线程上。结果就是，一个 协程 的开销和系统线程比起来相对很低（几 KB）。在现代的硬件上，有可能拥有数百万个 协程 。
```
package main

import (
  "fmt"
  "time"
)

const MAX_PROCESS = 12

func main() {
  fmt.Println("start")
  for i := 0; i < MAX_PROCESS; ++i {
    go process()
  }
  time.Sleep(time.Millisecond * 10) // 不建议，建议使用waitGroup（后面有说明）

  fmt.Println("done")
}

func process() {
  fmt.Println("processing")
}

```
注意：这个例子中，使用了 Sleep 让程序等了几毫秒。这是因为主进程在退出前 协程 才会有机会去执行（主进程在退出前不会等待全部 协程 执行完毕）。要解决这个问题，我们需要<font color=red>协调我们的代码</font>。


### 同步&锁
- 读操作是安全的，可以同时存在多个读；但是<font color=red>**写操作高风险，需要保持同步**</font>
- 下面例子中，对counter的写操作是异步的，高风险 输出：*随机顺序的1~20; 甚至会出现重复或者丢失*
```
package main

import (
  "fmt"
  "time"
)

var counter = 0

func main() {
  for i := 0; i < 20; i++ {
    go incr()
  }
  time.Sleep(time.Millisecond * 10)
}

func incr() {
  counter++
  fmt.Println(counter)
}
```
- 引入互斥锁
```
package main

import (
  "fmt"
  "time"
  "sync"
)

var (
  counter = 0
  lock sync.Mutex   // 定义锁，初始化为未加锁状态
)

func main() {
  for i := 0; i < 20; i++ {
    go incr()
  }
  time.Sleep(time.Millisecond * 10)
}

func incr() {
  lock.Lock()
  defer lock.Unlock()
  counter++
  fmt.Println(counter)
}
```
- 加锁的劣势
  - 1，大规模编程中，并不是经常能很明显知道什么代码需要保护
  - 2，像这种 覆盖着大量代码的锁操作 违背了并发编程的初心
  - 3，易引发死锁问题
    - 3.1, 在代码中使用两个或者更多的锁，很容易出现一种危险的情况，当协程 A 拥有锁 lockA ，想去访问锁 lockB ，同时协程 B 拥有锁 lockB 并需要访问锁 lockA 。
    - 3.2, 就是当我们忘记释放锁
  - 4，给程序员增加了负担

- 读写互斥锁
  - 一个锁定读取和一个锁定写入。它的区别是允许多个同时读取，同时确保写入是独占的
  - sync.RWMutex 就是这种锁。另外 sync.Mutex 结构不但提供了 Lock 和 Unlock 方法 ，也提供了 RLock 和 RUnlock 方法；其中 R 代表 Read.

- 原子函数
```
import(
  "sync/atomic"
)

var counter int

atomic.AddInt64(&counter 1)
```


### 通道 channel
- 为解决上面的问题，提出channel的概念
- 通道是协程之间用于传递数据的共享管道。换而言之，一个协程可以通过一个通道向另外一个协程传递数据。因此，在任意时间点，只有一个协程可以访问数据。

#### waiteGroup 方法
- 防止程序在所有goroutine执行完之前终止

```
package main

import (
  "fmt"
  "time"
  "math/rand"
  "sync"
)

// 构造一个waitGroup; 以便保证所有的goroutine执行之后再退出程序
var waitGroup sync.WaitGroup

// 设置需要等待的goroutine个数
waitGroup.Add(5)

func main() {
  c := make(chan int)       // 创建一个channel传递整数
  for i := 0; i < 5; i++ {
    worker := &Worker{id: i}
    go worker.process(c)    // channel作为入参传递给函数
  }

  for i := 0; i < 20; i++ {
    c <- rand.Int()         // 向channel中传递一个随机int
    time.Sleep(time.Millisecond * 50)
  }

  go func() {
    // 等待所有的任务完成
    waitGrooup.Wait()

    // 以关闭通道的方式，告诉程序可以退出了
    close(c)
  }
}

type Worker struct {
  id int
}

func (w *Worker) process(c chan int) {
  for {
    data := <-c             // 从channel中读取数据
    fmt.Printf("worker %d got %d\n", w.id, data)
  }

  // 计数-1
  waitGroup.Done()
}
```
-  Go 保证了发送到通道的数据只会被一个接收器接收。
- 这里，唯一的共享状态是通道，我们可以安全地同时从它接收和发送数据。通道提供了所有我们需要的同步代码保证，在任何时间只有一个 goroutine 可以访问特定的数据。

### 有缓冲的channel 和 无缓冲的channel
#### unbuffered channel: 在接收前没有能力保存任何值的channel
- 要求发送 goroutine 和 接收 goroutine 同时准备好 
- 当发送goroutine 和 接收goroutine 任意一方未就绪，channel阻塞
- 传递完成之前，发送goroutine不会释放资源

#### buffered channel:  在接收前能存储1个或多个值的通道
- 发送goroutine可以直接发送数据到channel，发送完成后释放goroutine资源<无其他操作>
- 当通道中没有要接收的值时，接收动作阻塞
- 当通道中没有可用缓冲区容纳要发送的值时，发送动作阻塞
- 当通道关闭后，goroutine依旧可以从channel中接收数据；但是不能再向channel中发送数据：(保证数据不丢失)
```
package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

const (
	numberGoroutines = 4  // Number of goroutines to use.
	taskLoad         = 10 // Amount of work to process.
)

var wg sync.WaitGroup


func init() {
	// Seed the random number generator.
	rand.Seed(time.Now().Unix())
}

// main is the entry point for all Go programs.
func main() {
	tasks := make(chan string, taskLoad)

	wg.Add(numberGoroutines)
	for gr := 1; gr <= numberGoroutines; gr++ {
		go worker(tasks, gr)
	}

	// Add a bunch of work to get done.
	for post := 1; post <= taskLoad; post++ {
		tasks <- fmt.Sprintf("Task : %d", post)
	}

	// Close the channel so the goroutines will quit
	// when all the work is done.
	close(tasks)

	// Wait for all the work to get done.
	wg.Wait()
}

// worker is launched as a goroutine to process work from
// the buffered channel.
func worker(tasks chan string, worker int) {
	// Report that we just returned.
	defer wg.Done()

	for {
		// Wait for work to be assigned.
		task, ok := <-tasks
		if !ok {
			// This means the channel is empty and closed.
			fmt.Printf("Worker: %d : Shutting Down\n", worker)
			return
		}

		// Display we are starting the work.
		fmt.Printf("Worker: %d : Started %s\n", worker, task)

		// Randomly wait to simulate work time.
		sleep := rand.Int63n(100)
		time.Sleep(time.Duration(sleep) * time.Millisecond)

		// Display we finished the work.
		fmt.Printf("Worker: %d : Completed %s\n", worker, task)
	}
}
```

### GOMAXPROCS 参数
```
// 给可用的核心分配一个逻辑处理器
runtime.GOMAXPROCS(runtime.NumCPU())
```