#include "stm32f10x.h"                  // Device header
#include "Delay.h"


int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	while(1)
	{	
		GPIO_Write(GPIOA,~0X0001);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0002);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0004);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0008);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0010);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0020);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0040);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0080);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0100);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0200);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0400);
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0800);
		Delay_ms(100);

	}
}
