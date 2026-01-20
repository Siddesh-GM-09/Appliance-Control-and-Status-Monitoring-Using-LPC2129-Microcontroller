extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init();
extern void lcd_string(char *ptr);
extern void lcd_integer(int num);
extern void delay_sec(unsigned char sec);
extern void delay_ms(unsigned char ms);
extern void uart0_init(unsigned int baud); 
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx();
extern void uart0_integer(int num);
extern void uart0_rx_string(char *ptr,int len);
extern void uart0_tx_string(char *ptr);
extern void config_uart0_intr(void);
extern unsigned char temp,flag;

