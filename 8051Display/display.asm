; Stackoverflow reference:
; http://stackoverflow.com/questions/14261374/8051-lcd-hello-world-replacing-db-with-variable/
;
;	ORG 08100h
	org	0h

hello:
	mov	r7, #42		; value to convert
	mov	dptr, #buffer	; destination buffer
	acall	str2ascii	; convert value

;	mov	P2, #(lcd_cmd SHR 8)	; load P2 with high address
;	mov	R0, #(lcd_cmd AND 255)	; load R0 with command reg addr
;	mov	R7, #03h        ; set LCD position, line=1, char=3
;	mov	dptr, #buffer	; point to buffer
;	acall   wr_string       ; write buffer to LCD

stop:   ajmp    stop            ; soft halt  

str2ascii:
; Converts a one byte decimal value into its ASCII string representation.
; Result is prepended with leading zeroes.
; 0   becomes "000"
; 42  becomes "042"
; 255 becomes "255
;
; @param r7 	Input value to convert (1 byte, 0 .. 255)
; @param dptr	Destination buffer, at 4 bytes (3 digits plus \0)
	mov	a, r7
	mov	b, #100
	div	ab		; leftmost digit in a
	add	a,#30h		; convert to ASCII
	movx	@dptr, a
	inc	dptr

	mov	a,b		; get reminder
	mov	b,#10
	div	ab		; middle digit in a, rightmost digit in b
	add	a,#30h		; convert to ASCII
	movx	@dptr, a
	inc	dptr

	mov	a,b
	add	a,#30h		; convert to ASCII
	movx	@dptr,a
	inc	dptr

	mov	a,#0
	movx	@dptr, a	; terminate string
	ret

	xseg
buffer:	ds	17		; one LCD line plus terminating \0

	end
