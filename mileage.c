#include "mileage.h"

void delay_10ms(int times){
	unsigned char a,b;
	for(;times>0;times--){
		for(b=40;b>0;b--){
			for(a=114;a>0;a--);
		}
	}
}


void display_distance(int parameter){
	switch (parameter){
		unsigned char a,b,c;
		
		case 1:  // distance 1 arrived
		P0=0x01;		delay_10ms(10);
		P0=0x02;		delay_10ms(10);
		P0=0x04;		delay_10ms(10);
		P0=0x08;		delay_10ms(10);
		P0=0x10;		delay_10ms(10);
		P0=0x20;		delay_10ms(10);
		P0=0x40;		delay_10ms(10);
		P0=0x80;		delay_10ms(10);
		P0=0x40;		delay_10ms(10);
		P0=0x20;		delay_10ms(10);
		P0=0x10;		delay_10ms(10);
		P0=0x08;		delay_10ms(10);
		P0=0x04;		delay_10ms(10);
		P0=0x02;		delay_10ms(10);
		P0=0x01;		delay_10ms(10);
		
		case 2:  // distance 2 arrived
		P0=0x81;		delay_10ms(10);
		P0=0x42;		delay_10ms(10);
		P0=0x24;		delay_10ms(10);
		P0=0x18;		delay_10ms(10);
		P0=0x24;		delay_10ms(10);
		P0=0x42;		delay_10ms(10);
		P0=0x81;		delay_10ms(10);
		P0=0x00;		delay_10ms(30);
		P0=0xFF;		delay_10ms(10);
		P0=0x00;		delay_10ms(10);
		P0=0xFF;		delay_10ms(10);
		P0=0x00;		delay_10ms(10);
		P0=0xFF;		delay_10ms(10);
		P0=0x00;		delay_10ms(40);
		
		case 3:  // distance 3 arrived
		for(c=80;c>0;c--){
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
		for(c=330;c>0;c--){
			for(b=40;b>0;b--){
				for(a=114;a>0;a--);
			}
		}
		for(c=80;c>0;c--){
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
		for(c=330;c>0;c--){
			for(b=40;b>0;b--){
				for(a=114;a>0;a--);
			}
		}
	
	
	}
	
}



void mile_display(){
		if(Dist==20) display_distance(1);
		if(Dist==40) display_distance(2);
		if(Dist==60) display_distance(3);
}
