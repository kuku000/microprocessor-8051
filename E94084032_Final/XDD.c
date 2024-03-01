#include<regx51.h>
#include<string.h>
//unsigned int sp=1843; //100Hz===>9216,????20%=9216*0.2=1843?????

//unsigned int sn=7373; //????80%=9216*0.8=7373?????

//unsigned int temp;  //????????


void print_msg(char *);
void write(char, int);
void delay(unsigned int);
void init_uart();
char recivevalue;
char a[] = {'e','9','4','0','8','4','0','3','2'};
char r[] = {'r','u','n'};
char s[] = {'s','h','o','t','d','o','w','n','N'};
char t[] = {'t','a','p'};
char g[] = {'d','e','l'};
char on[]={'L','C','D','o','n'};
char off[]={'L','C','D','o','f','f'};

char store[16];
int i = 0,j = 0;
int a_1=0;
int r1=0,r2=0,r3=0;
int s1=0,s2=0,s3=0;
int t1=0;
int d1=0;
int n = 0;
int v=0;
int e=0;
int k = 0xc0,l = 0x80;
int m=0;
int stage = 0;//for switch
int stage_2 =0;
int inter=0;
void main ()
{ 

	P2_0=1;
	P2_1=1;
	P2_2=1;
	P2_3=1;
	P2_4=1;
	P2_5=1;
	P2_6=1;
	P2_7=1;
	delay(50000);
	P1_0 = 1;
	delay(50000);
	
			init_uart();
	
			write(0x38, 0);
			write(0x0F, 0);
			write(0x06, 0);
			write(0x01, 0);
			write(0x80, 0);
			/*for(i;i<9;i++)
			{
				write(l, 0);
				print_msg(&a[i]);
				l=l+1;
			}
			l=0x80;
			i=0;*/
			//print_msg("E94084032");
	


			

		
		write(0x40, 0);       //CGRAM start
		write(0x00, 1);
		write(0x0a, 1);
		write(0x0a, 1);
		write(0x00, 1);
		write(0x11, 1);
		write(0x0e, 1);
		write(0x00, 1);
		write(0x00, 1);	
		//write(0xc0, 0);			//ROW2 LEFT
		//write(0x00, 1);
		
		write(0x48, 0);       //CGRAM start
		write(0x01,1);
		write(0x03,1);
		write(0x05,1);
		write(0x09,1);
		write(0x0b,1);
		write(0x1b,1);
		write(0x18,1);
		write(0x00, 1);
		
		//write(0xcf, 0);			//ROW2 RIGHT
		//write(0x01, 1);
		
		//else if(inter==2){
		 
			
		//}
		//else if
			while(1);
}


/////////UART//////////////////////////
void init_uart(void)
{
	SCON=0x50;
	TMOD=0x21;
	TH1=0xe6;
	TR1=1;
	IE=0x97;
	EX1=1;
}

void UART_Isr(void) interrupt 4
{ 
	while(RI == 0);
	RI=0;
	recivevalue=SBUF;
	store[n] = recivevalue;
	n = n+1;
	delay(5000);
	write(0x38, 0);
	write(0x0F, 0);
	write(0x06, 0);
	write(0x01, 0);
	write(0x80, 0);
	//print_msg("TYPEING... ...");
	write(k,0);
	
	for(j;j<n;j++)
	{
		write(k, 0);
		print_msg(&a[j]);
		k=k+1;
	}
			k=0xc0;
			j=0;
	
	///////check run///////////////////////////////
	if(recivevalue==a[a_1])
	{
	  a_1=a_1+1;
	}
	else{
	 a_1=0;
	}
	if(recivevalue==g[d1] )//delete
	{
		d1=d1+1;
	}
	else
		{
			d1=0;
	}
	if(recivevalue==t[t1] )//graph
		{
		t1=t1+1;
		
	}
	else{
	  t1=0;
	
	
	}
		
	if(recivevalue == r[r1] )//run
		{
			r1=r1+1;
		}
	else
		{
			r1=0;
		}
	if(recivevalue == s[s1] )//stop
		{
			s1=s1+1;
		}
	else
		{
			s1=0;
		}
		
			if(r1==3)
			{
				for (r2;r2<40;++r2)//run led
					{
						  write(0x1C,0);
							delay(10000);

					}
					r2=0;
					r1=0;
			}
			else if(s1==9)//close
			{
		P1_6 = 1;
		P1_7 = 1;
		P2_0 = 1;
		P2_1 = 1;
		P2_2 = 1;
		P2_3 = 1;
		P2_4 = 1;
		P2_5 = 1;
		P2_6 = 1;
		P2_7 = 1;
		write(0x08, 0);
		delay(50000);
		P1_0 = 1;
				for(e=0;e<6;e++){
		  SBUF=off[e];
				while(TI==0);
		   TI=0; 
			 }
		delay(50000);
		stage=0;
		  memset(store,0,16);
      write(k,0);
			
		  n=0;
			s1=0;
			}
			else if(t1==3)
	{
    delay(10000);
			write(0xcf, 0);		//ROW2 LEFT
		  write(0x01, 1);
		  delay(50000);
		  write(0xce, 0);
		  write(0x01, 1);
		  delay(50000);
		  write(0xcd, 0);
		  write(0x01, 1);
		  delay(50000);
		  write(0xcc, 0);
		  write(0x01, 1);
		  delay(50000);
		t1=0;
 
	}
	     else if(d1==3)
	{
			delay(10000);
		  write(0x01,0);
		  write(0xc0,0);
		  memset(store,0,16);
		  
		  
			d1=0;	 
	}
	     else if(a_1==9)
	{
			 delay(20000);
		   P1_0=0;
		   
		   for(v=0;v<5;v++){
		  SBUF=on[v];
				while(TI==0);
		   TI=0; 
			 }
		   delay(20000);
			 write(0x40, 0);       //CGRAM start
		write(0x00, 1);
		write(0x0a, 1);
		write(0x0a, 1);
		write(0x00, 1);
		write(0x11, 1);
		write(0x0e, 1);
		write(0x00, 1);
		write(0x00, 1);	
			 write(0x80, 0);			//ROW2 LEFT
		   write(0x00, 1);
			 
			 write(0x48, 0);       //CGRAM start
		write(0x01,1);
		write(0x03,1);
		write(0x05,1);
		write(0x09,1);
		write(0x0b,1);
		write(0x1b,1);
		write(0x18,1);
		write(0x00, 1);
		   write(0x8f, 0);			//ROW2 RIGHT
		   write(0x01, 1);
		   stage=1;
		
			 
			 
	}


			
			
	
	///////////////////////////////////////
	  
	
/////////////////////////////////////////////////

}


void interrupt0_Isr(void) interrupt 0
{
		//////LCD/////////////////////////////////////////////////////
		delay(50000);
	if(stage_2== 0)
	{
		/*P1_6 = 1;
		P1_7 = 1;
		P2_0 = 1;
		P2_1 = 1;
		P2_2 = 1;
		P2_3 = 1;
		P2_4 = 1;
		P2_5 = 1;
		P2_6 = 1;
		P2_7 = 1;
		P1_0 = 1;*/
		stage_2= 1;
		write(0x08, 0);
		write(0x01, 0);
		memset(store,0,16);
		
		//write(k,0);
		n=0;		
	}
	else
	{
		write(0x0c,0);
		
		write(0x80,0);
		print_msg("Best(1)");
		write(0xc0,0);
		print_msg("Worst(8)");
		stage_2= 0;
	}	
	delay(10000);
	/*
		write(0x40, 0);       //CGRAM start
		write(0x00, 1);
		write(0x0a, 1);
		write(0x0a, 1);
		write(0x00, 1);
		write(0x11, 1);
		write(0x0e, 1);
		write(0x00, 1);
		write(0x00, 1);	
		write(0xc0, 0);			//ROW2 LEFT
		write(0x00, 1);
		
		write(0x48, 0);       //CGRAM start
		write(0x01,1);
		write(0x03,1);
		write(0x05,1);
		write(0x09,1);
		write(0x0b,1);
		write(0x1b,1);
		write(0x18,1);
		write(0x00, 1);
		write(0xcf, 0);			//ROW2 RIGHT
		write(0x01, 1);
		
		*////////////////////////////////		
}

//////////UART////////////////////////////////
void print_msg(char*msg)
{
	for (; *msg!='\0' ;++msg) 
				write(*msg,1); 
}

void write(char cmd, int rs_value)
{
 P2= cmd;
 P1_6= rs_value;
 P1_7=1;
 delay(100);
 P1_7=0;
}
/////////////////////////////////////////////




void interrupt2_Isr(void) interrupt 2
{
	delay(10000);
	write(0x01,0);
	write(0x80,0);
	print_msg("Hey YoU");
	if(inter==2){
		for(m=0;m<40;++m)
	{
		write(0x1c,0);
		delay(10000);
	}
	
	}
	else if(inter==3){
	
	for(m=0;m<40;++m)
	{
		write(0x1c,0);
		delay(2000);
	}
		inter=0;
	
}
	inter=inter+1;
	
	delay(10000);
	//for(m=0;m<40;++m)
	//{
		//write(0x1c,0);
		//delay(10000);
	//}
}
////////////////timer0//////////////////////////
/*void timer0_Isr(void) interrupt 1{
if(P1_0==1)

{

TR0=0;

temp=65536-sn;

TH0=temp/256;

TL0=temp%256;

TR0=1;

P1_0=0;

}
else
{

TR0=0;

temp=65536-sp;

TH0=temp/256;

TL0=temp%256;

TR0=1;

P1_0=1;

}
}*/



void delay(unsigned int t)
{
	while(t--);
}