#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "hwsensor.h"
#include "BUZZER.h"

int main(void)
{
	HWSensor_Init();
	OLED_Init();
	BUZZER_Init();
	BUZZER_OFF();
	
	OLED_ShowString(1,1,"Count:");
	
	while (1)
	{
		int a = CountSensor_Get();
		a=a+1;
		OLED_ShowNum(1,7,CountSensor_Get(),5);
		if (a%2==0)
		{
			BUZZER_ON();
			OLED_ShowString(2,1,"            ");
			OLED_ShowString(2,1,"BUZZER:ON");
			Delay_ms(500);
		}
		else
		{
			BUZZER_OFF();
			OLED_ShowString(2,1,"BUZZER:OFF");
		}
	}
	
	
}
