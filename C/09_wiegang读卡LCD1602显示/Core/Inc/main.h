/*******************************************************************************
 *名称：main.h
 *功能：main.c的头文件
 *******************************************************************************/
#ifndef __MAIN_H
#define __MAIN_H

/*******************************************************************************
 *包含头文件
 *******************************************************************************/
#include <REGX52.H>
#include "lcd.h"
#include "wiegand.h"

/*******************************************************************************
 *函数声明
 *******************************************************************************/
/*在51单片机12MHZ时钟下的延时函数*/
void udelay(uint num);
/*中断初始化*/
void initial(void);

#endif /* __MAIN_H */