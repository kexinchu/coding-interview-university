# 第18章 《探讨C++新标准》 编程练习题之我解

## 18.1

**题：** 下面是一个简短程序的一部分:

![image-20220213141701341](https://static.fungenomics.com/images/2022/02/image-20220213141701341.png)

请提供函数average_list( )，让该程序变得完整。它应该是一个模板 函数，其中的类型参数指定了用作函数参数的initilize_list模板的类型以 及函数的返回类型。

## 18.2 

**题：** 下面是类Cpmv的声明:

![image-20220213141751988](https://static.fungenomics.com/images/2022/02/image-20220213141751988.png)

函数operator+ ( )应创建一个对象，其成员qcode和zcode有操作数的 相应成员拼接而成。请提供为移动构造函数和移动赋值运算符实现移动 语义的代码。编写一个使用所有这些方法的程序。为方便测试，让各个 方法都显示特定的内容，以便知道它们被调用。



## 18.3 

**题：** 编写并测试可变参数模板函数 `sum_value()`，它接受任意长度的参数列表(其中包含数值，但可以是任何类型)，并以long double的方 式返回这些数值的和。



## 18.4 

**题：** 使用 `lambda` 重新编写程序清单16.5。具体地说，使用一个有名称的 `lambda` 替换函数 `outint()`，并将函数符替换为两个匿名 `lambda` 表达式。











