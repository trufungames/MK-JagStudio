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
	.even
	.globl	__Z9sfxSelectv
__Z9sfxSelectv:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	move.l #select_sam_end,%d2
	sub.l #select_sam-3,%d2
	moveq #-4,%d0
	and.l %d0,%d2
	clr.l -(%sp)
	pea 5.w
	move.l %d2,-(%sp)
	pea select_sam
	pea 1.w
	lea zeroPlaySample,%a2
	jsr (%a2)
	lea (16,%sp),%sp
	clr.l (%sp)
	pea 5.w
	move.l %d2,-(%sp)
	pea select_sam
	pea 2.w
	jsr (%a2)
	lea (20,%sp),%sp
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
	.even
	.globl	__Z8sfxFightv
__Z8sfxFightv:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	move.l #fight_sam_end,%d2
	sub.l #fight_sam-3,%d2
	moveq #-4,%d0
	and.l %d0,%d2
	clr.l -(%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea fight_sam
	pea 1.w
	lea zeroPlaySample,%a2
	jsr (%a2)
	lea (16,%sp),%sp
	clr.l (%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea fight_sam
	pea 2.w
	jsr (%a2)
	lea (20,%sp),%sp
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
	.even
	.globl	__Z13sfxJohnnyCagev
__Z13sfxJohnnyCagev:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	move.l #johnnycage_sam_end,%d2
	sub.l #johnnycage_sam-3,%d2
	moveq #-4,%d0
	and.l %d0,%d2
	clr.l -(%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea johnnycage_sam
	pea 1.w
	lea zeroPlaySample,%a2
	jsr (%a2)
	lea (16,%sp),%sp
	clr.l (%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea johnnycage_sam
	pea 2.w
	jsr (%a2)
	lea (20,%sp),%sp
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
	.even
	.globl	__Z7sfxKanov
__Z7sfxKanov:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	move.l #kano_sam_end,%d2
	sub.l #kano_sam-3,%d2
	moveq #-4,%d0
	and.l %d0,%d2
	clr.l -(%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea kano_sam
	pea 1.w
	lea zeroPlaySample,%a2
	jsr (%a2)
	lea (16,%sp),%sp
	clr.l (%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea kano_sam
	pea 2.w
	jsr (%a2)
	lea (20,%sp),%sp
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
	.even
	.globl	__Z9sfxRaidenv
__Z9sfxRaidenv:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	move.l #raiden_sam_end,%d2
	sub.l #raiden_sam-3,%d2
	moveq #-4,%d0
	and.l %d0,%d2
	clr.l -(%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea raiden_sam
	pea 1.w
	lea zeroPlaySample,%a2
	jsr (%a2)
	lea (16,%sp),%sp
	clr.l (%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea raiden_sam
	pea 2.w
	jsr (%a2)
	lea (20,%sp),%sp
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
	.even
	.globl	__Z10sfxLiuKangv
__Z10sfxLiuKangv:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	move.l #liukang_sam_end,%d2
	sub.l #liukang_sam-3,%d2
	moveq #-4,%d0
	and.l %d0,%d2
	clr.l -(%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea liukang_sam
	pea 1.w
	lea zeroPlaySample,%a2
	jsr (%a2)
	lea (16,%sp),%sp
	clr.l (%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea liukang_sam
	pea 2.w
	jsr (%a2)
	lea (20,%sp),%sp
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
	.even
	.globl	__Z11sfxScorpionv
__Z11sfxScorpionv:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	move.l #scorpion_sam_end,%d2
	sub.l #scorpion_sam-3,%d2
	moveq #-4,%d0
	and.l %d0,%d2
	clr.l -(%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea scorpion_sam
	pea 1.w
	lea zeroPlaySample,%a2
	jsr (%a2)
	lea (16,%sp),%sp
	clr.l (%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea scorpion_sam
	pea 2.w
	jsr (%a2)
	lea (20,%sp),%sp
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
	.even
	.globl	__Z10sfxSubzerov
__Z10sfxSubzerov:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	move.l #subzero_sam_end,%d2
	sub.l #subzero_sam-3,%d2
	moveq #-4,%d0
	and.l %d0,%d2
	clr.l -(%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea subzero_sam
	pea 1.w
	lea zeroPlaySample,%a2
	jsr (%a2)
	lea (16,%sp),%sp
	clr.l (%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea subzero_sam
	pea 2.w
	jsr (%a2)
	lea (20,%sp),%sp
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
	.even
	.globl	__Z8sfxSonyav
__Z8sfxSonyav:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	move.l #sonya_sam_end,%d2
	sub.l #sonya_sam-3,%d2
	moveq #-4,%d0
	and.l %d0,%d2
	clr.l -(%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea sonya_sam
	pea 1.w
	lea zeroPlaySample,%a2
	jsr (%a2)
	lea (16,%sp),%sp
	clr.l (%sp)
	pea 6.w
	move.l %d2,-(%sp)
	pea sonya_sam
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
