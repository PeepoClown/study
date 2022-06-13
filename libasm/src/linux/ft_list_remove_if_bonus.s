extern free

section .text
	global ft_list_remove_if
ft_list_remove_if :
	cmp rdi, 0			; if **t_list == NULL -> return
	je return
	cmp rdx, 0			; if compare function pointer == NULL -> return
	je return
remove_first :
	mov r8, [rdi]		; r8 = *t_list
	cmp r8, 0			; if *t_list == NULL -> return
	je return
	push rdi			; save params in the stack
	push rsi
	push rdx
	mov rdi, [r8]		; rdi is data of current element
	mov rbx, rdx		; rbx is tmp var for compare function
	call rbx			; call compare function
	pop rdx				; return params from the stack
	pop rsi
	pop rdi
	cmp rax, 0			; if first element not suitable for removing
	jne get_begining	; if not gt to next loop
	mov r8, [rdi]		; r8 = *t_list
	mov r9, [r8 + 8]	; r9 = *t_list->next
	mov [rdi], r9		; rdi(*t_list) = *t_list->next
	push rdi			; save params in the stack
	push rsi
	push rdx
	push r8
	push r9
	mov rdi, r8			; mov r8 as argument to free
	call free			; call free
	pop r9				; return params from the stack
	pop r8
	pop rdx
	pop rsi
	pop rdi
	jmp remove_first
get_begining :
	mov r8, [rdi]		; r8 = *t_list(begining)
remove_main :
	cmp r8, 0			; if current element == NULL -> return
	je return
	mov r9, [r8 + 8]	; if next element == NULL -> return
	cmp r9, 0
	je return
	push rdi			; save params in the stack
	push rsi
	push rdx
	push r8
	push r9
	mov rdi, [r9]		; rdi = *t_list->next->data
	mov rbx, rdx		; rbx is tmp var for compare function
	call rbx			; call compare function
	pop r9				; return params from the stack
	pop r8
	pop rdx
	pop rsi
	pop rdi
	cmp rax, 0			; if current element not suitable for removing
	jne go_to_next		; got to next element
	push rdi			; save params in the stack
	push rsi
	push rdx
	push r8
	push r9
	mov rdi, r9			; rdi = *t_list->next
	mov r9, [r9 + 8]	; r9 = *t_list->next->next
	mov [r8 + 8], r9	; r8->next = *t_list->next->next
	call free			; call free
	pop r9				; return params from the stack
	pop r8
	pop rdx
	pop rsi
	pop rdi
	jmp remove_main
go_to_next :
	mov r8, r9			; current element = next element
	jmp remove_main
return :
	ret