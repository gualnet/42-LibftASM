STDOUT	equ	1

section	.bss

section	.data
	buff times 256 db 0
	buffsize equ $ - buff

section	.text
	global	_ft_cat
	extern	_ft_puts
	extern	_ft_bzero

_ft_cat:
	push rbp
	mov rbp, rsp

	mov r15, buff
	mov r14, rdi
_read_lp:

	mov rdi, r15
	mov rsi, buffsize
	call _ft_bzero

	mov rax, 0x2000003
	mov rdi, r14
	mov rsi, r15
	mov rdx, buffsize
	syscall
	push rax

	mov rax, 0x2000004
	mov rdi, STDOUT
	mov rsi, r15
	mov rdx, buffsize
	syscall

	pop r13
	cmp r13, 0
	jg _read_lp

	mov rax, 0

_end:
	pop rbp
	ret

_exit_err:
	mov rax, -1
	jmp _end
