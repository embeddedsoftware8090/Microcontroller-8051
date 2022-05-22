#include<reg51.h>
sbit led = P2^0;
void main()
{
	TMOD = 0X04;//COUNTER-0 MODE-0 is selected
	TR0  = 1;   //COUNTER-0  START
	while(TL0 < 5);
	led = 0;
	TR0 = 0;//stop COUNTER0
}