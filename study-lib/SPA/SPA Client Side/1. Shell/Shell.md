## 理解 Shell

Shell 是 SPA 的 master controller，是 SPA 的形状和结构；

类似聊天、登录和导航等功能模块依靠 API 依附在 Shell；

所有的功能模块都尽可能独立地完成工作；

![image.png](http://upload-images.jianshu.io/upload_images/1993435-45a66e8e4a275eb3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


## Shell 的功能

- 渲染和管理功能容器
- 管理应用状态
- 协调功能模块

## 渲染和管理功能容器

![image.png](http://upload-images.jianshu.io/upload_images/1993435-55b68a7817fa9ec8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### 渲染功能容器

```
var spa = (function () {
  var initModule = function ($container) {
    spa.shell.initModule($container)
  }
  return {
    initModule: initModule
  }
}())
```

### 管理功能容器

- 展开和收起聊天滑块功能容器

需求分析：
1. 能够配置滑块运动的速度和高度
2. 创建单个方法来展开和收起聊天滑块
3. 避免出现竞争条件，即滑块同时展开和收起
4. 可传入一个回调函数，在滑块运动结束时调用
5. 创建测试代码，以确保滑块功能正常

### 管理应用状态

- anchor interface pattern

![image.png](http://upload-images.jianshu.io/upload_images/1993435-e9afed461d67bedd.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

通过事件处理函数改变 hash 值，hash 值的变化导致不同的功能模块的变化

