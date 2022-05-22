#include<reg51.h>

#define lcd_d P2
sbit rs = P1^0;
sbit rw = P1^1;
sbit e  = P1^2;

void delay_1ms(int);

void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void string(unsigned char *);
/*void number(int);
void float_val(float);
*/

void delay_1ms(int d)
{
	  unsigned char i;
	  for(;d>0;d--)
	   {
			  for(i=250;i>0;i--);
        for(i=250;i>0;i--);			 
     }
}
void lcd_init(void)
{
	 lcd_cmd(0x01);//clear the display
	 lcd_cmd(0x02);//bring the cursor and lcd to starting position of ddram(or home position)
	 lcd_cmd(0x0c);//display ON cursor OFF
   lcd_cmd(0x38);//8 bit interface and both the lines enabled	
	 lcd_cmd(0x80);//select ddram
}

void lcd_cmd(unsigned char c)
{
	 lcd_d = c;
	 rs    = 0;
	 rw    = 0;
	 e=1;
	 delay_1ms(2);
	 e=0;
}

void lcd_data(unsigned char d)
{
	 lcd_d = d;
	 rs    = 1;
   rw    = 0;
   e     = 1;
   delay_1ms(2);
   e=0;	
}

void string(unsigned char *p)
{
	 while(*p)
	 lcd_data(*p++);
}

/*void number(int n)
{
	 int arr[5],i=0;
	 
	  
	 if(n==0)
   lcd_data('0');
	 else
	 { 
		 if(n<0)
		 {
			 lcd_data('-');
			 n=-n;
		 } 
				 
		 while(n>0)
		 {
			 arr[i++] = n%10;
			 n=n/10;		 
		 }
		 for(--i;i>=0;i--)
			lcd_data(arr[i]+48);
		}
}*/

/*void float_val(float f)
{
	 float temp;
	  int n;
	  n=f;
	  number(n);
	  lcd_data('.');
	  temp=(f-n)*100;
	  n=temp;
    number(n);	
	 
}*/