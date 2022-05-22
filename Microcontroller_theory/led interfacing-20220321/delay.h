void delay_1ms(int dly)
{
	unsigned char i;
	for(;dly>0;dly--)
	 {
	  for(i=250;i>0;i--);
	  for(i=247;i>0;i--);
	 }	 
}