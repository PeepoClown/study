section .text
	global ft_list_size
ft_list_size :
	mov rax, -1			; counter
loop :
	inc rax
	cmp rdi, 0			; if current element == NULL -> return
	je return
	mov rdi, [rdi + 8]	; move to next element
	jmp loop
return :
	ret
