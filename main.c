//考虑之后感觉应该用全局变量来记录里程，且一并放入Timer0()中；
#define D_Round 0.2  //定义
#define pi 3.14159265358

#include <lights.h>

float wx,wy,wz,ax,ay,az;
//raw data from MPU6050;quite likely that we won't use wy&ay though
float miles=0;

int main(){
	int turning_flag;
	EA=1;
	ET0=1;                   //计时器0用于测速
	ET1=1;                   //
	EX0=1;
	EX1=1;
	ES=1;
	Timer0intial();
	
	while(1){
		[wx,wy,wz,ax,ay,az]=read(MPU6050);            //读取数据的示意，具体代码参考MPU6050使用方法
		w=sqrt(wx^2+wy^2);                            //用于转向判断
		if(w>w0) turning_flag=1;
		if(turining_flag){
			//转向图案
		}
		
		
		Show_Pattern(wz);            		//显示图案为一个模块，这里只是示意
		if(miles < m1){
			do(Pattern(miles==m1) );
			Show_Pattern(wz);
			
		}
		
		if(miles < m2){
			do (Pattern);
			Show_Pattern();
		}
		
		if(miles < m3){
			
		}
		
	}
	
}

void Timer0() interrupt 1
{
	TH0= 0x3c;
	TL0= 0xB0;
	miles=miles+50*2*pi/wx*D_round; 
}