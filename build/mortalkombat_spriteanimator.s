#NO_APP
	.text
	.even
	.globl	__Z12animateFramejjP14AnimationFramefj
__Z12animateFramejjP14AnimationFramefj:
	link.w %fp,#0
	movem.l #15932,-(%sp)
	move.l 8(%fp),%d0
	move.l 12(%fp),%d1
	move.l 20(%fp),%d2
	move.l %d0,%a2
	add.l %d0,%a2
	add.l %a2,%d0
	lsl.l #6,%d0
	move.l sprite,%a2
	add.l %d0,%a2
	add.l %d1,%d1
	add.l %d1,%d1
	move.l %d1,%d0
	lsl.l #3,%d0
	sub.l %d1,%d0
	move.l 16(%fp),%a4
	add.l %d0,%a4
	move.l (%a4),%d3
	move.l %d3,28(%a2)
	move.l 4(%a4),%d6
	move.l %d6,32(%a2)
	lea ___floatunsisf,%a3
	move.l %d3,-(%sp)
	jsr (%a3)
	lea ___mulsf3,%a5
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a5)
	addq.l #8,%sp
	move.l #___fixsfsi,%d5
	move.l %d0,-(%sp)
	move.l %d5,%a0
	jsr (%a0)
	move.l %d0,104(%a2)
	move.l #___mulsi3,%d4
	move.l %d3,(%sp)
	move.l %d6,-(%sp)
	move.l %d4,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d5,%a0
	jsr (%a0)
	move.l %d0,48(%a2)
	move.l 8(%a4),(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a5)
	addq.l #8,%sp
	move.l %d0,%d2
	move.l 12(%a4),-(%sp)
	move.l 144(%a2),-(%sp)
	move.l %d4,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a3)
	lea ___addsf3,%a4
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a4)
	addq.l #8,%sp
	move.l %d0,%d2
	move.l 24(%fp),-(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixunssfsi
	addq.l #4,%sp
	move.l %d0,44(%a2)
	movem.l -36(%fp),#15484
	unlk %fp
	rts
	.even
	.globl	__Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
__Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb:
	link.w %fp,#0
	movem.l #15408,-(%sp)
	move.l 8(%fp),%a2
	move.l 12(%fp),%a3
	move.l 16(%fp),%d4
	move.b 23(%fp),%d3
	move.b 27(%fp),%d5
	move.l 8(%a2),-(%sp)
	move.l 4(%a2),-(%sp)
	move.l %a3,-(%sp)
	move.l 16(%a2),-(%sp)
	move.l (%a2),-(%sp)
	jsr __Z12animateFramejjP14AnimationFramefj
	move.w raptor_ticks,%a0
	move.l 16(%a2),%d1
	move.w %a0,%a1
	move.l %d1,%d2
	add.l %d1,%d2
	add.l %d2,%d2
	move.l %d2,%d0
	lsl.l #3,%d0
	sub.l %d2,%d0
	move.l 24(%a3,%d0.l),%d0
	add.l 12(%a2),%d0
	lea (20,%sp),%sp
	cmp.l %a1,%d0
	jhi .L2
	tst.b %d3
	jne .L4
	subq.l #1,%d1
	move.l %d1,16(%a2)
	jlt .L10
.L5:
	move.w %a0,%a0
	move.l %a0,12(%a2)
.L2:
	movem.l -24(%fp),#3132
	unlk %fp
	rts
.L4:
	addq.l #1,%d1
	move.l %d1,16(%a2)
	cmp.l %d4,%d1
	jlt .L5
	tst.b %d5
	jne .L8
	move.l %d4,16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L2
.L10:
	tst.b %d5
	jeq .L8
	subq.l #1,%d4
	move.l %d4,16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L2
.L8:
	clr.l 16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L2
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
