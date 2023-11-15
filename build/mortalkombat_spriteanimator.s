#NO_APP
	.text
	.even
__Z12animateFramejjP14AnimationFramefjiiii.constprop.1:
	link.w %fp,#-4
	movem.l #16188,-(%sp)
	move.l 8(%fp),%d0
	move.l 12(%fp),%d1
	move.l 20(%fp),%d2
	move.l %d0,%a2
	add.l %d0,%a2
	add.l %a2,%d0
	lsl.l #6,%d0
	move.l sprite,%a2
	add.l %d0,%a2
	move.w 8(%a2),%a0
	move.l %a0,-4(%fp)
	move.w 12(%a2),%d7
	ext.l %d7
	add.l %d1,%d1
	add.l %d1,%d1
	move.l %d1,%d0
	lsl.l #3,%d0
	sub.l %d1,%d0
	move.l 16(%fp),%a3
	add.l %d0,%a3
	move.l (%a3),%d3
	move.l %d3,28(%a2)
	move.l 4(%a3),%d6
	move.l %d6,32(%a2)
	lea ___floatunsisf,%a4
	move.l %d3,-(%sp)
	jsr (%a4)
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
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d5,%a0
	jsr (%a0)
	move.l %d0,48(%a2)
	move.l 8(%a3),(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a5)
	addq.l #8,%sp
	move.l %d0,%d2
	move.l 12(%a3),-(%sp)
	move.l 144(%a2),-(%sp)
	move.l %d4,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	lea ___addsf3,%a5
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a5)
	addq.l #8,%sp
	move.l %d0,%d2
	move.l 24(%fp),-(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixunssfsi
	addq.l #4,%sp
	move.l %d0,44(%a2)
	move.w -2(%fp),%d0
	add.w 18(%a3),%d0
	move.w %d0,8(%a2)
	move.w 22(%a3),%a3
	add.w %d7,%a3
	move.w %a3,12(%a2)
	movem.l -44(%fp),#15612
	unlk %fp
	rts
	.even
	.globl	__Z12animateFramejjP14AnimationFramefji
__Z12animateFramejjP14AnimationFramefji:
	link.w %fp,#0
	unlk %fp
	jra (__Z12animateFramejjP14AnimationFramefjiiii.constprop.1)
	.even
	.globl	__Z12animateFramejjP14AnimationFramefjiiii
__Z12animateFramejjP14AnimationFramefjiiii:
	link.w %fp,#-8
	movem.l #16188,-(%sp)
	move.l 8(%fp),%d0
	move.l 12(%fp),%d1
	move.l 20(%fp),%d3
	move.l 32(%fp),%d5
	move.l 36(%fp),%d4
	move.l 40(%fp),%d6
	move.l %d0,%a2
	add.l %d0,%a2
	add.l %a2,%d0
	lsl.l #6,%d0
	move.l sprite,%a2
	add.l %d0,%a2
	tst.l %d5
	jne .L5
	move.w 8(%a2),%d5
	ext.l %d5
.L5:
	tst.l %d4
	jne .L6
	move.w 12(%a2),%d4
	ext.l %d4
.L6:
	add.l %d1,%d1
	add.l %d1,%d1
	move.l %d1,%d0
	lsl.l #3,%d0
	sub.l %d1,%d0
	move.l 16(%fp),%a3
	add.l %d0,%a3
	move.l (%a3),%d2
	move.l %d2,28(%a2)
	move.l 4(%a3),%d1
	move.l %d1,32(%a2)
	lea ___floatunsisf,%a4
	move.l %d2,-(%sp)
	move.l %d1,-8(%fp)
	jsr (%a4)
	lea ___mulsf3,%a5
	move.l %d0,(%sp)
	move.l %d3,-(%sp)
	jsr (%a5)
	addq.l #8,%sp
	lea ___fixsfsi,%a0
	move.l %d0,-(%sp)
	move.l %a0,-4(%fp)
	jsr (%a0)
	move.l %d0,104(%a2)
	move.l #___mulsi3,%d7
	move.l %d2,(%sp)
	move.l -8(%fp),%d1
	move.l %d1,-(%sp)
	move.l %d7,%a1
	jsr (%a1)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d3,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	lea ___fixsfsi,%a0
	jsr (%a0)
	move.l %d0,48(%a2)
	move.l 8(%a3),(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d3,-(%sp)
	jsr (%a5)
	addq.l #8,%sp
	move.l %d0,%d3
	move.l 12(%a3),-(%sp)
	move.l 144(%a2),-(%sp)
	move.l %d7,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	lea ___addsf3,%a5
	move.l %d0,(%sp)
	move.l %d3,-(%sp)
	jsr (%a5)
	addq.l #8,%sp
	move.l %d0,%d3
	move.l 24(%fp),-(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d3,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixunssfsi
	addq.l #4,%sp
	move.l %d0,44(%a2)
	move.w %d6,%d1
	move.w %d6,%d0
	muls.w 18(%a3),%d0
	add.w %d5,%d0
	move.w %d0,8(%a2)
	muls.w 22(%a3),%d1
	add.w %d4,%d1
	move.w %d1,12(%a2)
	moveq #-1,%d1
	cmp.l %d6,%d1
	jeq .L9
	movem.l -48(%fp),#15612
	unlk %fp
	rts
.L9:
	move.w 30(%fp),%a0
	sub.w %d2,%a0
	move.w %a0,%d2
	add.w %d0,%d2
	move.w %d2,8(%a2)
	movem.l -48(%fp),#15612
	unlk %fp
	rts
	.even
	.globl	__Z19animationIsCompleteP14SpriteAnimatori
__Z19animationIsCompleteP14SpriteAnimatori:
	link.w %fp,#0
	move.l 12(%fp),%d0
	subq.l #1,%d0
	move.l 8(%fp),%a0
	cmp.l 16(%a0),%d0
	sle %d0
	neg.b %d0
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
	move.l 20(%a2),-(%sp)
	move.l 8(%a2),-(%sp)
	move.l 4(%a2),-(%sp)
	move.l %a3,-(%sp)
	move.l 16(%a2),-(%sp)
	move.l (%a2),-(%sp)
	jsr (__Z12animateFramejjP14AnimationFramefjiiii.constprop.1)
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
	lea (24,%sp),%sp
	cmp.l %a1,%d0
	jhi .L12
	tst.b %d3
	jne .L14
	subq.l #1,%d1
	move.l %d1,16(%a2)
	jlt .L20
.L15:
	move.w %a0,%a0
	move.l %a0,12(%a2)
.L12:
	movem.l -24(%fp),#3132
	unlk %fp
	rts
.L14:
	addq.l #1,%d1
	move.l %d1,16(%a2)
	cmp.l %d4,%d1
	jlt .L15
	tst.b %d5
	jne .L18
	move.l %d4,16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L12
.L20:
	tst.b %d5
	jeq .L18
	subq.l #1,%d4
	move.l %d4,16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L12
.L18:
	clr.l 16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L12
	.even
	.globl	__Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
__Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii:
	link.w %fp,#0
	movem.l #15408,-(%sp)
	move.l 8(%fp),%a2
	move.l 12(%fp),%a3
	move.l 16(%fp),%d4
	move.b 23(%fp),%d3
	move.b 27(%fp),%d5
	move.l 36(%fp),-(%sp)
	move.l 32(%fp),-(%sp)
	move.l 28(%fp),-(%sp)
	move.l 20(%a2),-(%sp)
	move.l 8(%a2),-(%sp)
	move.l 4(%a2),-(%sp)
	move.l %a3,-(%sp)
	move.l 16(%a2),-(%sp)
	move.l (%a2),-(%sp)
	jsr __Z12animateFramejjP14AnimationFramefjiiii
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
	lea (36,%sp),%sp
	cmp.l %a1,%d0
	jhi .L22
	tst.b %d3
	jne .L24
	subq.l #1,%d1
	move.l %d1,16(%a2)
	jlt .L30
.L25:
	move.w %a0,%a0
	move.l %a0,12(%a2)
.L22:
	movem.l -24(%fp),#3132
	unlk %fp
	rts
.L24:
	addq.l #1,%d1
	move.l %d1,16(%a2)
	cmp.l %d4,%d1
	jlt .L25
	tst.b %d5
	jne .L28
	move.l %d4,16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L22
.L30:
	tst.b %d5
	jeq .L28
	subq.l #1,%d4
	move.l %d4,16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L22
.L28:
	clr.l 16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L22
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
