/*! \file spi.c \brief SPI interface driver. */
//*****************************************************************************
//
// File Name	: 'spi.c'
// Title		: SPI interface driver
// Author		: Pascal Stang - Copyright (C) 2000-2002
// Created		: 11/22/2000
// Revised		: 06/06/2002
// Version		: 0.6
// Target MCU	: Atmel AVR series
// Editor Tabs	: 4
//
// NOTE: This code is currently below version 1.0, and therefore is considered
// to be lacking in some functionality or documentation, or may not be fully
// tested.  Nonetheless, you can expect most functions to work.
//
// This code is distributed under the GNU Public License
//		which can be found at http://www.gnu.org/licenses/gpl.txt
//
//*****************************************************************************
//#include <mega32.h> 
#include <avr/io.h>

// #include <interrupt.h>

 
#include "spi.h"

// Define the SPI_USEINT key if you want SPI bus operation to be
// interrupt-driven.  The primary reason for not using SPI in
// interrupt-driven mode is if the SPI send/transfer commands
// will be used from within some other interrupt service routine
// or if interrupts might be globally turned off due to of other
// aspects of your program
//
// Comment-out or uncomment this line as necessary
//#define SPI_USEINT

// global variables
volatile u08 spiTransferComplete;


// SPI interrupt service handler
#ifdef SPI_USEINT
SIGNAL(SIG_SPI)
{
	spiTransferComplete = TRUE;
}
#endif

// access routines
void MMC_spi_Init(char speed)
//****************************************************************************
{
  if  (speed==0 )                //Set MMC_Chip_Select to High,MMC/SD Invalid.
  SPCR |=0x03;//fosc/128
  else 
  SPCR &=0xfc;//fosc/4
}




void spiInit(void)
{

  PORTB = 0xb0;//0
          DDRB  = 0xb0;    //PB6 输入 其余输出
          
// #ifdef __AVR_ATmega128__
// 	// setup SPI I/O pins
// 	sbi(PORTB, 1);	// set SCK hi
// 	sbi(DDRB, 1);	// set SCK as output
// 	cbi(DDRB, 3);	// set MISO as input
// 	sbi(DDRB, 2);	// set MOSI as output
// 	sbi(DDRB, 0);	// SS must be output for Master mode to work
// #elif __AVR_ATmega8__
//     // setup SPI I/O pins
//     sbi(PORTB, 5);  // set SCK hi
//     sbi(DDRB, 5);   // set SCK as output
//     cbi(DDRB, 4);   // set MISO as input
//     sbi(DDRB, 3);   // set MOSI as output
//     sbi(DDRB, 2);   // SS must be output for Master mode to work
// #else
// 	// setup SPI I/O pins
// 	sbi(PORTB, 7);	// set SCK hi
// 	sbi(DDRB, 7);	// set SCK as output
// 	cbi(DDRB, 6);	// set MISO as input
// 	sbi(DDRB, 5);	// set MOSI as output
// 	sbi(DDRB, 4);	// SS must be output for Master mode to work
// #endif
// 	
// 	// setup SPI interface :
// 	// master mode
// 	sbi(SPCR, MSTR);
// 	// clock = f/4
// //	cbi(SPCR, SPR0);
// //	cbi(SPCR, SPR1);
// 	// clock = f/16
// 	cbi(SPCR, SPR0);
// 	sbi(SPCR, SPR1);
// 	// select clock phase positive-going in middle of data
// 	cbi(SPCR, CPOL);

// SPI initialization
// SPI Type: Master
// SPI Clock Rate: 2*2048.000 kHz
// SPI Clock Phase: Cycle Half
// SPI Clock Polarity: Low
// SPI Data Order: MSB First    

//  fosc/32  // for kingstone
 //SPCR=0x50;//0101 0000  Bit 6 – SPE: 使能SPI,Bit 4 – MSTR: 主/ 从选择 fosc/4   
 //SPCR=0x51;//0101 0001  Bit 6 – SPE: 使能SPI,Bit 4 – MSTR: 主/ 从选择 fosc/16
//cpol=0  raising
  SPCR=0x52;//0101 0010  Bit 6 – SPE: 使能SPI,Bit 4 – MSTR: 主/ 从选择 fosc/64 ingston 256M 需要低速 ok
  

//SPCR=0x53;//0101 0011  Bit 6 – SPE: 使能SPI,Bit 4 – MSTR: 主/ 从选择 fosc/128  //kingston 256M 需要低速ok
//SPSR=0x01;//double speed;       ///so   fosc/32 in   //kingsdon //
 // SPSR=0x00;//single speed;       ///so   fosc/64 in //sandisk   transcend    
  
    ////   //sandisk   low speed
    
 //   SPCR=0x53;//0101 0011  Bit 6 – SPE: 使能SPI,Bit 4 – MSTR: 主/ 从选择 fosc/128  //kingston 256M 需要低速ok
 SPSR=0x01;//double speed;       ///so   fosc/32 in   //kingsdon
 //SPSR=0x00;//single speed;       ///so   fosc/64 in 
  
  
  
  //sandisk  
// /* 设置MOSI 和SCK 为输出，其他为输入*/
// DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
// /* 使能SPI 主机模式，设置时钟速率为fck/16 */
// SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
// 	// Data order MSB first
// 	cbi(SPCR,DORD);
// 	// enable SPI
// 	sbi(SPCR, SPE);
// 		
// 	
// 	// some other possible configs
// 	//outp((1<<MSTR)|(1<<SPE)|(1<<SPR0), SPCR );
// 	//outp((1<<CPHA)|(1<<CPOL)|(1<<MSTR)|(1<<SPE)|(1<<SPR0)|(1<<SPR1), SPCR );
// 	//outp((1<<CPHA)|(1<<MSTR)|(1<<SPE)|(1<<SPR0), SPCR );
// 	
// 	// clear status
// 	inb(SPSR);
// 	spiTransferComplete = TRUE;
// 
// 	// enable SPI interrupt
// 	#ifdef SPI_USEINT
// 	sbi(SPCR, SPIE);
// 	#endif


 // CLI();

          //低功耗策略 
       // PORTA = 0xf0;    //PA0-PA3禁止上拉电阻防止影响AD627           
       //   DDRA  = 0xf0;    //PA0-PA3输入，其余输出
         
         
}



void spi_345(void)
{
SPCR|=0x0c; //cpol=1.   cpha=1
}
/*
void spiSetBitrate(u08 spr)
{
	outb(SPCR, (inb(SPCR) & ((1<<SPR0)|(1<<SPR1))) | (spr&((1<<SPR0)|(1<<SPR1)))));
}
*/    

void spiSendByte(u08 data)
{
	// send a byte over SPI and ignore reply
	#ifdef SPI_USEINT
		while(!spiTransferComplete);
		spiTransferComplete = FALSE;
	#else
// 		while(!(inb(SPSR) & (1<<SPIF))); 
 

SPDR=data;
while((SPSR & 0x80)==0);
	#endif

// 	outb(SPDR, data);
}

u08 spiTransferByte(u08 data)
{
	#ifdef SPI_USEINT
	// send the given data
	spiTransferComplete = FALSE;
	SPDR=data;//outb(SPDR, data);
	// wait for transfer to complete
	while(!spiTransferComplete);
	#else
	// send the given data
	SPDR=data;//outb(SPDR, data);
	// wait for transfer to complete
// 	while(!(inb(SPSR) & (1<<SPIF)));
while(!(SPSR & (1<<SPIF)));
	#endif
	// return the received data
	return (SPDR);
}

u16 spiTransferWord(u16 data)
{
	u16 rxData = 0;

	// send MS byte of given data
	rxData = (spiTransferByte((data>>8) & 0x00FF))<<8;
	// send LS byte of given data
	rxData |= (spiTransferByte(data & 0x00FF));

	// return the received data
	return rxData;
}


char spigetByte ( )
{     
spiSendByte(0xff);
	return SPDR;;   
	
	}





