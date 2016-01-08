#define D_Round 0.2  
#define pi 3.14159265358
#define distance_1 20
#define distance_2 40
#define distance_3 60
#define thres_omega 6553
#define omega_acc 30000 //快速加速阈值 

#include "lights.h"


unsigned char counter=0;
int Receive_Buff[11];
int a[3],w[3],Angle[3];
int a1=0,a2=0,a3=0;
int w1=0,w2=0;
int w_turning;

int Dist=0;
double AngleNew=0;
bit dis_flag_1=0,dis_flag_2=0,dis_flag_3=0;
bit Flag=0;

int main(){

	UartInit();

	while(1){                                          //20ms

        w_turning=sqrt(w[0]*w[0]+w[2]*w[2]);                            //用于转向判断
        if(w_turning>1500) {turning_pattern();}
 //       else if(w2-w1>omega_acc)  {speeding_pattern();}//omega_acc为快速加速阈值
 //       else if(w1-w2>omega_acc)  {slowing_pattern();}//omega_slow为刹车阈值
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
    if( AngleNew>0&&AngleNew<120){
                P0=0x0F;
                P1=0xFF;
        }
    else if(AngleNew>120&&AngleNew<240){
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
            if(a1>=a2&&a2<=a3){Flag=0;}//固定点判断
            if(a1<=a2&&a2>=a3){Flag=1; 
						if(w[1]>thres_omega){Dist++;}//一圈里程加1
						}
            if(Flag==1){AngleNew=asin(a[0]/2048.0)*57.3+90;}//利用x轴加速度方向判断方位角
            else{AngleNew=270-asin(a[0]/2048.0)*57.3;}
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