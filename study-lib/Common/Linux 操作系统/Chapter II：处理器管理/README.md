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