	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
		DCD 0X10001000
		DCD Reset_Handler
		ALIGN
		AREA mycode, CODE, READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler
	MOV R0, #8
	LDR R1,=SRC
	STR R0,[R1]
	LDR R2,=DST

	LDR R3,[R1]
	STR R3,[R2]
	
STOP
	B STOP
	
	AREA mydata,DATA,READWRITE
SRC DCD 0
DST DCD 0

END
