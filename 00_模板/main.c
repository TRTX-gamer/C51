/*
00_模板
    功能
        
    目的

*/

#include "reg52.h"

////////////////////////////////////////////////////////////////////////////////
typedef unsigned int u16;
typedef unsigned char u8;

////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
* 函 数 名      : Delay
* 函数功能      : 延时函数
* 输    入      : unsigned int
* 输    出      : 
* 注            ：S = 0.00001T + 0.00002 = 1E-05x + 2E-05
*******************************************************************************/
void Delay(u16 i)
{
    while (i--)
        ;
}

/*******************************************************************************
* 函 数 名      : main
* 函数功能      : 主函数
* 输    入      : 
* 输    出      : 
*******************************************************************************/
void main()
{
}

// 2021年8月10号17点04分