	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 4
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	callq	_get_int
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movl	%ecx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_get_int                ## -- Begin function get_int
	.p2align	4, 0x90
_get_int:                               ## @get_int
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
LBB1_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_3 Depth 2
	leaq	L_.str(%rip), %rdi
	leaq	-4(%rbp), %rsi
	movb	$0, %al
	callq	_scanf
	cmpl	$1, %eax
	je	LBB1_6
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_3
LBB1_3:                                 ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	callq	_getchar
                                        ## kill: def $al killed $al killed $eax
	movb	%al, -5(%rbp)
	movsbl	%al, %ecx
	cmpl	$10, %ecx
	je	LBB1_5
## %bb.4:                               ##   in Loop: Header=BB1_3 Depth=2
	movsbl	-5(%rbp), %edi
	callq	_putchar
	leaq	L_.str.1(%rip), %rdi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	jmp	LBB1_3
LBB1_5:                                 ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_1
LBB1_6:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

L_.str.1:                               ## @.str.1
	.asciz	" is not an integer.\nPlease enter an integer value\n"


.subsections_via_symbols
