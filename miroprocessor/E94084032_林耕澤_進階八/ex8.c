#include <regx51.h>
 int i=0;
 int z=0;
 int q=0;
 int t=0;
 void init_uart();
 char recivevalue;
 char a[9]={'E','9','4','0','8','4','0','3','2'};
 char b[5]={'w','r','o','n','g'};
 char c[7]={'c','o','r','r','e','c','t'};
 void main( ){
 init_uart();  
 while(1);
}

 void init_uart(void)
{
SCON=0x50;
TMOD=0x20;
TH1=0xe6;
TR1=1;
IE=0x90;
}
 void UART_Isr(void) interrupt 4
 {
   while(RI == 0);
   RI=0;
   recivevalue=SBUF;
   P2 = recivevalue;
	 if(recivevalue== a[i]){
		 i+=1;
	 }
	 else if(recivevalue==0x0D){
	   i=i;
	 }
	 else{
		 i=0;
	}
	 if(recivevalue==0x0D){
	 if(i==9){
	  
			for(z;z<7;z++){
			SBUF=c[z];
      while(TI==0);
      TI=0;
			}
			
			//for( q;q<9;q++){
			//SBUF=a[q];
      //while(TI==0);
      //TI=0;
			//}
		}
		
		
		else {
			for(t;t<5;t++){
			SBUF=b[t];
      while(TI==0);
      TI=0;	}
		}
 }
		}
		