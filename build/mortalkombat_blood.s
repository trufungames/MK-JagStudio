#NO_APP
	.text
	.even
	.globl	__Z9bloodInitv
__Z9bloodInitv:
	link.w %fp,#0
	moveq #3,%d0
	move.l %d0,_updateTicks
	clr.l _lastTicks
	move.l #0x40e00000,_bloodSpeed
	move.l #0x40800000,_gravity
	move.l #0xc1a00000,_bloodDropMomentumStart
	clr.b _bloodSpray1InUse
	clr.b _bloodSpray2InUse
	clr.b _bloodGlobInUse
	clr.b _bloodDrop1InUse
	clr.b _bloodDrop2InUse
	clr.b _bloodDrop3InUse
	clr.b _bloodDrop4InUse
	clr.b _bloodDrop5InUse
	clr.b _bloodDrop6InUse
	clr.b _bloodDrop7InUse
	clr.b _bloodDrop8InUse
	clr.b _bloodDrop9InUse
	clr.b _bloodDrop10InUse
	clr.b _bloodPool1InUse
	clr.b _bloodPool2InUse
	clr.b _bloodPool3InUse
	clr.b _bloodPool4InUse
	clr.b _bloodPool5InUse
	clr.b _bloodPool6InUse
	clr.b _bloodPool7InUse
	clr.b _bloodPool8InUse
	clr.b _bloodPool9InUse
	clr.b _bloodPool10InUse
	move.b #1,%d0
	move.l %d0,_bloodDirection
	unlk %fp
	rts
	.even
	.globl	__Z11bloodUpdatev
__Z11bloodUpdatev:
	link.w %fp,#0
	movem.l #14396,-(%sp)
	tst.b _bloodSpray1InUse
	jne .L18
.L3:
	tst.b _bloodSpray2InUse
	jne .L19
.L6:
	tst.b _bloodGlobInUse
	jne .L20
.L7:
	tst.b _bloodDrop1InUse
	jne .L8
.L16:
	move.b _bloodPool1InUse,%d2
	jne .L21
.L2:
	movem.l -28(%fp),#15388
	unlk %fp
	rts
.L21:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	pea _bloodPool1Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	movem.l -28(%fp),#15388
	unlk %fp
	rts
.L8:
	pea 1.w
	moveq #-1,%d0
	cmp.l _bloodDirection.l,%d0
	seq %d0
	ext.w %d0
	ext.l %d0
	neg.l %d0
	move.l %d0,-(%sp)
	pea 8.w
	pea _bloodDropFrames
	pea _bloodDrop1Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.w raptor_ticks,%a3
	move.l %a3,%a0
	sub.l _lastTicks,%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jlt .L16
	move.l sprite,%a2
	lea ___floatsisf,%a4
	move.w 10568(%a2),%a0
	move.l %a0,-(%sp)
	jsr (%a4)
	move.l %d0,%d2
	move.l _bloodDirection,(%sp)
	jsr (%a4)
	move.l _bloodSpeed,(%sp)
	move.l %d0,-(%sp)
	jsr ___mulsf3
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	jsr ___subsf3
	addq.l #8,%sp
	lea ___fixsfsi,%a5
	move.l %d0,-(%sp)
	jsr (%a5)
	move.l %d0,%d4
	move.w %d0,10568(%a2)
	move.l _bloodDrop1Momentum,%d3
	move.w 10572(%a2),%a0
	move.l %a0,(%sp)
	jsr (%a4)
	lea ___addsf3,%a4
	move.l %d3,(%sp)
	move.l %d0,-(%sp)
	jsr (%a4)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.w %d0,10572(%a2)
	move.b _bloodPool1InUse,%d2
	cmp.w #185,%d0
	jle .L12
	tst.b %d2
	jne .L13
	move.b #1,_bloodPool1InUse
	move.w %d4,12488(%a2)
	move.w #185,12492(%a2)
	moveq #1,%d0
	move.l %d0,12484(%a2)
	clr.l _bloodPool1Animator+16
	moveq #1,%d2
.L13:
	moveq #-1,%d1
	move.l %d1,10564(%a2)
	clr.b _bloodDrop1InUse
.L12:
	move.l %d3,-(%sp)
	move.l _gravity,-(%sp)
	jsr (%a4)
	addq.l #8,%sp
	move.l %d0,_bloodDrop1Momentum
	move.l %a3,_lastTicks
	tst.b %d2
	jeq .L2
	jra .L21
.L20:
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
	jeq .L7
	clr.b _bloodGlobInUse
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,10372(%a0)
	tst.b _bloodDrop1InUse
	jeq .L16
	jra .L8
.L19:
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
	jeq .L6
	clr.b _bloodSpray2InUse
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,10180(%a0)
	tst.b _bloodGlobInUse
	jeq .L7
	jra .L20
.L18:
	pea 1.w
	pea 1.w
	pea 5.w
	pea _bloodSprayFrames
	pea _bloodSpray1Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	moveq #3,%d0
	cmp.l _bloodSpray1Animator+16.l,%d0
	jeq .L22
.L4:
	pea 5.w
	pea _bloodSpray1Animator
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L3
.L23:
	clr.b _bloodSpray1InUse
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,9988(%a0)
	tst.b _bloodSpray2InUse
	jeq .L6
	jra .L19
.L22:
	tst.b _bloodSpray2InUse
	jne .L4
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
	jeq .L3
	jra .L23
	.even
	.globl	__Z10bloodSprayiii
__Z10bloodSprayiii:
	link.w %fp,#0
	move.l 16(%fp),%d0
	tst.b _bloodSpray1InUse
	jne .L25
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
.L25:
	unlk %fp
	rts
	.even
	.globl	__Z9bloodGlobiii
__Z9bloodGlobiii:
	link.w %fp,#0
	move.l 16(%fp),%d0
	tst.b _bloodGlobInUse
	jne .L31
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
.L31:
	unlk %fp
	rts
	.even
	.globl	__Z9bloodDropiii
__Z9bloodDropiii:
	link.w %fp,#0
	move.l %d3,-(%sp)
	move.l %d2,-(%sp)
	move.l 8(%fp),%a0
	move.l 12(%fp),%d1
	move.l 16(%fp),%d0
	tst.b _bloodDrop1InUse
	jne .L38
	move.b #1,_bloodDrop1InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a1
	move.w %a0,10568(%a1)
	move.w %d1,10572(%a1)
	moveq #1,%d2
	cmp.l %d0,%d2
	seq %d2
	ext.w %d2
	ext.l %d2
	moveq #1,%d3
	or.l %d2,%d3
	move.l %d3,10584(%a1)
	moveq #1,%d2
	move.l %d2,10564(%a1)
	clr.l _bloodDrop1Animator+16
	move.l _bloodDropMomentumStart,_bloodDrop1Momentum
.L38:
	tst.b _bloodDrop2InUse
	jne .L40
	move.b #1,_bloodDrop2InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a1
	move.w %a0,10760(%a1)
	move.w %d1,10764(%a1)
	moveq #1,%d3
	cmp.l %d0,%d3
	seq %d2
	ext.w %d2
	ext.l %d2
	or.l %d2,%d3
	move.l %d3,10776(%a1)
	moveq #1,%d2
	move.l %d2,10756(%a1)
	clr.l _bloodDrop2Animator+16
.L40:
	tst.b _bloodDrop3InUse
	jne .L42
	move.b #1,_bloodDrop3InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a1
	move.w %a0,10952(%a1)
	move.w %d1,10956(%a1)
	moveq #1,%d3
	cmp.l %d0,%d3
	seq %d2
	ext.w %d2
	ext.l %d2
	or.l %d2,%d3
	move.l %d3,10968(%a1)
	moveq #1,%d2
	move.l %d2,10948(%a1)
	clr.l _bloodDrop3Animator+16
.L42:
	tst.b _bloodDrop4InUse
	jne .L44
	move.b #1,_bloodDrop4InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a1
	move.w %a0,11144(%a1)
	move.w %d1,11148(%a1)
	moveq #1,%d3
	cmp.l %d0,%d3
	seq %d2
	ext.w %d2
	ext.l %d2
	or.l %d2,%d3
	move.l %d3,11160(%a1)
	moveq #1,%d2
	move.l %d2,11140(%a1)
	clr.l _bloodDrop4Animator+16
.L44:
	tst.b _bloodDrop5InUse
	jne .L46
	move.b #1,_bloodDrop5InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a1
	move.w %a0,11336(%a1)
	move.w %d1,11340(%a1)
	moveq #1,%d3
	cmp.l %d0,%d3
	seq %d2
	ext.w %d2
	ext.l %d2
	or.l %d2,%d3
	move.l %d3,11352(%a1)
	moveq #1,%d2
	move.l %d2,11332(%a1)
	clr.l _bloodDrop5Animator+16
.L46:
	tst.b _bloodDrop6InUse
	jne .L48
	move.b #1,_bloodDrop6InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a1
	move.w %a0,11528(%a1)
	move.w %d1,11532(%a1)
	moveq #1,%d3
	cmp.l %d0,%d3
	seq %d2
	ext.w %d2
	ext.l %d2
	or.l %d2,%d3
	move.l %d3,11544(%a1)
	moveq #1,%d2
	move.l %d2,11524(%a1)
	clr.l _bloodDrop6Animator+16
.L48:
	tst.b _bloodDrop7InUse
	jne .L50
	move.b #1,_bloodDrop7InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a1
	move.w %a0,11720(%a1)
	move.w %d1,11724(%a1)
	moveq #1,%d3
	cmp.l %d0,%d3
	seq %d2
	ext.w %d2
	ext.l %d2
	or.l %d2,%d3
	move.l %d3,11736(%a1)
	moveq #1,%d2
	move.l %d2,11716(%a1)
	clr.l _bloodDrop7Animator+16
.L50:
	tst.b _bloodDrop8InUse
	jne .L52
	move.b #1,_bloodDrop8InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a1
	move.w %a0,11912(%a1)
	move.w %d1,11916(%a1)
	moveq #1,%d3
	cmp.l %d0,%d3
	seq %d2
	ext.w %d2
	ext.l %d2
	or.l %d2,%d3
	move.l %d3,11928(%a1)
	moveq #1,%d2
	move.l %d2,11908(%a1)
	clr.l _bloodDrop8Animator+16
.L52:
	tst.b _bloodDrop9InUse
	jne .L54
	move.b #1,_bloodDrop9InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a1
	move.w %a0,12104(%a1)
	move.w %d1,12108(%a1)
	moveq #1,%d3
	cmp.l %d0,%d3
	seq %d2
	ext.w %d2
	ext.l %d2
	or.l %d2,%d3
	move.l %d3,12120(%a1)
	moveq #1,%d2
	move.l %d2,12100(%a1)
	clr.l _bloodDrop9Animator+16
.L54:
	tst.b _bloodDrop10InUse
	jne .L37
	move.b #1,_bloodDrop10InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a1
	move.w %a0,12296(%a1)
	move.w %d1,12300(%a1)
	moveq #1,%d3
	cmp.l %d0,%d3
	seq %d0
	ext.w %d0
	ext.l %d0
	moveq #1,%d1
	or.l %d0,%d1
	move.l %d1,12312(%a1)
	moveq #1,%d2
	move.l %d2,12292(%a1)
	clr.l _bloodDrop10Animator+16
.L37:
	move.l (%sp)+,%d2
	move.l (%sp)+,%d3
	unlk %fp
	rts
	.even
	.globl	__Z9bloodPoolii
__Z9bloodPoolii:
	link.w %fp,#0
	tst.b _bloodPool1InUse
	jne .L70
	move.b #1,_bloodPool1InUse
	move.l sprite,%a0
	move.w 10(%fp),12488(%a0)
	move.w 14(%fp),12492(%a0)
	moveq #1,%d0
	move.l %d0,12484(%a0)
	clr.l _bloodPool1Animator+16
.L70:
	unlk %fp
	rts
	.globl	_bloodDrop1Momentum
	.bss
	.even
_bloodDrop1Momentum:
	.skip 4
	.globl	_bloodDropMomentumStart
	.even
_bloodDropMomentumStart:
	.skip 4
	.globl	_gravity
	.even
_gravity:
	.skip 4
	.globl	_bloodSpeed
	.even
_bloodSpeed:
	.skip 4
	.globl	_lastTicks
	.even
_lastTicks:
	.skip 4
	.globl	_updateTicks
	.even
_updateTicks:
	.skip 4
	.globl	_bloodDirection
	.data
	.even
_bloodDirection:
	.long	1
	.globl	_bloodPool10InUse
	.bss
_bloodPool10InUse:
	.skip 1
	.globl	_bloodPool9InUse
_bloodPool9InUse:
	.skip 1
	.globl	_bloodPool8InUse
_bloodPool8InUse:
	.skip 1
	.globl	_bloodPool7InUse
_bloodPool7InUse:
	.skip 1
	.globl	_bloodPool6InUse
_bloodPool6InUse:
	.skip 1
	.globl	_bloodPool5InUse
_bloodPool5InUse:
	.skip 1
	.globl	_bloodPool4InUse
_bloodPool4InUse:
	.skip 1
	.globl	_bloodPool3InUse
_bloodPool3InUse:
	.skip 1
	.globl	_bloodPool2InUse
_bloodPool2InUse:
	.skip 1
	.globl	_bloodPool1InUse
_bloodPool1InUse:
	.skip 1
	.globl	_bloodDrop10InUse
_bloodDrop10InUse:
	.skip 1
	.globl	_bloodDrop9InUse
_bloodDrop9InUse:
	.skip 1
	.globl	_bloodDrop8InUse
_bloodDrop8InUse:
	.skip 1
	.globl	_bloodDrop7InUse
_bloodDrop7InUse:
	.skip 1
	.globl	_bloodDrop6InUse
_bloodDrop6InUse:
	.skip 1
	.globl	_bloodDrop5InUse
_bloodDrop5InUse:
	.skip 1
	.globl	_bloodDrop4InUse
_bloodDrop4InUse:
	.skip 1
	.globl	_bloodDrop3InUse
_bloodDrop3InUse:
	.skip 1
	.globl	_bloodDrop2InUse
_bloodDrop2InUse:
	.skip 1
	.globl	_bloodDrop1InUse
_bloodDrop1InUse:
	.skip 1
	.globl	_bloodGlobInUse
_bloodGlobInUse:
	.skip 1
	.globl	_bloodSpray2InUse
_bloodSpray2InUse:
	.skip 1
	.globl	_bloodSpray1InUse
_bloodSpray1InUse:
	.skip 1
	.globl	_bloodPoolFrames
	.data
	.even
_bloodPoolFrames:
	.long	48
	.long	48
	.long	144
	.long	128
	.long	0
	.long	0
	.long	6
	.long	48
	.long	48
	.long	192
	.long	128
	.long	0
	.long	0
	.long	4
	.long	48
	.long	48
	.long	240
	.long	128
	.long	0
	.long	0
	.long	4
	.globl	_bloodPool10Animator
	.even
_bloodPool10Animator:
	.long	74
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool9Animator
	.even
_bloodPool9Animator:
	.long	73
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool8Animator
	.even
_bloodPool8Animator:
	.long	72
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool7Animator
	.even
_bloodPool7Animator:
	.long	71
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool6Animator
	.even
_bloodPool6Animator:
	.long	70
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool5Animator
	.even
_bloodPool5Animator:
	.long	69
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool4Animator
	.even
_bloodPool4Animator:
	.long	68
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool3Animator
	.even
_bloodPool3Animator:
	.long	67
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool2Animator
	.even
_bloodPool2Animator:
	.long	66
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool1Animator
	.even
_bloodPool1Animator:
	.long	65
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDropFrames
	.even
_bloodDropFrames:
	.long	48
	.long	48
	.long	288
	.long	128
	.long	0
	.long	0
	.long	2
	.long	48
	.long	48
	.long	336
	.long	128
	.long	0
	.long	0
	.long	2
	.long	48
	.long	48
	.long	0
	.long	176
	.long	0
	.long	0
	.long	2
	.long	48
	.long	48
	.long	48
	.long	176
	.long	0
	.long	0
	.long	2
	.long	48
	.long	48
	.long	96
	.long	176
	.long	0
	.long	0
	.long	2
	.long	48
	.long	48
	.long	144
	.long	176
	.long	0
	.long	0
	.long	2
	.long	48
	.long	48
	.long	192
	.long	176
	.long	0
	.long	0
	.long	2
	.long	48
	.long	48
	.long	240
	.long	176
	.long	0
	.long	0
	.long	2
	.globl	_bloodDrop10Animator
	.even
_bloodDrop10Animator:
	.long	64
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop9Animator
	.even
_bloodDrop9Animator:
	.long	63
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop8Animator
	.even
_bloodDrop8Animator:
	.long	62
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop7Animator
	.even
_bloodDrop7Animator:
	.long	61
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop6Animator
	.even
_bloodDrop6Animator:
	.long	60
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop5Animator
	.even
_bloodDrop5Animator:
	.long	59
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop4Animator
	.even
_bloodDrop4Animator:
	.long	58
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop3Animator
	.even
_bloodDrop3Animator:
	.long	57
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop2Animator
	.even
_bloodDrop2Animator:
	.long	56
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop1Animator
	.even
_bloodDrop1Animator:
	.long	55
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodGlobFrames
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
