#NO_APP
	.text
.LC0:
	.ascii "        JagStudio C Template\0"
.LC1:
	.ascii "DPAD to Move\0"
.LC2:
	.ascii "B to Make a Sound\0"
	.even
	.globl	__Z9basicmainv
__Z9basicmainv:
	link.w %fp,#0
	movem.l #15420,-(%sp)
	clr.l __ZL4pad1
	moveq #1,%d0
	move.l %d0,_jsfFontIndx
	move.l %d0,_jsfFontSize
	pea 20.w
	clr.l -(%sp)
	lea rapLocate,%a3
	jsr (%a3)
	move.l #.LC0,_js_r_textbuffer
	addq.l #8,%sp
	lea _rapPrint,%a2
	jsr (%a2)
	clr.l _jsfFontIndx
	clr.l _jsfFontSize
	pea 50.w
	pea 16.w
	jsr (%a3)
	move.l #.LC1,_js_r_textbuffer
	addq.l #8,%sp
	jsr (%a2)
	pea 60.w
	pea 16.w
	jsr (%a3)
	move.l #.LC2,_js_r_textbuffer
	addq.l #8,%sp
	jsr (%a2)
	move.w #2000,15728728
	lea jsfGetPad,%a4
	move.l #__Z6moveUpv,%d3
	move.l #__Z8moveDownv,%d5
	move.l #__Z8moveLeftv,%d2
	move.l #__Z9moveRightv,%d4
	lea jsfGetPadPressed,%a3
	lea __Z8sfxShootv,%a5
	lea _jsfVsync,%a2
	pea 1.w
	jsr (%a4)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_UP,%d1
	addq.l #4,%sp
	jne .L9
.L2:
	move.l %d0,%d1
	and.l JAGPAD_DOWN,%d1
	jne .L10
.L3:
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jne .L11
.L4:
	and.l JAGPAD_RIGHT,%d0
	jne .L12
	pea 1.w
	jsr (%a3)
	move.l %d0,__ZL4pad1
	and.l JAGPAD_B,%d0
	addq.l #4,%sp
	jne .L13
.L6:
	clr.l -(%sp)
	jsr (%a2)
	addq.l #4,%sp
.L14:
	pea 1.w
	jsr (%a4)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_UP,%d1
	addq.l #4,%sp
	jeq .L2
.L9:
	move.l %d3,%a0
	jsr (%a0)
	move.l __ZL4pad1,%d0
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jeq .L4
.L11:
	move.l %d2,%a0
	jsr (%a0)
	pea 1.w
	jsr (%a3)
	move.l %d0,__ZL4pad1
	and.l JAGPAD_B,%d0
	addq.l #4,%sp
	jeq .L6
.L13:
	jsr (%a5)
	clr.l -(%sp)
	jsr (%a2)
	addq.l #4,%sp
	jra .L14
.L12:
	move.l %d4,%a0
	jsr (%a0)
	pea 1.w
	jsr (%a3)
	move.l %d0,__ZL4pad1
	and.l JAGPAD_B,%d0
	addq.l #4,%sp
	jeq .L6
	jra .L13
.L10:
	move.l %d5,%a0
	jsr (%a0)
	move.l __ZL4pad1,%d0
	jra .L3
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
