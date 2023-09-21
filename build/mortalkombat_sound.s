#NO_APP
	.text
	.even
	.globl	__Z8sfxShootv
__Z8sfxShootv:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	move.l #fight_sam_end,%d2
	sub.l #fight_sam-3,%d2
	moveq #-4,%d0
	and.l %d0,%d2
	clr.l -(%sp)
	pea 2.w
	move.l %d2,-(%sp)
	pea fight_sam
	pea 1.w
	lea zeroPlaySample,%a2
	jsr (%a2)
	lea (16,%sp),%sp
	clr.l (%sp)
	pea 2.w
	move.l %d2,-(%sp)
	pea fight_sam
	pea 2.w
	jsr (%a2)
	lea (20,%sp),%sp
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
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
