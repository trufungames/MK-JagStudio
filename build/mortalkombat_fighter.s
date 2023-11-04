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
	moveq #33,%d1
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
	clr.l 48(%a0)
	moveq #2,%d0
	move.l %d0,56(%a0)
	move.l %d0,60(%a0)
	clr.b 32(%a0)
	clr.b 33(%a0)
	clr.b 34(%a0)
	clr.b 35(%a0)
	move.l (%a0),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a1
	add.l %d0,%a1
	moveq #1,%d0
	move.l %d0,4(%a1)
	tst.b 15(%fp)
	jne .L15
	moveq #44,%d0
	move.l %d0,44(%a0)
	move.b #42,%d0
	move.l %d0,36(%a0)
	move.b #43,%d0
	move.l %d0,40(%a0)
	move.b #2,%d0
	move.l %d0,52(%a0)
	move.w #210,8(%a1)
	unlk %fp
	rts
.L15:
	move.b #41,%d0
	move.l %d0,44(%a0)
	move.b #39,%d0
	move.l %d0,36(%a0)
	move.b #40,%d0
	move.l %d0,40(%a0)
	move.b #1,%d0
	move.l %d0,52(%a0)
	move.w #50,8(%a1)
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
	.globl	__Z13fighterUpdatefP7FighterP14SpriteAnimatorP14AnimationFrameS4_S4_S4_S4_S4_b
__Z13fighterUpdatefP7FighterP14SpriteAnimatorP14AnimationFrameS4_S4_S4_S4_S4_b:
	link.w %fp,#0
	movem.l #16188,-(%sp)
	move.l 8(%fp),%d7
	move.l 12(%fp),%a2
	move.l 16(%fp),%a3
	move.l 20(%fp),%a5
	move.l 24(%fp),%d5
	move.l 28(%fp),%a4
	move.l 32(%fp),%d3
	move.l 36(%fp),%d4
	move.l 40(%fp),%d2
	move.b 47(%fp),%d6
	move.l 52(%a2),-(%sp)
	jsr jsfGetPad
	move.l %d0,48(%a2)
	move.l %d0,%d1
	and.l JAGPAD_C,%d1
	addq.l #4,%sp
	jeq .L19
	tst.b 35(%a2)
	jne .L20
	move.b #1,35(%a2)
	clr.l 16(%a3)
.L20:
	move.l 68(%a2),32(%fp)
	move.l 64(%a2),28(%fp)
	clr.l 24(%fp)
	moveq #1,%d0
	move.l %d0,20(%fp)
	move.l 28(%a2),16(%fp)
	move.l %d2,12(%fp)
	move.l %a3,8(%fp)
	movem.l -40(%fp),#15612
	unlk %fp
	jra __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
.L19:
	move.l %d0,%d1
	and.l JAGPAD_B,%d1
	jeq .L21
	tst.b 34(%a2)
	jne .L22
	move.b #1,34(%a2)
	clr.l 16(%a3)
.L22:
	and.l JAGPAD_DOWN,%d0
	jeq .L23
	tst.b 33(%a2)
	jne .L24
	move.b #1,33(%a2)
	clr.l 16(%a3)
.L24:
	move.l 68(%a2),32(%fp)
	move.l 64(%a2),28(%fp)
	clr.l 24(%fp)
	moveq #1,%d1
	move.l %d1,20(%fp)
	move.l 24(%a2),16(%fp)
	move.l %d4,12(%fp)
	move.l %a3,8(%fp)
	movem.l -40(%fp),#15612
	unlk %fp
	jra __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
.L21:
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jne .L39
	move.l %d0,%d1
	and.l JAGPAD_RIGHT,%d1
	jne .L40
	and.l JAGPAD_DOWN,%d0
	jeq .L33
	tst.b 33(%a2)
	jne .L34
	move.b #1,33(%a2)
	clr.l 16(%a3)
.L34:
	move.l 68(%a2),-(%sp)
	move.l 64(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 16(%a2),-(%sp)
	move.l %a4,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	move.l 36(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,4(%a0,%d0.l)
	lea (28,%sp),%sp
.L18:
	movem.l -40(%fp),#15612
	unlk %fp
	rts
.L23:
	tst.b 33(%a2)
	jeq .L25
	clr.b 33(%a2)
.L25:
	move.l 68(%a2),32(%fp)
	move.l 64(%a2),28(%fp)
	clr.l 24(%fp)
	moveq #1,%d0
	move.l %d0,20(%fp)
	move.l 20(%a2),16(%fp)
	move.l %d3,12(%fp)
	move.l %a3,8(%fp)
	movem.l -40(%fp),#15612
	unlk %fp
	jra __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
.L39:
	move.l 68(%a2),-(%sp)
	move.l 64(%a2),-(%sp)
	pea 1.w
	and.l #255,%d6
	move.l %d6,-(%sp)
	move.l 12(%a2),-(%sp)
	move.l %d5,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	move.b #1,32(%a2)
	clr.b 33(%a2)
	clr.b 34(%a2)
	move.l sprite,%a5
	move.l (%a2),%d0
	move.l %d0,%a4
	add.l %d0,%a4
	add.l %a4,%d0
	lsl.l #6,%d0
	lea (%a5,%d0.l),%a4
	move.w 8(%a4),%d2
	lea (28,%sp),%sp
	jle .L27
	lea ___floatsisf,%a3
	move.l 60(%a2),-(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l %d7,-(%sp)
	jsr ___mulsf3
	addq.l #8,%sp
	move.l %d0,%d4
	move.w %d2,%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	move.l #___subsf3,%d3
	move.l %d4,(%sp)
	move.l %d0,-(%sp)
	move.l %d3,%a1
	jsr (%a1)
	addq.l #8,%sp
	move.l #___fixsfsi,%d2
	move.l %d0,-(%sp)
	move.l %d2,%a0
	jsr (%a0)
	move.w %d0,8(%a4)
	move.l 36(%a2),%d0
	move.l %d0,%d5
	add.l %d0,%d5
	add.l %d0,%d5
	lsl.l #6,%d5
	add.l %a5,%d5
	move.l %d5,%a1
	move.w 8(%a1),%a1
	move.l %a1,(%sp)
	jsr (%a3)
	move.l %d4,(%sp)
	move.l %d0,-(%sp)
	move.l %d3,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d2,%a1
	jsr (%a1)
	move.l %d5,%a0
	move.w %d0,8(%a0)
	move.l 40(%a2),%d0
	move.l %d0,%d5
	add.l %d0,%d5
	add.l %d0,%d5
	lsl.l #6,%d5
	add.l %a5,%d5
	move.l %d5,%a1
	move.w 8(%a1),%a1
	move.l %a1,(%sp)
	jsr (%a3)
	move.l %d4,(%sp)
	move.l %d0,-(%sp)
	move.l %d3,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d2,%a1
	jsr (%a1)
	move.l %d5,%a0
	move.w %d0,8(%a0)
	move.l 44(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	add.l %d0,%a5
	move.w 8(%a5),%a1
	move.l %a1,(%sp)
	jsr (%a3)
	move.l %d4,(%sp)
	move.l %d0,-(%sp)
	move.l %d3,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d2,%a1
	jsr (%a1)
	addq.l #4,%sp
	move.w %d0,8(%a5)
	move.w 8(%a4),%a0
	move.l %a0,64(%a2)
	move.w 12(%a4),%a4
	move.l %a4,68(%a2)
.L44:
	movem.l -40(%fp),#15612
	unlk %fp
	rts
.L33:
	tst.b 33(%a2)
	jne .L41
	tst.b 34(%a2)
	jne .L42
	tst.b 32(%a2)
	jeq .L37
	clr.b 32(%a2)
	clr.l 16(%a3)
.L37:
	move.l 68(%a2),-(%sp)
	move.l 64(%a2),-(%sp)
	pea 1.w
	pea 1.w
	move.l 8(%a2),-(%sp)
	move.l %a5,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	move.l (%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	add.l %d0,%a0
	move.w 8(%a0),%a1
	move.l %a1,64(%a2)
	move.w 12(%a0),%a0
	move.l %a0,68(%a2)
	lea (28,%sp),%sp
	movem.l -40(%fp),#15612
	unlk %fp
	rts
.L40:
	move.l 68(%a2),-(%sp)
	move.l 64(%a2),-(%sp)
	pea 1.w
	eor.b #1,%d6
	and.l #255,%d6
	move.l %d6,-(%sp)
	move.l 12(%a2),-(%sp)
	move.l %d5,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	move.b #1,32(%a2)
	clr.b 33(%a2)
	clr.b 34(%a2)
	move.l sprite,%a5
	move.l (%a2),%d0
	move.l %d0,%a3
	add.l %d0,%a3
	add.l %a3,%d0
	lsl.l #6,%d0
	lea (%a5,%d0.l),%a3
	move.w 8(%a3),%d2
	lea (28,%sp),%sp
	cmp.w #259,%d2
	jgt .L31
	lea ___floatsisf,%a4
	move.l 56(%a2),-(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d7,-(%sp)
	jsr ___mulsf3
	addq.l #8,%sp
	move.l %d0,%d4
	move.w %d2,%a1
	move.l %a1,-(%sp)
	jsr (%a4)
	move.l #___addsf3,%d3
	move.l %d0,(%sp)
	move.l %d4,-(%sp)
	move.l %d3,%a0
	jsr (%a0)
	addq.l #8,%sp
	move.l #___fixsfsi,%d2
	move.l %d0,-(%sp)
	move.l %d2,%a1
	jsr (%a1)
	move.w %d0,8(%a3)
	move.l 36(%a2),%d0
	move.l %d0,%d5
	add.l %d0,%d5
	add.l %d0,%d5
	lsl.l #6,%d5
	add.l %a5,%d5
	move.l %d5,%a0
	move.w 8(%a0),%a0
	move.l %a0,(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d4,-(%sp)
	move.l %d3,%a1
	jsr (%a1)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d2,%a0
	jsr (%a0)
	move.l %d5,%a1
	move.w %d0,8(%a1)
	move.l 40(%a2),%d0
	move.l %d0,%d5
	add.l %d0,%d5
	add.l %d0,%d5
	lsl.l #6,%d5
	add.l %a5,%d5
	move.l %d5,%a0
	move.w 8(%a0),%a0
	move.l %a0,(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d4,-(%sp)
	move.l %d3,%a1
	jsr (%a1)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d2,%a0
	jsr (%a0)
	move.l %d5,%a1
	move.w %d0,8(%a1)
	move.l 44(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	add.l %d0,%a5
	move.w 8(%a5),%a0
	move.l %a0,(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d4,-(%sp)
	move.l %d3,%a1
	jsr (%a1)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.w %d0,8(%a5)
	move.w 8(%a3),%a1
	move.l %a1,64(%a2)
	move.w 12(%a3),%a3
	move.l %a3,68(%a2)
.L43:
	movem.l -40(%fp),#15612
	unlk %fp
	rts
.L41:
	move.l 68(%a2),-(%sp)
	move.l 64(%a2),-(%sp)
	clr.l -(%sp)
	clr.l -(%sp)
	move.l 16(%a2),-(%sp)
	move.l %a4,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	lea (28,%sp),%sp
	tst.l 16(%a3)
	jne .L18
	clr.b 33(%a2)
	move.l sprite,%a0
	move.l 40(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	moveq #1,%d1
	cmp.l 4(%a0,%d0.l),%d1
	jne .L18
	move.l 36(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	moveq #1,%d1
	move.l %d1,4(%a0,%d0.l)
	movem.l -40(%fp),#15612
	unlk %fp
	rts
.L31:
	move.l %d7,-(%sp)
	jsr __Z13bgScrollRightf
	move.l (%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a3
	add.l %d0,%a3
	addq.l #4,%sp
	move.w 8(%a3),%a1
	move.l %a1,64(%a2)
	move.w 12(%a3),%a3
	move.l %a3,68(%a2)
	jra .L43
.L42:
	move.l 68(%a2),-(%sp)
	move.l 64(%a2),-(%sp)
	clr.l -(%sp)
	clr.l -(%sp)
	move.l 20(%a2),-(%sp)
	move.l %d3,-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	lea (28,%sp),%sp
	tst.l 16(%a3)
	jne .L18
	clr.b 34(%a2)
	movem.l -40(%fp),#15612
	unlk %fp
	rts
.L27:
	move.l %d7,-(%sp)
	jsr __Z12bgScrollLeftf
	move.l (%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a4
	add.l %d0,%a4
	addq.l #4,%sp
	move.w 8(%a4),%a0
	move.l %a0,64(%a2)
	move.w 12(%a4),%a4
	move.l %a4,68(%a2)
	jra .L44
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
