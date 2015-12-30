#include <reg51.h>
#define NUM 3	//LED模组数

int LED[3]={0,120,240}	  ;//表示LED的位置
float Yaw;
int C1[8]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};

unsigned char C,D;

/*兼容ANSIC标准的数据类型可通过指针访问，
但扩展的bit、sbit、sfr和sfrl6数据类型专用于访问80C51的特殊功能寄存器，
故不能通过指针进行访问。
*/

//A,B确定点亮的角度 C实现一个灯组中的8只LED分别控制 D为模式选择
void Pattern_Cell(int A,int B,unsigned char C,unsigned char D)
{
	int i;
	for(i=0;i<NUM;i++){
		LED[i]=Yaw+i*360/NUM+180;
		for(;LED[i]<0||LED[i]>=360;)
			LED[i]-=360;		//控制所有坐标在-180到180之间
	}

	//D=1时整组调整
	if(D==1){
		if(LED[0]>=A&&LED[0]<B)
			P0=C;
		else
			P0=0xFF;

		if(LED[1]>=A&&LED[1]<B)
			P1=C;
		else
			P1=0xFF;

		if(LED[2]>=A&&LED[2]<B)
			P2=C;
		else
			P2=0xFF;
	}

	//D=0时分个单独调整
	else if(D==0){
		
		if(LED[0]>=A&&LED[0]<B)
			P0=C1[C];
		else
			P0=0xFF;

		if(LED[1]>=A&&LED[1]<B)
			P1=C1[C];
		else
			P1=0xFF;

		if(LED[2]>=A&&LED[2]<B)
			P2=C1[C];
		else
			P2=0xFF;
	}

}

int main()
{
	YawH=0;
	YawL=0;
	while(1){
		Pattern_Cell(-30,30,3,0);
	}
}