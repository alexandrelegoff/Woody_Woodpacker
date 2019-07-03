section .text
	global _start

_start:
		mov rax,0x2000004
		mov rdi,1
		lea rsi,[rel msg]
		mov rdx, msg_end - msg
		syscall

	mov rax,0x11111111
	jmp rax

align 8
	msg db '....WOODY.....',10,0
	msg_end db 0x0
