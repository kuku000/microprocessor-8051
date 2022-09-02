#include <regx51.h>

 void main( )
 {
 while(1)
 {
 if(P1==255)
	P2=0xff;
 else if(P1 >256 / 2)
	P2=0xfe;
 else if(P1 >256 / 3) //if P1 greater than 256/2
 P2 =0xfc; //LED on
 else if(P1>256/4)
 P2=0xf8;
 else if(P1>256/5)
 P2=0xf0;
 else if(P1>256/6)
 P2=0xe0;
 else if(P1>256/7)
 P2=0xc0;
 else if(P1>256/8)
P2=0x80;
 else if(P1>256/9)
 P2=0x00;
  
 
 }
 }