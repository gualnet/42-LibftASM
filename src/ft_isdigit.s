section	.bss

section	.data

section	.text
	global	_ft_isdigit

_ft_isdigit:
	push rbp
	mov rbp, rsp

	mov r10, 0

	cmp rdi, 48
	jl end
	cmp rdi, 57
	jg end

return_1:
	mov r10, 1

end:
	mov rax, r10
	pop rbp
	ret