### Radix Tree
- 基数树，原理跟Trie Tree极为相似，不同点是radix tree不是按照每个字符长度左节点拆分的，而是可以以一个或多个字符叠加作为一个分支，这样能避免长字符key会分出深度很深的节点。


### Gin的优点
- Gin 使用了 httprouter 作为底层路由引擎，它是基于 Radix Tree 实现的，非常高效。同时 Gin 提供了中间件机制和更灵活的路由定义。

### Protobuf如何加密
- Protobuf本身没有内建的加密功能
