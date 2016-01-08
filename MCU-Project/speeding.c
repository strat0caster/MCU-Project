#include "speeding.h"
unsigned char acc_pattern_value[7]={0x3C,0x99,0xC3,0xE7,0xFF,0xFF,0xFF};
unsigned char slow_pattern_value[0x24,0x99,];
int S_P_i=0,L_P_i=0;

void speeding_pattern(void){
	if(S_P_i<7){
		P0=acc_pattern_value[S_P_i];
		P1=acc_pattern_value[S_P_i];
		P2=acc_pattern_value[S_P_i];
		S_P_i++;
	}	else{S_P_i=0;}
	
}

void slowing_pattern(void){
	
}