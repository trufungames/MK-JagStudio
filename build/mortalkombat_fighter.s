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
	.globl	__Z17fighterInitializeP7FighterbP12SoundHandler
__Z17fighterInitializeP7FighterbP12SoundHandler:
	link.w %fp,#0
	move.l 8(%fp),%a0
	move.l 12(%fp),%d1
	move.l 16(%fp),88(%a0)
	clr.l 64(%a0)
	moveq #2,%d0
	move.l %d0,72(%a0)
	move.l %d0,76(%a0)
	clr.b 44(%a0)
	clr.b 45(%a0)
	clr.b 46(%a0)
	clr.b 47(%a0)
	clr.b 48(%a0)
	clr.b 49(%a0)
	clr.b 50(%a0)
	move.b #1,51(%a0)
	move.b %d1,96(%a0)
	move.l (%a0),%d0
	move.l %d0,%a1
	add.l %d0,%a1
	add.l %a1,%d0
	lsl.l #6,%d0
	move.l sprite,%a1
	add.l %d0,%a1
	moveq #1,%d0
	move.l %d0,4(%a1)
	tst.b %d1
	jne .L15
	moveq #44,%d0
	move.l %d0,60(%a0)
	move.b #42,%d0
	move.l %d0,52(%a0)
	move.b #43,%d0
	move.l %d0,56(%a0)
	move.b #2,%d0
	move.l %d0,68(%a0)
	move.w #210,8(%a1)
	moveq #-1,%d0
	move.l %d0,92(%a0)
	unlk %fp
	rts
.L15:
	move.b #41,%d0
	move.l %d0,60(%a0)
	move.b #39,%d0
	move.l %d0,52(%a0)
	move.b #40,%d0
	move.l %d0,56(%a0)
	move.b #1,%d0
	move.l %d0,68(%a0)
	move.w #50,8(%a1)
	move.l %d0,92(%a0)
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
	.globl	__Z13fighterUpdatefP7FighterP14SpriteAnimatorP14AnimationFrameS4_S4_S4_S4_S4_S4_S4_S4_b
__Z13fighterUpdatefP7FighterP14SpriteAnimatorP14AnimationFrameS4_S4_S4_S4_S4_S4_S4_S4_b:
	link.w %fp,#0
	movem.l #15420,-(%sp)
	move.l 12(%fp),%a2
	move.l 16(%fp),%a3
	move.b 59(%fp),%d2
	move.l 68(%a2),-(%sp)
	jsr jsfGetPad
	move.l %d0,64(%a2)
	move.l %d0,%d1
	and.l JAGPAD_C,%d1
	addq.l #4,%sp
	jeq .L19
	tst.b 51(%a2)
	jeq .L19
	tst.b 47(%a2)
	jne .L21
	clr.b 51(%a2)
	move.b #1,47(%a2)
	clr.l 16(%a3)
	moveq #0,%d2
	move.b 96(%a2),%d2
	move.l 88(%a2),%d1
	move.l (%a2),%d0
	moveq #29,%d3
	cmp.l %d0,%d3
	jeq .L25
	move.b #30,%d3
	cmp.l %d0,%d3
	jeq .L26
	move.b #26,%d3
	cmp.l %d0,%d3
	jeq .L78
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z11sfxHiyaMaleP12SoundHandlerb
	addq.l #8,%sp
.L21:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 28(%a2),-(%sp)
	move.l 40(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 28(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jne .L79
.L27:
	move.l 64(%a2),%d0
	move.l %d0,%d1
	and.l JAGPAD_C,%d1
	jne .L18
	move.l %d0,%d1
	and.l JAGPAD_9,%d1
	jne .L18
	move.l %d0,%d1
	and.l JAGPAD_A,%d1
	jne .L18
	and.l JAGPAD_7,%d0
	jne .L18
	move.b #1,51(%a2)
.L18:
	movem.l -32(%fp),#15420
	unlk %fp
	rts
.L19:
	tst.b 47(%a2)
	jne .L21
	move.l %d0,%d1
	and.l JAGPAD_9,%d1
	jeq .L28
	tst.b 51(%a2)
	jeq .L28
	tst.b 48(%a2)
	jne .L30
	clr.b 51(%a2)
	move.b #1,48(%a2)
	clr.l 16(%a3)
	moveq #0,%d2
	move.b 96(%a2),%d2
	move.l 88(%a2),%d1
	move.l (%a2),%d0
	moveq #29,%d3
	cmp.l %d0,%d3
	jeq .L34
	move.b #30,%d3
	cmp.l %d0,%d3
	jeq .L35
	move.b #26,%d3
	cmp.l %d0,%d3
	jeq .L80
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z11sfxHiyaMaleP12SoundHandlerb
	addq.l #8,%sp
.L30:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 32(%a2),-(%sp)
	move.l 44(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 32(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
.L83:
	clr.b 48(%a2)
	jra .L27
.L79:
	clr.b 47(%a2)
	jra .L27
.L28:
	tst.b 48(%a2)
	jne .L30
	move.l %d0,%d1
	and.l JAGPAD_A,%d1
	jeq .L36
	tst.b 51(%a2)
	jeq .L36
	tst.b 49(%a2)
	jne .L38
	clr.b 51(%a2)
	move.b #1,49(%a2)
	clr.l 16(%a3)
	moveq #0,%d2
	move.b 96(%a2),%d2
	move.l 88(%a2),%d1
	move.l (%a2),%d0
	moveq #29,%d3
	cmp.l %d0,%d3
	jeq .L42
	move.b #30,%d3
	cmp.l %d0,%d3
	jeq .L43
	move.b #26,%d3
	cmp.l %d0,%d3
	jeq .L81
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z11sfxHiyaMaleP12SoundHandlerb
	addq.l #8,%sp
.L38:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 36(%a2),-(%sp)
	move.l 48(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 36(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
.L86:
	clr.b 49(%a2)
	jra .L27
.L36:
	tst.b 49(%a2)
	jne .L38
	move.l %d0,%d1
	and.l JAGPAD_7,%d1
	jeq .L44
	tst.b 51(%a2)
	jeq .L44
	tst.b 50(%a2)
	jne .L46
	clr.b 51(%a2)
	move.b #1,50(%a2)
	clr.l 16(%a3)
	moveq #0,%d2
	move.b 96(%a2),%d2
	move.l 88(%a2),%d1
	move.l (%a2),%d0
	moveq #29,%d3
	cmp.l %d0,%d3
	jeq .L50
	move.b #30,%d3
	cmp.l %d0,%d3
	jeq .L51
	move.b #26,%d3
	cmp.l %d0,%d3
	jeq .L82
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z11sfxHiyaMaleP12SoundHandlerb
	addq.l #8,%sp
.L46:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 40(%a2),-(%sp)
	move.l 52(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 40(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
	clr.b 50(%a2)
	jra .L27
.L44:
	tst.b 50(%a2)
	jne .L46
	move.l %d0,%d1
	and.l JAGPAD_B,%d1
	jeq .L52
	tst.b 46(%a2)
	jne .L53
	move.b #1,46(%a2)
	clr.l 16(%a3)
.L53:
	and.l JAGPAD_DOWN,%d0
	jeq .L54
	tst.b 45(%a2)
	jne .L55
	move.b #1,45(%a2)
	clr.l 16(%a3)
.L55:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 24(%a2),-(%sp)
	move.l 36(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (32,%sp),%sp
	jra .L27
.L25:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z12sfxHiyaNinjaP12SoundHandlerb
	addq.l #8,%sp
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 28(%a2),-(%sp)
	move.l 40(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 28(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
	jra .L79
.L26:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z13sfxHiyaFemaleP12SoundHandlerb
	addq.l #8,%sp
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 28(%a2),-(%sp)
	move.l 40(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 28(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
	jra .L79
.L34:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z12sfxHiyaNinjaP12SoundHandlerb
	addq.l #8,%sp
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 32(%a2),-(%sp)
	move.l 44(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 32(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
	jra .L83
.L78:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z11sfxHiyaKangP12SoundHandlerb
	addq.l #8,%sp
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 28(%a2),-(%sp)
	move.l 40(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 28(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
	jra .L79
.L52:
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jne .L84
	move.l %d0,%d1
	and.l JAGPAD_RIGHT,%d1
	jne .L85
	and.l JAGPAD_DOWN,%d0
	jeq .L63
	tst.b 45(%a2)
	jne .L64
	move.b #1,45(%a2)
	clr.l 16(%a3)
.L64:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 16(%a2),-(%sp)
	move.l 28(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	move.l 52(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	moveq #-1,%d1
	move.l %d1,4(%a0,%d0.l)
	lea (32,%sp),%sp
	jra .L27
.L80:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z11sfxHiyaKangP12SoundHandlerb
	addq.l #8,%sp
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 32(%a2),-(%sp)
	move.l 44(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 32(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
	jra .L83
.L35:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z13sfxHiyaFemaleP12SoundHandlerb
	addq.l #8,%sp
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 32(%a2),-(%sp)
	move.l 44(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 32(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
	jra .L83
.L54:
	tst.b 45(%a2)
	jeq .L56
	clr.b 45(%a2)
.L56:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 20(%a2),-(%sp)
	move.l 32(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (32,%sp),%sp
	jra .L27
.L81:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z11sfxHiyaKangP12SoundHandlerb
	addq.l #8,%sp
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 36(%a2),-(%sp)
	move.l 48(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 36(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
	jra .L86
.L43:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z13sfxHiyaFemaleP12SoundHandlerb
	addq.l #8,%sp
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 36(%a2),-(%sp)
	move.l 48(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 36(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
	jra .L86
.L42:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z12sfxHiyaNinjaP12SoundHandlerb
	addq.l #8,%sp
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	pea 1.w
	move.l 36(%a2),-(%sp)
	move.l 48(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (28,%sp),%sp
	move.l 36(%a2),(%sp)
	move.l %a3,-(%sp)
	jsr __Z19animationIsCompleteP14SpriteAnimatori
	addq.l #8,%sp
	tst.b %d0
	jeq .L27
	jra .L86
.L84:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	pea 1.w
	and.l #255,%d2
	move.l %d2,-(%sp)
	move.l 12(%a2),-(%sp)
	move.l 24(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	move.b #1,44(%a2)
	clr.b 45(%a2)
	clr.b 46(%a2)
	clr.b 47(%a2)
	clr.b 48(%a2)
	move.l sprite,%d4
	move.l (%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l %d4,%a4
	add.l %d0,%a4
	move.w 8(%a4),%d2
	lea (32,%sp),%sp
	jle .L58
	lea ___floatsisf,%a3
	move.l 76(%a2),-(%sp)
	jsr (%a3)
	move.l %d0,(%sp)
	move.l 8(%fp),-(%sp)
	jsr ___mulsf3
	addq.l #8,%sp
	move.l %d0,%d3
	move.w %d2,%a0
	move.l %a0,-(%sp)
	jsr (%a3)
	move.l #___subsf3,%d2
	move.l %d3,(%sp)
	move.l %d0,-(%sp)
	move.l %d2,%a1
	jsr (%a1)
	addq.l #8,%sp
	lea ___fixsfsi,%a5
	move.l %d0,-(%sp)
	jsr (%a5)
	move.w %d0,8(%a4)
	move.l 52(%a2),%d0
	move.l %d0,%d5
	add.l %d0,%d5
	add.l %d0,%d5
	lsl.l #6,%d5
	add.l %d4,%d5
	move.l %d5,%a0
	move.w 8(%a0),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d3,(%sp)
	move.l %d0,-(%sp)
	move.l %d2,%a1
	jsr (%a1)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	move.l %d5,%a0
	move.w %d0,8(%a0)
	move.l 56(%a2),%d0
	move.l %d0,%d5
	add.l %d0,%d5
	add.l %d0,%d5
	lsl.l #6,%d5
	add.l %d4,%d5
	move.l %d5,%a1
	move.w 8(%a1),%a1
	move.l %a1,(%sp)
	jsr (%a3)
	move.l %d3,(%sp)
	move.l %d0,-(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	move.l %d5,%a1
	move.w %d0,8(%a1)
	move.l 60(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	add.l %d0,%d4
	move.l %d4,%a0
	move.w 8(%a0),%a0
	move.l %a0,(%sp)
	jsr (%a3)
	move.l %d3,(%sp)
	move.l %d0,-(%sp)
	move.l %d2,%a1
	jsr (%a1)
	addq.l #4,%sp
	move.l %d0,(%sp)
	jsr (%a5)
	addq.l #4,%sp
	move.l %d4,%a0
	move.w %d0,8(%a0)
	move.w 8(%a4),%a1
	move.l %a1,80(%a2)
	move.w 12(%a4),%a4
	move.l %a4,84(%a2)
	jra .L27
.L63:
	tst.b 45(%a2)
	jne .L87
	tst.b 46(%a2)
	jne .L88
	tst.b 44(%a2)
	jeq .L67
	clr.b 44(%a2)
	clr.l 16(%a3)
.L67:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	pea 1.w
	pea 1.w
	move.l 8(%a2),-(%sp)
	move.l 20(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	move.l (%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l sprite,%a0
	add.l %d0,%a0
	move.w 8(%a0),%a1
	move.l %a1,80(%a2)
	move.w 12(%a0),%a0
	move.l %a0,84(%a2)
	lea (32,%sp),%sp
	jra .L27
.L85:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	pea 1.w
	eor.b #1,%d2
	moveq #0,%d0
	move.b %d2,%d0
	move.l %d0,-(%sp)
	move.l 12(%a2),-(%sp)
	move.l 24(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	move.b #1,44(%a2)
	clr.b 45(%a2)
	clr.b 46(%a2)
	clr.b 47(%a2)
	clr.b 48(%a2)
	move.l sprite,%a4
	move.l (%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	lea (%a4,%d0.l),%a3
	move.w 8(%a3),%d2
	lea (32,%sp),%sp
	cmp.w #259,%d2
	jgt .L61
	lea ___floatsisf,%a5
	move.l 72(%a2),-(%sp)
	jsr (%a5)
	move.l %d0,(%sp)
	move.l 8(%fp),-(%sp)
	jsr ___mulsf3
	addq.l #8,%sp
	move.l %d0,%d4
	move.w %d2,%a0
	move.l %a0,-(%sp)
	jsr (%a5)
	move.l #___addsf3,%d3
	move.l %d0,(%sp)
	move.l %d4,-(%sp)
	move.l %d3,%a1
	jsr (%a1)
	addq.l #8,%sp
	move.l #___fixsfsi,%d2
	move.l %d0,-(%sp)
	move.l %d2,%a0
	jsr (%a0)
	move.w %d0,8(%a3)
	move.l 52(%a2),%d0
	move.l %d0,%d5
	add.l %d0,%d5
	add.l %d0,%d5
	lsl.l #6,%d5
	add.l %a4,%d5
	move.l %d5,%a1
	move.w 8(%a1),%a1
	move.l %a1,(%sp)
	jsr (%a5)
	move.l %d0,(%sp)
	move.l %d4,-(%sp)
	move.l %d3,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d2,%a1
	jsr (%a1)
	move.l %d5,%a0
	move.w %d0,8(%a0)
	move.l 56(%a2),%d0
	move.l %d0,%d5
	add.l %d0,%d5
	add.l %d0,%d5
	lsl.l #6,%d5
	add.l %a4,%d5
	move.l %d5,%a1
	move.w 8(%a1),%a1
	move.l %a1,(%sp)
	jsr (%a5)
	move.l %d0,(%sp)
	move.l %d4,-(%sp)
	move.l %d3,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d2,%a1
	jsr (%a1)
	move.l %d5,%a0
	move.w %d0,8(%a0)
	move.l 60(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	add.l %d0,%a4
	move.w 8(%a4),%a1
	move.l %a1,(%sp)
	jsr (%a5)
	move.l %d0,(%sp)
	move.l %d4,-(%sp)
	move.l %d3,%a0
	jsr (%a0)
	addq.l #4,%sp
	move.l %d0,(%sp)
	move.l %d2,%a1
	jsr (%a1)
	addq.l #4,%sp
	move.w %d0,8(%a4)
	move.w 8(%a3),%a0
	move.l %a0,80(%a2)
	move.w 12(%a3),%a3
	move.l %a3,84(%a2)
	jra .L27
.L82:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z11sfxHiyaKangP12SoundHandlerb
	addq.l #8,%sp
	jra .L46
.L51:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z13sfxHiyaFemaleP12SoundHandlerb
	addq.l #8,%sp
	jra .L46
.L50:
	move.l %d2,-(%sp)
	move.l %d1,-(%sp)
	jsr __Z12sfxHiyaNinjaP12SoundHandlerb
	addq.l #8,%sp
	jra .L46
.L87:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	clr.l -(%sp)
	move.l 16(%a2),-(%sp)
	move.l 28(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (32,%sp),%sp
	tst.l 16(%a3)
	jne .L27
	clr.b 45(%a2)
	move.l sprite,%a0
	move.l 56(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	moveq #1,%d3
	cmp.l 4(%a0,%d0.l),%d3
	jne .L27
	move.l 52(%a2),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	move.l %d3,4(%a0,%d0.l)
	jra .L27
.L61:
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
	move.w 8(%a3),%a0
	move.l %a0,80(%a2)
	move.w 12(%a3),%a3
	move.l %a3,84(%a2)
	jra .L27
.L88:
	move.l 92(%a2),-(%sp)
	move.l 84(%a2),-(%sp)
	move.l 80(%a2),-(%sp)
	clr.l -(%sp)
	clr.l -(%sp)
	move.l 20(%a2),-(%sp)
	move.l 32(%fp),-(%sp)
	move.l %a3,-(%sp)
	jsr __Z20updateSpriteAnimatorP14SpriteAnimatorP14AnimationFrameibbiii
	lea (32,%sp),%sp
	tst.l 16(%a3)
	jne .L27
	clr.b 46(%a2)
	jra .L27
.L58:
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
	move.w 8(%a4),%a1
	move.l %a1,80(%a2)
	move.w 12(%a4),%a4
	move.l %a4,84(%a2)
	jra .L27
	.even
	.globl	__Z15fighterPlayHiyaiP12SoundHandlerb
__Z15fighterPlayHiyaiP12SoundHandlerb:
	link.w %fp,#0
	move.l %d3,-(%sp)
	move.l %d2,-(%sp)
	move.l 8(%fp),%d0
	move.l 12(%fp),%d1
	move.b 19(%fp),%d2
	moveq #29,%d3
	cmp.l %d0,%d3
	jeq .L93
	move.b #30,%d3
	cmp.l %d0,%d3
	jeq .L94
	move.b #26,%d3
	cmp.l %d0,%d3
	jeq .L97
	and.l #255,%d2
	move.l %d2,12(%fp)
	move.l %d1,8(%fp)
	move.l (%sp)+,%d2
	move.l (%sp)+,%d3
	unlk %fp
	jra __Z11sfxHiyaMaleP12SoundHandlerb
.L97:
	and.l #255,%d2
	move.l %d2,12(%fp)
	move.l %d1,8(%fp)
	move.l (%sp)+,%d2
	move.l (%sp)+,%d3
	unlk %fp
	jra __Z11sfxHiyaKangP12SoundHandlerb
.L94:
	and.l #255,%d2
	move.l %d2,12(%fp)
	move.l %d1,8(%fp)
	move.l (%sp)+,%d2
	move.l (%sp)+,%d3
	unlk %fp
	jra __Z13sfxHiyaFemaleP12SoundHandlerb
.L93:
	and.l #255,%d2
	move.l %d2,12(%fp)
	move.l %d1,8(%fp)
	move.l (%sp)+,%d2
	move.l (%sp)+,%d3
	unlk %fp
	jra __Z12sfxHiyaNinjaP12SoundHandlerb
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
