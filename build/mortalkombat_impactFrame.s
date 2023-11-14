#NO_APP
	.text
	.even
	.globl	__Z16impactFrameResetP7Fighter
__Z16impactFrameResetP7Fighter:
	link.w %fp,#0
	move.l 8(%fp),%a0
	move.l sprite,%a1
	tst.b 112(%a0)
	jne .L5
	move.w 98(%a0),%d0
	add.w #30,%d0
	move.w %d0,8456(%a1)
	move.w 102(%a0),%a0
	lea (200,%a0),%a0
	move.w %a0,8460(%a1)
	unlk %fp
	rts
.L5:
	move.w 98(%a0),%d0
	add.w #30,%d0
	move.w %d0,7880(%a1)
	move.w 102(%a0),%a0
	lea (200,%a0),%a0
	move.w %a0,7884(%a1)
	unlk %fp
	rts
	.even
	.globl	__Z17impactFrameUpdateP14SpriteAnimatorP7FighterP11ImpactFrame
__Z17impactFrameUpdateP14SpriteAnimatorP7FighterP11ImpactFrame:
	link.w %fp,#0
	move.l %a3,-(%sp)
	move.l %a2,-(%sp)
	move.l 12(%fp),%a0
	move.l 16(%fp),%a1
	move.l 8(%fp),%a2
	move.l 16(%a2),%a2
	cmp.l (%a1),%a2
	jeq .L13
	move.l sprite,%a1
	tst.b 112(%a0)
	jne .L14
	move.w 98(%a0),%d0
	add.w #30,%d0
	move.w %d0,8456(%a1)
	move.w 102(%a0),%a0
	lea (200,%a0),%a0
	move.w %a0,8460(%a1)
	move.l (%sp)+,%a2
	move.l (%sp)+,%a3
	unlk %fp
	rts
.L13:
	move.l sprite,%a2
	tst.b 112(%a0)
	jeq .L9
	move.l (%a0),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	lea (%a2,%d0.l),%a3
	move.w 110(%a0),%d0
	move.w %d0,%d1
	muls.w 6(%a1),%d1
	add.w 8(%a3),%d1
	move.w %d1,7880(%a2)
	muls.w 10(%a1),%d0
	add.w 12(%a3),%d0
	move.w %d0,7884(%a2)
	move.l (%sp)+,%a2
	move.l (%sp)+,%a3
	unlk %fp
	rts
.L9:
	move.l (%a0),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	lea (%a2,%d0.l),%a3
	move.w 110(%a0),%d0
	move.w %d0,%d1
	muls.w 6(%a1),%d1
	add.w 8(%a3),%d1
	move.w %d1,8456(%a2)
	muls.w 10(%a1),%d0
	add.w 12(%a3),%d0
	move.w %d0,8460(%a2)
	move.l (%sp)+,%a2
	move.l (%sp)+,%a3
	unlk %fp
	rts
.L14:
	move.w 98(%a0),%d0
	add.w #30,%d0
	move.w %d0,7880(%a1)
	move.w 102(%a0),%a0
	lea (200,%a0),%a0
	move.w %a0,7884(%a1)
	move.l (%sp)+,%a2
	move.l (%sp)+,%a3
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
