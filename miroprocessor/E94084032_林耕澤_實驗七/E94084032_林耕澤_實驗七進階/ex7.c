#include <regx51.h> // include header file for 8051
 #define TH0_init 0x37 //TH0_init= 256 - 250
 #define TL0_init 0x05 //TL0_init = 256 - 250
 #define Timer0_int_exe_time 10 //the parameter can be changed
  
 int counter;
 
 
void main( )
 {
 TMOD =0x09; //set timer0 to mode 2(8-bits and auto-reload)
 IP = 0x02; //timer0 interrupt has high priority
 IE = 0x82; //enable timer0 interrupt
 P2 = 0xfe;
 TL0 = TL0_init; TH0 = TH0_init; //set TH0 & TL0
 TCON = 0x10; //enable timer0
 INT0=0x00; 
	while (1);

 }
  
 void timer0_interrupt(void) interrupt 1 // ?nterrupt 1?is int vector of INT0
 {
	if(INT0==1){
 counter++;
 if (counter == Timer0_int_exe_time) //250clock cycle * 2000 = 0.5 second
 {
	 
 P2=(P2<<1)|(P2>>7);
	 
 counter = 0;
 TH0=TH0_init;  
 TL0=TL0_init;  
 }
 }
	}
 //delay function
  