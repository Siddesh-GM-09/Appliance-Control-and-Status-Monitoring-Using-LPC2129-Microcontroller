#include <lpc21xx.h>
#include "header.h"

// appliances
#define AC   (1<<4)
#define BULB (1<<5)
#define FAN  (1<<6)
#define TV   (1<<7)

unsigned char temp, flag;

int status_ac=0, status_bulb=0, status_fan=0, status_tv=0; // Monitor appliances

// ---------- LCD HANDLING  ----------
void lcd_clear(void){
    lcd_cmd(0x01);      // Clear display
    delay_ms(2);        //clear needs ~1.5–2ms
}
void lcd_goto(unsigned char pos){
    lcd_cmd(pos);       // 0x80 line1, 0xC0 line2 (for 16x2)
}
void lcd_show_status(const char *dev, unsigned char on){
    lcd_clear();
    lcd_goto(0x80);
    lcd_string(dev);        // Device name on line 1
    lcd_goto(0xC0);
    if(on){
			lcd_string("STATUS: ON ");
		}
    else{
			lcd_string("STATUS: OFF");
		}
}
// ---------------------------------------------
int main(){
    lcd_init();
    uart0_init(9600);
    config_uart0_intr();
	
    IODIR0 |= (BULB|FAN|AC|TV);
    IOSET0 |= (BULB|FAN|AC|TV);   // Initially OFF if active-low relays/LEDs
	
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
	
    lcd_show_status("READY", 1);
    while(1){
        if(flag == 1){
            flag = 0;
            uart0_tx(temp);
            switch(temp){
                case 'A':
                    IOCLR0 = AC;
                    status_ac = 1;
                    lcd_show_status("AC", 1);
                    break;
                case 'a':
                    IOSET0 = AC;
                    status_ac = 0;
                    lcd_show_status("AC", 0);
                    break;
                case 'B':
                    IOCLR0 = BULB;
                    status_bulb = 1;
                    lcd_show_status("BULB", 1);
                    break;
                case 'b':
                    IOSET0 = BULB;
                    status_bulb = 0;
                    lcd_show_status("BULB", 0);
                    break;
                case 'F':
                    IOCLR0 = FAN;
                    status_fan = 1;
                    lcd_show_status("FAN", 1);
                    break;
                case 'f':
                    IOSET0 = FAN;
                    status_fan = 0;
                    lcd_show_status("FAN", 0);
                    break;
                case 'T':
                    IOCLR0 = TV;
                    status_tv = 1;
                    lcd_show_status("TV", 1);
                    break;
                case 't':
                    IOSET0 = TV;
                    status_tv = 0;
                    lcd_show_status("TV", 0);
                    break;
                default:
                    uart0_tx_string("Enter Valid Option\r\n");
                    lcd_clear();
                    lcd_goto(0x80);
                    lcd_string("INVALID OPTION");
                    lcd_goto(0xC0);
                    lcd_string("TRY AGAIN");
                    break;
            }
            // Status of appliances over UART
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