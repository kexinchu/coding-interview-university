#### 选项设计模式

Go 语言没有构造函数，一般通过定义 New 函数来充当构造函数。然而，如果结构有较多字段，要初始化这些字段，有很多种方式，但有一种方式认为是最好的，这就是函数式选项模式(Functional Options Pattern)。

- 新增/删除变量时可以通过新增/删除函数来达到目的

举例：
```
package main

import "fmt"

// 选项设计模式
// 问题：有一个结构体，定义一个函数，给结构体初始化

// 结构体
type Options struct {
    str1 string
    str2 string
    int1 int
    int2 int
}

// 声明一个函数类型的变量，用于传参
type Option func(opts *Options)

func newOptions(opts ...Option) {
    options := &Options{}
    for _, opt := range opts {
        opt(options)
    }
    fmt.Printf("options:%#v\n", options)
}

func WithStringOption1(str string) Option {
    return func(opts *Options) {
        opts.str1 = str
    }
}

func WithStringOption2(str string) Option {
    return func(opts *Options) {
        opts.str2 = str
    }
}
func WithStringOption3(int1 int) Option {
    return func(opts *Options) {
        opts.int1 = int1
    }
}
func WithStringOption4(int1 int) Option {
    return func(opts *Options) {
        opts.int2 = int1
    }
}
func main() {
    newOptions(WithStringOption1("5lmh.com"), WithStringOption2("topgoer.com"), WithStringOption3(5), WithStringOption4(6))
}
```

- 从这里可以看到，为了实现选项的功能，我们增加了很多的代码，实现成本相对还是较高的，所以实践中需要根据自己的业务场景去权衡是否需要使用。个人总结满足下面条件可以考虑使用选项模式
    - 参数确实比较复杂，影响调用方使用
    - 参数确实有比较清晰明确的默认值
    - 为参数的后续拓展考虑


#### 使用选项模式增强组件可扩展能力
在程序开发中，经常会遇到模块间的相互依赖问题，比如 模块A（如MySQL）需要调用模块B（如Config:读取配置）才能正常工作，那么我们说模块A依赖了模块B。
若是在模块A（MySQL）中直接使用（调用）了模块B(Config)的功能，那么我们说模块A耦合了模块B，比如我们模块A要新增加一种配置类型的支持，就只能要求模块B先升级才能实现。根据控制反转原则，可以将对模块A对模块B的内部耦合，变成对B的接口的依赖，在初始化模块A的时候，将B的实现作为参数传入模块A，如下是前后的对比：

- 升级前
```
Type MySQL struct{
    c *FileConfig   // 这是struct
}


func NewMySQL()*MySQL{
   return &MySQL{
       c:&FileConfig{} //产生耦合
   }
}
```

- 升级后
```
Type MySQL struct{
    c Config   // 这是interface
}


func NewMySQL( c Config)*MySQL{
   return &MySQL{
       c:c
   }
}
```

可见，通过依赖注入的方式，MySQL组件的可扩展性更好。上面的例子只有一个依赖项，我们很容易就写出了代码，那如果依赖项有很多呢，可以借助选项模式？

```
// Option 定义的选项类型 
type Option interface{
   apply(do * mysqlOptions)
}

// 也可以不定义成interface,而定义为一个func
//  比如 type Option func(do * mysqlOptions)

type mysqlOptions struct{
   readTimeout int
   writeTimeout int
}

func NewMySQL(opts …Option)MySQL{
  // 默认值
  opt:=& mysqlOptions{
       readTimeout:100,
       writeTimeout:50,
  }
  
  // 传入的选项将默认值替换掉
  for _,o:=range opts{
     o. apply(opt)
  }
  
  // go on
}

// 下面是Option的定义
// 先定义一个模板，方便后续声明新的option
type funcsOptionTPL struct {
   f func(*mysqlOptions)
}

func (fdo *funcsOptionTPL) apply(do *mysqlOptions) {
   fdo.f(do)
}

func newFuncOption(f func(*mysqlOptions)) *funcsOptionTPL {
   return &funcsOptionTPL{
      f: f,
   }
}

// 定义一个设置ReadTimeout的Option
func OptReadTimeout(t int) Option{
   return newFuncOption(func(opts *mysqlOptions) {
      opts.readTimeout=t
   })
}
 
// 定义一个设置WriteTimeout的Option
func OptWriteTimeout(t int) Option{
   return newFuncOption(func(opts *mysqlOptions) {
      opts.writeTimeout=t
   })
}
```

- 使用 初始化组件
```
// 方式1：使用缺省参数初始化
client：=NewMySQL()


方式2：传入option初始化
Client:=NewMySQL(OptReadTimeout(50),OptWriteTimeout(200))
```