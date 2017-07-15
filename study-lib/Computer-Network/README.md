<!--1. 
  architecture principle
  switching、routing 交换、路由
  naming/addressing/forwarding 命名、寻址和转发

2.
  congestion control 拥挤
  streaming 控制流
  rate limiting
  content distribution

3.
  software defined networking
  traffic engineering 网络流量
  network security 网络安全

---

Architecture and Principles-->

计算机网络 = 通信技术 + 计算机技术

通信系统模型
  信源 -> 发送设备 -> 信道 -> 接收设备 -> 信宿
（计算机）     ^                 （计算机）
          噪声源

计算机网络的定义：
  互连（通过信道，即通信链路，具体到光纤、同轴电缆和双绞线或是无线信号进行互连互通）、自治（无主从关系）的计算机集合

![](https://ooo.0o0.ooo/2017/06/28/5953c69ea29ac.png)

距离远、数量大如何保证互连？
通过交换网络互连主机
![](https://ooo.0o0.ooo/2017/06/28/5953c72a94079.png)
主机通过交换网络中的交换节点（路由器或交换机）实现数据的通信

---

什么是Internet?
全球最大的互连网络：ISP(Internet Service Provider)网络互连的”网络之网络“
![](https://ooo.0o0.ooo/2017/06/28/5953c91fbc962.png)
![](https://ooo.0o0.ooo/2017/06/28/5953ca0f0a2cd.png)

---

什么是网络协议？
硬件（主机、通信链路、交换设备）是计算机网路的基础
计算机网络的数据交换必须遵守约定的规则，如同交通系统

网络通信就是通信主体（主机）之间在特定的规则（协议）下进行交流（数据通信）
![](https://ooo.0o0.ooo/2017/06/28/5953cc902ca3f.png)

网络协议就是进行网络中的数据交换而建立的规则、标准或约定；

协议具体来说，规定了通信实体之间所交换信息的格式、意义、顺序以及针对收到的信息或发生的事件所采取的动作；

网络协议3要素：

- 语法
  数据与控制信息的结构或格式
- 语义
语义是解释控制信息每个部分的意义。它规定了需要发出何种控制信息，以及完成的动作与做出什么样的响应
- 时序
  协议双方在通信过程中的时间顺序

---
计算机网络结构
![](https://ooo.0o0.ooo/2017/06/28/5953d2025542b.png)

网络边缘
![](https://ooo.0o0.ooo/2017/06/29/5953d4cf8f56f.png)

接入网络
将边缘网络接入核心网（边缘路由器）
// 这块不是很明白

网络核心：由路由器互连构成的网络
网络核心的关键功能：路由 + 转发
网络核心收到一个数据包（数据分组），数据分组里有地址信息，
路由器根据地址将数据包正确的送到该路由器的某个接口（该接口对应下一个路由器）
这个过程就涉及路由器的两个功能：
路由器如何知道将这个数据包从哪个接口发出去呢？路由器根据本地转发表进行转发数据包。

本地转发表如何产生的呢？路由器要运行相关的路由协议，路由协议遵循某种路由算法从而计算获得路由表（本地转发表）
以上就是路由的功能：根据数据包的地址信息和路由协议，计算出数据包对应的本地转发表；

路由器收到数据分组并根据路由算法获得本地转发表，然后将数据包转发到对应的接口（输出链路）,这一过程就是转发功能
![](https://ooo.0o0.ooo/2017/06/29/5953dcaee043b.png)

---

Internet网络是网络之网络，由各个网络互连构成的网络

端系统通过 接入ISPs 连接到Internet，接入ISP也要进行互连，这样就构成复杂的网络互连的网络

### 如何实现接入ISPs的连接？
![](https://ooo.0o0.ooo/2017/07/01/5957566fe8dc3.png)
![](https://ooo.0o0.ooo/2017/07/01/595756a52f56d.png)
![](https://ooo.0o0.ooo/2017/07/01/595757277cf03.png)

---

## 数据交换

端系统通过通信链路实现数据通信，如果每个端节点直接互连，那么所需的链路为：
引入交换设备，交换机，每个端系统只需要一条链路，通过交换机实现数据转发。

通过将交换设备互连在一起，构成一个``交换网络``
![](https://ooo.0o0.ooo/2017/07/01/595759808d07e.png)

![](https://ooo.0o0.ooo/2017/07/01/59575a6ad38d4.png)

![](https://ooo.0o0.ooo/2017/07/01/59575b16b81a5.png)

由于电路交换网络在通信过程中，通信双方将独享电路资源，那么如何共享中续线呢？
![](https://ooo.0o0.ooo/2017/07/01/59575d3143bfa.png)

### 多路复用技术

![](https://ooo.0o0.ooo/2017/07/01/59575dbaa83f9.png)

### 报文交换和分组交换

- 报文交换

报文：源（应用）发送信息的整体，如一个文件
![](https://ooo.0o0.ooo/2017/07/01/59575f094300f.png)

- 分组交换

分组：报文分拆出来一系列相对较小的数据包，每个数据包相当于一个分组，
在拆分成一个个数据包的原始数据之前再加上一些头部信息(控制信息)；

以上过程中，分组交换就需要报文的拆分与重组

原始数据包拆分
![](https://ooo.0o0.ooo/2017/07/01/595760c1510f7.png)

一个一个分组单独传输
![](https://ooo.0o0.ooo/2017/07/01/595760f29b264.png)
![](https://ooo.0o0.ooo/2017/07/01/5957611d6570b.png)
![](https://ooo.0o0.ooo/2017/07/01/59576143868d3.png)
![](https://ooo.0o0.ooo/2017/07/01/59576155b4fa6.png)
![](https://ooo.0o0.ooo/2017/07/01/595763816ce4d.png)

### 存储-转发
![](https://ooo.0o0.ooo/2017/07/01/59576513d63c1.png)

---

报文交换与分组交换对比

- 传输延迟
传输延迟计算公式 = 发送的数据量 / 传输速率
![](https://ooo.0o0.ooo/2017/07/01/59576a98adebd.png)

![](https://ooo.0o0.ooo/2017/07/01/59576bb6ce583.png)

![](https://ooo.0o0.ooo/2017/07/01/59576d23b9be5.png)

![](https://ooo.0o0.ooo/2017/07/01/59576f4ed9486.png)

![](https://ooo.0o0.ooo/2017/07/01/59576f6535479.png)

![](https://ooo.0o0.ooo/2017/07/01/59576f9691177.png)

![](https://ooo.0o0.ooo/2017/07/01/595770b39f89c.png)

---

### 分组交换 vs 电路交换

![](https://ooo.0o0.ooo/2017/07/01/5957749df2513.png)

---

## 网络性能

- 数据传输速率
单位时间传输的比特量 bps kb/s Mb/s
k = 10^3 M = 10^6 G = 10^9

- 带宽
原指信号具有的频带宽度，即最高频率和最低频率之差，单位Hz

计算机中指：数字信道所能传输的最高数据率，单位是bps

- 时延

传输延迟：发送数据过程中从第一个bit发送到最后一个bit结束所需的时间

在分组交换的通信交换方式中，除了传输延迟还有其他的延迟。

分组交换为什么发生丢包和时延？
![](https://ooo.0o0.ooo/2017/07/01/59578b3d5927b.png)

- 分组延迟的类型

![](https://ooo.0o0.ooo/2017/07/01/59578bca7f074.png)

![](https://ooo.0o0.ooo/2017/07/01/59578cabdbd69.png)

- 时延带宽积
以比特为单位的链路长度
![](https://ooo.0o0.ooo/2017/07/01/595792d560be8.png)

- 丢包率
![](https://ooo.0o0.ooo/2017/07/01/5957940e4a5ef.png)

- 吞吐量

![](https://ooo.0o0.ooo/2017/07/01/595794dd81148.png)

![](https://ooo.0o0.ooo/2017/07/01/59579524a50c5.png)

---

### 计算机网络体系结构

![](https://ooo.0o0.ooo/2017/07/01/59579625669f7.png)

分层结构的思想：
每层提供特定的服务，底层为上层提供服务，上层依赖于底层提供近更进一步的服务。

网络体系结构是从``功能``上描述计算机网络结构，
每层遵循特定网络协议实现本层的功能，
因此，计算机网络体系结构就是计算机网络的各层及其协议的集合。

- 基本概念

  - 实体
    任何可发送或接收信息的硬件或软件进程

  - 协议
    控制两个对等实体进行通信的规则的集合，协议是水平的

  - 分层中的上下层关系
    任一层使用下层服务，遵循本层协议，实现本层功能，向上提供服务，服务是垂直的，下层协议的实现对上层的服务用户是透明的
  - 相邻层的实体之间通过接口进行交互，通过服务访问点SAP(Service Access Point)，交换原语，指定请求的特定服务

- OSI参考模型
理论成功，失败
![](https://ooo.0o0.ooo/2017/07/01/5957a4f984b13.png)

基于OSI参考模型解释通信过程

![](https://ooo.0o0.ooo/2017/07/01/5957a7088a743.png)

两个主机之间的数据通信过程为：
主机A发送用户数据，数据首先交给应用层；
应用层根据网络应用的不同、应用层协议的不同，给用户数据加上一些控制信息（应用层头）

![](https://ooo.0o0.ooo/2017/07/01/5957a8d0b3893.png)

传输层功能：
![](https://ooo.0o0.ooo/2017/07/01/5957ad887a075.png)

  - 报文的分段与重组
  - SAP寻址，保证报文提交给正确的进程（如端口号）
![](https://ooo.0o0.ooo/2017/07/01/5957af6b6d1ad.png)

会话层功能：
![](https://ooo.0o0.ooo/2017/07/01/5957afe5eab7f.png)

表示层功能：
![](https://ooo.0o0.ooo/2017/07/01/5957b051c712f.png)

应用层功能：
![](https://ooo.0o0.ooo/2017/07/01/5957b0e83bca3.png)

- TCP/IP 参考模型
先实践，后总结出来的模型

![](https://ooo.0o0.ooo/2017/07/01/5957b15ed2968.png)

![](https://ooo.0o0.ooo/2017/07/01/5957b21c9830f.png)

![](https://ooo.0o0.ooo/2017/07/01/5957b3efdec64.png)

message segments datagram frame bitsflow

---

## 应用层

应用层位于TCP/IP网络体系结构的最上层；

![](https://ooo.0o0.ooo/2017/07/02/5958fae53943c.png)

- 网络应用的体系结构
  - Client-Server C/S
  - Peer-to-Peer, P2P
  - Hybrid 混合结构

![](https://ooo.0o0.ooo/2017/07/02/5958fe26068d2.png)

![](https://ooo.0o0.ooo/2017/07/02/5958feb3102a6.png)

![](https://ooo.0o0.ooo/2017/07/02/5959004f5c25c.png)

![](https://ooo.0o0.ooo/2017/07/02/5959019e0c63e.png)

- 网络应用进程通信

一个典型的C/S网络应用体系结构由客户端和服务端构成，二者之间的进程需要进行通信。

  - 进程
    主机上运行的程序

  - 同一台主机上运行的进程之间如何进行通信？
    进程间通信机制
    操作系统提供

  - 不同主机上运行的进程之间如何通信？
    消息交换

    利用socket技术
![](https://ooo.0o0.ooo/2017/07/02/595905d4b47d8.png)

  - 如何寻址进程？
    不同主机上的进程间的通信，每个进程必须拥有标识符

      - 如何寻址主机？
        通过IP地址
        主机有了IP地址，是否足以定位进程？
        不能，因为同一主机可能同时运行多个网络进程
      
      - 如何标识网络进程？
        为主机上的每个需要通信的进程分配一个端口号
        HTTP Server: 80
        Mail Server: 25

      因此，是IP地址+端口号类唯一表示网络进程
![](https://ooo.0o0.ooo/2017/07/02/595907dc4ca97.png)

- 消息交换采用什么样的格式和顺序呢？
  通过``应用层协议``规定

![](https://ooo.0o0.ooo/2017/07/02/59590d5e3cf00.png)

  - 应用层协议的内容
    - 消息的类型
      请求消息
      响应消息
    - 消息的语法/格式
      消息有哪些字段
      字段如何描述
    - 字段的语义
      字段中信息的含义
    - 规则
      进程何时(如何)发送/响应消息

---

- 网络应用对传输服务的需求

![](https://ooo.0o0.ooo/2017/07/02/595910ca680ae.png)

![](https://ooo.0o0.ooo/2017/07/02/5959135a40c99.png)

既然UDP提供这么基础的服务，那么为什么还需要它呢？
UDP是为连接网络层和应用层的提供最基本的协议，因此可以给予应用层很大的发挥空间实现传输层的增强功能

---

### web应用

应用层包括许多应用，web应用和电子邮件应用

web应用的表现形式是web page，即网页

网页有一个个对象构成，html文件、脚本文件、图片、音视频等

web应用在消息通信过程中遵循http协议，在传输层使用TCP协议进行传输

![](https://ooo.0o0.ooo/2017/07/03/59591a307026f.png)

![](https://ooo.0o0.ooo/2017/07/03/59591b9144978.png)

![](https://ooo.0o0.ooo/2017/07/03/59591c5c92225.png)

HTTP协议是无状态协议，即服务器不维护任何客户端过去所发的请求信息

#### HTTP连接
- HTTP连接的两种类型
  
  - 非持久连接
    每个TCP连接最多允许传输一个对象,即`一个HTTP连接只用来获取一个对象`，再次获取另一个对象就需要再次建立HTTP连接
  - 持久连接
    每个TCP连接允许传输多个对象

HTTP在数据传输方向上是全双工的
  - 单工：数据只能一个方向上传输
  - 半双工：数据可以双向传输，但是在特定时刻只能单向传输
  - 全双工：数据可以在两个方向上同时传输

![](https://ooo.0o0.ooo/2017/07/03/595a4a23bbae1.png)

![](https://ooo.0o0.ooo/2017/07/03/595a4ab9c987a.png)

![](https://ooo.0o0.ooo/2017/07/03/595a4bc0ad6a8.png)

![](https://ooo.0o0.ooo/2017/07/03/595a4ff49704a.png)

- HTTP消息格式(语法)
  - 请求消息

  既然已经建立了TCP连接，那么请求头的host字段还有必要添加上去吗？
  跟后面的缓存和代理服务器会使用到这个信息。
![](https://ooo.0o0.ooo/2017/07/03/595a5210193ec.png)

  - 响应消息

  ![](https://ooo.0o0.ooo/2017/07/03/595a559121dea.png)

- Cookie技术
由于HTTP协议是无状态协议，不保存历史请求的状态信息。

为什么需要Cookie?
进行session跟踪和状态存储

  - Cookie组件
    http请求/响应行的cookie字段
    客户端主机上的cookie文件，由浏览器管理
    web服务器端的后台数据库
    
  - Cookie作用
  ![](https://ooo.0o0.ooo/2017/07/03/595a5b675b5c1.png)

### Web缓存与代理服务器技术

![](https://ooo.0o0.ooo/2017/07/03/595a5cd499aa4.png)

![](https://ooo.0o0.ooo/2017/07/03/595a5de8e94cc.png)

如何保证缓存服务器的资源与远程服务器保持同步？

  通过条件请求方法去实现数据同步！
  ![](https://ooo.0o0.ooo/2017/07/03/595a60e16806a.png)

以上说了：
  web缓存/代理服务器的基本结构
  为什么要使用代理服务器技术
  具体实现和数据同步的问题

---

### Email应用

- Email应用的构成

邮箱服务器
  邮箱：用于存储发给该用户的Email
  消息队列：存储待发送的Email

SMTP协议
  邮箱服务器之间进行消息传递所用的协议

  客户端：发送消息的服务器
  服务器：接收消息的服务器
  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-a88063edd1bf7d47.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  SMTP协议在传输层上使用TCP协议
  端口：25
  传输过程为3个阶段：握手、消息传输、关闭
  命令/响应交互模式（有别于HTTP协议的请求/响应模式）



![image.png](http://upload-images.jianshu.io/upload_images/1993435-66bdd75c2af0cd3e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-fb0cfefada853f97.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

SMTP的特点与HTTP的区别

![image.png](http://upload-images.jianshu.io/upload_images/1993435-727743fdb6a7b531.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- Email消息格式与POP3协议


![image.png](http://upload-images.jianshu.io/upload_images/1993435-a52c39c7788d1a62.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

SMTP只能支持ASCII字符，也就是SMTP服务器只能包含ASCII字符
那么，其他多媒体文件word、音视频、中文等非ASCII文本怎么存储

MIME(多媒体邮件扩展)
在邮件头部增加额外的行以声明MIME的内容类型，以说明消息包含
多媒体及其编码格式

注：文件类型可分为文本文件和二进制文件

文本文件就是以ASCII编码方式进行编码的文件
二进制文件直接是以二进制形式存在的文件，如PDF/word/图片等，二进制文件可以通过特定的编码方式转为以文本文件形式存在的文件，如base64编码
因此，上面Email的消息传输只能采用ASCII格式的文本文件，当传递其他多媒体文件时需要进行编码和指定文本类型

通过在特定协议的头部添加额外头信息（content-type和Content-Transfer-Encoding)的方法扩展了协议本身，HTTP协议也是采用这种方法进行二进制文件的传输；
![image.png](http://upload-images.jianshu.io/upload_images/1993435-58bf73a01a312e82.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 邮件访问协议
从服务器获取邮件，SMTP协议是负责访问传输协议，邮件应用不仅仅使用一个协议

![image.png](http://upload-images.jianshu.io/upload_images/1993435-1fcc5a022bc8f4e6.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

pop协议
![image.png](http://upload-images.jianshu.io/upload_images/1993435-df892c9a40d63b6f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

### DNS应用

在Internet上标识主机/路由器有两套系统：

- IP地址（供网络层使用）
- 域名地址(供人使用)

那么域名和IP地址之间如何映射？
通过域名解析系统DNS进行

它可以将域名解析为IP地址

![image.png](http://upload-images.jianshu.io/upload_images/1993435-f2e2cd05e5e39c7c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

如何理解DNS服务实现的负载均衡？
![image.png](http://upload-images.jianshu.io/upload_images/1993435-e498b4a9285f9121.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


根服务器
顶级域名服务器
上面为了获取www.amazon.com的域名进行了3次查询；

 - DNS根域名服务器
 本地域名服务器无法解析时，访问根域名服务器，如果根域名服务器也不知，则继续访问权威域名服务器，直到获取映射为止，将映射返回给本地域名服务器


![image.png](http://upload-images.jianshu.io/upload_images/1993435-e241a1ff5e195728.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- TLD顶级域名服务器和权威域名服务器
![image.png](http://upload-images.jianshu.io/upload_images/1993435-bba74e3900daa665.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 本地域名解析服务器

![image.png](http://upload-images.jianshu.io/upload_images/1993435-83227616ec517e45.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

DNS查询实例

- 迭代查询
![image.png](http://upload-images.jianshu.io/upload_images/1993435-1495d374f120982c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 递归查询
![image.png](http://upload-images.jianshu.io/upload_images/1993435-f8c68cf8984056eb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- DNS记录缓存与更新
![image.png](http://upload-images.jianshu.io/upload_images/1993435-7d657dd8263473f9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- DNS记录和消息格式
![image.png](http://upload-images.jianshu.io/upload_images/1993435-4011b644d1440322.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- DNS协议与消息格式
- 如何注册域名

![image.png](http://upload-images.jianshu.io/upload_images/1993435-30f4957f733ca3ab.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

## P2P应用

- 原理


![image.png](http://upload-images.jianshu.io/upload_images/1993435-79fb671a75507ecb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 文件分发

---

### socket编程

- 网络程序设计接口
![image.png](http://upload-images.jianshu.io/upload_images/1993435-e581d8b36550b297.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 应用编程接口API
![image.png](http://upload-images.jianshu.io/upload_images/1993435-8650f537902d3fd2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

几种典型的应用编程接口

![image.png](http://upload-images.jianshu.io/upload_images/1993435-b0b59613d000b528.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-9a0cb911a9e030c3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

应用进程对外进行标识该进程的套接字（应用进程之间进行通信的接口）通过IP地址+端口号唯一标识

![image.png](http://upload-images.jianshu.io/upload_images/1993435-8d7ff88b2261c1cd.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-56ce321e36336afc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-91e89ea62f8b41e2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-91e89ea62f8b41e2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-1c083de78b59b5ff.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-fbb3ead0e9aec79f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

TCP协议的套接字类型为SOCK_STREAM
UDP协议的套接字类型为SOCK_DGRAM
这两类套接字给应用层提供的服务不同


面向连接是指在真正进行数据传输时，必须要先建立连接

无连接指有数据传输，双方不需要直接交互，直接发送

![image.png](http://upload-images.jianshu.io/upload_images/1993435-3ca3445532b727f7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-702843efbc11ef90.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-702843efbc11ef90.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-4bace65b81a48281.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-7fcd73d50b4ffc9e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-a794377d41d0e0b2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-a1ee45e37e0747c6.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
如果不新建套接字，那么服务器只能在某个时刻为某个服务器进行服务，无法实现并发服务

发送数据
![image.png](http://upload-images.jianshu.io/upload_images/1993435-96c49f4816fb2be0.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

接收数据
![image.png](http://upload-images.jianshu.io/upload_images/1993435-a6713b10ae17b3bb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

Sockset API列表

![image.png](http://upload-images.jianshu.io/upload_images/1993435-09f002f75eaf11ae.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-cf6a15ab40929532.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 网络字节顺序
表示层解决数据表示转换问题——客户端和服务端之间进行数据通信时，这两端的数据表示不一时，
表示层就可以就数据进行转换，
在使用TCP/IP协议进行数据传输时，首先要将本地字节序转换为网络字节序

![image.png](http://upload-images.jianshu.io/upload_images/1993435-17842202c4c49793.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- C/S架构下Socket通信的流程
![image.png](http://upload-images.jianshu.io/upload_images/1993435-6959a150fbf67049.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---
客户端编程

- 解析服IP地址
![image.png](http://upload-images.jianshu.io/upload_images/1993435-c50d85aac0bb5e97.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 解析服务器端口号
![image.png](http://upload-images.jianshu.io/upload_images/1993435-aba2146237243c61.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 解析协议号
![image.png](http://upload-images.jianshu.io/upload_images/1993435-e5e972891c26c686.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- TCP客户端软件流程
![image.png](http://upload-images.jianshu.io/upload_images/1993435-33cc7f1bfc1f58c9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- UDP客户端软件流程
![image.png](http://upload-images.jianshu.io/upload_images/1993435-de5b898696c15d85.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---
基于套接字的服务器端的编程
![image.png](http://upload-images.jianshu.io/upload_images/1993435-a22b7879832143af.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 循环无连接服务器
循环：一次只处理一个客户请求，处理完后再处理下一个客户请求
无连接：基于UDP协议采用无连接的数据传输方法

![image.png](http://upload-images.jianshu.io/upload_images/1993435-2c9dd3f037183993.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 循环面向连接服务器

![image.png](http://upload-images.jianshu.io/upload_images/1993435-ba16e9dd8d7fbc83.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 并发无连接服务器
一个线程创建之后处理一个请求
![image.png](http://upload-images.jianshu.io/upload_images/1993435-bcc6678bf2c9dfeb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 并发面向连接服务器
![image.png](http://upload-images.jianshu.io/upload_images/1993435-e498cc2c0857707a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

## 传输层
![image.png](http://upload-images.jianshu.io/upload_images/1993435-c4ba53e65937f941.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 传输层协议
![image.png](http://upload-images.jianshu.io/upload_images/1993435-1d39bb8e00089626.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 传输层 vs 网络层
![image.png](http://upload-images.jianshu.io/upload_images/1993435-e52b5c6d9d97c850.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-76eab0b6a86401bf.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

### 多路复用和多路分用


![image.png](http://upload-images.jianshu.io/upload_images/1993435-279560b6f3371707.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 分用的工作原理
![image.png](http://upload-images.jianshu.io/upload_images/1993435-1936577ee8e8deef.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  - 无连接分用
![image.png](http://upload-images.jianshu.io/upload_images/1993435-26fc89ab7ac8208c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-7005e918150f318c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  - 面向连接的分用
![image.png](http://upload-images.jianshu.io/upload_images/1993435-be485f424fef0578.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
TCP协议是点对点的，所以两端应用连接时必须是不同的进程，但是也可以通过开辟多线程实现这一技术


![image.png](http://upload-images.jianshu.io/upload_images/1993435-b35956d22e22b956.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---
### 无连接传输协议

- UDP

![image.png](http://upload-images.jianshu.io/upload_images/1993435-1cfc3c57588cddab.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-463414a65591f7b5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---
### 可靠数据传输原理
如何将不可靠的信道转化为可靠的信道，实现可靠数据传输？

![image.png](http://upload-images.jianshu.io/upload_images/1993435-ab5ec2d50c3ac667.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-f27b9debb0bd5300.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

有限状态自动机
![image.png](http://upload-images.jianshu.io/upload_images/1993435-3f9da622a7c77d49.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

有限状态自动机刻画网络协议

Rdt 1.0研究可靠信道上的可靠数据传输协议

Rdt 2.0研究不可靠信道的可靠数据传输协议

![image.png](http://upload-images.jianshu.io/upload_images/1993435-247641e19c886e6e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-c23ebfcd8352d0f7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-fd14f95f1c4747dd.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

Rdt 2.1 和 2.2

Rdt 3.0停等操作
由于停等操作导致Rtd的性能较差

流水线机制可以提高资源利用率
![image.png](http://upload-images.jianshu.io/upload_images/1993435-6cfe42dca218113e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-657af8a68b601462.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-dad3be41b1792c36.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---
### TCP 协议
![image.png](http://upload-images.jianshu.io/upload_images/1993435-2b463b44fb839f7b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-28538e6757bdfa18.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-b39b5a31772d9bf5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

TCP的流量控制机制

上层应用可能处理buffer中数据的速度较慢，若发送方传输的数据过多、过快，那么
有可能导致buffer溢出

流量控制就是控制发送方传输的数据不至于过多过快

![image.png](http://upload-images.jianshu.io/upload_images/1993435-b9ebe4845d2f4f79.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-9bc369252b0b2194.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- TCP连接管理


![image.png](http://upload-images.jianshu.io/upload_images/1993435-c56455684ba8e022.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-d9cb62bcebdcb661.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

## 拥塞控制原理



![image.png](http://upload-images.jianshu.io/upload_images/1993435-0b691b1927ce8234.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

可靠数据传输解决的是端到端的“个体利益”的数据传输的问题
拥塞控制从“群体利益” 的角度去解决数据传输问题

拥塞控制：不要让中间的网络承受不了数据量
流量控制：发送方数据传输量不要太快和太大，以至于接收方接收不过来

拥塞的成因：

![image.png](http://upload-images.jianshu.io/upload_images/1993435-5207ea4cd668c71d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

如何进行拥塞控制
管制发送方的发送速率
![image.png](http://upload-images.jianshu.io/upload_images/1993435-065e7adfaf8b8ddb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- TCP拥塞控制机制

![image.png](http://upload-images.jianshu.io/upload_images/1993435-388985657a1ab466.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

## 网络层
传输层是端到端的层次，而网络层不再局限于端到端

基本过程:

![image.png](http://upload-images.jianshu.io/upload_images/1993435-79d3deb8f0b2a23b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

网络层的核心功能——转发与路由

数据报datagram在通过路由器时，会通过路由算法确定通过网络的端到端的路径，
而当前路由器的转发表则根据计算出的路径确定本路由如何转发分组


![image.png](http://upload-images.jianshu.io/upload_images/1993435-e27690343acadcba.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

网络层核心功能——连接建立
![image.png](http://upload-images.jianshu.io/upload_images/1993435-135bacf5c6f5556c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-3f3455bc20e5636d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

提供无连接服务的网络：数据报网络
提供连接服务的网络：虚电路网络

- 虚电路网络

![image.png](http://upload-images.jianshu.io/upload_images/1993435-fc87e8a782688ace.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
之所以称为虚电路，是因为电路交换是采用多路复用技术将同一个电路分成多路，
而分组交换则是利用链路的全部带宽并且采用电路交换的技术，因此是“虚电路”


![image.png](http://upload-images.jianshu.io/upload_images/1993435-c32fc726c23ebfe2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-74f3d34ec9aa24a6.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

从源主机和目的主机会建立一条虚电路(VC)，沿路的每段链路都有一个不同的VCID
沿着该虚电路传输的分组，携带对应虚电路的VCID而不是目的地址，
路由器在转发分组时依据转发表改写虚电路号

![image.png](http://upload-images.jianshu.io/upload_images/1993435-f295229545cccb7d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-c5018a310a4c26cb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 数据报网络

![image.png](http://upload-images.jianshu.io/upload_images/1993435-0a4555bb4476a09f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-871f819b6f5c9988.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-ea87e9d65d22959f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-5cdc3ad2a902d871.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### IPv4协议

Internet网络层主要是数据报网络
数据报网络层主要提供的服务是路由和转发功能


![image.png](http://upload-images.jianshu.io/upload_images/1993435-970576e91c1c30a8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

IP数据报的格式

![image.png](http://upload-images.jianshu.io/upload_images/1993435-9fa31baa7b851e0f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- IP分片

之所以要进行IP分片，原因是传输的IP分组数据报大小超过链路的MTD,所以要进行分片

  -最大传输单元(MTU)
  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-63fe03e133507d3d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-dbb9ebb205e788b0.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

 - IP编址
 
 点分十进制IP地址
 ![image.png](http://upload-images.jianshu.io/upload_images/1993435-0a156f2286a2dfdf.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

 具有相同网络号的主机构成的网络叫做IP子网
 因此，当路由器执行路由功能时只需要记录相应收发网络的IP子网就可以了

 ![image.png](http://upload-images.jianshu.io/upload_images/1993435-ecf2c1da6edb0cbe.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

 - 有类IP地址
 如何去规范网络号和主机号所占据的位数

 ![image.png](http://upload-images.jianshu.io/upload_images/1993435-2a7fcf7940a7dbb1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

 ![image.png](http://upload-images.jianshu.io/upload_images/1993435-91b3f9e8659b55ed.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

 私有ip地址：只能在企业或组织内部使用，在公共网络上是无法识别的
 ![image.png](http://upload-images.jianshu.io/upload_images/1993435-621ef4dc84b90ac6.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

 - IP子网和子网掩码

 子网划分
![image.png](http://upload-images.jianshu.io/upload_images/1993435-aca7a879e22da357.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-b814977077f8544a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

子网掩码？


![image.png](http://upload-images.jianshu.io/upload_images/1993435-48864aaa3988a034.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- CIDR与路由聚合
- IPv6
![image.png](http://upload-images.jianshu.io/upload_images/1993435-e4766bb16cfd4bd9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-e4766bb16cfd4bd9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

 - 路由算法
 将网络抽象为图
 ![image.png](http://upload-images.jianshu.io/upload_images/1993435-0081081c0d5433b3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

 ![image.png](http://upload-images.jianshu.io/upload_images/1993435-31ed9af032586d6f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-d01e21507c2b9325.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

## 数据链路层

链路可分为物理链路和数据链路，
物理链路处于物理层，数据链路处于数据链路层

![image.png](http://upload-images.jianshu.io/upload_images/1993435-b1cb22749714dc56.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

帧同步：
作为数据链路层的数据帧，在物理层传输中是一系列的比特
从另一端物理层接收到一串串的比特流，怎样识别出数据帧呢？


![image.png](http://upload-images.jianshu.io/upload_images/1993435-1f5a084d7927aff5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-1f5a084d7927aff5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-11ef1a510db5eb2c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-ffb80ad10ec26816.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

将数据报通过网卡的控制器构造成数据帧

![image.png](http://upload-images.jianshu.io/upload_images/1993435-88c01cd399059a71.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


- 多路访问控制协议
如果在一个网络中使用广播链路或共享物理介质，需要一个机制来协调谁使用这一广播链路或介质

![image.png](http://upload-images.jianshu.io/upload_images/1993435-47688e37ca8f5531.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

## 局域网

-MAC地址

当构造数据帧时，可以通MAC地址标识数据帧从哪里发出，由哪个节点进行接收

![image.png](http://upload-images.jianshu.io/upload_images/1993435-03eccee070f83461.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-b8d3747218fae82b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

MAC地址与IP地址区别：
 MAC地址相当于身份证，用于标识数据帧，是一个平面地址
 IP地址相当于邮政地址，用于标识数据报，是一个层次地址，依赖于节点具体位于网络的哪个子网

 ARP协议：地址解析协议

![image.png](http://upload-images.jianshu.io/upload_images/1993435-f398b039efcbea21.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

如果发送端事先不知道接收端的MAC地址呢？
如果两端处于同一个局域网，则通过广播的方式

如果两端不在同一个局域网中？

![image.png](http://upload-images.jianshu.io/upload_images/1993435-cc999878dbfe1df5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-0c9cd0a70756c4dd.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---
### 以太网
居统治地位的有线LAN技术
![image.png](http://upload-images.jianshu.io/upload_images/1993435-96494b889fbbbc85.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

以太网在链路层属于无连接、不可靠的服务

![image.png](http://upload-images.jianshu.io/upload_images/1993435-96494b889fbbbc85.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-139a1743ac5f6c29.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

以太网交换机
![image.png](http://upload-images.jianshu.io/upload_images/1993435-cd10b80716522c51.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-58a5b5228a9ddcce.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

PPP协议
点对点数据链路协议
![image.png](http://upload-images.jianshu.io/upload_images/1993435-caa120ee2cca47df.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 无线局域网
![image.png](http://upload-images.jianshu.io/upload_images/1993435-caa120ee2cca47df.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

## 网络安全

![image.png](http://upload-images.jianshu.io/upload_images/1993435-788ed7db0bbcf447.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-a575126454e478e5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-021ed7b52ef23446.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-30f6465ea1299db1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-63867d110443c78e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-d4b5fb1e16919163.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-f05a7fe7229c7e98.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-aa3705a6ae6fb43a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-ead5bebeeb551c67.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

## 密码学基础

![image.png](http://upload-images.jianshu.io/upload_images/1993435-910aa4cc9df86408.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

根据在加密和解密过程中使用的密钥相同与否：
将加密方法分成两大类：
  对称密钥加密
  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-412d21c53afcb6fc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  公开密钥加密
  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-23bae5bd6b7e9f76.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  ![image.png](http://upload-images.jianshu.io/upload_images/1993435-b3448a88208d2a19.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  - 传统加密方法

![image.png](http://upload-images.jianshu.io/upload_images/1993435-5292fe3e106561f9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-2af0fed33e4993cb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-887cf683425437ac.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-8212d2cca0e32325.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-7eb6ebee428d63a7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 现代加密技术
![image.png](http://upload-images.jianshu.io/upload_images/1993435-473ee1862cec745a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-3cb0fc83096d0691.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-36f12ef0a2d3e9ca.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-44a8953624b4f607.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 数据加密标准DES
- 非对称密钥
![image.png](http://upload-images.jianshu.io/upload_images/1993435-749ee9d7bc774fe9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-82d964fbc341cdda.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-4889784742df967b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-b43ec0cab91c888a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-314894626ef111dc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-49ddc5f443815d9c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 身份认证

![image.png](http://upload-images.jianshu.io/upload_images/1993435-9dc850cdbf302c1d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-2b1ab92134a389da.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-31c83ad5e596d24c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-ff4288fbe7b57e27.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



![image.png](http://upload-images.jianshu.io/upload_images/1993435-f2a2443939a0de40.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)




![image.png](http://upload-images.jianshu.io/upload_images/1993435-61adfe210258da26.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-f5833859642e2ef5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-01a284b090a0a258.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-c6f7d4af19dfa806.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-9afc9fdb0daac516.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 报文完整性

![image.png](http://upload-images.jianshu.io/upload_images/1993435-1725c221ff76f129.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-8e229859c1cc1d66.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-58daec138237d10f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

  
![image.png](http://upload-images.jianshu.io/upload_images/1993435-170f6fbdf06197b4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-aa751cb10889daed.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-e6626ecf3c4ebdfc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-0ea3ee3c0ce8e12f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 数字签名

![image.png](http://upload-images.jianshu.io/upload_images/1993435-d16407bf9ee92184.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-b3354e3326cf9fe6.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



![image.png](http://upload-images.jianshu.io/upload_images/1993435-723a11b49574bc6d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

报文摘要签名


![image.png](http://upload-images.jianshu.io/upload_images/1993435-f36bd6a242f23aa1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 密钥分发中心

![image.png](http://upload-images.jianshu.io/upload_images/1993435-df32772f61e8d2c7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


![image.png](http://upload-images.jianshu.io/upload_images/1993435-1e607ed685a3ff9c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-4a6604ce302d7eea.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- 公钥问题

![image.png](http://upload-images.jianshu.io/upload_images/1993435-ea826e78eff99f05.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-50151def78fa8417.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)




![image.png](http://upload-images.jianshu.io/upload_images/1993435-a926887d98c033da.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](http://upload-images.jianshu.io/upload_images/1993435-463b68ccc3759b97.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

