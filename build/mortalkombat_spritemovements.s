#NO_APP
	.text
	.even
	.globl	__Z6moveUpv
__Z6moveUpv:
	link.w %fp,#0
	unlk %fp
	rts
	.even
	.globl	__Z8moveDownv
__Z8moveDownv:
	link.w %fp,#0
	unlk %fp
	rts
	.even
	.globl	__Z13bgScrollRightf
__Z13bgScrollRightf:
	link.w %fp,#0
	movem.l #12348,-(%sp)
	move.l 8(%fp),%d2
	move.l sprite,%a2
	lea ___floatsisf,%a3
	move.w 2120(%a2),%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	move.l %d0,%d3
	move.l #0xc42d0000,(%sp)
	move.l %d0,-(%sp)
	jsr ___gesf2
	addq.l #8,%sp
	tst.l %d0
	jlt .L3
	move.w 1736(%a2),%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	lea ___subsf3,%a5
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #8,%sp
	lea ___fixsfsi,%a4
	move.l %d0,-(%sp)
	jsr (%a4)
	move.w %d0,1736(%a2)
	move.w 1928(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	move.w %d0,1928(%a2)
	move.l %d2,(%sp)
	move.l %d2,-(%sp)
	jsr ___addsf3
	addq.l #8,%sp
	move.l %d0,%d2
	move.l %d0,-(%sp)
	move.l %d3,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	move.w %d0,2120(%a2)
	move.w 2312(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	move.w %d0,2312(%a2)
	move.w 2504(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.w %d0,2504(%a2)
.L3:
	movem.l -24(%fp),#15372
	unlk %fp
	rts
	.even
	.globl	__Z12bgScrollLeftf
__Z12bgScrollLeftf:
	link.w %fp,#0
	movem.l #12348,-(%sp)
	move.l 8(%fp),%d2
	move.l sprite,%a2
	lea ___floatsisf,%a3
	move.w 2120(%a2),%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	move.l %d0,%d3
	move.l #0xc0000000,(%sp)
	move.l %d0,-(%sp)
	jsr ___lesf2
	addq.l #8,%sp
	tst.l %d0
	jgt .L9
	move.w 1736(%a2),%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	lea ___addsf3,%a4
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a4)
	addq.l #8,%sp
	lea ___fixsfsi,%a5
	move.l %d0,-(%sp)
	jsr (%a5)
	move.w %d0,1736(%a2)
	move.w 1928(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	move.w %d0,1928(%a2)
	move.l %d2,(%sp)
	move.l %d2,-(%sp)
	jsr (%a4)
	addq.l #8,%sp
	move.l %d0,%d2
	move.l %d3,-(%sp)
	move.l %d0,-(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	move.w %d0,2120(%a2)
	move.w 2312(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	move.w %d0,2312(%a2)
	move.w 2504(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.w %d0,2504(%a2)
.L9:
	movem.l -24(%fp),#15372
	unlk %fp
	rts
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
