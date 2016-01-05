<<<<<<< HEAD
#include <reg51.h>
#include <intrins.h>
sfr AUXR=0x8E;
sfr T2CON=0xC8;
sfr RCAP2L=0xCA;
sfr RCAP2H=0xCB;
sfr TL2=0xCC;
sfr TH2=0xCD;

int a[3],w[3],Angle[3]; 
//Angle[0]=Angle_X, Angle[1]=Angle_Y, Angle[2]=Angle_Z;
//Angle_Z directly determines where it is ON THE WHEEL.
int Receive_Buff[11];
unsigned char counter=0,test=0;
int low_8=0, high_8=0;

void main(void) {
	unsigned char LED;
	void UartInit();
	UartInit();
	while(1){
			if( Angle[0] >20000){
				LED=0x00;
			}
			else{
				LED=0xFF;
			}
			low_8=Angle[0] & 0xFF;
			high_8=(Angle[0]>>8)&0xFF;
			P1=low_8;
			P2=high_8;
			P0=LED;

	}

}



void UartInit(void)		//9600bps@11.0592MHz
{
	EA=1;
	ES=1;
/*/
	PCON&=0x7F;
	SCON=0x50;
	AUXR &= 0xBF;		
	AUXR &= 0xFE;		
	TMOD&=0x0F;
	TMOD|=0x20;
	TH1=0xFD;
	TL1=0xFD;
	ET1=0;
  TR1=1;
//以上为UART方式1，9600波特率；已经测试成功，可以收到并中断;TL1!!!!!
*/
	SCON = 0x50;		//8???,?????
	RCAP2L = 0xFD;
	RCAP2H = 0xFF;
	TL2 = 0xFD;		//??????
	TH2 = 0xFF;		//??????
	T2CON=0x34;

}

void ser() interrupt 4
{
	if (RI)
	{
		RI=0;	
		Receive_Buff[counter]=SBUF;	
		
	  if(counter==0&&Receive_Buff[0]!=0x55) return;      //第0号数据不是帧头
	  counter++; 
		
	  if(counter==11)             //接收到11个数据
	    {
	       counter=0;               //重新赋值，准备下一帧数据的接收        
		
			switch(Receive_Buff [1])
			{
//			case 0x51:
//			a[0]=(Receive_Buff[3]<<8|Receive_Buff[2])/32768.0*16;
//			a[1]=(Receive_Buff[5]<<8|Receive_Buff[4])/32768.0*16;
//			a[2]=(Receive_Buff[7]<<8|Receive_Buff[6])/32768.0*16;
//			break;
//			case 0x52:		
//			w[0]=(Receive_Buff[3]<<8|Receive_Buff[2])/32768.0*2000;
//			w[1]=(Receive_Buff[5]<<8|Receive_Buff[4])/32768.0*2000;
//			w[2]=(Receive_Buff[7]<<8|Receive_Buff[6])/32768.0*2000;
//			break;
			case 0x53: 
			Angle[0]=(Receive_Buff[3]<<8|Receive_Buff[2]);
//			Angle[1]=(Receive_Buff[5]<<8|Receive_Buff[4])/32768.0*180;
//			Angle[2]=(Receive_Buff[7]<<8|Receive_Buff[6])/32768.0*180;
			break;
			default: break;
			} 
	      }

	  }
	
		if(TI){TI=0;}
}


=======
#include <reg51.h>
#include <intrins.h>
sfr AUXR=0x8E;
sfr T2CON=0xC8;
sfr RCAP2L=0xCA;
sfr RCAP2H=0xCB;
sfr TL2=0xCC;
sfr TH2=0xCD;

int a[3],w[3],Angle[3]; 
//Angle[0]=Angle_X, Angle[1]=Angle_Y, Angle[2]=Angle_Z;
//Angle_Z directly determines where it is ON THE WHEEL.
unsigned char Receive_Buff[11];
unsigned char counter=0,test=0;
unsigned char low_8=0, high_8=0;


void main(void) {
	unsigned char LED;
	void UartInit();
	UartInit();
	while(1){
			if( Angle[2] >21800){
				LED=0x00;
			}
			else{
				LED=0xFF;
			}
			low_8=Angle[2] & 0xFF;
			high_8=(Angle[2]>>8)&0xFF;
			P0=LED;

	}

}



void UartInit(void)		//9600bps@11.0592MHz
{
	EA=1;
	ES=1;
/*/
	PCON&=0x7F;
	SCON=0x50;
	AUXR &= 0xBF;		
	AUXR &= 0xFE;		
	TMOD&=0x0F;
	TMOD|=0x20;
	TH1=0xFD;
	TL1=0xFD;
	ET1=0;
  TR1=1;
//以上为UART方式1，9600波特率；已经测试成功，可以收到并中断;TL1!!!!!
*/
	SCON = 0x50;		//8???,?????
	RCAP2L = 0xFD;
	RCAP2H = 0xFF;
	TL2 = 0xFD;		//??????
	TH2 = 0xFF;		//??????
	T2CON=0x34;

}

void ser() interrupt 4
{
	if (RI)
	{
		RI=0;	
		Receive_Buff[counter]=SBUF;	
		
	  if(counter==0&&Receive_Buff[0]!=0x55) return;      //第0号数据不是帧头
	  counter++; 
		
	  if(counter==11)             //接收到11个数据
	    {
	       counter=0;               //重新赋值，准备下一帧数据的接收        
		
			switch(Receive_Buff [1])
			{
//			case 0x51:
//			a[0]=(Receive_Buff[3]<<8|Receive_Buff[2])/32768.0*16;
//			a[1]=(Receive_Buff[5]<<8|Receive_Buff[4])/32768.0*16;
//			a[2]=(Receive_Buff[7]<<8|Receive_Buff[6])/32768.0*16;
//			break;
//			case 0x52:		
//			w[0]=(Receive_Buff[3]<<8|Receive_Buff[2])/32768.0*2000;
//			w[1]=(Receive_Buff[5]<<8|Receive_Buff[4])/32768.0*2000;
//			w[2]=(Receive_Buff[7]<<8|Receive_Buff[6])/32768.0*2000;
//			break;
			case 0x53: 
//			Angle[0]=(Receive_Buff[3]<<8|Receive_Buff[2])/32768.0*180;
			Angle[1]=(Receive_Buff[5]<<8|Receive_Buff[4])/32768.0*180;
//			Angle[2]=(Receive_Buff[7]<<8|Receive_Buff[6]);
			break;
			default: break;
			} 
	      }

	  }
	
		if(TI){TI=0;}
}


>>>>>>> origin/master
