section	.bss

section	.data

section	.text
	global	_ft_tolower

_ft_tolower:
	;enter
	push rbp
	;je sauvegarde l'adresse de la stack ?
	mov rbp, rsp
;if:
	cmp rdi, 0x41
	jl	endif_out
	cmp rdi, 0x5a
	jg endif_out

endif_in:
	add rdi, 0x20
	mov rax, rdi
	jmp end

endif_out:
	mov rax, rdi

end:
	;leave
	pop rbp
	ret
