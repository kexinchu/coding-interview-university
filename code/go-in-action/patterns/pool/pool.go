// Example provided with help from Fatih Arslan and Gabriel Aszalos.
// Package pool manages a user defined set of resources.

// - 使用 buffered channel 来实现资源池
//     - 管理可以在任意数量的goroutine之间共享及独立使用的资源
// 	- 这种模式在需要共享一组静态资源的情况下(如共享数据库/内存缓冲区)非常有用

// 	- **标准库: sync.Pool 已经实现了资源池**

package pool

import (
	"errors"
	"io"
	"log"
	"sync"
)

// Pool manages a set of resources that can be shared safely by
// multiple goroutines. The resource being managed must implement
// the io.Closer interface.
type Pool struct {
	m         sync.Mutex
	resources chan io.Closer
	factory   func() (io.Closer, error) // 函数类型
	closed    bool
}

// ErrPoolClosed is returned when an Acquire returns on a
// closed pool.
var ErrPoolClosed = errors.New("Pool has been closed.")

// New creates a pool that manages resources. A pool requires a
// function that can allocate a new resource and the size of
// the pool.
func New(fn func() (io.Closer, error), size uint) (*Pool, error) {
	if size <= 0 {
		return nil, errors.New("Size value too small.")
	}

	return &Pool{
		factory:   fn,
		resources: make(chan io.Closer, size),
	}, nil
}

// Acquire retrieves a resource	from the pool.
func (p *Pool) Acquire() (io.Closer, error) {
	select {
	// Check for a free resource.
	case r, ok := <-p.resources:
		log.Println("Acquire:", "Shared Resource")
		if !ok {
			return nil, ErrPoolClosed
		}
		return r, nil

	// Provide a new resource since there are none available.
	default:
		log.Println("Acquire:", "New Resource")
		return p.factory()
	}
}

// Release places a new resource onto the pool.
func (p *Pool) Release(r io.Closer) {
	// Secure this operation with the Close operation.
	p.m.Lock()
	defer p.m.Unlock()
	// 这里的互斥量和Close函数中的互斥量是同一个；这样可以阻止两个方法在不同的goroutine中同时运行
	// 1, 保证76行，同一时间不会有其他Goroutine调用Close方法写同一个标志
	// 2, 不想王一个已经关闭的通道里塞数据，会造成panic

	// If the pool is closed, discard the resource.
	if p.closed {
		r.Close()
		return
	}

	select {
	// Attempt to place the new resource on the queue.
	case p.resources <- r:
		log.Println("Release:", "In Queue")

	// If the queue is already at cap we close the resource.
	default:
		log.Println("Release:", "Closing")
		r.Close()
	}
}

// Close will shutdown the pool and close all existing resources.
func (p *Pool) Close() {
	// Secure this operation with the Release operation.
	p.m.Lock()
	defer p.m.Unlock()

	// If the pool is already close, don't do anything.
	if p.closed {
		return
	}

	// Set the pool as closed.
	p.closed = true

	// Close the channel before we drain the channel of its
	// resources. If we don't do this, we will have a deadlock(死锁).
	close(p.resources)
	// 必须保证同时只有一个goroutine可以执行这部分

	// Close the resources
	for r := range p.resources {
		r.Close()
	}
}
