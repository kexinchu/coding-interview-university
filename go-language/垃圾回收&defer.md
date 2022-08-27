### 垃圾回收


### defer 关键字
- 无论什么情况，在函数返回之后，defer都将被执行.
```
package main

import (
  "fmt"
  "os"
)

func main() {
  file, err := os.Open("a_file_to_read")
  if err != nil {
    fmt.Println(err)
    return
  }
  defer file.Close()
  // 读取文件

  // ... ...
}
```
