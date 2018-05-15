section	.bss

section	.data

section	.text
	global	_ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp

	mov rcx, 0
lp:
	cmp rcx, rdx
	je end
	mov [rdi + rcx], rsi
	inc rcx
	jmp lp

end:
	mov rax, rdi
	pop rbp
	ret