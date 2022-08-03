/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		FUN
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		ADS v1.2.2
 * @Target core		TC264D
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-3-23
 ********************************************************************************************************************/



#include "stm32f10x.h"                  // Device header



////-------------------------------------------------------------------------------------------------------------------
////  @brief      绝对值函数
////  @param      dat				需要求绝对值的数
////  @return     int				返回绝对值
////  Sample usage:				dat = myabs(dat);//将dat变成正数
////-------------------------------------------------------------------------------------------------------------------
//int  myabs(int dat)
//{
//    if(dat>=0)  return dat;
//    else        return -dat;
//}


////-------------------------------------------------------------------------------------------------------------------
////  @brief      软件延时
////  @param      t				延时时间
////  @return     void			
////  Sample usage:				
////-------------------------------------------------------------------------------------------------------------------
//void my_delay(long t)
//{
//    while(t--);
//}


////-------------------------------------------------------------------------------------------------------------------
////  @brief      限幅
////  @param      x				被限幅的数据
////  @param      y				限幅范围(数据会被限制在-y至+y之间)
////  @return     float			限幅之后的数据			
////  Sample usage:				float dat = limit(500,300);//数据被限制在-300至+300之间  因此返回的结果是300
////-------------------------------------------------------------------------------------------------------------------
//float limit(float x, int32 y)
//{
//    if(x>y)             return (float)y;
//    else if(x<-y)       return (float)(-y);
//    else                return x;
//}


////-------------------------------------------------------------------------------------------------------------------
////  @brief      双边限幅
////  @param      x				被限幅的数据
////  @param      a				限幅范围左边界
////  @param      b				限幅范围右边界
////  @return     float			限幅之后的数据			
////  Sample usage:				int16 dat = limit_ab(500,-300，400);//数据被限制在-300至+400之间  因此返回的结果是400
////-------------------------------------------------------------------------------------------------------------------
u16 limit_ab(u16 x, u16 a, u16 b)
{
    if(x<a) x = a;
    if(x>b) x = b;
    return x;
}

