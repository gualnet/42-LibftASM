
section	.text
	global	_ft_memchr
	extern	_ft_strlen


_ft_memchr:
	push rbp
	mov rbp, rsp
	sub rsp, 40

	mov [rsp + 8], rdi
	mov [rsp + 16], rsi
	mov [rsp + 24], rdx
	mov rax, 15


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

_lp:
	mov rdi, [rsp + 8]
	mov rax, [rsp + 16]
	mov rcx, [rsp + 24]
	cld
	repne scasb


	mov rax, [rsp + 24]
	sub rax, rcx
	sub rax, 1
	jmp _give_res


_end:
	add rsp, 40
	pop rbp
	ret

_zero_end:
	mov rax, 0
	jmp _end

 _give_res:
	add rax, [rsp + 8]
	jmp _end

_one_more:
	call _ft_strlen
	cmp rax, 0
	jne _zero_end
	jmp _check_n
