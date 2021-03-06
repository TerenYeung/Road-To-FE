## 一个简单的 C++ 程序

每个 C++ 程序都包含一个或多个函数，其中一个必须命名为 main。

操作系统通过调用 main 执行 C++ 程序

- 一个函数的定义

```
int main()
{
  return 0;
}
```
一个函数的定义包括以下部分：
函数名
形参列表
函数体
返回类型

在多数系统中，main 的返回值用来指示状态;
返回值为 0 表示成功，非 0 的含义由系统定义，通常指示错误类型；

- 关于 main 函数

main 函数式操作系统执行程序的调用入口

- 头文件与源文件

头文件定义库的接口，源文件是库的接口的实现

对于包含来自标准库的头文件时，使用<>;
对于不属于标准库的头文件，使用 "";

--

## 基础语法

程序 = 算法 + 数据结构

学习一门程序语言的起步是——学习该语言支持下的数据和数据类型；

程序本质上就是进行一系列的算术运算和逻辑运算，因此有了数据及其数据类型后，就学习其有哪些运算符，以及通过数据（ 运算子 ）与运算符的结合形成``表达式``去进行数据运算；

将一系列的表达式赋予一定的逻辑就形成一条条语句；

流程控制语句（if, while, for) 等允许我们条件性或重复性的执行特定的语句

最后，通过函数进行语句的封装，形成一个独立的计算单元


### 变量和数据类型

程序是算法 + 数据结构，学习一门程序语言，起点就是学习该语言下支持的数据类型；

一个数据具备 VANT 基本属性：
value
address
name
type

C++ 语言为变量定义数据类型，实际就定义该变量的 type;
其中 value 是赋值时发生的；
address 是通过 malloc 或 new 分配的
name 就是变量名；

type 决定了该变量的
```
取值范围
存储空间
数据解释方式
操作运算
```

C++ 语言定义几种内置数据类型（整型、浮点型、字符型等），同时也提供自定义数据类型机制（类），C++ 标准库还定义一些复杂数据类型（可变长字符串和向量）

- 内置类型
首先讲讲内置类型

基本内置类型分为算数类型和空类型

算数类型可分为整型、浮点型、字符型和布尔型

[注]
计算机以比特序列存储数据
可寻址的最小内存块成为“字节”
存储的基本单元或次性处理事务的一个固定长度的位（bit）组称为字，现代计算机的字长通常为16、32、64位
C++ 语言的设计准则之一是尽可能接近硬件

数据的类型允许进行转换，类型转换可分为显式转换和隐式转换；

```
bool b = 42;
int i = b; // 转换为 1
i = 3.14 // 转换为 3
```
当赋给 unsigned 一个超出范围的值时，结果是 初始值 % 数值总数；
```
unsigned char i = -1 // -1 % 256
```
当赋值给 signed 时，结果是 undefined，此时程序可能继续工作、崩溃或 产生垃圾数据

- 变量
变量提供一个具名、可供程序操作的存储空间；
当我们 `int i = 10;`，表示：
变量 i 分配了一个 16 位的存储空间，该空间决定了值的取值范围、操作运算等

[注] C++ 语言中，初始化不是赋值，即
```
int i = 12;
i = 30;
// 二者性质不同
```
初始化时创建变量时赋予一个初始值，
赋值则是将对象当前值擦除，用新值替代；

变量的定义、声明和初始化

所谓标识符，就是标识变量的名字;

编译器在编译过程中把用到变量的地方替换成对应的值

- 复合类型

基于其他类型定义的类型，C++ 有两种复合类型：引用和指针

引用为对象（变量）起了另一个名字;
通过将 `declarator` 写成 `&d` 的形式定义引用类型

初始化变量，初始值是拷贝到新建的对象，而定义引用则是把引用和初始值绑定在一起，并且一旦定义了引用，就无法令其再绑定另外的对象
引用即别名

```
int ival = 1024;
int &refVal = ival;
int &refVal; // 报错： 引用必须被初始化
```
因为引用本身不是一个对象，所以不能定义引用的引用

引用只能绑定在对象上，而不能与字面量或表达式绑定在一块
```
int &refVal = 10; // error: 引用类型的初始值必须是一个对象
```

- 指针
指向另一种类型的复合类型

指针与引用不同点在于：
指针本身是一个对象，允许对指针赋值和拷贝

定义指针
```
int *p;
int i = 42;
int *p = &i;
cout << *p << endl;
```
空指针不指向任何对象

创建空指针的方法
```
// C++11 标准，推荐使用
int *p1 = nullptr;

int *p2 = 0;

// #include cstdlib
int *p3 = NULL;
```
[TIPS]
关于预处理器，是运行于编译过程之前的一段程序

- void*
可用于存放任意对象的地址

- const 限定符
const 对象一旦创建后其值就不能再改变
```
const int i = 12; // correct
const int k; // error: k 未初始化
```

> 想要在多个文件之间共享 const 对象，必须在变量的定义之前添加 extern 关键字
```
// file.cc
extern const int bufSize =fcn();
// file.h
extern const int bufSize;

引用与 const
```
const int i = 1024;
const int &r = i;
const int &r1 = 42; // 正确：r1 是一个常量引用
```

指针与 const
```
const double pi = 3.14;
const double *cptr = &pi;

const 指针
```
int i = 0;
const *const p = &i; // 把 * 放在 const 前说明指针是一个常量，即不变的是指针本身而非指向的值
```

顶层 const 与底层 const

用 `top-level const` 表示指针本身是个常量
用 `low-level const` 表示指针所指向的对象是一个常量
```
int i = 41;
int *const p1 = &i; // 不能改变 p1 的值，顶层 const
const int *p2 = &i; // 允许改变 p2 的值，底层 
```

constexpr 和常量表达式
```
const int i = 1;
const int limit = i + 1;
int j = 2; // 不是常量表达式
const int k = get_size(); // 不是常量表达式
```
C++11 允许将变量声明为 constexpr 类型以便有编译器验证变量值是否为常量表达式
```
constexpr int i = 10;
constexpr int *j = nullptr;
```

const、指针与引用之间的关系 ！！！

-  处理类型
类型别名是某种类型的同义词，使用类型别名的好处是让复杂的类型名字变简单和知道该类型的真实目的；

```
typedef double wages; // wages 是 double 的同义词
typedef wages base, *p; // base 是 double 同义词，p 是 doube* 同义词
```
新标准规定，使用别名声明定义类型别名

```
using SI = Sales_item; // SI 是 Sales_item 的同义词
```

---

## 关于代码风格

不存在唯一正确的风格，但必须保持一致性
