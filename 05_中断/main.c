/*
05_中断
    功能
        逐行扫描，led显示出汉字或字母，当得到中断信号时，进行led显示翻转
    目的
        1 学习中断
*/

#include "reg52.h"   // 在reg52.h文件中已经定于过了RCLK,所以用reg51.h
#include <intrins.h> // 一般程序中需要使用到空指令_nop_();字符循环移位指令_crol_等时使用。

////////////////////////////////////////////////////////////////////////////////
typedef unsigned int u16;
typedef unsigned char u8;

sbit HC595_SRCLK = P3 ^ 6; // 74HC595位移寄存器时钟输入
sbit HC595_RCLK = P3 ^ 5;  // 74HC595储存寄存器时钟输入
sbit HC595_SER = P3 ^ 4;   // 74HC595串行数据输入

////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
* 函 数 名      : Delay
* 函数功能      : 延时函数
* 输    入      : unsigned int
* 输    出      : 
* 注            ：S = 0.00001T + 0.00002 = 1E-05x + 2E-05
*******************************************************************************/
void Delay(u16 i);
/*******************************************************************************
* 函 数 名      : Int0Init
* 函数功能      : 初始化中断0函数
* 输    入      : 
* 输    出      : 
*******************************************************************************/
void Int0Init();
/*******************************************************************************
* 函 数 名      : Int0
* 函数功能      : 中断0函数
* 输    入      : 
* 输    出      : 
*******************************************************************************/
void Int0() interrupt 0;
/*******************************************************************************
* 函 数 名      : LedLattice
* 函数功能      : led点阵显示函数,8*8的led点阵
* 输    入      : unsigned char
* 输    出      : 
*******************************************************************************/
void LedLattice(u8 led[], u16 t);

/*******************************************************************************
* 函 数 名      : main
* 函数功能      : 主函数
* 输    入      : 
* 输    出      : 
*******************************************************************************/
void main()
{
    u8 ledweiduan[16] = {0X80, 0X40, 0X20, 0X10, 0X08, 0X04, 0X02, 0X01,
                         0X00, 0X42, 0XE7, 0X42, 0X00, 0X81, 0X66, 0X3C}; // led位选8个和段选8个

    while (1)
    {
        LedLattice(ledweiduan, 85);
    }
}

void Delay(u16 i)
{
    while (i--)
        ;
}

void Int0Init()
{
    IT0 = 1;
    EX0 = 1;
    EA = 1;
}

void Int0() interrupt 0
{
    if ()
    {
    }
}

void LedLattice(u8 led[], u16 t)
{
    u8 i, j, tmep;

    for (i = 0; i < 8; i++) // 位选8次，一遍
    {
        tmep = led[i];
        P0 = 0XFF; // 消影

        for (j = 0; j < 8; j++) // 位选1次
        {
            HC595_SER = tmep >> 7;
            tmep <<= 1;

            HC595_SRCLK = 1;
            _nop_();
            _nop_();
            HC595_SRCLK = 0;
        }
        HC595_RCLK = 1;
        _nop_();
        _nop_();
        HC595_RCLK = 0;
        P0 = ~led[i + 8]; // 段选
        Delay(t);         // 延时控制频率HZ
    }
}

// 2021年8月24号02点00分