
section	.text
	global	_ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp

	mov r15, rdi

	mov rcx, rdx ; set len
	mov rax, rsi ; set char
	cld
	rep stosb

	mov rax, r15
end:
	pop rbp
	ret
