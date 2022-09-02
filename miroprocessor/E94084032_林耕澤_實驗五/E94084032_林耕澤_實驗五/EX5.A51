       ORG 0000h
	   ;MOV R1,#500d
	   ;MOV R5,#0
	   MOV R5,#0
       JMP LOOP
       ORG 0030h
LOOP:  MOV SP,#32h
       MOV A,#0xfc
	   MOV P2,A
	   MOV R1,#250d
	   MOV R0,#8d
	   JMP MARQUEE
	   
MARQUEE:
       MOV R1,#250d
	   MOV R0,#8d
       SETB P1.0
	   SETB P1.2
       CALL DELAY1
       RL A
       MOV P2,A
	   JMP MARQUEE
	   
DELAY1: 
       JNB P1.0,PH
	   JNB P1.2,PP
	   DJNZ R1,DELAY3
	   RET
DELAY3:
       DJNZ R1,DELAY1
DELAY2: 
        
        
	   DJNZ R1,DELAY3
	   RET    
	   
	   
	   
	   
PH:  CALL DELAY2
PUSH 0E0h
INC R5
JMP MARQUEE

PP: 
POP 0E0h
MOV P2,A
DJNZ R5,PP
END


 
	   
       
       
	   
             
	   
