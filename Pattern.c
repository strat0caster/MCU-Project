#define D_Round 0.2  //定义
#define pi 3.14159265358

#include <lights.h>

float wx,wy,wz,ax,ay,az;//raw data from MPU6050;quite likely that we won't use wy&ay though
float miles=0;
float delta_miles;
