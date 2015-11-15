#include "fftest.h"
 #include "pwm_tc2.h"	
 #include "LED.h" 		
#include 	<avr/interrupt.h>		  
judge_content content;  
 float scale;
extern main_adc();
extern enter_sleep() ;

 extern int sample[2][FFT_N ]  ; //fft_num 128   
 extern volatile unsigned char pingpang  ;      //两个队列
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
uint16_t  count_sample=0;//每128点的时间是32ms，每32ms就记一次。帧计数 1000个 为32秒， 开始尝试放大

uint16_t  max=512 ,min=512;
  unsigned int  bias=512;
    unsigned int silent_time=0;

/*------------------------------------------------*/
/* Capture waveform                               */






void init_USART_baud(unsigned long num )//USART 初始化
{
    //USART 38400 8, n,1  PC上位机软件(超级终端等)也要设成同样的设置才能通讯
    UCSRC = (1<<URSEL) | 0x06;    //异步，8位数据，无奇偶校验，一个停止位，无倍速    
    UBRRL=(F_CPU/num/16-1)%256;
    UBRRH= (F_CPU/num/16-1)/256;
    UCSRA = 0x00;
    UCSRB |=  (1<<TXEN); //使能接收中断，使能接收，使能发送
     
    //UCSRB = (1<<TXEN);    // 使能发送
} 

	usart_interrupt_en()
	
	{
	 
	UCSRB|=(1<<TXCIE) ; //使能接收中断，使能接收，使能发送
	}
       void send_c(  char schar) //发送采用查询方式
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
*  Description:     找到AD的偏压值
*				    
*  Input:           int * data,为采样值  num采样数	    
*  Output:         null
*  Return:         int 
*  Others:         无 调整后需要对最值复位。
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
*  Description:    减512 时形成+/_   同时进行是否增益过大的检测，如果大就马上降低
*				    
*  Input:           int * data,为采样值  num采样数	    
*  Output:         null
*  Return:         void
*  Others:         无 调整后需要对最值复位。


if (gain_debug)//取消调整gain的影响
   {
 
       if ((*data<131||*data>892) &&gain>1)
  
       { 
  
           adjust_gain(--gain);// 过大马上调，增大要等5分钟后 增益再次放大？
  
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
	else  continue;    //上下不靠直接返回下一次循环，本次不判断了。
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
	 //peak_index[3] 当前帧；peak_index[0]>  前第三帧
         if ( (cont_po->peak_index[3]>=4) &&(cont_po->peak_index[3]<=30)&&judge(spektrum) &&cont_po->energy<ENERGYover)//&& (judge(spektrum)>=30))// 156Hz < frequncy  < 20/32*1000Hz =667Hz 
		 
			{
					     cont_po->flg.pre_flag3=1;//当前帧合格
						 
						     						   
						 temp=cont_po->flg.pre_flag3+cont_po->flg.pre_flag2+cont_po->flg.pre_flag1+cont_po->flg.pre_flag0;//连续4帧鼾声标标志的和。
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
							
							  wake();//位置改变才停止
							 
                          
					
							
						   }
			}
	  else 
		//本次判断失败，				  
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
 
 {               cont_po->nosignal_count=0;//lifeng 改 20130815
            if (cont_po->flg.pitch_flg==1)// 
                 {
                        
                         cont_po->count_pitch++;	//  有潜在信号 
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
 
 void  reset_check (judge_content * cont_po )//没有可疑的 复位

{
      cont_po->nosignal_count=0;
			   
			      
			          cont_po->flg.pitch_flg=0;////未 出现静止期，连怀疑都没有
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

 void silent(judge_content * cont_po )//没有可疑的 复位

{
      cont_po->nosignal_count++;
			   
			       if ( cont_po->nosignal_count>SILENT)//15帧
			        {
			          cont_po->flg.pitch_flg=1;//出现静止期
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
 //在10秒内找到最大值，如果超过500 则降低5倍，两次5倍则25倍  , 同样如果最大值
 
/***************************************************************
*  Function:       adjust_gain
*  Description:    调整增益   //pA7--PA2 分别接不同的电阻，。只要输出为0 就接入，不接入时应为高阻。
*				    
*  Input:           档位 6bit   64个值 0--63     63 对应增益最大   63 为111111，实际的输出为000000 即电阻全对地。
*  高位bit 权为高   100000   为 32 对应输出011111.  
                    010000   为 16 对应输出101111       
  60 对应 111100  实际的输出为000011 即高位电阻全对地。
*	  //PA7:50 pA6:100 PA5:200 PA4:300 PA3:510 PA2:1k	    
*  Output:         null
*  Return:         void
*  Others:         无 调整后需要对最值复位。



允许输入大于63的数，会自动消减，允许输入0，如果有，则一切按照gain_debug来执行。




****************************************************************/
 //
 
void  adjust_gain(unsigned char i )//没有复位动作
 {//实测不失真 最大范围是 131 --967  
                 //而且随着输入增大，实测的最大会下降，最低会下降
 
 //static unsigned char gain=0;

 unsigned char data=0;
  
  
// PA7:100 pA6:200 PA5:390 PA4:330 PA3:510 PA2:1k
 
  

 if (i>=63)
 i=63; //保护
  
         //允许 0 
 
 
 
  if (gain_debug)
   i= gain_debug;//如果开启gain_debug，则一切按照gain_debug来执行。
   
    gain=i;// 执行的增益
   
/*	
	
	else
{
reset_check(point);

 
 max=512;
 min=512;
 }//如果没开启gain_debug，则一切按照正常来执行。
 gain=i;
 
 
 */
 
 
 
  data=(i<<2);//对到PA7  gain=0x11110000
 
DDRA=data;//方向输出  PA0,PA1为0 为输入

 
//DDRA|=0x04;//PB2 方向输出
PORTA=~data ;//相应的bit输出0;


 
 }
 void   gain_ready(unsigned char i )//没有复位动作
 {//实测不失真 最大范围是 131 --967  
                 //而且随着输入增大，实测的最大会下降，最低会下降
 
 //static unsigned char gain=0;

 unsigned char data=0;
 //PA7:50 pA6:100 PA5:200 PA4:330 PA3:510 PA2:1k
  
// PA7:100 pA6:200 PA5:390 PA4:330 PA3:510 PA2:1k
 
 
 
 
  data=(i<<2);//对到PA7  gain=0x11110000
 
DDRA=data;//方向输出

 
//DDRA|=0x04;//PB2 方向输出
PORTA=~data ;//相应的bit输出0;


 
 }
 
 
 //的jtag 设置保护eeprom的值 preserve

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
  /*中断使能*/
 
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


  
测试睡眠唤醒函数*/
/* 只有扩展STANDBY模式是jtag无法唤醒的，其他都可以由jtag唤醒。
其他的失眠可以由int2来唤醒，在gain=8 时，第二级1k 第二级200欧，对于本机器吹气大声说话即可唤醒。

*/

int main1(void) 
{ 
      LED_all_right();
    
    MCUCSR = (0<<ISC2); /* 外部INT2的下降沿激活中断 */
    GICR |= (1<<INT2); /* 外部INT2中断使能 */
	adjust_gain(8);

    sei();  /*中断使能*/
    
    /* 进入空闲模式，等待INT2唤醒 */
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
    sleep_cpu();
    sleep_disable();
    
    /* 进入ADC 噪声抑制模式，等待INT2唤醒 */
    set_sleep_mode(SLEEP_MODE_ADC);
    sleep_enable();
    sleep_cpu();
    sleep_disable();

    /* 进入掉电模式，等待INT2唤醒 */
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_cpu();
    sleep_disable();

    /* 进入省电模式，等待INT2唤醒 */
    set_sleep_mode(SLEEP_MODE_PWR_SAVE);
    sleep_enable();
    sleep_cpu();
    sleep_disable();

    /* 进入STANDBY模式，等待INT2唤醒 */
    set_sleep_mode(SLEEP_MODE_STANDBY);
    sleep_enable();
    sleep_cpu();
    sleep_disable();

    /* 进入扩展STANDBY模式，等待INT2唤醒 */
    set_sleep_mode(SLEEP_MODE_EXT_STANDBY);
    sleep_enable();
    sleep_cpu();
    sleep_disable();

    _delay_ms(200);

    return 0;
}

 
 
 
 
 /*
 这个函数是在一定周期内观察测量值的范围，如果过大就把增益降低一北倍，
 如果过小则增加一倍。并把所测得的max和min值复位，调整后需要有个延时作为
 电容的过渡时间
   第三级如果考虑500变到200.每次 500/5,500/4,500/3,500/2,4bit
   第二级可以考虑500 与200 两bit。
 
 1,2,3,4,5这时的 增益控制步调是正确的 
 */
 
 void   AGC()
 {
 
 judge_content * point;
  point= &content;
  
 if (max-min >420)
 
    {
	if(gain>1)
	
	adjust_gain	(--gain);//不许为0 
	 
	}
	
else if (max-min <210)
 
    {
	
	adjust_gain	(++gain);
	
	}	
	
	
	max=512;
	min=512;

	
 //reset_check (point);//回到初始重新判断，不要把不正常的数据带到下一次
  
 count_sample=900;//自然产生延时
 }
 
 
 
 
 
 
 
 
 				
int main (void)
{ 
	 
	 
	unsigned char index=0;
	judge_content * point;
	unsigned char  i;
 if (MCUCSR&&0x04)//MCUCSR 的BORF是否为1 ，是否BOD重启
 
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
	 
	 i=if_thieved();//是否盗版
	 
	 if(i)
	 
	{
      
	   // wake(); just for sleep
	
	  
	   
	
	   
	   power_on();//just for test
	   
	   adjust_gain(1);//目前为PA4，PA5 为空 //000001 对应PA2接入1k欧， 
	  
	   adjust_gain(0);//32 对应PA7接入100欧， 
	   gain_ready(0);
	   main_adc(); //sleep 
      power_off();//just for test
	for(;;) {
		 	
	   /* 

 减小（寻找peak lower，如果超过则标记，则调低AGC一倍。 ）算法复位 。
2.         增加（4k 128字，需要32ms。每5分钟调一次即可。对应9375次，可以考虑1万次的最大最小，如果都很小可以加倍）。
3.         记忆上次的最佳增益，要保存？

*/

 if ((pingpang_fresh ==0x01)&& (over==1 ) )//new frame createded   
				 
	    {     count_sample++;
				 																
				  // usart_write(sample[0] ,256);
				  
				  
				  if(count_sample== 200 ||count_sample==201) 
				  
				  {
				  
				 bias= find_bias(sample[0] ,FFT_N );// 16秒后测便偏移。rc=（2+5k）*10u=70*10-3=
				  
				  adjust_gain(32);//适当增益
				   //power_off();
				  }
				  
				  
				  
				  
				 if(count_sample>300) 
				  
		          {  //正常前10000次为开机的充电过程过滤   
				  
				
					
					 
					 
					
					
                      
 
				 sendpang=0;
				 posi_uart=0;
				 over=1;
					//  usart_interrupt_en();	
					 
                 i=off_bias(sample[0] ,FFT_N );//-512
		    	// copy_buff(sample[0],spektrum_sample_buff_old, FFT_N );  //back
				
				if (i==1 )   //增益没调整
				  
		      {	
				  point->energy=energy_do(sample[0] ,FFT_N );
		    	  point->diff =cross_zero(sample[0] ,FFT_N );
								 
			 	
				
			        if ((point->energy>ENERGY)&&(point->diff>DIFF_LOW ))
                        {
                           judge_active(point,0);//sample[0]
#if 0						  
 silent_time=0;//检测是否有必要睡眠   
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
				         point->flg.pitch_flg=0;//鼾声持续过长，怀疑是假的。
					
				        }
					if	(point->energy<ENERGY_low)
						silent_time++;
				     else     silent_time=0;
						
					if 	(	silent_time>SILENT_TIME)//180s 既3分钟没动静就认为安静了,后改为20s
						I_need_sleep();
						
							
						
						
					
                  }//	if (i==1 )   //增益没调整
				  
				  
				      if(count_sample>1300) // 因为两边都加，所以达到9375 为5分钟 
                    
					 {
					 
					  count_sample=210;;
					 
					  AGC();  
					    }
									
				  
				  
				  
				}  // if（count_sampl>10000)  
				
		pingpang_fresh &=0xfe;// new feame free
			}//if ((pingpang_fresh ==0x01)&& (over==1 ) )//new frame createded  
				
		   	if ( (pingpang_fresh ==0x02)&& (over==1) )//new frame  createded  
																			 
			{ 
			 count_sample++;
			 
			 
				 if(count_sample>300) //10秒
				  
		     {  //正常前10000次为开机的充电过程过滤   
				
			   
			   
				     
			   
			   
			   
			 
					
					
				 //usart_write(sample[1] ,256);
				  
				 sendpang=1;
				 posi_uart=0;
				 over=1;
			 	 //usart_interrupt_en();
				 
				 
				 
				i=off_bias(sample[1] ,FFT_N );
				if (i==1 )   //增益没调整
				  
		      {
				point->energy=energy_do(sample[1] ,FFT_N );
				 
				point->diff =cross_zero(sample[1] ,FFT_N );
					
					
			     	if ((point->energy>ENERGY)||(point->diff>DIFF_LOW ))
                      {
                        judge_active(point,1);//sample[1]
  #if 0						  
 silent_time=0;//检测是否有必要睡眠   
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
				        point->flg.pitch_flg=0;//鼾声持续过长，怀疑是假的。
			          }
						

                	if	(point->energy<ENERGY_low)
						silent_time++;
					  else     silent_time=0;	
					if 	(	silent_time>SILENT_TIME)//180s 既3分钟没动静就认为安静了，后改为20s
						I_need_sleep();
						
					 
							 
		 /*	*/
			       }//if (i==1 )   //增益没调整
				   
				 if(count_sample>1300) // 因为两边都加，所以达到9375 为5分钟 
                    
					{
					count_sample=210;
					 
					  AGC();     
					}	
					
					
		    	}//	if（count_sampl>10000)			   
					   
			    pingpang_fresh &=0xfd;// new feame free				 
		      }	//if ( (pingpang_fresh ==0x02)&& (over==1) )//new frame  createded  
		 	
		}//	for(;;) {
	}//if_thieved();//是否盗版
 }
