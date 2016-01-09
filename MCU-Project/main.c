#define D_Round 0.2  
#define pi 3.14159265358
#define distance_1 40
#define distance_2 100
#define distance_3 160
#define thres_omega 6553
#define thres_turning 900
#define omega_acc 900 //快速加速阈值 

#include "lights.h"


int code digital_angle[360]={0,0,1,3,5,8,11,15,20,25,31,38,45,53,61,70,79,90,100,
	112,124,136,149,163,177,192,207,223,240,257,274,293,311,330,350,370,391,412,434,
	456,479,502,526,550,575,600,625,651,678,704,732,759,787,816,844,873,903,933,963,993,
	1024,1055,1087,1118,1150,1183,1215,1248,1281,1314,1348,1381,1415,1449,1484,1518,1553,
	1587,1622,1657,1692,1728,1763,1798,1834,1870,1905,1941,1977,2012,2048,2084,2119,2155,
	2191,2226,2262,2298,2333,2368,2404,2439,2474,2509,2543,2578,2612,2647,2681,2715,2748,
	2782,2815,2848,2881,2913,2946,2978,3009,3041,3072,3103,3133,3163,3193,3223,3252,3280,
	3309,3337,3364,3392,3418,3445,3471,3496,3521,3546,3570,3594,3617,3640,3662,3684,3705,
	3726,3746,3766,3785,3803,3822,3839,3856,3873,3889,3904,3919,3933,3947,3960,3972,3984,
	3996,4006,4017,4026,4035,4043,4051,4058,4065,4071,4076,4081,4085,4088,4091,4093,4095,
	4096,4096,4096,4097,4099,4101,4104,4107,4111,4116,4121,4127,4134,4141,4148,4157,4166,
	4175,4185,4196,4207,4219,4232,4245,4259,4273,4288,4303,4319,4336,4353,4370,4388,4407,
	4426,4446,4466,4487,4508,4530,4552,4575,4598,4622,4646,4671,4696,4721,4747,4773,4800,
	4827,4855,4883,4911,4940,4969,4998,5028,5058,5089,5120,5151,5182,5214,5246,5278,5311,
	5343,5376,5410,5443,5477,5511,5545,5579,5614,5648,5683,5718,5753,5788,5823,5859,5894,
	5929,5965,6001,6036,6072,6108,6144,6179,6215,6251,6286,6322,6358,6393,6429,6464,6499,
	6534,6569,6604,6639,6674,6708,6742,6776,6810,6844,6877,6911,6944,6977,7009,7041,7073,
	7105,7136,7168,7198,7229,7259,7289,7318,7347,7376,7404,7432,7460,7487,7514,7540,7566,
	7592,7617,7641,7666,7689,7712,7735,7757,7779,7801,7821,7842,7861,7880,7899,7917,7935,
	7952,7968,7984,8000,8015,8029,8043,8056,8068,8080,8092,8102,8112,8122,8131,8139,8147,
8154,8161,8167,8172,8177,8181,8184,8187,8189,8191,8192};
unsigned char counter=0;
int Receive_Buff[11];
int a[3],w[3],Angle[3];
int a1=0,a2=0,a3=0;
int w1=0,w2=0;
float w_turning;

int Dist=0;
int AngleNew=0;
//double AngleNew=0;
bit dis_flag_1=0,dis_flag_2=0,dis_flag_3=0;
bit Flag=0;


int main(){
	
	UartInit();

	while(1){                                          //20ms

        w_turning=abs(w[0])+abs(w[2]);                            //用于转向判断
        if(w_turning>thres_turning) {turning_pattern();}
        else if(w2-w1>omega_acc)  {speeding_pattern();}//omega_acc为快速加速阈值
        else if(w1-w2>omega_acc)  {slowing_pattern();}//omega_slow为刹车阈值
        else if(dis_flag_1){display_distance(1);}
        else if(dis_flag_2){display_distance(2);}
        else if(dis_flag_3){display_distance(3);}
        else{cruise_pattern();}
				
				if(Dist==distance_1){dis_flag_1=1;};
				if(Dist==distance_2){dis_flag_2=1;};
        if(Dist==distance_3){dis_flag_3=1;};
    }
	
}


void cruise_pattern(){
    if( AngleNew>digital_angle[0]&&AngleNew<digital_angle[120]){
                P0=0x0F;
                P1=0xFF;
        }
    else if(AngleNew>digital_angle[120]&&AngleNew<digital_angle[240]){
                P1=0x0F;
                P0=0xFF;
        }
    else{
            P0=0xFF;
            P1=0xFF;
    }
}


void UartInit(void)		//115200bps@11.0592MHz
{
	EA=1;
	ES=1;
	SCON = 0x50;
	RCAP2L = 0xFD;
	RCAP2H = 0xFF;
	TL2 = 0xFD;		
	TH2 = 0xFF;		
	T2CON=0x34;
//以上为T2定时器实现115200波特率
}



void ser() interrupt 4
{
    if(RI)
    {
        RI=0;
        Receive_Buff[counter]=SBUF;

      if(counter==0&&Receive_Buff[0]!=0x55) return;      //第0号数据不是帧头
      counter++;

      if(counter==11)             //接收到11个数据
        {counter=0;               //重新赋值，准备下一帧数据的接收

            switch(Receive_Buff [1])
            {
            case 0x51:
            a[0]=(Receive_Buff[3]<<8|Receive_Buff[2]);
//          a[1]=(Receive_Buff[5]<<8|Receive_Buff[4]);
            a1=a2;
            a2=a3;
            a3=a[0];
						AngleNew=a[0]+2048;
						//尝试用另一种方法取得角度；详情见下方
            if(a1>=a2&&a2<=a3){Flag=0;}//固定点判断
            if(a1<=a2&&a2>=a3){Flag=1; 
						if(w[1]>thres_omega){Dist++;}//一圈里程加1
						}
//            if(Flag==1){AngleNew=asin(a[0]/2048.0)*57.3+90;}//利用x轴加速度方向判断方位角
//            else{AngleNew=270-asin(a[0]/2048.0)*57.3;}
//						asin函数比较花时间，尝试用另一种方法
						if(Flag==1){AngleNew=8192-AngleNew;}
						
//          a[2]=(Receive_Buff[7]<<8|Receive_Buff[6])/32768.0*16;
            break;
						
            case 0x52:
            w[0]=(Receive_Buff[3]<<8|Receive_Buff[2]);
            w[1]=(Receive_Buff[5]<<8|Receive_Buff[4]);
            w[2]=(Receive_Buff[7]<<8|Receive_Buff[6]);
						w1=w2;
						w2=w[1];
//          w=w[i]/32768.0*2000;
            break;
            case 0x53:
//            Angle[0]=(Receive_Buff[3]<<8|Receive_Buff[2]);
//            Angle[1]=(Receive_Buff[5]<<8|Receive_Buff[4])/32768.0*180;
//            Angle[2]=(Receive_Buff[7]<<8|Receive_Buff[6])/32768.0*180;
            break;
            default: break;
            }
          }

    }
    if(TI){TI=0;}
}