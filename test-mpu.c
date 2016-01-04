#include <reg51.h>
#include <intrins.h>
sfr AUXR=0x8E;



int a[3],w[3],Angle[3]; 
//Angle[0]=Angle_X, Angle[1]=Angle_Y, Angle[2]=Angle_Z;
//Angle_Z directly determines where it is ON THE WHEEL.
unsigned char Receive_Buff[11];
unsigned char counter=0,test=0;


void main(void) {
	unsigned char LED;
	void UartInit();
	UartInit();
	while(1){
			if( Angle[2] >120){
				LED=0x55;
			}
			else{
				LED=0x33;
			}
			P2=Angle[2];
			P0=LED;
				
	}
	
}



void UartInit(void)		//9600bps@11.0592MHz
{
	EA=1;
	ES=1;
/*	AUXR &= 0xBF;		//��ʱ��1ʱ��ΪFosc
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	SCON = 0x50;		//8λ���ݣ��ɱ䲨����
	TMOD &= 0x0F;		//�趨T1Ϊ16λ�Զ���װ�ط�ʽ
	TL1 = 0xE8;		
	TH1 = 0xFF;		//�趨��ʱ����ֵ
	ET1 = 0;		//��ֹT1�ж�
	TR1 = 1;		//	������ʱ��1
*/
//�������û�õĶ���
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
//����ΪUART��ʽ1��9600�����ʣ��Ѿ����Գɹ��������յ����ж�;TL1!!!!!

}

void ser() interrupt 4
{
	if (RI)
	{
		RI=0;	
		Receive_Buff[counter]=SBUF;	
		
	  if(counter==0&&Receive_Buff[0]!=0x55) return;      //��0�����ݲ���֡ͷ
	  counter++; 
		P1=counter;
		
	  if(counter==11)             //���յ�11������
	    {
	       counter=0;               //���¸�ֵ��׼����һ֡���ݵĽ���        
		
			switch(Receive_Buff [1])
			{
			case 0x51:
			a[0]=(Receive_Buff[2]<<8|Receive_Buff[3])/32768.0*16;
			a[1]=(Receive_Buff[4]<<8|Receive_Buff[5])/32768.0*16;
			a[2]=(Receive_Buff[6]<<8|Receive_Buff[7])/32768.0*16;
			break;
			case 0x52:		
			w[0]=(Receive_Buff[2]<<8|Receive_Buff[3])/32768.0*2000;
			w[1]=(Receive_Buff[4]<<8|Receive_Buff[5])/32768.0*2000;
			w[2]=(Receive_Buff[6]<<8|Receive_Buff[7])/32768.0*2000;
			break;
			case 0x53: 
			Angle[0]=(Receive_Buff[2]<<8|Receive_Buff[3])/32768.0*180;
			Angle[1]=(Receive_Buff[4]<<8|Receive_Buff[5])/32768.0*180;
			Angle[2]=(Receive_Buff[6]<<8|Receive_Buff[7])/32768.0*180;
			break;
			} 
	      }
	  }
}


