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
  
  WritData_345(0x1E,0x00);  //X轴误差补偿; (15.6mg/LSB)
  WritData_345(0x1F,0x00);  //Y轴误差补偿; (15.6mg/LSB)
  WritData_345(0x20,0x00);  //Z轴误差补偿; (15.6mg/LSB)
  
  WritData_345(0x21,0x00);  //敲击延时0:禁用; (1.25ms/LSB)
  WritData_345(0x22,0x00);  //检测第一次敲击后的延时0:禁用; (1.25ms/LSB)
  WritData_345(0x23,0x00);  //敲击窗口0:禁用; (1.25ms/LSB)
  
  WritData_345(0x24,0x01);  //保存检测活动阀值; (62.5mg/LSB)
  WritData_345(0x25,0x01);  //保存检测静止阀值; (62.5mg/LSB)
  WritData_345(0x26,0x2B);  //检测活动时间阀值; (1s/LSB)
  WritData_345(0x27,0x00);  //
  WritData_345(0x28,0x09);  //自由落体检测推荐阀值; (62.5mg/LSB)
  WritData_345(0x29,0xFF);  //自由落体检测时间阀值,设置为最大时间; (5ms/LSB)
  WritData_345(0x2A,0x80);  //
  //SPI_Read(0x2B);    //只读寄存器,状态读取
  WritData_345(0x2C,0x0A);  //
  WritData_345(0x2D,0x28);  //开启Link,测量功能;关闭自动休眠,休眠,唤醒功能
  WritData_345(0x2E,0x00);  //所有均关闭
  WritData_345(0x2F,0x00);  //中断功能设定,不使用中断
  //SPI_Read(0x30);    //只读寄存器,状态读取
  WritData_345(0x38,0x81);  //FIFO模式设定,Stream模式，触发连接INT1,31级样本缓冲
  //SPI_Read(0x39);    //只读寄存器,状态读取
                
}
 