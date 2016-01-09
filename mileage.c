#include "mileage.h"

unsigned char pattern_1[15]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F,0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE};
unsigned char pattern_2[16]={0x7E,0xBD,0xDB,0xE7,0xDB,0xBD,0x7E,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0xFF,0xFF};
int i=0,j=0,k=0;

void delay_1ms(int parameter);
void delay_10ms(int parameter);


void display_distance(int parameter){
	switch (parameter){
		case 1:  // distance 1 arrived
		if(i<15){		
		P0=pattern_1[i];		
		P1=pattern_1[i];		
		P2=pattern_1[i];
		delay_10ms(1);
		i++;}
		else{dis_flag_1=0;}
		break;
		
		case 2:  // distance 2 arrived
		if(j<16){
		P0=pattern_2[i];
		P1=pattern_2[i];
		P2=pattern_2[i];
		delay_1ms(7);
		}
		else{dis_flag_2=0;}
		break;
		
		case 3:  // distance 3 arrived
		if(k<15){
				if(AngleNew>0   &&  AngleNew<60)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);k++;return;}
				if(AngleNew>60  &&  AngleNew<120)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);k++;return;}
				if(AngleNew>120 &&  AngleNew<180)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);k++;return;}
				if(AngleNew>180 &&  AngleNew<240)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);k++;return;}
				if(AngleNew>240 &&  AngleNew<300)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);k++;return;}
				if(AngleNew>300 &&  AngleNew<360)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);k++;return;}
		}
		if(k>=15 && k<25){
		P0=0xFF;
		delay_1ms(6);
		k++;
		}
		if(k>=25 && k<40){
				if(AngleNew>0   &&  AngleNew<60)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);k++;return;}
				if(AngleNew>60  &&  AngleNew<120)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);k++;return;}
				if(AngleNew>120 &&  AngleNew<180)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);k++;return;}
				if(AngleNew>180 &&  AngleNew<240)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);k++;return;}
				if(AngleNew>240 &&  AngleNew<300)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);k++;return;}
				if(AngleNew>300 &&  AngleNew<360)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);k++;return;}
		}
		if(k>=40 && k<50){
		P0=0xFF;
		delay_1ms(6);
		k++;
		}
		if(k>=50){dis_flag_3=0;}
		break;
	}
}

