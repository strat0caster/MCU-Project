#ifndef _LIGHTS_H_
#define _LIGHTS_H_

//mainly just adding all sorts of header files in

#include <reg51.h>
#include <intrins.h>
#include <math.h>

//#include <MPU6050.h>
// downloaded already from github;

#include "speeding.h"
// speed obtaining module
// contains 

//#include <led.h>
// led pattern module
// contains functions for displaying different patterns.

#include "mileage.h"
// mileage module
// contains functions for mileage patterns

//#include <turning.h>
// turning status module
// contains turning status data obtaining and corresponding interrupt function


//#include <supersonic.h>
// reserved for the supersonic distance measuring and alarming module;
// only de-comment if progress allows 
// seems useless now

#include "delay.h"

//#include "bluetooth.h"

#endif

sfr AUXR=0x8E;
sfr T2CON=0xC8;
sfr RCAP2L=0xCA;
sfr RCAP2H=0xCB;
sfr TL2=0xCC;
sfr TH2=0xCD;

extern int Dist;
extern double AngleNew;

void turning_pattern();
void cruise_pattern();
void speeding_pattern();
void slowing_pattern();
void display_distance(int parameter);	
void UartInit();