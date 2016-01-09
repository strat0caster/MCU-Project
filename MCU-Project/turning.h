#ifndef _TURNING_H_
#define _TURNING_H_
extern void turning_pattern(void);

extern bit dis_flag_1,dis_flag_2,dis_flag_3;
extern int AngleNew;
extern int code digital_angle[360];
	
void delay_50us(int times);
void delay_1ms(int times);
void delay_10ms(int times);
#include <reg51.h>
#endif