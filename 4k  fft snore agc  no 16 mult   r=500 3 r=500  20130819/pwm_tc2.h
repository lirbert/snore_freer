

 #include <avr/io.h>
#include <util/delay.h>
void timer2_init(void);
void pwm_en(void);
void pwm_stop(void);
void pwmini(void) ;
void moter(unsigned char i);
#define MOTION_JUDGE 80
