/*Write an ECP to transmit string  "Embedded" serially through UART 
of 8051  to serial port of PC
Note: assume C.F =11.0592MHZ,SMOD=0, baud rate =9600*/
#include<reg51.h>
void init_uart(void);
void uart_transmit(unsigned char);
unsigned char uart_receive(void);
void uart_str(unsigned char *);
void main()
{
	 init_uart();
	 uart_str("Embedded");
	 while(1);
}
void init_uart(void)
{
	/**i)select 8N1 frame format**/
	 SCON =  0X50; 
	/***************************/
	/**ii)Set the baud rate as 9600**/
	 TMOD  = 0X20;
	 TH1 = TL1 = 253;
	 TR1 = 1;
	/********************************/
}
void uart_transmit(unsigned char d)
{
	 SBUF = d; //Initiate or start the transmission by assigning data to SBUF
	 while(TI == 0);//wait untill the transmission is completed 
	 TI = 0;//clear TI flag 
}

unsigned char uart_receive(void)
{
	while(RI == 0); //wait till the RI flag is SET or raised
	RI = 0 ;//clear RI flag
	return SBUF;
}
void uart_str(unsigned char *s)
{
	while(*s)
		uart_transmit(*s++);
}
