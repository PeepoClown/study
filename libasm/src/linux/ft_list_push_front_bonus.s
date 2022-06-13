extern malloc

section .text
	global ft_list_push_front
ft_list_push_front :	
	push rdi			; put list pointer on stack
	push rsi			; put data on stack
	mov rdi, 16			; 16 bites is size of list element
	call malloc			; rax points to new element of list
	pop rsi				; return data from the stack
	pop rdi				; return list pointer from the stack
	cmp rax, 0			; if malloc return NULL
	je error_malloc
	mov [rax], rsi		; rax - new element, [rax] - it's data
	mov rbx, [rdi]		; put previos head of list at rbx (rdi is **t_list)
	mov [rax + 8], rbx	; [rax + 8] - next field of new element
	mov [rdi], rax		; [rdi] - head of list, now it's points to new element
error_malloc :
	ret
