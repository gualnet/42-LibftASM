STDOUT	equ	1

section	.data
	buff times 256 db 0
	buffsize equ $ - buff
msg:
	.err_fd db "cat: No such file or directory", 10, 0
	.errSize equ $ - msg.err_fd

section	.text
	global	_ft_cat
	extern	_ft_puts
	extern	_ft_bzero

_ft_cat:
	push rbp
	mov rbp, rsp
	
	mov rax, 0
	cmp edi, eax
	jle _exit_err_fd

	mov r15, buff
	mov r14, rdi

_read_lp:
	mov rdi, buff
	mov rsi, buffsize
	call _ft_bzero

	mov rax, 0x2000003 ; read
	mov rdi, r14
	mov rsi, r15
	mov rdx, buffsize
	syscall

	push rax
	mov r13, rax

	mov rax, 0x2000004 ; write
	mov rdi, STDOUT
	mov rsi, r15
	mov rdx, r13
	syscall

	pop r13
	cmp r13, 0
	jg _read_lp

	mov rax, 0
	jmp _end

_exit_err_fd:

	mov rax, 0x2000004 ; write
	mov rdi, STDOUT
	lea rsi, [rel msg.err_fd]
	mov rdx, msg.errSize
	syscall

_end:
	pop rbp
	ret

