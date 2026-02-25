	.file	"1.c"
	.text
	.def	scanf;	.scl	3;	.type	32;	.endef
	.seh_proc	scanf
scanf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	movq	32(%rbp), %rax
	movq	%rbx, %r8
	movq	%rax, %rdx
	call	__mingw_vfscanf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	movq	32(%rbp), %rax
	movq	%rbx, %r8
	movq	%rax, %rdx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	c_to_f
	.def	c_to_f;	.scl	2;	.type	32;	.endef
	.seh_proc	c_to_f
c_to_f:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	16(%rbp), %xmm1
	movsd	.LC0(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	.LC1(%rip), %xmm2
	movapd	%xmm0, %xmm1
	divsd	%xmm2, %xmm1
	movsd	.LC2(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	c_to_k
	.def	c_to_k;	.scl	2;	.type	32;	.endef
	.seh_proc	c_to_k
c_to_k:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	16(%rbp), %xmm1
	movsd	.LC3(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	f_to_c
	.def	f_to_c;	.scl	2;	.type	32;	.endef
	.seh_proc	f_to_c
f_to_c:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	16(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	subsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm1
	movsd	.LC1(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	.LC0(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	f_to_k
	.def	f_to_k;	.scl	2;	.type	32;	.endef
	.seh_proc	f_to_k
f_to_k:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	16(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm2
	movapd	%xmm0, %xmm1
	subsd	%xmm2, %xmm1
	movsd	.LC1(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	.LC0(%rip), %xmm2
	movapd	%xmm0, %xmm1
	divsd	%xmm2, %xmm1
	movsd	.LC3(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	k_to_c
	.def	k_to_c;	.scl	2;	.type	32;	.endef
	.seh_proc	k_to_c
k_to_c:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	16(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm1
	subsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	k_to_f
	.def	k_to_f;	.scl	2;	.type	32;	.endef
	.seh_proc	k_to_f
k_to_f:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	16(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm1
	subsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm1
	movsd	.LC0(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	.LC1(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm1
	movsd	.LC2(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC4:
	.ascii "%d\0"
.LC5:
	.ascii "%lf %c %c\0"
.LC6:
	.ascii "%.2f\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movl	$80080, %eax
	call	___chkstk_ms
	subq	%rax, %rsp
	.seh_stackalloc	80080
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	leaq	79928(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movl	$0, 79948(%rbp)
	jmp	.L18
.L25:
	leaq	-90(%rbp), %rcx
	leaq	-89(%rbp), %rdx
	leaq	-88(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movzbl	-89(%rbp), %eax
	cmpb	$67, %al
	jne	.L19
	movzbl	-90(%rbp), %eax
	cmpb	$70, %al
	jne	.L20
	movq	-88(%rbp), %rax
	movq	%rax, %xmm0
	call	c_to_f
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	floor
	movq	%xmm0, %rax
	movq	%rax, 79936(%rbp)
.L20:
	movzbl	-90(%rbp), %eax
	cmpb	$75, %al
	jne	.L19
	movq	-88(%rbp), %rax
	movq	%rax, %xmm0
	call	c_to_k
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	floor
	movq	%xmm0, %rax
	movq	%rax, 79936(%rbp)
.L19:
	movzbl	-89(%rbp), %eax
	cmpb	$70, %al
	jne	.L21
	movzbl	-90(%rbp), %eax
	cmpb	$67, %al
	jne	.L22
	movq	-88(%rbp), %rax
	movq	%rax, %xmm0
	call	f_to_c
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	floor
	movq	%xmm0, %rax
	movq	%rax, 79936(%rbp)
.L22:
	movzbl	-90(%rbp), %eax
	cmpb	$75, %al
	jne	.L21
	movq	-88(%rbp), %rax
	movq	%rax, %xmm0
	call	f_to_k
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	floor
	movq	%xmm0, %rax
	movq	%rax, 79936(%rbp)
.L21:
	movzbl	-89(%rbp), %eax
	cmpb	$75, %al
	jne	.L23
	movzbl	-90(%rbp), %eax
	cmpb	$67, %al
	jne	.L24
	movq	-88(%rbp), %rax
	movq	%rax, %xmm0
	call	k_to_c
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	floor
	movq	%xmm0, %rax
	movq	%rax, 79936(%rbp)
.L24:
	movzbl	-90(%rbp), %eax
	cmpb	$70, %al
	jne	.L23
	movq	-88(%rbp), %rax
	movq	%rax, %xmm0
	call	k_to_f
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	floor
	movq	%xmm0, %rax
	movq	%rax, 79936(%rbp)
.L23:
	movl	79948(%rbp), %eax
	cltq
	movsd	79936(%rbp), %xmm0
	movsd	%xmm0, -80(%rbp,%rax,8)
	addl	$1, 79948(%rbp)
.L18:
	movl	79928(%rbp), %eax
	cmpl	%eax, 79948(%rbp)
	jl	.L25
	movl	$0, 79932(%rbp)
	jmp	.L26
.L27:
	movl	79932(%rbp), %eax
	cltq
	movsd	-80(%rbp,%rax,8), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %rdx
	movq	%rdx, %xmm0
	movapd	%xmm0, %xmm1
	movq	%rax, %rdx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	printf
	addl	$1, 79932(%rbp)
.L26:
	movl	79928(%rbp), %eax
	cmpl	%eax, 79932(%rbp)
	jl	.L27
	movl	$0, %eax
	addq	$80080, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.long	0
	.long	1075970048
	.align 8
.LC1:
	.long	0
	.long	1075052544
	.align 8
.LC2:
	.long	0
	.long	1077936128
	.align 8
.LC3:
	.long	1717986918
	.long	1081152102
	.ident	"GCC: (GNU) 13.2.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	floor;	.scl	2;	.type	32;	.endef
