/*Write an ECP to generate a delay of 1millisecond using Timer0 mode1*/
#include<reg51.h>
void main()
{
	/*1)select Timer function and mode of operation*/
	TMOD = 0X01;
	/************************************************/
	/*2)Set the timer to generate the required delay**/
	TH0  = 0XFC;
	TL0  = 0X18;
	/*************************************************/
	TR0 = 1;//3) start Timer0
	while(TF0 == 0);//4) wait for TF0 flag to raise or set
	TR0 = 0;//5) stop Timer0
	TF0 = 0;//clear TF0 flag
}