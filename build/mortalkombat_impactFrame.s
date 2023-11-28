#NO_APP
	.text
	.even
	.globl	__Z16impactFrameResetP7Fighter
__Z16impactFrameResetP7Fighter:
	link.w %fp,#0
	move.l 8(%fp),%a0
	move.l sprite,%a1
	tst.b 134(%a0)
	jne .L5
	move.w 120(%a0),%d0
	add.w #30,%d0
	move.w %d0,10376(%a1)
	move.w 124(%a0),%a0
	lea (200,%a0),%a0
	move.w %a0,10380(%a1)
	unlk %fp
	rts
.L5:
	move.w 120(%a0),%d0
	add.w #30,%d0
	move.w %d0,9800(%a1)
	move.w 124(%a0),%a0
	lea (200,%a0),%a0
	move.w %a0,9804(%a1)
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
	tst.b 134(%a0)
	jne .L14
	move.w 120(%a0),%d0
	add.w #30,%d0
	move.w %d0,10376(%a1)
	move.w 124(%a0),%a0
	lea (200,%a0),%a0
	move.w %a0,10380(%a1)
	move.l (%sp)+,%a2
	move.l (%sp)+,%a3
	unlk %fp
	rts
.L13:
	move.l sprite,%a2
	tst.b 134(%a0)
	jeq .L9
	move.l (%a0),%d0
	move.l %d0,%d1
	add.l %d0,%d1
	add.l %d1,%d0
	lsl.l #6,%d0
	lea (%a2,%d0.l),%a3
	move.w 132(%a0),%d0
	muls.w 6(%a1),%d0
	add.w 8(%a3),%d0
	move.w %d0,9800(%a2)
	move.w 12(%a3),%a3
	add.w 10(%a1),%a3
	move.w %a3,9804(%a2)
	move.l (%sp)+,%a2
	move.l (%sp)+,%a3
	unlk %fp
	rts
.L9:
	move.l (%a0),%d0
	move.l %d0,%a3
	add.l %d0,%a3
	add.l %a3,%d0
	lsl.l #6,%d0
	lea (%a2,%d0.l),%a3
	move.w 8(%a3),%d1
	add.w 30(%a3),%d1
	moveq #48,%d0
	add.l 4(%a1),%d0
	muls.w 132(%a0),%d0
	add.w %d0,%d1
	move.w %d1,10376(%a2)
	move.w 12(%a3),%a3
	add.w 10(%a1),%a3
	move.w %a3,10380(%a2)
	move.l (%sp)+,%a2
	move.l (%sp)+,%a3
	unlk %fp
	rts
.L14:
	move.w 120(%a0),%d0
	add.w #30,%d0
	move.w %d0,9800(%a1)
	move.w 124(%a0),%a0
	lea (200,%a0),%a0
	move.w %a0,9804(%a1)
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
