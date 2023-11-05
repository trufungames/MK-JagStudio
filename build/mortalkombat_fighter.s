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
	clr.l 50(%a0)
	moveq #2,%d0
	move.l %d0,58(%a0)
	move.l %d0,62(%a0)
	clr.b 32(%a0)
	clr.b 33(%a0)
	clr.b 34(%a0)
	clr.b 35(%a0)
	move.b #1,36(%a0)
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
	move.l %d0,46(%a0)
	move.b #42,%d0
	move.l %d0,38(%a0)
	move.b #43,%d0
	move.l %d0,42(%a0)
	move.b #2,%d0
	move.l %d0,54(%a0)
	move.w #210,8(%a1)
	unlk %fp
	rts
.L15:
	move.b #41,%d0
	move.l %d0,46(%a0)
	move.b #39,%d0
	move.l %d0,38(%a0)
	move.b #40,%d0
	move.l %d0,42(%a0)
	move.b #1,%d0
	move.l %d0,54(%a0)
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
	movem.l #15420,-(%sp)
	move.l 12(%fp),%a2
	move.l 16(%fp),%a3
	move.b 47(%fp),%d2
	move.l 54(%a2),-(%sp)
	jsr jsfGetPad
	move.l %d0,50(%a2)
	move.l %d0,%d1
	and.l JAGPAD_C,%d1
	addq.l #4,%sp
	jne .L19
	tst.b 35(%a2)
	jeq .L42
.L20:
	move.l 70(%a2),-(%sp)
	move.l 66(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 28(%a2),-(%sp)
	move.l 40(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	lea (24,%sp),%sp
	move.l 28(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jne .L43
.L22:
	move.l JAGPAD_C,%d0
	and.l 50(%a2),%d0
	jne .L18
	move.b #1,36(%a2)
.L18:
	movem.l -32(%fp),#15420
	unlk %fp
	rts
.L19:
	tst.b 35(%a2)
	jne .L20
	tst.b 36(%a2)
	jeq .L20
	clr.b 36(%a2)
	move.b #1,35(%a2)
	clr.l 16(%a3)
	move.l 70(%a2),-(%sp)
	move.l 66(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 28(%a2),-(%sp)
	move.l 40(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	lea (24,%sp),%sp
	move.l 28(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L22
.L43:
	clr.b 35(%a2)
	jra .L22
.L42:
	move.l %d0,%d1
	and.l JAGPAD_B,%d1
	jne .L44
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jne .L45
	move.l %d0,%d1
	and.l JAGPAD_RIGHT,%d1
	jne .L46
	and.l JAGPAD_DOWN,%d0
	jne .L47
	tst.b 33(%a2)
	jne .L48
	tst.b 34(%a2)
	jne .L49
	tst.b 32(%a2)
	jeq .L38
	clr.b 32(%a2)
	clr.l 16(%a3)
.L38:
	move.l 70(%a2),-(%sp)
	move.l 66(%a2),-(%sp)
	pea 1.w
	pea 1.w
	move.l 8(%a2),-(%sp)
	move.l 20(%fp),-(%sp)
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
	move.l %a1,66(%a2)
	move.w 12(%a0),%a0
	move.l %a0,70(%a2)
	lea (28,%sp),%sp
	jra .L22
.L44:
	tst.b 34(%a2)
	jne .L24
	move.b #1,34(%a2)
	clr.l 16(%a3)
.L24:
	and.l JAGPAD_DOWN,%d0
	jeq .L25
	tst.b 33(%a2)
	jne .L26
	move.b #1,33(%a2)
	clr.l 16(%a3)
.L26:
	move.l 70(%a2),-(%sp)
	move.l 66(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 24(%a2),-(%sp)
	move.l 36(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	lea (28,%sp),%sp
	jra .L22
.L25:
	tst.b 33(%a2)
	jeq .L27
	clr.b 33(%a2)
.L27:
	move.l 70(%a2),-(%sp)
	move.l 66(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 20(%a2),-(%sp)
	move.l 32(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	lea (28,%sp),%sp
	jra .L22
.L47:
	tst.b 33(%a2)
	jne .L35
	move.b #1,33(%a2)
	clr.l 16(%a3)
.L35:
	move.l 70(%a2),-(%sp)
	move.l 66(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 16(%a2),-(%sp)
	move.l 28(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	move.l 38(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,4(%a0,%d0.l)
	lea (28,%sp),%sp
	jra .L22
.L45:
	move.l 70(%a2),-(%sp)
	move.l 66(%a2),-(%sp)
	pea 1.w
	and.l #255,%d2
	move.l %d2,-(%sp)
	move.l 12(%a2),-(%sp)
	move.l 24(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	move.b #1,32(%a2)
	clr.b 33(%a2)
	clr.b 34(%a2)
	clr.b 35(%a2)
	move.l sprite,%a5
	move.l (%a2),%d0
	move.l %d0,%a4
	add.l %d0,%a4
	add.l %a4,%d0
	lsl.l #6,%d0
	lea (%a5,%d0.l),%a4
	move.w 8(%a4),%d2
	lea (28,%sp),%sp
	jle .L29
	lea ___floatsisf,%a3
	move.l 62(%a2),-(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l 8(%fp),-(%sp)
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
	move.l 38(%a2),%d0
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
	move.l 42(%a2),%d0
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
	move.l 46(%a2),%d0
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
	move.l %a0,66(%a2)
	move.w 12(%a4),%a4
	move.l %a4,70(%a2)
	jra .L22
.L46:
	move.l 70(%a2),-(%sp)
	move.l 66(%a2),-(%sp)
	pea 1.w
	eor.b #1,%d2
	and.l #255,%d2
	move.l %d2,-(%sp)
	move.l 12(%a2),-(%sp)
	move.l 24(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	move.b #1,32(%a2)
	clr.b 33(%a2)
	clr.b 34(%a2)
	clr.b 35(%a2)
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
	jgt .L32
	lea ___floatsisf,%a4
	move.l 58(%a2),-(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l 8(%fp),-(%sp)
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
	move.l 38(%a2),%d0
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
	move.l 42(%a2),%d0
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
	move.l 46(%a2),%d0
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
	move.l %a1,66(%a2)
	move.w 12(%a3),%a3
	move.l %a3,70(%a2)
	jra .L22
.L48:
	move.l 70(%a2),-(%sp)
	move.l 66(%a2),-(%sp)
	clr.l -(%sp)
	clr.l -(%sp)
	move.l 16(%a2),-(%sp)
	move.l 28(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	lea (28,%sp),%sp
	tst.l 16(%a3)
	jne .L22
	clr.b 33(%a2)
	move.l sprite,%a0
	move.l 42(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	moveq #1,%d1
	cmp.l 4(%a0,%d0.l),%d1
	jne .L22
	move.l 38(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	moveq #1,%d1
	move.l %d1,4(%a0,%d0.l)
	jra .L22
.L32:
	move.l 8(%fp),-(%sp)
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
	move.l %a1,66(%a2)
	move.w 12(%a3),%a3
	move.l %a3,70(%a2)
	jra .L22
.L49:
	move.l 70(%a2),-(%sp)
	move.l 66(%a2),-(%sp)
	clr.l -(%sp)
	clr.l -(%sp)
	move.l 20(%a2),-(%sp)
	move.l 32(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbii
	lea (28,%sp),%sp
	tst.l 16(%a3)
	jne .L22
	clr.b 34(%a2)
	jra .L22
.L29:
	move.l 8(%fp),-(%sp)
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
	move.l %a0,66(%a2)
	move.w 12(%a4),%a4
	move.l %a4,70(%a2)
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
