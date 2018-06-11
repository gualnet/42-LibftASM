
section	.text
	global	_ft_isalpha

_ft_isalpha:
	push rbp,
	mov rbp, rsp

	mov r10, 0
; Maj
	cmp rdi, 65
	jl end
	cmp rdi, 90
	jle return_1
; Min
	cmp rdi, 97
	jl end
	cmp rdi, 122
	jg end

return_1:
	mov r10, 1

end:
	mov rax, r10
	pop rbp
	ret