section .text
	global ft_atoi_base
ft_atoi_base :
	push rdi				; save params in the stack
	push rsi
	call validate_base		; check base on spaces, '+', '-', and other illegal symbols
	pop rsi					; return params from the stack
	pop rdi
	cmp rax, 0				; if returned 0 -> error in string of base
	je invalid_base
	push rdi				; save params in the stack
	push rsi
	call validate_base_len	; check base line length
	pop rsi					; return params from the stack
	pop rdi
	cmp rax, 2				; if base line length == (1 | 0) -> error
	jl invalid_base
	mov r8, 0				; result
	mov r9, 1				; sign
	mov rdx, rax			; length of base line
	dec rdi					; str--
skip_spaces :
	inc rdi					; str++
	mov bl, byte[rdi]		; get current symbol (*str)
	cmp bl, 9				; if current symbol < 9
	jl invalid_sym			; return 0
	cmp bl, 14				; if current symbol >= 9 && < 14 -> skip it
	jl skip_spaces
	cmp bl, 32				; if current symbol == space -> skip it
	je skip_spaces
	dec rdi					; str--
skip_sign :
	inc rdi					; str++
	mov bl, byte[rdi]		; get current symbol (*str)
	cmp bl, 43				; if current symbol == '+'
	je plus
	cmp bl, 45				; if current symbol == '-'
	je minus
main_loop :
	mov bl, byte[rdi]		; get current symbol (*str)
	push rdi				; save params in the stack
	push rsi
	mov cl, bl				; save current symbol in cl
	call check_sym			; check symbol is a part of base
	pop rsi					; return params from the stack
	pop rdi
	cmp rax, 0				; if symbol is not a part of base
	jl return				; return current result
	imul r8, rdx			; if it is -> multiply current result on base line length
	add r8, rax				; add to result current digit value
	inc rdi					; str++
	jmp main_loop
check_sym :
	mov rax, -1
check_sym_loop :
	inc rax
	mov bl, byte[rsi + rax]	; bl = str[i(rax)]
	cmp bl, 0				; if symbol == '\0'
	je sym_not_from_base	; we occured end of base line -> symbol not from a base
	cmp bl, cl				; if current symbol of base line equal to current symbol
	je sym_in_base			; it in a base line
	jmp check_sym_loop
sym_in_base :
	ret
sym_not_from_base :
	mov rax, -1				; error
	ret
validate_base :
	mov rdi, rsi			; go on base line
	xor rax, rax			; rax = 0
	xor r8, r8				; i(r8) = 0
validate_base_ex_loop :		; extern loop
	xor r9, r9				; j(r9) = 0
	mov bl, byte[rdi + r8]	; if current symbol of a base line
	cmp bl, 0				; == 0 -> end loop and return
	je validate_base_ex_loop_end
	add r9, r8				; j = i + 1
	inc r9
	cmp bl, 32				; if is space or escape symbol -> error
	jng validate_base_end
	cmp bl, 43				; if is sign -> error
	je validate_base_end
	cmp bl, 45
	je validate_base_end
	cmp bl, 127				; if is not ascii value -> error
	jg validate_base_end
validate_base_in_loop :		; inner loop
	mov cl, byte[rdi + r9]	; cl = base[j]
	cmp cl, 0
	je validate_base_in_loop_end
	cmp bl, cl				; == 0 -> end loop
	je validate_base_end
	inc r9					; j++
	jmp validate_base_in_loop
validate_base_in_loop_end :
	inc r8					; i++
	jmp validate_base_ex_loop
validate_base_ex_loop_end :
	mov rax, 1				; return 1 -> good
	ret
validate_base_end :
	ret
validate_base_len :
	mov rdi, rsi			; go on base line
	mov rax, -1
validate_base_len_loop :
	inc rax
	cmp byte[rdi + rax], 0	; if is the end of a base line
	jne validate_base_len_loop
	ret						; return its length
invalid_base :
	xor rax, rax			; rax = 0 -> return
	ret
minus :
	mov r9, -1				; sign = -1
	inc rdi
	jmp main_loop
plus :
	inc rdi
	jmp main_loop
invalid_sym :
	xor rax, rax			; rax = 0 -> return
	ret
return :
	imul r8, r9				; multiply result on sign
	mov rax, r8				; rax = total = result * sign
	ret						; return total