#ifndef __KEY_H
#define __KEY_H 	
#include "stm32f10x.h"

#define KEY_Cmd      RCC_APB2Periph_GPIOA
#define KEY_GPIO1    GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_10|GPIO_Pin_3
#define KEY_GPIO2    GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7
#define GPIOX        GPIOA

void KEY_Init(void) ;
int KEY_Scan(void);
extern u8 KeyVal;


#endif	

