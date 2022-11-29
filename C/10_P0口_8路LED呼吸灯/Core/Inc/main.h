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


////////////////////////////////////////////////////////////////////////////////
typedef unsigned int u16;
typedef unsigned char u8;

void Timer0_Init(u8 x);
void LEDCycle_PWM_task(void);

#endif /* __MAIN_H */