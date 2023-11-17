#NO_APP
	.text
	.even
	.globl	__Z15spriteDelayInitv
__Z15spriteDelayInitv:
	link.w %fp,#0
	moveq #10,%d0
	move.l %d0,_spriteCount
	clr.b _sprites+8
	clr.b _sprites+22
	clr.b _sprites+36
	clr.b _sprites+50
	clr.b _sprites+64
	clr.b _sprites+78
	clr.b _sprites+92
	clr.b _sprites+106
	clr.b _sprites+120
	clr.b _sprites+134
	unlk %fp
	rts
	.even
	.globl	__Z17spriteDelayUpdatev
__Z17spriteDelayUpdatev:
	link.w %fp,#0
	movem.l #12336,-(%sp)
	move.l _spriteCount,%d1
	jle .L2
	move.w raptor_ticks,%a2
	move.l sprite,%a3
	lea _sprites+8,%a0
	moveq #0,%d0
.L5:
	tst.b (%a0)
	jeq .L4
	cmp.l -4(%a0),%a2
	jcs .L4
	clr.b (%a0)
	move.l -8(%a0),%a1
	move.l %a1,%d2
	add.l %a1,%d2
	add.l %a1,%d2
	lsl.l #6,%d2
	moveq #-1,%d3
	move.l %d3,4(%a3,%d2.l)
	move.l 2(%a0),%a1
	clr.b (%a1)
.L4:
	addq.l #1,%d0
	lea (14,%a0),%a0
	cmp.l %d0,%d1
	jgt .L5
.L2:
	movem.l (%sp)+,#3084
	unlk %fp
	rts
	.even
	.globl	__Z22spriteDelaySetInactiveiiPb
__Z22spriteDelaySetInactiveiiPb:
	link.w %fp,#0
	move.l _spriteCount,%d1
	jle .L9
	tst.b _sprites+8
	jeq .L19
	lea _sprites+22,%a0
	moveq #0,%d0
.L13:
	addq.l #1,%d0
	cmp.l %d0,%d1
	jeq .L9
	lea (14,%a0),%a0
	tst.b -14(%a0)
	jne .L13
	add.l %d0,%d0
	move.l %d0,%d1
	lsl.l #3,%d1
	sub.l %d0,%d1
	lea _sprites,%a0
	move.l 8(%fp),(%a0,%d1.l)
	move.l %d1,%a0
	add.l #_sprites,%a0
	move.l 12(%fp),4(%a0)
	lea _sprites+8,%a1
	move.b #1,(%a1,%d1.l)
	move.l 16(%fp),10(%a0)
.L9:
	unlk %fp
	rts
.L19:
	moveq #0,%d0
	add.l %d0,%d0
	move.l %d0,%d1
	lsl.l #3,%d1
	sub.l %d0,%d1
	lea _sprites,%a0
	move.l 8(%fp),(%a0,%d1.l)
	move.l %d1,%a0
	add.l #_sprites,%a0
	move.l 12(%fp),4(%a0)
	lea _sprites+8,%a1
	move.b #1,(%a1,%d1.l)
	move.l 16(%fp),10(%a0)
	jra .L9
	.globl	_spriteCount
	.bss
	.even
_spriteCount:
	.skip 4
	.globl	_sprites
	.even
_sprites:
	.skip 140
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
