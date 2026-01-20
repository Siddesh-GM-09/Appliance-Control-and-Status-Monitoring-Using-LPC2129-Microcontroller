#include<lpc21xx.h>
#include "header.h"
//appliances
#define AC (1<<4)
#define BULB (1<<5)
#define FAN (1<<6)
#define TV (1<<7)
unsigned char temp,flag;
int status_ac=0,status_bulb=0,status_fan=0,status_tv=0; //Flag to Monitor appliances
int main(){
	lcd_init();
	uart0_init(9600);
	config_uart0_intr();
	IODIR0|=BULB|FAN|AC|TV;
	IOSET0|=BULB|FAN|AC|TV;
	uart0_tx_string("Menu : \r\n");
	uart0_tx_string("A.ON AC\r\n");
	uart0_tx_string("a.OFF AC\r\n");
	uart0_tx_string("B.On Bulb\r\n");
	uart0_tx_string("b.OFF Bulb\r\n");
	uart0_tx_string("F.ON Fan\r\n");
	uart0_tx_string("f.OFF Fan\r\n");
	uart0_tx_string("T.ON TV\r\n");
	uart0_tx_string("t. OFF TV\r\n");
	uart0_tx_string("Enter the Option : ");
	while(1){
		if(flag==1){
			flag=0;
			uart0_tx(temp);
			lcd_cmd(0X80);
			switch(temp){
				case 'A' :IOCLR0=AC;
				lcd_string("AC ON");
				status_ac=1;
				break;
				case 'a' :IOSET0=AC;
				lcd_string("AC OFF");
				status_ac=0;
				break;
				case 'B' :IOCLR0=BULB;
				lcd_string("BULB ON");
				status_bulb=1;
				break;
				case 'b' : IOSET0=BULB;
				lcd_string("BULB OFF");
				status_bulb=0;
				break;
				case 'F' : IOCLR0=FAN;
				lcd_string("FAN ON");
				status_fan=1;
				break;
				case 'f' : IOSET0=FAN;
				lcd_string("FAN OFF");
				status_fan=0;
				break;
				case 'T' : IOCLR0=TV;
				lcd_string("TV ON");
				status_tv=1;
				break;
				case 't' :IOSET0=TV;
				lcd_string("TV OFF");
				status_tv=0;
				break;
				default:uart0_tx_string("Enter Valid Option\r\n");
			}
			//Status of appliances
			uart0_tx_string("\r\n------ STATUS ------\r\n");
        uart0_tx_string(status_ac   ? "AC   : ON\r\n"   : "AC   : OFF\r\n");
        uart0_tx_string(status_bulb ? "BULB : ON\r\n"   : "BULB : OFF\r\n");
        uart0_tx_string(status_fan  ? "FAN  : ON\r\n"   : "FAN  : OFF\r\n");
        uart0_tx_string(status_tv   ? "TV   : ON\r\n"   : "TV   : OFF\r\n");
        uart0_tx_string("--------------------\r\n");
        uart0_tx_string("Enter the Option : ");
		}
	}
}
