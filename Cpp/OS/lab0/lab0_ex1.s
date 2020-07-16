	.file	"lab0_ex1.c"
	.globl	count
	.data
	.align 4
	.type	count, @object
	.size	count, 4
count:
	.long	1
	.globl	value
	.align 4
	.type	value, @object
	.size	value, 4
value:
	.long	1
	.comm	buf,40,32
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%ebx
	.cfi_offset 7, -12
	.cfi_offset 3, -16
	movl	count, %edx
	movl	value, %eax
	movl	buf, %ebx
	movl	%edx, %ecx
	movl	%ebx, %edi
#APP
# 6 "lab0_ex1.c" 1
	cld 
	rep 
	stosl
# 0 "" 2
#NO_APP
	popl	%ebx
	.cfi_restore 3
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
