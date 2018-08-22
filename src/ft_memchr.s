
section	.text
	global	_ft_memchr
	extern	_ft_strlen
	extern	_ft_puts

_ft_memchr:
	push rbp
	mov rbp, rsp
	sub rsp, 40

	mov [rsp + 8], rdi	;string
	mov [rsp + 16], rsi	;char
	mov [rsp + 24], rdx	;len
	; mov rax, 15

;_check_c:
	cmp rsi, 0
	je _one_more
_check_n:
	cmp rdx, 0
	je _zero_end
;_check_strlen:
	call _ft_strlen
	cmp rax, 0
	je _zero_end


; _loop:
	mov rcx, [rsp + 24]		;count register - set a len
	add rcx, 1
	mov rdi, [rsp + 8]		;set to string address
	mov rax, [rsp + 16]		;set le char a trouver
	; sld
	repne scasb

	cmp rcx, 0
	je _zero_end

	mov rax, rdi
	dec rax
	jmp _give_res

_end:
	add rsp, 40
	pop rbp
	ret

_zero_end:
	mov rax, 0
	jmp _end

 _give_res:
	jmp _end

_one_more:
	call _ft_strlen
	cmp rax, 0
	jne _zero_end
	jmp _check_n
