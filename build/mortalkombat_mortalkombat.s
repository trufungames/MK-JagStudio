#NO_APP
	.data
	.even
.LC0:
	.long	80
	.long	144
	.long	0
	.long	0
	.long	6
	.long	80
	.long	144
	.long	80
	.long	0
	.long	6
	.long	80
	.long	144
	.long	160
	.long	0
	.long	6
	.long	80
	.long	144
	.long	240
	.long	0
	.long	6
	.long	80
	.long	144
	.long	320
	.long	0
	.long	6
	.long	80
	.long	144
	.long	400
	.long	0
	.long	6
	.long	80
	.long	144
	.long	480
	.long	0
	.long	6
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.even
.LC1:
	.long	80
	.long	144
	.long	560
	.long	0
	.long	6
	.long	80
	.long	144
	.long	640
	.long	0
	.long	6
	.long	80
	.long	144
	.long	720
	.long	0
	.long	6
	.long	80
	.long	144
	.long	800
	.long	0
	.long	6
	.long	80
	.long	144
	.long	880
	.long	0
	.long	6
	.long	80
	.long	144
	.long	0
	.long	144
	.long	6
	.long	80
	.long	144
	.long	80
	.long	144
	.long	6
	.long	80
	.long	144
	.long	160
	.long	144
	.long	6
	.long	80
	.long	144
	.long	240
	.long	144
	.long	6
	.long	80
	.long	144
	.long	320
	.long	144
	.long	6
	.even
.LC2:
	.long	80
	.long	144
	.long	400
	.long	144
	.long	3
	.long	80
	.long	144
	.long	480
	.long	144
	.long	3
	.long	80
	.long	144
	.long	560
	.long	144
	.long	3
	.even
.LC3:
	.long	80
	.long	144
	.long	640
	.long	144
	.long	3
	.long	80
	.long	144
	.long	720
	.long	144
	.long	3
	.long	80
	.long	144
	.long	800
	.long	144
	.long	3
	.even
.LC5:
	.long	80
	.long	144
	.long	0
	.long	0
	.long	5
	.long	80
	.long	144
	.long	80
	.long	0
	.long	5
	.long	80
	.long	144
	.long	160
	.long	0
	.long	5
	.long	80
	.long	144
	.long	240
	.long	0
	.long	5
	.long	80
	.long	144
	.long	320
	.long	0
	.long	5
	.long	80
	.long	144
	.long	400
	.long	0
	.long	5
	.long	80
	.long	144
	.long	480
	.long	0
	.long	5
	.even
.LC6:
	.long	80
	.long	144
	.long	560
	.long	0
	.long	6
	.long	80
	.long	144
	.long	640
	.long	0
	.long	6
	.long	80
	.long	144
	.long	720
	.long	0
	.long	6
	.long	80
	.long	144
	.long	800
	.long	0
	.long	6
	.long	80
	.long	144
	.long	880
	.long	0
	.long	6
	.long	80
	.long	144
	.long	0
	.long	144
	.long	6
	.long	80
	.long	144
	.long	80
	.long	144
	.long	6
	.long	80
	.long	144
	.long	160
	.long	144
	.long	6
	.long	80
	.long	144
	.long	240
	.long	144
	.long	6
	.even
.LC7:
	.long	80
	.long	144
	.long	320
	.long	144
	.long	3
	.long	80
	.long	144
	.long	400
	.long	144
	.long	3
	.long	80
	.long	144
	.long	480
	.long	144
	.long	3
	.text
	.even
	.globl	__Z9basicmainv
__Z9basicmainv:
	link.w %fp,#-1024
	movem.l #16188,-(%sp)
	clr.l __ZL4pad1
	clr.l __ZL4pad2
	move.w #-20673,15728728
	pea 20.w
	pea 5.w
	jsr rapDebugSetXY
	addq.l #8,%sp
	jsr RAPTOR_console_inverse
	move.l sprite,%a0
	move.l 1160(%a0),-(%sp)
	clr.l -(%sp)
	jsr rapDebugSetMonitor
	addq.l #4,%sp
	clr.l (%sp)
	jsr rapSetClock
	move.w #8,raptor_clock_mode
	moveq #16,%d1
	move.l %d1,(%sp)
	clr.l -(%sp)
	move.l #9535920,-(%sp)
	lea jsfLoadClut,%a2
	jsr (%a2)
	addq.l #8,%sp
	moveq #16,%d2
	move.l %d2,(%sp)
	pea 1.w
	move.l #10060240,-(%sp)
	jsr (%a2)
	moveq #12,%d0
	move.l %d0,-40(%fp)
	move.l #0x3f000000,-36(%fp)
	move.l #9011632,-32(%fp)
	clr.l -28(%fp)
	clr.l -24(%fp)
	pea 240.w
	pea .LC0
	pea -1020(%fp)
	lea _memcpy,%a2
	jsr (%a2)
	pea 200.w
	pea .LC1
	pea -780(%fp)
	jsr (%a2)
	lea (36,%sp),%sp
	pea 60.w
	pea .LC2
	pea -260(%fp)
	jsr (%a2)
	pea 60.w
	pea .LC3
	pea -200(%fp)
	jsr (%a2)
	moveq #80,%d0
	move.l %d0,-80(%fp)
	move.l #144,-76(%fp)
	move.l #880,-72(%fp)
	move.l #144,-68(%fp)
	move.b #3,%d0
	move.l %d0,-64(%fp)
	move.b #80,%d0
	move.l %d0,-60(%fp)
	move.l #144,-56(%fp)
	clr.l -52(%fp)
	move.l #288,-48(%fp)
	move.b #3,%d0
	move.l %d0,-44(%fp)
	move.b #13,%d0
	move.l %d0,-20(%fp)
	move.l #0x3f000000,-16(%fp)
	move.l #9535952,-12(%fp)
	clr.l -8(%fp)
	clr.l -4(%fp)
	pea 140.w
	pea .LC5
	pea -400(%fp)
	jsr (%a2)
	lea (36,%sp),%sp
	pea 180.w
	pea .LC6
	pea -580(%fp)
	jsr (%a2)
	pea 60.w
	pea .LC7
	pea -140(%fp)
	jsr (%a2)
	lea (24,%sp),%sp
	clr.b %d4
	clr.b %d3
	clr.b %d2
	clr.b -1021(%fp)
	clr.b -1022(%fp)
	lea jsfGetPad,%a2
	moveq #-40,%d7
	add.l %fp,%d7
	lea __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibb,%a3
	moveq #-20,%d6
	add.l %fp,%d6
	move.l #jsfGetPadPressed,%d5
	lea rapDebugUpdate,%a5
	lea _jsfVsync,%a4
	pea 1.w
	jsr (%a2)
	move.l %d0,__ZL4pad1
	moveq #2,%d0
	move.l %d0,(%sp)
	jsr (%a2)
	move.l %d0,__ZL4pad2
	move.l __ZL4pad1,%d0
	move.l %d0,%d1
	and.l JAGPAD_B,%d1
	addq.l #4,%sp
	jeq .L2
.L36:
	tst.b %d4
	jne .L3
	clr.l -24(%fp)
	moveq #1,%d4
.L3:
	and.l JAGPAD_DOWN,%d0
	jeq .L4
	tst.b %d2
	jne .L5
	clr.l -24(%fp)
	moveq #1,%d2
.L5:
	clr.l -(%sp)
	pea 1.w
	pea 1.w
	pea -80(%fp)
	move.l %d7,-(%sp)
	jsr (%a3)
	lea (20,%sp),%sp
.L6:
	move.l __ZL4pad2,%d0
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jne .L32
.L16:
	move.l %d0,%d1
	and.l JAGPAD_RIGHT,%d1
	jne .L33
	and.l JAGPAD_DOWN,%d0
	jeq .L21
	tst.b %d3
	jne .L22
	clr.l -4(%fp)
	moveq #1,%d3
.L22:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea -140(%fp)
	move.l %d6,-(%sp)
	jsr (%a3)
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,3268(%a0)
	lea (20,%sp),%sp
.L18:
	pea 1.w
	move.l %d5,%a0
	jsr (%a0)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_STAR,%d1
	addq.l #4,%sp
	jne .L34
.L25:
	and.l JAGPAD_HASH,%d0
	jne .L35
	jsr (%a5)
	clr.l -(%sp)
	jsr (%a4)
	addq.l #4,%sp
.L39:
	pea 1.w
	jsr (%a2)
	move.l %d0,__ZL4pad1
	moveq #2,%d0
	move.l %d0,(%sp)
	jsr (%a2)
	move.l %d0,__ZL4pad2
	move.l __ZL4pad1,%d0
	move.l %d0,%d1
	and.l JAGPAD_B,%d1
	addq.l #4,%sp
	jne .L36
.L2:
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jne .L37
	move.l %d0,%d1
	and.l JAGPAD_RIGHT,%d1
	jne .L38
	and.l JAGPAD_DOWN,%d0
	jeq .L11
	tst.b %d2
	jne .L12
	clr.l -24(%fp)
	moveq #1,%d2
.L12:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea -260(%fp)
	move.l %d7,-(%sp)
	jsr (%a3)
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,2692(%a0)
	lea (20,%sp),%sp
	move.l __ZL4pad2,%d0
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jeq .L16
.L32:
	pea 1.w
	pea 1.w
	pea 9.w
	pea -580(%fp)
	move.l %d6,-(%sp)
	jsr (%a3)
	move.l sprite,%a0
	move.w 2504(%a0),%d0
	lea (20,%sp),%sp
	jle .L17
	subq.w #5,%d0
	move.w %d0,2504(%a0)
	subq.w #5,3272(%a0)
	subq.w #5,3464(%a0)
	subq.w #5,3656(%a0)
	clr.b %d3
	move.b #1,-1021(%fp)
	pea 1.w
	move.l %d5,%a0
	jsr (%a0)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_STAR,%d1
	addq.l #4,%sp
	jeq .L25
.L34:
	move.l sprite,%a0
	moveq #1,%d0
	move.l %d0,2692(%a0)
	move.l %d0,2884(%a0)
	move.l %d0,3076(%a0)
	move.l %d0,3268(%a0)
	move.l %d0,3460(%a0)
	move.l %d0,3652(%a0)
	pea 1.w
	jsr rapDebugSetVisible
	addq.l #4,%sp
	jsr (%a5)
	clr.l -(%sp)
	jsr (%a4)
	addq.l #4,%sp
	jra .L39
.L35:
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,2692(%a0)
	move.l %d0,2884(%a0)
	move.l %d0,3076(%a0)
	move.l %d0,3268(%a0)
	move.l %d0,3460(%a0)
	move.l %d0,3652(%a0)
	clr.l -(%sp)
	jsr rapDebugSetVisible
	addq.l #4,%sp
	jsr (%a5)
	clr.l -(%sp)
	jsr (%a4)
	addq.l #4,%sp
	jra .L39
.L21:
	tst.b %d3
	jne .L40
	tst.b -1021(%fp)
	jeq .L24
	clr.l -4(%fp)
.L24:
	pea 1.w
	pea 1.w
	pea 7.w
	pea -400(%fp)
	move.l %d6,-(%sp)
	jsr (%a3)
	lea (20,%sp),%sp
	clr.b -1021(%fp)
	jra .L18
.L4:
	clr.l -(%sp)
	pea 1.w
	pea 2.w
	pea -200(%fp)
	move.l %d7,-(%sp)
	jsr (%a3)
	lea (20,%sp),%sp
	clr.b %d2
	jra .L6
.L33:
	pea 1.w
	clr.l -(%sp)
	pea 9.w
	pea -580(%fp)
	move.l %d6,-(%sp)
	jsr (%a3)
	move.l sprite,%a0
	move.w 2504(%a0),%d0
	lea (20,%sp),%sp
	cmp.w #259,%d0
	jgt .L20
	addq.w #4,%d0
	move.w %d0,2504(%a0)
	addq.w #4,3272(%a0)
	addq.w #4,3464(%a0)
	addq.w #4,3656(%a0)
	clr.b %d3
	move.b #1,-1021(%fp)
	jra .L18
.L37:
	pea 1.w
	pea 1.w
	pea 9.w
	pea -780(%fp)
	move.l %d7,-(%sp)
	jsr (%a3)
	move.l sprite,%a0
	move.w 2312(%a0),%d0
	lea (20,%sp),%sp
	jle .L8
	subq.w #4,%d0
	move.w %d0,2312(%a0)
	subq.w #4,2696(%a0)
	subq.w #4,2888(%a0)
	subq.w #4,3080(%a0)
	clr.b %d4
	clr.b %d2
	move.b #1,-1022(%fp)
	jra .L6
.L11:
	tst.b %d2
	jne .L41
	tst.b %d4
	jne .L42
	tst.b -1022(%fp)
	jeq .L15
	clr.l -24(%fp)
.L15:
	pea 1.w
	pea 1.w
	pea 7.w
	pea -1020(%fp)
	move.l %d7,-(%sp)
	jsr (%a3)
	lea (20,%sp),%sp
	clr.b -1022(%fp)
	jra .L6
.L38:
	pea 1.w
	clr.l -(%sp)
	pea 9.w
	pea -780(%fp)
	move.l %d7,-(%sp)
	jsr (%a3)
	move.l sprite,%a0
	move.w 2312(%a0),%d0
	lea (20,%sp),%sp
	cmp.w #259,%d0
	jgt .L10
	addq.w #5,%d0
	move.w %d0,2312(%a0)
	addq.w #5,2696(%a0)
	addq.w #5,2888(%a0)
	addq.w #5,3080(%a0)
	clr.b %d4
	clr.b %d2
	move.b #1,-1022(%fp)
	jra .L6
.L40:
	clr.l -(%sp)
	clr.l -(%sp)
	pea 2.w
	pea -140(%fp)
	move.l %d6,-(%sp)
	jsr (%a3)
	lea (20,%sp),%sp
	tst.l -4(%fp)
	jne .L18
	move.l sprite,%a0
	moveq #1,%d0
	cmp.l 3460(%a0),%d0
	jeq .L43
	clr.b %d3
	jra .L18
.L20:
	jsr __Z13bgScrollRightv
	clr.b %d3
	move.b #1,-1021(%fp)
	jra .L18
.L17:
	jsr __Z12bgScrollLeftv
	clr.b %d3
	move.b #1,-1021(%fp)
	jra .L18
.L41:
	clr.l -(%sp)
	clr.l -(%sp)
	pea 2.w
	pea -260(%fp)
	move.l %d7,-(%sp)
	jsr (%a3)
	lea (20,%sp),%sp
	tst.l -24(%fp)
	jne .L6
	move.l sprite,%a0
	moveq #1,%d0
	cmp.l 2884(%a0),%d0
	jeq .L44
	clr.b %d2
	jra .L6
.L10:
	jsr __Z13bgScrollRightv
	clr.b %d4
	clr.b %d2
	move.b #1,-1022(%fp)
	jra .L6
.L42:
	clr.l -(%sp)
	clr.l -(%sp)
	pea 2.w
	pea -200(%fp)
	move.l %d7,-(%sp)
	jsr (%a3)
	lea (20,%sp),%sp
	tst.l -24(%fp)
	sne %d0
	and.b %d0,%d4
	jra .L6
.L8:
	jsr __Z12bgScrollLeftv
	clr.b %d4
	clr.b %d2
	move.b #1,-1022(%fp)
	jra .L6
.L43:
	move.l %d0,3268(%a0)
	clr.b %d3
	jra .L18
.L44:
	move.l %d0,2692(%a0)
	clr.b %d2
	jra .L6
	.even
	.globl	__Z10fireButtonv
__Z10fireButtonv:
	link.w %fp,#0
	unlk %fp
	jra __Z8sfxShootv
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
.lcomm __ZL4pad1,4
.lcomm __ZL4pad2,4
