# 第十四章 C++中的代码重用

本章内容包括：

- has-a 关系；
- 包含对象成员的类；
- 模板类valarray
- 私有和保护继承；
- 多重继承；
- 虚基类；
- 创建类模板；
- 使用类模板；
- 模板的具体化。

## 14.1 包含对象成员的类
### 14.1.1 valarray类简介

valarray类是由头文件 `valarray` 支持的。**这个类用于处理数值，它支持诸如将数组中所有元素的值相加以及在数组中找出最大和最小的值等操作**。valarray被定义为一个模板类，以便能够处理不同的数据类型。例子：

![image-20210815170242081](https://static.fungenomics.com/images/2021/08/image-20210815170242081.png)

从中可知，可以创建长度为零的空数组、指定长度的空数组、所有元素度被初始化为指定值的数组、用常规数组中的值进行初始化的数组。

这个类有一些内置方法：

- operator：访问各个元素；
- `size()`: 返回包含的元素数；
- `sum()`: 返回所有元素的总和；
- `max()`: 返回最大的元素；
- `min()`: 返回最小的元素。

等等，https://cplusplus.com/reference/valarray/valarray/ 。


### 14.1.2 Student类的设计

![image-20210815170944251](https://static.fungenomics.com/images/2021/08/image-20210815170944251.png)

![image-20210815172143416](https://static.fungenomics.com/images/2021/08/image-20210815172143416.png)

## 14.2 私有继承

C++还有另一种实现has-a关系的途径——私有继承。使用私有继 承，基类的公有成员和保护成员都将成为派生类的私有成员。这意味着 基类方法将不会成为派生对象公有接口的一部分，但可以在派生类的成 员函数中使用它们。

要进行私有继承，请使用关键字 `private` 而不是 `public` 来定义类（实 际上，`private`是默认值，因此省略访问限定符也将导致私有继承）。

使用私有继承时，只能在派生类的方法中使用基类的方法。

用类名显式地限定函数名不适合于友元函数，这是因为友元不属于 类。然而，可以通过显式地转换为基类来调用正确的函数。

如果两个基类都提供了函数operator<<( )，由于这个类使用的是多重继承，编译器将无法确定 应转换成哪个基类。

### 14.2.2 使用包含还是私有继承

大多数C++程序员倾向于使用包含。首先，它易于理 解。类声明中包含表示被包含类的显式命名对象，代码可以通过名称引 用这些对象，而使用继承将使关系更抽象。其次，继承会引起很多问 题，尤其从多个基类继承时，可能必须处理很多问题，如包含同名方法 的独立的基类或共享祖先的独立基类。总之，使用包含不太可能遇到这 样的麻烦。另外，包含能够包括多个同类的子对象。如果某个类需要3 个string对象，可以使用包含声明3个独立的string成员。而继承则只能使 用一个这样的对象（当对象都没有名称时，将难以区分）。

然而，私有继承所提供的特性确实比包含多。例如，假设类包含保 护成员（可以是数据成员，也可以是成员函数），则这样的成员在派生 类中是可用的，但在继承层次结构外是不可用的。如果使用组合将这样 的类包含在另一个类中，则后者将不是派生类，而是位于继承层次结构 之外，因此不能访问保护成员。但通过继承得到的将是派生类，因此它 能够访问保护成员。

另一种需要使用私有继承的情况是需要重新定义虚函数。派生类可 以重新定义虚函数，但包含类不能。使用私有继承，重新定义的函数将 只能在类中使用，而不是公有的。 

### 14.2.3 保护继承

保护继承是私有继承的变体。保护继承在列出基类时使用关键字 `protected`。使用保护继承时，基类的公有成员和保护成员都将成为派生类的保护成员。

![image-20210815194347832](https://static.fungenomics.com/images/2021/08/image-20210815194347832.png)

### 14.2.4 使用using重新定义访问权限
使用保护派生或私有派生时，基类的公有成员将成为保护成员或私 有成员。假设要让基类的方法在派生类外面可用，方法之一是定义一个使用该基类方法的派生类方法。

另一种方法是，将函数调用包装在另一个函数调用中，即使用一个 using声明（就像名称空间那样）来指出派生类可以使用特定的基类成 员，即使采用的是私有派生。



## 14.3 多重继承
【短期内不会用到，多重继承、模板类和虚基类等没细看。】
![image-20210815202024284](https://static.fungenomics.com/images/2021/08/image-20210815202024284.png)

![image-20210815202112888](https://static.fungenomics.com/images/2021/08/image-20210815202112888.png)

## 14.5 总结

C++提供了几种重用代码的手段。无论使用哪种继 承，基类的公有接口都将成为派生类的内部接口。这有时候被称为继承 实现，但并不继承接口，因为派生类对象不能显式地使用基类的接口。 因此，不能将派生对象看作是一种基类对象。

还可以通过开发包含对象成员的类来重用类代码。这种方法被称为 包含、层次化或组合，它建立的也是has-a关系。另一方面，如果需要使用某个类的几个对象，则用包含更适合。

多重继承（MI）使得能够在类设计中重用多个类的代码。