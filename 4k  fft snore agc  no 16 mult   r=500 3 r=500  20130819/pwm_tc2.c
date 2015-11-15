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
COM21=1; COM20=0; --> �Ƚ�ƥ��ʱset OC2 pin   
CS20=1; --> timer2 source �������κη�Ƶ��ֱ��ΪClk��ʹ��PWM���Թ������㹻��
CS22=1;CS21=1,CS20=1;  8KHz 
pwm Ƶ�� 32Hz
*/
TCNT2 = 0x00; //����TC2�����Ĵ�����ֵ 
OCR2 = 0x00; //����ȽϼĴ�����ֵ�����ø�ֵ�����ڵ���OC2ռ�ձ� ����
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
�������ƣ�
�����ܣ�
ע�����
��ʾ˵����
�� �룺
�� �أ�
--------------------------------------------------------------------*/
void pwmini(void) 
{
OC2_OUT_EN; //Ϊ����PWM������������PD7Ϊ���
timer2_init();
__asm__ __volatile__ ("sei" ::);   // ����ȫ���ж�
 
}



void moter(unsigned char i)


{

OCR2 = i; //����ȽϼĴ�����ֵ�����ø�ֵ�����ڵ���OC2ռ�ձ� ����

pwm_en();
_delay_ms(3000);;//3��
pwm_stop();

}
 
 /* 
 ��ͣADC��ȡ��λ��10�ε�ƽ��ֵ
 ��һ�Σ���3�룬���Ƿ�λ�øı䣬���û�ı��15����ֱ������������λΪֹ���������Ҳֹͣ������ 
 */
 
 void wake()//λ�øı��ֹͣ
 
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
	   moter(j);;//�ں�3��
	 
	  
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
	   
	    _delay_ms(30000);;//3��
	  _delay_ms(30000);;//3��
 enable_adc();
 
 }