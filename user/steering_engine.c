#include "steering_engine.h"
#include "utils.h"

void StreeingEngine_init(StreeingEngine* o, GPIO_TypeDef* GPIOx, uint32_t RCC_APB2Periph, uint16_t a, uint16_t b, uint16_t c, uint16_t d)
{
	o->gpio_x = GPIOx;
	o->gpio_pin_a = a;
	o->gpio_pin_b = b;
	o->gpio_pin_c = c;
	o->gpio_pin_d = d;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);
	o->GPIO_InitStructure.GPIO_Pin = o->gpio_pin_a | o->gpio_pin_b | o->gpio_pin_c | o->gpio_pin_d;
	o->GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	o->GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(o->gpio_x, &o->GPIO_InitStructure);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_a | o->gpio_pin_b | o->gpio_pin_c | o->gpio_pin_d);
}

void StreeingEngine_clockwise(StreeingEngine* o, int speed)
{
	GPIO_SetBits(o->gpio_x, o->gpio_pin_a);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_b);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_c);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_d);
	delay_us(speed);
	
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_a);
	GPIO_SetBits(o->gpio_x, o->gpio_pin_b);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_c);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_d);
	delay_us(speed);
	
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_a);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_b);
	GPIO_SetBits(o->gpio_x, o->gpio_pin_c);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_d);
	delay_us(speed);
		
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_a);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_b);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_c);
	GPIO_SetBits(o->gpio_x, o->gpio_pin_d);
	delay_us(speed);
}

void StreeingEngine_counterClockwise(StreeingEngine* o, int speed)
{
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_a);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_b);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_c);
	GPIO_SetBits(o->gpio_x, o->gpio_pin_d);
	delay_us(speed);
	
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_a);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_b);
	GPIO_SetBits(o->gpio_x, o->gpio_pin_c);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_d);
	delay_us(speed);
	
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_a);
	GPIO_SetBits(o->gpio_x, o->gpio_pin_b);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_c);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_d);
	delay_us(speed);

	GPIO_SetBits(o->gpio_x, o->gpio_pin_a);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_b);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_c);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_d);
	delay_us(speed);
}

void StreeingEngine_stop(StreeingEngine* o)
{
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_a);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_b);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_c);
	GPIO_ResetBits(o->gpio_x, o->gpio_pin_d);
}
