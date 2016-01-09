#ifndef _SPEEDING_H_
#define _SPEEDING_H_
extern void speeding_pattern(void);
extern void slowing_pattern(void);
extern int AngleNew;
extern bit dis_flag_1,dis_flag_2,dis_flag_3;
void delay_50us(int times);
void delay_1ms(int times);
void delay_10ms(int times);
#include <reg51.h>
#endif