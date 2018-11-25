stm32 学习笔记

目前有 led 点灯代码和舵机控制代码

硬件条件：
    STM32F103C8T6 最小系统控制板 (http://pan.baidu.com/s/1geHfIE3)
    ULN2003驱动板5V测试模块板 + 5线4相减速步进电机 (http://pan.baidu.com/s/1boXz89T, http://pan.baidu.com/s/1i52v0FF)
    
现状：
    实现了板载 LED 灯(D2) 频闪
    实现了舵机的正反转
        舵机接线规则：
        IN1(A) ---- PB5
        IN2(B) ---- PB6
        IN3(C) ---- PB7
        IN4(D) ---- PB8
        +      ---- +5V
        -      ---- GND
    电机导通相序
        正转  D-C-B-A
        反转  A-B-C-D
