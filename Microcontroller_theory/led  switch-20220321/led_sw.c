/*Write an ECP to cotrol the LED(AL-LED) using switch(AL-switch)*/
#include<reg51.h>
sbit AL_LED = P1^0;
sbit AL_SW  = P2^0;
void main()
{
	while(1)
	{
		if(AL_SW == 0)//read switch status
		{
			AL_LED = 0;//active-low LED is ON
    }
		else
		{
			AL_LED = 1;//active-low LED is OFF
    }	
  }
}
