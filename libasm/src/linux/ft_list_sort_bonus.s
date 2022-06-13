section .text
	global ft_list_sort
ft_list_sort :
	mov rdi, [rdi]		; rdi is **t_list, now only 1 level pointer
	cmp rdi, 0			; if *t_list == NULL -> return
	je return
	mov rdx, rdi		; save begin of the list
loop :
	mov r8, [rdi + 8]	; check next element (list->next)
	cmp r8, 0			; if is the end of a list -> return
	je return
	push rdi			; save *t_list
	push rsi			; save compare function
	mov rbx, rsi		; put compare function to rbx
	mov rsi, [rdi + 8]	; rsi - 2d argument of compare func (next element)
	mov rsi, [rsi]		; now is value of its (list->next->data)
	mov rdi, [rdi]		; rdi is value of current element (list->data)
	call rbx			; call a compare function
	pop rsi				; return compare function from the stack
	pop rdi				; retrun *t_list from the stack
	cmp rax, 0			; if compare function return > 0
	jg swap				; swap values
	jmp go_to_next		; else -> go to next element
swap :
	mov r9, [r8]		; save to r9 value of next element (list->next->data)
	mov r10, [rdi]		; save to r10 value of current element (list->data)
	mov [rdi], r9		; move to data of current element data of next element
	mov [r8], r10		; move to data of next element data of current element
	mov rdi, rdx		; return to begin of the list
	jmp loop
go_to_next :
	mov rdi, [rdi + 8]	; now rdi is next element (list->next)
	jmp loop
return :
	ret
