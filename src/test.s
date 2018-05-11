section	.data
hello:
	.string	db "Hello World!", 10
	.len equ $ - hello.string

section .text
	global	_start
	global	_main
	extern	_printf

_start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	lea rdi, [rel hello.string]
	call _printf
	leave
	ret