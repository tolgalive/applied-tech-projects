.MODEL SMALL
.STACK 100H
.DATA
.code
main proc
	mov ax,@data
	mov ds,ax

	;36
	MOV AH, 1 ;read first digit
	INT 21H AL = 51
	SUB AL, ‘0’ ; convert digit from ASCII code to binary AL = 3
	MOV BL, 10 BL = 10
	MUL BL ; multiply digit by 10 AX = AL * BL = 3 * 10 = 30 = AH AL =
	MOV CL, AL CL = 30
	MOV AH, 1 ; read 2nd digit
	INT 21H AL 
	SUB AL, ‘0’ ; convert digit from ASCII code to binary
	ADD AL, CL ; AL contains the 2-digit number

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

	mov ah,4ch
	int 21h
	
main endp
end main 
	