#include "turning.h"
double AngleNew;
void turning_display(void){
	if(AngleNew>0   && AngleNew<15)		{P1=0xFF;P2=0xFF;P0=0x9F;delay_1ms(1);P0=0x04;delay_1ms(2);P0=0x9F;delay(1ms)return;}
	if(AngleNew>15  && AngleNew<30)		{P0=0xFF;P2=0xFF;P1=0x9F;delay_1ms(1);P1=0x04;delay_1ms(2);P1=0x9F;delay(1ms)return;}
	if(AngleNew>30  && AngleNew<45)   {P0=0xFF;P1=0xFF;P2=0x9F;delay_1ms(1);P2=0x04;delay_1ms(2);P2=0x9F;delay(1ms)return;}
	if(AngleNew>45  && AngleNew<60)		{P1=0xFF;P2=0xFF;P0=0x9F;delay_1ms(1);P0=0x04;delay_1ms(2);P0=0x9F;delay(1ms)return;}
	if(AngleNew>60  && AngleNew>75)		{P0=0xFF;P2=0xFF;P1=0x9F;delay_1ms(1);P1=0x04;delay_1ms(2);P1=0x9F;delay(1ms)return;}
	if(AngleNew>75  && AngleNew<90)		{P0=0xFF;P1=0xFF;P2=0x9F;delay_1ms(1);P2=0x04;delay_1ms(2);P2=0x9F;delay(1ms)return;}
	if(AngleNew>90  && AngleNew<105)	{P1=0xFF;P2=0xFF;P0=0x9F;delay_1ms(1);P0=0x04;delay_1ms(2);P0=0x9F;delay(1ms)return;}
	if(AngleNew>105 && AngleNew<120)	{P0=0xFF;P2=0xFF;P1=0x9F;delay_1ms(1);P1=0x04;delay_1ms(2);P1=0x9F;delay(1ms)return;}
	if(AngleNew>120 && AngleNew<135)	{P0=0xFF;P1=0xFF;P2=0x9F;delay_1ms(1);P2=0x04;delay_1ms(2);P2=0x9F;delay(1ms)return;}
	if(AngleNew>135 && AngleNew<150)	{P1=0xFF;P2=0xFF;P0=0x9F;delay_1ms(1);P0=0x04;delay_1ms(2);P0=0x9F;delay(1ms)return;}
	if(AngleNew>150 && AngleNew<165)	{P0=0xFF;P2=0xFF;P1=0x9F;delay_1ms(1);P1=0x04;delay_1ms(2);P1=0x9F;delay(1ms)return;}
	if(AngleNew>165 && AngleNew<180)	{P0=0xFF;P1=0xFF;P2=0x9F;delay_1ms(1);P2=0x04;delay_1ms(2);P2=0x9F;delay(1ms)return;}
	if(AngleNew>180 && AngleNew<195)	{P1=0xFF;P2=0xFF;P0=0x9F;delay_1ms(1);P0=0x04;delay_1ms(2);P0=0x9F;delay(1ms)return;}
	if(AngleNew>195 && AngleNew<210)	{P0=0xFF;P2=0xFF;P1=0x9F;delay_1ms(1);P1=0x04;delay_1ms(2);P1=0x9F;delay(1ms)return;}
	if(AngleNew>210 && AngleNew<225)	{P0=0xFF;P1=0xFF;P2=0x9F;delay_1ms(1);P2=0x04;delay_1ms(2);P2=0x9F;delay(1ms)return;}
	if(AngleNew>225 && AngleNew<240)	{P1=0xFF;P2=0xFF;P0=0x9F;delay_1ms(1);P0=0x04;delay_1ms(2);P0=0x9F;delay(1ms)return;}
	if(AngleNew>240 && AngleNew<255)	{P0=0xFF;P2=0xFF;P1=0x9F;delay_1ms(1);P1=0x04;delay_1ms(2);P1=0x9F;delay(1ms)return;}
	if(AngleNew>255 && AngleNew<270)	{P0=0xFF;P1=0xFF;P2=0x9F;delay_1ms(1);P2=0x04;delay_1ms(2);P2=0x9F;delay(1ms)return;}
	if(AngleNew>270 && AngleNew<285)	{P1=0xFF;P2=0xFF;P0=0x9F;delay_1ms(1);P0=0x04;delay_1ms(2);P0=0x9F;delay(1ms)return;}
	if(AngleNew>285 && AngleNew<300)	{P0=0xFF;P2=0xFF;P1=0x9F;delay_1ms(1);P1=0x04;delay_1ms(2);P1=0x9F;delay(1ms)return;}
  if(AngleNew>300 && AngleNew<315)	{P0=0xFF;P1=0xFF;P2=0x9F;delay_1ms(1);P2=0x04;delay_1ms(2);P2=0x9F;delay(1ms)return;}
	if(AngleNew>315 && AngleNew<330)	{P1=0xFF;P2=0xFF;P0=0x9F;delay_1ms(1);P0=0x04;delay_1ms(2);P0=0x9F;delay(1ms)return;}
	if(AngleNew>330 && AngleNew<345)	{P0=0xFF;P2=0xFF;P1=0x9F;delay_1ms(1);P1=0x04;delay_1ms(2);P1=0x9F;delay(1ms)return;}
	if(AngleNew>345 && AngleNew<360)	{P0=0xFF;P1=0xFF;P2=0x9F;delay_1ms(1);P2=0x04;delay_1ms(2);P2=0x9F;delay(1ms)return;}
}
//�뻭����̾��
//��̾���ڳ����Ϲ̶�λ��
//����15��������Ϊ����3r/s��ʱ��10ms��Լת��10�㡣Ϊ�˱�֤���ȣ�����15�ȼ����