#define D_Round 0.2  //定义
#define pi 3.14159265358

#include <lights.h>

float wx,wy,wz,ax,ay,az;//raw data from MPU6050;quite likely that we won't use wy&ay though
float miles=0;
float delta_miles;

void Pattern_1(int start){
	Pattern_Cell(start,start+180,0xFF,0);
}

void Pattern_11(){
	for(i=0;i<36;i++){
		Pattern_Cell(i*10,4+i*10,0,1);
		Pattern_Cell(i*10,4+i*10,1,1);
		Pattern_Cell(i*10,4+i*10,2,1);
		Pattern_Cell(i*10,4+i*10,3,1);
	}
	for(i=0;i<72;i++){
		Pattern_Cell(i*5,4+i*5,4,1);
		Pattern_Cell(i*5,4+i*5,5,1);
		Pattern_Cell(i*5,4+i*5,6,1);
		Pattern_Cell(i*5,4+i*5,7,1);
	}
}