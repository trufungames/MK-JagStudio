#NO_APP
	.text
	.even
	.globl	__Z11fighterHideP7Fighter
__Z11fighterHideP7Fighter:
	link.w %fp,#0
	move.l 8(%fp),%a0
	move.l (%a0),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,4(%a0,%d0.l)
	unlk %fp
	rts
	.even
	.globl	__Z11fighterShowP7Fighter
__Z11fighterShowP7Fighter:
	link.w %fp,#0
	move.l 8(%fp),%a0
	move.l (%a0),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	moveq #1,%d1
	move.l %d1,4(%a0,%d0.l)
	unlk %fp
	rts
	.even
	.globl	__Z21fighterMakeSelectableP7Fighterb
__Z21fighterMakeSelectableP7Fighterb:
	link.w %fp,#0
	move.l 8(%fp),%a0
	move.l (%a0),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	tst.b 15(%fp)
	jne .L8
	add.l %d0,%d1
	lsl.l #6,%d1
	move.l sprite,%a0
	add.l %d1,%a0
	move.w #243,8(%a0)
	moveq #26,%d1
	cmp.l %d0,%d1
	jeq .L9
	moveq #-1,%d0
	move.l %d0,24(%a0)
.L3:
	unlk %fp
	rts
.L8:
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	add.l %d0,%a0
	move.w #4,8(%a0)
	moveq #1,%d0
	move.l %d0,24(%a0)
	unlk %fp
	rts
.L9:
	move.w #227,8(%a0)
	moveq #-1,%d0
	move.l %d0,24(%a0)
	jra .L3
	.even
	.globl	__Z17fighterInitializeP7Fighterb
__Z17fighterInitializeP7Fighterb:
	link.w %fp,#0
	move.l 8(%fp),%a0
	clr.l 44(%a0)
	move.l #4000,52(%a0)
	move.l #4000,56(%a0)
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
	jne .L15
	moveq #38,%d0
	move.l %d0,40(%a0)
	moveq #36,%d1
	move.l %d1,32(%a0)
	move.b #37,%d0
	move.l %d0,36(%a0)
	move.b #2,%d1
	move.l %d1,48(%a0)
	unlk %fp
	rts
.L15:
	moveq #35,%d0
	move.l %d0,40(%a0)
	move.b #33,%d1
	move.l %d1,32(%a0)
	move.b #34,%d0
	move.l %d0,36(%a0)
	move.b #1,%d1
	move.l %d1,48(%a0)
	unlk %fp
	rts
	.even
	.globl	__Z17fighterUpdateIdlefP7FighterP14SpriteAnimatorP14AnimationFrame
__Z17fighterUpdateIdlefP7FighterP14SpriteAnimatorP14AnimationFrame:
	link.w %fp,#0
	pea 1.w
	pea 1.w
	move.l 12(%fp),%a0
	move.l 8(%a0),-(%sp)
	move.l 20(%fp),-(%sp)
	move.l 16(%fp),-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	unlk %fp
	rts
	.even
	.globl	__Z13fighterUpdatefP7FighterP14SpriteAnimatorP14AnimationFrameS4_S4_S4_S4_b
__Z13fighterUpdatefP7FighterP14SpriteAnimatorP14AnimationFrameS4_S4_S4_S4_b:
	link.w %fp,#0
	movem.l #16188,-(%sp)
	move.l 8(%fp),%d4
	move.l 12(%fp),%a2
	move.l 16(%fp),%a3
	move.l 20(%fp),%a4
	move.l 24(%fp),%d5
	move.l 28(%fp),%d7
	move.l 32(%fp),%d2
	move.l 36(%fp),%d3
	move.b 43(%fp),%d6
	move.l 48(%a2),-(%sp)
	jsr jsfGetPad
	move.l %d0,44(%a2)
	move.l %d0,%d1
	and.l JAGPAD_B,%d1
	addq.l #4,%sp
	jeq .L19
	tst.b 30(%a2)
	jne .L20
	move.b #1,30(%a2)
	clr.l 16(%a3)
.L20:
	and.l JAGPAD_DOWN,%d0
	jeq .L21
	tst.b 29(%a2)
	jne .L22
	move.b #1,29(%a2)
	clr.l 16(%a3)
.L22:
	clr.l 24(%fp)
	moveq #1,%d0
	move.l %d0,20(%fp)
	move.l 24(%a2),16(%fp)
	move.l %d3,12(%fp)
	move.l %a3,8(%fp)
	movem.l -40(%fp),#15612
	unlk %fp
	jra __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
.L19:
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jne .L35
	move.l %d0,%d1
	and.l JAGPAD_RIGHT,%d1
	jne .L36
	and.l JAGPAD_DOWN,%d0
	jne .L37
	tst.b 29(%a2)
	jne .L38
	tst.b 30(%a2)
	jne .L39
	tst.b 28(%a2)
	jeq .L33
	clr.b 28(%a2)
	clr.l 16(%a3)
.L33:
	moveq #1,%d0
	move.l %d0,24(%fp)
	move.l %d0,20(%fp)
	move.l 8(%a2),16(%fp)
	move.l %a4,12(%fp)
	move.l %a3,8(%fp)
	movem.l -40(%fp),#15612
	unlk %fp
	jra __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
.L21:
	tst.b 29(%a2)
	jeq .L23
	clr.b 29(%a2)
.L23:
	clr.l 24(%fp)
	moveq #1,%d1
	move.l %d1,20(%fp)
	move.l 20(%a2),16(%fp)
	move.l %d2,12(%fp)
	move.l %a3,8(%fp)
	movem.l -40(%fp),#15612
	unlk %fp
	jra __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
.L35:
	pea 1.w
	and.l #255,%d6
	move.l %d6,-(%sp)
	move.l 12(%a2),-(%sp)
	move.l %d5,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.b #1,28(%a2)
	clr.b 29(%a2)
	clr.b 30(%a2)
	move.l sprite,%a4
	move.l (%a2),%d0
	move.l %d0,%d5
	add.l %d0,%d5
	add.l %d0,%d5
	lsl.l #6,%d5
	add.l %a4,%d5
	move.l %d5,%a0
	move.w 8(%a0),%d2
	lea (20,%sp),%sp
	jle .L25
	lea ___floatsisf,%a3
	move.l 56(%a2),-(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d4,-(%sp)
	jsr ___mulsf3
	addq.l #8,%sp
	move.l %d0,%d3
	move.w %d2,%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	move.l #___subsf3,%d2
	move.l %d3,(%sp)
	move.l %d0,-(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #8,%sp
	lea ___fixsfsi,%a5
	move.l %d0,-(%sp)
	jsr (%a5)
	move.l %d5,%a0
	move.w %d0,8(%a0)
	move.l 32(%a2),%d0
	move.l %d0,%d4
	add.l %d0,%d4
	add.l %d0,%d4
	lsl.l #6,%d4
	add.l %a4,%d4
	move.l %d4,%a0
	move.w 8(%a0),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d3,(%sp)
	move.l %d0,-(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	move.l %d4,%a0
	move.w %d0,8(%a0)
	move.l 36(%a2),%d0
	move.l %d0,%d4
	add.l %d0,%d4
	add.l %d0,%d4
	lsl.l #6,%d4
	add.l %a4,%d4
	move.l %d4,%a0
	move.w 8(%a0),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d3,(%sp)
	move.l %d0,-(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	move.l %d4,%a0
	move.w %d0,8(%a0)
	move.l 40(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	add.l %d0,%a4
	move.w 8(%a4),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d3,(%sp)
	move.l %d0,-(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.w %d0,8(%a4)
.L18:
	movem.l -40(%fp),#15612
	unlk %fp
	rts
.L37:
	tst.b 29(%a2)
	jne .L30
	move.b #1,29(%a2)
	clr.l 16(%a3)
.L30:
	clr.l -(%sp)
	pea 1.w
	move.l 16(%a2),-(%sp)
	move.l %d7,-(%sp)
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
	movem.l -40(%fp),#15612
	unlk %fp
	rts
.L36:
	pea 1.w
	eor.b #1,%d6
	and.l #255,%d6
	move.l %d6,-(%sp)
	move.l 12(%a2),-(%sp)
	move.l %d5,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	move.b #1,28(%a2)
	clr.b 29(%a2)
	clr.b 30(%a2)
	move.l sprite,%a4
	move.l (%a2),%d0
	move.l %d0,%d5
	add.l %d0,%d5
	add.l %d0,%d5
	lsl.l #6,%d5
	add.l %a4,%d5
	move.l %d5,%a0
	move.w 8(%a0),%d2
	lea (20,%sp),%sp
	cmp.w #259,%d2
	jgt .L28
	lea ___floatsisf,%a3
	move.l 52(%a2),-(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d4,-(%sp)
	jsr ___mulsf3
	addq.l #8,%sp
	move.l %d0,%d3
	move.w %d2,%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	move.l #___addsf3,%d2
	move.l %d0,(%sp)
	move.l %d3,-(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #8,%sp
	lea ___fixsfsi,%a5
	move.l %d0,-(%sp)
	jsr (%a5)
	move.l %d5,%a0
	move.w %d0,8(%a0)
	move.l 32(%a2),%d0
	move.l %d0,%d4
	add.l %d0,%d4
	add.l %d0,%d4
	lsl.l #6,%d4
	add.l %a4,%d4
	move.l %d4,%a0
	move.w 8(%a0),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d3,-(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	move.l %d4,%a0
	move.w %d0,8(%a0)
	move.l 36(%a2),%d0
	move.l %d0,%d4
	add.l %d0,%d4
	add.l %d0,%d4
	lsl.l #6,%d4
	add.l %a4,%d4
	move.l %d4,%a0
	move.w 8(%a0),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d3,-(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	move.l %d4,%a0
	move.w %d0,8(%a0)
	move.l 40(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	add.l %d0,%a4
	move.w 8(%a4),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d3,-(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.w %d0,8(%a4)
	movem.l -40(%fp),#15612
	unlk %fp
	rts
.L38:
	clr.l -(%sp)
	clr.l -(%sp)
	move.l 16(%a2),-(%sp)
	move.l %d7,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.l 16(%a3)
	jne .L18
	clr.b 29(%a2)
	move.l sprite,%a0
	move.l 36(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	moveq #1,%d1
	cmp.l 4(%a0,%d0.l),%d1
	jne .L18
	move.l 32(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	moveq #1,%d1
	move.l %d1,4(%a0,%d0.l)
	movem.l -40(%fp),#15612
	unlk %fp
	rts
.L28:
	move.l %d4,8(%fp)
	movem.l -40(%fp),#15612
	unlk %fp
	jra __Z13bgScrollRightf
.L39:
	clr.l -(%sp)
	clr.l -(%sp)
	move.l 20(%a2),-(%sp)
	move.l %d2,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb
	lea (20,%sp),%sp
	tst.l 16(%a3)
	jne .L18
	clr.b 30(%a2)
	movem.l -40(%fp),#15612
	unlk %fp
	rts
.L25:
	move.l %d4,8(%fp)
	movem.l -40(%fp),#15612
	unlk %fp
	jra __Z12bgScrollLeftf
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
