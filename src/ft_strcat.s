
section	.text
	global	_ft_strcat
	extern	_ft_strlen
	extern	_ft_memcpy

_ft_strcat:
	push rbp
	mov rbp, rsp

	sub rsp, 32
	mov [rsp + 8], rdi
	mov [rsp + 16], rsi

	call _ft_strlen
	mov rcx, rax

	mov r15, [rsp + 8]
	mov r14, [rsp + 16]
	mov rdx, 0
	mov r13b, [r14 + rdx]
_lp:
	mov [r15 + rcx], r13b
	inc rcx
	inc rdx
	mov r13b, [r14 + rdx]
	cmp r13b, 0
	jne _lp

	mov rax, [rsp + 8]
_end:
	add rsp, 32
	pop rbp
	ret


