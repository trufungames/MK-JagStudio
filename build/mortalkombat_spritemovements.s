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
	.globl	__Z9moveRightv
__Z9moveRightv:
	link.w %fp,#0
	movem.l #60,-(%sp)
	move.l sprite,%a2
	lea ___floatsisf,%a5
	move.w 968(%a2),%a0
	move.l %a0,-(%sp)
	jsr (%a5)
	lea ___subsf3,%a4
	move.l #0x3f800000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a4)
	addq.l #8,%sp
	lea ___fixsfsi,%a3
	move.l %d0,-(%sp)
	jsr (%a3)
	move.w %d0,968(%a2)
	move.w 1160(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a5)
	move.l #0x3f800000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a3)
	move.w %d0,1160(%a2)
	move.w 1352(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a5)
	move.l #0x40000000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a3)
	addq.l #4,%sp
	move.w %d0,1352(%a2)
	movem.l -16(%fp),#15360
	unlk %fp
	rts
	.even
	.globl	__Z8moveLeftv
__Z8moveLeftv:
	link.w %fp,#0
	movem.l #60,-(%sp)
	move.l sprite,%a2
	lea ___floatsisf,%a5
	move.w 968(%a2),%a0
	move.l %a0,-(%sp)
	jsr (%a5)
	lea ___addsf3,%a4
	move.l #0x3f800000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a4)
	addq.l #8,%sp
	lea ___fixsfsi,%a3
	move.l %d0,-(%sp)
	jsr (%a3)
	move.w %d0,968(%a2)
	move.w 1160(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a5)
	move.l #0x3f800000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a3)
	move.w %d0,1160(%a2)
	move.w 1352(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a5)
	move.l #0x40000000,(%sp)
	move.l %d0,-(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a3)
	addq.l #4,%sp
	move.w %d0,1352(%a2)
	movem.l -16(%fp),#15360
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
