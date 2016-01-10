#include "turning.h"
				  			   

void delay_1ms(int parameter);
void delay_10ms(int parameter);

void turning_pattern(void){

if(AngleNew>0 && AngleNew<5)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>5 && AngleNew<10)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>10 && AngleNew<15)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>15 && AngleNew<20)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>20 && AngleNew<25)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>25 && AngleNew<30)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
if(AngleNew>30 && AngleNew<35)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>35 && AngleNew<40)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>40 && AngleNew<45)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>45 && AngleNew<50)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>50 && AngleNew<55)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>55 && AngleNew<60)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
if(AngleNew>60 && AngleNew<65)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>65 && AngleNew<70)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>70 && AngleNew<75)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>75 && AngleNew<80)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>80 && AngleNew<85)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>85 && AngleNew<90)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
if(AngleNew>90 && AngleNew<95)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>95 && AngleNew<100)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>100 && AngleNew<105)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>105 && AngleNew<110)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>110 && AngleNew<115)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>115 && AngleNew<120)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
if(AngleNew>120 && AngleNew<125)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>125 && AngleNew<130)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>130 && AngleNew<135)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>135 && AngleNew<140)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>140 && AngleNew<145)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>145 && AngleNew<150)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
if(AngleNew>150 && AngleNew<155)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>155 && AngleNew<160)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>160 && AngleNew<165)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>165 && AngleNew<170)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>170 && AngleNew<175)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>175 && AngleNew<180)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
if(AngleNew>180 && AngleNew<185)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>185 && AngleNew<190)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>190 && AngleNew<195)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>195 && AngleNew<200)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>200 && AngleNew<205)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>205 && AngleNew<210)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
if(AngleNew>210 && AngleNew<215)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>215 && AngleNew<220)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>220 && AngleNew<225)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>225 && AngleNew<230)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>230 && AngleNew<235)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>235 && AngleNew<240)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
if(AngleNew>240 && AngleNew<245)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>245 && AngleNew<250)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>250 && AngleNew<255)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>255 && AngleNew<260)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>260 && AngleNew<265)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>265 && AngleNew<270)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
if(AngleNew>270 && AngleNew<275)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>275 && AngleNew<280)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>280 && AngleNew<285)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>285 && AngleNew<290)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>290 && AngleNew<295)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>295 && AngleNew<300)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
if(AngleNew>300 && AngleNew<305)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>305 && AngleNew<310)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>310 && AngleNew<315)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>315 && AngleNew<320)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>320 && AngleNew<325)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>325 && AngleNew<330)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
if(AngleNew>330 && AngleNew<335)  {P0=0xF9; P1=0xFF; P2=0xFF;return;}
if(AngleNew>335 && AngleNew<340)  {P0=0x40; P1=0xFF; P2=0xFF;return;}
if(AngleNew>340 && AngleNew<345)  {P0=0xF9; P1=0xF9; P2=0xFF;return;}
if(AngleNew>345 && AngleNew<350)  {P0=0xFF; P1=0x40; P2=0xF9;return;}
if(AngleNew>350 && AngleNew<355)  {P0=0xFF; P1=0xF9; P2=0x40;return;}
if(AngleNew>355 && AngleNew<360)  {P0=0xFF; P1=0xFF; P2=0xF9;return;}
	
}

//前面清零里程标志是为了体现优先级。
//想画个感叹号
//感叹号在车轮上固定位置
//设置15°间隔是因为：在3r/s的时候10ms大约转过10°。为了保证精度，设置15度间隔。