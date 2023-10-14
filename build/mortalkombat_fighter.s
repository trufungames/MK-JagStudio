#NO_APP
	.text
	.even
	.globl	__Z11fighterHideP7Fighter
__Z11fighterHideP7Fighter:
	link.w %fp,#0
	unlk %fp
	rts
	.even
	.globl	__Z17fighterInitializeP7Fighterb
__Z17fighterInitializeP7Fighterb:
	link.w %fp,#0
	move.l 8(%fp),%a0
	clr.l 44(%a0)
	moveq #4,%d0
	move.l %d0,52(%a0)
	move.l %d0,56(%a0)
	clr.b 28(%a0)
	clr.b 29(%a0)
	clr.b 30(%a0)
	move.l (%a0),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a1
	moveq #1,%d1
	move.l %d1,4(%a1,%d0.l)
	tst.b 15(%fp)
	jne .L6
	moveq #19,%d0
	move.l %d0,40(%a0)
	moveq #17,%d1
	move.l %d1,32(%a0)
	move.b #18,%d0
	move.l %d0,36(%a0)
	move.b #2,%d1
	move.l %d1,48(%a0)
	unlk %fp
	rts
.L6:
	moveq #16,%d0
	move.l %d0,40(%a0)
	move.b #14,%d1
	move.l %d1,32(%a0)
	move.b #15,%d0
	move.l %d0,36(%a0)
	move.b #1,%d1
	move.l %d1,48(%a0)
	unlk %fp
	rts
	.even
	.globl	__Z13fighterUpdateP7FighterP14SpriteAnimatorP14AnimationFrameS4_S4_S4_S4_
__Z13fighterUpdateP7FighterP14SpriteAnimatorP14AnimationFrameS4_S4_S4_S4_:
	link.w %fp,#0
	movem.l #15920,-(%sp)
	move.l 8(%fp),%a2
	move.l 12(%fp),%a3
	move.l 16(%fp),%d6
	move.l 20(%fp),%d4
	move.l 24(%fp),%d5
	move.l 28(%fp),%d2
	move.l 32(%fp),%d3
	move.l 48(%a2),-(%sp)
	jsr jsfGetPad
	move.l %d0,44(%a2)
	move.l %d0,%d1
	and.l JAGPAD_B,%d1
	addq.l #4,%sp
	jeq .L9
	tst.b 30(%a2)
	jne .L10
	move.b #1,30(%a2)
	clr.l 16(%a3)
.L10:
	and.l JAGPAD_DOWN,%d0
	jeq .L11
	tst.b 29(%a2)
	jne .L12
	move.b #1,29(%a2)
	clr.l 16(%a3)
.L12:
	clr.l 24(%fp)
	moveq #1,%d0
	move.l %d0,20(%fp)
	move.l 24(%a2),16(%fp)
	move.l %d3,12(%fp)
	move.l %a3,8(%fp)
	movem.l -28(%fp),#3196
	unlk %fp
	jra __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
.L9:
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jne .L25
	move.l %d0,%d1
	and.l JAGPAD_RIGHT,%d1
	jne .L26
	and.l JAGPAD_DOWN,%d0
	jne .L27
	tst.b 29(%a2)
	jne .L28
	tst.b 30(%a2)
	jne .L29
	tst.b 28(%a2)
	jeq .L23
	clr.b 28(%a2)
	clr.l 16(%a3)
.L23:
	moveq #1,%d0
	move.l %d0,24(%fp)
	move.l %d0,20(%fp)
	move.l 8(%a2),16(%fp)
	move.l %d6,12(%fp)
	move.l %a3,8(%fp)
	movem.l -28(%fp),#3196
	unlk %fp
	jra __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
.L11:
	tst.b 29(%a2)
	jeq .L13
	clr.b 29(%a2)
.L13:
	clr.l 24(%fp)
	moveq #1,%d1
	move.l %d1,20(%fp)
	move.l 20(%a2),16(%fp)
	move.l %d2,12(%fp)
	move.l %a3,8(%fp)
	movem.l -28(%fp),#3196
	unlk %fp
	jra __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
.L25:
	pea 1.w
	pea 1.w
	move.l 12(%a2),-(%sp)
	move.l %d4,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.b #1,28(%a2)
	clr.b 29(%a2)
	clr.b 30(%a2)
	move.l sprite,%a0
	move.l (%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	lea (%a0,%d0.l),%a1
	move.w 8(%a1),%d0
	lea (20,%sp),%sp
	jle .L15
	move.w 58(%a2),%d1
	sub.w %d1,%d0
	move.w %d0,8(%a1)
	move.l 32(%a2),%d0
	move.l %d0,%a1
	add.l %d0,%a1
	add.l %a1,%d0
	lsl.l #6,%d0
	sub.w %d1,8(%a0,%d0.l)
	move.l 36(%a2),%d0
	move.l %d0,%a1
	add.l %d0,%a1
	add.l %a1,%d0
	lsl.l #6,%d0
	sub.w %d1,8(%a0,%d0.l)
	move.l 40(%a2),%d0
	move.l %d0,%a1
	add.l %d0,%a1
	add.l %a1,%d0
	lsl.l #6,%d0
	sub.w %d1,8(%a0,%d0.l)
.L8:
	movem.l -28(%fp),#3196
	unlk %fp
	rts
.L27:
	tst.b 29(%a2)
	jne .L20
	move.b #1,29(%a2)
	clr.l 16(%a3)
.L20:
	clr.l -(%sp)
	pea 1.w
	move.l 16(%a2),-(%sp)
	move.l %d5,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.l 32(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,4(%a0,%d0.l)
	lea (20,%sp),%sp
	movem.l -28(%fp),#3196
	unlk %fp
	rts
.L26:
	pea 1.w
	clr.l -(%sp)
	move.l 12(%a2),-(%sp)
	move.l %d4,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.b #1,28(%a2)
	clr.b 29(%a2)
	clr.b 30(%a2)
	move.l sprite,%a0
	move.l (%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	lea (%a0,%d0.l),%a1
	move.w 8(%a1),%d0
	lea (20,%sp),%sp
	cmp.w #259,%d0
	jgt .L18
	move.w 54(%a2),%d1
	add.w %d1,%d0
	move.w %d0,8(%a1)
	move.l 32(%a2),%d0
	move.l %d0,%a1
	add.l %d0,%a1
	add.l %a1,%d0
	lsl.l #6,%d0
	add.w %d1,8(%a0,%d0.l)
	move.l 36(%a2),%d0
	move.l %d0,%a1
	add.l %d0,%a1
	add.l %a1,%d0
	lsl.l #6,%d0
	add.w %d1,8(%a0,%d0.l)
	move.l 40(%a2),%d0
	move.l %d0,%a1
	add.l %d0,%a1
	add.l %a1,%d0
	lsl.l #6,%d0
	add.w %d1,8(%a0,%d0.l)
	movem.l -28(%fp),#3196
	unlk %fp
	rts
.L28:
	clr.l -(%sp)
	clr.l -(%sp)
	move.l 16(%a2),-(%sp)
	move.l %d5,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.l 16(%a3)
	jne .L8
	clr.b 29(%a2)
	move.l sprite,%a0
	move.l 36(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	moveq #1,%d1
	cmp.l 4(%a0,%d0.l),%d1
	jne .L8
	move.l 32(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	moveq #1,%d1
	move.l %d1,4(%a0,%d0.l)
	movem.l -28(%fp),#3196
	unlk %fp
	rts
.L18:
	movem.l -28(%fp),#3196
	unlk %fp
	jra __Z13bgScrollRightv
.L29:
	clr.l -(%sp)
	clr.l -(%sp)
	move.l 20(%a2),-(%sp)
	move.l %d2,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.l 16(%a3)
	jne .L8
	clr.b 30(%a2)
	movem.l -28(%fp),#3196
	unlk %fp
	rts
.L15:
	movem.l -28(%fp),#3196
	unlk %fp
	jra __Z12bgScrollLeftv
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
