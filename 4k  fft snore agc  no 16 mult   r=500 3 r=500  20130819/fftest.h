
/********************************************************************
*  Copyright (C), 2008-2010, yourde Institute of Technology Co.,Ltd
*  File Name:       ffttest.c
*  Author:          lizhong
*  Version:         v2.0 for snore
*  Created Date:    2013-03-9
*  Description:     main
*  Change History:        
*  <author>  <time>   <version >   <desc>
*  lizhong  13/3/1     v1.0       build this moudle
*  lizhong   13/06/9    v2.0       upgrade this moudle
*********************************************************************/











/*------------------------------------------------*/
/* FFTEST : A test program for FFT module         */
 
#include "adc.h"
#include <avr/io.h>
 #include "LED.h" 
#include <avr/pgmspace.h>//常用  PROGMEM 定义， pgm_read_byte,pgm_write_byte 

#include "suart.h"		/* Defs for using Software UART module (Debugging via AVRSP-COM) */
#include "ffft.h"		/* Defs for using Fixed-point FFT module */
 #include "pwm_tc2.h"

#define	SYSCLK		16000000 
#define SILENT_TIME  625     //为20s
#define CROSS_GAP 0     //为20s
 
typedef  struct  bit_flg
{
unsigned char pre_flag0:1; 
unsigned char pre_flag1:1;
unsigned char pre_flag2:1; 
unsigned char pre_flag3:1; 
unsigned char pitch_flg:1;
unsigned char snore_flag:1
}bit_flg; 

typedef struct judge_content {
            
				bit_flg flg;
				unsigned char signal_count;
				unsigned char count_pitch;
				unsigned char nosignal_count;
				unsigned char peak_index[4];
				 
				long unsigned int  energy;
				unsigned char diff;
                          }judge_content ;
						  
						  
						  
						  
						  
						  
						  
unsigned char  agc(unsigned char i );
						  
						  
 void  reset_check (judge_content * cont_po );