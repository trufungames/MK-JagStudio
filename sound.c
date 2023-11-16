
#include "common.h"
#include "sound.h"


void sfxFight(struct SoundHandler* soundHandler)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(SOUND_CHANNEL_ANNOUNCER,STRPTR(fight_sam),(STRPTR(fight_sam_end)-STRPTR(fight_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxJohnnyCage(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(johnnycage_sam),(STRPTR(johnnycage_sam_end)-STRPTR(johnnycage_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxKano(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(kano_sam),(STRPTR(kano_sam_end)-STRPTR(kano_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxRaiden(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(raiden_sam),(STRPTR(raiden_sam_end)-STRPTR(raiden_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxLiuKang(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(liukang_sam),(STRPTR(liukang_sam_end)-STRPTR(liukang_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxScorpion(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(scorpion_sam),(STRPTR(scorpion_sam_end)-STRPTR(scorpion_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxSubzero(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(subzero_sam),(STRPTR(subzero_sam_end)-STRPTR(subzero_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxSonya(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(sonya_sam),(STRPTR(sonya_sam_end)-STRPTR(sonya_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxP1Cursor(struct SoundHandler* soundHandler)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(SOUND_CHANNEL_PLAYER1,STRPTR(p1cursor_sam),(STRPTR(p1cursor_sam_end)-STRPTR(p1cursor_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxP2Cursor(struct SoundHandler* soundHandler)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(SOUND_CHANNEL_PLAYER2,STRPTR(p2cursor_sam),(STRPTR(p2cursor_sam_end)-STRPTR(p2cursor_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxGong(struct SoundHandler* soundHandler)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(SOUND_CHANNEL_MISC,STRPTR(gong_sam),(STRPTR(gong_sam_end)-STRPTR(gong_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxIntro(struct SoundHandler* soundHandler)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(SOUND_CHANNEL_MISC,STRPTR(intro_sam),(STRPTR(intro_sam_end)-STRPTR(intro_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxHiyaMale(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	if (rapRND() & 255 > 100)
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(hiya_male1_sam),(STRPTR(hiya_male1_sam_end)-STRPTR(hiya_male1_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
	else
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(hiya_male2_sam),(STRPTR(hiya_male2_sam_end)-STRPTR(hiya_male2_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
}

void sfxHiyaFemale(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	if (rapRND() & 255 > 100)
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(hiya_female1_sam),(STRPTR(hiya_female1_sam_end)-STRPTR(hiya_female1_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
	else
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(hiya_female2_sam),(STRPTR(hiya_female2_sam_end)-STRPTR(hiya_female2_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
}

void sfxHiyaKang(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	if (rapRND() & 255 > 100)
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(hiya_kang1_sam),(STRPTR(hiya_kang1_sam_end)-STRPTR(hiya_kang1_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
	else
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(hiya_kang2_sam),(STRPTR(hiya_kang2_sam_end)-STRPTR(hiya_kang2_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
}

void sfxHiyaNinja(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	if (rapRND() & 255 > 100)
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(hiya_ninja1_sam),(STRPTR(hiya_ninja1_sam_end)-STRPTR(hiya_ninja1_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
	else
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(hiya_ninja2_sam),(STRPTR(hiya_ninja2_sam_end)-STRPTR(hiya_ninja2_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
}

void sfxBlock(struct SoundHandler* soundHandler)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(SOUND_CHANNEL_MISC,STRPTR(block_sam),(STRPTR(block_sam_end)-STRPTR(block_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxGroanMale(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	if (rapRND() & 255 > 100)
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(groan_male01_sam),(STRPTR(groan_male01_sam_end)-STRPTR(groan_male01_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
	else
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(groan_male02_sam),(STRPTR(groan_male02_sam_end)-STRPTR(groan_male02_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
}

void sfxGroanFemale(struct SoundHandler* soundHandler, bool isPlayer1)
{
	if (!soundHandler->EnableSFX)
		return;

	if (rapRND() & 255 > 100)
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(groan_female01_sam),(STRPTR(groan_female01_sam_end)-STRPTR(groan_female01_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
	else
	{
		zeroPlaySample(isPlayer1 ? SOUND_CHANNEL_PLAYER1 : SOUND_CHANNEL_PLAYER2,STRPTR(groan_female02_sam),(STRPTR(groan_female02_sam_end)-STRPTR(groan_female02_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
}

void sfxHit(struct SoundHandler* soundHandler)
{
	if (!soundHandler->EnableSFX)
		return;

	if (rapRND() & 255 > 100)
	{
		zeroPlaySample(SOUND_CHANNEL_MISC,STRPTR(hit_01_sam),(STRPTR(hit_01_sam_end)-STRPTR(hit_01_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
	else
	{
		zeroPlaySample(SOUND_CHANNEL_MISC,STRPTR(hit_02_sam),(STRPTR(hit_02_sam_end)-STRPTR(hit_02_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
}

void sfxImpact(struct SoundHandler* soundHandler)
{
	if (!soundHandler->EnableSFX)
		return;

	zeroPlaySample(SOUND_CHANNEL_MISC,STRPTR(hit_impact_sam),(STRPTR(hit_impact_sam_end)-STRPTR(hit_impact_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
}

void sfxSwing(struct SoundHandler* soundHandler)
{
	if (!soundHandler->EnableSFX)
		return;

	if (rapRND() & 255 > 100)
	{
		zeroPlaySample(SOUND_CHANNEL_MISC,STRPTR(swing_01_sam),(STRPTR(swing_01_sam_end)-STRPTR(swing_01_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
	else
	{
		zeroPlaySample(SOUND_CHANNEL_MISC,STRPTR(swing_02_sam),(STRPTR(swing_02_sam_end)-STRPTR(swing_02_sam)+3) & 0xfffffffc,(46168/7000),Zero_Audio_8bit_Signed);
	}
}