section	.bss

section	.data

section	.text
	global	_ft_toupper

_ft_toupper:
	push rbp
	mov rbp, rsp

;if:
	cmp rdi, 97
	jl endif_out
	cmp rdi, 122
	jg endif_out

endif_in:
	sub rdi, 32
	mov rax, rdi
	jmp end

endif_out:
	mov rax, rdi

end:
	pop rbp
	ret