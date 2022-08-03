#include "stm32f10x.h"
#include "delay.h"
#include "key.h"

/*本文件的函数，主要实现矩阵键盘的功能。矩阵键盘使用PB8到PB15引脚，其中，PB8到PB11固定为
推挽输出，PB12到PB15固定为下拉输入。即，无键按下时，对应PB12到PB15为0，有键按下时，PB12到PB15中，
对应的引脚为高。*/
u8 KeyVal=0;	 //keyVal为最后返回的键值。
	
void KEY_Init(void) //初始化矩阵键盘要使用的GPIO口。
{

 	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(KEY_Cmd,ENABLE);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //定义PB8到PB11为上拉输入、、。
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin  = KEY_GPIO1;
    GPIO_Init(GPIOX,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;       //定义PB12到PB15为下拉输入。
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin  = KEY_GPIO2;
    //因为上面定义引脚为输出时，已经打开整个GPIOA的时钟了，
	//所以此处不再需要函数RCC_APB2PeriphClockCmd()来打开时钟了。
    GPIO_Init(GPIOX,&GPIO_InitStructure);		
}

int KEY_Scan() //实现矩阵键盘。返回值为，各按键的键值，此键值由用户自己定义。
{
	GPIO_Write(GPIOX,(GPIOX->ODR & 0xfff0 | 0x000f)); //先让PB8到PB11全部输出高。
	
//	if((GPIOX->IDR & 0xf000)==0x0000)  //如果PB12到PB15全为0，则没有键按下。此时，返回值为-1.
//		return -1;
//	else
//	{	
//	    Delay_ms(5);    //延时5ms去抖动。
//	    if((GPIOX->IDR & 0xf000)==0x0000)//如果延时5ms后，PB12到PB15又全为0，则，刚才引脚的电位变化是抖动产生的.
//	    return -1;
//	}

	GPIO_Write(GPIOX,(GPIOX->ODR & 0xfff0 | 0x0001));	//让PB11到PB8输出二进制的0001.

		switch(GPIOX->IDR & 0x00f0)//对PB12到PB15的值进行判断，以输出不同的键值。
			{
				case 0x0010: KeyVal=13; break;
				case 0x0020: KeyVal=14;	break;
				case 0x0040: KeyVal=15;	break;
				case 0x0080: KeyVal=16;	break;
			}
	   
	GPIO_Write(GPIOX,(GPIOX->ODR & 0xfff0 | 0x0002));	//让PB11到PB8输出二进制的0.
		switch(GPIOX->IDR & 0x00f0)		        //对PB12到PB15的值进行判断，以输出不同的键值。
		{
			case 0x0010: KeyVal=9;	break;
			case 0x0020: KeyVal=10;	break;
			case 0x0040: KeyVal=11;	break;
			case 0x0080: KeyVal=12;	break;
		}

	GPIO_Write(GPIOX,(GPIOX->ODR & 0xfff0 | 0x0004));	//让PB11到PB8输出二进制的1011.
		switch(GPIOX->IDR & 0x00f0)		        //对PB12到PB15的值进行判断，以输出不同的键值。
		{
			case 0x0010: KeyVal=5;	break;
			case 0x0020: KeyVal=6;	break;
			case 0x0040: KeyVal=7;	break;
			case 0x0080: KeyVal=8;	break;
		}
 
	 GPIO_Write(GPIOX,(GPIOX->ODR & 0xfff0 | 0x0008));	//让PB11到PB8输出二进制的0111.
		switch(GPIOX->IDR & 0x00f0)		        //对PB12到PB15的值进行判断，以输出不同的键值。
		{
			case 0x0010: KeyVal=1;	break;
			case 0x0020: KeyVal=2;	break;
			case 0x0040: KeyVal=3;	break;
			case 0x0080: KeyVal=4;	break;
		}			
		return 0;
}

