section .text
	global fibonacci
fibonacci:
	mov rax, 1
	mov rbx, 1
	mov rcx, 3
	jmp .L2
.L1:
	lea rdx, [rax + rbx]
	mov rax, rbx
	mov rbx, rdx
	inc rcx
.L2:
	cmp rcx, rdi
	jbe .L1
	mov rax, rbx
	ret