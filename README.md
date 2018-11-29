stm32 学习笔记

硬件条件：
    STM32F103C8T6 最小系统控制板 (http://pan.baidu.com/s/1geHfIE3)
    ULN2003驱动板5V测试模块板 + 5线4相减速步进电机 (http://pan.baidu.com/s/1boXz89T, http://pan.baidu.com/s/1i52v0FF)
    CH340G USB 转串口工具


已有功能：
    板载 LED 灯(D2) 频闪

    舵机的正反转
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
    
    通过 PC 串口与 stm32 通信，使用 0 和 非0 来控制 LED 的开关，同是返回 ‘off\r\n’ 和 ‘on\r\n’
