#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "steering_engine.h"
#include "uart.h"

void LED_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

// led
/*
int main(void)
{
	LED_init();
	delay_x_ms(10000);
	while(1)
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
		delay_x_ms(100000);
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		delay_x_ms(100000);
	}
}
*/
int main(void)
{
	u8 i;
	u8 s[] = "Hello\r\n";
	USART1_config();
	while(1)
	{
		for(i=0; i<sizeof(s)/sizeof(s[0]); i++)
		{
			USART_SendData(USART1, s[i]);
		}
		// USART_ReceiveData(USART1);
	}

}

/*******************
IN1(A) ---- PB5
IN2(B) ---- PB6
IN3(C) ---- PB7
IN4(D) ---- PB8
+   ---- +5V
-   ---- GND
*********************/
//正转 电机导通相序 D-C-B-A
//反转 电机导通相序 A-B-C-D
/*
int main(void)
{
	int i = 0;
	StreeingEngine engine;
	StreeingEngine_init(&engine, GPIOB, RCC_APB2Periph_GPIOB, GPIO_Pin_5, GPIO_Pin_6, GPIO_Pin_7, GPIO_Pin_8);
	LED_init();
	
	delay_x_ms(225);
	
	while(1)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		for (i = 0; i < 64 * 64 / 8; i++)
		{
			StreeingEngine_clockwise(&engine, 150);
			delay_x_ms(225);
		}
		StreeingEngine_stop(&engine);
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delay_x_ms(100000);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		for (i = 0; i < 64 * 64 / 8; i++)
		{
			StreeingEngine_counterClockwise(&engine, 150);
			delay_x_ms(225);
		}
		StreeingEngine_stop(&engine);
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delay_x_ms(100000);
	}
}
*/
