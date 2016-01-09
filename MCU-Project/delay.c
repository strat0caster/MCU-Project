#include "delay.h"
void delay_1ms(int times){
	unsigned char a,b;
	for(;times>0;times--){
		for(b=13;b>0;b--){
			for(a=33;a>0;a--);
		}
	}
}


void delay_10ms(int times){
	unsigned char a,b;
	for(;times>0;times--){
		for(b=40;b>0;b--){
			for(a=114;a>0;a--);
		}
	}
}
