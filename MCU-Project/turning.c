#include "turning.h"


void turning_pattern(void){
	if(dis_flag_1){dis_flag_1=0;};
	if(dis_flag_2){dis_flag_2=0;};
	if(dis_flag_3){dis_flag_3=0;};
	if(AngleNew>0   && AngleNew<15)		{P1=0xFF;P2=0xFF;P0=0xF9;delay_50us(10);P0=0x20;delay_1ms(1);P0=0xF9;delay_50us(10);P0=0xFF;return;}
	if(AngleNew>15  && AngleNew<30)		{P0=0xFF;P2=0xFF;P1=0xF9;delay_50us(10);P1=0x20;delay_1ms(1);P1=0xF9;delay_50us(10);P1=0xFF;return;}
	if(AngleNew>30  && AngleNew<45)   {P0=0xFF;P1=0xFF;P2=0xF9;delay_50us(10);P2=0x20;delay_1ms(1);P2=0xF9;delay_50us(10);P2=0xFF;return;}
	if(AngleNew>45  && AngleNew<60)		{P1=0xFF;P2=0xFF;P0=0xF9;delay_50us(10);P0=0x20;delay_1ms(1);P0=0xF9;delay_50us(10);P0=0xFF;return;}
	if(AngleNew>60  && AngleNew>75)		{P0=0xFF;P2=0xFF;P1=0xF9;delay_50us(10);P1=0x20;delay_1ms(1);P1=0xF9;delay_50us(10);P1=0xFF;return;}
	if(AngleNew>75  && AngleNew<90)		{P0=0xFF;P1=0xFF;P2=0xF9;delay_50us(10);P2=0x20;delay_1ms(1);P2=0xF9;delay_50us(10);P2=0xFF;return;}
	if(AngleNew>90  && AngleNew<105)	{P1=0xFF;P2=0xFF;P0=0xF9;delay_50us(10);P0=0x20;delay_1ms(1);P0=0xF9;delay_50us(10);P0=0xFF;return;}
	if(AngleNew>105 && AngleNew<120)	{P0=0xFF;P2=0xFF;P1=0xF9;delay_50us(10);P1=0x20;delay_1ms(1);P1=0xF9;delay_50us(10);P1=0xFF;return;}
	if(AngleNew>120 && AngleNew<135)	{P0=0xFF;P1=0xFF;P2=0xF9;delay_50us(10);P2=0x20;delay_1ms(1);P2=0xF9;delay_50us(10);P2=0xFF;return;}
	if(AngleNew>135 && AngleNew<150)	{P1=0xFF;P2=0xFF;P0=0xF9;delay_50us(10);P0=0x20;delay_1ms(1);P0=0xF9;delay_50us(10);P0=0xFF;return;}
	if(AngleNew>150 && AngleNew<165)	{P0=0xFF;P2=0xFF;P1=0xF9;delay_50us(10);P1=0x20;delay_1ms(1);P1=0xF9;delay_50us(10);P1=0xFF;return;}
	if(AngleNew>165 && AngleNew<180)	{P0=0xFF;P1=0xFF;P2=0xF9;delay_50us(10);P2=0x20;delay_1ms(1);P2=0xF9;delay_50us(10);P2=0xFF;return;}
	if(AngleNew>180 && AngleNew<195)	{P1=0xFF;P2=0xFF;P0=0xF9;delay_50us(10);P0=0x20;delay_1ms(1);P0=0xF9;delay_50us(10);P0=0xFF;return;}
	if(AngleNew>195 && AngleNew<210)	{P0=0xFF;P2=0xFF;P1=0xF9;delay_50us(10);P1=0x20;delay_1ms(1);P1=0xF9;delay_50us(10);P1=0xFF;return;}
	if(AngleNew>210 && AngleNew<225)	{P0=0xFF;P1=0xFF;P2=0xF9;delay_50us(10);P2=0x20;delay_1ms(1);P2=0xF9;delay_50us(10);P2=0xFF;return;}
	if(AngleNew>225 && AngleNew<240)	{P1=0xFF;P2=0xFF;P0=0xF9;delay_50us(10);P0=0x20;delay_1ms(1);P0=0xF9;delay_50us(10);P0=0xFF;return;}
	if(AngleNew>240 && AngleNew<255)	{P0=0xFF;P2=0xFF;P1=0xF9;delay_50us(10);P1=0x20;delay_1ms(1);P1=0xF9;delay_50us(10);P1=0xFF;return;}
	if(AngleNew>255 && AngleNew<270)	{P0=0xFF;P1=0xFF;P2=0xF9;delay_50us(10);P2=0x20;delay_1ms(1);P2=0xF9;delay_50us(10);P2=0xFF;return;}
	if(AngleNew>270 && AngleNew<285)	{P1=0xFF;P2=0xFF;P0=0xF9;delay_50us(10);P0=0x20;delay_1ms(1);P0=0xF9;delay_50us(10);P0=0xFF;return;}
	if(AngleNew>285 && AngleNew<300)	{P0=0xFF;P2=0xFF;P1=0xF9;delay_50us(10);P1=0x20;delay_1ms(1);P1=0xF9;delay_50us(10);P1=0xFF;return;}
  if(AngleNew>300 && AngleNew<315)	{P0=0xFF;P1=0xFF;P2=0xF9;delay_50us(10);P2=0x20;delay_1ms(1);P2=0xF9;delay_50us(10);P2=0xFF;return;}
	if(AngleNew>315 && AngleNew<330)	{P1=0xFF;P2=0xFF;P0=0xF9;delay_50us(10);P0=0x20;delay_1ms(1);P0=0xF9;delay_50us(10);P0=0xFF;return;}
	if(AngleNew>330 && AngleNew<345)	{P0=0xFF;P2=0xFF;P1=0xF9;delay_50us(10);P1=0x20;delay_1ms(1);P1=0xF9;delay_50us(10);P1=0xFF;return;}
	if(AngleNew>345 && AngleNew<360)	{P0=0xFF;P1=0xFF;P2=0xF9;delay_50us(10);P2=0x20;delay_1ms(1);P2=0xF9;delay_50us(10);P2=0xFF;return;}
}
//前面清零里程标志是为了体现优先级。
//想画个感叹号
//感叹号在车轮上固定位置
//设置15°间隔是因为：在3r/s的时候10ms大约转过10°。为了保证精度，设置15度间隔。