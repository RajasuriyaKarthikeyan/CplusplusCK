	.file	"auto.c"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sd	s0,24(sp)
	sd	s1,16(sp)
	addi	s0,sp,32
	li	a5,10
	sw	a5,-20(s0)
	nop
	ld	s0,24(sp)
	ld	s1,16(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: () 10.2.0"
