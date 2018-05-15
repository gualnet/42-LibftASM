section	.bss

section	.data

section	.text
	global	_ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp

	mov rcx, 0

lp:
	cmp [rdi + rcx], byte 0
	je end
	inc rcx
	jmp lp

end:
	mov rax, rcx
	pop rbp
	ret


