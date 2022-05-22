/*Write an ECP to demonstrate switch bouncing and de-bouncing*/
#include<reg51.h>
#include"delay.h"
#define LEDS P1
sbit sw = P2^0;
void main()
{
	unsigned char POS=0;
	while(POS<8)
	{
		if(sw==0)
		{
    delay_1ms(200);//to avoid switch bouncing(switch de-bouncing)			
		LEDS = (1<<POS++)^0x0f;//shifting the leds from lsb to msb
		while(sw==0);//wait untill switch is released	
    }		
  }
}