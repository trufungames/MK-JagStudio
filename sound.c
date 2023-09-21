
#include "common.h"
#include "sound.h"


void sfxShoot (void)
{
	zeroPlaySample(1,STRPTR(fight_sam),(STRPTR(fight_sam_end)-STRPTR(fight_sam)+3) & 0xfffffffc,(46168/16000),Zero_Audio_8bit_Signed);
	zeroPlaySample(2,STRPTR(fight_sam),(STRPTR(fight_sam_end)-STRPTR(fight_sam)+3) & 0xfffffffc,(46168/16000),Zero_Audio_8bit_Signed);
}
