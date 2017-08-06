
### 数据类型

- 布尔类型

```
 bool modified;
 modified = true;
```

- 枚举类型

```
 enum 枚举名 {元素名1, 元素名2, ..., 元素名n}

 enum MONTH {JAN = 1, FEB, MAR, ...,}

 MONTH month;
```

- 复合数据类型
字符、数组和结构体

  - 字符
  ```
    char ch;
    const char cch = 'C';
  ```
  字符文字使用单引号对

  > 正常情况下，字符存储使用8位的ASCII码对一个字符进行存储
  使用UNICODE字符集，使用2个字节16位对一个字符进行存储
  ```
  # 字符表示的等价性

  char a = 'A';
  char a = 65;
  char a = 0101;
  char a = 0x41;
  ```

![image.png](http://upload-images.jianshu.io/upload_images/1993435-e05f78b9352db7a3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  - 数组
  数组的定义
  将具有相同性质的数据元素构成一个整体，构成单一维度上的数据序列
  ```
  元素类型 数组名称[常数表达式]
  常数表达式必须为常数或常量，在C下则必须是常数
  int a[8];
  ```
![image.png](http://upload-images.jianshu.io/upload_images/1993435-e67971d735130538.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-02c8535714a6b442.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-049d288a56b9922b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  - 结构体
  ```
    struct 结构体名称 {
      成员类型1 成名名称1
    }
  ```

  数组 vs 结构体
  数据不能整体赋值，因此不能作为函数的返回值
  而结构体是可以以整体赋值，因此可以作为函数返回值

---

### 指针

每一个变量或是数据对象有四个基本特征：VANT
```
V => value
A => address
N => name
T => type
```
一般程序编译完成后，name和type都会缺失

- 数据对象的地址和值
地址就是数据对象的存储位置，一般以在计算机的存储设备的编号表示

值就是该位置所存储的内容

- 指针的定义

```
 int *p; // *用于表示该变量为指针变量，是指向整数的指针；
 struct POINT {
   int x, y;
 }
 POINT *p;
```

```
int *p;指针修饰符
p 指针变量，用于获取指针指向的地址
*p 引领操作符，用于获取指针变量p上的值
&n 取值操作符，用于获取变量n的地址
```

- 指针变量的存储布局

```
  // 指向原始数据类型
  int n = 10; int *p = &n;
  // 指向数据
  int a[2] = {1, 2};
  int *p = a; // 指向数组的基地址（首元素地址），相当于 &a || &a[0]

```
![image.png](http://upload-images.jianshu.io/upload_images/1993435-fa6d160737b17243.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 指针的意义
![image.png](http://upload-images.jianshu.io/upload_images/1993435-66ae784d61af53c5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 常量指针与指针常量

常量指针：指向常量的指针，不能通过引领操作符修改指针所指向的目标数据对象的值
```
  int n = 10;
  const int *p = &n;
```
指针常量：指针指向的位置不可变化，但可以改变指针所指向的目标数据对象的值
```
  int n = 10;
  int * const p = &n;
```
常量指针常量
```
const int * const p = &n;
```
![image.png](http://upload-images.jianshu.io/upload_images/1993435-625662f1e2e3f90e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 指针和复合数据类型
  - 指针与数组
  ```

  ```
  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-114fffe7141d498a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-a4dd3c2666f2d446.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-7e32d5c2500dde50.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-b2a0787fed69f804.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  [注]多维数组作为函数参数
  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-fd871ca61b96305c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
  建议按照第1种方案

  ```
    void PrintTwoDemensinalArray(int *a, unsigned int m, unsigned int n) {
      unsigned int i, j;
      for(i=0; i<m; i++)
        for(j=0; j<n; j++)
          cout << *(a+n*i+j) << ";";
    }
    
    int a[2][3] = { {1, 2, 3}, {4, 5, 6}};
    PrintTwoDimensinalArray(a, 2, 3);
  ```

- 指针与结构体
```
  struct STUDENT { int id; STRING name; int age;};
  STUDENT student= { 1, "teren", 18};
  STUDENT *pstudent = &student;

  (*pstudent).age = 20;
  pstudent->id = 2

  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-610168a824fdf9af.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
```


![image.png](http://upload-images.jianshu.io/upload_images/1993435-324ab4b6a39603b6.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-5556e395d4bca264.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

- 字符串
字符串的表示
  - 作为字符数组
  - 作为指向字符的指针
  - 作为抽象的字符串整体
  
字符数组
```
  char s[5] = {'h', 'e', 'l', 'l', 'o'};
```
![image.png](http://upload-images.jianshu.io/upload_images/1993435-2a38abd2f91a390a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

如何区分存储空间刚好存储连续的多个字符数组？
在字符数组末尾添加结束标志'\0'

![image.png](http://upload-images.jianshu.io/upload_images/1993435-56cda649c00396ca.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-e102842c360a0ada.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-38865755eea2efbe.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



![image.png](http://upload-images.jianshu.io/upload_images/1993435-33361802ce2616e4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-777cfb0f1d7c62b4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
```
  为什么数组不能直接赋值？
  char s[9];
  s = "CPP-Prog";
上面语句表示，为字符数组分配9个字节的存储空间用于存储9个元素，s = "CPP-Prog"这句表示将 "CPP-Prog"该字符串的基地址赋值给字符串数组的9个元素，故是错误；

C++中，数组不能直接赋值，本质上就是为数组赋值时，本来要为其赋多个值，结果只整体赋了一个值
```

![image.png](http://upload-images.jianshu.io/upload_images/1993435-7f6836863de8e2d3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-fe4aab5f09e1ebc1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



![image.png](http://upload-images.jianshu.io/upload_images/1993435-9778844afc4022eb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-a492fdfdbb4890a0.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-d68551509b667ec4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-5ab055e7eef5aad7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


---

### 表达式

- 递增递减表达式
  - 前缀递增递减
    先递增递减，后计算
    ```
      a = 1
      b = ++a * 3 => a = a + 1, b = a * 3
      a = 2, b = 6
    ```
  - 后缀递增递减
    先计算，后递增递减
    ```
      a = 1
      b = a++ * 3 => b = a * 3, a = a + 1;
      a = 2, b = 3
    ```
- 关系表达式

- 逻辑表达式

```
 && || !
```
![image.png](http://upload-images.jianshu.io/upload_images/1993435-4669575f90f43f32.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### 流程控制语句

- 顺序结构
  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-aa6c9d17f2c6a809.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 分支结构
![image.png](http://upload-images.jianshu.io/upload_images/1993435-9f6fac78bac3ebec.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](http://upload-images.jianshu.io/upload_images/1993435-795cfe9c927713d4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
  - if分支结构
  ```
    if () {}
    if () {} else {}
    if () {} else if {} else if {} else {}
  ```
  - swtich分支结构
  ```
    switch() {
      case x:
    }
  ```
- 循环结构
![image.png](http://upload-images.jianshu.io/upload_images/1993435-67de9bad12b44ace.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
  - while循环
  ```
    while () {}
  ```
  - for循环
![image.png](http://upload-images.jianshu.io/upload_images/1993435-7270495fb79a2fe9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### 函数
- 函数的声明与调用
![image.png](http://upload-images.jianshu.io/upload_images/1993435-49e6da7e97c769a5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-7f38a6a029567ecd.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 函数定义
![image.png](http://upload-images.jianshu.io/upload_images/1993435-09cba27ac45f4eaf.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  函数重载
![image.png](http://upload-images.jianshu.io/upload_images/1993435-816493616e2af32d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 函数调用规范
  - 参数传递机制： 值传递和引用传递

    值传递机制：
      形参在函数调用时才分配存储空间，并接受实参的值
      实参在函数调用前获得计算
      实参与形参必须保持数目、类型和顺序的一致性
      实参向形参传递是单向的，函数内部对形参修改不会反映到实参中去

  - 函数调用栈框架

* 阅读源码时，先从main函数开始，自顶向下，逐步求精

### 算法
- 基本概念
  解决问题的方法和步骤
  给出解决问题的逻辑描述，以及根据算法描述进行实际编程

- 算法特征
  - 有穷性：步骤有限
  - 确定性：算法步骤的顺序和内容没有二义性
  - 输入：算法有0个或多个输入
  - 输出：算法至少具有一个输出
  - 有效性：所有操作具有明确含义，并能在有限时间内完成
  * 算法的正确性需要数学证明

- 算法描述
  - 自然语言
  - 流程图
  - 伪代码
![image.png](http://upload-images.jianshu.io/upload_images/1993435-4f372de4d2af532f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 算法设计与实现
![image.png](http://upload-images.jianshu.io/upload_images/1993435-6f0a94318ca1c330.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-458ed550efa3b52d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-eaa784df90854fee.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 递归算法
![image.png](http://upload-images.jianshu.io/upload_images/1993435-55718318c7a49b0f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-ebda503e609083d1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-02b37794a6ed9f3c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 容错
![image.png](http://upload-images.jianshu.io/upload_images/1993435-b477f0c80515a6dd.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-b6f7f370db379d47.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-206e15a7615e2b49.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 算法复杂度
正常情况下，算法的执行时间是问题规模的函数，算法的复杂度（时间复杂度）；
算法使用到多少的饿内存空间，叫算法的空间复杂度；
现在，随着内存空间的增加，我们更加关注时间复杂度；
![](http://upload-images.jianshu.io/upload_images/1993435-bb4e1df47c601f83.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

```
如： 3n*n + 100n
去除对变化趋势影响较小的项100n
忽略与问题规模无关的常数，如3，则这个问题的复杂度为：
O(n*n)
```
![image.png](http://upload-images.jianshu.io/upload_images/1993435-4a11f5a10a265273.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 算法复杂度的估计
可以看循环的嵌套层级

![image.png](http://upload-images.jianshu.io/upload_images/1993435-cbc8015c5f1a6956.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### 程序组织与软件开发方法
  - 库与程序文件
  程序文件包括：
    源文件 *.cpp
    头文件 *.h / *.hpp / *
  
  库：
    源文件 + 头文件

![image.png](http://upload-images.jianshu.io/upload_images/1993435-da242ae6c086b8d7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-2457c88ac646378d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



![image.png](http://upload-images.jianshu.io/upload_images/1993435-93225ff1c5e05263.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-4a174770892711a1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 随机数库的设计

- 作用域和生存期
作用域是量的空间范围
  局部作用域
  全局作用域
  ```
    int a = 1; // 全局作用域
    int main()
    {
      int b = 2; // 局部作用域
      cout << "a: " << a << endl;
      cout << "b: " << b << endl;
    }
  ```
生存期
  静态（全局）生存期: 生死仅与程序是否执行有关

  自动（局部）生存期：生死仅与程序流程是否位于该块有关

static关键字
  修饰全局变量：使其作用域仅限定于本文件内部，其他文件不可见
  修饰局部变量：使局部变量具有静态生存期，程序退出该块时局部变量仍存在；

## 软件开发流程
需求分析：
  确定软件需要解决什么问题

方案设计：
  概要设计：设计总体方案，形成高层模块划分
  详细设计：细化模块，获得各模块的输入、输出与算法
编码实现：
  实际编程
系统测试：
  测试程序的正确性和稳定性
经验总结

![image.png](http://upload-images.jianshu.io/upload_images/1993435-feb142ec04eaadcb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-483d4a77e0abaea1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

## 程序抽象

- 数据封装

将数据结构的细节隐藏起来

- 信息隐藏

![image.png](http://upload-images.jianshu.io/upload_images/1993435-0793bff82c848e70.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

数据封装和信息隐藏合在一起实现程序抽象

---

## 链表

- 链表的含义
  每个元素与前后元素相链接的元素序列
- 链表的意义
  存储顺序访问的数据对象集
  数据对象占用的存储空间是动态分配的

- 节点
  每个元素就是一个节点，每个节点包括数据域和链接域
  头指针和尾指针是指向表头和表尾的两个指针

![image.png](http://upload-images.jianshu.io/upload_images/1993435-9a8abcfb2041762e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-714968707a41bdc5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



![image.png](http://upload-images.jianshu.io/upload_images/1993435-37ef36ec56b90420.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-6c79f5a8eda65ee3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-68d19ee0417dbbda.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-9b0650f3d1846bfc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-fceb8aa8980cdce4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-53b535f838f21d6e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


- 函数指针
指向函数的指针

```
  void * 用于表示抽象的数据对象，即可以指向任意数据类型的数据对象的地址，表明目标数据对象是未知的
```

```
 char *(* as_string)(ADT object)
 变量 as_string 指向一个函数，该函数接收 ADT 类型的参数， 返回值是 char *;
```

- 函数指针的使用

```
 char *returned_value;
 PPOINT pt = PtCreate(10, 20);
 as_string = DoTransformObjectIntoString;
 returned_value = as_string((ADT)pt);
 // 标准格式如下：
 return_value = (*as_string)((ADT)pt);
```


![image.png](http://upload-images.jianshu.io/upload_images/1993435-7c171277e060fa6f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-817257e756c5a136.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-08e1e4a0fe229cf9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-2a1deaca622295cc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 抽象链表

