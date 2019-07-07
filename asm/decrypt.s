global _start

_start:
	push rax
	push rdi
	push rsi
	push rdx

	mov rcx,0
	lea rax,[rel addr]

_decrypt:
	mov r8,[rax]
	xor r8, key
	mov qword [rax], r8
	inc rax
	inc rcx
	cmp rcx,size
	jne _decrypt

_print:
	mov rax,1
	mov rdi,1
	lea rsi,[rel msg]
	mov rdx,msg_end-msg
	syscall


_end:
	pop rdx
	pop rsi
	pop rdi
	pop rax

	mov rax,addr
	jmp rax

align 8
	msg db "....WOODY.....",10,0
	msg_end db 0x0
	addr dq 0x1111111111111111
	key  dq 0x2222222222222222
	size dq 0x3333333333333333
