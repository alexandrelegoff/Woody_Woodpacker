global _start

_start:
	push rax
	push rdi
	push rsi
	push rdx
	push r8
	push r9
	push r10

_initialize:
	xor rcx,rcx
	mov rax,[rel addr]
	mov r9,[rel key]
	mov r10,[rel size]
	
_decrypt:
	mov r8,[rax]
	xor r8,r9
	mov qword [rax], r8
	inc rax
	inc rcx
	cmp rcx,r10
	jne _decrypt

_print:
	mov rax,1
	mov rdi,1
	lea rsi,[rel msg]
	mov rdx,msg_end-msg
	syscall

_end:
	pop r10
	pop r9
	pop r8
	pop rdx
	pop rsi
	pop rdi
	pop rax

	mov rax,[rel addr]
	jmp rax

align 8
	msg db "....WOODY....",10
	msg_end db 0x0
	addr dq 0x1111111111111111
	key  dq 0x2222222222222222
	size dq 0x3333333333333333
