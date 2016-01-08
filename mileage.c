#include "mileage.h"

unsigned char pattern_1[15]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F,0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE};
unsigned char pattern_2[16]={0x7E,0xBD,0xDB,0xE7,0xDB,0xBD,0x7E,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0xFF,0xFF};
int M_i_1=0,M_i_2=0,M_i_3=0;



void display_distance(int parameter){
	switch (parameter){
		case 1:  // distance 1 arrived
		if(M_i_1<15){		
		P0=pattern_1[M_i_1];		
		P1=pattern_1[M_i_1];		
		P2=pattern_1[M_i_1];
		delay_10ms(1);
		M_i_1++;}
		else{dis_flag_1=0;}
		break;
		
		case 2:  // distance 2 arrived
		if(M_i_2<16){
		P0=pattern_2[M_i_2];
		P1=pattern_2[M_i_2];
		P2=pattern_2[M_i_2];
		delay_1ms(7);
		M_i_2++;
		}
		else{dis_flag_2=0;}
		break;
		
		case 3:  // distance 3 arrived
		if(M_i_3<15){
				if(AngleNew>0   &&  AngleNew<60)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);M_i_3++;return;}
				if(AngleNew>60  &&  AngleNew<120)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);M_i_3++;return;}
				if(AngleNew>120 &&  AngleNew<180)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);M_i_3++;return;}
				if(AngleNew>180 &&  AngleNew<240)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);M_i_3++;return;}
				if(AngleNew>240 &&  AngleNew<300)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);M_i_3++;return;}
				if(AngleNew>300 &&  AngleNew<360)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);M_i_3++;return;}
		}
		if(M_i_3>=15 && M_i_3<25){
		P0=0xFF;
		delay_1ms(6);
		M_i_3++;
		}
		if(M_i_3>=25 && M_i_3<40){
				if(AngleNew>0   &&  AngleNew<60)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);M_i_3++;return;}
				if(AngleNew>60  &&  AngleNew<120)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);M_i_3++;return;}
				if(AngleNew>120 &&  AngleNew<180)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);M_i_3++;return;}
				if(AngleNew>180 &&  AngleNew<240)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);M_i_3++;return;}
				if(AngleNew>240 &&  AngleNew<300)	{P0=0xFF;P1=0xFF;P2=0xFF;delay_1ms(5);M_i_3++;return;}
				if(AngleNew>300 &&  AngleNew<360)	{P0=0x0C;P1=0x0C;P2=0x0C;delay_1ms(5);M_i_3++;return;}
		}
		if(M_i_3>=40 && M_i_3<50){
		P0=0xFF;
		delay_1ms(6);
		M_i_3++;
		}
		if(M_i_3>=50){dis_flag_3=0;}
		break;
	}
}

