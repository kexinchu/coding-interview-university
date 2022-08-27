### 切片(数组)
- 初始化
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
注意： Go中使用 2x 算法来增加数组长度

- 取子切片
```
// 注意修改子切片的值会影响原切片的值
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

### map
- 初始化
```
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
注意：迭代映射是没有顺序的，每次迭代查找都会随机返回键值对
