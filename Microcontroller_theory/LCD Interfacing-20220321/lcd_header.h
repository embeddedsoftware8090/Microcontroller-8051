#include<reg51.h>
#include"delay.h"

#define LCD_d P2
sbit rs = P1^0;
sbit rw = P1^1;
sbit en = P1^2;

void init_lcd(void);
void lcd_display(unsigned char);
void write_cmd(unsigned char);
void lcd_str(unsigned char *);
//void lcd_int(int);

/*void lcd_int(int n)
{
  signed char i=0,a[5];
	if(n==0)
		lcd_display('0');
	else
	{	
		if(n<0)
		{
			lcd_display('-');
			n=-n;
    }
     while(n>0)
      {
		   a[i++] = n%10;
		   n=n/10;
      }		
	  for(--i;i>=0;i--)
	    lcd_display(a[i]+48);
  }
}*/

void init_lcd(void)
{
	write_cmd(0x01);//TO CLEAR THE DISPLAY
	write_cmd(0x02);//TO RETURN CURSOR AND LCD TO HOME POSITION
	write_cmd(0x0c);//DISPLAY ON CURSOR OFF
	write_cmd(0x38);//8bit interface mode
	write_cmd(0x80);//select the starting address of DDRAM
}

void write_cmd(unsigned char d)
{
	LCD_d = d;//command is assigned to data pins(D0 to D7)
	rs    = 0;//command register is selected
	rw    = 0;//write to LCD
	en    = 1;//latch the data present on data pins to LCD
	delay_1ms(2);//wait for 2ms (lcd is in internal operation mode)
	en    = 0;//To re-latch the next instruction
}

void lcd_display(unsigned char d)
{
	LCD_d = d;//command is assigned to data pins(D0 to D7)
	rs    = 1;//data register is selected
	rw    = 0;//write to LCD
	en    = 1;//latch the data present on data pins to LCD
	delay_1ms(2);//wait for 2ms (lcd is in internal operation mode)
	en    = 0;//To re-latch the next byte
}
void lcd_str(unsigned char *s)
{
	unsigned char cnt=0;
	while(*s)
	{
		lcd_display(*s++);
		cnt++;
		if(cnt==16)
			write_cmd(0xc0);//select starting address of second line
	}	
}