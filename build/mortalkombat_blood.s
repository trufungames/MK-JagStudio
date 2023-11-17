#NO_APP
	.text
	.even
	.globl	__Z9bloodInitv
__Z9bloodInitv:
	link.w %fp,#0
	moveq #120,%d0
	move.l %d0,_bloodStayDelay
	move.b #3,%d0
	move.l %d0,_updateTicks
	clr.l _lastTicks1
	clr.l _lastTicks2
	clr.l _lastTicks3
	clr.l _lastTicks4
	clr.l _lastTicks5
	clr.l _lastTicks6
	clr.l _lastTicks7
	clr.l _lastTicks8
	clr.l _lastTicks9
	clr.l _lastTicks10
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
	.globl	__Z10bloodSprayiii
__Z10bloodSprayiii:
	link.w %fp,#0
	move.l 16(%fp),%d0
	tst.b _bloodSpray1InUse
	jne .L2
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
.L2:
	unlk %fp
	rts
	.even
	.globl	__Z9bloodGlobiii
__Z9bloodGlobiii:
	link.w %fp,#0
	move.l 16(%fp),%d0
	tst.b _bloodGlobInUse
	jne .L8
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
.L8:
	unlk %fp
	rts
	.even
	.globl	__Z9bloodDropiii
__Z9bloodDropiii:
	link.w %fp,#0
	movem.l #14368,-(%sp)
	move.l 8(%fp),%d4
	move.l 12(%fp),%d3
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
	tst.b _bloodDrop1InUse
	jne .L15
	move.b #1,_bloodDrop1InUse
	move.l %d2,_bloodDirection
	move.l sprite,%a0
	move.w %d4,12488(%a0)
	move.w %d3,12492(%a0)
	moveq #1,%d0
	cmp.l %d2,%d0
	seq %d0
	ext.w %d0
	ext.l %d0
	moveq #1,%d1
	or.l %d0,%d1
	move.l %d1,12504(%a0)
	moveq #1,%d0
	move.l %d0,12484(%a0)
	clr.l _bloodDrop1Animator+16
	move.l _bloodDropMomentumStart,_bloodDrop1Momentum
.L14:
	movem.l -16(%fp),#1052
	unlk %fp
	rts
.L15:
	tst.b _bloodDrop2InUse
	jne .L18
	move.b #1,_bloodDrop2InUse
	move.l %d2,_bloodDirection
	move.l sprite,%a0
	move.w %d4,12680(%a0)
	move.w %d3,12684(%a0)
	moveq #1,%d1
	cmp.l %d2,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,12696(%a0)
	moveq #1,%d0
	move.l %d0,12676(%a0)
	clr.l _bloodDrop2Animator+16
	movem.l -16(%fp),#1052
	unlk %fp
	rts
.L18:
	tst.b _bloodDrop3InUse
	jeq .L46
	tst.b _bloodDrop4InUse
	jne .L22
	move.b #1,_bloodDrop4InUse
	move.l %d2,_bloodDirection
	move.l sprite,%a0
	move.w %d4,13064(%a0)
	move.w %d3,13068(%a0)
	moveq #1,%d1
	cmp.l %d2,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,13080(%a0)
	moveq #1,%d0
	move.l %d0,13060(%a0)
	clr.l _bloodDrop4Animator+16
	movem.l -16(%fp),#1052
	unlk %fp
	rts
.L46:
	move.b #1,_bloodDrop3InUse
	move.l %d2,_bloodDirection
	move.l sprite,%a0
	move.w %d4,12872(%a0)
	move.w %d3,12876(%a0)
	moveq #1,%d1
	cmp.l %d2,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,12888(%a0)
	moveq #1,%d0
	move.l %d0,12868(%a0)
	clr.l _bloodDrop3Animator+16
	movem.l -16(%fp),#1052
	unlk %fp
	rts
.L22:
	tst.b _bloodDrop5InUse
	jeq .L47
	tst.b _bloodDrop6InUse
	jne .L26
	move.b #1,_bloodDrop6InUse
	move.l %d2,_bloodDirection
	move.l sprite,%a0
	move.w %d4,13448(%a0)
	move.w %d3,13452(%a0)
	moveq #1,%d1
	cmp.l %d2,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,13464(%a0)
	moveq #1,%d0
	move.l %d0,13444(%a0)
	clr.l _bloodDrop6Animator+16
	movem.l -16(%fp),#1052
	unlk %fp
	rts
.L47:
	move.b #1,_bloodDrop5InUse
	move.l %d2,_bloodDirection
	move.l sprite,%a0
	move.w %d4,13256(%a0)
	move.w %d3,13260(%a0)
	moveq #1,%d1
	cmp.l %d2,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,13272(%a0)
	moveq #1,%d0
	move.l %d0,13252(%a0)
	clr.l _bloodDrop5Animator+16
	movem.l -16(%fp),#1052
	unlk %fp
	rts
.L26:
	tst.b _bloodDrop7InUse
	jne .L28
	move.b #1,_bloodDrop7InUse
	move.l %d2,_bloodDirection
	move.l sprite,%a0
	move.w %d4,13640(%a0)
	move.w %d3,13644(%a0)
	moveq #1,%d1
	cmp.l %d2,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,13656(%a0)
	moveq #1,%d0
	move.l %d0,13636(%a0)
	clr.l _bloodDrop7Animator+16
	movem.l -16(%fp),#1052
	unlk %fp
	rts
.L28:
	tst.b _bloodDrop8InUse
	jne .L30
	move.b #1,_bloodDrop8InUse
	move.l %d2,_bloodDirection
	move.l sprite,%a0
	move.w %d4,13832(%a0)
	move.w %d3,13836(%a0)
	moveq #1,%d1
	cmp.l %d2,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,13848(%a0)
	moveq #1,%d0
	move.l %d0,13828(%a0)
	clr.l _bloodDrop8Animator+16
	movem.l -16(%fp),#1052
	unlk %fp
	rts
.L30:
	tst.b _bloodDrop9InUse
	jne .L32
	move.b #1,_bloodDrop9InUse
	move.l %d2,_bloodDirection
	move.l sprite,%a0
	move.w %d4,14024(%a0)
	move.w %d3,14028(%a0)
	moveq #1,%d1
	cmp.l %d2,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,14040(%a0)
	moveq #1,%d0
	move.l %d0,14020(%a0)
	clr.l _bloodDrop9Animator+16
	movem.l -16(%fp),#1052
	unlk %fp
	rts
.L32:
	tst.b _bloodDrop10InUse
	jne .L14
	move.b #1,_bloodDrop10InUse
	move.l %d2,_bloodDirection
	move.l sprite,%a0
	move.w %d4,14216(%a0)
	move.w %d3,14220(%a0)
	moveq #1,%d1
	cmp.l %d2,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	or.l %d0,%d1
	move.l %d1,14232(%a0)
	moveq #1,%d0
	move.l %d0,14212(%a0)
	clr.l _bloodDrop10Animator+16
	movem.l -16(%fp),#1052
	unlk %fp
	rts
	.even
	.globl	__Z9bloodPoolii
__Z9bloodPoolii:
	link.w %fp,#0
	move.l 8(%fp),%d1
	move.l 12(%fp),%d0
	tst.b _bloodPool1InUse
	jeq .L61
	tst.b _bloodPool2InUse
	jeq .L62
	tst.b _bloodPool3InUse
	jeq .L63
	tst.b _bloodPool4InUse
	jeq .L64
	tst.b _bloodPool5InUse
	jeq .L65
	tst.b _bloodPool6InUse
	jeq .L66
	tst.b _bloodPool7InUse
	jeq .L67
	tst.b _bloodPool8InUse
	jeq .L68
	tst.b _bloodPool9InUse
	jeq .L69
	tst.b _bloodPool10InUse
	jeq .L70
	unlk %fp
	rts
.L61:
	move.b #1,_bloodPool1InUse
	move.l sprite,%a0
	move.w %d1,4424(%a0)
	move.w %d0,4428(%a0)
	moveq #1,%d0
	move.l %d0,4420(%a0)
	clr.l _bloodPool1Animator+16
	pea _bloodPool1InUse
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	pea 23.w
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
	unlk %fp
	rts
.L63:
	move.b #1,_bloodPool3InUse
	move.l sprite,%a0
	move.w %d1,4808(%a0)
	move.w %d0,4812(%a0)
	moveq #1,%d0
	move.l %d0,4804(%a0)
	clr.l _bloodPool3Animator+16
	pea _bloodPool3InUse
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	pea 25.w
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
	unlk %fp
	rts
.L67:
	move.b #1,_bloodPool7InUse
	move.l sprite,%a0
	move.w %d1,5576(%a0)
	move.w %d0,5580(%a0)
	moveq #1,%d0
	move.l %d0,5572(%a0)
	clr.l _bloodPool7Animator+16
	pea _bloodPool7InUse
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	pea 29.w
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
	unlk %fp
	rts
.L62:
	move.b #1,_bloodPool2InUse
	move.l sprite,%a0
	move.w %d1,4616(%a0)
	move.w %d0,4620(%a0)
	moveq #1,%d0
	move.l %d0,4612(%a0)
	clr.l _bloodPool2Animator+16
	pea _bloodPool2InUse
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	pea 24.w
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
	unlk %fp
	rts
.L64:
	move.b #1,_bloodPool4InUse
	move.l sprite,%a0
	move.w %d1,5000(%a0)
	move.w %d0,5004(%a0)
	moveq #1,%d0
	move.l %d0,4996(%a0)
	clr.l _bloodPool4Animator+16
	pea _bloodPool4InUse
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	pea 26.w
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
	unlk %fp
	rts
.L65:
	move.b #1,_bloodPool5InUse
	move.l sprite,%a0
	move.w %d1,5192(%a0)
	move.w %d0,5196(%a0)
	moveq #1,%d0
	move.l %d0,5188(%a0)
	clr.l _bloodPool5Animator+16
	pea _bloodPool5InUse
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	pea 27.w
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
	unlk %fp
	rts
.L66:
	move.b #1,_bloodPool6InUse
	move.l sprite,%a0
	move.w %d1,5384(%a0)
	move.w %d0,5388(%a0)
	moveq #1,%d0
	move.l %d0,5380(%a0)
	clr.l _bloodPool6Animator+16
	pea _bloodPool6InUse
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	pea 28.w
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
	unlk %fp
	rts
.L70:
	move.b #1,_bloodPool10InUse
	move.l sprite,%a0
	move.w %d1,6152(%a0)
	move.w %d0,6156(%a0)
	moveq #1,%d0
	move.l %d0,6148(%a0)
	clr.l _bloodPool10Animator+16
	pea _bloodPool10InUse
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	pea 32.w
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
	unlk %fp
	rts
.L68:
	move.b #1,_bloodPool8InUse
	move.l sprite,%a0
	move.w %d1,5768(%a0)
	move.w %d0,5772(%a0)
	moveq #1,%d0
	move.l %d0,5764(%a0)
	clr.l _bloodPool8Animator+16
	pea _bloodPool8InUse
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	pea 30.w
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
	unlk %fp
	rts
.L69:
	move.b #1,_bloodPool9InUse
	move.l sprite,%a0
	move.w %d1,5960(%a0)
	move.w %d0,5964(%a0)
	moveq #1,%d0
	move.l %d0,5956(%a0)
	clr.l _bloodPool9Animator+16
	pea _bloodPool9InUse
	move.w raptor_ticks,%a0
	add.l _bloodStayDelay,%a0
	move.l %a0,-(%sp)
	pea 31.w
	jsr __Z22spriteDelaySetInactiveiiPb
	lea (12,%sp),%sp
	unlk %fp
	rts
	.even
	.globl	__Z11bloodUpdatev
__Z11bloodUpdatev:
	link.w %fp,#0
	movem.l #12344,-(%sp)
	tst.b _bloodSpray1InUse
	jne .L110
.L73:
	tst.b _bloodSpray2InUse
	jne .L111
.L76:
	tst.b _bloodGlobInUse
	jne .L112
.L77:
	tst.b _bloodDrop1InUse
	jne .L113
.L78:
	tst.b _bloodDrop2InUse
	jne .L114
.L80:
	tst.b _bloodDrop3InUse
	jne .L115
.L82:
	tst.b _bloodDrop4InUse
	jne .L116
.L84:
	tst.b _bloodDrop5InUse
	jne .L117
.L86:
	tst.b _bloodDrop6InUse
	jne .L118
.L88:
	tst.b _bloodDrop7InUse
	jne .L119
.L90:
	tst.b _bloodDrop8InUse
	jne .L120
.L92:
	tst.b _bloodDrop9InUse
	jne .L121
.L94:
	tst.b _bloodDrop10InUse
	jne .L122
.L96:
	tst.b _bloodPool1InUse
	jne .L123
.L98:
	tst.b _bloodPool2InUse
	jne .L124
.L99:
	tst.b _bloodPool3InUse
	jne .L125
.L100:
	tst.b _bloodPool4InUse
	jne .L126
.L101:
	tst.b _bloodPool5InUse
	jne .L127
.L102:
	tst.b _bloodPool6InUse
	jne .L128
.L103:
	tst.b _bloodPool7InUse
	jne .L129
.L104:
	tst.b _bloodPool8InUse
	jne .L130
.L105:
	tst.b _bloodPool9InUse
	jne .L131
.L106:
	tst.b _bloodPool10InUse
	jne .L132
.L72:
	movem.l -20(%fp),#7180
	unlk %fp
	rts
.L132:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	pea _bloodPool10Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	movem.l -20(%fp),#7180
	unlk %fp
	rts
.L131:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	pea _bloodPool9Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.b _bloodPool10InUse
	jeq .L72
	jra .L132
.L130:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	pea _bloodPool8Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.b _bloodPool9InUse
	jeq .L106
	jra .L131
.L129:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	pea _bloodPool7Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.b _bloodPool8InUse
	jeq .L105
	jra .L130
.L128:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	pea _bloodPool6Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.b _bloodPool7InUse
	jeq .L104
	jra .L129
.L127:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	pea _bloodPool5Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.b _bloodPool6InUse
	jeq .L103
	jra .L128
.L126:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	pea _bloodPool4Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.b _bloodPool5InUse
	jeq .L102
	jra .L127
.L125:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	pea _bloodPool3Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.b _bloodPool4InUse
	jeq .L101
	jra .L126
.L124:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	pea _bloodPool2Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.b _bloodPool3InUse
	jeq .L100
	jra .L125
.L123:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea _bloodPoolFrames
	pea _bloodPool1Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.b _bloodPool2InUse
	jeq .L99
	jra .L124
.L122:
	pea 1.w
	moveq #-1,%d1
	cmp.l _bloodDirection.l,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	neg.l %d0
	move.l %d0,-(%sp)
	pea 8.w
	pea _bloodDropFrames
	pea _bloodDrop10Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.w raptor_ticks,%a3
	move.l %a3,%a0
	sub.l _lastTicks10,%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jlt .L96
	move.l sprite,%a4
	move.w _bloodDirection+2,%d3
	muls.w _bloodSpeedRnd+2,%d3
	move.w 14216(%a4),%a0
	sub.w %d3,%a0
	move.w %a0,%d3
	move.w %a0,14216(%a4)
	move.l _bloodDrop10Momentum,%d2
	move.w 14220(%a4),%a0
	move.l %a0,-(%sp)
	jsr ___floatsisf
	lea ___addsf3,%a2
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a2)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.w %d0,14220(%a4)
	move.l _poolYLocation,%d1
	move.w %d0,%a0
	cmp.l %a0,%d1
	jlt .L133
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop10Momentum
	move.l %a3,_lastTicks10
.L145:
	tst.b _bloodPool1InUse
	jeq .L98
	jra .L123
.L121:
	pea 1.w
	moveq #-1,%d1
	cmp.l _bloodDirection.l,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	neg.l %d0
	move.l %d0,-(%sp)
	pea 8.w
	pea _bloodDropFrames
	pea _bloodDrop9Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.w raptor_ticks,%a3
	move.l %a3,%a0
	sub.l _lastTicks9,%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jlt .L94
	move.l sprite,%a4
	move.w _bloodDirection+2,%d3
	muls.w _bloodSpeedRnd+2,%d3
	move.w 14024(%a4),%a0
	sub.w %d3,%a0
	move.w %a0,%d3
	move.w %a0,14024(%a4)
	move.l _bloodDrop9Momentum,%d2
	move.w 14028(%a4),%a0
	move.l %a0,-(%sp)
	jsr ___floatsisf
	lea ___addsf3,%a2
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a2)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.w %d0,14028(%a4)
	move.l _poolYLocation,%d1
	move.w %d0,%a0
	cmp.l %a0,%d1
	jlt .L134
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop9Momentum
	move.l %a3,_lastTicks9
.L149:
	tst.b _bloodDrop10InUse
	jeq .L96
	jra .L122
.L120:
	pea 1.w
	moveq #-1,%d1
	cmp.l _bloodDirection.l,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	neg.l %d0
	move.l %d0,-(%sp)
	pea 8.w
	pea _bloodDropFrames
	pea _bloodDrop8Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.w raptor_ticks,%a3
	move.l %a3,%a0
	sub.l _lastTicks8,%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jlt .L92
	move.l sprite,%a4
	move.w _bloodDirection+2,%d3
	muls.w _bloodSpeedRnd+2,%d3
	move.w 13832(%a4),%a0
	sub.w %d3,%a0
	move.w %a0,%d3
	move.w %a0,13832(%a4)
	move.l _bloodDrop8Momentum,%d2
	move.w 13836(%a4),%a0
	move.l %a0,-(%sp)
	jsr ___floatsisf
	lea ___addsf3,%a2
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a2)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.w %d0,13836(%a4)
	move.l _poolYLocation,%d1
	move.w %d0,%a0
	cmp.l %a0,%d1
	jlt .L135
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop8Momentum
	move.l %a3,_lastTicks8
.L147:
	tst.b _bloodDrop9InUse
	jeq .L94
	jra .L121
.L119:
	pea 1.w
	moveq #-1,%d1
	cmp.l _bloodDirection.l,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	neg.l %d0
	move.l %d0,-(%sp)
	pea 8.w
	pea _bloodDropFrames
	pea _bloodDrop7Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.w raptor_ticks,%a3
	move.l %a3,%a0
	sub.l _lastTicks7,%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jlt .L90
	move.l sprite,%a4
	move.w _bloodDirection+2,%d3
	muls.w _bloodSpeedRnd+2,%d3
	move.w 13640(%a4),%a0
	sub.w %d3,%a0
	move.w %a0,%d3
	move.w %a0,13640(%a4)
	move.l _bloodDrop7Momentum,%d2
	move.w 13644(%a4),%a0
	move.l %a0,-(%sp)
	jsr ___floatsisf
	lea ___addsf3,%a2
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a2)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.w %d0,13644(%a4)
	move.l _poolYLocation,%d1
	move.w %d0,%a0
	cmp.l %a0,%d1
	jlt .L136
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop7Momentum
	move.l %a3,_lastTicks7
.L151:
	tst.b _bloodDrop8InUse
	jeq .L92
	jra .L120
.L118:
	pea 1.w
	moveq #-1,%d1
	cmp.l _bloodDirection.l,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	neg.l %d0
	move.l %d0,-(%sp)
	pea 8.w
	pea _bloodDropFrames
	pea _bloodDrop6Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.w raptor_ticks,%a3
	move.l %a3,%a0
	sub.l _lastTicks6,%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jlt .L88
	move.l sprite,%a4
	move.w _bloodDirection+2,%d3
	muls.w _bloodSpeedRnd+2,%d3
	move.w 13448(%a4),%a0
	sub.w %d3,%a0
	move.w %a0,%d3
	move.w %a0,13448(%a4)
	move.l _bloodDrop6Momentum,%d2
	move.w 13452(%a4),%a0
	move.l %a0,-(%sp)
	jsr ___floatsisf
	lea ___addsf3,%a2
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a2)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.w %d0,13452(%a4)
	move.l _poolYLocation,%d1
	move.w %d0,%a0
	cmp.l %a0,%d1
	jlt .L137
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop6Momentum
	move.l %a3,_lastTicks6
.L146:
	tst.b _bloodDrop7InUse
	jeq .L90
	jra .L119
.L117:
	pea 1.w
	moveq #-1,%d1
	cmp.l _bloodDirection.l,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	neg.l %d0
	move.l %d0,-(%sp)
	pea 8.w
	pea _bloodDropFrames
	pea _bloodDrop5Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.w raptor_ticks,%a3
	move.l %a3,%a0
	sub.l _lastTicks5,%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jlt .L86
	move.l sprite,%a4
	move.w _bloodDirection+2,%d3
	muls.w _bloodSpeedRnd+2,%d3
	move.w 13256(%a4),%a0
	sub.w %d3,%a0
	move.w %a0,%d3
	move.w %a0,13256(%a4)
	move.l _bloodDrop5Momentum,%d2
	move.w 13260(%a4),%a0
	move.l %a0,-(%sp)
	jsr ___floatsisf
	lea ___addsf3,%a2
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a2)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.w %d0,13260(%a4)
	move.l _poolYLocation,%d1
	move.w %d0,%a0
	cmp.l %a0,%d1
	jlt .L138
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop5Momentum
	move.l %a3,_lastTicks5
.L150:
	tst.b _bloodDrop6InUse
	jeq .L88
	jra .L118
.L116:
	pea 1.w
	moveq #-1,%d1
	cmp.l _bloodDirection.l,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	neg.l %d0
	move.l %d0,-(%sp)
	pea 8.w
	pea _bloodDropFrames
	pea _bloodDrop4Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.w raptor_ticks,%a3
	move.l %a3,%a0
	sub.l _lastTicks4,%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jlt .L84
	move.l sprite,%a4
	move.w _bloodDirection+2,%d3
	muls.w _bloodSpeedRnd+2,%d3
	move.w 13064(%a4),%a0
	sub.w %d3,%a0
	move.w %a0,%d3
	move.w %a0,13064(%a4)
	move.l _bloodDrop4Momentum,%d2
	move.w 13068(%a4),%a0
	move.l %a0,-(%sp)
	jsr ___floatsisf
	lea ___addsf3,%a2
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a2)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.w %d0,13068(%a4)
	move.l _poolYLocation,%d1
	move.w %d0,%a0
	cmp.l %a0,%d1
	jlt .L139
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop4Momentum
	move.l %a3,_lastTicks4
.L148:
	tst.b _bloodDrop5InUse
	jeq .L86
	jra .L117
.L115:
	pea 1.w
	moveq #-1,%d1
	cmp.l _bloodDirection.l,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	neg.l %d0
	move.l %d0,-(%sp)
	pea 8.w
	pea _bloodDropFrames
	pea _bloodDrop3Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.w raptor_ticks,%a3
	move.l %a3,%a0
	sub.l _lastTicks3,%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jlt .L82
	move.l sprite,%a4
	move.w _bloodDirection+2,%d3
	muls.w _bloodSpeedRnd+2,%d3
	move.w 12872(%a4),%a0
	sub.w %d3,%a0
	move.w %a0,%d3
	move.w %a0,12872(%a4)
	move.l _bloodDrop3Momentum,%d2
	move.w 12876(%a4),%a0
	move.l %a0,-(%sp)
	jsr ___floatsisf
	lea ___addsf3,%a2
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a2)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.w %d0,12876(%a4)
	move.l _poolYLocation,%d1
	move.w %d0,%a0
	cmp.l %a0,%d1
	jlt .L140
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop3Momentum
	move.l %a3,_lastTicks3
.L152:
	tst.b _bloodDrop4InUse
	jeq .L84
	jra .L116
.L114:
	pea 1.w
	moveq #-1,%d1
	cmp.l _bloodDirection.l,%d1
	seq %d0
	ext.w %d0
	ext.l %d0
	neg.l %d0
	move.l %d0,-(%sp)
	pea 8.w
	pea _bloodDropFrames
	pea _bloodDrop2Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.w raptor_ticks,%a3
	move.l %a3,%a0
	sub.l _lastTicks2,%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jlt .L80
	move.l sprite,%a4
	move.w _bloodDirection+2,%d3
	muls.w _bloodSpeedRnd+2,%d3
	move.w 12680(%a4),%a0
	sub.w %d3,%a0
	move.w %a0,%d3
	move.w %a0,12680(%a4)
	move.l _bloodDrop2Momentum,%d2
	move.w 12684(%a4),%a0
	move.l %a0,-(%sp)
	jsr ___floatsisf
	lea ___addsf3,%a2
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a2)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.w %d0,12684(%a4)
	move.l _poolYLocation,%d1
	move.w %d0,%a0
	cmp.l %a0,%d1
	jlt .L141
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop2Momentum
	move.l %a3,_lastTicks2
.L153:
	tst.b _bloodDrop3InUse
	jeq .L82
	jra .L115
.L113:
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
	sub.l _lastTicks1,%a0
	lea (20,%sp),%sp
	cmp.l _updateTicks.l,%a0
	jlt .L78
	move.l sprite,%a4
	move.w _bloodDirection+2,%d3
	muls.w _bloodSpeedRnd+2,%d3
	move.w 12488(%a4),%d1
	sub.w %d3,%d1
	move.w %d1,%d3
	move.w %d1,12488(%a4)
	move.l _bloodDrop1Momentum,%d2
	move.w 12492(%a4),%a0
	move.l %a0,-(%sp)
	jsr ___floatsisf
	lea ___addsf3,%a2
	move.l %d2,(%sp)
	move.l %d0,-(%sp)
	jsr (%a2)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr ___fixsfsi
	addq.l #4,%sp
	move.w %d0,12492(%a4)
	move.l _poolYLocation,%d1
	move.w %d0,%a0
	cmp.l %a0,%d1
	jlt .L142
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop1Momentum
	move.l %a3,_lastTicks1
.L154:
	tst.b _bloodDrop2InUse
	jeq .L80
	jra .L114
.L112:
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
	jeq .L77
	clr.b _bloodGlobInUse
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,12292(%a0)
	tst.b _bloodDrop1InUse
	jeq .L78
	jra .L113
.L111:
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
	jeq .L76
	clr.b _bloodSpray2InUse
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,12100(%a0)
	tst.b _bloodGlobInUse
	jeq .L77
	jra .L112
.L110:
	pea 1.w
	pea 1.w
	pea 5.w
	pea _bloodSprayFrames
	pea _bloodSpray1Animator
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	moveq #3,%d0
	cmp.l _bloodSpray1Animator+16.l,%d0
	jeq .L143
.L74:
	pea 5.w
	pea _bloodSpray1Animator
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L73
.L144:
	clr.b _bloodSpray1InUse
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,11908(%a0)
	tst.b _bloodSpray2InUse
	jeq .L76
	jra .L111
.L143:
	tst.b _bloodSpray2InUse
	jne .L74
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
	jeq .L73
	jra .L144
.L133:
	move.l %d1,-(%sp)
	move.w %d3,%a0
	move.l %a0,-(%sp)
	jsr __Z9bloodPoolii
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,14212(%a0)
	clr.b _bloodDrop10InUse
	move.l _bloodDrop10Momentum,%d2
	move.w raptor_ticks,%a3
	addq.l #8,%sp
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop10Momentum
	move.l %a3,_lastTicks10
	jra .L145
.L137:
	move.l %d1,-(%sp)
	move.w %d3,%a0
	move.l %a0,-(%sp)
	jsr __Z9bloodPoolii
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,13444(%a0)
	clr.b _bloodDrop6InUse
	move.l _bloodDrop6Momentum,%d2
	move.w raptor_ticks,%a3
	addq.l #8,%sp
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop6Momentum
	move.l %a3,_lastTicks6
	jra .L146
.L135:
	move.l %d1,-(%sp)
	move.w %d3,%a0
	move.l %a0,-(%sp)
	jsr __Z9bloodPoolii
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,13828(%a0)
	clr.b _bloodDrop8InUse
	move.l _bloodDrop8Momentum,%d2
	move.w raptor_ticks,%a3
	addq.l #8,%sp
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop8Momentum
	move.l %a3,_lastTicks8
	jra .L147
.L139:
	move.l %d1,-(%sp)
	move.w %d3,%a0
	move.l %a0,-(%sp)
	jsr __Z9bloodPoolii
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,13060(%a0)
	clr.b _bloodDrop4InUse
	move.l _bloodDrop4Momentum,%d2
	move.w raptor_ticks,%a3
	addq.l #8,%sp
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop4Momentum
	move.l %a3,_lastTicks4
	jra .L148
.L134:
	move.l %d1,-(%sp)
	move.w %d3,%a0
	move.l %a0,-(%sp)
	jsr __Z9bloodPoolii
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,14020(%a0)
	clr.b _bloodDrop9InUse
	move.l _bloodDrop9Momentum,%d2
	move.w raptor_ticks,%a3
	addq.l #8,%sp
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop9Momentum
	move.l %a3,_lastTicks9
	jra .L149
.L138:
	move.l %d1,-(%sp)
	move.w %d3,%a0
	move.l %a0,-(%sp)
	jsr __Z9bloodPoolii
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,13252(%a0)
	clr.b _bloodDrop5InUse
	move.l _bloodDrop5Momentum,%d2
	move.w raptor_ticks,%a3
	addq.l #8,%sp
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop5Momentum
	move.l %a3,_lastTicks5
	jra .L150
.L136:
	move.l %d1,-(%sp)
	move.w %d3,%a0
	move.l %a0,-(%sp)
	jsr __Z9bloodPoolii
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,13636(%a0)
	clr.b _bloodDrop7InUse
	move.l _bloodDrop7Momentum,%d2
	move.w raptor_ticks,%a3
	addq.l #8,%sp
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop7Momentum
	move.l %a3,_lastTicks7
	jra .L151
.L140:
	move.l %d1,-(%sp)
	move.w %d3,%a0
	move.l %a0,-(%sp)
	jsr __Z9bloodPoolii
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,12868(%a0)
	clr.b _bloodDrop3InUse
	move.l _bloodDrop3Momentum,%d2
	move.w raptor_ticks,%a3
	addq.l #8,%sp
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop3Momentum
	move.l %a3,_lastTicks3
	jra .L152
.L141:
	move.l %d1,-(%sp)
	move.w %d3,%a0
	move.l %a0,-(%sp)
	jsr __Z9bloodPoolii
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,12676(%a0)
	clr.b _bloodDrop2InUse
	move.l _bloodDrop2Momentum,%d2
	move.w raptor_ticks,%a3
	addq.l #8,%sp
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop2Momentum
	move.l %a3,_lastTicks2
	jra .L153
.L142:
	move.l %d1,-(%sp)
	move.w %d3,%a0
	move.l %a0,-(%sp)
	jsr __Z9bloodPoolii
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,12484(%a0)
	clr.b _bloodDrop1InUse
	move.l _bloodDrop1Momentum,%d2
	move.w raptor_ticks,%a3
	addq.l #8,%sp
	move.l _gravity,-(%sp)
	move.l %d2,-(%sp)
	jsr (%a2)
	addq.l #8,%sp
	move.l %d0,_bloodDrop1Momentum
	move.l %a3,_lastTicks1
	jra .L154
	.globl	_bloodSpeedRnd
	.bss
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
	.globl	_bloodDrop10Momentum
	.even
_bloodDrop10Momentum:
	.skip 4
	.globl	_bloodDrop9Momentum
	.even
_bloodDrop9Momentum:
	.skip 4
	.globl	_bloodDrop8Momentum
	.even
_bloodDrop8Momentum:
	.skip 4
	.globl	_bloodDrop7Momentum
	.even
_bloodDrop7Momentum:
	.skip 4
	.globl	_bloodDrop6Momentum
	.even
_bloodDrop6Momentum:
	.skip 4
	.globl	_bloodDrop5Momentum
	.even
_bloodDrop5Momentum:
	.skip 4
	.globl	_bloodDrop4Momentum
	.even
_bloodDrop4Momentum:
	.skip 4
	.globl	_bloodDrop3Momentum
	.even
_bloodDrop3Momentum:
	.skip 4
	.globl	_bloodDrop2Momentum
	.even
_bloodDrop2Momentum:
	.skip 4
	.globl	_bloodDrop1Momentum
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
	.globl	_lastTicks10
	.even
_lastTicks10:
	.skip 4
	.globl	_lastTicks9
	.even
_lastTicks9:
	.skip 4
	.globl	_lastTicks8
	.even
_lastTicks8:
	.skip 4
	.globl	_lastTicks7
	.even
_lastTicks7:
	.skip 4
	.globl	_lastTicks6
	.even
_lastTicks6:
	.skip 4
	.globl	_lastTicks5
	.even
_lastTicks5:
	.skip 4
	.globl	_lastTicks4
	.even
_lastTicks4:
	.skip 4
	.globl	_lastTicks3
	.even
_lastTicks3:
	.skip 4
	.globl	_lastTicks2
	.even
_lastTicks2:
	.skip 4
	.globl	_lastTicks1
	.even
_lastTicks1:
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
