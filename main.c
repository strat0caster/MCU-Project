//考虑之后感觉应该用全局变量来记录里程，且一并放入Timer0()中；
#define D_Round 0.2  //定义
#define pi 3.14159265358

#include <lights.h>

float wx,wy,wz,ax,ay,az;//raw data from MPU6050;quite likely that we won't use wy&ay though
float miles=0;
float delta_miles;

int main(){
	void UartInit();
	int turning_flag;
	UartInit();

/*	EA=1;
	ET0=1;                   //计时器0用于测速
	ET1=1;                   //
	EX0=1;
	EX1=1;
	ES=1;
	Timer0intial();
	*/

	while(1){						                  //20ms
		wz0=wz;
		[wx,wy,wz,ax,ay,az]=read(MPU6050);            //读取数据的示意，具体代码参考MPU6050使用方法
		w=sqrt(wx^2+wy^2);                            //用于转向判断
		if(w>w0) {
			turning_flag=1;
		}
		else if(wz-wz1>w1){									 //w1为快速加速阈值
			speeding_flag=1;
		}
		else if(wz0-wz>w2){  								  //w2为刹车阈值
			slowing_flag=1;
		}
/*		else if(miles>miles1&&mildes<miles1+dmiles){		//dmiles 决定闪烁时间长短
			miles_flag1=1;
		}

		else if(miles>miles1&&mildes<miles1+dmiles){		//dmiles 决定闪烁时间长短
			miles_flag2=1;
		}
		else if(miles>miles1&&mildes<miles1+dmiles){		//dmiles 决定闪烁时间长短
			miles_flag2=1;
		}
*/

		
		if(turining_flag){
			Turning_Pattern();
			turning_flag=0;
		}
		else if(slowing_flag){
			Slowing_Pattern();
			slowing_flag=0;
		}
		else if(miles_flag1){
			Miles_Pattern();
			miles_flag1=0;
		}
		else if(miles_flag2){
			Miles_Pattern();
			miles_flag2=0;
		}
		else{
			Cruise_Pattern();
		}
		
	}
	
}

/*void Timer0() interrupt 1
{
	TH0= 0x3c;
	TL0= 0xB0;
	delta_miles=50*2*pi/wz*D_round;
	miles=miles+delta_miles; 
}
*/

void UartInit(void)		//115200bps@11.0592MHz
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
以上为UART方式1，9600波特率*/
	SCON = 0x50;		//8???,?????
	RCAP2L = 0xFD;
	RCAP2H = 0xFF;
	TL2 = 0xFD;		//??????
	TH2 = 0xFF;		//??????
	T2CON=0x34;
//以上为T2定时器实现115200波特率
}

//在这里加入interrupt 4 中断函数