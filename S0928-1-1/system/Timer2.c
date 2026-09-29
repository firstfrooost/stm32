#include "stm32f10x.h"                  // Device header

void Timer2_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_ETRClockMode1Config(TIM1,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_NonInverted,0x0f);
	
	TIM_TimeBaseInitTypeDef TIM1_OutInitStructure;
	TIM1_OutInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM1_OutInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM1_OutInitStructure.TIM_Period = 2-1;
	TIM1_OutInitStructure.TIM_Prescaler = 1-1;
	TIM1_OutInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1,&TIM1_OutInitStructure);
	
	TIM_ClearFlag(TIM1,TIM_FLAG_Update);
	
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM1,ENABLE);

}

uint16_t Timer2_GetCounter(void)
{
	return TIM_GetCounter(TIM1);
}
