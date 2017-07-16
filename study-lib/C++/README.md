
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



