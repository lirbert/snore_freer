/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.1b Evaluation
Automatic Program Generator
� Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project :
Version :
Date    : 2011/11/6
Author  : Freeware, for evaluation and non-commercial use only
Company :
Comments: ��֤adת����������ģʽ�������жϺ�led��
         (����pb.0�ϣ��ߵ�ƽ��)��500ms,�����жϽ�
         ����ѭ����Ϩ��


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.1920000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/
    
 #include <avr/io.h>
#include "adc.h"
 #include "ffft.h"


int sample[2][FFT_N ]  ; //fft_num 128   
 volatile unsigned char pingpang =0;      //��������
  volatile  unsigned int position =0 ;//;//invalid data 
 //volatile bitS	pingpang_fresh ;
 volatile  unsigned char pingpang_fresh =0x00; //0x11
 	volatile  unsigned int posi_uart=0	;	
	volatile unsigned char sendpang =0; 
  volatile   unsigned char over=1; 
int  fi=0;
    
void init_AD();



// Declare your global variables here

#include 	<avr/interrupt.h>

void init_timer0()
{
  TCCR0=0x00;   //stop
  TCNT0=0x00;    
    // T/C0 ��ʼ��  oc0  disconnect
  //WGM01 WGM00  =10  (CTC0)
// cs02 cs01 cs00 =101; 
 TCCR0|=0x0d;     // �ڲ�ʱ�ӣ�1024��Ƶ��8.192M/1024=8KHz����CTCģʽ  (auto clear)
// 024( 4),(8k/2=4kHz  
//OCR0=0x02;Ϊ3��Ƶ��
//OCR0=0x00;Ϊ1��Ƶ  8k

//OCR0=0x01;Ϊ8��Ƶ  1k
OCR0=0x01;////OCR0=0x00; 1��Ƶ 8k
 TIMSK|=0x02;     // ����T/C0�Ƚ��ж�  //test

}   

// ADC interrupt service routine
ISR  (ADC_vect)
{   //�ҵ��� ���� �ȶ�ADCL 
 // // sample[pingpang][position]=ADCW;
    int temp;
 temp=ADCW;
sample[pingpang][position]=temp;// 
       position++;   
 ///  no time to do    
     if (pingpang_fresh ==0x03 )
      while(1);
//            
       //����λ�ÿռ�
   if  (position== FFT_N )
        
        {
       pingpang_fresh |=1<<pingpang;;//new frame  createded 
	  
		
      		
          		  
         position=0;
		  
         pingpang=(pingpang+1)%2;
 
          
        }
    
      
//PORTB|=0x1;    //�����������led����
//delay_ms(500);
//ADCSRA|=(1<<ADSC); //����ADC,���������һ�䣬�����������Ӿ�ֻ�ܽ���һ��ת������2����������
// Place your code here

}


     

  ISR  (TIMER0_COMP_vect) 
  //   interrupt [TIM0_OVF] void timer0_comp_isr(void)
  
 
{
 //compare occured TCNT0=OCR0 /*��ʱ���Ƚ�ƥ���жϣ�����û������κ���䣬ʵ�ʲ����п����ô�ʵ������PWM*/ 
                    //clear flag auto
}


void init_AD()
{
   PORTA&=0xff;//PA0 
DDRA&=0xfe;//PA0  

 



// ADC initialization
// ADC Clock frequency: 125.000 kHz
// ADC Voltage Reference: AVCC pin
// ADC Auto Trigger Source: Free Running
ADMUX=ADC_VREF_TYPE & 0xff; // //internel ref 2.56v
//    //  ADMUX[4-0]  :   01011 diff end   ad1-ad0   gain =200 
//    ADMUX|=  0x0B;
//    //  ADMUX[4-0]  :   00000 sigle  end    ad0   gain = 1
   ADMUX|=  0x00; //adc0-----------20130622


 // Auto Trigger Source               
  SFIOR|=(1<<ADTS1);// timer0  countr 0 compare match  
   SFIOR|=(1<<ADTS0); 
//SFIOR&=0x1F;

//ADCSRA|=(1<<ADSC); //����ADC  
//ADCSRA=0xAD; 
  
ADCSRA|=(1<<ADATE); //����  
ADCSRA|=(1<< ADIE); //
//ADPS2 ADPS1 ADPS0    1 1 1   128 ��Ƶ


// /128 = 64k  

 //ADCSRA|=(1<< ADPS0); //  /32= 256k 
 // //     /64 = 128 kHz  
  ADCSRA|=(1<< ADPS1); //   
 ADCSRA|=(1<< ADPS2); //               
  ADCSRA|=(1<< ADSC); // start convention
  ADCSRA|=(1<<ADEN); //ʹ��ADC 
/*  ADCSRA|=(1<< ADPS0); //  /128= 64k
 ADCSRA|=(1<< ADPS1); //   
  ADCSRA|=(1<< ADPS2); //  
 */
    
 
}     

ISR   (USART_TXC_vect)
{   //�ҵ��� ���� �ȶ�ADCL 
 // // sample[pingpang][position]=ADCW;
				  
 /*
	 
	 	UDR= 	 *((unsigned char *)(sample[sendpang])+posi_uart);
	  
	  posi_uart++;
	  if (posi_uart==256)
	   {
          over=1;
		 UCSRB&=0xbf ;//disable 
          
		  
        } 
          
	*/ 
}



void main_adc(void)
{
// Declare your local variables here    
 
 


 
init_AD();

init_timer0();
 
 
   
	sei();	
 
 

 
}   
 //����ֱ��ʹ�ܻ�ʹ����ֵ�������䡣����Ҫ��Ϊ��AD�жϵĿ���    
 stop_adc()
 {
 
  //ADCSRA&=~(1<<ADEN); //ֹͣADC 
  
 // ADCSRA &=~(1<< ADIE); //��ֹ�жϲ���ֵ���ɻ�����
  TIMSK&=~0x02;     // ����T/C0�Ƚ��ж�  // ��������

 }
 
 //����ֱ��ʹ�ܻ�ʹ����ֵ�������䡣����Ҫ��Ϊ��AD�жϵĿ���    
enable_adc()
 {
 
 // ADCSRA|=(1<<ADEN); //ʹ��ADC 
 // ADCSRA|=(1<< ADIE); ////��ֹ�жϲ���ֵ���ɻ�����
 
  TIMSK|=0x02;     // ����T/C0�Ƚ��ж�  //��������   �������𶯸��ţ�

pingpang=0;  //��Ϊ��wake�и�����pingpang���ڴ�
position=0;//�����жϻḲ������
pingpang_fresh =0x00;

 }


   