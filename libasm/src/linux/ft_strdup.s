extern malloc
extern ft_strlen
extern ft_strcpy

section .text
	global ft_strdup
ft_strdup :
	push rdi 			; put a line on top of the stack
	call ft_strlen		; rax is string length
	inc rax				; increment because '\0'
	mov rdi, rax		; rdi - param of malloc, is length + 1
	call malloc			; rax is pointer to our future string copy
	pop rdi				; return string from the stack
	cmp rax, 0			; if malloc return NULL
	je malloc_error
	mov rsi, rdi		; rsi - source string
	mov rdi, rax		; rdi - destination string
	call ft_strcpy		; rax - string copy
	ret
malloc_error :
	ret