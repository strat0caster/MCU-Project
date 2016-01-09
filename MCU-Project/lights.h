#ifndef _LIGHTS_H_
#define _LIGHTS_H_


//mainly just adding all sorts of header files in

#include <reg51.h>
#include <intrins.h>
#include <math.h>
#include "speeding.h"  // contains patterns for accelerating and slowing 
#include "mileage.h"   // contains functions for mileage patterns
#include "turning.h"   // contains patterns for turning
#include "delay.h"     // contains several delay functions

#endif




sfr AUXR=0x8E;
sfr T2CON=0xC8;
sfr RCAP2L=0xCA;
sfr RCAP2H=0xCB;
sfr TL2=0xCC;
sfr TH2=0xCD;

extern int Dist;
extern int AngleNew;
extern bit dis_flag_1,dis_flag_2,dis_flag_3;
extern int code digital_angle[360];

void turning_pattern();
void cruise_pattern();
void speeding_pattern();
void slowing_pattern();
void display_distance(int parameter);	
void UartInit();
