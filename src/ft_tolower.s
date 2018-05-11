section	.data
hi:
	.string db "coucou!!!",10


section	.text
	global	_ft_tolower


_ft_tolower:
	;enter
	push rbp

	;test syscall
	mov rbp, rsp
	
	mov	rax, 0x2000004
	mov rdi, 1
	lea rsi, [rel rbp]
	mov rdx, 9
	syscall
	

	;leave
	pop rbp
	ret

_write_call:
	