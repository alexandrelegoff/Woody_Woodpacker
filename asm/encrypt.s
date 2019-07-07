section .text
	global encrypt_text_section

encrypt_text_section:
	enter 0,0
	push rax
	push rdi
	push rsi
	mov rax, 0x1111111122222222
	mov rcx,0

xor_encryption:
	mov r8, [rdi]
	xor r8, rdx
	mov qword [rdi], r8
	inc rdi
	inc rcx
	cmp rcx,rsi
	jne xor_encryption
end:
	pop rsi
	pop rdi
	pop rax
	leave
	ret
