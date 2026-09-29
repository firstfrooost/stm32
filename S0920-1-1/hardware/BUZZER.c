#include "stm32f10x.h"                  // Device header

void BUZZER_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_BUZZERStructure;
	GPIO_BUZZERStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_BUZZERStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_BUZZERStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_BUZZERStructure);
}

void BUZZER_ON(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
}
void BUZZER_OFF(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
}

void BUZZER_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_13) == 0)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
	}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	}
}
