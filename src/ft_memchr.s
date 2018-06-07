
section	.text
	global	_ft_memchr
	extern	_ft_strlen
	extern	_strlen

_ft_memchr:
	push rbp
	mov rbp, rsp
	sub rsp, 32

	mov [rsp + 8], rdi
	mov [rsp + 16], rsi
	mov [rsp + 24], rdx

_chk_00:
	cmp rdx, 0
	je _zero_end
	jmp _check

_chk_01:
	cmp rsi, 0
	je _zero_end
	
_str_lp:
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
	add rsp, 32
	pop rbp
	ret

_zero_end:
	mov rax, 0
	jmp _end

 _give_res:
	add rax, [rsp + 8]
	jmp _end

_check:
	call _ft_strlen
	cmp rax, 0
	jne _chk_01
	je _str_lp