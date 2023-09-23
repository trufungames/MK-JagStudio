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
	.globl	__Z13bgScrollRightv
__Z13bgScrollRightv:
	link.w %fp,#0
	movem.l #8252,-(%sp)
	move.l sprite,%a2
	lea ___floatsisf,%a3
	move.w 1160(%a2),%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	move.l %d0,%d2
	move.l #0xc42d0000,(%sp)
	move.l %d0,-(%sp)
	jsr ___gesf2
	addq.l #8,%sp
	tst.l %d0
	jlt .L3
	move.w 776(%a2),%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	lea ___subsf3,%a5
	move.l #0x3f800000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #8,%sp
	lea ___fixsfsi,%a4
	move.l %d0,-(%sp)
	jsr (%a4)
	move.w %d0,776(%a2)
	move.w 968(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l #0x3f800000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	move.w %d0,968(%a2)
	move.l #0x40000000,(%sp)
	move.l %d2,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	move.w %d0,1160(%a2)
	move.w 1352(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l #0x40000000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	move.w %d0,1352(%a2)
	move.w 1544(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l #0x40000000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.w %d0,1544(%a2)
.L3:
	movem.l -20(%fp),#15364
	unlk %fp
	rts
	.even
	.globl	__Z12bgScrollLeftv
__Z12bgScrollLeftv:
	link.w %fp,#0
	movem.l #8252,-(%sp)
	move.l sprite,%a2
	lea ___floatsisf,%a3
	move.w 1160(%a2),%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	move.l %d0,%d2
	move.l #0xc0000000,(%sp)
	move.l %d0,-(%sp)
	jsr ___lesf2
	addq.l #8,%sp
	tst.l %d0
	jgt .L9
	move.w 776(%a2),%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	lea ___addsf3,%a5
	move.l #0x3f800000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #8,%sp
	lea ___fixsfsi,%a4
	move.l %d0,-(%sp)
	jsr (%a4)
	move.w %d0,776(%a2)
	move.w 968(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l #0x3f800000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	move.w %d0,968(%a2)
	move.l #0x40000000,(%sp)
	move.l %d2,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	move.w %d0,1160(%a2)
	move.w 1352(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l #0x40000000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	move.w %d0,1352(%a2)
	move.w 1544(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l #0x40000000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.w %d0,1544(%a2)
.L9:
	movem.l -20(%fp),#15364
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
