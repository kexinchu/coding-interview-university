## Array
- 数组
- fix length, 长度定义之后不能够修改
- 支持多维数组

```go
var array_ [10]int  // length is 10
// 直接初始化
var arr0 [5]int = [5]int{1, 2, 3}
var arr1 = [5]int{1, 2, 3, 4, 5}
var arr2 = [...]int{1, 2, 3, 4, 5, 6}   // 根据初始化值确定数组长度
var str = [5]string{3: "hello world", 4: "tom"}
// 局部：
a := [3]int{1, 2}           // 未初始化元素值为 0。
b := [...]int{1, 2, 3, 4}   // 通过初始化值确定数组长度。
c := [5]int{2: 100, 4: 200} // 使用索引号初始化元素。
d := [...]struct {
    name string
    age  uint8
}{
    {"user1", 10}, // 可省略元素类型。
    {"user2", 20}, // 别忘了最后一行的逗号。
}
// Note: 数组是定长的, 长度定义之后不能再修改
```

## Slice
- slice长度可变，(数组长度一旦确定之后不可变)
- slice是一个 <font color=#FF000>**引用类型**</font>。底层是指向数组的指针，数据存放在数组中
```go
var slice_ []int    // 无显式length
```

- 实际结构
```go
type SliceHead struct {
    Data uintptr    // 指向底层数组的指针
    Len  int        // 切片长度
    Cap  int        // 切片容量
}
```
- Slice 扩容
    - 扩容实际是新建了一个新的数组
        - If slice 的Cap还有剩余空间，此时append 不会分配新的底层容量，只是改变slice的Len，不改变Cap
    - 扩容机制
        - go 1.17及以前：如果需要的容量>旧容量的2倍，直接扩容到期望容量；否则，如果旧容量<1024, 扩充成旧容量的两倍；否则扩充为旧容量的1.25倍
        - go 1.18及以后：如果需要的容量>旧容量的2倍，直接扩容到期望容量；否则，如果旧容量<256, 扩充成旧容量的两倍；否则每次容量增加 (旧容量 + 3 * threshold) / 4 

- 如果 Golang Slice 扩容机制仅仅是简单的倍增（如2倍）, 如何减少内存浪费?
    - 在初始化的时候，尽量预估所需的容量，避免频繁的扩容
    ```go
    s := make([]int, length, capacity);
    ```
    - 使用append并手动控制容量 (一次性扩展所需的容量)
    ```go
    s = append(s, make([]int, 1000)...)
    ```
    - 配置更合理的增长因子
    - 使用copy合理的缩小slice的长度
    ```go
    s = s[:desiredLen]
    ```

<img src="./pictures/go-slice.png" width=300px>

```go
// runtime/slice.go
type slice struct {
    array unsafe.Pointer // 元素指针
    len   int // 长度 
    cap   int // 容量
}
// Node: 底层数组是可以被多个 slice 同时指向的，因此对一个 slice 的元素进行操作是有可能影响到其他 slice 的。
slice := []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
s1 := slice[2:5]
s2 := s1[2:6:7]

s2 = append(s2, 100)
s2 = append(s2, 200)

s1[2] = 20
```