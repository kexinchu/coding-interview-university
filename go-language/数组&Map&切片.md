### 数组
- 声明数组时需要指定元素类型 + 数组长度； 且定义之后数组长度固定；如果需要存储更多的数组，需要声明一个新的数据，并将数组中的值复制到新数组中
```
array := [5]int{1,2,3,4,5}
```
- [...] 根据初始化时数组元素的数量 确定长度
```
array := [...]int{1,2,3,4,5}
```
- 指定特定元素的值
```
array := [5]int{1:20, 2:30}  // [0,20,30,0,0]
```
- 数组间相互复制 (会 check 数组元素类型+长度)
```
var array1 [4]int

array2 := [5]int{1,2,3,4,5}

array1 = array2  // 报错
```
- 指针数组赋值
```
var array1 [2]*string

// 定义数组长度 + 指针
array2 := [3]*string{new(string), new(string), new(string)}

*array2[0] = "blue"
*array2[1] = "yellow"
*array2[2] = "red"

// 两个数组指向同一组字符串
array1 = array2
```

- **多维数组也是一样的**

### 切片(数组)
#### 切片的数据结构
  -  地址指针 - 长度 - 容量
  -  切片需要占据 24 Byte的内存： 8 Byte的指针 + 长度/容量各8 Byte
 <img src="https://github.com/kexinchu/coding-interview-university/blob/main/go-language/pictures/slice.png" width="350px"> 

- 因为切片是指针，所以复制指针，只是复制了切片本身，都指向同一个底层数组


- 初始化 (仅仅)声明之后，切片长度为0，此时通过slice[i]访问会报错
```
names := []string{"leto", "jessica", "paul"}
// cap = 3, len = 3

var names []string
// cap = 0, len = 0

// make(type, len, cap=0)
checks := make([]bool, 10)
// cap = 10, len = 10

scores := make([]int, 0, 20)
// cap = 20, len = 0 
// 注意此时，因为len=0; scores[7]=9 会报错
```

#### 常用函数
- append
```
scores := make([]int, 0, 20)
scores = append(scores, 5) // prints [5]
```
注意： Go中使用 2x 算法来增加切片长度
  - 切片长度 < 1000 时，通过 **<font color=red>X 2</font>** 来增加切片长度
  - 切片长度 > 1000 时，通过 **<font color=red>X 1.25</font>** 来增加切片长度

- 取子切片
  - **<font color=red>修改子切片的值会影响原切片的值</font>**
  - **<font color=red>对子切片append也有可能会影响</font>**
    - 因为都是指向同一个底层数组(oriArray), 如果对子切片append；同时底层数组还有余量(cap);则会直接修改oriArray[len(slice)]的值，如果另一个切片newSlice也指向这个index，则newSlice[len(slice)]也被修改了
    - 如果底层数组没有容量了，则不会<会新申请一个array，并复制 + append；这样切片的底层数组通过原底层数组分开>
```
scores := []int{1,2,3,4,5}
slice := scores[2:4]
slice[0] = 999
fmt.Println(scores)  // prints [1,2,999,4,5]
```
- 内建函数 copy
```
scores := []int{1,2,3,4,5,6,7,8,9}

worst := make([]int, 5)

copy(worst, scores[:5])
worst[0] = 10
fmt.Println(worst)  // [10 2 3 4 5]
fmt.Println(scores) // [1 2 3 4 5 6 7 8 9]

// 也可以只复制一部分
// copy(worst[2:4], scores[:5])
// fmt.Println(worst)  // [0 0 1 2 0]
```

- 不支持负数下标
```
// 删除最后一个元素
scores := []int{1, 2, 3, 4, 5}
scores = scores[:len(scores)-1]
```

- 删除元素
```
// 不会保持顺序 (原地)
func removeAtIndex(source []int, index int) []int {
  lastIndex := len(source) - 1
  // 交换最后一个值和想去移除的值
  source[index], source[lastIndex] = source[lastIndex], source[index]
  return source[:lastIndex]
}

// (移动)
seq = append(seq[:index], seq[index+1:]...)
```

- 通过切片来声明+初始化切片
```
source := [5]int{9,8,7,6,5}

// 得到len 3-2 = 1； cap 4-2 = 2 的切片
// slice = [7]
slice := source[2:3:4]
```
担心append切片修改底层数组，可以通过使创建的切片的cap = len； 这样在切片第一次append时，创建新的底层数组；与原来的底层数组分开
```
slice = source[2:3:3]
```

### map
#### 无序
  - 无序的原因是因为map的底层使用了散列表

- 底层原理可参考： https://juejin.cn/post/6972535873971847204

- 初始化
  - 未初始化的map的值为nil； nil值不能用来存储key-value对；
```
// 未初始化
var lookup map[string]string

lookup["red"] = "#da1337"  // 会报错

// 初始化
lookup = map[string]int{}{"a":1,}
lookup := make(map[string]int, 100)
```

- len 返回key的数量
- delete 删除一个键值对
```
// returns 1
total := len(lookup)

// has no return, can be called on a non-existing key
delete(lookup, "goku")
```

- 循环
```
for key, value := range lookup {
  ...
}
```
注意：
  - 1, 迭代映射是没有顺序的，每次迭代查找都会随机返回键值对
  - 2, range 返回的都是副本 


- 函数间传递map
  - 之间传递map并不会制造出该map的副本； 导致函数体内部修改传入的map；会影响其他依赖这个map的操作