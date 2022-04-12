	AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
	DCD 0X10001000
	DCD Reset_Handler

	AREA MYCODE, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	MOV R1,#0Xa
	MOV R4,#0
	LDR R2,=DST	
	
UP LDR R3,[R0,R4]
	STR R3,[R2,R4]
	ADD R4, #4
	SUB R1, #1
	CMP R1,#0
	BHI UP
	
	LDR R0,=DST
	MOV R1, R0
	MOV R3, R0
	MOV R10, #0
	MOV R11, #0
	MOV R2, #0XA
	
COM	CMP R11, R2		
	BEQ STOP		
	ADD R3,R0,#4	
	MOV R1,R0		
	ADD R10,R11,#1
	
OUT CMP R10,R2		
	BEQ IN
	ADD R10,#1		
	LDR R4,[R3],#4
	LDR R5,[R1]
	CMP R5,R4
	BLT OUT
	MOV R1,R3
	SUB R1,#4
	B OUT
IN	ADD R11,#1
	LDR R4,[R0]
	LDR R5,[R1]
	STR R4,[R1]
	STR R5,[R0],#4
	B COM

	
STOP B STOP


SRC DCD 0x30,0x29,0x28,0x27,0x26,0x25,0x24,0x23,0x22,0x21

	AREA mydata,DATA,READWRITE

DST DCD 0,0,0,0,0,0,0,0,0,0
	END
