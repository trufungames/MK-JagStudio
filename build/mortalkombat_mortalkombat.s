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
	movem.l #15932,-(%sp)
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
	addq.l #8,%sp
	lea jsfGetPad,%a5
	move.l #__Z6moveUpv,%d4
	move.l #__Z8moveDownv,%d6
	move.l #__Z8moveLeftv,%d3
	move.l #__Z9moveRightv,%d5
	lea jsfGetPadPressed,%a4
	move.l #rapDebugSetVisible,%d2
	lea rapDebugUpdate,%a3
	lea _jsfVsync,%a2
	pea 1.w
	jsr (%a5)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_UP,%d1
	addq.l #4,%sp
	jne .L10
.L2:
	move.l %d0,%d1
	and.l JAGPAD_DOWN,%d1
	jne .L11
.L3:
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jne .L12
.L4:
	and.l JAGPAD_RIGHT,%d0
	jne .L13
.L5:
	pea 1.w
	jsr (%a4)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_STAR,%d1
	addq.l #4,%sp
	jne .L14
.L6:
	and.l JAGPAD_HASH,%d0
	jne .L15
	jsr (%a3)
	clr.l -(%sp)
	jsr (%a2)
	addq.l #4,%sp
.L16:
	pea 1.w
	jsr (%a5)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_UP,%d1
	addq.l #4,%sp
	jeq .L2
.L10:
	move.l %d4,%a0
	jsr (%a0)
	move.l __ZL4pad1,%d0
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	jeq .L4
.L12:
	move.l %d3,%a0
	jsr (%a0)
	pea 1.w
	jsr (%a4)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_STAR,%d1
	addq.l #4,%sp
	jeq .L6
.L14:
	move.l sprite,%a0
	moveq #1,%d0
	move.l %d0,3624(%a0)
	pea 1.w
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	jsr (%a3)
	clr.l -(%sp)
	jsr (%a2)
	addq.l #4,%sp
	jra .L16
.L15:
	move.l sprite,%a0
	clr.l 3624(%a0)
	clr.l -(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	jsr (%a3)
	clr.l -(%sp)
	jsr (%a2)
	addq.l #4,%sp
	jra .L16
.L13:
	move.l %d5,%a0
	jsr (%a0)
	jra .L5
.L11:
	move.l %d6,%a0
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
