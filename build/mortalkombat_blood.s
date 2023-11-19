#NO_APP
	.text
	.even
	.globl	__Z9bloodInitv
__Z9bloodInitv:
	link.w %fp,#0
	moveq #10,%d0
	move.l %d0,_bloodDropCount
	move.b #120,%d0
	move.l %d0,_bloodStayDelay
	move.b #3,%d0
	move.l %d0,_updateTicks
	move.l #0x40e00000,_bloodSpeed
	move.l #0x40800000,_gravity
	move.l #0xc1a00000,_bloodDropMomentumStart
	clr.b _bloodSpray1InUse
	clr.b _bloodSpray2InUse
	clr.b _bloodGlobInUse
	move.b #1,%d0
	move.l %d0,_bloodDirection
	unlk %fp
	rts
	.even
	.globl	__Z11bloodUpdatev
__Z11bloodUpdatev:
	link.w %fp,#-12
	movem.l #16188,-(%sp)
	tst.b _bloodSpray1InUse
	jne .L28
.L3:
	tst.b _bloodSpray2InUse
	jne .L29
.L6:
	tst.b _bloodGlobInUse
	jne .L30
.L7:
	move.l _bloodDropCount,%d2
	jle .L2
	lea _bloodDrops+8,%a2
	move.l #_bloodDrops,%d4
	lea _bloodDrops+18,%a3
	lea _bloodDrops+10,%a5
	lea _bloodDrops+14,%a4
	moveq #0,%d3
	move.l #__Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb,%d7
.L18:
	tst.b (%a2)
	jne .L31
	addq.l #1,%d3
	lea (22,%a2),%a2
	moveq #22,%d1
	add.l %d1,%d4
	lea (22,%a3),%a3
	lea (22,%a5),%a5
	lea (22,%a4),%a4
	cmp.l %d3,%d2
	jgt .L18
.L33:
	tst.l %d2
	jle .L2
	lea _bloodPools+8,%a2
	moveq #0,%d3
	lea __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb,%a3
.L20:
	tst.b (%a2)
	jne .L32
	addq.l #1,%d3
	lea (10,%a2),%a2
	cmp.l %d2,%d3
	jlt .L20
.L2:
	movem.l -52(%fp),#15612
	unlk %fp
	rts
.L31:
	pea 1.w
	moveq #-1,%d0
	cmp.l (%a4),%d0
	seq %d0
	ext.w %d0
	ext.l %d0
	neg.l %d0
	move.l %d0,-(%sp)
	pea 8.w
	pea _bloodDropFrames
	move.l -14(%a3),-(%sp)
	move.l %d7,%a0
	jsr (%a0)
	move.w raptor_ticks,%d5
	ext.l %d5
	move.l %d5,%a0
	sub.l (%a5),%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jge .L10
	move.l _bloodDropCount,%d2
	addq.l #1,%d3
	lea (22,%a2),%a2
	moveq #22,%d1
	add.l %d1,%d4
	lea (22,%a3),%a3
	lea (22,%a5),%a5
	lea (22,%a4),%a4
	cmp.l %d3,%d2
	jgt .L18
	jra .L33
.L32:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	move.l -4(%a2),-(%sp)
	jsr (%a3)
	move.l _bloodDropCount,%d2
	lea (20,%sp),%sp
	addq.l #1,%d3
	lea (10,%a2),%a2
	cmp.l %d2,%d3
	jlt .L20
	jra .L2
.L10:
	move.l sprite,-4(%fp)
	move.l %d4,%a1
	move.l (%a1),%d0
	move.l %d0,%a0
	add.l %d0,%a0
	add.l %a0,%d0
	lsl.l #6,%d0
	move.l -4(%fp),%a0
	add.l %d0,%a0
	move.w 2(%a4),%d0
	muls.w _bloodSpeedRnd+2,%d0
	move.w 8(%a0),%d1
	sub.w %d0,%d1
	move.w %d1,-6(%fp)
	move.w %d1,8(%a0)
	move.l (%a3),%d6
	move.w 12(%a0),%a1
	move.l %a1,-(%sp)
	move.l %a0,-10(%fp)
	jsr ___floatsisf
	move.l %d0,(%sp)
	move.l %d6,-(%sp)
	jsr ___addsf3
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.l -10(%fp),%a0
	move.w %d0,12(%a0)
	move.l _poolYLocation,%d1
	move.w %d0,%a1
	move.l _bloodDropCount,%d2
	cmp.l %a1,%d1
	jlt .L11
	move.l _gravity,-(%sp)
	move.l %d6,-(%sp)
	jsr ___addsf3
	addq.l #8,%sp
	move.l %d0,(%a3)
	move.l %d5,(%a5)
.L35:
	addq.l #1,%d3
	lea (22,%a2),%a2
	moveq #22,%d1
	add.l %d1,%d4
	lea (22,%a3),%a3
	lea (22,%a5),%a5
	lea (22,%a4),%a4
	cmp.l %d3,%d2
	jgt .L18
	jra .L33
.L11:
	tst.l %d2
	jle .L13
	tst.b _bloodPools+8
	jeq .L34
	lea _bloodPools+18,%a1
	moveq #0,%d0
.L16:
	addq.l #1,%d0
	cmp.l %d0,%d2
	jeq .L13
	lea (10,%a1),%a1
	tst.b -10(%a1)
	jne .L16
	move.l %d0,%a0
	add.l %d0,%a0
	add.l %a0,%a0
	add.l %a0,%d0
	add.l %d0,%d0
	lea _bloodPools+8,%a0
	move.b #1,(%a0,%d0.l)
	lea _bloodPools,%a0
	move.l (%a0,%d0.l),%a0
	move.l %a0,%d2
	add.l %a0,%d2
	add.l %a0,%d2
	lsl.l #6,%d2
	move.l -4(%fp),%a1
	add.l %d2,%a1
	move.w -6(%fp),8(%a1)
	move.w %d1,12(%a1)
	moveq #1,%d1
	move.l %d1,4(%a1)
	move.l %d0,%a1
	add.l #_bloodPools+4,%a1
	move.l (%a1),%a1
	clr.l 16(%a1)
	add.l #_bloodPools+8,%d0
	move.l %d0,-(%sp)
	add.l _bloodStayDelay,%d5
	move.l %d5,-(%sp)
	move.l %a0,-(%sp)
	jsr __Z22spriteDelaySetInactiveiiPb
	move.l %d4,%a0
	move.l (%a0),%d0
	move.l %d0,%a0
	add.l %d0,%a0
	add.l %a0,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	add.l %d0,%a0
	move.w raptor_ticks,%d5
	ext.l %d5
	move.l _bloodDropCount,%d2
	lea (12,%sp),%sp
.L13:
	moveq #-1,%d0
	move.l %d0,4(%a0)
	clr.b (%a2)
	move.l (%a3),%d6
	move.l _gravity,-(%sp)
	move.l %d6,-(%sp)
	jsr ___addsf3
	addq.l #8,%sp
	move.l %d0,(%a3)
	move.l %d5,(%a5)
	jra .L35
.L30:
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
	move.l %d1,12292(%a0)
	jra .L7
.L29:
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
	move.l %d0,12100(%a0)
	tst.b _bloodGlobInUse
	jeq .L7
	jra .L30
.L28:
	pea 1.w
	pea 1.w
	pea 5.w
	pea _bloodSprayFrames
	pea _bloodSpray1Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	moveq #3,%d0
	cmp.l _bloodSpray1Animator+16.l,%d0
	jeq .L36
.L4:
	pea 5.w
	pea _bloodSpray1Animator
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L3
.L37:
	clr.b _bloodSpray1InUse
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,11908(%a0)
	tst.b _bloodSpray2InUse
	jeq .L6
	jra .L29
.L36:
	tst.b _bloodSpray2InUse
	jne .L4
	move.b #1,_bloodSpray2InUse
	move.l sprite,%a0
	move.l _bloodDirection,%d1
	move.w %d1,%d0
	move.w %d1,%d2
	muls.w #-12,%d2
	add.w 11912(%a0),%d2
	move.w %d2,12104(%a0)
	neg.w %d0
	add.w %d0,%d0
	add.w %d0,%d0
	add.w 11916(%a0),%d0
	move.w %d0,12108(%a0)
	moveq #1,%d0
	cmp.l %d1,%d0
	seq %d0
	ext.w %d0
	ext.l %d0
	moveq #1,%d1
	or.l %d0,%d1
	move.l %d1,12120(%a0)
	moveq #1,%d0
	move.l %d0,12100(%a0)
	clr.l _bloodSpray2Animator+16
	pea 5.w
	pea _bloodSpray1Animator
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L3
	jra .L37
.L34:
	moveq #0,%d0
	move.l %d0,%a0
	add.l %d0,%a0
	add.l %a0,%a0
	add.l %a0,%d0
	add.l %d0,%d0
	lea _bloodPools+8,%a0
	move.b #1,(%a0,%d0.l)
	lea _bloodPools,%a0
	move.l (%a0,%d0.l),%a0
	move.l %a0,%d2
	add.l %a0,%d2
	add.l %a0,%d2
	lsl.l #6,%d2
	move.l -4(%fp),%a1
	add.l %d2,%a1
	move.w -6(%fp),8(%a1)
	move.w %d1,12(%a1)
	moveq #1,%d1
	move.l %d1,4(%a1)
	move.l %d0,%a1
	add.l #_bloodPools+4,%a1
	move.l (%a1),%a1
	clr.l 16(%a1)
	add.l #_bloodPools+8,%d0
	move.l %d0,-(%sp)
	add.l _bloodStayDelay,%d5
	move.l %d5,-(%sp)
	move.l %a0,-(%sp)
	jsr __Z22spriteDelaySetInactiveiiPb
	move.l %d4,%a0
	move.l (%a0),%d0
	move.l %d0,%a0
	add.l %d0,%a0
	add.l %a0,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	add.l %d0,%a0
	move.w raptor_ticks,%d5
	ext.l %d5
	move.l _bloodDropCount,%d2
	lea (12,%sp),%sp
	jra .L13
	.even
	.globl	__Z10bloodSprayiii
__Z10bloodSprayiii:
	link.w %fp,#0
	move.l 16(%fp),%d0
	tst.b _bloodSpray1InUse
	jne .L39
	move.b #1,_bloodSpray1InUse
	move.l %d0,_bloodDirection
	move.l sprite,%a0
	move.w 10(%fp),11912(%a0)
	move.w 14(%fp),11916(%a0)
	moveq #1,%d1
	cmp.l %d0,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,11928(%a0)
	moveq #1,%d0
	move.l %d0,11908(%a0)
	clr.l _bloodSpray1Animator+16
.L39:
	unlk %fp
	rts
	.even
	.globl	__Z9bloodGlobiii
__Z9bloodGlobiii:
	link.w %fp,#0
	move.l 16(%fp),%d0
	tst.b _bloodGlobInUse
	jne .L45
	move.b #1,_bloodGlobInUse
	move.l %d0,_bloodDirection
	move.l sprite,%a0
	move.w 10(%fp),12296(%a0)
	move.w 14(%fp),12300(%a0)
	moveq #1,%d1
	cmp.l %d0,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,12312(%a0)
	moveq #1,%d0
	move.l %d0,12292(%a0)
	clr.l _bloodGlobAnimator+16
.L45:
	unlk %fp
	rts
	.even
	.globl	__Z9bloodDropiii
__Z9bloodDropiii:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	move.l 16(%fp),%d2
	lea RAPTOR_random,%a2
	jsr (%a2)
	moveq #8,%d1
	and.l %d1,%d0
	add.l #186,%d0
	move.l %d0,_poolYLocation
	jsr (%a2)
	jsr (%a2)
	move.l _bloodSpeed,-(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.l %d0,_bloodSpeedRnd
	move.l _bloodDropCount,%d1
	jle .L51
	tst.b _bloodDrops+8
	jeq .L63
	lea _bloodDrops+30,%a0
	moveq #0,%d0
.L55:
	addq.l #1,%d0
	cmp.l %d0,%d1
	jeq .L51
	lea (22,%a0),%a0
	tst.b -22(%a0)
	jne .L55
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d1
	add.l %d1,%d1
	sub.l %d0,%d1
	move.l %d1,%a0
	add.l %d1,%a0
	lea _bloodDrops+8,%a1
	move.b #1,(%a0,%a1.l)
	move.l %a0,%a1
	add.l #_bloodDrops,%a1
	move.l %d2,14(%a1)
	lea _bloodDrops,%a2
	move.l (%a2,%a0.l),%d0
	move.l %d0,%a0
	add.l %d0,%a0
	add.l %a0,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	add.l %d0,%a0
	move.w 10(%fp),8(%a0)
	move.w 14(%fp),12(%a0)
	moveq #1,%d0
	cmp.l %d2,%d0
	seq %d0
	ext.w %d0
	ext.l %d0
	moveq #1,%d1
	or.l %d0,%d1
	move.l %d1,24(%a0)
	moveq #1,%d0
	move.l %d0,4(%a0)
	move.l 4(%a1),%a0
	clr.l 16(%a0)
	move.l _bloodDropMomentumStart,18(%a1)
.L51:
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
.L63:
	moveq #0,%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d1
	add.l %d1,%d1
	sub.l %d0,%d1
	move.l %d1,%a0
	add.l %d1,%a0
	lea _bloodDrops+8,%a1
	move.b #1,(%a0,%a1.l)
	move.l %a0,%a1
	add.l #_bloodDrops,%a1
	move.l %d2,14(%a1)
	lea _bloodDrops,%a2
	move.l (%a2,%a0.l),%d0
	move.l %d0,%a0
	add.l %d0,%a0
	add.l %a0,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	add.l %d0,%a0
	move.w 10(%fp),8(%a0)
	move.w 14(%fp),12(%a0)
	moveq #1,%d0
	cmp.l %d2,%d0
	seq %d0
	ext.w %d0
	ext.l %d0
	moveq #1,%d1
	or.l %d0,%d1
	move.l %d1,24(%a0)
	moveq #1,%d0
	move.l %d0,4(%a0)
	move.l 4(%a1),%a0
	clr.l 16(%a0)
	move.l _bloodDropMomentumStart,18(%a1)
	jra .L51
	.even
	.globl	__Z9bloodPoolii
__Z9bloodPoolii:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.l _bloodDropCount,%d1
	jle .L65
	tst.b _bloodPools+8
	jeq .L75
	lea _bloodPools+18,%a0
	moveq #0,%d0
.L69:
	addq.l #1,%d0
	cmp.l %d0,%d1
	jeq .L65
	lea (10,%a0),%a0
	tst.b -10(%a0)
	jne .L69
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d1
	add.l %d1,%d0
	add.l %d0,%d0
	lea _bloodPools+8,%a0
	move.b #1,(%a0,%d0.l)
	lea _bloodPools,%a0
	move.l (%a0,%d0.l),%d1
	move.l %d1,%d2
	add.l %d1,%d2
	add.l %d1,%d2
	lsl.l #6,%d2
	move.l sprite,%a0
	add.l %d2,%a0
	move.w 10(%fp),8(%a0)
	move.w 14(%fp),12(%a0)
	moveq #1,%d2
	move.l %d2,4(%a0)
	move.l %d0,%a0
	add.l #_bloodPools+4,%a0
	move.l (%a0),%a0
	clr.l 16(%a0)
	add.l #_bloodPools+8,%d0
	move.l %d0,-(%sp)
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
.L65:
	move.l -4(%fp),%d2
	unlk %fp
	rts
.L75:
	moveq #0,%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d1
	add.l %d1,%d0
	add.l %d0,%d0
	lea _bloodPools+8,%a0
	move.b #1,(%a0,%d0.l)
	lea _bloodPools,%a0
	move.l (%a0,%d0.l),%d1
	move.l %d1,%d2
	add.l %d1,%d2
	add.l %d1,%d2
	lsl.l #6,%d2
	move.l sprite,%a0
	add.l %d2,%a0
	move.w 10(%fp),8(%a0)
	move.w 14(%fp),12(%a0)
	moveq #1,%d2
	move.l %d2,4(%a0)
	move.l %d0,%a0
	add.l #_bloodPools+4,%a0
	move.l (%a0),%a0
	clr.l 16(%a0)
	add.l #_bloodPools+8,%d0
	move.l %d0,-(%sp)
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
	jra .L65
	.globl	_bloodDropCount
	.bss
	.even
_bloodDropCount:
	.skip 4
	.globl	_bloodSpeedRnd
	.even
_bloodSpeedRnd:
	.skip 4
	.globl	_poolYLocation
	.even
_poolYLocation:
	.skip 4
	.globl	_bloodStayDelay
	.even
_bloodStayDelay:
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
	.globl	_updateTicks
	.even
_updateTicks:
	.skip 4
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
	.globl	_bloodPools
	.data
	.even
_bloodPools:
	.long	23
	.long	_bloodPool1Animator
	.byte	0
	.skip 1
	.long	23
	.long	_bloodPool2Animator
	.byte	0
	.skip 1
	.long	23
	.long	_bloodPool3Animator
	.byte	0
	.skip 1
	.long	23
	.long	_bloodPool4Animator
	.byte	0
	.skip 1
	.long	23
	.long	_bloodPool5Animator
	.byte	0
	.skip 1
	.long	23
	.long	_bloodPool6Animator
	.byte	0
	.skip 1
	.long	23
	.long	_bloodPool7Animator
	.byte	0
	.skip 1
	.long	23
	.long	_bloodPool8Animator
	.byte	0
	.skip 1
	.long	23
	.long	_bloodPool9Animator
	.byte	0
	.skip 1
	.long	23
	.long	_bloodPool10Animator
	.byte	0
	.skip 1
	.globl	_bloodDrops
	.even
_bloodDrops:
	.long	65
	.long	_bloodDrop1Animator
	.byte	0
	.skip 1
	.long	0
	.long	0
	.long	0
	.long	66
	.long	_bloodDrop2Animator
	.byte	0
	.skip 1
	.long	0
	.long	0
	.long	0
	.long	67
	.long	_bloodDrop3Animator
	.byte	0
	.skip 1
	.long	0
	.long	0
	.long	0
	.long	68
	.long	_bloodDrop4Animator
	.byte	0
	.skip 1
	.long	0
	.long	0
	.long	0
	.long	69
	.long	_bloodDrop5Animator
	.byte	0
	.skip 1
	.long	0
	.long	0
	.long	0
	.long	70
	.long	_bloodDrop6Animator
	.byte	0
	.skip 1
	.long	0
	.long	0
	.long	0
	.long	71
	.long	_bloodDrop7Animator
	.byte	0
	.skip 1
	.long	0
	.long	0
	.long	0
	.long	72
	.long	_bloodDrop8Animator
	.byte	0
	.skip 1
	.long	0
	.long	0
	.long	0
	.long	73
	.long	_bloodDrop9Animator
	.byte	0
	.skip 1
	.long	0
	.long	0
	.long	0
	.long	74
	.long	_bloodDrop10Animator
	.byte	0
	.skip 1
	.long	0
	.long	0
	.long	0
	.globl	_bloodPoolFrames
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
	.long	32
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool9Animator
	.even
_bloodPool9Animator:
	.long	31
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool8Animator
	.even
_bloodPool8Animator:
	.long	30
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool7Animator
	.even
_bloodPool7Animator:
	.long	29
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool6Animator
	.even
_bloodPool6Animator:
	.long	28
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool5Animator
	.even
_bloodPool5Animator:
	.long	27
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool4Animator
	.even
_bloodPool4Animator:
	.long	26
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool3Animator
	.even
_bloodPool3Animator:
	.long	25
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool2Animator
	.even
_bloodPool2Animator:
	.long	24
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodPool1Animator
	.even
_bloodPool1Animator:
	.long	23
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
	.long	1
	.long	48
	.long	48
	.long	336
	.long	128
	.long	0
	.long	0
	.long	1
	.long	48
	.long	48
	.long	0
	.long	176
	.long	0
	.long	0
	.long	1
	.long	48
	.long	48
	.long	48
	.long	176
	.long	0
	.long	0
	.long	1
	.long	48
	.long	48
	.long	96
	.long	176
	.long	0
	.long	0
	.long	1
	.long	48
	.long	48
	.long	144
	.long	176
	.long	0
	.long	0
	.long	1
	.long	48
	.long	48
	.long	192
	.long	176
	.long	0
	.long	0
	.long	1
	.long	48
	.long	48
	.long	240
	.long	176
	.long	0
	.long	0
	.long	1
	.globl	_bloodDrop10Animator
	.even
_bloodDrop10Animator:
	.long	74
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop9Animator
	.even
_bloodDrop9Animator:
	.long	73
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop8Animator
	.even
_bloodDrop8Animator:
	.long	72
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop7Animator
	.even
_bloodDrop7Animator:
	.long	71
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop6Animator
	.even
_bloodDrop6Animator:
	.long	70
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop5Animator
	.even
_bloodDrop5Animator:
	.long	69
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop4Animator
	.even
_bloodDrop4Animator:
	.long	68
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop3Animator
	.even
_bloodDrop3Animator:
	.long	67
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop2Animator
	.even
_bloodDrop2Animator:
	.long	66
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodDrop1Animator
	.even
_bloodDrop1Animator:
	.long	65
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
	.long	64
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
	.long	63
	.long	1056964608
	.long	12294080
	.long	0
	.long	0
	.skip 4
	.globl	_bloodSpray1Animator
	.even
_bloodSpray1Animator:
	.long	62
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
