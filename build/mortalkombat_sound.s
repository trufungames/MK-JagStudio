#NO_APP
	.text
	.even
	.globl	__Z8sfxFightP12SoundHandler
__Z8sfxFightP12SoundHandler:
	link.w %fp,#0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jne .L4
	unlk %fp
	rts
.L4:
	clr.l -(%sp)
	pea 6.w
	move.l #fight_sam_end,%d0
	sub.l #fight_sam-3,%d0
	moveq #-4,%d1
	and.l %d0,%d1
	move.l %d1,-(%sp)
	pea fight_sam
	pea 3.w
	jsr zeroPlaySample
	lea (20,%sp),%sp
	unlk %fp
	rts
	.even
	.globl	__Z13sfxJohnnyCageP12SoundHandlerb
__Z13sfxJohnnyCageP12SoundHandlerb:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.b 15(%fp),%d0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jeq .L6
	tst.b %d0
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #johnnycage_sam_end,%d1
	sub.l #johnnycage_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea johnnycage_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
.L6:
	move.l -4(%fp),%d2
	unlk %fp
	rts
	.even
	.globl	__Z7sfxKanoP12SoundHandlerb
__Z7sfxKanoP12SoundHandlerb:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.b 15(%fp),%d0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jeq .L12
	tst.b %d0
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #kano_sam_end,%d1
	sub.l #kano_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea kano_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
.L12:
	move.l -4(%fp),%d2
	unlk %fp
	rts
	.even
	.globl	__Z9sfxRaidenP12SoundHandlerb
__Z9sfxRaidenP12SoundHandlerb:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.b 15(%fp),%d0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jeq .L18
	tst.b %d0
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #raiden_sam_end,%d1
	sub.l #raiden_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea raiden_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
.L18:
	move.l -4(%fp),%d2
	unlk %fp
	rts
	.even
	.globl	__Z10sfxLiuKangP12SoundHandlerb
__Z10sfxLiuKangP12SoundHandlerb:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.b 15(%fp),%d0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jeq .L24
	tst.b %d0
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #liukang_sam_end,%d1
	sub.l #liukang_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea liukang_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
.L24:
	move.l -4(%fp),%d2
	unlk %fp
	rts
	.even
	.globl	__Z11sfxScorpionP12SoundHandlerb
__Z11sfxScorpionP12SoundHandlerb:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.b 15(%fp),%d0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jeq .L30
	tst.b %d0
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #scorpion_sam_end,%d1
	sub.l #scorpion_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea scorpion_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
.L30:
	move.l -4(%fp),%d2
	unlk %fp
	rts
	.even
	.globl	__Z10sfxSubzeroP12SoundHandlerb
__Z10sfxSubzeroP12SoundHandlerb:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.b 15(%fp),%d0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jeq .L36
	tst.b %d0
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #subzero_sam_end,%d1
	sub.l #subzero_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea subzero_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
.L36:
	move.l -4(%fp),%d2
	unlk %fp
	rts
	.even
	.globl	__Z8sfxSonyaP12SoundHandlerb
__Z8sfxSonyaP12SoundHandlerb:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.b 15(%fp),%d0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jeq .L42
	tst.b %d0
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #sonya_sam_end,%d1
	sub.l #sonya_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea sonya_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
.L42:
	move.l -4(%fp),%d2
	unlk %fp
	rts
	.even
	.globl	__Z11sfxP1CursorP12SoundHandler
__Z11sfxP1CursorP12SoundHandler:
	link.w %fp,#0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jne .L51
	unlk %fp
	rts
.L51:
	clr.l -(%sp)
	pea 6.w
	move.l #p1cursor_sam_end,%d0
	sub.l #p1cursor_sam-3,%d0
	moveq #-4,%d1
	and.l %d0,%d1
	move.l %d1,-(%sp)
	pea p1cursor_sam
	pea 1.w
	jsr zeroPlaySample
	lea (20,%sp),%sp
	unlk %fp
	rts
	.even
	.globl	__Z11sfxP2CursorP12SoundHandler
__Z11sfxP2CursorP12SoundHandler:
	link.w %fp,#0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jne .L56
	unlk %fp
	rts
.L56:
	clr.l -(%sp)
	pea 6.w
	move.l #p2cursor_sam_end,%d0
	sub.l #p2cursor_sam-3,%d0
	moveq #-4,%d1
	and.l %d0,%d1
	move.l %d1,-(%sp)
	pea p2cursor_sam
	pea 2.w
	jsr zeroPlaySample
	lea (20,%sp),%sp
	unlk %fp
	rts
	.even
	.globl	__Z7sfxGongP12SoundHandler
__Z7sfxGongP12SoundHandler:
	link.w %fp,#0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jne .L61
	unlk %fp
	rts
.L61:
	clr.l -(%sp)
	pea 6.w
	move.l #gong_sam_end,%d0
	sub.l #gong_sam-3,%d0
	moveq #-4,%d1
	and.l %d0,%d1
	move.l %d1,-(%sp)
	pea gong_sam
	pea 4.w
	jsr zeroPlaySample
	lea (20,%sp),%sp
	unlk %fp
	rts
	.even
	.globl	__Z8sfxIntroP12SoundHandler
__Z8sfxIntroP12SoundHandler:
	link.w %fp,#0
	move.l 8(%fp),%a0
	tst.b (%a0)
	jne .L66
	unlk %fp
	rts
.L66:
	clr.l -(%sp)
	pea 6.w
	move.l #intro_sam_end,%d0
	sub.l #intro_sam-3,%d0
	moveq #-4,%d1
	and.l %d0,%d1
	move.l %d1,-(%sp)
	pea intro_sam
	pea 4.w
	jsr zeroPlaySample
	lea (20,%sp),%sp
	unlk %fp
	rts
	.even
	.globl	__Z11sfxHiyaMaleP12SoundHandlerb
__Z11sfxHiyaMaleP12SoundHandlerb:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.b 15(%fp),%d2
	move.l 8(%fp),%a0
	tst.b (%a0)
	jne .L77
	move.l -4(%fp),%d2
	unlk %fp
	rts
.L77:
	jsr RAPTOR_random
	btst #0,%d0
	jeq .L70
	tst.b %d2
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #hiya_male1_sam_end,%d1
	sub.l #hiya_male1_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea hiya_male1_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
.L78:
	move.l -4(%fp),%d2
	unlk %fp
	rts
.L70:
	tst.b %d2
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #hiya_male2_sam_end,%d1
	sub.l #hiya_male2_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea hiya_male2_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
	jra .L78
	.even
	.globl	__Z13sfxHiyaFemaleP12SoundHandlerb
__Z13sfxHiyaFemaleP12SoundHandlerb:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.b 15(%fp),%d2
	move.l 8(%fp),%a0
	tst.b (%a0)
	jne .L89
	move.l -4(%fp),%d2
	unlk %fp
	rts
.L89:
	jsr RAPTOR_random
	btst #0,%d0
	jeq .L82
	tst.b %d2
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #hiya_female1_sam_end,%d1
	sub.l #hiya_female1_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea hiya_female1_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
.L90:
	move.l -4(%fp),%d2
	unlk %fp
	rts
.L82:
	tst.b %d2
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #hiya_female2_sam_end,%d1
	sub.l #hiya_female2_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea hiya_female2_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
	jra .L90
	.even
	.globl	__Z11sfxHiyaKangP12SoundHandlerb
__Z11sfxHiyaKangP12SoundHandlerb:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.b 15(%fp),%d2
	move.l 8(%fp),%a0
	tst.b (%a0)
	jne .L101
	move.l -4(%fp),%d2
	unlk %fp
	rts
.L101:
	jsr RAPTOR_random
	btst #0,%d0
	jeq .L94
	tst.b %d2
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #hiya_kang1_sam_end,%d1
	sub.l #hiya_kang1_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea hiya_kang1_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
.L102:
	move.l -4(%fp),%d2
	unlk %fp
	rts
.L94:
	tst.b %d2
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #hiya_kang2_sam_end,%d1
	sub.l #hiya_kang2_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea hiya_kang2_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
	jra .L102
	.even
	.globl	__Z12sfxHiyaNinjaP12SoundHandlerb
__Z12sfxHiyaNinjaP12SoundHandlerb:
	link.w %fp,#0
	move.l %d2,-(%sp)
	move.b 15(%fp),%d2
	move.l 8(%fp),%a0
	tst.b (%a0)
	jne .L113
	move.l -4(%fp),%d2
	unlk %fp
	rts
.L113:
	jsr RAPTOR_random
	btst #0,%d0
	jeq .L106
	tst.b %d2
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #hiya_ninja1_sam_end,%d1
	sub.l #hiya_ninja1_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea hiya_ninja1_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
.L114:
	move.l -4(%fp),%d2
	unlk %fp
	rts
.L106:
	tst.b %d2
	seq %d0
	ext.w %d0
	clr.l -(%sp)
	pea 6.w
	move.l #hiya_ninja2_sam_end,%d1
	sub.l #hiya_ninja2_sam-3,%d1
	moveq #-4,%d2
	and.l %d1,%d2
	move.l %d2,-(%sp)
	pea hiya_ninja2_sam
	move.w #1,%a0
	sub.w %d0,%a0
	move.l %a0,-(%sp)
	jsr zeroPlaySample
	lea (20,%sp),%sp
	jra .L114
	.globl	colliders
	.data
	.even
colliders:
	.long	raptor_collisionlist
	.globl	sprite
	.even
sprite:
	.long	RAPTOR_sprite_table
