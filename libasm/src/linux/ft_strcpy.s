section .text
	global ft_strcpy
ft_strcpy :
	mov rax, -1					; counter
loop :
	inc rax
	mov bl, byte[rsi + rax]		; get char of source string
	cmp bl, 0					; if is '\0' -> return
	je return
	mov byte[rdi + rax], bl		; put this char to destination string
	jmp loop
return :
	mov byte[rdi + rax], 0		; set '\0'
	mov rax, rdi				; put string to rax and return
	ret