# 第九章 内存模型和名称空间

本章内容包括：

- 单独编译；
- 存储持续性、作用域和链接性；
- 定位（placement）new运算符；
- 名称空间。

## 9.1 单独编译

第1章介绍过，可以单独编译文件，然后将它们链接成可执行的程序。通常，C++编译器既编译程序，也管理链接器。如果只修改了一个文件，则可以只重新编译该文件，然后将它与其他文件的编译版本链接，这使得大程序的管理更便捷。

例如，UNIX和Linux系统都具有make程 序，可以跟踪程序依赖的文件以及这些文件的最后修改时间。运行make 时，如果它检测到上次编译后修改了源文件，make将记住重新构建程序 所需的步骤。

例如但需要将一个结构体在多个文件中复用时，与其将结构体声明加入到每一个文件 中，不如将其放在头文件中，然后在每一个源代码文件中包含该头文件。这样，要修改结构体声明时，只需在头文件中做一次改动即可。另外，也可以将函数原型放在头文件中。因此，可以将原来的程序分成三 部分。

- 头文件：包含结构体声明和使用这些结构体的函数的声明；
- 源代码文件：包含与结构体有关的函数代码；
- 源代码文件：包含调用与结构体相关的函数代码；

这是一种非常有用的组织程序的策略。例如，如果编写另一个程序 时，也需要使用这些函数，则只需包含头文件，并将函数文件添加到项 目列表或make列表中即可。另外，这种组织方式也与OOP方法一致。**一个文件（头文件）包含了用户定义类型的定义；另一个文件包含操纵用 户定义类型的函数的代码。这两个文件组成了一个软件包，可用于各种程序中**。

**不要将函数定义或变量声明放到头文件中**。这样做通常会引来麻烦，因为，如果在头文件包含了一个函数的定义，然后在（同一个程序的）另外两个文件中分别包含了该头文件，那么同一个程序中将包含同一个函数的两个定义，除非函数是内联的，否则这将出错。

头文件常包含的内容：

- 函数原型（也叫函数声明）；
- 使用`#define`或`const`定义的符号常量；
- 结构体声明；
- 类声明；
- 模板声明；
- 内联函数。

将结构体声明放在头文件中是可以的，因为它们不创建变量，而只是在源代码文件中声明结构体变量时，告诉编译器如何创建该结构体变量。同样，模板声明也不是将被编译的代码，它们指示编译器如何生成与源代码中函数调用相匹配的函数定义。被声明为`const`的常量和内联函数有特殊的链接属性（稍后将介绍），因此可以将其放在头文件中，而不会引 起问题。

在包含头文件时，我们使 用`"coordin.h"`，而不是 `<coodin.h>`。如果文件名包含在尖括号中，则 C++编译器将在存储标准头文件的主机系统的文件系统中查找；但如果文件名包含在双引号中，**则编译器将首先查找当前的工作目录或源代码目录（取决于编译器）**，如果没有找到， 则将在标准位置查找。**因此在包含自己的头文件时，应使用引号而不是 尖括号**。

![image-20210810163533843](https://static.fungenomics.com/images/2021/08/image-20210810163533843.png)

> 在同一个文件中只能将同一个头文件包含一次。记住这个规则很容易，但很可能在不知 情的情况下将头文件包含多次。例如，可能使用包含了另外一个头文件的头文件。有一种标准的C/C++技术可以避免多次包含同一个头文件。它是基于预处理器编译指令#ifndef（即if not defined）的。`#ifndef-#define-#endif` 语句的这种方法**并不能防止编译器将文件包含两次，而只是让它忽略除第一次包含之外的所有内容**。大多数标准C和C++头文件都使用这种防护 （guarding）方案。否则，可能在一个文件中定义同一个结构体、函数、类等两次，这将导致编译错误。

## 9.2 存储持续性、作用域和链接性

存储类别如何影响信息在文件间的共享？

- 自动存储持续性：在**函数定义中声明的变量**（包括函数参数）的存 储持续性为自动的。在程序开始执行其所属的函数或代码块时 被创建，在执行完函数或代码块时，它们使用的内存被释放；
- 静态存储持续性：在函数**定义外**定义的变量和使用关键字`static`定义 的变量的存储持续性都为静态。它们在程序整个运行过程中都存在；
- 线程存储持续性（C++11）：如果变量是使用关键字`thread_local`声明的，则其生命 周期与所属的线程一样长；
- 动态存储持续性：用`new`运算符分配的内存将一直存在，直到使用 `delete`运算符将其释放或程序结束为止。这种内存的存储持续性为动态，有时被称为自由存储（free store）或堆（heap）。


### 9.2.1 作用域和链接

作用域（scope）描述了名称在文件（翻译单元）的多大范围内可见。链接性（linkage）描述了名称如何在不同单元间共享。链接性为外部的 名称可在文件间共享，链接性为内部的名称只能由一个文件中的函数共 享。自动变量的名称没有链接性，因为它们不能共享。

作用域为局部的变量只在定义它的代码 块中可用。**代码块是由花括号括起的一系列语句**。例如函数体就是代码块，但可以在函数体中嵌入其他代码块。作用域为全局（也叫文件作用域）的变量在定义位置到文件结尾之间都可用。自动变量的作用域为局部，静态变量的作用域是全局还是局部取决于它是如何被定义的。在函数原型作用域（function prototype scope）中使用的名称只在包含参数列表的括号内可用（**这就是为什么这些名称是什么以及是否出现都不重要的原因**）。在类中声明的成员的作用域为整个类。在名 称空间中声明的变量的作用域为整个名称空间

### 9.2.2 自动存储持续性

在默认情况下，在函数中声明的函数参数和变量的存储持续性为自 动，作用域为局部，没有链接性。

如果在代码块中定义了变量，则该变量的存在时间和作用域将被限 制在该代码块内。例子：

![image-20210811100416035](https://static.fungenomics.com/images/2021/08/image-20210811100416035.png)

![image-20210811100534389](https://static.fungenomics.com/images/2021/08/image-20210811100534389.png)

1．自动变量的初始化
2．自动变量和栈

由于自动变量的数目随函数的开始和结束而增减，因此程序必须 在运行时对自动变量进行管理。常用的方法是留出一段内存，并将其视为栈，以管理变量的增减。之所以被称为栈，是由于新数据被象征性地放在原有数据的上面（也就是说，在相邻的内存单元中，而不是在同一 个内存单元中），当程序使用完后，将其从栈中删除。

![image-20210811110310770](https://static.fungenomics.com/images/2021/08/image-20210811110310770.png)


3．寄存器变量
这旨在提高访问变量的速度。

### 9.2.3 静态持续变量

要想创建链接性为外部的静态持续变量，必须在代码块的外面声明它；
要创建链接性为内部的静态持续变量，必须在代码块的外面声明它，并使用 `static` 限定符；
要创建没有链接性的静态持续变量，必须在代码块内声明它，并使用 `static` 限定符。

![image-20210811110632232](https://static.fungenomics.com/images/2021/08/image-20210811110632232.png)

正如前面指出的，所有静态持续变量（上述示例中的`global`、 `one_file`和 `count`）在整个程序执行期间都存在。在 `funct1()` 中声明的变量 `count` 的作用域为局部，没有链接性，这意味着只能在`funct1()` 函数中使用它，就像自动变量 `llama` 一样。然而，与`llama` 不同的是，即使在 `funct1()` 函数没有被执行时，`count` 也留在内存中。`global` 和 `one_file` 的作用域都为整个文件，即在从声明位置到文件结尾的范围内都可以被使 用。具体地说，可以在 `main()`、`funct1()` 和 `funct2()` 中使用它们。由于` one_file` 的链接性为内部，因此只能在包含上述代码的文件中使用它； 由于 `global` 的链接性为外部，因此可以在程序的其他文件中使用它。

> 应少用静态外部变量，如使用最好都声明为内部连接性的静态变量。

![image-20210811111319645](https://static.fungenomics.com/images/2021/08/image-20210811111319645.png)

### 9.2.4 静态持续性、外部链接性
链接性为外部的变量通常简称为外部变量，它们的存储持续性为静 态，作用域为整个文件。外部变量是在函数外部定义的，因此对所有函 数而言都是外部的。

1．单定义规则
C++有“单定义规则”（One Definition Rule，ODR），该规则指出， 变量只能有一次定义。请注意，单定义规则并非意味着不能有多个变量的名称相同。例 如，在不同函数中声明的同名自动变量是彼此独立的，它们都有自己的 地址。

![image-20210811111827133](https://static.fungenomics.com/images/2021/08/image-20210811111827133.png)


### 9.2.5 静态持续性、内部链接性

将static限定符用于作用域为整个文件的变量时，该变量的链接性将 为内部的。在多文件程序中，内部链接性和外部链接性之间的差别很有 意义。链接性为内部的变量只能在其所属的文件中使用；但常规外部变 量都具有外部链接性，即可以在其他文件中使用。

![image-20210811112129019](https://static.fungenomics.com/images/2021/08/image-20210811112129019.png)

> 在多文件程序中，可以在一个文件（且只能在一个文件）中定义一个外部变量。使用该变量的其他文件必须使用关键字 `extern` 声明它。

可使用外部变量在多文件程序的不同部分之间共享数据；可使用链接性为内部的静态变量在同一个文件中的多个函数之间共享数据（名称空间提供了另外一种共享数据的方法）。另外，如果将作用域为整个文 件的变量变为静态的，就不必担心其名称与其他文件中的作用域为整个 文件的变量发生冲突。

### 9.2.6 静态存储持续性、无链接性

这种变量是这样创建的，将static限定符用于在代码块中定义的变 量。在代码块中使用static时，将导致局部变量的存储持续性为静态的。 这意味着虽然该变量只在该代码块中可用，但它在该代码块不处于活动 状态时仍然存在。因此在两次函数调用之间，静态局部变量的值将保持 不变。（静态变量适用于再生——可以用它们将瑞士银行的秘密账号传 递到下一个要去的地方）。另外，如果初始化了静态局部变量，则程序 只在启动时进行一次初始化。以后再调用函数时，将不会像自动变量那样再次被初始化。

```Cpp
// static.cpp -- using a static local variable
#include <iostream>
// constants
const int ArSize = 10;

// function prototype
void strcount(const char * str);

int main()
{
    using namespace std;
    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, ArSize);
    while (cin)
    {
        cin.get(next);
        while (next != '\n')    // string didn't fit!
            cin.get(next);      // dispose of remainder
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }
    cout << "Bye\n";
// code to keep window open for MSVC++
/*
cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0;
}

void strcount(const char * str)
{
    using namespace std;
    static int total = 0;        // static local variable
    int count = 0;               // automatic local variable

    cout << "\"" << str <<"\" contains ";
    while (*str++)               // go to end of string
        count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
```

![image-20210811112939105](https://static.fungenomics.com/images/2021/08/image-20210811112939105.png)

注意，在这个程序中，由于数组长度为10，因此程序从每行读取的字符数都不超过 9个。另外还需要注意的是，每次函数被调用时，自动变量count都被重 置为0。然而，静态变量total只在程序运行时被设置为0，以后在两次函 数调用之间，其值将保持不变，因此能够记录读取的字符总数。

### 9.2.7 说明符和限定符

![image-20210811113430209](https://static.fungenomics.com/images/2021/08/image-20210811113430209.png)

3. 再谈const

在C++（但不是在C语言）中，`const`限定符对默认存储类型稍有影响。在默认情况下全局变量的链接性为外部的，**但`const`全局变量的链接性为内部的**。也就是说，在C++看来，全局 `const` 定义就像使用了 `static` 说明符一样。

C++修改了常量类型的规则，让程序员更轻松。例如，假设将一组 常量放在头文件中，并在同一个程序的多个文件中使用该头文件。那 么，预处理器将头文件的内容包含到每个源文件中后，所有的源文件都 将包含类似下面这样的定义：

```Cpp
const int fingers = 10;
const char *waring = "wak!";
```

如果全局const声明的链接性像常规变量那样是外部的，则根据单定 义规则，这将出错（幸亏不是）。

由于外部定义的`const`数据的链接性为内部的，因此可以在所有文件中使用相同的声明。


### 9.2.8 函数和链接性

和变量一样，函数也有链接性，虽然可选择的范围比变量小。和C 语言一样，C++不允许在一个函数中定义另外一个函数，因此所有函数 的存储持续性都自动为静态的，即在整个程序执行期间都一直存在。在 默认情况下，函数的链接性为外部的，即可以在文件间共享。实际上， 可以在函数原型中使用关键字extern来指出函数是在另一个文件中定义 的，不过这是可选的。**还可以使用关键字`static`将函数的链接性设置为内部的，使之只能在一个文件中使用**，但必须同时在原型和函数定义中使用该关键字。

### 9.2.9 语言链接性

在 C++中，同一个名称可能对应多个函数，必须将这些函数翻译为不同的 符号名称。因此，C++编译器执行名称矫正或名称修饰（参见第8 章），为重载函数生成不同的符号名称。例如，可能将`spiff(int)`转换 为 `_spoff_i`，而将 `spiff(double，double)` 转换为 `_spiff_d_d`。这种方法被称为C++语言链接（C++ language linkage）。

### 9.2.10 存储方案和动态分配

动态内存由运算符 `new` 和 `delete` 控制，而不是由作用域和链接性规则控制。因此，**可以在一个函数中分配动态内存，而在另一个函数中将其释放**。与自动内存不同，动态内存不是LIFO，其分配和释放顺序要取决于 `new` 和 `delete` 在何时以何种方式被使用。通常，编译器使用三块独立的内存：一块用 于静态变量（可能再细分），一块用于自动变量，另外一块用于动态存 储。

## 9.3 名称空间

名称可以是变量、函数、结构体、枚举、类以及类和结构体的成员。C++标准提供了名称空间工具，以便更好地控制名称的作用域。

### 9.3.1 传统的C++名称空间

C++关于全局变量和局部变量的规则定义了一种名称空间层次。每 个声明区域都可以声明名称，这些名称独立于在其他声明区域中声明的 名称。在一个函数中声明的局部变量不会与在另一个函数中声明的局部 变量发生冲突。

![image-20210811114957087](https://static.fungenomics.com/images/2021/08/image-20210811114957087.png)

![image-20210811115021641](https://static.fungenomics.com/images/2021/08/image-20210811115021641.png)

### 9.3.2 新的名称空间特性

C++新增了这样一种功能，即通过定义一种新的声明区域来创建命 名的名称空间，这样做的目的之一是提供一个声明名称的区域。一个名 称空间中的名称不会与另外一个名称空间的相同名称发生冲突，同时允 许程序的其他部分使用该名称空间中声明的东西。

名称空间可以是全局的，也可以位于另一个名称空间中，**但不能位于代码块中**。因此，在默认情况下，在名称空间中声明的名称的链接性 为外部的（除非它引用了常量）。

1．using声明和using编译指令

using声明由被限定的名称和它前面的关键字using组成：

```Cpp
using Jill::fetch;        // a using declaration
```
`using` 声明将特定的名称添加到它所属的声明区域中。例如 `main()` 中的 `using` 声明 `Jill::fetch` 将 `fetch` 添加到 `main()` 定义的声明区域中。完成该声明后，便可以使用名称 `fetch` 代替 `Jill::fetch`。


using声明使一个名称可用，而using编译指令使所有的名称都可 用。using编译指令由名称空间名和它前面的关键字using namespace组成，它使名称空间中的所有名称都可用，而不需要使用作用域解析运算符。在全局声明区域中使用using编译指令，将使该名称空间的名称全局可用。

2．using编译指令和using声明之比较

一般说来，使用`using`声明比使用`using`编译指令更安全，这是由于它只导入指定的名称。如果该名称与局部名称发生冲突，编译器将发出 指示。`using` 编译指令导入所有名称，包括可能并不需要的名称。如果与局部名称发生冲突，则局部名称将覆盖名称空间版本，而编译器并不会发出警告。另外，名称空间的开放性意味着名称空间的名称可能分散在多个地方，这使得难以准确知道添加了哪些名称。

3．名称空间的其他特性
可以将名称空间声明进行嵌套。

![image-20210811135518193](https://static.fungenomics.com/images/2021/08/image-20210811135518193.png)

这里，flame指的是element::fire::flame。同样，可以使用下面的 using编译指令使内部的名称可用。

4．未命名的名称空间

可以通过省略名称空间的名称来创建未命名的名称空间。

该名称空间中声明的名称的潜在作用域为：从声明点到该声明区域末尾，这与全局变量相似。然而，这种名称空间没有名称，因此不能显式地使用 `using` 编译指令或 `using` 声明来使它在其他位置都可用。也就是说，不能在未命名名称空间所属文件之外的其他文件中，使用该名称空间中的名称。这相当于是一个链接性为内部的静态变量的替代品。

### 9.3.4 名称空间及其前途

使用名称空间的原则：

- 使用在已命名的名称空间中声明的变量，而不是使用外部全局变量；
- 使用在已命名的名称空间中声明的变量，而不是使用静态全局变量；
- 如果开发了一个函数库或类库，将其放在一个名称空间中；
- 仅将编译指令using作为一种将旧代码转换为使用名称空间的权宜之计；
- 不要在头文件中使用 `using` 编译指令。首先，这样做掩盖了要让哪些名称可用；另外，包含头文件的顺序可能影响程序的行为。如果非要使用编译指令 `using`，应将其放在所有预处理器编译指令 `#include` 之后；
- 导入名称时，首选使用作用域解析运算符或using声明的方法；
- 对于using声明，首选将其作用域设置为局部而不是全局。

## 9.4 总结

C++提倡在开发程序时使用多个文件。一种有效的组织策略 是，使用头文件来定义用户类型，为操纵用户类型的函数提供函数原 型；并将函数定义放在一个独立的源代码文件中。头文件和源代码文件 一起定义和实现了用户定义的类型及其使用方式。

C++的存储方案决定了变量保留在内存中的时间（储存持续性）以 及程序的哪一部分可以访问它（作用域和链接性）。

动态内存分配和释放是使用new和delete进行的，它使用自由存储区 或堆来存储数据。调用new占用内存，而调用delete释放内存。程序使用 指针来跟踪这些内存单元。

名称空间允许定义一个可在其中声明标识符的命名区域。这样做的 目的是减少名称冲突，尤其当程序非常大，并使用多个厂商的代码时。可以通过使用作用域解析运算符、using声明或using编译指令，来使名 称空间中的标识符可用。