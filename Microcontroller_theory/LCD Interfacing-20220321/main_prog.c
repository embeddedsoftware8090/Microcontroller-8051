/*Write an ECP to display 2 custom symbols on alphanumeric LCD using 8051*/
#include"lcd_header.h"
unsigned char cgram_lut[]=
   {
    0x17,0x14,0x14,0x1f,0x05,0x05,0x1d,0x00,
	  0x0e,0x1b,0x11,0x11,0x11,0x11,0x1f,0x00
   };
void cgram_write(void);
void main()
{
  init_lcd();//Initialising the LCD
	lcd_str("custom symbols:");
  cgram_write();
	while(1)
	{
   write_cmd(0xc0);	//select DDRAM 	
	 lcd_display(0);//custom symbol-0 display
	 lcd_display(1);//custom symbol-1 display
  }	
}
void cgram_write(void)
{
	unsigned char j;
	write_cmd(0x40);//select starting address of CGRAM
	/*To write custom bytes to CGRAM */
	for(j=0;j<16;j++)
	 lcd_display(cgram_lut[j]);
	/***********************************/
}











