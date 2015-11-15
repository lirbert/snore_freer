#include "fftest.h"
 #include "pwm_tc2.h"	
 #include "LED.h" 		
#include 	<avr/interrupt.h>		  
judge_content content;  
 float scale;
extern main_adc();
extern enter_sleep() ;

 extern int sample[2][FFT_N ]  ; //fft_num 128   
 extern volatile unsigned char pingpang  ;      //��������
  extern volatile unsigned char  pingpang_fresh   ;
 extern volatile int posi_uart	;	
extern	volatile unsigned char sendpang ;
extern volatile unsigned char over ;  
//extern const prog_uchar sign;
const prog_uchar FlashConst = 3;//eeprom
/*------------------------------------------------*/
/* Global variables                               */

 //char pool[16];	/* Console input buffer */

//int16_t capture[FFT_N];			/* Wave captureing buffer */
int temp_sample [FFT_N];	
complex_t bfly_buff[FFT_N];		/* FFT buffer */
uint16_t  spektrum[FFT_N/2];		/* Spectrum output buffer */
uint16_t  spektrum_sample_buff_old[FFT_N/2];

//const unsigned char snore[]="snore/r/n";
 const unsigned char hello[]=" nFFT sample program\r\n";
unsigned char gain=12,gain_debug=16;//
uint16_t  count_sample=0;//ÿ128���ʱ����32ms��ÿ32ms�ͼ�һ�Ρ�֡���� 1000�� Ϊ32�룬 ��ʼ���ԷŴ�

uint16_t  max=512 ,min=512;
  unsigned int  bias=512;
    unsigned int silent_time=0;

/*------------------------------------------------*/
/* Capture waveform                               */






void init_USART_baud(unsigned long num )//USART ��ʼ��
{
    //USART 38400 8, n,1  PC��λ�����(�����ն˵�)ҲҪ���ͬ�������ò���ͨѶ
    UCSRC = (1<<URSEL) | 0x06;    //�첽��8λ���ݣ�����żУ�飬һ��ֹͣλ���ޱ���    
    UBRRL=(F_CPU/num/16-1)%256;
    UBRRH= (F_CPU/num/16-1)/256;
    UCSRA = 0x00;
    UCSRB |=  (1<<TXEN); //ʹ�ܽ����жϣ�ʹ�ܽ��գ�ʹ�ܷ���
     
    //UCSRB = (1<<TXEN);    // ʹ�ܷ���
} 

	usart_interrupt_en()
	
	{
	 
	UCSRB|=(1<<TXCIE) ; //ʹ�ܽ����жϣ�ʹ�ܽ��գ�ʹ�ܷ���
	}
       void send_c(  char schar) //���Ͳ��ò�ѯ��ʽ
{
    while( !(UCSRA & (1<<UDRE)) );
    UDR=schar;
}

   int usart_write( unsigned char* buf  , int num)
          { int i;
           for(i=0;i<num;i++)
               
               {
               send_c(* buf++) ;
               }
               
           return   num;  
          
          
          
          }
   



void capture_wave (int16_t *buffer, uint16_t count)
{
	ADMUX = _BV(REFS0)|_BV(ADLAR)|_BV(MUX2)|_BV(MUX1)|_BV(MUX0);	// channel

	do {
		ADCSRA = _BV(ADEN)|_BV(ADSC)|_BV(ADFR)|_BV(ADIF)|_BV(ADPS2)|_BV(ADPS1);
		while(bit_is_clear(ADCSRA, ADIF));
		*buffer++ = ADC - 32768;
	} while(--count);

	ADCSRA = 0;
}


/* This is an alternative function of capture_wave() and can omit captureing buffer.

void capture_wave_inplace (complex_t *buffer, uint16_t count)
{
	const prog_int16_t *window = tbl_window;
	int16_t v;

	ADMUX = _BV(REFS0)|_BV(ADLAR)|_BV(MUX2)|_BV(MUX1)|_BV(MUX0);	// channel

	do {
		ADCSRA = _BV(ADEN)|_BV(ADSC)|_BV(ADFR)|_BV(ADIF)|_BV(ADPS2)|_BV(ADPS1);
		while(bit_is_clear(ADCSRA, ADIF));
		v = fmuls_f(ADC - 32768, pgm_read_word_near(window));
		buffer->r = v;
		buffer->i = v;
		buffer++; window++;
	} while(--count);

	ADCSRA = 0;
}
*/

/*------------------------------------------------*/
/* Online Monitor via an ISP cable                */

unsigned long int SUM_SPECTRUM(uint16_t * spectrum,unsigned char num)

{ unsigned char i;
unsigned long int sum=0;
for(i=0;i<num;i++)
{
sum+=*spectrum++;
}
return  sum ;
}

unsigned int peak(uint16_t * spectrum_in,unsigned int  num)

{  unsigned char i,index;
   unsigned int max=0;
   spectrum_in+=3;
   for(i=3;i<num;i++)
   {
    if (*spectrum_in>max)
    {
     max=*spectrum_in ;
	 index=i;
	 }
	 spectrum_in++;
   }
   return  index;
}


/***************************************************************
*  Function:       find_bias
*  Description:     �ҵ�AD��ƫѹֵ
*				    
*  Input:           int * data,Ϊ����ֵ  num������	    
*  Output:         null
*  Return:         int 
*  Others:         �� ��������Ҫ����ֵ��λ��
****************************************************************/
unsigned  int  find_bias(int * data,int num)
{ int i=0 ;
   long int sum=0;
   for (i=0;i<num;i++)
   
   {
    
   
   sum+=  *data++ ;
     }

   
     return sum/num;
}










//   float on zero ;


/***************************************************************
*  Function:       off_bias
*  Description:    ��512 ʱ�γ�+/_   ͬʱ�����Ƿ��������ļ�⣬���������Ͻ���
*				    
*  Input:           int * data,Ϊ����ֵ  num������	    
*  Output:         null
*  Return:         void
*  Others:         �� ��������Ҫ����ֵ��λ��


if (gain_debug)//ȡ������gain��Ӱ��
   {
 
       if ((*data<131||*data>892) &&gain>1)
  
       { 
  
           adjust_gain(--gain);// �������ϵ�������Ҫ��5���Ӻ� �����ٴηŴ�
  
         return 0;
        }
   
****************************************************************/








unsigned  char  off_bias(int * data,int num)
{ int i=0 ;
   for (i=0;i<num;i++)
   
   {
   if(*data>max )
   max=*data;
   if (*data<min)
   min=*data;
   
   
   
  
    *data++ =*data-bias;
     }

   
     return 1;
}




void multy_16(int * sampl ,int num)
{ int i  ;
   for (i=0;i<num;i++)
   
   {
        *sampl ++ =(*sampl )*16; 
    
   
   }
}
//   direct calc 
int  cross_zero (int * sampl,int num)

{
int sam,i ;
  char   present;
static int temp_sample=1;

 unsigned int sum=0;
for (i=0;i<num;i++)
   
   /**
    *{
    *if ( * sampl++>0)
    *   present=1;
    *else
    *   present =-1;
    *    
    *   
    *if( temp_sample!=present)
    *sum++;
    *temp_sample=present;
    *}
    */
 {     sam=* sampl++;
	if ( sam>CROSS_GAP)
      present=1;
   else
      {
	  if ( sam<-CROSS_GAP)
        present =-1;
	else  continue;    //���²���ֱ�ӷ�����һ��ѭ�������β��ж��ˡ�
// goto end ;
	   }
       
      
   if( temp_sample!=present)
   sum++;
   temp_sample=present;
   
	//end:  ;
  }	

   return sum ;
}
 long unsigned int energy_do(int * sample,int num)
{  int i=0;long unsigned int energy=0;
    
  for (i=0;i<num;i++)
   
   { 
   
   
   energy+=  (* sample)*(* sample++);
   }
  return energy;
}

void fft_input_no_window(int * sample,complex_t *dest,int num)


{


 int i=0;

  for (i=0;i<num;i++)
   
   { 
   
    dest->r = * sample  ;
     dest->i = * sample++ ;
   dest++;
   }


}

copy_buff(int * source,int * dest ,int num)



{


 int i=0;

  for (i=0;i<num;i++)
   
   { 
   
    *dest++ = * source++ ;
    
   
   }


}


 

unsigned char  judge( uint16_t * spectrum)
{
unsigned long int middle ;

float whole;
//float scale,devia,deviation;

whole=SUM_SPECTRUM(spectrum+1,FFT_N/2-1);
//low=mean(spectrum+1,18);
scale=SUM_SPECTRUM(spectrum+4,21);//4---25//  780Hz 
//high=mean(spectrum+50,10);//50---60

//scale=middle/low;
 scale=scale/whole;
//devia=max/high;
//if (scale >1.5&&devia<2.5&&deviation<3)
     // usart_write(snore,10);	
	 if (scale>0.3&&scale<0.55)
   return 1;
   else return 0;

}
	  void    write( unsigned char turn) 
{

  sendpang=turn;
  
  send_c(*(sample[0]) );
  posi_uart=1;
   
}

  

 void correction( int * dest,int * source,int num )
 {
 int i=0;

  for (i=0;i<num;i++)
   
   { 
   
    (*dest)  = (  * dest++)*(* source++) ;
    
   
   }
 
 }
 
 
 void correlation( int * dest,int * source,int num )
 {
 int i=0;

  for (i=3;i<num;i++)
   
   { 
   
    (*dest)  = (  * dest++)+(* source++) ;
    
   
   }
 
 }
void  adjust(  judge_content * cont_po)
 
 {
     unsigned char i,temp=0;
	 //peak_index[3] ��ǰ֡��peak_index[0]>  ǰ����֡
         if ( (cont_po->peak_index[3]>=4) &&(cont_po->peak_index[3]<=30)&&judge(spektrum) &&cont_po->energy<ENERGYover)//&& (judge(spektrum)>=30))// 156Hz < frequncy  < 20/32*1000Hz =667Hz 
		 
			{
					     cont_po->flg.pre_flag3=1;//��ǰ֡�ϸ�
						 
						     						   
						 temp=cont_po->flg.pre_flag3+cont_po->flg.pre_flag2+cont_po->flg.pre_flag1+cont_po->flg.pre_flag0;//����4֡�������־�ĺ͡�
					     if ( temp>=3)
					      {
						    cont_po->flg.snore_flag=1;//
							cont_po->flg.pitch_flg=0;
							cont_po->count_pitch=0;
							cont_po->flg.pre_flag0=0;
							cont_po->flg.pre_flag1=0;
							cont_po->flg.pre_flag2=0;
							cont_po->flg.pre_flag3=0;
							cont_po->peak_index[0]=0;
							cont_po->peak_index[1]=0;
							cont_po->peak_index[2]=0;
							cont_po->peak_index[3]=0;
							// usart_write(snore,10);	
							
							  wake();//λ�øı��ֹͣ
							 
                          
					
							
						   }
			}
	  else 
		//�����ж�ʧ�ܣ�				  
		 {
  
          cont_po->flg.pre_flag3=0;
		cont_po->peak_index[0]=0;
		cont_po->peak_index[1]=0;
		cont_po->peak_index[2]=0;
		cont_po->peak_index[3]=0;
						 
         }    
		cont_po->flg.pre_flag0=cont_po->flg.pre_flag1;
		cont_po->flg.pre_flag1=cont_po->flg.pre_flag2;
		cont_po->flg.pre_flag2=cont_po->flg.pre_flag3;
						 
							
		cont_po->peak_index[0]=cont_po->peak_index[1];
		cont_po->peak_index[1]=cont_po->peak_index[2];
		cont_po->peak_index[2]=cont_po->peak_index[3];
							 
				
 }
 
 
 
 
 void judge_active( judge_content * cont_po,unsigned  char pipang)
 
 {               cont_po->nosignal_count=0;//lifeng �� 20130815
            if (cont_po->flg.pitch_flg==1)// 
                 {
                        
                         cont_po->count_pitch++;	//  ��Ǳ���ź� 
 		            	//multy_16(sample[pipang],FFT_N);//*16
			          fft_input_no_window(sample[pipang], bfly_buff,FFT_N);
		
            	      fft_execute(bfly_buff);
			 
				      fft_output(bfly_buff, spektrum); 
					 
                       					    
					      correlation(spektrum_sample_buff_old,spektrum,FFT_N/2 );
					  
					      cont_po->peak_index[3]=peak(spektrum_sample_buff_old,FFT_N/2 );
					  
                          copy_buff(spektrum,spektrum_sample_buff_old, FFT_N/2 ); 
					  
                      
                          adjust(cont_po); 
					    
					    
					}	   
					  
 
 }
 
 void  reset_check (judge_content * cont_po )//û�п��ɵ� ��λ

{
      cont_po->nosignal_count=0;
			   
			      
			          cont_po->flg.pitch_flg=0;////δ ���־�ֹ�ڣ������ɶ�û��
			          cont_po->count_pitch=0;		 
				 
			 
			 cont_po->flg.pre_flag0=0;
			 cont_po->flg.pre_flag1=0;
			 cont_po->flg.pre_flag2=0;
		     cont_po->flg.pre_flag3=0;
			 cont_po->peak_index[0]=0;
			 cont_po->peak_index[1]=0;
			 cont_po->peak_index[2]=0;
			 cont_po->peak_index[3]=0;
} 

 void silent(judge_content * cont_po )//û�п��ɵ� ��λ

{
      cont_po->nosignal_count++;
			   
			       if ( cont_po->nosignal_count>SILENT)//15֡
			        {
			          cont_po->flg.pitch_flg=1;//���־�ֹ��
			          cont_po->count_pitch=0;		 
					}
			 
			 cont_po->flg.pre_flag0=0;
			 cont_po->flg.pre_flag1=0;
			 cont_po->flg.pre_flag2=0;
		     cont_po->flg.pre_flag3=0;
			 cont_po->peak_index[0]=0;
			 cont_po->peak_index[1]=0;
			 cont_po->peak_index[2]=0;
			 cont_po->peak_index[3]=0;
} 
 //��10�����ҵ����ֵ���������500 �򽵵�5��������5����25��  , ͬ��������ֵ
 
/***************************************************************
*  Function:       adjust_gain
*  Description:    ��������   //pA7--PA2 �ֱ�Ӳ�ͬ�ĵ��裬��ֻҪ���Ϊ0 �ͽ��룬������ʱӦΪ���衣
*				    
*  Input:           ��λ 6bit   64��ֵ 0--63     63 ��Ӧ�������   63 Ϊ111111��ʵ�ʵ����Ϊ000000 ������ȫ�Եء�
*  ��λbit ȨΪ��   100000   Ϊ 32 ��Ӧ���011111.  
                    010000   Ϊ 16 ��Ӧ���101111       
  60 ��Ӧ 111100  ʵ�ʵ����Ϊ000011 ����λ����ȫ�Եء�
*	  //PA7:50 pA6:100 PA5:200 PA4:300 PA3:510 PA2:1k	    
*  Output:         null
*  Return:         void
*  Others:         �� ��������Ҫ����ֵ��λ��



�����������63���������Զ���������������0������У���һ�а���gain_debug��ִ�С�




****************************************************************/
 //
 
void  adjust_gain(unsigned char i )//û�и�λ����
 {//ʵ�ⲻʧ�� ���Χ�� 131 --967  
                 //����������������ʵ��������½�����ͻ��½�
 
 //static unsigned char gain=0;

 unsigned char data=0;
  
  
// PA7:100 pA6:200 PA5:390 PA4:330 PA3:510 PA2:1k
 
  

 if (i>=63)
 i=63; //����
  
         //���� 0 
 
 
 
  if (gain_debug)
   i= gain_debug;//�������gain_debug����һ�а���gain_debug��ִ�С�
   
    gain=i;// ִ�е�����
   
/*	
	
	else
{
reset_check(point);

 
 max=512;
 min=512;
 }//���û����gain_debug����һ�а���������ִ�С�
 gain=i;
 
 
 */
 
 
 
  data=(i<<2);//�Ե�PA7  gain=0x11110000
 
DDRA=data;//�������  PA0,PA1Ϊ0 Ϊ����

 
//DDRA|=0x04;//PB2 �������
PORTA=~data ;//��Ӧ��bit���0;


 
 }
 void   gain_ready(unsigned char i )//û�и�λ����
 {//ʵ�ⲻʧ�� ���Χ�� 131 --967  
                 //����������������ʵ��������½�����ͻ��½�
 
 //static unsigned char gain=0;

 unsigned char data=0;
 //PA7:50 pA6:100 PA5:200 PA4:330 PA3:510 PA2:1k
  
// PA7:100 pA6:200 PA5:390 PA4:330 PA3:510 PA2:1k
 
 
 
 
  data=(i<<2);//�Ե�PA7  gain=0x11110000
 
DDRA=data;//�������

 
//DDRA|=0x04;//PB2 �������
PORTA=~data ;//��Ӧ��bit���0;


 
 }
 
 
 //��jtag ���ñ���eeprom��ֵ preserve

void EEPROM_Write(unsigned int waddr,unsigned char wdata)
{
        while(EECR & (1 << EEWE));
        EEAR = waddr;
        EEDR = wdata;                                                                        
        
        asm volatile("PUSH R16" "\n\t"                        
                  "LDI R16,0x04" "\n\t"
                  "OUT 0x1C,R16" "\n\t"                //EECR |= (1 << EEMWE);
                  "LDI R16,0x06" "\n\t"
                  "OUT 0x1C,R16" "\n\t"                //EECR |= (1 << EEWE);
                  "POP R16");
}

I_need_sleep()
{
   #if  0

{
  /*�ж�ʹ��*/
 
  enter_sleep() ;
 // LED_snore();//has waked
 
  silent_time=0;
}
#endif 
}
 
 
 
 
unsigned char if_thieved()
 {
 int  tp,tp2;
 //0x0000, 0x0001, 0x0002, and 0x0003 for 1, 2, 4, and 8MHz respectively
 
 /**
  *tp2 = pgm_read_byte(osc_address); 
  *    
  *
  *rc[0]=   pgm_read_byte(0x0000); 
  *
  *rc[1]=   pgm_read_byte(0x0000); 
  *rc[2]=   pgm_read_byte(0x0000); 
  *rc[3]=  pgm_read_byte(0x0000); 
  *
  *tp=rc[0]+rc[1]+rc[2]+rc[3]+0x48&0x31;
  *if (tp2==0xff)//first
  *
  *{
  *EEPROM_Write(osc_address,tp); 
  */
  
  
  tp=   pgm_read_byte(&FlashConst); 
  if (tp==3)//2621 
    {
     EEPROM_Write(FlashConst,OSCCAL);//eeprom  write  not  flash
	 return 1;
	 }
	 else
  {
  if (OSCCAL== tp)

  return 1;
  else return 0;
  
   }
 
 
  
 }
 
 
 
 
 
 
 #include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <util/delay.h>
/*
 SIGNAL(SIG_INTERRUPT2)
{    
    PORTB ^= (1 << 1);     
}


  
����˯�߻��Ѻ���*/
/* ֻ����չSTANDBYģʽ��jtag�޷����ѵģ�������������jtag���ѡ�
������ʧ�߿�����int2�����ѣ���gain=8 ʱ���ڶ���1k �ڶ���200ŷ�����ڱ�������������˵�����ɻ��ѡ�

*/

int main1(void) 
{ 
      LED_all_right();
    
    MCUCSR = (0<<ISC2); /* �ⲿINT2���½��ؼ����ж� */
    GICR |= (1<<INT2); /* �ⲿINT2�ж�ʹ�� */
	adjust_gain(8);

    sei();  /*�ж�ʹ��*/
    
    /* �������ģʽ���ȴ�INT2���� */
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
    sleep_cpu();
    sleep_disable();
    
    /* ����ADC ��������ģʽ���ȴ�INT2���� */
    set_sleep_mode(SLEEP_MODE_ADC);
    sleep_enable();
    sleep_cpu();
    sleep_disable();

    /* �������ģʽ���ȴ�INT2���� */
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_cpu();
    sleep_disable();

    /* ����ʡ��ģʽ���ȴ�INT2���� */
    set_sleep_mode(SLEEP_MODE_PWR_SAVE);
    sleep_enable();
    sleep_cpu();
    sleep_disable();

    /* ����STANDBYģʽ���ȴ�INT2���� */
    set_sleep_mode(SLEEP_MODE_STANDBY);
    sleep_enable();
    sleep_cpu();
    sleep_disable();

    /* ������չSTANDBYģʽ���ȴ�INT2���� */
    set_sleep_mode(SLEEP_MODE_EXT_STANDBY);
    sleep_enable();
    sleep_cpu();
    sleep_disable();

    _delay_ms(200);

    return 0;
}

 
 
 
 
 /*
 �����������һ�������ڹ۲����ֵ�ķ�Χ���������Ͱ����潵��һ������
 �����С������һ������������õ�max��minֵ��λ����������Ҫ�и���ʱ��Ϊ
 ���ݵĹ���ʱ��
   �������������500�䵽200.ÿ�� 500/5,500/4,500/3,500/2,4bit
   �ڶ������Կ���500 ��200 ��bit��
 
 1,2,3,4,5��ʱ�� ������Ʋ�������ȷ�� 
 */
 
 void   AGC()
 {
 
 judge_content * point;
  point= &content;
  
 if (max-min >420)
 
    {
	if(gain>1)
	
	adjust_gain	(--gain);//����Ϊ0 
	 
	}
	
else if (max-min <210)
 
    {
	
	adjust_gain	(++gain);
	
	}	
	
	
	max=512;
	min=512;

	
 //reset_check (point);//�ص���ʼ�����жϣ���Ҫ�Ѳ����������ݴ�����һ��
  
 count_sample=900;//��Ȼ������ʱ
 }
 
 
 
 
 
 
 
 
 				
int main (void)
{ 
	 
	 
	unsigned char index=0;
	judge_content * point;
	unsigned char  i;
 if (MCUCSR&&0x04)//MCUCSR ��BORF�Ƿ�Ϊ1 ���Ƿ�BOD����
 
    power_off();//just for test
    
	//xmitstr(PSTR("\r\nFFT sample program\r\n"));
   init_USART_baud(256000 ); // just for sleep
   // usart_write(hello ,23);
	//usart_interrupt_en();
	sample[0][0]=2;
	sample[0][1]=3;
	sample[0][2]=-4;
	sample[0][4]=-3;
	sample[0][5]=-1;
	sample[0][6]=3;
	sample[0][7]=5;
	sample[0][8]=-4;
	sample[0][9]=-5;
	 
	 
	
		 point->diff =cross_zero(sample[0] ,10 );
		 
		 for (i=0;i<FFT_N;i++)
		 
		 {
		 sample[0][i]=i+1;
		 
		 }
		 fft_input_no_window(sample[0], bfly_buff,FFT_N);
		 fft_execute(bfly_buff);
		 fft_output(bfly_buff, spektrum); 
			
	 
     usart_write( hello , 17);
    
  	  
	  
	   
	    LED_all_right();
	
	 
	  point= &content;
	 content.diff=0 ;
	 
	 i=if_thieved();//�Ƿ����
	 
	 if(i)
	 
	{
      
	   // wake(); just for sleep
	
	  
	   
	
	   
	   power_on();//just for test
	   
	   adjust_gain(1);//ĿǰΪPA4��PA5 Ϊ�� //000001 ��ӦPA2����1kŷ�� 
	  
	   adjust_gain(0);//32 ��ӦPA7����100ŷ�� 
	   gain_ready(0);
	   main_adc(); //sleep 
      power_off();//just for test
	for(;;) {
		 	
	   /* 

 ��С��Ѱ��peak lower������������ǣ������AGCһ���� ���㷨��λ ��
2.         ���ӣ�4k 128�֣���Ҫ32ms��ÿ5���ӵ�һ�μ��ɡ���Ӧ9375�Σ����Կ���1��ε������С���������С���Լӱ�����
3.         �����ϴε�������棬Ҫ���棿

*/

 if ((pingpang_fresh ==0x01)&& (over==1 ) )//new frame createded   
				 
	    {     count_sample++;
				 																
				  // usart_write(sample[0] ,256);
				  
				  
				  if(count_sample== 200 ||count_sample==201) 
				  
				  {
				  
				 bias= find_bias(sample[0] ,FFT_N );// 16�����ƫ�ơ�rc=��2+5k��*10u=70*10-3=
				  
				  adjust_gain(32);//�ʵ�����
				   //power_off();
				  }
				  
				  
				  
				  
				 if(count_sample>300) 
				  
		          {  //����ǰ10000�Ϊ�Ϊ�����ĳ����̹���   
				  
				
					
					 
					 
					
					
                      
 
				 sendpang=0;
				 posi_uart=0;
				 over=1;
					//  usart_interrupt_en();	
					 
                 i=off_bias(sample[0] ,FFT_N );//-512
		    	// copy_buff(sample[0],spektrum_sample_buff_old, FFT_N );  //back
				
				if (i==1 )   //����û����
				  
		      {	
				  point->energy=energy_do(sample[0] ,FFT_N );
		    	  point->diff =cross_zero(sample[0] ,FFT_N );
								 
			 	
				
			        if ((point->energy>ENERGY)&&(point->diff>DIFF_LOW ))
                        {
                           judge_active(point,0);//sample[0]
#if 0						  
 silent_time=0;//����Ƿ��б�Ҫ˯��   
 #endif
						   
                     
				         }
                     else
			   
			            {
			             silent(point);
			   
			             }
			      			
  			            //	correction (spektrum,spektrum_sample_buff_old,FFT_N/2 );
      		         	// index= peak(spektrum, FFT_N/2);
				
			       	if (point->count_pitch>CONTINUE_PITCH)
				        {
				         point->flg.pitch_flg=0;//�������������������Ǽٵġ�
					
				        }
					if	(point->energy<ENERGY_low)
						silent_time++;
				     else     silent_time=0;
						
					if 	(	silent_time>SILENT_TIME)//180s ��3����û��������Ϊ������,���Ϊ20s
						I_need_sleep();
						
							
						
						
					
                  }//	if (i==1 )   //����û����
				  
				  
				      if(count_sample>1300) // ��Ϊ���߶��ӣ����Դﵽ9375 Ϊ5���� 
                    
					 {
					 
					  count_sample=210;;
					 
					  AGC();  
					    }
									
				  
				  
				  
				}  // if��count_sampl>10000)  
				
		pingpang_fresh &=0xfe;// new feame free
			}//if ((pingpang_fresh ==0x01)&& (over==1 ) )//new frame createded  
				
		   	if ( (pingpang_fresh ==0x02)&& (over==1) )//new frame  createded  
																			 
			{ 
			 count_sample++;
			 
			 
				 if(count_sample>300) //10��
				  
		     {  //����ǰ10000�Ϊ�Ϊ�����ĳ����̹���   
				
			   
			   
				     
			   
			   
			   
			 
					
					
				 //usart_write(sample[1] ,256);
				  
				 sendpang=1;
				 posi_uart=0;
				 over=1;
			 	 //usart_interrupt_en();
				 
				 
				 
				i=off_bias(sample[1] ,FFT_N );
				if (i==1 )   //����û����
				  
		      {
				point->energy=energy_do(sample[1] ,FFT_N );
				 
				point->diff =cross_zero(sample[1] ,FFT_N );
					
					
			     	if ((point->energy>ENERGY)||(point->diff>DIFF_LOW ))
                      {
                        judge_active(point,1);//sample[1]
  #if 0						  
 silent_time=0;//����Ƿ��б�Ҫ˯��   
 #endif
						   
			    	  }
                 else
			   
			         {
			           silent(point);
			   
			         }
			   
			   //	correction (spektrum,spektrum_sample_buff_old,FFT_N/2 );
      			// index= peak(spektrum, FFT_N/2);
				
				    if (point->count_pitch>CONTINUE_PITCH)
				      {
				        point->flg.pitch_flg=0;//�������������������Ǽٵġ�
			          }
						

                	if	(point->energy<ENERGY_low)
						silent_time++;
					  else     silent_time=0;	
					if 	(	silent_time>SILENT_TIME)//180s ��3����û��������Ϊ�����ˣ����Ϊ20s
						I_need_sleep();
						
					 
							 
		 /*	*/
			       }//if (i==1 )   //����û����
				   
				 if(count_sample>1300) // ��Ϊ���߶��ӣ����Դﵽ9375 Ϊ5���� 
                    
					{
					count_sample=210;
					 
					  AGC();     
					}	
					
					
		    	}//	if��count_sampl>10000)			   
					   
			    pingpang_fresh &=0xfd;// new feame free				 
		      }	//if ( (pingpang_fresh ==0x02)&& (over==1) )//new frame  createded  
		 	
		}//	for(;;) {
	}//if_thieved();//�Ƿ����
 }
