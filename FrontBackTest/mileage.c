#include "mileage.h"

double AngleNew;
int Dist;




void display_distance(int parameter){
	switch (parameter){
		unsigned char a,b,c;
		
		case 1:  // distance 1 arrived
		P0=0xFE;		delay_10ms(10);
		P0=0xFD;		delay_10ms(10);
		P0=0xFB;		delay_10ms(10);
		P0=0xF7;		delay_10ms(10);
		P0=0xEF;		delay_10ms(10);
		P0=0xDF;		delay_10ms(10);
		P0=0xBF;		delay_10ms(10);
		P0=0x7F;		delay_10ms(10);
		P0=0xBF;		delay_10ms(10);
		P0=0xDF;		delay_10ms(10);
		P0=0xEF;		delay_10ms(10);
		P0=0xF7;		delay_10ms(10);
		P0=0xFB;		delay_10ms(10);
		P0=0xFD;		delay_10ms(10);
		P0=0xFE;		delay_10ms(10);
		break;
		
		case 2:  // distance 2 arrived
		P0=0x7E;		delay_10ms(10);
		P0=0xBD;		delay_10ms(10);
		P0=0xDB;		delay_10ms(10);
		P0=0xE7;		delay_10ms(10);
		P0=0xDB;		delay_10ms(10);
		P0=0xBD;		delay_10ms(10);
		P0=0x7E;		delay_10ms(10);
		P0=0xFF;		delay_10ms(30);
		P0=0x00;		delay_10ms(10);
		P0=0xFF;		delay_10ms(10);
		P0=0x00;		delay_10ms(10);
		P0=0xFF;		delay_10ms(10);
		P0=0x00;		delay_10ms(10);
		P0=0xFF;		delay_10ms(40);
		break;
		
		case 3:  // distance 3 arrived
		for(c=10;c>0;c--){
			for(b=40;b>0;b--){
				for(a=114;a>0;a--){
					if(AngleNew>0   &&  AngleNew<60)	{P0=0x00;P1=0x00;P2=0x00;}
					if(AngleNew>60  &&  AngleNew<120)	{P0=0xF3;P1=0xF3;P2=0xF3;}
					if(AngleNew>120 &&  AngleNew<180)	{P0=0x00;P1=0x00;P2=0x00;}
					if(AngleNew>180 &&  AngleNew<240)	{P0=0xF3;P1=0xF3;P2=0xF3;}
					if(AngleNew>240 &&  AngleNew<300)	{P0=0x00;P1=0x00;P2=0x00;}
					if(AngleNew>300 &&  AngleNew<360)	{P0=0xF3;P1=0xF3;P2=0xF3;}
				}
			}
		}
		P0=0x00;
		for(c=33;c>0;c--){
			for(b=40;b>0;b--){
				for(a=114;a>0;a--);
			}
		}
		for(c=10;c>0;c--){
			for(b=40;b>0;b--){
				for(a=114;a>0;a--){
					if(AngleNew>0   &&  AngleNew<60)	{P0=0xFF;P1=0xFF;P2=0xFF;}
					if(AngleNew>60  &&  AngleNew<120)	{P0=0x0C;P1=0x0C;P2=0x0C;}
					if(AngleNew>120 &&  AngleNew<180)	{P0=0xFF;P1=0xFF;P2=0xFF;}
					if(AngleNew>180 &&  AngleNew<240)	{P0=0x0C;P1=0x0C;P2=0x0C;}
					if(AngleNew>240 &&  AngleNew<300)	{P0=0xFF;P1=0xFF;P2=0xFF;}
					if(AngleNew>300 &&  AngleNew<360)	{P0=0x0C;P1=0x0C;P2=0x0C;}

				}
			}
		}
		P0=0x00;
		for(c=33;c>0;c--){
			for(b=40;b>0;b--){
				for(a=114;a>0;a--);
			}
		}
		break;
		default : break;
	
	}
	
}



void mile_display(){
		if(Dist==20) display_distance(1);
		if(Dist==40) display_distance(2);
		if(Dist==60) display_distance(3);
}
