sbit cs   = P1^6;
sbit mosi = P1^4;
sbit miso = P1^5;
sbit clk  = P1^3;
float spi_adc_read(bit d1,bit d0)
{
	unsigned int adc_val=0;char j;
	cs = 0;//chip select communication start
  clk=0;mosi=1;clk=1;//when cs=0 and mosi=1 it constitute a start bit
	clk=0;mosi=1;clk=1;//single ended mode
  clk=0;clk=1;//d2 is dont care in MCP3204
  clk=0;mosi=d1;clk=1;
	clk=0;mosi=d0;clk=1;
	clk=0;clk=1;//sampling
  clk=0;clk=1;//null bit
	/** read 12bit digital code**/
  for(j=11;j>=0;j--)
  {
		clk=0;
		if(miso)
			adc_val|=(1<<j);
		clk=1;
  }
  /******************************/	
	cs =1;//communication stop
	return ((adc_val*5.0)/4096);
}

