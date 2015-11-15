 #include "pwm_tc2.h"

#include "adxl345.h"
#define OC2_OUT_EN DDRD |= 0b10000000    //pd7
#define OC2_OUT_DIS DDRD &= 0b01111111    //pd7
#include "ffft.h"
extern int sample[2][FFT_N ]  ; //fft_num 128   

extern  ADXL345_config();
 extern stop_adc();
  extern enable_adc();
void timer2_init(void) 
{ 
TCCR2 = 0x60|0x07;
/*
WGM21=1; WGM20=1; --> fast PWM modle
COM21=1; COM20=0; --> 比较匹配时set OC2 pin   
CS20=1; --> timer2 source 不经过任何分频，直接为Clk，使得PWM可以工作得足够快
CS22=1;CS21=1,CS20=1;  8KHz 
pwm 频率 32Hz
*/
TCNT2 = 0x00; //设置TC2计数寄存器初值 
OCR2 = 0x00; //输出比较寄存器初值，设置该值可用于调节OC2占空比 正比
}

void pwm_en(void)
{
TCCR2=0x60|0x07;

OC2_OUT_EN;
}

void pwm_stop(void)
{
TCCR2=0x60 ;//no  clk
OC2_OUT_DIS;

//OCIE2 and TOIE2
}


/*--------------------------------------------------------------------
程序名称：
程序功能：
注意事项：
提示说明：
输 入：
返 回：
--------------------------------------------------------------------*/
void pwmini(void) 
{
OC2_OUT_EN; //为允许PWM工作，需设置PD7为输出
timer2_init();
__asm__ __volatile__ ("sei" ::);   // 开放全局中断
 
}



void moter(unsigned char i)


{

OCR2 = i; //输出比较寄存器初值，设置该值可用于调节OC2占空比 正比

pwm_en();
_delay_ms(3000);;//3秒
pwm_stop();

}
 
 /* 
 先停ADC，取得位置10次的平均值
 震荡一次，等3秒，看是否位置改变，如果没改变加15再震。直到最大的震荡做完位为止。如果动了也停止并结束 
 */
 
 void wake()//位置改变才停止
 
 {
 unsigned char i,j;
  XYZ *xyz_data,*xyz_data_sum,*xyz_data_last;
  unsigned int k;
 
 stop_adc();
 
 xyz_data=sample[0];
 xyz_data_sum=xyz_data+sizeof (XYZ);
  xyz_data_last=xyz_data_sum+sizeof (XYZ);
 
 	   xyz_data_sum->x=0;
	   xyz_data_sum->y=0;
	   xyz_data_sum->z=0;
	 
	 ADXL345_config();
	
		for(i=0;i<10;i++) {
  	   readxyz_345( (unsigned char *)xyz_data);
	   xyz_data_sum->x+=xyz_data->x;
	   xyz_data_sum->y+=xyz_data->y;
	  xyz_data_sum->z+=xyz_data->z;
	  	   
	   }
	  xyz_data_last->x=xyz_data_sum->x/10;
	   xyz_data_last->y=xyz_data_sum->y/10;
	   xyz_data_last->z=xyz_data_sum->z/10;
	   
	   pwmini();
	  
	  
		//  point= &content;
		// content.diff=0 ;
  for(j=35;j<245 ;j=j+15)
	   
	   {
	    xyz_data_sum->x=0;
	   xyz_data_sum->y=0;
	   xyz_data_sum->z=0;
	   moter(j);;//内涵3秒
	 
	  
	   for(k=0;k<1000;k++) 
	      {
	 
	          for(i=0;i<10;i++) {
  	             readxyz_345(  (unsigned char *) xyz_data);
	             xyz_data_sum->x+=xyz_data->x;
	             xyz_data_sum->y+=xyz_data->y;
	             xyz_data_sum->z+=xyz_data->z;
	  	   
	                          }// for(i=0;i<10;i++) {
	       xyz_data_sum->x=xyz_data_sum->x/10;
	       xyz_data_sum->y=xyz_data_sum->y/10;
	       xyz_data_sum->z=xyz_data_sum->z/10;
	   
	      if ((abs(xyz_data_last->x- xyz_data_sum->x)>MOTION_JUDGE)||(abs(xyz_data_last->z- xyz_data_sum->z)>MOTION_JUDGE)||(abs(xyz_data_last->y- xyz_data_sum->y)>MOTION_JUDGE))
	        {
			 enable_adc();
	         return;
	       }
	   
	      }
	   }
	   
	    _delay_ms(30000);;//3秒
	  _delay_ms(30000);;//3秒
 enable_adc();
 
 }