section	.bss

section	.data

section	.text
	global	_ft_isascii

_ft_isascii:
	push rbp
	mov rbp, rsp

	mov r10, 0

	cmp rdi, 0
	jl end
	cmp rdi, 127
	jg end
	mov r10, 1

end:
	mov rax, r10
	pop rbp
	ret