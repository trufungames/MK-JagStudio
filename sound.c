
#include "common.h"
#include "sound.h"


void sfxShoot(bool enableSFX)
{
	if (!enableSFX)
		return;
		
	zeroPlaySample(1,STRPTR(fight_sam),(STRPTR(fight_sam_end)-STRPTR(fight_sam)+3) & 0xfffffffc,(46168/16000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(fight_sam),(STRPTR(fight_sam_end)-STRPTR(fight_sam)+3) & 0xfffffffc,(46168/16000),Zero_Audio_8bit_Signed);
}

void sfxFight(bool enableSFX)
{
	if (!enableSFX)
		return;

	zeroPlaySample(1,STRPTR(fight_sam),(STRPTR(fight_sam_end)-STRPTR(fight_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(fight_sam),(STRPTR(fight_sam_end)-STRPTR(fight_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxJohnnyCage(bool enableSFX)
{
	if (!enableSFX)
		return;

	zeroPlaySample(1,STRPTR(johnnycage_sam),(STRPTR(johnnycage_sam_end)-STRPTR(johnnycage_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(johnnycage_sam),(STRPTR(johnnycage_sam_end)-STRPTR(johnnycage_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxKano(bool enableSFX)
{
	if (!enableSFX)
		return;

	zeroPlaySample(1,STRPTR(kano_sam),(STRPTR(kano_sam_end)-STRPTR(kano_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(kano_sam),(STRPTR(kano_sam_end)-STRPTR(kano_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxRaiden(bool enableSFX)
{
	if (!enableSFX)
		return;

	zeroPlaySample(1,STRPTR(raiden_sam),(STRPTR(raiden_sam_end)-STRPTR(raiden_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(raiden_sam),(STRPTR(raiden_sam_end)-STRPTR(raiden_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxLiuKang(bool enableSFX)
{
	if (!enableSFX)
		return;

	zeroPlaySample(1,STRPTR(liukang_sam),(STRPTR(liukang_sam_end)-STRPTR(liukang_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(liukang_sam),(STRPTR(liukang_sam_end)-STRPTR(liukang_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxScorpion(bool enableSFX)
{
	if (!enableSFX)
		return;

	zeroPlaySample(1,STRPTR(scorpion_sam),(STRPTR(scorpion_sam_end)-STRPTR(scorpion_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(scorpion_sam),(STRPTR(scorpion_sam_end)-STRPTR(scorpion_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxSubzero(bool enableSFX)
{
	if (!enableSFX)
		return;

	zeroPlaySample(1,STRPTR(subzero_sam),(STRPTR(subzero_sam_end)-STRPTR(subzero_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(subzero_sam),(STRPTR(subzero_sam_end)-STRPTR(subzero_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxSonya(bool enableSFX)
{
	if (!enableSFX)
		return;

	zeroPlaySample(1,STRPTR(sonya_sam),(STRPTR(sonya_sam_end)-STRPTR(sonya_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(sonya_sam),(STRPTR(sonya_sam_end)-STRPTR(sonya_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxP1Cursor(bool enableSFX)
{
	if (!enableSFX)
		return;

	zeroPlaySample(1,STRPTR(p1cursor_sam),(STRPTR(p1cursor_sam_end)-STRPTR(p1cursor_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(p1cursor_sam),(STRPTR(p1cursor_sam_end)-STRPTR(p1cursor_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxP2Cursor(bool enableSFX)
{
	if (!enableSFX)
		return;

	zeroPlaySample(1,STRPTR(p2cursor_sam),(STRPTR(p2cursor_sam_end)-STRPTR(p2cursor_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(p2cursor_sam),(STRPTR(p2cursor_sam_end)-STRPTR(p2cursor_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxGong(bool enableSFX)
{
	if (!enableSFX)
		return;

	zeroPlaySample(1,STRPTR(gong_sam),(STRPTR(gong_sam_end)-STRPTR(gong_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(gong_sam),(STRPTR(gong_sam_end)-STRPTR(gong_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}