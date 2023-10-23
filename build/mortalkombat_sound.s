#NO_APP
	.text
	.even
	.globl	__Z8sfxShootb
__Z8sfxShootb:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	tst.b 11(%fp)
	jne .L4
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
.L4:
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
	.globl	__Z9sfxSelectb
__Z9sfxSelectb:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	tst.b 11(%fp)
	jne .L9
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
.L9:
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
	.globl	__Z8sfxFightb
__Z8sfxFightb:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	tst.b 11(%fp)
	jne .L14
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
.L14:
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
	.globl	__Z13sfxJohnnyCageb
__Z13sfxJohnnyCageb:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	tst.b 11(%fp)
	jne .L19
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
.L19:
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
	.globl	__Z7sfxKanob
__Z7sfxKanob:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	tst.b 11(%fp)
	jne .L24
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
.L24:
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
	.globl	__Z9sfxRaidenb
__Z9sfxRaidenb:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	tst.b 11(%fp)
	jne .L29
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
.L29:
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
	.globl	__Z10sfxLiuKangb
__Z10sfxLiuKangb:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	tst.b 11(%fp)
	jne .L34
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
.L34:
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
	.globl	__Z11sfxScorpionb
__Z11sfxScorpionb:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	tst.b 11(%fp)
	jne .L39
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
.L39:
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
	.globl	__Z10sfxSubzerob
__Z10sfxSubzerob:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	tst.b 11(%fp)
	jne .L44
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
.L44:
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
	.globl	__Z8sfxSonyab
__Z8sfxSonyab:
	link.w %fp,#0
	move.l %a2,-(%sp)
	move.l %d2,-(%sp)
	tst.b 11(%fp)
	jne .L49
	move.l -8(%fp),%d2
	move.l -4(%fp),%a2
	unlk %fp
	rts
.L49:
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
