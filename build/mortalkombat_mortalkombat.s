#NO_APP
	.text
	.even
	.globl	__Z9basicmainv
__Z9basicmainv:
	link.w %fp,#0
	movem.l #14396,-(%sp)
	clr.l __ZL4pad1
	move.w #-20673,15728728
	pea 20.w
	pea 5.w
	jsr rapDebugSetXY
	addq.l #8,%sp
	jsr RAPTOR_console_inverse
	lea jsfGetPad,%a5
	move.l #__Z8moveLeftv,%d3
	move.l #__Z9moveRightv,%d4
	lea jsfGetPadPressed,%a4
	move.l #rapDebugSetVisible,%d2
	lea rapDebugUpdate,%a3
	lea _jsfVsync,%a2
	pea 1.w
	jsr (%a5)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	addq.l #4,%sp
	jne .L8
.L2:
	and.l JAGPAD_RIGHT,%d0
	jne .L9
.L3:
	pea 1.w
	jsr (%a4)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_STAR,%d1
	addq.l #4,%sp
	jne .L10
.L4:
	and.l JAGPAD_HASH,%d0
	jne .L11
	jsr (%a3)
	clr.l -(%sp)
	jsr (%a2)
	addq.l #4,%sp
.L12:
	pea 1.w
	jsr (%a5)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_LEFT,%d1
	addq.l #4,%sp
	jeq .L2
.L8:
	move.l %d3,%a0
	jsr (%a0)
	pea 1.w
	jsr (%a4)
	move.l %d0,__ZL4pad1
	move.l %d0,%d1
	and.l JAGPAD_STAR,%d1
	addq.l #4,%sp
	jeq .L4
.L10:
	move.l sprite,%a0
	moveq #1,%d0
	move.l %d0,3076(%a0)
	move.l %d0,3268(%a0)
	move.l %d0,3460(%a0)
	move.l %d0,3652(%a0)
	move.l %d0,3844(%a0)
	move.l %d0,4036(%a0)
	pea 1.w
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	jsr (%a3)
	clr.l -(%sp)
	jsr (%a2)
	addq.l #4,%sp
	jra .L12
.L11:
	move.l sprite,%a0
	moveq #-1,%d0
	move.l %d0,3076(%a0)
	move.l %d0,3268(%a0)
	move.l %d0,3460(%a0)
	move.l %d0,3652(%a0)
	move.l %d0,3844(%a0)
	move.l %d0,4036(%a0)
	clr.l -(%sp)
	move.l %d2,%a0
	jsr (%a0)
	addq.l #4,%sp
	jsr (%a3)
	clr.l -(%sp)
	jsr (%a2)
	addq.l #4,%sp
	jra .L12
.L9:
	move.l %d4,%a0
	jsr (%a0)
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
