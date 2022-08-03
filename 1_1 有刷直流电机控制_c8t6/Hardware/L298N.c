//#include "stm32f10x.h"                  // Device header
//#include "L298N.h"  


//void L298N_Init(void)
//{
//	RCC_APB2PeriphClockCmd(L298N_Cmd, ENABLE);
//	
//	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Pin = ENA1 | IN_C | IN_D;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOX, &GPIO_InitStructure);
//	
//	GPIO_ResetBits(GPIOX,  ENA1 | IN_C | IN_D);
//}

//void L298N_ON(void)
//{
//	GPIO_SetBits(GPIOX, ENA1);
//}

//void L298N_OFF(void)
//{
//	GPIO_ResetBits(GPIOX, ENA1);
//}

//void L298N_F(void)
//{
//	GPIO_SetBits(GPIOX, IN_C);
//	GPIO_ResetBits(GPIOX, IN_D);
//}

//void L298N_R(void)
//{
//	GPIO_SetBits(GPIOX, IN_D);
//	GPIO_ResetBits(GPIOX, IN_C);
//}