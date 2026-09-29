#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "KEY.h"	

uint8_t KeyNum;

int main(void)
{
	LED_Init();
	Key_Init();

	while(1)
	{
		KeyNum = Key_GetNum();
		if (KeyNum == 1)
		{
			LED1_Turn();
		}
		if (KeyNum == 2)
		{
			
			LED2_Turn();
		}
		if (KeyNum == 4 || KeyNum == 3)
		{
			LED1_OFF();
			LED2_OFF();
		}
		
	}
}
