/*****************************************************
File name     : AD_onchip.c
Chip type           : ATmega16L
Program type        : Application
Clock frequency     : 4.000000 MHz
Memory model        : Small
External SRAM size  : 0
Data Stack size     : 256
Function            : �ڲ�ADת�����������ʾ
*****************************************************/

#include<mega16.h>  
#include<delay.h> 

#define hc164_data   PORTD.0  // 164������
#define hc164_clk    PORTD.1  // 164ʱ����

void hc164_send_byte (unsigned char byte);  // 164����ӳ���
void leddisplay(void);  // �������ʾ�ӳ���

unsigned char ledxs[8]={16,16,16,16,0,0,0,0}; // �������ʾ������
                //   ADת��ֵ  ǧλ   ��λ    ʮλ  ��λ 
flash unsigned char tab[]={0xb7,0x12,0x67,0x76,0xd2,0xf4,0xf5,0x16,0xf7,0xf6,0xd7,0xf1,0xa5,0x73,0xe5,0xc5,0,0xff};
                          //���������� 0-F��  ȫ��ȫ��
bit time_2ms_ok;  // 2msʱ�䵽��־

interrupt [TIM0_COMP] void timer0_comp_isr(void);  // Timer 0 �Ƚ�ƥ���жϷ���
interrupt [ADC_INT] void adc_isr(void);   // ADC ת������жϷ���

void main(void)
{
  DDRA=0x0f;
  PORTA=0x0f;    
  DDRD=0xff;      // LED��ʾ����I/O�˿ڳ�ʼ��
  // T/C0 ��ʼ��
  TCCR0=0x0B;     // �ڲ�ʱ�ӣ�64��Ƶ��4M/64=62.5KHz����CTCģʽ
  TCNT0=0x00;     
  OCR0=0x7C;      // OCR0 = 0x7C(124),(124+1)/62.5=2ms
  TIMSK=0x02;     // ����T/C0�Ƚ��ж�

  // ADC ��ʼ��
  ADMUX=0x47;     // �ο���ԴAVcc��ADC7��������
  SFIOR&=0x1F;    
  SFIOR|=0x60;    // ѡ��T/C0�Ƚ�ƥ���ж�ΪADC����Դ
  ADCSRA=0xAD;    // ADC�����Զ�����ת����ADCת���ж�����ADCclk=125Kz
  #asm("sei")     // ����ȫ���ж�

  while (1)
  {
    if (time_2ms_ok)
    {
       leddisplay();    // LED������ʾ        
       time_2ms_ok = 0;                      
       delay_ms(1000);
    }
  }
}   
// Timer 0 �Ƚ�ƥ���жϷ���
interrupt [TIM0_COMP] void timer0_comp_isr(void)
{
  time_2ms_ok = 1;
}

// ADC ת������жϷ���
interrupt [ADC_INT] void adc_isr(void)
{   
    unsigned int ad_value; 
    unsigned char adl,adh;
    adl = ADCL;
    adh = ADCH;               
    ad_value = ((unsigned int)adh<<8)|adl;  // ��ȡADת����� 
    ledxs[4] = ad_value/1000;               // ���ADת��ֵǧλ
    ledxs[5] = (ad_value%1000)/100;         // ���ADת��ֵ��λ
    ledxs[6] = (ad_value%100)/10;           // ���ADת��ֵʮλ
    ledxs[7] = (ad_value%100)%10;           // ���ADת��ֵ��λ
}
void leddisplay()        // �������ʾ�ӳ���
{
  unsigned char i;
  for(i=0;i<8;i++)
  {
     hc164_send_byte (tab[ledxs[i]]);
     delay_us(2);
  }
} 
void hc164_send_byte (unsigned char byte)    // 164����ӳ���
{
  unsigned char i;
   for(i=0;i<8;i++)
   {
      hc164_data = byte & ( 1 << i );       
      hc164_clk = 1;       
      hc164_clk = 0;   
   }  
}
