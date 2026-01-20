#include<lpc21xx.h>
#include "header.h"
extern unsigned char temp,flag;
void uart0_handler(void) __irq{
	int v=U0IIR;
	v=v&0X0E;
	if(v==4){ //If Data Recived
		temp=U0RBR;
		flag=1;
	}
	VICVectAddr=0;
}
void config_uart0_intr(void){
	VICIntSelect=0;
	VICVectCntl2=6|(1<<5);//Intr SLot2
	VICVectAddr2=(unsigned int)uart0_handler;
	VICIntEnable=(1<<6);
	U0IER=1;//Enable only UART0 Rx intr
}
