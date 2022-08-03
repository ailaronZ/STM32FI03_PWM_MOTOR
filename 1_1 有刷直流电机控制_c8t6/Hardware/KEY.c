#include "stm32f10x.h"
#include "delay.h"
#include "key.h"

/*���ļ��ĺ�������Ҫʵ�־�����̵Ĺ��ܡ��������ʹ��PB8��PB15���ţ����У�PB8��PB11�̶�Ϊ
���������PB12��PB15�̶�Ϊ�������롣�����޼�����ʱ����ӦPB12��PB15Ϊ0���м�����ʱ��PB12��PB15�У�
��Ӧ������Ϊ�ߡ�*/
u8 KeyVal=0;	 //keyValΪ��󷵻صļ�ֵ��
	
void KEY_Init(void) //��ʼ���������Ҫʹ�õ�GPIO�ڡ�
{

 	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(KEY_Cmd,ENABLE);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //����PB8��PB11Ϊ�������롢����
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin  = KEY_GPIO1;
    GPIO_Init(GPIOX,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;       //����PB12��PB15Ϊ�������롣
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin  = KEY_GPIO2;
    //��Ϊ���涨������Ϊ���ʱ���Ѿ�������GPIOA��ʱ���ˣ�
	//���Դ˴�������Ҫ����RCC_APB2PeriphClockCmd()����ʱ���ˡ�
    GPIO_Init(GPIOX,&GPIO_InitStructure);		
}

int KEY_Scan() //ʵ�־�����̡�����ֵΪ���������ļ�ֵ���˼�ֵ���û��Լ����塣
{
	GPIO_Write(GPIOX,(GPIOX->ODR & 0xfff0 | 0x000f)); //����PB8��PB11ȫ������ߡ�
	
//	if((GPIOX->IDR & 0xf000)==0x0000)  //���PB12��PB15ȫΪ0����û�м����¡���ʱ������ֵΪ-1.
//		return -1;
//	else
//	{	
//	    Delay_ms(5);    //��ʱ5msȥ������
//	    if((GPIOX->IDR & 0xf000)==0x0000)//�����ʱ5ms��PB12��PB15��ȫΪ0���򣬸ղ����ŵĵ�λ�仯�Ƕ���������.
//	    return -1;
//	}

	GPIO_Write(GPIOX,(GPIOX->ODR & 0xfff0 | 0x0001));	//��PB11��PB8��������Ƶ�0001.

		switch(GPIOX->IDR & 0x00f0)//��PB12��PB15��ֵ�����жϣ��������ͬ�ļ�ֵ��
			{
				case 0x0010: KeyVal=13; break;
				case 0x0020: KeyVal=14;	break;
				case 0x0040: KeyVal=15;	break;
				case 0x0080: KeyVal=16;	break;
			}
	   
	GPIO_Write(GPIOX,(GPIOX->ODR & 0xfff0 | 0x0002));	//��PB11��PB8��������Ƶ�0.
		switch(GPIOX->IDR & 0x00f0)		        //��PB12��PB15��ֵ�����жϣ��������ͬ�ļ�ֵ��
		{
			case 0x0010: KeyVal=9;	break;
			case 0x0020: KeyVal=10;	break;
			case 0x0040: KeyVal=11;	break;
			case 0x0080: KeyVal=12;	break;
		}

	GPIO_Write(GPIOX,(GPIOX->ODR & 0xfff0 | 0x0004));	//��PB11��PB8��������Ƶ�1011.
		switch(GPIOX->IDR & 0x00f0)		        //��PB12��PB15��ֵ�����жϣ��������ͬ�ļ�ֵ��
		{
			case 0x0010: KeyVal=5;	break;
			case 0x0020: KeyVal=6;	break;
			case 0x0040: KeyVal=7;	break;
			case 0x0080: KeyVal=8;	break;
		}
 
	 GPIO_Write(GPIOX,(GPIOX->ODR & 0xfff0 | 0x0008));	//��PB11��PB8��������Ƶ�0111.
		switch(GPIOX->IDR & 0x00f0)		        //��PB12��PB15��ֵ�����жϣ��������ͬ�ļ�ֵ��
		{
			case 0x0010: KeyVal=1;	break;
			case 0x0020: KeyVal=2;	break;
			case 0x0040: KeyVal=3;	break;
			case 0x0080: KeyVal=4;	break;
		}			
		return 0;
}

