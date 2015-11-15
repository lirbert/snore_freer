 
 
 
 #include "LED.h" 
 #include <util/delay.h>
 #include <avr/io.h>
 
 
#define   LED_SNORE    0
#define    LED_TESTOK    1
#define    POWER_ON    3

void  LED_snore(void)//PB0 low light
{//�ϵ�Ĭ��DDRx=0x00,PORTx=0x00 ���룬����������
//���õĹܽ�ʹ���ڲ���������
//PORTB| = 0x01;//PB0 �ڲ�����
 DDRB|=0x01;//PB0 �������
 
PORTB&=~(1<<LED_SNORE); //����LED
 stop_adc();

_delay_ms(1000);;//3�� 
PORTB|=(1<<LED_SNORE); //Ϩ��LED
enable_adc();
/*
�˿�����
��������ģʽʱ�����еĶ˿����Ŷ�Ӧ������Ϊֻ������С�Ĺ��ġ�
����Ҫ���Ǳ������������Ը��ء�
������ģʽ��I/O ʱ��clkI/O ��ADC ʱ��clkADC ����ֹͣ�ˣ����뻺����Ҳ��ֹ�ˣ��Ӷ���֤�����·�������ĵ�����
��ĳЩ����������߼���ʹ�ܵģ�������⻽�����������ڴ˹��ܵľ���������μ��� ��������ʹ�ܺ�����ģʽ�� ��
������뻺������ʹ�ܵģ���ʱ���벻�����գ��źŵ�ƽҲ��Ӧ�ýӽ�VCC/2���������뻺���������Ķ���ĵ�����
 */
 
 
 
 } 
 
void  LED_all_right(void)//PB1 low light
 {
 
DDRB|= 0x02;//PB1 �������
 
PORTB&=~(1<<LED_TESTOK); //����LED
_delay_ms(1000);;//3��
PORTB|=(1<<LED_TESTOK); //Ϩ��LED

 }
 
  
void  power_on(void)//PB3 low light
 {
 
DDRB|= 0x08;//PB3 �������
 
PORTB&=~(1<<POWER_ON); //����LED


 }
 
 void  power_off(void)//PB1 low light
 {
 
DDRB|= 0x08;//PB3 �������
 
PORTB|=(1<<POWER_ON); //�ر�mos
_delay_ms(100);;//3��

DDRB&= ~(1<<POWER_ON);// ����
PORTB&= ~(1<<POWER_ON);// ����
/**/
 }
  