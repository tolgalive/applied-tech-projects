.MODEL SMALL
.STACK 100H
.DATA
	NUM1 DW 3
	NUM2 DW 5
	SUM DW ?
.CODE
MAIN PROC
	MOV AX,@DATA
	MOV DS,AX
	
	MOV AX,NUM1
	ADD AX,NUM2
	ADD SUM,AX
	
	MOV BL, 10
	DIV BL ; getting least significant digit
	ADD AH, ‘0’ ; converting L.S. digit to ASCII
	MOV DH, AH ; storing L.S. digit temporarily
	MOV AH, 0
	DIV BL ; getting most significant digit
	ADD AH, ‘0’ ; converting M.S. digit into ASCII
	MOV DL, AH ; displaying M.S. digit
	MOV AH, 2
	INT 21H
	MOV DL, DH ; displaying least significant digit
	INT 21H
	
	MOV AH,4CH
	INT 21H
	
MAIN ENDP
END MAIN	