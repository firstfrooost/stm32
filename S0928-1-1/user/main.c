#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "Timer2.h"

volatile int16_t Num;           //方向计数（可正可负；ISR 修改、主循环读取，必须 volatile）
volatile uint32_t Timer_Count;  //TIM2(PA0)侧累计：每次更新中断+1（当前Period=10，即每10个脉冲）
volatile uint32_t Timer2_Count; //TIM1(PA12)侧累计：每次更新中断+1（当前Period=10，即每10个脉冲）

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//优先级分组只设置一次
	
	OLED_Init();
	Timer_Init();
	Timer2_Init();
	
	OLED_ShowString(1,1,"Num:");
	OLED_ShowString(2,1,"CNT1:");
	OLED_ShowString(3,1,"CNT2:");
	
	
	while(1)
	{
		OLED_ShowSignedNum(1,5,Num,5);			//带符号显示，避开"Num:"(1~4列)
		OLED_ShowNum(2,6,Timer2_Count,5);		//TIM1(PA12)侧累计，不覆盖"CNT1:"
		OLED_ShowNum(3,6,Timer_Count,5);		//TIM2(PA0)侧累计，不覆盖"CNT2:"
		Delay_ms(50);							//节流，降低软件I2C刷新频率
	}
	
}
 
void TIM1_UP_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1,TIM_IT_Update)==SET)
	{
		Timer2_Count++;
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0)
		{
			Num--;
		}
		TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
	}
}
	
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
	{
		Timer_Count++;
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12) == 0)
		{
			Num++;
		}
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}

