#include<regx51.h>
void delay (int);
void turn ();

code char half_phase[] = {0x09,0x08,0x0c,0x04,0x06,0x02,0x03,0x01};
code char half_phase2[] = {0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};
int dir ,  delay_time;
void main ()
{
	IE=0x85;


	delay_time = 300;


	dir = 1;
while(1)
{
	turn();
}
}

void turn() {
	int x;
	if(dir ==1) //one phase, turn right
	{
		for(x=0;x<8;x++)
		{
			P1=half_phase[x];
			delay(delay_time);
		}
	}
	else //two phase, turn left
	{
		for(x=0;x<8;x++)
		{
			P1=half_phase2[x];
			delay(delay_time);
	 }
}
}

void my_external_interrupt_0_routine(void) interrupt 0 
{  
	 delay(20000);
	
   if(dir==1)
	  dir=0;
   else
		dir=1;
 }
void my_external_interrupt_1_routine(void) interrupt 2
{ 
	delay(20000);
	
  if(delay_time==300)
		delay_time=1000;
	else
		delay_time=300;
}
void delay(int t)
{
while(t--);
}