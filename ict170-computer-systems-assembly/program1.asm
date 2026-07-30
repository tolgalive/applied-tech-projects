.MODEL SMALL
.STACK 100H
.DATA
	STR1 DB 'HELLO$'
	STR2 DB 'WORLD$'
.CODE
MAIN PROC
	MOV AX,@DATA
	MOV DS,AX

	LEA DX,STR1
	MOV AH,09H
	INT 21H
	
	mov DL, 10 ; Line Feed
	mov AH, 02h
	int 21h
	mov DL, 13; Carriage Return
	mov AH, 02h
	int 21h
	
	LEA DX,STR2
	MOV AH,90H
	INT 21H
	
	MOV AH,4CH
	INT 21H
MAIN ENDP
END MAIN	