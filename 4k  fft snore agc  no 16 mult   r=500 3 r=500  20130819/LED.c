 
 
 
 #include "LED.h" 
 #include <util/delay.h>
 #include <avr/io.h>
 
 
#define   LED_SNORE    0
#define    LED_TESTOK    1
#define    POWER_ON    3

void  LED_snore(void)//PB0 low light
{//上电默认DDRx=0x00,PORTx=0x00 输入，无上拉电阻
//不用的管脚使能内部上拉电阻
//PORTB| = 0x01;//PB0 内部上啦
 DDRB|=0x01;//PB0 方向输出
 
PORTB&=~(1<<LED_SNORE); //点亮LED
 stop_adc();

_delay_ms(1000);;//3秒 
PORTB|=(1<<LED_SNORE); //熄灭LED
enable_adc();
/*
端口引脚
进入休眠模式时，所有的端口引脚都应该配置为只消耗最小的功耗。
最重要的是避免驱动电阻性负载。
在休眠模式下I/O 时钟clkI/O 和ADC 时钟clkADC 都被停止了，输入缓冲器也禁止了，从而保证输入电路不会消耗电流。
在某些情况下输入逻辑是使能的，用来检测唤醒条件。用于此功能的具体引脚请参见“ 数字输入使能和休眠模式” 。
如果输入缓冲器是使能的，此时输入不能悬空，信号电平也不应该接近VCC/2，否则输入缓冲器会消耗额外的电流。
 */
 
 
 
 } 
 
void  LED_all_right(void)//PB1 low light
 {
 
DDRB|= 0x02;//PB1 方向输出
 
PORTB&=~(1<<LED_TESTOK); //点亮LED
_delay_ms(1000);;//3秒
PORTB|=(1<<LED_TESTOK); //熄灭LED

 }
 
  
void  power_on(void)//PB3 low light
 {
 
DDRB|= 0x08;//PB3 方向输出
 
PORTB&=~(1<<POWER_ON); //点亮LED


 }
 
 void  power_off(void)//PB1 low light
 {
 
DDRB|= 0x08;//PB3 方向输出
 
PORTB|=(1<<POWER_ON); //关闭mos
_delay_ms(100);;//3秒

DDRB&= ~(1<<POWER_ON);// 悬空
PORTB&= ~(1<<POWER_ON);// 悬空
/**/
 }
  