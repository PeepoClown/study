extern __errno_location

section .text
	global ft_read
ft_read :
	mov rax, 0				; code of system call read
	syscall
	cmp rax, -1				; if returned negative num(error occured)
	jng error
	ret
error :
	neg rax					; get absolute value
	mov rdi, rax
	call __errno_location	; __errno_location return the adress of errno code to rdi
	mov [rax], rdi			; put errno to memory that rax points
	mov rax, -1				; return -1 like original write
	ret
