section .text
	global ft_strcmp
ft_strcmp :
	mov rax, -1				; counter
loop :
	inc rax
	mov bl, byte[rdi + rax]	; char of s1
	mov cl, byte[rsi + rax]	; char of s2
	cmp bl, 0				; if s1 ends -> compare chars of both string
	je compare
	cmp cl, 0				; if s2 ends -> compare chars of both string
	je compare
	cmp bl, cl				; if char of s1 not equal to char of s2 -> compare chars of both string
	jne compare
	jmp loop
compare :
	cmp bl, cl
	je equal
	jne not_equal
equal :
	mov rax, 0				; return zero if equal
	ret
not_equal :
	sub bl, cl				; get difference beetwen chars
	movsx rax, bl			; place 8 bit register data with sign to 64 bit register and return
	ret