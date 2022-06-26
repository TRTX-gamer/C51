/*
09_wiegang读卡LCD1602显示
    功能
        通过读卡器读卡，LCD1602显示信息
    目的
        练习LCD显示，读卡器的使用
*/
#include <REGX52.H>

////////////////////////////////////////////////////////////////////////////////
typedef unsigned int u16;
typedef unsigned char u8;

////////////////////////////////////////////////////////////////////////////////

/******************************************************************************
 *函数名称：main( )
 *函数功能：主函数
 *入口函数：无
 *出口函数：无
 ****************************************************************************/
void main()
{
    while (1)
    {
        initial();
        rf_card->global_var = 0;
        //等待中断
    }
}

/******************************************************************************
 *函数名称：Wiegand_Data0( )
 *函数功能：韦根卡数据0中断处理
 *入口函数：无
 *出口函数：无
 ******************************************************************************/
void Wiegand_Data0() interrupt 0 using 1 //中断0处理函数,使用第一组寄存器，main函数使用0组寄存器，写好寄存器组可以省去寄存器入栈，提高速度
{
    EX0 = 0; //关中断0
    udelay(5);
    if (DATA0 == 0) //如果INT0为低，标示0线中断
    {
        rf_card->wiegand[rf_card->global_var] = '0'; //往数组里填0
        rf_card->global_var = rf_card->global_var + 1;
    }
    udelay(500);  //延时1500uS（去掉中断后的处理时间）
    EX0 = 1;      //开中断0
    udelay(2500); //延时2500uS(max值，去掉前期处理时间)
}

/******************************************************************************
 *函数名称：Wiegand_Data1( )
 *函数功能：韦根卡数据1中断处理
 *入口函数：无
 *出口函数：无
 ******************************************************************************/
void Wiegand_Data1() interrupt 2 using 2 //中断1处理函数,使用第二组寄存器
{
    EX1 = 0; //关中断1
    udelay(5);
    if (DATA1 == 0)
    {
        rf_card->wiegand[rf_card->global_var] = '1';
        rf_card->global_var = rf_card->global_var + 1;
    }
    udelay(500);
    EX1 = 1; //开中断0
}

// 2022年6月26号11点35分