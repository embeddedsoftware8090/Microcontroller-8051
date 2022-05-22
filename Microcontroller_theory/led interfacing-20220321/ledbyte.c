/*Write an ECP to shift the LEDS from right to left one by one @500ms
Note: assume 4 active low LEDS connected to lower nibble of P1
       4 active-high leds connected to upper nibble of P1*/
#include<reg51.h>
#include"delay.h"
#define LEDS P1
void main()
{
	unsigned char POS=0;
	while(POS<8)
	{
		LEDS = (1<<POS++)^0x0f;
    delay_1ms(500);		
  }
}
