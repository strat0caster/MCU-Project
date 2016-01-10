#include "speeding.h"
#define acc_pattern_length 12
#define slow_pattern_length 12
//unsigned char acc_pattern_value[acc_pattern_length]={0x3C,0x99,0xC3,0xE7,0xE7,0xFF,0xFF,0xFF};
unsigned char acc_pattern_value[acc_pattern_length]={0x00,0x00,0x7e,0x3c,0x18,0x00,0x00,0x81,0xc3,0xe7,0x00,0x00};
unsigned char slow_pattern_value[acc_pattern_length]={0x00,0x00,0xe7,0xc3,0x81,0x00,0x00,0x18,0x3c,0x7e,0x00,0x00};
int S_P_i=0,L_P_i=0;


void speeding_pattern(void){
	if(dis_flag_1){dis_flag_1=0;};
	if(dis_flag_2){dis_flag_2=0;};
	if(dis_flag_3){dis_flag_3=0;};
	if(S_P_i<acc_pattern_length){
		P0=acc_pattern_value[S_P_i];
		P1=acc_pattern_value[S_P_i];
		P2=acc_pattern_value[S_P_i];
		S_P_i++;
		delay_50us(1);
	}	else{S_P_i=0;}
	
}

void slowing_pattern(void){	
	if(dis_flag_1){dis_flag_1=0;};
	if(dis_flag_2){dis_flag_2=0;};
	if(dis_flag_3){dis_flag_3=0;};
		if(L_P_i<slow_pattern_length){
		P0=slow_pattern_value[L_P_i];
		P1=slow_pattern_value[L_P_i];
		P2=slow_pattern_value[L_P_i];
		L_P_i++;
		delay_50us(1);
	}	else{L_P_i=0;}
}