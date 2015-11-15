/*****************************************************
File name     : AD_onchip.c
Chip type           : ATmega16L
Program type        : Application
Clock frequency     : 4.000000 MHz
Memory model        : Small
External SRAM size  : 0
Data Stack size     : 256
Function            : 内部AD转换，数码管显示
*****************************************************/

#include<mega16.h>  
#include<delay.h> 

#define hc164_data   PORTD.0  // 164数据线
#define hc164_clk    PORTD.1  // 164时钟线

void hc164_send_byte (unsigned char byte);  // 164输出子程序
void leddisplay(void);  // 数码管显示子程序

unsigned char ledxs[8]={16,16,16,16,0,0,0,0}; // 数码管显示缓冲区
                //   AD转换值  千位   百位    十位  个位 
flash unsigned char tab[]={0xb7,0x12,0x67,0x76,0xd2,0xf4,0xf5,0x16,0xf7,0xf6,0xd7,0xf1,0xa5,0x73,0xe5,0xc5,0,0xff};
                          //共阴极代码 0-F，  全灭，全亮
bit time_2ms_ok;  // 2ms时间到标志

interrupt [TIM0_COMP] void timer0_comp_isr(void);  // Timer 0 比较匹配中断服务
interrupt [ADC_INT] void adc_isr(void);   // ADC 转换完成中断服务

void main(void)
{
  DDRA=0x0f;
  PORTA=0x0f;    
  DDRD=0xff;      // LED显示控制I/O端口初始化
  // T/C0 初始化
  TCCR0=0x0B;     // 内部时钟，64分频（4M/64=62.5KHz），CTC模式
  TCNT0=0x00;     
  OCR0=0x7C;      // OCR0 = 0x7C(124),(124+1)/62.5=2ms
  TIMSK=0x02;     // 允许T/C0比较中断

  // ADC 初始化
  ADMUX=0x47;     // 参考电源AVcc、ADC7单端输入
  SFIOR&=0x1F;    
  SFIOR|=0x60;    // 选择T/C0比较匹配中断为ADC触发源
  ADCSRA=0xAD;    // ADC允许、自动触发转换、ADC转换中断允许、ADCclk=125Kz
  #asm("sei")     // 开放全局中断

  while (1)
  {
    if (time_2ms_ok)
    {
       leddisplay();    // LED串行显示        
       time_2ms_ok = 0;                      
       delay_ms(1000);
    }
  }
}   
// Timer 0 比较匹配中断服务
interrupt [TIM0_COMP] void timer0_comp_isr(void)
{
  time_2ms_ok = 1;
}

// ADC 转换完成中断服务
interrupt [ADC_INT] void adc_isr(void)
{   
    unsigned int ad_value; 
    unsigned char adl,adh;
    adl = ADCL;
    adh = ADCH;               
    ad_value = ((unsigned int)adh<<8)|adl;  // 读取AD转换结果 
    ledxs[4] = ad_value/1000;               // 求得AD转换值千位
    ledxs[5] = (ad_value%1000)/100;         // 求得AD转换值百位
    ledxs[6] = (ad_value%100)/10;           // 求得AD转换值十位
    ledxs[7] = (ad_value%100)%10;           // 求得AD转换值个位
}
void leddisplay()        // 数码管显示子程序
{
  unsigned char i;
  for(i=0;i<8;i++)
  {
     hc164_send_byte (tab[ledxs[i]]);
     delay_us(2);
  }
} 
void hc164_send_byte (unsigned char byte)    // 164输出子程序
{
  unsigned char i;
   for(i=0;i<8;i++)
   {
      hc164_data = byte & ( 1 << i );       
      hc164_clk = 1;       
      hc164_clk = 0;   
   }  
}
