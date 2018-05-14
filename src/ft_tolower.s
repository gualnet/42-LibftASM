section	.data
hi:
	.string db "coucou!!!",10


section	.text
	global	_ft_tolower


_ft_tolower:
	;enter
	push rbp
	;je sauvegarde l'adresse de la stack ?
	mov rbp, rsp
	
if:
	cmp rdi, 0x41
	jl	endif_out
	cmp rdi, 0x5a
	jg endif_out

endif_in:
	add rdi, 0x20
	mov rax, 0x49
	mov rax, rdi
	jmp end

endif_out:
	;rax pour un pointeur ou un type entier de taille inferieure ou
	;	egale a 64 bits (Les valeurs sont etendues sur 64 bits.) ;
	;rdx:rax pour une valeur 128 bits ;
	mov rax, rdi

	
end:
	;leave
	pop rbp
	ret

_write_call:
	