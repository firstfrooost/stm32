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
		DUO();
		LAI();
		MI();
		FA();
		SUO();
		LA();
		XI();
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
		Delay_us(100);
		LED_OFF();
		Delay_us(100);
}

void BUZZ2(void)
{
		LED_ON();
		Delay_us(100);
		LED_OFF();
		Delay_us(200);
}

void BUZZ3(void)
{
		LED_ON();
		Delay_us(100);
		LED_OFF();
		Delay_us(300);
}

void BUZZ4(void)
{
		LED_ON();
		Delay_us(100);
		LED_OFF();
		Delay_us(400);
}

void BUZZ5(void)
{
		LED_ON();
		Delay_us(100);
		LED_OFF();
		Delay_us(500);
}

void BUZZ6(void)
{
		LED_ON();
		Delay_us(100);
		LED_OFF();
		Delay_us(600);
}

void BUZZ7(void)
{
		LED_ON();
		Delay_us(100);
		LED_OFF();
		Delay_us(700);
}

void BUZZ8(void)
{
		LED_ON();
		Delay_us(100);
		LED_OFF();
		Delay_us(800);
}

void DUO(void)
{
	for(int i=0;i<=2000;i++)
	{
	 BUZZ1();
	}
}

void LAI(void)
{
	for(int i=0;i<=1333;i++)
	{
	 BUZZ2();
	}
}

void MI(void)
{
	for(int i=0;i<=1000;i++)
	{
	 BUZZ3();
	}
}

void FA(void)
{
	for(int i=0;i<=800;i++)
	{
   BUZZ4();
	}
}

void SUO(void)
{
	for(int i=0;i<=667;i++)
	{
		BUZZ5();
	}
}

void LA(void)
{
	for(int i=0;i<=571;i++)
	{
	 BUZZ6();
	}
}
	
void XI(void)
{
	for(int i=0;i<=500;i++)
	{
		BUZZ7();
	}
}