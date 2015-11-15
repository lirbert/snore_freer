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

DDRB &= 0xFB;    /*PB2 ��������*/ 
    PORTB&=0xFB ;   /*��ƽ����  ���� ���߻�һֱΪ1 */ 

  GIFR |= (1 << INT2)  ;      //��INT2�ж� 

      GICR &= ~(1<<INT2); /* �ⲿINT2�ж��Ƚ�ֹ�������޸�ISC2 �����ж� */
   MCUCSR = (1<<ISC2); /* �ⲿINT2�������ؼ����ж� */
    GICR |= (1<<INT2); /* �ⲿINT2�ж�ʹ�� */
 
  //GIFR  |= (1 << INTF1) | (1 << INTF0);     //���INT0��INT1�жϱ�־λ
 
 }
 
 void  dis_int2()//PB2
{
 

  GIFR |= (1 << INT2)  ;      //��INT2�ж� 

  GICR&= ~(1<<INT2); /* �ⲿINT2�ж�ʹ�� */
 
  //GIFR  |= (1 << INTF1) | (1 << INTF0);     //���INT0��INT1�жϱ�־λ
 
 }
  
  
  
  
  
  
  /* 
����sleep.h���涨��ĳ�������Ӧ����˯��ģʽ 
����#define SLEEP_MODE_IDLE 0 
��������ģʽ 
����#define SLEEP_MODE_ADC _BV(SM0) 
����ADC ��������ģʽ 
����#define SLEEP_MODE_PWR_DOWN _BV(SM1) 
��������ģʽ 
����#define SLEEP_MODE_PWR_SAVE (_BV(SM0) | _BV(SM1)) 
����ʡ��ģʽ 
����#define SLEEP_MODE_STANDBY (_BV(SM1) | _BV(SM2)) 
����Standby ģʽ 
����#define SLEEP_MODE_EXT_STANDBY (_BV(SM0) | _BV(SM1) | _BV(SM2)) 
������չStandbyģʽ 
�������� 
����void set_sleep_mode (uint8_t mode); 
�����趨˯��ģʽ 
����void sleep_mode (void); 
��������˯��״̬ 
����*/ 
  enter_sleep() 
{
    //initial_int2();//again  ready
  
    /* �������ģʽ���ȴ�INT2���� */
	  sei();
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);//SLEEP_MODE_PWR_DOWN\
    sleep_enable();
    sleep_cpu();
	//dis_int2();
    sleep_disable();
 
   
   }