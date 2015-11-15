 #include <avr/io.h>
 
 
 #include <avr/sleep.h>
#include 	<avr/interrupt.h>
 
  #include "LED.h" 
  
 ISR  (INT2_vect)
{   
LED_snore();
}

 ISR  (INT1_vect)
{   
LED_snore();
}

 ISR  (INT0_vect)
{   
LED_snore();
}


void  initial_int2()//PB2
{

DDRB &= 0xFB;    /*PB2 方向输入*/ 
    PORTB&=0xFB ;   /*电平设置  悬空 拉高会一直为1 */ 

  GIFR |= (1 << INT2)  ;      //清INT2中断 

      GICR &= ~(1<<INT2); /* 外部INT2中断先禁止，避免修改ISC2 引发中断 */
   MCUCSR = (1<<ISC2); /* 外部INT2的上升沿激活中断 */
    GICR |= (1<<INT2); /* 外部INT2中断使能 */
 
  //GIFR  |= (1 << INTF1) | (1 << INTF0);     //清除INT0、INT1中断标志位
 
 }
 
 void  dis_int2()//PB2
{
 

  GIFR |= (1 << INT2)  ;      //清INT2中断 

  GICR&= ~(1<<INT2); /* 外部INT2中断使能 */
 
  //GIFR  |= (1 << INTF1) | (1 << INTF0);     //清除INT0、INT1中断标志位
 
 }
  
  
  
  
  
  
  /* 
　　sleep.h里面定义的常数，对应各种睡眠模式 
　　#define SLEEP_MODE_IDLE 0 
　　空闲模式 
　　#define SLEEP_MODE_ADC _BV(SM0) 
　　ADC 噪声抑制模式 
　　#define SLEEP_MODE_PWR_DOWN _BV(SM1) 
　　掉电模式 
　　#define SLEEP_MODE_PWR_SAVE (_BV(SM0) | _BV(SM1)) 
　　省电模式 
　　#define SLEEP_MODE_STANDBY (_BV(SM1) | _BV(SM2)) 
　　Standby 模式 
　　#define SLEEP_MODE_EXT_STANDBY (_BV(SM0) | _BV(SM1) | _BV(SM2)) 
　　扩展Standby模式 
　　函数 
　　void set_sleep_mode (uint8_t mode); 
　　设定睡眠模式 
　　void sleep_mode (void); 
　　进入睡眠状态 
　　*/ 
  enter_sleep() 
{
    //initial_int2();//again  ready
  
    /* 进入空闲模式，等待INT2唤醒 */
	  sei();
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);//SLEEP_MODE_PWR_DOWN\
    sleep_enable();
    sleep_cpu();
	//dis_int2();
    sleep_disable();
 
   
   }