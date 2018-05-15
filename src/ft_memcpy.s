section	.bss

section	.data

section	.text
	global	_ft_memcpy

_ft_memcpy:
	push rbp
	mov rbp, rsp

	mov rcx, 0

lp:
	cmp rcx, rdx
	je end
	mov r10, [rsi + rcx]
	mov [rdi + rcx], r10
	inc rcx
	jmp lp

end:
	mov rax, rdi
	pop rbp
	ret
