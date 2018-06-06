
section	.text
	global	_ft_bzero

_ft_bzero:
	push rbp
	mov rbp, rsp

	cmp rsi, 0
	jle end
	
	; init compteur de boucle
	mov rcx, rsi

while_00:
	cmp rcx, 0
	jl end
	dec rcx
	mov [rdi + rcx], byte 0
	jmp while_00
	
end:
	pop rbp
	ret
