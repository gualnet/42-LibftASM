
%define EOF		-1
%define OUT_FD	1
%define ERR_FD	2

section	.data
string:
	.line_ret db 10, 0
	lrSize equ $ - .line_ret
	.null db "(null)", 10, 0

section	.text
	global	_ft_puts
	extern	_ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp

	sub rsp, 32
	mov [rsp + 16], rdi

	cmp rdi, 0
	jne _get_len

	mov rax, 0x2000004
	mov rdi, ERR_FD
	lea rsi, [rel string.null]
	mov rdx, 7
	syscall
	mov word [rsp + 8], EOF
	jmp _end

_get_len:
	call _ft_strlen
	mov [rsp + 8], rax

_lp:
	mov rax, 0x2000004
	mov rdi, OUT_FD
	mov rsi, [rsp + 16]
	mov rdx, [rsp + 8]
	syscall

	mov rax, 0x2000004
	mov rdi, OUT_FD
	lea rsi, [rel string.line_ret]
	mov rdx, lrSize
	syscall

	cmp word [rsp + 8], 0
	jne _end
	add word [rsp + 8], 1


_end:
	mov rax, [rsp + 8]
	add rsp, 32
	pop rbp
	ret