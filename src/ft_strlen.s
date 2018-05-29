section	.bss

section	.data

section	.text
	global	_ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp

	xor rax,rax 	; reset al through rax reg
	mov dx, di		; moving string addr into dx reg
	mov cx, 1		; setting count reg at 1;
	cld				; set la direction du counter (inc/dec)
	repne scasb		; REP while Not Equal and SCan A String
	sub ax, cx		

end:
	pop rbp
	ret
