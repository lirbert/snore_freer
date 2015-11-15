 //adc.h
 

// library function prototypes
 
 

// this #pragma directive will tell the compiler to

// compile/link the functions from the mylib.lib library
 

#define F_CPU       8192000

#define  ADEN     7
#define  ADSC     6
#define  ADATE    5
#define  ADFR     5    /*This definition was in old datasheet*/
#define  ADIF     4
#define  ADIE     3
#define  ADPS2    2
#define  ADPS1    1
#define  ADPS0    0   

#define  ADTS2    7  
#define  ADTS1    6 
#define  ADTS0    5 

//#define ADC_VREF_TYPE 0x40  //avcc 
#define ADC_VREF_TYPE 0xc0  //internel ref 2.56v


 #define  ENERGY    40000
 #define  ENERGYover    20000000 
 #define  ENERGY_low    6000 //for test
 #define  DIFF_LOW      40
 #define  DIFF_HIGH      45
 #define   CONTINUE_PITCH 160 //80֡,2.4s
  #define  SILENT  10  // 静音间隔  15*32ms=480ms  ,80*32=2.5s 
  #define osc_address   0x1ff0  //修订的校准值在尾部

 
 
void init_timer0();
 
