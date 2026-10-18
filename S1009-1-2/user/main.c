#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"
#include "Servo.h"
#include "Key.h"

uint8_t KeyNum;
float Angle;

int main(void)
{
	OLED_Init();
	Key_Init();

	
	OLED_ShowString(1,1,"Angle:");
	
	while (1)
	{
		KeyNum=Key_GetNum();
		if (KeyNum==1)
		{
			OLED_ShowString(1,1,"abbbbbb");
		}
		Servo_SetAngle(Angle);
		OLED_ShowNum(1,7,Angle,3);
	}
	
}
 