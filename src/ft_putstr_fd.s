
%define EOF	-1
%define ERR_FD	2

section	.data
string:
	.line_end db 10, 0
	.null db "(null)", 10, 0

section	.text
	global	_ft_putstr_fd
	extern	_ft_strlen

_ft_putstr_fd:
	push rbp
	mov rbp, rsp
	sub rsp, 32

	mov [rsp + 8], rdi ;r14
	mov [rsp + 16], rsi;r15

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
	mov [rsp + 24], rax
	
lp:
	mov rax, 0x2000004
	mov rdi, [rsp + 16]
	mov rsi, [rsp + 8]
	mov rdx, [rsp + 24]
	syscall

	mov rax, 0x2000004
	mov rdi, [rsp + 16]
	lea rsi, [rel string.line_end]
	mov rdx, 2
	syscall

	cmp rax, 0
	jne end
	add rax, 1
end:
	add rsp, 32
	pop rbp
	ret