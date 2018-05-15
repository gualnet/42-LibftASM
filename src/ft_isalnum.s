section	.bss

section	.data

section	.text
	global	_ft_isalnum
	extern	_ft_isalpha
	extern	_ft_isdigit

_ft_isalnum:
	push rbp
	mov rbp, rsp

	call _ft_isalpha
	cmp rax, 1
	je end
	call _ft_isdigit

end:
	pop rbp
	ret