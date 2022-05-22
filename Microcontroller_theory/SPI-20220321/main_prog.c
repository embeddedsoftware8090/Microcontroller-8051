/*write an ECP to read ADC(MCP3204)
readings and display it on LCD*/
#include"lcd.c"
#include"mcp3204.h"
void main()
{
	lcd_init();
	string("mcp-3204...");
	
  while(1)
	{	
	lcd_cmd(0xc0);
	float_val(spi_adc_read(0,0));
	lcd_data('v');	
	}
}
