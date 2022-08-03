#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "L298N.h"
#include "Oled.h"
#include "Key.h"
#include "Motor.h"
//#include "Limit.h"

extern u8 KeyVal;
int main(void)
{
//	L298N_Init();
//	L298N_ON();
	OLED_Init();
	KEY_Init();
	Motor_Init();
//	Motor_ON();
//	KEY_Scan();
//	OLED_ShowChar(1, 1, 'A');
	OLED_ShowString(1, 1, "Speed:");
//	OLED_ShowNum(2, 1, 12345, 5);
//	OLED_ShowSignedNum(2, 7, -66, 2);
//	OLED_ShowHexNum(3, 1, 0xAA55, 4);
//	OLED_ShowBinNum(4, 1, 0xAA55, 16);
		int8_t speed,KeyNum=0;
		
	while (1)
	{
		KEY_Scan();
		KeyNum=KeyVal;
//		limit_ab(speed,50,60);
		
//		OLED_ShowNum(1, 8, speed, 3);
		OLED_ShowSignedNum(1, 8, speed, 3);
		OLED_ShowSignedNum(2, 8, KeyNum, 3);
		if(KeyNum==1){speed=50;Delay_ms(10);KeyNum=0;}
		
		
		
		if(KeyNum==2){speed=speed++;Delay_ms(10);KeyNum=0;}


		
		
		
		if(KeyVal==3)
			speed=speed-5;
		if(KeyVal==4)
			speed=0;
		if(KeyVal==9)
			speed=60;
		if(KeyVal==10)
			speed=70;
		if(KeyVal==11)
			speed=80;
		if(KeyVal==12)
			speed=90;
		if(KeyVal==13)
			speed=100;
		if(KeyVal==14)
			speed=-100;		

					
		
		
		
		Motor_SetSpeed(speed);
		
		
/*****************************************°´¼ü²âÊÔ**************************************/		
//		if(KeyVal==1)
//		{
//			L298N_ON();
//			GPIO_ResetBits(GPIOX, IN_C | IN_D);
//		}
//		
//		if(KeyVal==2)
//			L298N_F();
//		
//		if(KeyVal==3)
//			L298N_R();
//		
//		if(KeyVal==4)
//			L298N_OFF();	
//		
	/************************¼òÒ×PWM**************************************************/
//			for(TIME=0;TIME<20;TIME++)
//		{
//			for(i=0;i<10;i++)
//			{
//				L298N_OFF();
//			Delay_ms(TIME);
//				L298N_ON();
//				L298N_F();
//			Delay_ms(20-TIME);
//			}
//		
//		}
//		for(TIME=0;TIME<20;TIME++)
//		{
//			for(i=0;i<10;i++)
//			{
//				L298N_OFF();
//			Delay_ms(20-TIME);
//				L298N_ON();
//				L298N_F();
//			Delay_ms(TIME);
//			}
//		
//		}
/******************************************************************************************/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	}
}
