//����֮��о�Ӧ����ȫ�ֱ�������¼��̣���һ������Timer0()�У�
#define D_Round 0.2  //����
#define pi 3.14159265358

#include <lights.h>

float wx,wy,wz,ax,ay,az;
//raw data from MPU6050;quite likely that we won't use wy&ay though
float miles=0;

int main(){
	int turning_flag;
	EA=1;
	ET0=1;                   //��ʱ��0���ڲ���
	ET1=1;                   //
	EX0=1;
	EX1=1;
	ES=1;
	Timer0intial();
	
	while(1){
		[wx,wy,wz,ax,ay,az]=read(MPU6050);            //��ȡ���ݵ�ʾ�⣬�������ο�MPU6050ʹ�÷���
		w=sqrt(wx^2+wy^2);                            //����ת���ж�
		if(w>w0) turning_flag=1;
		if(turining_flag){
			//ת��ͼ��
		}
		
		
		Show_Pattern(wz);            		//��ʾͼ��Ϊһ��ģ�飬����ֻ��ʾ��
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