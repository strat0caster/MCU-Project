//����֮��о�Ӧ����ȫ�ֱ�������¼��̣���һ������Timer0()�У�
#define D_Round 0.2  //����
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
	ET0=1;                   //��ʱ��0���ڲ���
	ET1=1;                   //
	EX0=1;
	EX1=1;
	ES=1;
	Timer0intial();
	*/

	while(1){						                  //20ms
		wz0=wz;
		[wx,wy,wz,ax,ay,az]=read(MPU6050);            //��ȡ���ݵ�ʾ�⣬�������ο�MPU6050ʹ�÷���
		w=sqrt(wx^2+wy^2);                            //����ת���ж�
		if(w>w0) {
			turning_flag=1;
		}
		else if(wz-wz1>w1){									 //w1Ϊ���ټ�����ֵ
			speeding_flag=1;
		}
		else if(wz0-wz>w2){  								  //w2Ϊɲ����ֵ
			slowing_flag=1;
		}
/*		else if(miles>miles1&&mildes<miles1+dmiles){		//dmiles ������˸ʱ�䳤��
			miles_flag1=1;
		}

		else if(miles>miles1&&mildes<miles1+dmiles){		//dmiles ������˸ʱ�䳤��
			miles_flag2=1;
		}
		else if(miles>miles1&&mildes<miles1+dmiles){		//dmiles ������˸ʱ�䳤��
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
����ΪUART��ʽ1��9600������*/
	SCON = 0x50;		//8???,?????
	RCAP2L = 0xFD;
	RCAP2H = 0xFF;
	TL2 = 0xFD;		//??????
	TH2 = 0xFF;		//??????
	T2CON=0x34;
//����ΪT2��ʱ��ʵ��115200������
}

//���������interrupt 4 �жϺ���