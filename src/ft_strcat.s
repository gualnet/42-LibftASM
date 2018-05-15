section	.bss
	

section	.data
print:
	.format db "-->%c", 10
	

section	.text
	global	_ft_strcat
	extern _printf

; params
; rdi = s1
; rsi = s2

_ft_strcat:
	push rbp
	mov rbp, rsp
	mov r10, 0 ; i = 0
	mov r11, 0 ; j = 0
loop_00:
	cmp [rdi + r10], byte 0x0
	je loop_01
	inc r10
	jmp loop_00

loop_01:
	cmp [rsi + r11], byte 0
	je end
	mov r12, [rsi + r11]
	mov [rdi + r10], r12
	inc r10
	inc r11
	jmp loop_01

end:
	mov [rdi + r10], byte 0x0
	mov rax, rdi
	pop rbp
	ret