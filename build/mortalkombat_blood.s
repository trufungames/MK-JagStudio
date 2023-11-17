#NO_APP
	.text
	.even
	.globl	__Z11bloodUpdatev
__Z11bloodUpdatev:
	link.w %fp,#0
	move.l %d2,-(%sp)
	tst.b _bloodSpray1InUse
	jne .L9
.L2:
	tst.b _bloodSpray2InUse
	jne .L10
.L5:
	tst.b _bloodGlobInUse
	jne .L11
.L1:
	move.l -4(%fp),%d2
	unlk %fp
	rts
.L11:
	pea 1.w
	pea 1.w
	pea 6.w
	pea _bloodGlobFrames
	pea _bloodGlobAnimator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	pea 6.w
	pea _bloodGlobAnimator
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L1
	clr.b _bloodGlobInUse
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,10372(%a0)
	move.l -4(%fp),%d2
	unlk %fp
	rts
.L10:
	pea 1.w
	pea 1.w
	pea 5.w
	pea _bloodSprayFrames
	pea _bloodSpray2Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	pea 5.w
	pea _bloodSpray2Animator
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L5
	clr.b _bloodSpray2InUse
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,10180(%a0)
	tst.b _bloodGlobInUse
	jeq .L1
	jra .L11
.L9:
	pea 1.w
	pea 1.w
	pea 5.w
	pea _bloodSprayFrames
	pea _bloodSpray1Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	moveq #3,%d0
	cmp.l _bloodSpray1Animator+16.l,%d0
	jeq .L12
.L3:
	pea 5.w
	pea _bloodSpray1Animator
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L2
.L13:
	clr.b _bloodSpray1InUse
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,9988(%a0)
	tst.b _bloodSpray2InUse
	jeq .L5
	jra .L10
.L12:
	tst.b _bloodSpray2InUse
	jne .L3
	move.b #1,_bloodSpray2InUse
	move.l sprite,%a0
	move.l _bloodDirection,%d1
	move.w %d1,%d0
	move.w %d1,%d2
	muls.w #-12,%d2
	add.w 9992(%a0),%d2
	move.w %d2,10184(%a0)
	neg.w %d0
	add.w %d0,%d0
	add.w %d0,%d0
	add.w 9996(%a0),%d0
	move.w %d0,10188(%a0)
	moveq #1,%d0
	cmp.l %d1,%d0
	seq %d0
	ext.w %d0
	ext.l %d0
	moveq #1,%d1
	or.l %d0,%d1
	move.l %d1,10200(%a0)
	moveq #1,%d0
	move.l %d0,10180(%a0)
	clr.l _bloodSpray2Animator+16
	pea 5.w
	pea _bloodSpray1Animator
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L2
	jra .L13
	.even
	.globl	__Z10bloodSprayiii
__Z10bloodSprayiii:
	link.w %fp,#0
	move.l 16(%fp),%d0
	tst.b _bloodSpray1InUse
	jne .L15
	move.b #1,_bloodSpray1InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a0
	move.w 10(%fp),9992(%a0)
	move.w 14(%fp),9996(%a0)
	moveq #1,%d1
	cmp.l %d0,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,10008(%a0)
	moveq #1,%d0
	move.l %d0,9988(%a0)
	clr.l _bloodSpray1Animator+16
.L15:
	unlk %fp
	rts
	.even
	.globl	__Z9bloodGlobiii
__Z9bloodGlobiii:
	link.w %fp,#0
	move.l 16(%fp),%d0
	tst.b _bloodGlobInUse
	jne .L21
	move.b #1,_bloodGlobInUse
	move.l %d0,_bloodDirection
	move.l sprite,%a0
	move.w 10(%fp),10376(%a0)
	move.w 14(%fp),10380(%a0)
	moveq #1,%d1
	cmp.l %d0,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,10392(%a0)
	moveq #1,%d0
	move.l %d0,10372(%a0)
	clr.l _bloodGlobAnimator+16
.L21:
	unlk %fp
	rts
	.globl	_bloodDirection
	.data
	.even
_bloodDirection:
	.long	1
	.globl	_bloodGlobInUse
	.bss
_bloodGlobInUse:
	.skip 1
	.globl	_bloodSpray2InUse
_bloodSpray2InUse:
	.skip 1
	.globl	_bloodSpray1InUse
_bloodSpray1InUse:
	.skip 1
	.globl	_bloodGlobFrames
	.data
	.even
_bloodGlobFrames:
	.long	64
	.long	32
	.long	0
	.long	32
	.long	0
	.long	0
	.long	5
	.long	64
	.long	32
	.long	64
	.long	32
	.long	0
	.long	0
	.long	4
	.long	64
	.long	32
	.long	128
	.long	32
	.long	0
	.long	0
	.long	4
	.long	64
	.long	32
	.long	192
	.long	32
	.long	0
	.long	0
	.long	4
	.long	64
	.long	32
	.long	256
	.long	32
	.long	0
	.long	0
	.long	4
	.long	64
	.long	32
	.long	320
	.long	32
	.long	0
	.long	0
	.long	4
	.globl	_bloodGlobAnimator
	.even
_bloodGlobAnimator:
	.long	54
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodSprayFrames
	.even
_bloodSprayFrames:
	.long	64
	.long	32
	.long	0
	.long	0
	.long	0
	.long	0
	.long	5
	.long	64
	.long	32
	.long	64
	.long	0
	.long	0
	.long	0
	.long	4
	.long	64
	.long	32
	.long	128
	.long	0
	.long	0
	.long	0
	.long	4
	.long	64
	.long	32
	.long	192
	.long	0
	.long	0
	.long	0
	.long	4
	.long	64
	.long	32
	.long	256
	.long	0
	.long	0
	.long	0
	.long	4
	.globl	_bloodSpray2Animator
	.even
_bloodSpray2Animator:
	.long	53
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodSpray1Animator
	.even
_bloodSpray1Animator:
	.long	52
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	colliders
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
