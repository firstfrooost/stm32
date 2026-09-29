#include "stm32f10x.h"                  // Device header

void LightSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_LightSensor_Structure;
	GPIO_LightSensor_Structure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_LightSensor_Structure.GPIO_Pin = GPIO_Pin_13;
	GPIO_LightSensor_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_LightSensor_Structure);
}

uint8_t LightSensor_Get(void)
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}