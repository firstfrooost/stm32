#include "stm32f10x.h"                  // Device header
#include "buzzer.h"
#include "Delay.h"
#include "LightSensor.h"

int main(void)
{
	buzzerinit();
	LightSensor_Init();
	
	while(1)
	{
		if (LightSensor_Get() == 1)
		{
			BUZZ_ON();
		}
		else
		{
			BUZZ_OFF();
		}
	}
}
