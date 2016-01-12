unsigned char Flower_Value[14]={0x3f,0x1f,0x0f,0x07,0x03,0x01,0x00,0x00,0x03,0x07,0x0f,0x1f,0x3f,0x7f}

void Flower(){
if(AngleNew>60&&AngleNew<120){
		S_P_2=0;
		S_P_3=0;
	if(S_P_1<14){
		P0=Flower_Value[S_P_1];
		P1=Flower_Value[S_P_1];
		P2=Flower_Value[S_P_1];
		S_P_1++;
	}
	else{
		P0=0x7f;
		P1=0x7f;
		P2=0x7f;
	}
}
else if(AngleNew>120&&AngleNew<180){
		S_P_1=0;
		S_P_3=0;
		if(S_P_2<14){
			P0=Flower_Value[S_P_2];
			P1=Flower_Value[S_P_2];
			P2=Flower_Value[S_P_2];
			S_P_2++;
		}
		else{		
		P0=0x7f;
		P1=0x7f;
		P2=0x7f;}
}
else if(AngleNew>180&&AngleNew<240){
		S_P_1=0;
		S_P_2=0;
		if(S_P_2<14){
			P0=Flower_Value[S_P_3];
			P1=Flower_Value[S_P_3];
			P2=Flower_Value[S_P_3];
			S_P_3++;
		}
		else{		
		P0=0x7f;
		P1=0x7f;
		P2=0x7f;
	}
}
else{
		P0=0x7f;
		P1=0x7f;
		P2=0x7f;
}
}