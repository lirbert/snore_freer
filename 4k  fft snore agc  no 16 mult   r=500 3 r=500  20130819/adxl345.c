#include "adxl345.h"

void cs_l ()
{
 PORTB&=0xef; //set 0
 }
 
void cs_h ()
{

 PORTB|=0x10 ; //set 1
 }

 


void  WritData_345(unsigned  char address,unsigned  char data)

{ unsigned  char   addr= address&0x7f;//reset MB bit     single
cs_l();
spiSendByte(addr );//0x0111   set write bit
spiSendByte(data);
cs_h();

}
void readData_345(unsigned  char address,unsigned  char data)

{ unsigned  char   addr= address|0x80;//set read bit
cs_l();
spiSendByte(addr);//0x1000   reset MB bit   single
data=spigetByte();
cs_h();

}

void readxyz_345(unsigned  char * data )//MB =1

{ unsigned  char   addr= 0x32|0xc0 ;//set read bit//0x1100   set MB bit   single
unsigned char i;
cs_l();


spiSendByte(addr);
for(i=0;i<6;i++)
*data++=spigetByte();
cs_h();

}






 
void ADXL345_config(void)
{   unsigned  char i;
spiInit();
spi_345();
readData_345(0,i);
  //WritData_345(0x31,0x2b);
  
  WritData_345(0x1E,0x00);  //X������; (15.6mg/LSB)
  WritData_345(0x1F,0x00);  //Y������; (15.6mg/LSB)
  WritData_345(0x20,0x00);  //Z������; (15.6mg/LSB)
  
  WritData_345(0x21,0x00);  //�û���ʱ0:����; (1.25ms/LSB)
  WritData_345(0x22,0x00);  //����һ���û������ʱ0:����; (1.25ms/LSB)
  WritData_345(0x23,0x00);  //�û�����0:����; (1.25ms/LSB)
  
  WritData_345(0x24,0x01);  //��������ֵ; (62.5mg/LSB)
  WritData_345(0x25,0x01);  //�����⾲ֹ��ֵ; (62.5mg/LSB)
  WritData_345(0x26,0x2B);  //���ʱ�䷧ֵ; (1s/LSB)
  WritData_345(0x27,0x00);  //
  WritData_345(0x28,0x09);  //�����������Ƽ���ֵ; (62.5mg/LSB)
  WritData_345(0x29,0xFF);  //����������ʱ�䷧ֵ,����Ϊ���ʱ��; (5ms/LSB)
  WritData_345(0x2A,0x80);  //
  //SPI_Read(0x2B);    //ֻ���Ĵ���,״̬��ȡ
  WritData_345(0x2C,0x0A);  //
  WritData_345(0x2D,0x28);  //����Link,��������;�ر��Զ�����,����,���ѹ���
  WritData_345(0x2E,0x00);  //���о��ر�
  WritData_345(0x2F,0x00);  //�жϹ����趨,��ʹ���ж�
  //SPI_Read(0x30);    //ֻ���Ĵ���,״̬��ȡ
  WritData_345(0x38,0x81);  //FIFOģʽ�趨,Streamģʽ����������INT1,31����������
  //SPI_Read(0x39);    //ֻ���Ĵ���,״̬��ȡ
                
}
 