section	.bss

section	.data

section	.text
	global	_ft_isprint

_ft_isprint:
	push rbp
	mov rbp, rsp

	mov r10, 0

	cmp rdi, 32
	jl end
	cmp rdi, 126
	jg end

	mov r10, 1
end:
	mov rax, r10
	pop rbp
	ret