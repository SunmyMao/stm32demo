#include "stm32f10x.h"
#include "stm32f10x_conf.h"

void LED_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void delay_x_ms(int x)
{
	int i,j;
	for(i=0; i < x; i++)
	{
		for(j=0; j < 112; j++);
	}
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
		delay_x_ms(10000);
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		delay_x_ms(10000);
	}
}
*/

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

void Engine_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB, GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8);
}

void forward(int speed)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	delay_x_ms(speed);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	delay_x_ms(speed);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	delay_x_ms(speed);
		
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);
	GPIO_SetBits(GPIOB,GPIO_Pin_8);
	delay_x_ms(speed);
}

void backward(int speed)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);
	GPIO_SetBits(GPIOB,GPIO_Pin_8);
	delay_x_ms(speed);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	delay_x_ms(speed);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	delay_x_ms(speed);

	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	delay_x_ms(speed);
}

void stop(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	GPIO_ResetBits(GPIOB,GPIO_Pin_6);
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
}


int main(void)
{
	int i = 0;
	Engine_init();
	LED_init();
	delay_x_ms(225);
	
	while(1)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		for (i = 0; i < 250; i++)
		{
			forward(150);
			delay_x_ms(225);
		}
		stop();
		GPIO_SetBits(GPIOC, GPIO_Pin_13);

		delay_x_ms(100000);
		
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		for (i = 0; i < 250; i++)
		{
			backward(150);
			delay_x_ms(225);
		}
		stop();

		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delay_x_ms(100000);
	}
}
