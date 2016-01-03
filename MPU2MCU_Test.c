#define D_Round 0.2  //定义
#define pi 3.14159265358



#include <lights.h>


float wx,wy,wz,ax,ay,az;//raw data from MPU6050;quite likely that we won't use wy&ay though
float Roll ,Pitch ,Yaw=0;
 unsigned char Rebuf[11],counter=0,test=0x55;
 unsigned char sign;


void UartInit(void)		//115200bps@11.0592MHz
{
	EA=1;
	ES=1;
	SCON = 0x50;		//8位数据,可变波特率
//	AUXR &= 0xBF;		//定时器1时钟为Fosc/12,即12T
//	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x02;		//设定定时器1为16位自动重装方式
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时初值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	PCON = 0x00;
}
void main(){
	unsigned char LED;
LED=0x22;
P0=LED;//测试

UartInit();
while(1){
if(Yaw>20){LED=0x55;}
else{LED=0x88;}
}
P0=LED;
}


void ser() interrupt 4{ 
	P2=test;
	test++;
if(RI){
	RI=0;
	Rebuf[counter]=SBUF;	
	SBUF=Rebuf[counter];
		if(counter==0 && Rebuf[0]!=0x55) return;
		counter++;
		if(counter==11) {
			counter=0;
			switch(Rebuf [1]) {
			case 0x51:
				//检查帧头
				ax= ((Rebuf [3]<<8| Rebuf [2]))/32768.0*16; 
				ay= ((Rebuf [5]<<8| Rebuf [4]))/32768.0*16; 
				az= ((Rebuf [7]<<8| Rebuf [6]))/32768.0*16; 
				break;
			case 0x52:
				wx = ((Rebuf [3]<<8| Rebuf [2]))/32768.0*2000;
				wy = ((Rebuf [5]<<8| Rebuf [4]))/32768.0*2000; 
				wz = ((Rebuf [7]<<8| Rebuf [6]))/32768.0*2000;
				break;
			case 0x53: 
				Roll = ((Rebuf [3]<<8| Rebuf [2]))/32768.0*180; 
				Pitch = ((Rebuf [5]<<8| Rebuf [4]))/32768.0*180; 
				Yaw = ((Rebuf [7]<<8| Rebuf [6]))/32768.0*180; 
				break;
			}
		}
	}
if(TI){TI=0;}
}