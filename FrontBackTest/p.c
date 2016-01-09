void Pattern000(){
if(AngleNew>170&&AngleNew<190){P0=0x00;}
else if(AngleNew>160&&AngleNew<170&&AngleNew>190&&AngleNew<200){P0=0x01;}
else if(AngleNew>150&&AngleNew<160&&AngleNew>200&&AngleNew<210){P0=0x03;}
else if(AngleNew>140&&AngleNew<150&&AngleNew>210&&AngleNew<220){P0=0x07;}
else if(AngleNew>130&&AngleNew<140&&AngleNew>220&&AngleNew<230){P0=0x0f;}
else if(AngleNew>120&&AngleNew<130&&AngleNew>230&&AngleNew<240){P0=0x1f;}
else if(AngleNew>110&&AngleNew<120&&AngleNew>240&&AngleNew<250){P0=0x3f;}
else if(AngleNew>100&&AngleNew<110&&AngleNew>250&&AngleNew<260){P0=0x7f;}
else P0=0xff;
}
void Pattern001(){
if(AngleNew>170+110&&AngleNew<190+110){P0=0x00;}
else if(AngleNew>(160+110)%360&&AngleNew<(170+110)%360&&AngleNew>(190+110)%360&&AngleNew<(200+110)%360){P0=0x01;}
else if(AngleNew>(150+110)%360&&AngleNew<(160+110)%360&&AngleNew>(200+110)%360&&AngleNew<(210+110)%360){P0=0x03;}
else if(AngleNew>(140+110)%360&&AngleNew<(150+110)%360&&AngleNew>(210+110)%360&&AngleNew<(220+110)%360){P0=0x07;}
else if(AngleNew>(130+110)%360&&AngleNew<(140+110)%360&&AngleNew>(220+110)%360&&AngleNew<(230+110)%360){P0=0x0f;}
else if(AngleNew>(120+110)%360&&AngleNew<(130+110)%360&&AngleNew>(230+110)%360&&AngleNew<(240+110)%360){P0=0x1f;}
else if(AngleNew>(110+110)%360&&AngleNew<(120+110)%360&&AngleNew>(240+110)%360&&AngleNew<(250+110)%360){P0=0x3f;}
else if(AngleNew>(100+110)%360&&AngleNew<(110+110)%360&&AngleNew>(250+110)%360&&AngleNew<(260+110)%360){P0=0x7f;}
else P0=0xff;
}
void Pattern002(){
if(AngleNew>(170+225)%360&&AngleNew<(190+225)%360){P0=0x00;}
else if(AngleNew>(160+225)%360&&AngleNew<(170+225)%360&&AngleNew>(190+225)%360&&AngleNew<(200+225)%360){P0=0x01;}
else if(AngleNew>(150+225)%360&&AngleNew<(160+225)%360&&AngleNew>(200+225)%360&&AngleNew<(210+225)%360){P0=0x03;}
else if(AngleNew>(140+225)%360&&AngleNew<(150+225)%360&&AngleNew>(210+225)%360&&AngleNew<(220+225)%360){P0=0x07;}
else if(AngleNew>(130+225)%360&&AngleNew<(140+225)%360&&AngleNew>(220+225)%360&&AngleNew<(230+225)%360){P0=0x0f;}
else if(AngleNew>(120+225)%360&&AngleNew<(130+225)%360&&AngleNew>(230+225)%360&&AngleNew<(240+225)%360){P0=0x1f;}
else if(AngleNew>(110+225)%360&&AngleNew<(120+225)%360&&AngleNew>(240+225)%360&&AngleNew<(250+225)%360){P0=0x3f;}
else if(AngleNew>(100+225)%360&&AngleNew<(110+225)%360&&AngleNew>(250+225)%360&&AngleNew<(260+225)%360){P0=0x7f;}
else P0=0xff;}
