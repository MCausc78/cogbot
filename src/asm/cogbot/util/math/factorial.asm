section .text
	global factorial
factorial:
	mov rax, 1
	cmp rdi, 65
	ja .L3
	mov rcx, 1
	jmp .L2
.L1:
	imul rcx
	inc rcx
.L2:
	cmp rcx, rdi
	jbe .L1
	jmp .L3
.L3:
	ret