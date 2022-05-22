/*ECP to demonstrate hardware control of timers in 8051*/
#include<reg51.h>
void main()
{
	TMOD = 0X09;
	TR0  = 1;//start timer0
	while(1)
	{
		if(TF0 == 1)
			TF0 = 0;//clear TF0 flag
  }
}
