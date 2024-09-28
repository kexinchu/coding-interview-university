### 错误处理

- Go 首选错误处理方式是返回值，而不是异常。
举例
```
func main() {
  if len(os.Args) != 2 {
    os.Exit(1)
  }

  n, err := strconv.Atoi(os.Args[1])
  if err != nil {
    fmt.Println("not a valid number")   // 异常
  } else {
    fmt.Println(n)
  }
}
```

- 自定义Error
    - <font color=red>导入 errors 包然后使用它的New来创建</font>
    ```
    import (
        "errors"
    )

    func process(count int) error {
        if count < 1 {
            return errors.New("Invalid count")
        }
        ...
        return nil
    }
    ```

    - **定义包级别的变量（被定义在函数之外）**，可以被其他包访问（首字母大写）。各种函数可以返回这个错误
    ```
    // io 包中
    var EOF = errors.New("EOF")

    // main 包中
    import (
        "fmt"
        "io"
    )

    func main() {
        var input int
        _, err := fmt.Scan(&input)
        if err == io.EOF {
            fmt.Println("no more input!")
        }
    }
    ```
