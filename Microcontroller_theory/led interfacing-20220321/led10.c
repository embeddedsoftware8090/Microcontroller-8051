/*Write an ECP to blink active-low
LED for 10 times @500ms
Note:
assuming LED connected to P1.0*/
#include<reg51.h>
#include"delay.h"
sbit AL_LED = P1^0;

void main()
{
	unsigned char cnt=0;
	while(cnt++<10)
	{
		AL_LED = 0;//ACTIVE-LOW LED ON
		delay_1ms(500);//delay of 500milliseconds
		AL_LED = 1;//ACTIVE-LOW LED OFF
		delay_1ms(500);//delay of 500milliseconds
  }
	//while(1);
}
