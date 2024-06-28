### 定义变量

```Go
// 类型相同
var vname1, vname2, vname3 type = v1, v2, v3

// 简化
var vname1, vname2, vname3 = v1, v2, v3

vname1, vname2, vname3 := v1, v2, v3
```
- 注意: **":="** 这个符号直接取代了 var 和 type, 这种形式叫做简短声明。不过它有一个限制，那就是它只能用在函数内部；在函数外部使用则会无法编译通过，所以一般用 var 方式来定义全局变量。


### 常量
- const关键字

```Go
const Pi = 3.1415926
const Pi float32 = 3.1415926    // 可以指定常量类型
const i = 10000
const MaxThread = 10
const prefix = "astaxie_"
```

## 内置基础类型
- bool
- int 和 uint
    - int 和 uint 的长度取决于不同编译器的实现
    - 支持固定位数的类型: 
        - int8, int16, int32, int64, rune
        - uint8, uint16, uint32, uint64, byte
        - rune 是 int32 的别称
        - byte 是 uint8 的别称
        - 注意这些不同类型的变量变量质检不允许相互赋值或操作，会编译器报错
- float32 和 float64
    - 没有float类型, 默认是float64
    - Go也支持复数：默认 *complex128* (64位实数 + 64位虚数)，也支持 *complex64* (32位实数 + 32位虚数)
- string - 字符串
    - 一般用 "" 括起来；如果需要声明多行，可以用 *\`* 来声明 (\'括起的字符串为 Raw 字符串，即字符串在代码中的形式就是打印时的形式，它没有字符转义，换行也将原样输出)。
    - Go 中字符串是不可变的，如果想要修改; 
        - 可以将字符串转换成 []byte 类型，修改之后，再转回 string 类型
        - 也可以通过切片来修改： 字符串可以进行切片操作
        - 可以通过 + 来链接两个字符串
- error - 错误类型
    - errors 包可以声明和处理错误
- Go 数据底层的存储
    <img src="./pictures/structure-storage.png" width=400px>

```Go
// Boolean
var isActive bool  // 全局变量声明
var enabled, disabled = true, false  // 忽略类型的声明
func test() {
    var available bool  // 一般声明
    valid := false      // 简短声明
    available = true    // 赋值操作
}

// Int
// 下面代码就会产生 invalid operation: a+b (mismatched types int8 and int32)
// 注意 int 和 int32 也不能互用
var a int8
var b int32
c := a + b

// 复数
var c complex64 = 5+5i

// string
var m string = `hello
    world`
var s string = "hello"
s[0] = 'c'   // cannot assign to s [0]
// 借助 []byte
c := []byte(s)
c[0] = 'c'
s2 = string(c)  // s2 = cello
// 通过切片
s = "c" + s[1:]  // s = cello

s := "hello, "
m := "world"
a := s + m       // a = "hello, world"

// error
err := errors.New("emit macho dwarf: elf header corrupted")
if err != nil {
    fmt.Print(err)
}
```

### iota 枚举
- Go里面的关键字：iota，用来声明 enum 的时候采用，它默认的开始值是0， const中每增加1行，值+1

```Go
const (
    x = iota // x == 0
    y = iota // y == 1
    z = iota // z == 2
    w        // 常量声明省略值时，默认和之前一个值的字面相同。这里隐式地说 w = iota，因此 w == 3。其实上面 y 和 z 可同样不用 "= iota"
)

const v = iota // 每遇到一个 const 关键字，iota 就会重置，此时 v == 0

const (
    h, i, j = iota, iota, iota // h=0,i=0,j=0 iota在同一行值相同
)

const (
    a       = iota // a=0
    b       = "B"
    c       = iota             //c=2
    d, e, f = iota, iota, iota //d=3,e=3,f=3
    g       = iota             //g = 4
)
```

## 首字母 大写 vs 小写
- 变量 & 函数: 首字母大写表示公有，可以被其他包读取，小写表示私有，表示不可导出


## array, slice, map
- array - 数组
    - 数组是定长的，长度定义之后不能修改
    - 支持多维数组
- slice
    - slice 并不是真正意义上的动态数组，而是一个 <font color=#FF000>**引用类型**</font>。slice 总是指向一个底层 array，slice 的声明也可以像 array 一样，只是不需要长度。
    <img src="./pictures/slice.png" width=400px>
- map - 字典
    - map[keyType]valueType
    - map 是无序的，每次打印出来的 map 都会不一样，它不能通过 index 获取，而必须通过 key 获取
    - map 的长度是不固定的，也就是和 slice 一样，也是一种引用类型
    - 内置的 len 函数同样适用于 map，返回 map 拥有的 key 的数量
    - map 的值可以很方便的修改，通过 numbers["one"]=11 可以很容易的把 key 为 one 的字典值改为 11
    - 在 Go 中，没有值可以安全地进行并发读写，它不是 thread-safe，在多个 go-routine 存取时，必须使用 mutex lock 机制


```Go
// Golang 并没有提供 Linked Lists 的数据结构
// 全局：
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


// Slice 是数组的一个封装，通过内部指针和相关属性引用数组片段. (数组的引用), 也支持通过下标访问引用的数组元素. 
// Slice 是引用类型，但是本身是结构体，还是值传递。
// Slice实际上是一个结构体：底层的存储类型是数组
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


// map
// 声明一个 key 是字符串，值为 int 的字典, 这种方式的声明需要在使用之前使用 make 初始化
var numbers map[string]int
// 另一种 map 的声明方式
numbers := make(map[string]int)
numbers["one"] = 1  // 赋值
numbers["ten"] = 10 // 赋值
numbers["three"] = 3

fmt.Println("第三个数字是: ", numbers["three"]) // 读取数据
// 打印出来如:第三个数字是: 3
```


## make 和 new 操作
- make 用于内建类型（map、slice 和 channel）的内存分配
    - 返回初始化后的（非零）值
- new 用于各种类型的内存分配, 
    - 返回值是对应内存地址的指针


## 零值 - 变量未填充前的默认值

```Go
int     0
int8    0
int32   0
int64   0
uint    0x0
rune    0 // rune 的实际类型是 int32
byte    0x0 // byte 的实际类型是 uint8
float32 0 // 长度为 4 byte
float64 0 // 长度为 8 byte
bool    false
string  ""
```
