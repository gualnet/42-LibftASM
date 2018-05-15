section	.bss

section	.data

section	.text
	global	_ft_strdup
	extern	_ft_strlen
	extern	_malloc

_ft_strdup:
	push rbp
	mov rbp, rsp

	; recup len de str
	mov r15, rdi
	call _ft_strlen
	mov r11, rax ; r11 - len de la str

	; malloc(len)
	mov rdi, r11
	call _malloc
	mov r12, rax ; r12 - addr de la zone allouee

	cmp r12, 0 ; si malloc == NULL
	mov rax, 0 ; return (NULL)
	je end

	mov rcx, 0
lp:
	cmp [r15 + rcx], byte 0
	je close_str
	mov r13, [r15 + rcx]
	mov [r12 + rcx], r13
	inc rcx
	jmp lp

close_str:
	mov [r12 + rcx], byte 0
	mov rax, r12

end:
	pop rbp
	ret