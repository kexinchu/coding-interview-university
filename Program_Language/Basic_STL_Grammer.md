# 基础STL编程语法 - C++ / Golang /Python

## List
##### C++ 
- array / 数组
  - 固定长度的sequence, 大小无法改变; 且数组的维度必须是一个常量表达式
  - 数组不支持拷贝 和 赋值 ---- 不能将数组的内容拷贝给其他数组作为初始值，也不能用数组为其他数组赋值
  - array 克服了不能copy的问题，支持完全相同类型和大小的array对象的 copy和move

```C++
#include<array>

int main(){
    std::array<int, 5> muarray = {0,1,2,3,4};

    std::int a[5] = {0,1,2,3,4};

    // initializer-list initializations:
    std::array<int,3> second = {10,20};   // initialized as:   {10,20,0}
    std::array<int,3> third = {1,2,3};    // initialized as:   {1,2,3}

    // copy initialization:
    std::array<int,3> fourth = third;     // copy:             {1,2,3}
}
```
- vector
  - 与数组类似, 拥有一段连续的内存空间, 并且其实地址不变。可以高效的进行碎金存取 O(1)
  - 由于内存空间是连续的，在进行插入和删除时，会造成内存块的copy，时间复杂度为O(n)

- list
  - 由双向链表实现，内存空间不连续，只能通过指针访问数据，可以高效的进行插入和删除
  - 随机存取没有效率 O(n)
```C++
#include <iostream>
#include <list>

int main ()
{
  int myints[] = {75,23,65,42,13};
  std::list<int> mylist (myints,myints+5);

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
```
##### Golang


## Dict


## Set


## Queue


## Stalk

