
section	.text
	global	_ft_strdup
	extern	_ft_strlen
	extern	_strlen
	extern	_ft_memcpy
	extern	_malloc

_ft_strdup:
	push rbp
	mov rbp, rsp
	sub rsp, 64

	; recup len de str
	mov [rsp], rdi	; -> rsp - 0 => param 1: ptr source string
	call _strlen
	mov r15, rax	; => string len (\0 excluded)
	
	; malloc(len)
	mov rdi, rax
	inc rdi
	call _malloc
	cmp rax, 0	; if malloc == NULL
	je end		; return NULL
	mov r14, rax

	mov rdi, r14
	mov rsi, [rsp]
	mov rdx, r15
	call _ft_memcpy

	mov rax, r14

close_str:
	mov [rax + r15], byte 0

end:
	add rsp, 64

	pop rbp
	ret