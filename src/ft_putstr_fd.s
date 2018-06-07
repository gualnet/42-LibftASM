
%define EOF	-1
%define ERR_FD	2

section	.data
string:
	.line_end db 0
	.null db "(null)", 10, 0

section	.text
	global	_ft_putstr_fd
	extern	_ft_strlen

_ft_putstr_fd:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	mov r14, rdi
	mov r15, rsi

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
	mov [rsp + 8], rax
	
lp:
	mov rax, 0x2000004
	mov rdi, r15
	mov rsi, r14
	mov rdx, [rsp + 8]
	syscall

	mov rax, 0x2000004
	mov rdi, r15
	lea rsi, [rel string.line_end]
	mov rdx, 1
	syscall

	cmp rax, 0
	jne end
	add rax, 1
end:
	add rsp, 16
	pop rbp
	ret