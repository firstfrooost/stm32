#include "stm32f10x.h"                  // Device header
#ifndef __HWSENSOR_H
#define __HWSENSOR_H

void HWSensor_Init(void);
uint8_t HWSensor_Get(void);
uint16_t CountSensor_Get(void);

#endif