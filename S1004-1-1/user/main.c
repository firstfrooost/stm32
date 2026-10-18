#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void LED_ON(void);
void LED_OFF(void);
void BUZZ1(void);
void BUZZ2(void);
void BUZZ3(void);
void BUZZ4(void);
void BUZZ5(void);
void BUZZ6(void);
void BUZZ7(void);
void BUZZ8(void);
void DUO(void);
void LAI(void);
void MI(void);
void FA(void);
void SUO(void);
void LA(void);
void XI(void);

int main(void)
{
	RCC->APB2ENR = 0x00000010;
	GPIOC->CRH = 0x00300000;
	while(1)
	{
		for(int i=0;i<=100;i++)
		{
		BUZZ1();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ2();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ3();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ4();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ5();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ6();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ7();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ8();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ7();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ6();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ5();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ4();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ3();
		}
		for(int i=0;i<=100;i++)
		{
		BUZZ2();
		}
	}
}

void LED_ON(void)
{
	GPIOC->ODR = 0x00002000;
}

void LED_OFF(void)
{
	GPIOC->ODR = 0x00000000;
}

void BUZZ1(void)
{
		LED_ON();
		Delay_us(1000);
		LED_OFF();
		Delay_us(1000);
}

void BUZZ2(void)
{
		LED_ON();
		Delay_us(850);
		LED_OFF();
		Delay_us(1150);
}

void BUZZ3(void)
{
		LED_ON();
		Delay_us(700);
		LED_OFF();
		Delay_us(1300);
}

void BUZZ4(void)
{
		LED_ON();
		Delay_us(550);
		LED_OFF();
		Delay_us(1450);
}

void BUZZ5(void)
{
		LED_ON();
		Delay_us(400);
		LED_OFF();
		Delay_us(1600);
}

void BUZZ6(void)
{
		LED_ON();
		Delay_us(250);
		LED_OFF();
		Delay_us(1750);
}

void BUZZ7(void)
{
		LED_ON();
		Delay_us(100);
		LED_OFF();
		Delay_us(1900);
}

void BUZZ8(void)
{
		LED_ON();
		Delay_us(10);
		LED_OFF();
		Delay_us(2000);
}

