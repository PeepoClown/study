section .text
	global ft_strlen
ft_strlen :
	mov rax, -1				; rax - counter
loop :
	inc rax
	cmp byte[rdi + rax], 0	; if '\0' occured -> return rax
	jne loop
	ret
