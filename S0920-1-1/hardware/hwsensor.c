#include "stm32f10x.h"                  // Device header
#include "BUZZER.h"

uint16_t CountSensor_Count;

void HWSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitTypeDef GPIO_HWsensor_Structure;
	GPIO_HWsensor_Structure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_HWsensor_Structure.GPIO_Pin = GPIO_Pin_12;
	GPIO_HWsensor_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_HWsensor_Structure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource12);
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line12;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI15_10_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line12) == SET)
	{
		CountSensor_Count ++;
		EXTI_ClearITPendingBit(EXTI_Line12);
	}
}

uint16_t CountSensor_Get(void)
{
	return CountSensor_Count;
}

uint8_t HWSensor_Get(void)
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12);
	
}