
%define EOF		-1
%define OUT_FD	1
%define ERR_FD	2

section	.data
string:
	.line_ret db 10
	.null db "(null)", 10, 0

section	.text
	global	_ft_puts
	extern	_ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp

	cmp rdi, 0
	jne get_len
	mov rax, 0x2000004
	mov rdi, ERR_FD
	lea rsi, [rel string.null]
	mov rdx, 7
	syscall
	mov r10, 1
	jmp end

get_len:
	call _ft_strlen
	mov r10, rax
	mov r11, rdi
lp:
	mov rax, 0x2000004
	mov rdi, OUT_FD
	mov rsi, r11
	mov rdx, r10
	syscall

	mov rax, 0x2000004
	mov rdi, OUT_FD
	lea rsi, [rel string.line_ret]
	mov rdx, 1
	syscall

	cmp r10, 0
	jne end
	add r10, 1
end:
	mov rax, r10
	pop rbp
	ret