#NO_APP
	.text
	.even
__Z12animateFramejjP14AnimationFramefjii.constprop.1:
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
	.globl	__Z12animateFramejjP14AnimationFramefj
__Z12animateFramejjP14AnimationFramefj:
	link.w %fp,#0
	unlk %fp
	jra (__Z12animateFramejjP14AnimationFramefjii.constprop.1)
	.even
	.globl	__Z12animateFramejjP14AnimationFramefjii
__Z12animateFramejjP14AnimationFramefjii:
	link.w %fp,#-4
	movem.l #16188,-(%sp)
	move.l 8(%fp),%d0
	move.l 12(%fp),%d1
	move.l 20(%fp),%d2
	move.l 28(%fp),%d5
	move.l 32(%fp),%d4
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
	move.l (%a3),%d3
	move.l %d3,28(%a2)
	move.l 4(%a3),%d1
	move.l %d1,32(%a2)
	lea ___floatunsisf,%a4
	move.l %d3,-(%sp)
	move.l %d1,-4(%fp)
	jsr (%a4)
	lea ___mulsf3,%a5
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a5)
	addq.l #8,%sp
	move.l #___fixsfsi,%d7
	move.l %d0,-(%sp)
	move.l %d7,%a0
	jsr (%a0)
	move.l %d0,104(%a2)
	move.l #___mulsi3,%d6
	move.l %d3,(%sp)
	move.l -4(%fp),%d1
	move.l %d1,-(%sp)
	move.l %d6,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d7,%a0
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
	move.l %d6,%a0
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
	move.w 18(%a3),%d0
	add.w %d5,%d0
	move.w %d0,8(%a2)
	move.w 22(%a3),%a3
	add.w %d4,%a3
	move.w %a3,12(%a2)
	movem.l -44(%fp),#15612
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
	move.l 8(%a2),-(%sp)
	move.l 4(%a2),-(%sp)
	move.l %a3,-(%sp)
	move.l 16(%a2),-(%sp)
	move.l (%a2),-(%sp)
	jsr (__Z12animateFramejjP14AnimationFramefjii.constprop.1)
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
	jhi .L10
	tst.b %d3
	jne .L12
	subq.l #1,%d1
	move.l %d1,16(%a2)
	jlt .L18
.L13:
	move.w %a0,%a0
	move.l %a0,12(%a2)
.L10:
	movem.l -24(%fp),#3132
	unlk %fp
	rts
.L12:
	addq.l #1,%d1
	move.l %d1,16(%a2)
	cmp.l %d4,%d1
	jlt .L13
	tst.b %d5
	jne .L16
	move.l %d4,16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L10
.L18:
	tst.b %d5
	jeq .L16
	subq.l #1,%d4
	move.l %d4,16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L10
.L16:
	clr.l 16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L10
	.even
	.globl	__Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
__Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii:
	link.w %fp,#0
	movem.l #15408,-(%sp)
	move.l 8(%fp),%a2
	move.l 12(%fp),%a3
	move.l 16(%fp),%d4
	move.b 23(%fp),%d3
	move.b 27(%fp),%d5
	move.l 32(%fp),-(%sp)
	move.l 28(%fp),-(%sp)
	move.l 8(%a2),-(%sp)
	move.l 4(%a2),-(%sp)
	move.l %a3,-(%sp)
	move.l 16(%a2),-(%sp)
	move.l (%a2),-(%sp)
	jsr __Z12animateFramejjP14AnimationFramefjii
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
	lea (28,%sp),%sp
	cmp.l %a1,%d0
	jhi .L20
	tst.b %d3
	jne .L22
	subq.l #1,%d1
	move.l %d1,16(%a2)
	jlt .L28
.L23:
	move.w %a0,%a0
	move.l %a0,12(%a2)
.L20:
	movem.l -24(%fp),#3132
	unlk %fp
	rts
.L22:
	addq.l #1,%d1
	move.l %d1,16(%a2)
	cmp.l %d4,%d1
	jlt .L23
	tst.b %d5
	jne .L26
	move.l %d4,16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L20
.L28:
	tst.b %d5
	jeq .L26
	subq.l #1,%d4
	move.l %d4,16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L20
.L26:
	clr.l 16(%a2)
	move.w %a0,%a0
	move.l %a0,12(%a2)
	jra .L20
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
