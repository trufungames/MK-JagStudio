#NO_APP
	.data
	.even
.LC0:
	.long	96
	.long	144
	.long	0
	.long	0
	.long	6
	.long	96
	.long	144
	.long	96
	.long	0
	.long	6
	.long	96
	.long	144
	.long	192
	.long	0
	.long	6
	.long	96
	.long	144
	.long	288
	.long	0
	.long	6
	.long	96
	.long	144
	.long	384
	.long	0
	.long	6
	.long	96
	.long	144
	.long	480
	.long	0
	.long	6
	.long	96
	.long	144
	.long	576
	.long	0
	.long	6
	.even
.LC4:
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
	.long	80
	.long	144
	.long	560
	.long	0
	.long	6
	.even
.LC8:
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
	.even
.LC12:
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
	.even
.LC16:
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
	.even
.LC20:
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
	.text
	.even
	.globl	__Z9basicmainv
__Z9basicmainv:
	link.w %fp,#-1720
	movem.l #16188,-(%sp)
	clr.l __ZL4pad1
	clr.l __ZL4pad2
	tst.w raptor_ntsc_flag
	jne .L2
	moveq #50,%d0
	move.l %d0,__ZL11ticksPerSec
.L2:
	clr.l __ZL9lastTicks
	move.w #0,15728728
	pea 20.w
	pea 5.w
	jsr rapDebugSetXY
	addq.l #8,%sp
	jsr RAPTOR_console_inverse
	move.l sprite,%a0
	move.l 1736(%a0),-(%sp)
	clr.l -(%sp)
	jsr rapDebugSetMonitor
	addq.l #4,%sp
	clr.l (%sp)
	jsr rapSetClock
	move.w #8,raptor_clock_mode
	moveq #95,%d2
	move.l %d2,(%sp)
	clr.l -(%sp)
	move.l #12605584,-(%sp)
	jsr jsfLoadClut
	addq.l #8,%sp
	moveq #16,%d3
	move.l %d3,(%sp)
	pea 15.w
	move.l #10863632,-(%sp)
	jsr jsfLoadClut
	addq.l #8,%sp
	moveq #16,%d4
	move.l %d4,(%sp)
	pea 14.w
	move.l #12436592,-(%sp)
	jsr jsfLoadClut
	moveq #17,%d1
	move.l %d1,-140(%fp)
	move.l #0x3f000000,-136(%fp)
	move.l #8766384,-132(%fp)
	clr.l -128(%fp)
	clr.l -124(%fp)
	pea 140.w
	pea .LC0
	pea -1120(%fp)
	lea _memcpy,%a2
	jsr (%a2)
	moveq #18,%d0
	move.l %d0,-120(%fp)
	move.l #0x3f000000,-116(%fp)
	move.l #9290704,-112(%fp)
	clr.l -108(%fp)
	clr.l -104(%fp)
	pea 160.w
	pea .LC4
	pea -1280(%fp)
	jsr (%a2)
	moveq #19,%d1
	move.l %d1,-100(%fp)
	move.l #0x3f000000,-96(%fp)
	move.l #9815024,-92(%fp)
	clr.l -88(%fp)
	clr.l -84(%fp)
	lea (36,%sp),%sp
	pea 200.w
	pea .LC8
	pea -1480(%fp)
	jsr (%a2)
	moveq #20,%d0
	move.l %d0,-80(%fp)
	move.l #0x3f000000,-76(%fp)
	move.l #10339344,-72(%fp)
	clr.l -68(%fp)
	clr.l -64(%fp)
	pea 240.w
	pea .LC12
	pea -1720(%fp)
	jsr (%a2)
	moveq #21,%d1
	move.l %d1,-60(%fp)
	move.l #0x3f000000,-56(%fp)
	move.l #10863664,-52(%fp)
	clr.l -48(%fp)
	clr.l -44(%fp)
	pea 140.w
	pea .LC16
	pea -980(%fp)
	jsr (%a2)
	moveq #15,%d0
	move.l %d0,-40(%fp)
	move.l #0x3f000000,-36(%fp)
	move.l #11387984,-32(%fp)
	clr.l -28(%fp)
	clr.l -24(%fp)
	lea (36,%sp),%sp
	pea 140.w
	pea .LC16
	pea -840(%fp)
	jsr (%a2)
	moveq #16,%d1
	move.l %d1,-20(%fp)
	move.l #0x3f000000,-16(%fp)
	move.l #11912304,-12(%fp)
	clr.l -8(%fp)
	clr.l -4(%fp)
	pea 140.w
	pea .LC20
	pea -700(%fp)
	jsr (%a2)
	pea 60.w
	clr.l -(%sp)
	pea -560(%fp)
	lea _memset,%a2
	jsr (%a2)
	moveq #15,%d0
	move.l %d0,-560(%fp)
	move.l #11387984,-556(%fp)
	moveq #7,%d1
	move.l %d1,-552(%fp)
	move.b #9,%d0
	move.l %d0,-548(%fp)
	move.b #2,%d1
	move.l %d1,-544(%fp)
	move.l %d1,-540(%fp)
	move.b #1,%d0
	move.l %d0,-536(%fp)
	lea (36,%sp),%sp
	pea 60.w
	clr.l -(%sp)
	pea -500(%fp)
	jsr (%a2)
	moveq #16,%d1
	move.l %d1,-500(%fp)
	move.l #11912304,-496(%fp)
	moveq #7,%d0
	move.l %d0,-492(%fp)
	move.b #9,%d1
	move.l %d1,-488(%fp)
	move.b #2,%d0
	move.l %d0,-484(%fp)
	move.l %d0,-480(%fp)
	move.b #1,%d1
	move.l %d1,-476(%fp)
	pea 60.w
	clr.l -(%sp)
	pea -440(%fp)
	jsr (%a2)
	moveq #17,%d0
	move.l %d0,-440(%fp)
	move.l #8766384,-436(%fp)
	moveq #7,%d1
	move.l %d1,-432(%fp)
	move.b #9,%d0
	move.l %d0,-428(%fp)
	move.b #2,%d1
	move.l %d1,-424(%fp)
	move.l %d1,-420(%fp)
	move.b #1,%d0
	move.l %d0,-416(%fp)
	pea 60.w
	clr.l -(%sp)
	pea -380(%fp)
	jsr (%a2)
	moveq #18,%d1
	move.l %d1,-380(%fp)
	move.l #9290704,-376(%fp)
	moveq #7,%d0
	move.l %d0,-372(%fp)
	move.b #9,%d1
	move.l %d1,-368(%fp)
	move.b #2,%d0
	move.l %d0,-364(%fp)
	move.l %d0,-360(%fp)
	move.b #1,%d1
	move.l %d1,-356(%fp)
	lea (36,%sp),%sp
	pea 60.w
	clr.l -(%sp)
	pea -320(%fp)
	jsr (%a2)
	moveq #19,%d0
	move.l %d0,-320(%fp)
	move.l #9815024,-316(%fp)
	moveq #10,%d1
	move.l %d1,-312(%fp)
	move.b #9,%d0
	move.l %d0,-308(%fp)
	move.b #2,%d1
	move.l %d1,-304(%fp)
	move.l %d1,-300(%fp)
	move.b #1,%d0
	move.l %d0,-296(%fp)
	pea 60.w
	clr.l -(%sp)
	pea -260(%fp)
	jsr (%a2)
	moveq #20,%d1
	move.l %d1,-260(%fp)
	move.l #10339344,-256(%fp)
	moveq #12,%d0
	move.l %d0,-252(%fp)
	move.b #9,%d1
	move.l %d1,-248(%fp)
	move.b #2,%d0
	move.l %d0,-244(%fp)
	move.l %d0,-240(%fp)
	move.b #1,%d1
	move.l %d1,-236(%fp)
	pea 60.w
	clr.l -(%sp)
	pea -200(%fp)
	jsr (%a2)
	moveq #21,%d0
	move.l %d0,-200(%fp)
	move.l #10863664,-196(%fp)
	moveq #7,%d1
	move.l %d1,-192(%fp)
	move.l %d1,-188(%fp)
	move.b #1,%d0
	move.l %d0,-184(%fp)
	move.b #2,%d1
	move.l %d1,-180(%fp)
	move.l %d0,-176(%fp)
	lea (36,%sp),%sp
	pea 1.w
	pea -500(%fp)
	jsr __Z21fighterMakeSelectableP7Fighterb
	addq.l #4,%sp
	clr.l (%sp)
	pea -260(%fp)
	jsr __Z21fighterMakeSelectableP7Fighterb
	addq.l #8,%sp
	lea ___floatsisf,%a4
	move.l #___divsf3,%d4
	lea jsfGetPadPressed,%a2
	move.l #__Z11fighterHideP7Fighter,%d5
	move.l #__Z17fighterUpdateIdlefP7FighterP14SpriteAnimatorP14AnimationFrame,%d7
	move.l #rapDebugSetVisible,%d6
	move.l #rapDebugUpdate,%d3
	lea _jsfVsync,%a5
	move.w raptor_ticks,%a3
	move.l %a3,%d0
	sub.l __ZL9lastTicks,%d0
	move.l %d0,-(%sp)
	jsr (%a4)
	move.l %d0,%d2
	move.l __ZL11ticksPerSec,(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	move.l %d4,%a0
	jsr (%a0)
	addq.l #8,%sp
	move.l %d0,%d2
	move.l %a3,__ZL9lastTicks
	pea 1.w
	jsr (%a2)
	move.l %d0,__ZL4pad1
	moveq #1,%d1
	move.l %d1,(%sp)
	jsr (%a2)
	move.l %d0,__ZL4pad2
	move.l __ZL4pad1,%d0
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	addq.l #4,%sp
	jeq .L3
.L41:
	move.l __ZL8p1Cursor,%d0
	subq.l #1,%d0
	move.l %d0,__ZL8p1Cursor
	jlt .L36
	moveq #3,%d1
	cmp.l %d0,%d1
	jeq .L33
.L5:
	pea -440(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -500(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -260(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -200(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -320(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -380(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -560(%fp)
	move.l %d5,%a0
	jsr (%a0)
	move.l __ZL8p1Cursor,%d0
	addq.l #4,%sp
	moveq #6,%d1
	cmp.l %d0,%d1
	jcs .L11
.L37:
	add.l %d0,%d0
	move.w .L20(%pc,%d0.l),%d0
	jmp %pc@(2,%d0:w)
.L20:
	.word .L13-.L20
	.word .L14-.L20
	.word .L15-.L20
	.word .L16-.L20
	.word .L17-.L20
	.word .L18-.L20
	.word .L19-.L20
.L10:
	move.l __ZL8p1Cursor,%d0
	moveq #1,%d1
	cmp.l %d0,%d1
	jeq .L34
	moveq #2,%d1
	cmp.l %d0,%d1
	jne .L5
.L33:
	moveq #6,%d0
	move.l %d0,__ZL8p1Cursor
	pea -440(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -500(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -260(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -200(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -320(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -380(%fp)
	move.l %d5,%a0
	jsr (%a0)
	addq.l #4,%sp
	pea -560(%fp)
	move.l %d5,%a0
	jsr (%a0)
	move.l __ZL8p1Cursor,%d0
	addq.l #4,%sp
	moveq #6,%d1
	cmp.l %d0,%d1
	jcc .L37
.L11:
	moveq #6,%d1
	cmp.l %d0,%d1
	jcs .L21
.L38:
	add.l %d0,%d0
	move.w .L29(%pc,%d0.l),%d0
	jmp %pc@(2,%d0:w)
.L29:
	.word .L22-.L29
	.word .L23-.L29
	.word .L24-.L29
	.word .L25-.L29
	.word .L26-.L29
	.word .L27-.L29
	.word .L28-.L29
.L18:
	pea 16.w
	pea 14.w
	move.l #9814992,-(%sp)
	jsr jsfLoadClut
	addq.l #8,%sp
	moveq #1,%d1
	move.l %d1,(%sp)
	pea -380(%fp)
	jsr __Z21fighterMakeSelectableP7Fighterb
	addq.l #8,%sp
	pea -380(%fp)
	jsr __Z11fighterShowP7Fighter
	move.l sprite,%a0
	move.w #137,200(%a0)
	move.w #123,204(%a0)
	move.l __ZL8p1Cursor,%d0
	addq.l #4,%sp
	moveq #6,%d1
	cmp.l %d0,%d1
	jcc .L38
.L21:
	pea 1.w
	jsr (%a2)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_STAR,%d1
	addq.l #4,%sp
	jne .L39
.L30:
	and.l JAGPAD_HASH,%d0
	jne .L40
	move.l %d3,%a0
	jsr (%a0)
	clr.l -(%sp)
	jsr (%a5)
	addq.l #4,%sp
.L43:
	move.w raptor_ticks,%a3
	move.l %a3,%d0
	sub.l __ZL9lastTicks,%d0
	move.l %d0,-(%sp)
	jsr (%a4)
	move.l %d0,%d2
	move.l __ZL11ticksPerSec,(%sp)
	jsr (%a4)
	move.l %d0,(%sp)
	move.l %d2,-(%sp)
	move.l %d4,%a0
	jsr (%a0)
	addq.l #8,%sp
	move.l %d0,%d2
	move.l %a3,__ZL9lastTicks
	pea 1.w
	jsr (%a2)
	move.l %d0,__ZL4pad1
	moveq #1,%d1
	move.l %d1,(%sp)
	jsr (%a2)
	move.l %d0,__ZL4pad2
	move.l __ZL4pad1,%d0
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	addq.l #4,%sp
	jne .L41
.L3:
	move.l %d0,%d1
	and.l JAGPAD_RIGHT,%d1
	jeq .L6
	move.l __ZL8p1Cursor,%d0
	addq.l #1,%d0
	move.l %d0,__ZL8p1Cursor
	moveq #4,%d1
	cmp.l %d0,%d1
	jeq .L42
	moveq #7,%d1
	cmp.l %d0,%d1
	jne .L5
.L34:
	moveq #4,%d0
	move.l %d0,__ZL8p1Cursor
	jra .L5
.L27:
	pea -1280(%fp)
	pea -120(%fp)
	pea -380(%fp)
	move.l %d2,-(%sp)
	move.l %d7,%a0
	jsr (%a0)
	lea (16,%sp),%sp
	pea 1.w
	jsr (%a2)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_STAR,%d1
	addq.l #4,%sp
	jeq .L30
.L39:
	move.l sprite,%a0
	moveq #1,%d0
	move.l %d0,4228(%a0)
	move.l %d0,4420(%a0)
	move.l %d0,4612(%a0)
	move.l %d0,4804(%a0)
	move.l %d0,4996(%a0)
	move.l %d0,5188(%a0)
	pea 1.w
	move.l %d6,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d3,%a0
	jsr (%a0)
	clr.l -(%sp)
	jsr (%a5)
	addq.l #4,%sp
	jra .L43
.L40:
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,4228(%a0)
	move.l %d0,4420(%a0)
	move.l %d0,4612(%a0)
	move.l %d0,4804(%a0)
	move.l %d0,4996(%a0)
	move.l %d0,5188(%a0)
	clr.l -(%sp)
	move.l %d6,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d3,%a0
	jsr (%a0)
	clr.l -(%sp)
	jsr (%a5)
	addq.l #4,%sp
	jra .L43
.L26:
	pea -1480(%fp)
	pea -100(%fp)
	pea -320(%fp)
	move.l %d2,-(%sp)
	move.l %d7,%a0
	jsr (%a0)
	lea (16,%sp),%sp
	jra .L21
.L25:
	pea -980(%fp)
	pea -60(%fp)
	pea -200(%fp)
	move.l %d2,-(%sp)
	move.l %d7,%a0
	jsr (%a0)
	lea (16,%sp),%sp
	jra .L21
.L24:
	pea -1720(%fp)
	pea -80(%fp)
	pea -260(%fp)
	move.l %d2,-(%sp)
	move.l %d7,%a0
	jsr (%a0)
	lea (16,%sp),%sp
	jra .L21
.L23:
	pea -700(%fp)
	pea -20(%fp)
	pea -500(%fp)
	move.l %d2,-(%sp)
	move.l %d7,%a0
	jsr (%a0)
	lea (16,%sp),%sp
	jra .L21
.L22:
	pea -1120(%fp)
	pea -140(%fp)
	pea -440(%fp)
	move.l %d2,-(%sp)
	move.l %d7,%a0
	jsr (%a0)
	lea (16,%sp),%sp
	jra .L21
.L28:
	pea -840(%fp)
	pea -40(%fp)
	pea -560(%fp)
	move.l %d2,-(%sp)
	move.l %d7,%a0
	jsr (%a0)
	lea (16,%sp),%sp
	jra .L21
.L17:
	pea 16.w
	pea 14.w
	move.l #10339312,-(%sp)
	jsr jsfLoadClut
	addq.l #8,%sp
	moveq #1,%d0
	move.l %d0,(%sp)
	pea -320(%fp)
	jsr __Z21fighterMakeSelectableP7Fighterb
	addq.l #8,%sp
	pea -320(%fp)
	jsr __Z11fighterShowP7Fighter
	move.l sprite,%a0
	move.w #73,200(%a0)
	move.w #123,204(%a0)
	move.l __ZL8p1Cursor,%d0
	addq.l #4,%sp
	jra .L11
.L16:
	pea 16.w
	pea 14.w
	move.l #11387952,-(%sp)
	jsr jsfLoadClut
	addq.l #8,%sp
	moveq #1,%d1
	move.l %d1,(%sp)
	pea -200(%fp)
	jsr __Z21fighterMakeSelectableP7Fighterb
	addq.l #8,%sp
	pea -200(%fp)
	jsr __Z11fighterShowP7Fighter
	move.l sprite,%a0
	move.w #265,200(%a0)
	move.w #43,204(%a0)
	move.l __ZL8p1Cursor,%d0
	addq.l #4,%sp
	jra .L11
.L15:
	pea 16.w
	pea 14.w
	move.l #10863632,-(%sp)
	jsr jsfLoadClut
	addq.l #8,%sp
	moveq #1,%d0
	move.l %d0,(%sp)
	pea -260(%fp)
	jsr __Z21fighterMakeSelectableP7Fighterb
	addq.l #8,%sp
	pea -260(%fp)
	jsr __Z11fighterShowP7Fighter
	move.l sprite,%a0
	move.w #201,200(%a0)
	move.w #43,204(%a0)
	move.l __ZL8p1Cursor,%d0
	addq.l #4,%sp
	jra .L11
.L19:
	pea 16.w
	pea 14.w
	move.l #11912272,-(%sp)
	jsr jsfLoadClut
	addq.l #8,%sp
	moveq #1,%d0
	move.l %d0,(%sp)
	pea -560(%fp)
	jsr __Z21fighterMakeSelectableP7Fighterb
	addq.l #8,%sp
	pea -560(%fp)
	jsr __Z11fighterShowP7Fighter
	move.l sprite,%a0
	move.w #201,200(%a0)
	move.w #123,204(%a0)
	move.l __ZL8p1Cursor,%d0
	addq.l #4,%sp
	jra .L11
.L14:
	pea 16.w
	pea 14.w
	move.l #12436592,-(%sp)
	jsr jsfLoadClut
	addq.l #8,%sp
	moveq #1,%d1
	move.l %d1,(%sp)
	pea -500(%fp)
	jsr __Z21fighterMakeSelectableP7Fighterb
	addq.l #8,%sp
	pea -500(%fp)
	jsr __Z11fighterShowP7Fighter
	move.l sprite,%a0
	move.w #73,200(%a0)
	move.w #43,204(%a0)
	move.l __ZL8p1Cursor,%d0
	addq.l #4,%sp
	jra .L11
.L13:
	pea 16.w
	pea 14.w
	move.l #9290672,-(%sp)
	jsr jsfLoadClut
	addq.l #8,%sp
	moveq #1,%d0
	move.l %d0,(%sp)
	pea -440(%fp)
	jsr __Z21fighterMakeSelectableP7Fighterb
	addq.l #8,%sp
	pea -440(%fp)
	jsr __Z11fighterShowP7Fighter
	move.l sprite,%a0
	move.w #12,200(%a0)
	move.w #43,204(%a0)
	move.l __ZL8p1Cursor,%d0
	addq.l #4,%sp
	jra .L11
.L6:
	move.l %d0,%d1
	and.l JAGPAD_UP,%d1
	jeq .L8
	move.l __ZL8p1Cursor,%d0
	moveq #4,%d1
	cmp.l %d0,%d1
	jeq .L44
	moveq #6,%d1
	cmp.l %d0,%d1
	jne .L5
	moveq #2,%d0
	move.l %d0,__ZL8p1Cursor
	jra .L5
.L36:
	moveq #3,%d0
	move.l %d0,__ZL8p1Cursor
	jra .L5
.L8:
	and.l JAGPAD_DOWN,%d0
	jne .L10
	move.l __ZL8p1Cursor,%d0
	jra .L11
.L42:
	clr.l __ZL8p1Cursor
	jra .L5
.L44:
	moveq #1,%d0
	move.l %d0,__ZL8p1Cursor
	jra .L5
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
	.even
__ZL11ticksPerSec:
	.long	60
.lcomm __ZL9lastTicks,4
	.even
__ZL8p1Cursor:
	.long	1
