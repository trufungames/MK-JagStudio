#NO_APP
	.text
	.even
	.globl	__Z6moveUpv
__Z6moveUpv:
	link.w %fp,#0
	move.l sprite,%a0
	subq.w #2,204(%a0)
	unlk %fp
	rts
	.even
	.globl	__Z8moveDownv
__Z8moveDownv:
	link.w %fp,#0
	move.l sprite,%a0
	addq.w #2,204(%a0)
	unlk %fp
	rts
	.even
	.globl	__Z9moveRightv
__Z9moveRightv:
	link.w %fp,#0
	move.l sprite,%a0
	addq.w #2,200(%a0)
	unlk %fp
	rts
	.even
	.globl	__Z8moveLeftv
__Z8moveLeftv:
	link.w %fp,#0
	move.l sprite,%a0
	subq.w #2,200(%a0)
	unlk %fp
	rts
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
