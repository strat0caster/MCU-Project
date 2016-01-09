#include <reg51.h>
#include <intrins.h>
#include <math.h>
#include "mileage.h"

#define D_Round 0.2  //定义
#define pi 3.14159265358

bit turning_flag,speeding_flag,slowing_flag,miles_flag1,miles_flag2,miles_flag3;

sfr AUXR=0x8E;
sfr T2CON=0xC8;
sfr RCAP2L=0xCA;
sfr RCAP2H=0xCB;
sfr TL2=0xCC;
sfr TH2=0xCD;

int a[3],w[3],Angle[3];
//Angle[0]=Angle_X, Angle[1]=Angle_Y, Angle[2]=Angle_Z;
//Angle_Z directly determines where it is ON THE WHEEL.
int Receive_Buff[11];
unsigned char counter=0,test=0;
int a1=0,a2=0,a3=0;
int timer=0;
extern int Dist=0;
extern double AngleNew=0;
bit Flag=0;

int main(){

    unsigned char LED;
    void UartInit();
    void Cruise_Pattern();
    void Speeding_Pattern();
    void Slowing_Pattern();
    void display_distance(int parameter);
    UartInit();

    while(1){                                          //20ms

        w_turning=sqrt(w[0]*w[0]+w[2]*w[2]);                            //用于转向判断
        if(w_turning>w0) {
            Turning_Pattern();
        }
        else if(w[1]){                                     //w1为快速加速阈值
            Speeding_Pattern();
        }
        else if(wz0-wz>w2){                                    //w2为刹车阈值
            Slowing_Pattern();
        }
        else if(Dist==20){        //dmiles 决定闪烁时间长短
            display_distance(1);
        }
        else if(Dist==40){        //dmiles 决定闪烁时间长短
            display_distance(2);
        }
        else if(Dist==60){        //dmiles 决定闪烁时间长短
            display_distance(3);
        }
        else{
            Cruise_Pattern();
        }


    }

}

void UartInit(void)        //115200bps@11.0592MHz
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
//以上为UART方式1，115200波特率；已经测试成功，可以收到并中断;TL1!!!!!
*/
    SCON = 0x50;        //8???,?????
    RCAP2L = 0xFD;
    RCAP2H = 0xFF;
    TL2 = 0xFD;        //??????
    TH2 = 0xFF;        //??????
    T2CON=0x34;
}

void Cruise_Pattern(){
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

void ser() interrupt 4
{
    if(RI)
    {
        RI=0;
        Receive_Buff[counter]=SBUF;

      if(counter==0&&Receive_Buff[0]!=0x55) return;      //第0号数据不是帧头
      counter++;

      if(counter==11)             //接收到11个数据
        {
           counter=0;               //重新赋值，准备下一帧数据的接收

            switch(Receive_Buff [1])
            {
            case 0x51:
            a[0]=(Receive_Buff[3]<<8|Receive_Buff[2]);
//            a[1]=(Receive_Buff[5]<<8|Receive_Buff[4]);
            a1=a2;
            a2=a3;
            a3=a[0];
            if(a1>=a2&&a2<=a3){//固定点判断
                Flag=1;
            }
            if(a1<=a2&&a2>=a3){
                Flag=0;
                if(w[1]>6553){
                    Dist++;
                }
            }
            if(Flag==1){
                AngleNew=asin(a[0]/2048.0)*57.3+90;//利用x轴加速度方向判断方位角
            }
            else{
                AngleNew=270-asin(a[0]/2048.0)*57.3;
            }
            // }
            //     AngleNew=0;
            // }
            // if(w[1]>1000&&a1>a2&&a2<a3){
            //     AngleNew=0;
            // }
//            a[2]=(Receive_Buff[7]<<8|Receive_Buff[6])/32768.0*16;
            break;
            case 0x52:

//            w[0]=(Receive_Buff[3]<<8|Receive_Buff[2]);
            w[1]=(Receive_Buff[5]<<8|Receive_Buff[4]);
            // if(w[1]>1000)
            // AngleNew+=w[1]/100;
//            w[2]=(Receive_Buff[7]<<8|Receive_Buff[6])/32768.0*2000;
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

        if(TI){
            TI=0;
        }
}