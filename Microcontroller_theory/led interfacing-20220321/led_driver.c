/*Write an ECP to blink 2 active-low
LEDs infinitely @100ms
Note:
assuming LEDs are connected to P1.0,P1.1*/
#include<reg51.h>
#include"delay.h"
sbit AL_LED0 = P1^0;
sbit AL_LED1 = P1^1;
void main()
{
	while(1)
	{
		AL_LED0 = 0;//ACTIVE-LOW LED0 ON
		AL_LED1 = 0;//ACTIVE-LOW LED1 ON
		delay_1ms(100);//delay of 100milliseconds
		AL_LED0 = 1;//ACTIVE-LOW LED0 OFF
		AL_LED1 = 1;//ACTIVE-LOW LED1 OFF
		delay_1ms(100);//delay of 100milliseconds
  }
}
