#define D_Round 0.2  //定义
#define pi 3.14159265358



#include <lights.h>


float wx,wy,wz,ax,ay,az;//raw data from MPU6050;quite likely that we won't use wy&ay though
float Roll ,Pitch ,Yaw=0;
 unsigned char Rebuf[11],counter;
 unsigned char sign;

void usart_rx_isr(void) interrupt 4 //USART 串行接收中断
 {
	Rebuf[counter]=SBUF;//不同单片机略有差异 
	if(counter==0&&Rebuf[0]!=0x55) 
		return; //第 0 号数据不是帧头,跳过

	counter++;
	if(counter==11) //接收到 11 个数据
	{
	counter=0; //重新赋值,准备下一帧数据的接收 
	sign=1;
		}
}


void main(){
P0=0x00;



REN=1;
PCON=0x80;
SM0=1;
SM1=0;

while(1){
	if(sign) {
		sign=0; 
		if(Rebuf[0]==0x55) {
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
	if(Yaw>10)
	P0=0xf0;
}

}


