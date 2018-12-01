#ifndef _STEERING_ENGINE_H
#define _STEERING_ENGINE_H

#include "stm32f10x_gpio.h"

typedef struct StreeingEngine
{
	GPIO_TypeDef* gpio_x;
	uint16_t gpio_pin_a;
	uint16_t gpio_pin_b;
	uint16_t gpio_pin_c;
	uint16_t gpio_pin_d;
	
	GPIO_InitTypeDef GPIO_InitStructure;
} StreeingEngine;

void StreeingEngine_init(StreeingEngine* o, GPIO_TypeDef* GPIOx, uint32_t RCC_APB2Periph, uint16_t a, uint16_t b, uint16_t c, uint16_t d);

void StreeingEngine_clockwise(StreeingEngine* o, int speed);
void StreeingEngine_counterClockwise(StreeingEngine* o, int speed);
void StreeingEngine_stop(StreeingEngine* o);

#endif
