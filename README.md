# STM32-H7-GUI-U8G2

## 项目简介
这是一个基于STM32 H7系列单片机的GUI框架项目，使用U8G2图形库实现界面显示，集成了MultiButton按键库实现按键控制。该项目旨在提供一个轻量级、易用的嵌入式GUI解决方案。

## 主要特性
- 基于U8G2图形库的显示驱动
- 集成MultiButton按键库，支持多种按键操作
- 适配STM32 H7系列高性能单片机
- 模块化的UI设计，易于扩展
- C语言实现，代码简洁高效
- 使用CMake构建系统，支持CLion开发

## 硬件支持
- 控制器：STM32 H7系列
- 显示屏：支持U8G2库兼容的显示模块
  - SSD1306
  - SH1106
  - 其他U8G2支持的显示屏
- 按键：支持多按键输入

## 开发环境
- CLion 2023.x 或更高版本
- STM32CubeMX
- OpenOCD
- ARM GCC工具链
- CMake 3.x 或更高版本

## 软件架构

## 软件依赖
- STM32 HAL库
- U8G2图形库
- MultiButton按键库

## 目录结构 
stm32-H7-gui-u8g2/
├── ui/ # UI相关源代码
│ ├── button/ # 按键处理模块
│ └── display/ # 显示驱动模块
├── .gitignore # Git忽略文件配置
├── CMakeLists.txt # CMake构建配置文件
├── LICENSE # GPL-3.0开源协议
└── README.md # 项目说明文档

## 快速开始
1. 环境准备
   - 安装CLion IDE
   - 安装STM32CubeMX
   - 安装OpenOCD
   - 安装ARM GCC工具链
   - 安装CMake

2. 获取代码

bash
git clone https://github.com/Z1R343L-D77/stm32-H7-gui-u8g2.git

3. 硬件连接
   - 按照硬件设计文档连接显示屏
   - 配置按键输入引脚

4. 编译与下载
   - 使用IDE打开项目
   - 根据实际硬件配置修改相应的引脚定义
   - 编译并下载到开发板

## 配置说明
1. 显示屏配置
   - 在display模块中选择对应的显示屏驱动
   - 配置通信接口（I2C/SPI）
   - 设置显示屏分辨率

2. 按键配置
   - 在button模块中配置按键数量
   - 设置按键触发方式
   - 配置按键回调函数

3. 项目配置
   - 使用STM32CubeMX生成基础代码
   - 在CLion中打开项目
   - 配置工具链：
     - 设置ARM GCC编译器路径
     - 配置OpenOCD路径
     - 设置CMake工具链

4. 硬件连接
   - 按照硬件设计文档连接显示屏
   - 配置按键输入引脚
   - 连接ST-Link调试器

5. 编译与下载
   - 在CLion中选择正确的编译配置
   - 使用OpenOCD配置进行下载和调试
   - 编译并下载到开发板

## OpenOCD配置


## 调试说明
1. CLion调试配置
   - 创建OpenOCD下载配置
   - 配置GDB调试器
   - 设置断点和监视变量

2. 显示屏配置
   - 在display模块中选择对应的显示屏驱动
   - 配置通信接口（I2C/SPI）
   - 设置显示屏分辨率

3. 按键配置
   - 在button模块中配置按键数量
   - 设置按键触发方式
   - 配置按键回调函数

## 常见问题
1. OpenOCD连接问题
   - 检查ST-Link连接
   - 验证OpenOCD配置文件
   - 确认驱动安装正确

2. 编译错误处理
   - 检查工具链配置
   - 确认CMake配置正确
   - 验证依赖库路径

## 贡献指南
欢迎提交Issue和Pull Request。在提交大的改动之前，请先开Issue讨论。

## 开源协议
本项目采用[GPL-3.0](LICENSE)协议开源。

## 参考资料
- [U8G2图形库](https://github.com/olikraus/u8g2)
- [MultiButton按键库](https://github.com/0x1abin/MultiButton)
- [OpenOCD用户手册](http://openocd.org/doc/html/index.html)
- [CLion嵌入式开发文档](https://www.jetbrains.com/help/clion/embedded-development.html)
