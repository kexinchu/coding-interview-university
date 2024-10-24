
### Redis的发布/订阅模式 (Pub/Sub)
- 发布者向一个或多个channel发布消息，并不关心是否有订阅者
    ```shell
    PUBLISH news "Breaking news!"  # news 这里就是channel
    ```
- 订阅者订阅一个或多个channel，或者使用模式订阅来订阅符合特定模式的channel。当有发布者向channel发布消息时，订阅者会立即收到该消息
    ```shell
    SUBSCRIBE news sports    # 订阅了两个channel
    UNSUBSCRIBE news sports  # 取消 
    
    PSUBSCRIBE news.*       # 模式订阅
    PUNSUBSCRIBE news.*
    ```
- channel - 无缓存

- 注意：
    - Redis的Pub/Sub无消息确认机制，消息可能会丢失
    - 无持久化


### Redis有哪些结构
- 字符串
    - 最基础类型，每个键最多存储 512 MB 数据
    - 常用于缓存简单的键值对，计数器等
    - SDS(simple dynamic string) 是Redis中使用的一种动态字符串结构，用于高效的处理字符串操作；SDS 在 C 语言传统字符串的基础上，增加了一些额外的字段，用于管理字符串的长度和内存分配信息
- 列表
    - 底层是双向链表，按照插入顺序排序
    - 常用在任务队列，消息队列，记录历史数据时
    - LPUSH从列表头部插入值，LPOP从列表头部弹出值，类似栈的操作，是一对常用的操作
- 集合（Set）
    - 底层是hash表，无序
- 有序集合（Sorted Set）
    - 跳表实现
- hash (key-value 集合)

- Redis的有序集合（Sorted Set）通过跳表实现元素的快速查找、插入、删除。
    - 跳表支持范围查询
    - 跳表（Skip List）通过为有序链表添加多层索引，来加速查找、插入和删除操作。它的时间复杂度可以达到 O(log n)。


### Redis设置过期时间
```shell
EXPIRE mykey 60  # 设置key过期时间为60s

EXPRIREAT mykey 1672531199   # 设置过期时间戳

SET mykey "value" EX 60

SETEX mykey 60 "value"

```

### Golang 读写 Redis





