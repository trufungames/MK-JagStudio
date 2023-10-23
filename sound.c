
#include "common.h"
#include "sound.h"


void sfxShoot(bool enableSFX)
{
	if (!enableSFX)
		return;
		
	zeroPlaySample(1,STRPTR(fight_sam),(STRPTR(fight_sam_end)-STRPTR(fight_sam)+3) & 0xfffffffc,(46168/16000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(fight_sam),(STRPTR(fight_sam_end)-STRPTR(fight_sam)+3) & 0xfffffffc,(46168/16000),Zero_Audio_8bit_Signed);
}

void sfxSelect(bool enableSFX)
{
	if (!enableSFX)
		return;
		
	zeroPlaySample(1,STRPTR(select_sam),(STRPTR(select_sam_end)-STRPTR(select_sam)+3) & 0xfffffffc,(46168/8000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(select_sam),(STRPTR(select_sam_end)-STRPTR(select_sam)+3) & 0xfffffffc,(46168/8000),Zero_Audio_8bit_Signed);
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