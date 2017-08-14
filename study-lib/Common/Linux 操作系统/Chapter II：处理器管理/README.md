## 处理器管理

操作系统是对硬件的第一次扩充

### 处理器部件的基本结构

![处理器部件的基本结构](http://upload-images.jianshu.io/upload_images/1993435-85572493b162368e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

程序状态字 PSW 记录当前程序运行的动态信息，通常包含：

程序计数器，指令寄存器，条件码
...

PSW 也是计算机系统的寄存器，通常设置一组控制与状态寄存器

---

### 指令与处理器模式

机器指令是计算机系统执行的基本命令，是中央处理器执行的基本单位

指令有一个或多个字节组建成，包括操作码 + 操作数 + 状态字 + 特征码

- 机器指令的执行过程

CPU 根据 程序计数器取出指令，放入指令寄存器，并对指令进行译码，然后发出各种控制命令，执行微操作系列，从而完成一条指令的执行

具体步骤为：

取指：根据 PC 从存储器或高速缓存中取出指令到 IR

解码：解译 IR 中的指令来决定其执行行为

执行：连接到 CPU 部件，执行运算，产生结果并写回，同时在 CC 里设置运算结论标识；跳转指令操作 PC，其他指令递增 PC 值；

目前指令执行的方式采用指令流水线


![指令流水线](http://upload-images.jianshu.io/upload_images/1993435-07e17179145ec857.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 特权指令和非特权指令

![](http://upload-images.jianshu.io/upload_images/1993435-f13ecb8348203912.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
那么操作系统如何实现特权指令与非特权指令的一个执行界分：处理器模式

通过设置程序状态字的处理器模式位进特权指令的管理

![](http://upload-images.jianshu.io/upload_images/1993435-f0227ae13b2af94a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

既然划分了模式，必然有模式切换

一般情况下，用户模式不会向内核模式切换


![](http://upload-images.jianshu.io/upload_images/1993435-4c24f37273cb3c0e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

### 中断

中断是程序执行过程中，遇到急需处理的事件时，暂时中止 CPU 上现行程序的运行，转去执行相应的事件处理程序，待处理完成后再返回原程序被中断处或调度其他程序执行的过程

操作系统是 ”中断驱动” 的；
操作系统程序与用户程序的切换只有通过中断才可以进行切换

用户程序之间的切换也只有通过中断切换到操作系统程序，再通过操作系统程序切换到用户程序；

中断是激活操作系统的唯一方式

- 异常
异常指当前运行指令引起的中断事件，如地址异常、算术异常、处理器硬件故障等

- 系统异常
与硬件无关，是操作系统专门设置的，操作系统提供一系列的服务称为系统调用，用户程序如何请求操作系统为其服务呢？通过系统异常


![image.png](http://upload-images.jianshu.io/upload_images/1993435-28d05666e2905c65.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

### 中断源

中断事件的分类：
处理器硬件故障中断事件：

![image.png](http://upload-images.jianshu.io/upload_images/1993435-d3d64842167fe572.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

程序性中断事件：

![image.png](http://upload-images.jianshu.io/upload_images/1993435-118b9ae020769dca.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

自愿性中断事件：

![image.png](http://upload-images.jianshu.io/upload_images/1993435-a0dd361c761ae5bc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

IO 中断事件

外部设备中断事件

---


### 中断系统

中断系统是操作系统的基础，因为中断是激活操作系统的唯一方式

![image.png](http://upload-images.jianshu.io/upload_images/1993435-59053da21037c443.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

中断系统也是软硬件协同设计操作系统的典范例子

这样一个装置称为中断装置

![image.png](http://upload-images.jianshu.io/upload_images/1993435-7379fa37b6952333.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-33b2c3929933c215.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-085633363844fe2d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-3ceae6be0346570d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 中断响应

![image.png](http://upload-images.jianshu.io/upload_images/1993435-0d7c4751ea4cd14d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

记录中断点，调入操作系统的中断处理程序，交由软件完成中断处理过程


![image.png](http://upload-images.jianshu.io/upload_images/1993435-cfece81b5fac4533.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-69f97a0d105b8d22.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

在运行程序过程中，在指令执行周期的最后一个阶段——中断阶段判断是否有中断源

![image.png](http://upload-images.jianshu.io/upload_images/1993435-d66ad0c3c44a03a1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 多中断的响应与处理

中断屏蔽
![image.png](http://upload-images.jianshu.io/upload_images/1993435-640f8d13acc7c060.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

中断优先级

![image.png](http://upload-images.jianshu.io/upload_images/1993435-692147c79eb038f1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

中断的嵌套处理
![image.png](http://upload-images.jianshu.io/upload_images/1993435-449c1f79b6907907.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

### 进程及其状态

- 进程的概念

进程是一个具有一定独立功能的程序关于某个数据集合的一次``运行活动``，简单讲就是程序的运行活动

进程是操作系统进行资源分配和调度的一个独立单位

![](http://upload-images.jianshu.io/upload_images/1993435-2961d0c0dd9edc2b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![](http://upload-images.jianshu.io/upload_images/1993435-5edaae2f42986118.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-f7760ffe78cfabad.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 进程的状态


![image.png](http://upload-images.jianshu.io/upload_images/1993435-366a1f519ccef35f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

进程 3 态的转化
![](http://upload-images.jianshu.io/upload_images/1993435-5727d30822cb0557.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

进程挂起


![image.png](http://upload-images.jianshu.io/upload_images/1993435-a015d2cb18ce7b1e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



![image.png](http://upload-images.jianshu.io/upload_images/1993435-6bf299ef7443293a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

### 进程的数据描述

- 进程控制块

记录进程的状态


![image.png](http://upload-images.jianshu.io/upload_images/1993435-69edc5a62634ed29.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 标识信息

![](http://upload-images.jianshu.io/upload_images/1993435-3e4a74af2f42ed2c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 现场信息

![image.png](http://upload-images.jianshu.io/upload_images/1993435-96a07aa12ac06fbd.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 控制信息

![image.png](http://upload-images.jianshu.io/upload_images/1993435-d46f9a5447437dd3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 进程映象


![image.png](http://upload-images.jianshu.io/upload_images/1993435-fb7fae3916905b7e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![](http://upload-images.jianshu.io/upload_images/1993435-6da1fbc2d41eb46f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 进程上下文


![image.png](http://upload-images.jianshu.io/upload_images/1993435-a792869a938fc2c5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

### 进程管理


![image.png](http://upload-images.jianshu.io/upload_images/1993435-b5a96c51bc4afb6e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-001897f784d34989.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-6505dbd803fd1540.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 进程的控制与管理

![image.png](http://upload-images.jianshu.io/upload_images/1993435-3498c954727ec252.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 原语

![image.png](http://upload-images.jianshu.io/upload_images/1993435-be128f211de9630e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

### 进程切换与模式切换

- 进程切换


![image.png](http://upload-images.jianshu.io/upload_images/1993435-54a5dc949e2e9812.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-23cfdf951b1be527.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-f30ff8b2ffbcd662.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
以上工作由硬件完成，进程切换过程实际上就是中断处理程序的工作流程

---

多线程技术

- 单线程结构
![image.png](http://upload-images.jianshu.io/upload_images/1993435-3dc00a969929d145.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 单线程结构在并发程序设计上的问题

![](http://upload-images.jianshu.io/upload_images/1993435-ea765af1f2fff541.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 多线程结构进程


![image.png](http://upload-images.jianshu.io/upload_images/1993435-95b12a0416b645d7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-aa9474e92731e94b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

线程无挂起态，挂起与资源有关，线程没有独立的资源


![image.png](http://upload-images.jianshu.io/upload_images/1993435-353b9aa21e827962.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-ed985b5230400611.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### 多线程实现技术

- 内核级线程 KLT

![image.png](http://upload-images.jianshu.io/upload_images/1993435-e0cf12e1e8577371.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-373c2ab952f8b06d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 用户级线程 ULT

![image.png](http://upload-images.jianshu.io/upload_images/1993435-b143d80a9316d032.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-d37b5c98b4468893.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)




![image.png](http://upload-images.jianshu.io/upload_images/1993435-d67f86888b931a57.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-fba47d317c058b4d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-4db765bfa399c1ff.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### 多线程实现的混合策略


![image.png](http://upload-images.jianshu.io/upload_images/1993435-226f0666b61b18d5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-a297a958b64b8896.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-840156272f09187d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 多线程实现的混合策略分类

![](http://upload-images.jianshu.io/upload_images/1993435-aaf44aff865790ca.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
### 处理器调度层次
![image.png](http://upload-images.jianshu.io/upload_images/1993435-e2cef1b0abb5fd66.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-9576c79e9eac18ab.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-1f638da96b4c85fc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-c78a860eef3aa813.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-beb41f4dac24c8a0.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

进程调度程序是操作系统最核心部分

![image.png](http://upload-images.jianshu.io/upload_images/1993435-77de5b1abd718e8a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-ec61db3dce40222e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### 处理器调度算法

![image.png](http://upload-images.jianshu.io/upload_images/1993435-3a0e370d0e087fed.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-ffefb7c30c10187e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![Uploading image_485974.png . . .]

- 分级调度算法


![image.png](http://upload-images.jianshu.io/upload_images/1993435-2f814e75db8f6b1e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

