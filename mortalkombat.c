// -----------------------------------------------------------------------
//
// Example C project showing sprites and multiple files.
//
// -----------------------------------------------------------------------

// -----------------------------------------------------------------------
// Define your sprite names in common.h
// -----------------------------------------------------------------------
#include "common.h"								// This should be included in all source files
#include "spritemovements.h"
#include "spriteanimator.h"
#include "fighter.h"
#include "sound.h"
#include "impactFrame.h"
#include "blood.h"
#include "spritedelay.h"

// *************************************************
//            User Global Variables
// *************************************************
static int pad1;
static int pad2;
static int ticksPerSec = 60;
int lastTicks = 0;
int p1Cursor = 1;
int p2Cursor = 2; 
bool onTitleScreen = true;
bool onScreenChooseFighter = false;
bool onScreenVsBattle = false;
bool onScreenFight = false;
static int BLACKPAL[128];
static int WHITEPAL[8];

static	SoundHandler soundHandler = {
		false,  //sound on/off
		false,  //music on/off
		1,  //sound volume
		1   //music volume
	};
//Scorpion animation frames
static SpriteAnimator cageAnimator = {
	CAGE, 0.5f, BMPCAGE, 0, 0, 96
};

static SpriteAnimator cageAnimator2 = {
	CAGE2, 0.5f, BMPCAGE, 0, 0, 96
};

struct ImpactFrame cageImpactFrameLowPunch = {
	2, 62, 30
};
struct ImpactFrame cageImpactFrameHighPunch = {
	2, 62, 10
};
struct ImpactFrame cageImpactFrameLowKick = {
	2, 62, 30
};
struct ImpactFrame cageImpactFrameHighKick = {
	3, 62, 10
};
struct ImpactFrame cageImpactFrameUppercut = {
	3, 32, 30
};

static AnimationFrame cageHitLowFrames[] = {
	{ 80, 144, 288, 432, 11 , 0, 6 },
	{ 80, 144, 368, 432, 8, 0, 6 },
	{ 80, 144, 448, 432, 16, 0, 6 },
	{ 80, 144, 368, 432, 8, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0}
};
static AnimationFrame cageHitHighFrames[] = {
	{ 80, 144, 608, 432, 5 , 0, 6 },
	{ 80, 144, 528, 432, 13, 0, 6 },
	{ 80, 144, 608, 432, 5, 0, 6 },
	{ 80, 144, 448, 432, 16, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0}
};
static AnimationFrame cageHitBackFrames[] = {
	{ 80, 144, 608, 432, 5, 0, 6 },
	{ 64, 144, 688, 432, 8, 0, 6 },
	{ 64, 144, 752, 432, 16, 0, 6 },
	{ 48, 144, 816, 432, 8, 0, 6 },
	{ 64, 144, 864, 432, 8, 0, 6 },
	{ 80, 144, 448, 432, 16, 0, 6 }
};
static AnimationFrame cageHitFallFrames[] = {
	{ 80, 144, 208, 576, 6, 0, 6 },
	{ 96, 144, 288, 576, -15, 0, 6 },
	{ 112, 112, 0, 720, -24, 0, 6 },
	{ 96, 96, 928, 928, -25, -28, 6 },
	{ 96, 96, 352, 864, -24, -48, 6 },
	{ 128, 64, 896, 870, -41, -90, 6 }
};
static AnimationFrame cageIdleFrames[] = {
	{ 96, 144, 0, 0, 0, 0, 6 },
	{ 96, 144, 96, 0, 0, 0, 6 },
	{ 96, 144, 192, 0, 0, 0, 6 },
	{ 96, 144, 288, 0, 0, 0, 6 },
	{ 96, 144, 384, 0, 0, 0, 6 },
	{ 96, 144, 480, 0, 0, 0, 6 },
	{ 96, 144, 576, 0, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0}
};
static AnimationFrame cageWalkFrames[] = {
	{ 96, 144, 672, 0, 0, 0, 6 },
	{ 96, 144, 768, 0, 0, 0, 6 },
	{ 96, 144, 864, 0, 0, 0, 6 },
	{ 96, 144, 0, 144, 0, 0, 6 },
	{ 96, 144, 96, 144, 0, 0, 6 },
	{ 96, 144, 192, 144, 0, 0, 6 },
	{ 96, 144, 288, 144, 0, 0, 6 },
	{ 96, 144, 384, 144, 0, 0, 6 },
	{ 96, 144, 480, 144, 0, 0, 6 }
};
static AnimationFrame cageDuckFrames[] = {
	{ 96, 144, 576, 144, 6, 0, 3 },
	{ 80, 144, 672, 144, 6, 0, 3 },
	{ 80, 144, 752, 144, 6, 0, 3 }
};
static AnimationFrame cageBlockFrames[] = {
	{ 80, 144, 832, 144, 0, 0, 3 },
	{ 80, 144, 912, 144, 0, 0, 3 },
	{ 80, 144, 0, 288, 0, 0, 3 }
};
static AnimationFrame cageBlockDuckFrames[] = {
	{ 80, 144, 80, 288, 6, 0, 3 },
	{ 80, 144, 160, 288, 6, 0, 3 }
};
static AnimationFrame cagePunchLowFrames[] = {
	{ 80, 144, 240, 288, 15, 0, 4 },
	{ 80, 144, 320, 288, 19, 0, 4 },
	{ 112, 144, 400, 288, 18, 0, 8 },
	{ 80, 144, 320, 288, 19, 0, 4 },
	{ 80, 144, 240, 288, 15, 0, 4 }
};
static AnimationFrame cagePunchHighFrames[] = {
	{ 80, 144, 240, 288, 15, 0, 4 },
	{ 80, 144, 320, 288, 19, 0, 4 },
	{ 96, 144, 688, 288, 31, 0, 8 },
	{ 80, 144, 320, 288, 19, 0, 4 },
	{ 80, 144, 240, 288, 15, 0, 4 }
};
static AnimationFrame cageKickLowFrames[] = {
	{ 48, 144, 880, 288, 40, 0, 4 },
	{ 96, 144, 928, 288, 41, 0, 4 },
	{ 128, 144, 0, 432, 33, 0, 8 },
	{ 96, 144, 928, 288, 41, 0, 4 },
	{ 48, 144, 880, 288, 40, 0, 4 },
	{ 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0}
};
static AnimationFrame cageKickHighFrames[] = {
	{ 48, 144, 880, 288, 40, 0, 4 },
	{ 48, 144, 128, 432, 39, 0, 4 },
	{ 96, 144, 928, 288, 41, 0, 4 },
	{ 112, 144, 176, 432, 39, 0, 8 },
	{ 96, 144, 928, 288, 41, 0, 4 },
	{ 48, 144, 128, 432, 39, 0, 4 },
	{ 48, 144, 880, 288, 40, 0, 4 }
};
static AnimationFrame cageUppercutFrames[] = {
	{ 96, 80, 448, 944, 6, 64, 4 },
	{ 96, 112, 544, 912, 2, 32, 4 },
	{ 80, 144, 640, 880, 21, 1, 4 },
	{ 64, 160, 720, 864, 28, -15, 12 },
	{ 80, 144, 784, 880, 7, 1, 4 }
};

//Liu Kang animation frames
struct ImpactFrame kangImpactFrameLowPunch = {
	2, 62, 30
};
struct ImpactFrame kangImpactFrameHighPunch = {
	2, 62, 10
};
struct ImpactFrame kangImpactFrameLowKick = {
	2, 62, 30
};
struct ImpactFrame kangImpactFrameHighKick = {
	3, 62, 10
};

static SpriteAnimator kangAnimator = {
	KANG, 0.5f, BMPKANG, 0, 0, 80
};

static SpriteAnimator kangAnimator2 = {
	KANG2, 0.5f, BMPKANG, 0, 0, 80
};

static AnimationFrame kangHitLowFrames[] = {
	{ 80, 144, 304, 432, 8 , 0, 6 },
	{ 80, 144, 384, 432, 5, 0, 6 },
	{ 80, 144, 464, 432, 4, 0, 6 },
	{ 80, 144, 384, 432, 5, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame kangHitHighFrames[] = {
	{ 80, 144, 544, 432, 14, 0, 6 },
	{ 80, 144, 624, 432, 14, 0, 6 },
	{ 80, 144, 544, 432, 14, 0, 6 },
	{ 80, 144, 624, 432, 14, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame kangHitBackFrames[] = {
	{ 80, 144, 384, 432, 5, 0, 6 },
	{ 80, 144, 624, 432, 5, 0, 6 },
	{ 80, 144, 704, 432, 15, 0, 6 },
	{ 80, 144, 784, 432, 12, 0, 6 },
	{ 80, 144, 864, 432, 4, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame kangIdleFrames[] = {
	{ 80, 144, 0, 0, 0, 0, 7 },
	{ 80, 144, 80, 0, 0, 0, 7 },
	{ 80, 144, 160, 0, 0, 0, 7 },
	{ 80, 144, 240, 0, 0, 0, 7 },
	{ 80, 144, 320, 0, 0, 0, 7 },
	{ 80, 144, 400, 0, 0, 0, 7 },
	{ 80, 144, 480, 0, 0, 0, 7 },
	{ 80, 144, 560, 0, 0, 0, 7 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame kangWalkFrames[] = {
	{ 80, 144, 640, 0, 0, 0, 6 },
	{ 80, 144, 720, 0, 0, 0, 6 },
	{ 80, 144, 800, 0, 0, 0, 6 },
	{ 80, 144, 880, 0, 0, 0, 6 },
	{ 80, 144, 0, 144, 0, 0, 6 },
	{ 80, 144, 80, 144, 0, 0, 6 },
	{ 80, 144, 160, 144, 0, 0, 6 },
	{ 80, 144, 240, 144, 0, 0, 6 },
	{ 80, 144, 320, 144, 0, 0, 6 }
};
static AnimationFrame kangDuckFrames[] = {
	{ 80, 144, 400, 144, 0, 0, 3 },
	{ 80, 144, 480, 144, 0, 0, 3 },
	{ 80, 144, 560, 144, 0, 0, 3 }
};
static AnimationFrame kangBlockFrames[] = {
	{ 80, 144, 640, 144, 0, 0, 3 },
	{ 80, 144, 720, 144, 0, 0, 3 },
	{ 80, 144, 800, 144, 0, 0, 3 }
};
static AnimationFrame kangBlockDuckFrames[] = {
	{ 80, 144, 880, 144, 0, 0, 3 },
	{ 80, 144, 0, 288, 0, 0, 3 }
};
static AnimationFrame kangPunchLowFrames[] = {
	{ 80, 144, 80, 288, 8, 0, 4 },
	{ 80, 144, 160, 288, 11, 0, 4 },
	{ 112, 144, 240, 288, 12, 0, 8 },
	{ 80, 144, 160, 288, 11, 0, 4 },
	{ 80, 144, 80, 288, 8, 0, 4 }
};
static AnimationFrame kangPunchHighFrames[] = {
	{ 80, 144, 80, 288, 8, 0, 4 },
	{ 80, 144, 160, 288, 11, 0, 4 },
	{ 112, 144, 640, 288, 12, 0, 8 },
	{ 80, 144, 160, 288, 11, 0, 4 },
	{ 80, 144, 80, 288, 8, 0, 4 }
};
static AnimationFrame kangKickLowFrames[] = {
	{ 80, 144, 864, 288, 17, 0, 4 },
	{ 80, 144, 944, 288, 11, 0, 4 },
	{ 112, 144, 0, 432, 0, 0, 8 },
	{ 80, 144, 944, 288, 11, 0, 4 },
	{ 80, 144, 864, 288, 17, 0, 4 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame kangKickHighFrames[] = {
	{ 80, 144, 864, 288, 17, 0, 4 },
	{ 80, 144, 944, 288, 11, 0, 4 },
	{ 80, 144, 112, 432, 8, 0, 4 },
	{ 112, 144, 192, 432, 2, 0, 8 },
	{ 80, 144, 112, 432, 8, 0, 4 },
	{ 80, 144, 944, 288, 11, 0, 4 },
	{ 80, 144, 864, 288, 17, 0, 4 }
};
//Raiden animation frames
struct ImpactFrame raidenImpactFrameLowPunch = {
	2, 62, 30
};
struct ImpactFrame raidenImpactFrameHighPunch = {
	2, 62, 10
};
struct ImpactFrame raidenImpactFrameLowKick = {
	2, 62, 30
};
struct ImpactFrame raidenImpactFrameHighKick = {
	2, 62, 10
};

static SpriteAnimator raidenAnimator = {
	RAIDEN, 0.5f, BMPRAIDEN, 0, 0, 80
};

static SpriteAnimator raidenAnimator2 = {
	RAIDEN2, 0.5f, BMPRAIDEN, 0, 0, 80
};

static AnimationFrame raidenHitLowFrames[] = {
	{ 80, 144, 224, 432, 0 , 0, 6 },
	{ 80, 144, 304, 432, 0, 0, 6 },
	{ 80, 144, 384, 432, 0, 0, 6 },
	{ 80, 144, 304, 432, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame raidenHitHighFrames[] = {
	{ 80, 144, 464, 432, 0, 0, 6 },
	{ 80, 144, 544, 432, 0, 0, 6 },
	{ 80, 144, 464, 432, 0, 0, 6 },
	{ 80, 144, 544, 432, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame raidenHitBackFrames[] = {
	{ 80, 144, 464, 432, 0, 0, 6 },
	{ 80, 144, 624, 432, 0, 0, 6 },
	{ 80, 144, 704, 432, 0, 0, 6 },
	{ 64, 144, 784, 432, 0, 0, 6 },
	{ 48, 144, 864, 432, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame raidenIdleFrames[] = {
	{ 80, 144, 0, 0, 0, 0, 6 },
	{ 80, 144, 80, 0, 0, 0, 6 },
	{ 80, 144, 160, 0, 0, 0, 6 },
	{ 80, 144, 240, 0, 0, 0, 6 },
	{ 80, 144, 320, 0, 0, 0, 6 },
	{ 80, 144, 400, 0, 0, 0, 6 },
	{ 80, 144, 480, 0, 0, 0, 6 },
	{ 80, 144, 560, 0, 0, 0, 6 },
	{ 80, 144, 640, 0, 0, 0, 6 },
	{ 80, 144, 720, 0, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame raidenWalkFrames[] = {
	{ 80, 144, 800, 0, 0, 0, 6 },
	{ 80, 144, 880, 0, 0, 0, 6 },
	{ 80, 144, 0, 144, 0, 0, 6 },
	{ 80, 144, 80, 144, 0, 0, 6 },
	{ 80, 144, 160, 144, 0, 0, 6 },
	{ 80, 144, 240, 144, 0, 0, 6 },
	{ 80, 144, 320, 144, 0, 0, 6 },
	{ 80, 144, 400, 144, 0, 0, 6 },
	{ 80, 144, 480, 144, 0, 0, 6 }
};
static AnimationFrame raidenDuckFrames[] = {
	{ 80, 144, 560, 144, 0, 0, 3 },
	{ 80, 144, 640, 144, 0, 0, 3 },
	{ 80, 144, 720, 144, 0, 0, 3 }
};
static AnimationFrame raidenBlockFrames[] = {
	{ 80, 144, 800, 144, 0, 0, 3 },
	{ 80, 144, 880, 144, 0, 0, 3 },
	{ 80, 144, 0, 288, 0, 0, 3 }
};
static AnimationFrame raidenBlockDuckFrames[] = {
	{ 80, 144, 80, 288, 0, 0, 3 },
	{ 80, 144, 160, 288, 0, 0, 3 }
};
static AnimationFrame raidenPunchLowFrames[] = {
	{ 80, 144, 240, 288, 3, 0, 4 },
	{ 80, 144, 320, 288, 4, 0, 4 },
	{ 112, 144, 400, 288, 5, 0, 8 },
	{ 80, 144, 320, 288, 4, 0, 4 },
	{ 80, 144, 240, 288, 3, 0, 4 }
};
static AnimationFrame raidenPunchHighFrames[] = {
	{ 80, 144, 240, 288, 3, 0, 4 },
	{ 80, 144, 320, 288, 4, 0, 4 },
	{ 112, 144, 736, 288, 6, 0, 8 },
	{ 80, 144, 320, 288, 4, 0, 4 },
	{ 80, 144, 240, 288, 3, 0, 4 }
};
static AnimationFrame raidenKickLowFrames[] = {
	{ 80, 144, 848, 288, 0, 0, 4 },
	{ 96, 144, 928, 288, 0, 0, 4 },
	{ 112, 144, 0, 432, 0, 0, 8 },
	{ 96, 144, 928, 288, 0, 0, 4 },
	{ 80, 144, 848, 288, 0, 0, 4 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame raidenKickHighFrames[] = {
	{ 80, 144, 848, 288, 0, 0, 4 },
	{ 96, 144, 928, 288, 0, 0, 4 },
	{ 112, 144, 112, 432, 0, 0, 8 },
	{ 96, 144, 928, 288, 0, 0, 4 },
	{ 80, 144, 848, 288, 0, 0, 4 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};

//Subzero animation frames
struct ImpactFrame subzeroImpactFrameLowPunch = {
	2, 62, 30
};
struct ImpactFrame subzeroImpactFrameHighPunch = {
	2, 62, 10
};
struct ImpactFrame subzeroImpactFrameLowKick = {
	2, 62, 30
};
struct ImpactFrame subzeroImpactFrameHighKick = {
	3, 62, 10
};

static SpriteAnimator subzeroAnimator = {
	SUBZERO, 0.5f, BMPSUBZERO, 0, 0, 72
};

static SpriteAnimator subzeroAnimator2 = {
	SUBZERO2, 0.5f, BMPSUBZERO, 0, 0, 72
};

static AnimationFrame subzeroHitLowFrames[] = {
	{ 64, 144, 272, 432, 0, 0, 8 },
	{ 80, 144, 336, 432, 0, 0, 6 },
	{ 80, 144, 416, 432, 0, 0, 6 },
	{ 80, 144, 336, 432, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame subzeroHitHighFrames[] = {
	{ 64, 144, 496, 432, 0, 0, 6 },
	{ 80, 144, 560, 432, 0, 0, 6 },
	{ 80, 144, 640, 432, 0, 0, 6 },
	{ 80, 144, 560, 432, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame subzeroHitBackFrames[] = {
	{ 80, 144, 336, 432, 0, 0, 6 },
	{ 48, 144, 720, 432, 8, 0, 6 },
	{ 64, 144, 768, 432, 16, 0, 6 },
	{ 64, 144, 832, 432, 8, 0, 6 },
	{ 64, 144, 272, 432, 0, 0, 8 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame subzeroIdleFrames[] = {
	{ 64, 144, 0, 0, 10, 0, 6 },
	{ 64, 144, 64, 0, 11, 0, 6 },
	{ 64, 144, 128, 0, 13, 0, 6 },
	{ 64, 144, 192, 0, 13, 0, 6 },
	{ 64, 144, 256, 0, 12, 0, 6 },
	{ 64, 144, 320, 0, 12, 0, 6 },
	{ 64, 144, 384, 0, 12, 0, 6 },
	{ 64, 144, 448, 0, 12, 0, 6 },
	{ 64, 144, 512, 0, 12, 0, 6 },
	{ 64, 144, 576, 0, 12, 0, 6 },
	{ 64, 144, 640, 0, 12, 0, 6 },
	{ 64, 144, 704, 0, 11, 0, 6 }
};
static AnimationFrame subzeroWalkFrames[] = {
	{ 80, 144, 768, 0, 0, 0, 6 },
	{ 80, 144, 848, 0, 0, 0, 6 },
	{ 80, 144, 928, 0, 0, 0, 6 },
	{ 80, 144, 0, 144, 0, 0, 6 },
	{ 80, 144, 80, 144, 0, 0, 6 },
	{ 80, 144, 160, 144, 0, 0, 6 },
	{ 80, 144, 240, 144, 0, 0, 6 },
	{ 80, 144, 320, 144, 0, 0, 6 },
	{ 80, 144, 400, 144, 0, 0, 6 }
};
static AnimationFrame subzeroDuckFrames[] = {
	{ 64, 144, 480, 144, 12, 0, 3 },
	{ 64, 144, 544, 144, 12, 0, 3 },
	{ 64, 144, 608, 144, 12, 0, 3 }
};
static AnimationFrame subzeroBlockFrames[] = {
	{ 64, 144, 672, 144, 12, 0, 3 },
	{ 64, 144, 736, 144, 12, 0, 3 },
	{ 64, 144, 800, 144, 12, 0, 3 }
};
static AnimationFrame subzeroBlockDuckFrames[] = {
	{ 64, 144, 864, 144, 12, 0, 3 },
	{ 64, 144, 928, 144, 12, 0, 3 }
};
static AnimationFrame subzeroPunchLowFrames[] = {
	{ 80, 144, 0, 288, 8, 0, 4 },
	{ 96, 144, 80, 288, 11, 0, 4 },
	{ 112, 144, 176, 288, 12, 0, 8 },
	{ 96, 144, 80, 288, 11, 0, 4 },
	{ 80, 144, 0, 288, 8, 0, 4 }
};
static AnimationFrame subzeroPunchHighFrames[] = {
	{ 80, 144, 0, 288, 8, 0, 4 },
	{ 80, 144, 480, 288, 11, 0, 4 },
	{ 112, 144, 560, 288, 12, 0, 8 },
	{ 80, 144, 480, 288, 11, 0, 4 },
	{ 80, 144, 0, 288, 8, 0, 4 }
};
static AnimationFrame subzeroKickLowFrames[] = {
	{ 64, 144, 784, 288, 10, 0, 4 },
	{ 80, 144, 848, 288, 20, 0, 4 },
	{ 112, 144, 0, 432, 17, 0, 8 },
	{ 80, 144, 848, 288, 20, 0, 4 },
	{ 64, 144, 784, 288, 10, 0, 4 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame subzeroKickHighFrames[] = {
	{ 64, 144, 784, 288, 10, 0, 4 },
	{ 48, 144, 112, 432, 20, 0, 4 },
	{ 80, 144, 848, 288, 20, 0, 4 },
	{ 112, 144, 160, 432, 17, 0, 8 },
	{ 80, 144, 848, 288, 20, 0, 4 },
	{ 48, 144, 112, 432, 20, 0, 4 },
	{ 64, 144, 784, 288, 10, 0, 4 }
};

//Sonya animation frames
struct ImpactFrame sonyaImpactFrameLowPunch = {
	2, 62, 30
};
struct ImpactFrame sonyaImpactFrameHighPunch = {
	2, 62, 10
};
struct ImpactFrame sonyaImpactFrameLowKick = {
	3, 62, 30
};
struct ImpactFrame sonyaImpactFrameHighKick = {
	3, 62, 10
};
static SpriteAnimator sonyaAnimator = {
	SONYA, 0.5f, BMPSONYA, 0, 0, 80
};

static SpriteAnimator sonyaAnimator2 = {
	SONYA2, 0.5f, BMPSONYA, 0, 0, 80
};

static AnimationFrame sonyaHitLowFrames[] = {
	{ 64, 144, 880, 288, 0, 0, 6 },
	{ 80, 144, 0, 432, -6, 0, 6 },
	{ 64, 144, 880, 288, 0, 0, 6 },
	{ 80, 144, 80, 432, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame sonyaHitHighFrames[] = {
	{ 80, 144, 160, 432, 0, 0, 6 },
	{ 80, 144, 240, 432, 0, 0, 6 },
	{ 80, 144, 320, 432, 0, 0, 6 },
	{ 80, 144, 240, 432, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame sonyaHitBackFrames[] = {
	{ 80, 144, 80, 432, 0, 0, 6 },
	{ 80, 144, 400, 432, 8, 0, 6 },
	{ 80, 144, 480, 432, 16, 0, 6 },
	{ 80, 144, 560, 432, 8, 0, 6 },
	{ 80, 144, 640, 432, 8, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame sonyaIdleFrames[] = {
	{ 80, 144, 0, 0, 0, 0, 6 },
	{ 80, 144, 80, 0, 0, 0, 6 },
	{ 80, 144, 160, 0, 0, 0, 6 },
	{ 80, 144, 240, 0, 0, 0, 6 },
	{ 80, 144, 320, 0, 0, 0, 6 },
	{ 80, 144, 400, 0, 0, 0, 6 },
	{ 80, 144, 480, 0, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame sonyaWalkFrames[] = {
	{ 80, 144, 560, 0, 0, 0, 6 },
	{ 80, 144, 640, 0, 0, 0, 6 },
	{ 80, 144, 720, 0, 0, 0, 6 },
	{ 80, 144, 800, 0, 0, 0, 6 },
	{ 80, 144, 880, 0, 0, 0, 6 },
	{ 80, 144, 0, 144, 0, 0, 6 },
	{ 80, 144, 80, 144, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame sonyaDuckFrames[] = {
	{ 80, 144, 160, 144, 0, 0, 3 },
	{ 80, 144, 240, 144, 0, 0, 3 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame sonyaBlockFrames[] = {
	{ 80, 144, 320, 144, 0, 0, 3 },
	{ 80, 144, 400, 144, 0, 0, 3 },
	{ 80, 144, 480, 144, 0, 0, 3 }
};
static AnimationFrame sonyaBlockDuckFrames[] = {
	{ 80, 144, 560, 144, 0, 0, 3 },
	{ 80, 144, 640, 144, 0, 0, 3 }
};
static AnimationFrame sonyaPunchLowFrames[] = {
	{ 80, 144, 720, 144, 8, 0, 4 },
	{ 80, 144, 800, 144, 8, 0, 4 },
	{ 112, 144, 880, 144, 11, 0, 8 },
	{ 80, 144, 800, 144, 8, 0, 4 },
	{ 80, 144, 720, 144, 8, 0, 4 }
};
static AnimationFrame sonyaPunchHighFrames[] = {
	{ 80, 144, 720, 144, 8, 0, 4 },
	{ 80, 144, 800, 144, 8, 0, 4 },
	{ 112, 144, 192, 288, 12, 0, 8 },
	{ 80, 144, 800, 144, 8, 0, 4 },
	{ 80, 144, 720, 144, 8, 0, 4 }
};
static AnimationFrame sonyaKickLowFrames[] = {
	{ 80, 144, 416, 288, 8, 0, 4 },
	{ 80, 144, 496, 288, 27, 0, 4 },
	{ 80, 144, 576, 288, 27, 0, 4 },
	{ 112, 144, 656, 288, 19, 0, 8 },
	{ 80, 144, 576, 288, 27, 0, 4 },
	{ 80, 144, 496, 288, 27, 0, 4 },
	{ 80, 144, 416, 288, 8, 0, 4 }
};
static AnimationFrame sonyaKickHighFrames[] = {
	{ 80, 144, 416, 288, 8, 0, 4 },
	{ 80, 144, 496, 288, 27, 0, 4 },
	{ 80, 144, 576, 288, 27, 0, 4 },
	{ 112, 144, 768, 288, 19, 0, 8 },
	{ 80, 144, 576, 288, 27, 0, 4 },
	{ 80, 144, 496, 288, 27, 0, 4 },
	{ 80, 144, 416, 288, 8, 0, 4 }
};

//Scorpion animation frames
static SpriteAnimator scorpionAnimator = {
	SCORPION, 0.5f, BMPSUBZERO, 0, 0, 80
};

static SpriteAnimator scorpionAnimator2 = {
	SCORPION2, 0.5f, BMPSUBZERO, 0, 0, 80
};

static AnimationFrame scorpionIdleFrames[] = {
	{ 80, 144, 0, 736, 0, 0, 6 },
	{ 80, 144, 80, 736, 0, 0, 6 },
	{ 80, 144, 160, 736, 0, 0, 6 },
	{ 80, 144, 240, 736, 0, 0, 6 },
	{ 80, 144, 320, 736, 0, 0, 6 },
	{ 80, 144, 400, 736, 0, 0, 6 },
	{ 80, 144, 480, 736, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame scorpionWalkFrames[] = {
	{ 80, 144, 560, 736, 0, 0, 6 },
	{ 80, 144, 640, 736, 0, 0, 6 },
	{ 80, 144, 720, 736, 0, 0, 6 },
	{ 80, 144, 800, 736, 0, 0, 6 },
	{ 80, 144, 880, 736, 0, 0, 6 },
	{ 80, 144, 0, 880, 0, 0, 6 },
	{ 80, 144, 80, 880, 0, 0, 6 },
	{ 80, 144, 160, 880, 0, 0, 6 },
	{ 80, 144, 240, 880, 0, 0, 6 }
};

//Kano animation frames
static SpriteAnimator kanoAnimator = {
	KANO, 0.5f, BMPKANO, 0, 0, 80
};

static SpriteAnimator kanoAnimator2 = {
	KANO2, 0.5f, BMPKANO, 0, 0, 80
};

struct ImpactFrame kanoImpactFrameLowPunch = {
	2, 62, 30
};
struct ImpactFrame kanoImpactFrameHighPunch = {
	2, 62, 10
};
struct ImpactFrame kanoImpactFrameLowKick = {
	3, 62, 30
};
struct ImpactFrame kanoImpactFrameHighKick = {
	3, 62, 10
};

static AnimationFrame kanoHitLowFrames[] = {
	{ 80, 144, 384, 432, 0, 0, 12 },
	{ 80, 144, 464, 432, 0, 0, 6 },
	{ 80, 144, 544, 432, 0, 0, 6 },
	{ 80, 144, 464, 432, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame kanoHitHighFrames[] = {
	{ 80, 144, 704, 432, 0, 0, 6 },
	{ 80, 144, 624, 432, 0, 0, 6 },
	{ 80, 144, 704, 432, 0, 0, 6 },
	{ 80, 144, 624, 432, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame kanoHitBackFrames[] = {
	{ 80, 144, 704, 432, 0, 0, 6 },
	{ 80, 144, 384, 432, 0, 0, 12 },
	{ 80, 144, 784, 432, 0, 0, 6 },
	{ 80, 144, 544, 432, 0, 0, 6 },
	{ 96, 144, 864, 432, 0, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame kanoIdleFrames[] = {
	{ 80, 144, 0, 0, 0, 0, 5 },
	{ 80, 144, 80, 0, 0, 0, 5 },
	{ 80, 144, 160, 0, 0, 0, 5 },
	{ 80, 144, 240, 0, 0, 0, 5 },
	{ 80, 144, 320, 0, 0, 0, 5 },
	{ 80, 144, 400, 0, 0, 0, 5 },
	{ 80, 144, 480, 0, 0, 0, 5 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};
static AnimationFrame kanoWalkFrames[] = {
	{ 80, 144, 560, 0, 0, 0, 6 },
	{ 80, 144, 640, 0, 0, 0, 6 },
	{ 80, 144, 720, 0, 0, 0, 6 },
	{ 80, 144, 800, 0, 0, 0, 6 },
	{ 80, 144, 880, 0, 0, 0, 6 },
	{ 80, 144, 0, 144, 0, 0, 6 },
	{ 80, 144, 80, 144, 0, 0, 6 },
	{ 80, 144, 160, 144, 0, 0, 6 },
	{ 80, 144, 240, 144, 0, 0, 6 }
};
static AnimationFrame kanoDuckFrames[] = {
	{ 80, 144, 320, 144, 0, 0, 3 },
	{ 80, 144, 400, 144, 0, 0, 3 },
	{ 80, 144, 480, 144, 0, 0, 3 }
};
static AnimationFrame kanoBlockFrames[] = {
	{ 80, 144, 560, 144, 0, 0, 3 },
	{ 80, 144, 640, 144, 0, 0, 3 },
	{ 80, 144, 720, 144, 0, 0, 3 }
};
static AnimationFrame kanoBlockDuckFrames[] = {
	{ 80, 144, 800, 144, 0, 0, 3 },
	{ 80, 144, 880, 144, 0, 0, 3 }
};
static AnimationFrame kanoPunchLowFrames[] = {
	{ 80, 144, 160, 288, 3, 0, 4 },
	{ 80, 144, 240, 288, 15, 0, 4 },
	{ 112, 144, 320, 288, 6, 0, 8 },
	{ 80, 144, 240, 288, 15, 0, 4 },
	{ 80, 144, 160, 288, 3, 0, 4 }
};
static AnimationFrame kanoPunchHighFrames[] = {
	{ 80, 144, 160, 288, 3, 0, 4 },
	{ 80, 144, 240, 288, 15, 0, 4 },
	{ 112, 144, 656, 288, 17, 0, 8 },
	{ 80, 144, 240, 288, 15, 0, 4 },
	{ 80, 144, 160, 288, 3, 0, 4 }
};
static AnimationFrame kanoKickLowFrames[] = {
	{ 80, 144, 0, 432, 0, 0, 4 },
	{ 80, 144, 80, 432, 0, 0, 4 },
	{ 112, 144, 160, 432, 0, 0, 4 },
	{ 112, 144, 880, 288, 0, 0, 8 },
	{ 80, 144, 160, 432, 0, 0, 4 },
	{ 80, 144, 80, 432, 0, 0, 4 },
	{ 80, 144, 0, 432, 0, 0, 4 }
};
static AnimationFrame kanoKickHighFrames[] = {
	{ 80, 144, 0, 432, 0, 0, 4 },
	{ 80, 144, 80, 432, 0, 0, 4 },
	{ 112, 144, 160, 432, 0, 0, 4 },
	{ 112, 144, 272, 432, 0, 0, 8 },
	{ 80, 144, 160, 432, 0, 0, 4 },
	{ 80, 144, 80, 432, 0, 0, 4 },
	{ 80, 144, 0, 432, 0, 0, 4 }
};

static SpriteAnimator lightningAnimator = {
	LIGHTNING, 0.5f, BMP_LIGHTNING, 0, 0
};

static SpriteAnimator lightning2Animator = {
	LIGHTNING2, 0.5f, BMP_LIGHTNING, 0, 0
};

static AnimationFrame lightningFrames[] = {
	{ 80, 144, 0, 0, 0, 0, 4 },
	{ 80, 144, 80, 0, 0, 0, 4 },
	{ 80, 144, 160, 0, 0, 0, 4 },
	{ 80, 144, 240, 0, 0, 0, 4 },
	{ 80, 144, 320, 0, 0, 0, 4 },
	{ 80, 144, 400, 0, 0, 0, 4 },
	{ 80, 144, 480, 0, 0, 0, 4 },
	{ 80, 144, 560, 0, 0, 0, 4 },
	{ 80, 144, 640, 0, 0, 0, 4 },
	{ 80, 144, 720, 0, 0, 0, 4 },
	{ 80, 144, 0, 144, 0, 0, 4 },
	{ 80, 144, 80, 144, 0, 0, 4 },
	{ 80, 144, 160, 144, 0, 0, 4 },
	{ 80, 144, 240, 144, 0, 0, 4 },
	{ 80, 144, 320, 144, 0, 0, 4 },
	{ 80, 144, 400, 144, 0, 0, 4 },
	{ 80, 144, 480, 144, 0, 0, 4 },
	{ 80, 144, 560, 144, 0, 0, 4 },
	{ 80, 144, 640, 144, 0, 0, 4 },
	{ 80, 144, 720, 144, 0, 0, 4 },
	{ 80, 144, 0, 288, 0, 0, 4 },
	{ 80, 144, 80, 288, 0, 0, 4 },
	{ 80, 144, 160, 288, 0, 0, 4 },
	{ 80, 144, 240, 288, 0, 0, 4 },
	{ 80, 144, 320, 288, 0, 0, 4 },
	{ 80, 144, 400, 288, 0, 0, 4 },
	{ 80, 144, 480, 288, 0, 0, 4 },
	{ 80, 144, 560, 288, 0, 0, 4 },
	{ 80, 144, 640, 288, 0, 0, 4 },
	{ 80, 144, 720, 288, 0, 0, 4 }
};

static SpriteAnimator shutter1Animator = {
	SHUTTER_1, 0.5f, BMP_SHUTTER, 0, 0
};

static SpriteAnimator shutter2Animator = {
	SHUTTER_2, 0.5f, BMP_SHUTTER, 0, 0
};

static SpriteAnimator shutter3Animator = {
	SHUTTER_3, 0.5f, BMP_SHUTTER, 0, 0
};

static SpriteAnimator shutter4Animator = {
	SHUTTER_4, 0.5f, BMP_SHUTTER, 0, 0
};

static SpriteAnimator shutter5Animator = {
	SHUTTER_5, 0.5f, BMP_SHUTTER, 0, 0
};

static AnimationFrame shutterFrames[] = {
	{ 48, 48, 0, 0, 0, 0, 3 },
	{ 48, 48, 0, 0, 0, 0, 3 },
	{ 48, 48, 0, 0, 0, 0, 3 },
	{ 48, 48, 48, 0, 0, 0, 3 },
	{ 48, 48, 96, 0, 0, 0, 3 },
	{ 48, 48, 144, 0, 0, 0, 3 },
	{ 48, 48, 192, 0, 0, 0, 3 },
	{ 48, 48, 240, 0, 0, 0, 3 },
	{ 48, 48, 288, 0, 0, 0, 3 },
	{ 48, 48, 336, 0, 0, 0, 3 },
	{ 48, 48, 384, 0, 0, 0, 3 },
	{ 48, 48, 432, 0, 0, 0, 3 },
	{ 48, 48, 480, 0, 0, 0, 3 },
	{ 48, 48, 528, 0, 0, 0, 3 },
	{ 48, 48, 576, 0, 0, 0, 3 }
};

static SpriteAnimator fightAnimator = {
	FIGHT, 0.5f, BMP_FIGHT, 0, 0
};

static AnimationFrame fightIdleFrames[] = {
	{ 160, 48, 0, 0, 0, 0, 3 }
};

static AnimationFrame fightFlashFrames[] = {
	{ 160, 48, 0, 0, 0, 0, 3 },
	{ 160, 48, 0, 48, 0, 0, 3 }
};

///////////////////////////////
// Player 1 Fighters
///////////////////////////////
static Fighter fighterScorpion = {
	SCORPION, BMPSUBZERO,
	SCORPION_IDLE_FRAME_COUNT,
	SCORPION_WALK_FRAME_COUNT,
	SUBZERO_DUCK_FRAME_COUNT,
	SUBZERO_BLOCK_FRAME_COUNT,
	SUBZERO_BLOCK_DUCK_FRAME_COUNT,
	SUBZERO_LOW_PUNCH_FRAME_COUNT,
	SUBZERO_HIGH_PUNCH_FRAME_COUNT,
	SUBZERO_LOW_KICK_FRAME_COUNT,
	SUBZERO_HIGH_KICK_FRAME_COUNT,
	SUBZERO_UPPERCUT_FRAME_COUNT,
	SUBZERO_HIT_LOW_FRAME_COUNT,
	SUBZERO_HIT_HIGH_FRAME_COUNT,
	SUBZERO_HIT_BACK_FRAME_COUNT,
	SUBZERO_HIT_FALL_FRAME_COUNT
};

static Fighter fighterKano = {
	KANO, BMPKANO,
	KANO_IDLE_FRAME_COUNT,
	KANO_WALK_FRAME_COUNT,
	KANO_DUCK_FRAME_COUNT,
	KANO_BLOCK_FRAME_COUNT,
	KANO_BLOCK_DUCK_FRAME_COUNT,
	KANO_LOW_PUNCH_FRAME_COUNT,
	KANO_HIGH_PUNCH_FRAME_COUNT,
	KANO_LOW_KICK_FRAME_COUNT,
	KANO_HIGH_KICK_FRAME_COUNT,
	KANO_UPPERCUT_FRAME_COUNT,
	KANO_HIT_LOW_FRAME_COUNT,
	KANO_HIT_HIGH_FRAME_COUNT,
	KANO_HIT_BACK_FRAME_COUNT,
	KANO_HIT_FALL_FRAME_COUNT
};

static Fighter fighterCage = {
	CAGE, BMPCAGE,
	CAGE_IDLE_FRAME_COUNT,
	CAGE_WALK_FRAME_COUNT,
	CAGE_DUCK_FRAME_COUNT,
	CAGE_BLOCK_FRAME_COUNT,
	CAGE_BLOCK_DUCK_FRAME_COUNT,
	CAGE_LOW_PUNCH_FRAME_COUNT,
	CAGE_HIGH_PUNCH_FRAME_COUNT,
	CAGE_LOW_KICK_FRAME_COUNT,
	CAGE_HIGH_KICK_FRAME_COUNT,
	CAGE_UPPERCUT_FRAME_COUNT,
	CAGE_HIT_LOW_FRAME_COUNT,
	CAGE_HIT_HIGH_FRAME_COUNT,
	CAGE_HIT_BACK_FRAME_COUNT,
	CAGE_HIT_FALL_FRAME_COUNT
};

static Fighter fighterKang = {
	KANG, BMPKANG,
	KANG_IDLE_FRAME_COUNT,
	KANG_WALK_FRAME_COUNT,
	KANG_DUCK_FRAME_COUNT,
	KANG_BLOCK_FRAME_COUNT,
	KANG_BLOCK_DUCK_FRAME_COUNT,
	KANG_LOW_PUNCH_FRAME_COUNT,
	KANG_HIGH_PUNCH_FRAME_COUNT,
	KANG_LOW_KICK_FRAME_COUNT,
	KANG_HIGH_KICK_FRAME_COUNT,
	KANG_UPPERCUT_FRAME_COUNT,
	KANG_HIT_LOW_FRAME_COUNT,
	KANG_HIT_HIGH_FRAME_COUNT,
	KANG_HIT_BACK_FRAME_COUNT,
	KANG_HIT_FALL_FRAME_COUNT
};

static Fighter fighterRaiden = {
	RAIDEN, BMPRAIDEN,
	RAIDEN_IDLE_FRAME_COUNT,
	RAIDEN_WALK_FRAME_COUNT,
	RAIDEN_DUCK_FRAME_COUNT,
	RAIDEN_BLOCK_FRAME_COUNT,
	RAIDEN_BLOCK_DUCK_FRAME_COUNT,
	RAIDEN_LOW_PUNCH_FRAME_COUNT,
	RAIDEN_HIGH_PUNCH_FRAME_COUNT,
	RAIDEN_LOW_KICK_FRAME_COUNT,
	RAIDEN_HIGH_KICK_FRAME_COUNT,
	RAIDEN_UPPERCUT_FRAME_COUNT,
	RAIDEN_HIT_LOW_FRAME_COUNT,
	RAIDEN_HIT_HIGH_FRAME_COUNT,
	RAIDEN_HIT_BACK_FRAME_COUNT,
	RAIDEN_HIT_FALL_FRAME_COUNT
};

static Fighter fighterSubzero = {
	SUBZERO, BMPSUBZERO,
	SUBZERO_IDLE_FRAME_COUNT,
	SUBZERO_WALK_FRAME_COUNT,
	SUBZERO_DUCK_FRAME_COUNT,
	SUBZERO_BLOCK_FRAME_COUNT,
	SUBZERO_BLOCK_DUCK_FRAME_COUNT,
	SUBZERO_LOW_PUNCH_FRAME_COUNT,
	SUBZERO_HIGH_PUNCH_FRAME_COUNT,
	SUBZERO_LOW_KICK_FRAME_COUNT,
	SUBZERO_HIGH_KICK_FRAME_COUNT,
	SUBZERO_UPPERCUT_FRAME_COUNT,
	SUBZERO_HIT_LOW_FRAME_COUNT,
	SUBZERO_HIT_HIGH_FRAME_COUNT,
	SUBZERO_HIT_BACK_FRAME_COUNT,
	SUBZERO_HIT_FALL_FRAME_COUNT
};

static Fighter fighterSonya = {
	SONYA, BMPSONYA,
	SONYA_IDLE_FRAME_COUNT,
	SONYA_WALK_FRAME_COUNT,
	SONYA_DUCK_FRAME_COUNT,
	SONYA_BLOCK_FRAME_COUNT,
	SONYA_BLOCK_DUCK_FRAME_COUNT,
	SONYA_LOW_PUNCH_FRAME_COUNT,
	SONYA_HIGH_PUNCH_FRAME_COUNT,
	SONYA_LOW_KICK_FRAME_COUNT,
	SONYA_HIGH_KICK_FRAME_COUNT,
	SONYA_UPPERCUT_FRAME_COUNT,
	SONYA_HIT_LOW_FRAME_COUNT,
	SONYA_HIT_HIGH_FRAME_COUNT,
	SONYA_HIT_BACK_FRAME_COUNT,
	SONYA_HIT_FALL_FRAME_COUNT
};

///////////////////////////////
// Player 2 Fighters
///////////////////////////////
static Fighter fighterScorpion2 = {
	SCORPION2, BMPSUBZERO,
	SCORPION_IDLE_FRAME_COUNT,
	SCORPION_WALK_FRAME_COUNT,
	SUBZERO_DUCK_FRAME_COUNT,
	SUBZERO_BLOCK_FRAME_COUNT,
	SUBZERO_BLOCK_DUCK_FRAME_COUNT,
	SUBZERO_LOW_PUNCH_FRAME_COUNT,
	SUBZERO_HIGH_PUNCH_FRAME_COUNT,
	SUBZERO_LOW_KICK_FRAME_COUNT,
	SUBZERO_HIGH_KICK_FRAME_COUNT,
	SUBZERO_UPPERCUT_FRAME_COUNT,
	SUBZERO_HIT_LOW_FRAME_COUNT,
	SUBZERO_HIT_HIGH_FRAME_COUNT,
	SUBZERO_HIT_BACK_FRAME_COUNT,
	SUBZERO_HIT_FALL_FRAME_COUNT
};

static Fighter fighterKano2 = {
	KANO2, BMPKANO,
	KANO_IDLE_FRAME_COUNT,
	KANO_WALK_FRAME_COUNT,
	KANO_DUCK_FRAME_COUNT,
	KANO_BLOCK_FRAME_COUNT,
	KANO_BLOCK_DUCK_FRAME_COUNT,
	KANO_LOW_PUNCH_FRAME_COUNT,
	KANO_HIGH_PUNCH_FRAME_COUNT,
	KANO_LOW_KICK_FRAME_COUNT,
	KANO_HIGH_KICK_FRAME_COUNT,
	KANO_UPPERCUT_FRAME_COUNT,
	KANO_HIT_LOW_FRAME_COUNT,
	KANO_HIT_HIGH_FRAME_COUNT,
	KANO_HIT_BACK_FRAME_COUNT,
	KANO_HIT_FALL_FRAME_COUNT
};

static Fighter fighterCage2 = {
	CAGE2, BMPCAGE,
	CAGE_IDLE_FRAME_COUNT,
	CAGE_WALK_FRAME_COUNT,
	CAGE_DUCK_FRAME_COUNT,
	CAGE_BLOCK_FRAME_COUNT,
	CAGE_BLOCK_DUCK_FRAME_COUNT,
	CAGE_LOW_PUNCH_FRAME_COUNT,
	CAGE_HIGH_PUNCH_FRAME_COUNT,
	CAGE_LOW_KICK_FRAME_COUNT,
	CAGE_HIGH_KICK_FRAME_COUNT,
	CAGE_UPPERCUT_FRAME_COUNT,
	CAGE_HIT_LOW_FRAME_COUNT,
	CAGE_HIT_HIGH_FRAME_COUNT,
	CAGE_HIT_BACK_FRAME_COUNT,
	CAGE_HIT_FALL_FRAME_COUNT
};

static Fighter fighterKang2 = {
	KANG2, BMPKANG,
	KANG_IDLE_FRAME_COUNT,
	KANG_WALK_FRAME_COUNT,
	KANG_DUCK_FRAME_COUNT,
	KANG_BLOCK_FRAME_COUNT,
	KANG_BLOCK_DUCK_FRAME_COUNT,
	KANG_LOW_PUNCH_FRAME_COUNT,
	KANG_HIGH_PUNCH_FRAME_COUNT,
	KANG_LOW_KICK_FRAME_COUNT,
	KANG_HIGH_KICK_FRAME_COUNT,
	KANG_UPPERCUT_FRAME_COUNT,
	KANG_HIT_LOW_FRAME_COUNT,
	KANG_HIT_HIGH_FRAME_COUNT,
	KANG_HIT_BACK_FRAME_COUNT,
	KANG_HIT_FALL_FRAME_COUNT
};

static Fighter fighterRaiden2 = {
	RAIDEN2, BMPRAIDEN,
	RAIDEN_IDLE_FRAME_COUNT,
	RAIDEN_WALK_FRAME_COUNT,
	RAIDEN_DUCK_FRAME_COUNT,
	RAIDEN_BLOCK_FRAME_COUNT,
	RAIDEN_BLOCK_DUCK_FRAME_COUNT,
	RAIDEN_LOW_PUNCH_FRAME_COUNT,
	RAIDEN_HIGH_PUNCH_FRAME_COUNT,
	RAIDEN_LOW_KICK_FRAME_COUNT,
	RAIDEN_HIGH_KICK_FRAME_COUNT,
	RAIDEN_UPPERCUT_FRAME_COUNT,
	RAIDEN_HIT_LOW_FRAME_COUNT,
	RAIDEN_HIT_HIGH_FRAME_COUNT,
	RAIDEN_HIT_BACK_FRAME_COUNT,
	RAIDEN_HIT_FALL_FRAME_COUNT
};

static Fighter fighterSubzero2 = {
	SUBZERO2, BMPSUBZERO,
	SUBZERO_IDLE_FRAME_COUNT,
	SUBZERO_WALK_FRAME_COUNT,
	SUBZERO_DUCK_FRAME_COUNT,
	SUBZERO_BLOCK_FRAME_COUNT,
	SUBZERO_BLOCK_DUCK_FRAME_COUNT,
	SUBZERO_LOW_PUNCH_FRAME_COUNT,
	SUBZERO_HIGH_PUNCH_FRAME_COUNT,
	SUBZERO_LOW_KICK_FRAME_COUNT,
	SUBZERO_HIGH_KICK_FRAME_COUNT,
	SUBZERO_UPPERCUT_FRAME_COUNT,
	SUBZERO_HIT_LOW_FRAME_COUNT,
	SUBZERO_HIT_HIGH_FRAME_COUNT,
	SUBZERO_HIT_BACK_FRAME_COUNT,
	SUBZERO_HIT_FALL_FRAME_COUNT
};

static Fighter fighterSonya2 = {
	SONYA2, BMPSONYA,
	SONYA_IDLE_FRAME_COUNT,
	SONYA_WALK_FRAME_COUNT,
	SONYA_DUCK_FRAME_COUNT,
	SONYA_BLOCK_FRAME_COUNT,
	SONYA_BLOCK_DUCK_FRAME_COUNT,
	SONYA_LOW_PUNCH_FRAME_COUNT,
	SONYA_HIGH_PUNCH_FRAME_COUNT,
	SONYA_LOW_KICK_FRAME_COUNT,
	SONYA_HIGH_KICK_FRAME_COUNT,
	SONYA_UPPERCUT_FRAME_COUNT,
	SONYA_HIT_LOW_FRAME_COUNT,
	SONYA_HIT_HIGH_FRAME_COUNT,
	SONYA_HIT_BACK_FRAME_COUNT,
	SONYA_HIT_FALL_FRAME_COUNT
};

// *************************************************


// *************************************************
//               User Prototypes
// *************************************************
void switchScreenChooseFighter();
void switchScreenVsBattle(int p1Cursor, int p2Cursor);
void switchScreenFight(int p1Cursor, int P2Cursor);
void SetPlayerPalettes();

void basicmain()
{
	pad1=0;
	pad2=0;
	if (!rapNTSCFlag)
	{
		ticksPerSec = 50;
	}
	lastTicks = 0;
	int myTicks = 0;
	int p1Selected = -1;
	int p2Selected = -1;
	bool chooseFighterDone = false;
	int shutterTicks = 0;
	bool roundFightSequenceComplete = false;
	int fightScale = 0;
	struct Fighter* fighter1Ptr;
	struct Fighter* fighter2Ptr;

	//wire up all of the fighter animations
	//Johnny Cage
	fighterCage.idleFrames = &cageIdleFrames;
	fighterCage.walkFrames = &cageWalkFrames;
	fighterCage.duckFrames = &cageDuckFrames;
	fighterCage.blockFrames = &cageBlockFrames;
	fighterCage.blockDuckFrames = &cageBlockDuckFrames;
	fighterCage.punchLowFrames = &cagePunchLowFrames;
	fighterCage.punchHighFrames = &cagePunchHighFrames;
	fighterCage.kickLowFrames = &cageKickLowFrames;
	fighterCage.kickHighFrames = &cageKickHighFrames;
	fighterCage.uppercutFrames = &cageUppercutFrames;
	fighterCage.hitLowFrames = &cageHitLowFrames;
	fighterCage.hitHighFrames = &cageHitHighFrames;
	fighterCage.hitBackFrames = &cageHitBackFrames;
	fighterCage.hitFallFrames = &cageHitFallFrames;
	fighterCage2.idleFrames = &cageIdleFrames;
	fighterCage2.walkFrames = &cageWalkFrames;
	fighterCage2.duckFrames = &cageDuckFrames;
	fighterCage2.blockFrames = &cageBlockFrames;
	fighterCage2.blockDuckFrames = &cageBlockDuckFrames;
	fighterCage2.punchLowFrames = &cagePunchLowFrames;
	fighterCage2.punchHighFrames = &cagePunchHighFrames;
	fighterCage2.kickLowFrames = &cageKickLowFrames;
	fighterCage2.kickHighFrames = &cageKickHighFrames;
	fighterCage2.uppercutFrames = &cageUppercutFrames;
	fighterCage2.hitLowFrames = &cageHitLowFrames;
	fighterCage2.hitHighFrames = &cageHitHighFrames;
	fighterCage2.hitBackFrames = &cageHitBackFrames;
	fighterCage2.hitFallFrames = &cageHitFallFrames;
	//Kano
	fighterKano.idleFrames = &kanoIdleFrames;
	fighterKano.walkFrames = &kanoWalkFrames;
	fighterKano.duckFrames = &kanoDuckFrames;
	fighterKano.blockFrames = &kanoBlockFrames;
	fighterKano.blockDuckFrames = &kanoBlockDuckFrames;
	fighterKano.punchLowFrames = &kanoPunchLowFrames;
	fighterKano.punchHighFrames = &kanoPunchHighFrames;
	fighterKano.kickLowFrames = &kanoKickLowFrames;
	fighterKano.kickHighFrames = &kanoKickHighFrames;
	fighterKano.uppercutFrames = &cageUppercutFrames;
	fighterKano.hitLowFrames = &kanoHitLowFrames;
	fighterKano.hitHighFrames = &kanoHitHighFrames;
	fighterKano.hitBackFrames = &kanoHitBackFrames;
	fighterKano.hitFallFrames = &cageHitFallFrames;
	fighterKano2.idleFrames = &kanoIdleFrames;
	fighterKano2.walkFrames = &kanoWalkFrames;
	fighterKano2.duckFrames = &kanoDuckFrames;
	fighterKano2.blockFrames = &kanoBlockFrames;
	fighterKano2.blockDuckFrames = &kanoBlockDuckFrames;
	fighterKano2.punchLowFrames = &kanoPunchLowFrames;
	fighterKano2.punchHighFrames = &kanoPunchHighFrames;
	fighterKano2.kickLowFrames = &kanoKickLowFrames;
	fighterKano2.kickHighFrames = &kanoKickHighFrames;
	fighterKano2.uppercutFrames = &cageUppercutFrames;
	fighterKano2.hitLowFrames = &kanoHitLowFrames;
	fighterKano2.hitHighFrames = &kanoHitHighFrames;
	fighterKano2.hitBackFrames = &kanoHitBackFrames;
	fighterKano2.hitFallFrames = &cageHitFallFrames;
	//Raiden
	fighterRaiden.idleFrames = &raidenIdleFrames;
	fighterRaiden.walkFrames = &raidenWalkFrames;
	fighterRaiden.duckFrames = &raidenDuckFrames;
	fighterRaiden.blockFrames = &raidenBlockFrames;
	fighterRaiden.blockDuckFrames = &raidenBlockDuckFrames;
	fighterRaiden.punchLowFrames = &raidenPunchLowFrames;
	fighterRaiden.punchHighFrames = &raidenPunchHighFrames;
	fighterRaiden.kickLowFrames = &raidenKickLowFrames;
	fighterRaiden.kickHighFrames = &raidenKickHighFrames;
	fighterRaiden.uppercutFrames = &cageUppercutFrames;
	fighterRaiden.hitLowFrames = &raidenHitLowFrames;
	fighterRaiden.hitHighFrames = &raidenHitHighFrames;
	fighterRaiden.hitBackFrames = &raidenHitBackFrames;
	fighterRaiden.hitFallFrames = &cageHitFallFrames;
	fighterRaiden2.idleFrames = &raidenIdleFrames;
	fighterRaiden2.walkFrames = &raidenWalkFrames;
	fighterRaiden2.duckFrames = &raidenDuckFrames;
	fighterRaiden2.blockFrames = &raidenBlockFrames;
	fighterRaiden2.blockDuckFrames = &raidenBlockDuckFrames;
	fighterRaiden2.punchLowFrames = &raidenPunchLowFrames;
	fighterRaiden2.punchHighFrames = &raidenPunchHighFrames;
	fighterRaiden2.kickLowFrames = &raidenKickLowFrames;
	fighterRaiden2.kickHighFrames = &raidenKickHighFrames;
	fighterRaiden2.uppercutFrames = &cageUppercutFrames;
	fighterRaiden2.hitLowFrames = &raidenHitLowFrames;
	fighterRaiden2.hitHighFrames = &raidenHitHighFrames;
	fighterRaiden2.hitBackFrames = &raidenHitBackFrames;
	fighterRaiden2.hitFallFrames = &cageHitFallFrames;
	//Liu Kang
	fighterKang.idleFrames = &kangIdleFrames;
	fighterKang.walkFrames = &kangWalkFrames;
	fighterKang.duckFrames = &kangDuckFrames;
	fighterKang.blockFrames = &kangBlockFrames;
	fighterKang.blockDuckFrames = &kangBlockDuckFrames;
	fighterKang.punchLowFrames = &kangPunchLowFrames;
	fighterKang.punchHighFrames = &kangPunchHighFrames;
	fighterKang.kickLowFrames = &kangKickLowFrames;
	fighterKang.kickHighFrames = &kangKickHighFrames;
	fighterKang.uppercutFrames = &cageUppercutFrames;
	fighterKang.hitLowFrames = &kangHitLowFrames;
	fighterKang.hitHighFrames = &kangHitHighFrames;
	fighterKang.hitBackFrames = &kangHitBackFrames;
	fighterKang.hitFallFrames = &cageHitFallFrames;
	fighterKang2.idleFrames = &kangIdleFrames;
	fighterKang2.walkFrames = &kangWalkFrames;
	fighterKang2.duckFrames = &kangDuckFrames;
	fighterKang2.blockFrames = &kangBlockFrames;
	fighterKang2.blockDuckFrames = &kangBlockDuckFrames;
	fighterKang2.punchLowFrames = &kangPunchLowFrames;
	fighterKang2.punchHighFrames = &kangPunchHighFrames;
	fighterKang2.kickLowFrames = &kangKickLowFrames;
	fighterKang2.kickHighFrames = &kangKickHighFrames;
	fighterKang2.uppercutFrames = &cageUppercutFrames;
	fighterKang2.hitLowFrames = &kangHitLowFrames;
	fighterKang2.hitHighFrames = &kangHitHighFrames;
	fighterKang2.hitBackFrames = &kangHitBackFrames;
	fighterKang2.hitFallFrames = &cageHitFallFrames;
	//Scorpion
	fighterScorpion.idleFrames = &scorpionIdleFrames;
	fighterScorpion.walkFrames = &scorpionWalkFrames;
	fighterScorpion.duckFrames = &subzeroDuckFrames;
	fighterScorpion.blockFrames = &subzeroBlockFrames;
	fighterScorpion.blockDuckFrames = &subzeroBlockDuckFrames;
	fighterScorpion.punchLowFrames = &subzeroPunchLowFrames;
	fighterScorpion.punchHighFrames = &subzeroPunchHighFrames;
	fighterScorpion.kickLowFrames = &subzeroKickLowFrames;
	fighterScorpion.kickHighFrames = &subzeroKickHighFrames;
	fighterScorpion.uppercutFrames = &cageUppercutFrames;
	fighterScorpion.hitLowFrames = &subzeroHitLowFrames;
	fighterScorpion.hitHighFrames = &subzeroHitHighFrames;
	fighterScorpion.hitBackFrames = &subzeroHitBackFrames;
	fighterScorpion.hitFallFrames = &cageHitFallFrames;
	fighterScorpion2.idleFrames = &scorpionIdleFrames;
	fighterScorpion2.walkFrames = &scorpionWalkFrames;
	fighterScorpion2.duckFrames = &subzeroDuckFrames;
	fighterScorpion2.blockFrames = &subzeroBlockFrames;
	fighterScorpion2.blockDuckFrames = &subzeroBlockDuckFrames;
	fighterScorpion2.punchLowFrames = &subzeroPunchLowFrames;
	fighterScorpion2.punchHighFrames = &subzeroPunchHighFrames;
	fighterScorpion2.kickLowFrames = &subzeroKickLowFrames;
	fighterScorpion2.kickHighFrames = &subzeroKickHighFrames;
	fighterScorpion2.uppercutFrames = &cageUppercutFrames;
	fighterScorpion2.hitLowFrames = &subzeroHitLowFrames;
	fighterScorpion2.hitHighFrames = &subzeroHitHighFrames;
	fighterScorpion2.hitBackFrames = &subzeroHitBackFrames;
	fighterScorpion2.hitFallFrames = &cageHitFallFrames;
	//Sub-Zero
	fighterSubzero.idleFrames = &subzeroIdleFrames;
	fighterSubzero.walkFrames = &subzeroWalkFrames;
	fighterSubzero.duckFrames = &subzeroDuckFrames;
	fighterSubzero.blockFrames = &subzeroBlockFrames;
	fighterSubzero.blockDuckFrames = &subzeroBlockDuckFrames;
	fighterSubzero.punchLowFrames = &subzeroPunchLowFrames;
	fighterSubzero.punchHighFrames = &subzeroPunchHighFrames;
	fighterSubzero.kickLowFrames = &subzeroKickLowFrames;
	fighterSubzero.kickHighFrames = &subzeroKickHighFrames;
	fighterSubzero.uppercutFrames = &cageUppercutFrames;
	fighterSubzero.hitLowFrames = &subzeroHitLowFrames;
	fighterSubzero.hitHighFrames = &subzeroHitHighFrames;
	fighterSubzero.hitBackFrames = &subzeroHitBackFrames;
	fighterSubzero.hitFallFrames = &cageHitFallFrames;
	fighterSubzero2.idleFrames = &subzeroIdleFrames;
	fighterSubzero2.walkFrames = &subzeroWalkFrames;
	fighterSubzero2.duckFrames = &subzeroDuckFrames;
	fighterSubzero2.blockFrames = &subzeroBlockFrames;
	fighterSubzero2.blockDuckFrames = &subzeroBlockDuckFrames;
	fighterSubzero2.punchLowFrames = &subzeroPunchLowFrames;
	fighterSubzero2.punchHighFrames = &subzeroPunchHighFrames;
	fighterSubzero2.kickLowFrames = &subzeroKickLowFrames;
	fighterSubzero2.kickHighFrames = &subzeroKickHighFrames;
	fighterSubzero2.uppercutFrames = &cageUppercutFrames;
	fighterSubzero2.hitLowFrames = &subzeroHitLowFrames;
	fighterSubzero2.hitHighFrames = &subzeroHitHighFrames;
	fighterSubzero2.hitBackFrames = &subzeroHitBackFrames;
	fighterSubzero2.hitFallFrames = &cageHitFallFrames;
	//Sonya
	fighterSonya.idleFrames = &sonyaIdleFrames;
	fighterSonya.walkFrames = &sonyaWalkFrames;
	fighterSonya.duckFrames = &sonyaDuckFrames;
	fighterSonya.blockFrames = &sonyaBlockFrames;
	fighterSonya.blockDuckFrames = &sonyaBlockDuckFrames;
	fighterSonya.punchLowFrames = &sonyaPunchLowFrames;
	fighterSonya.punchHighFrames = &sonyaPunchHighFrames;
	fighterSonya.kickLowFrames = &sonyaKickLowFrames;
	fighterSonya.kickHighFrames = &sonyaKickHighFrames;
	fighterSonya.uppercutFrames = &cageUppercutFrames;
	fighterSonya.hitLowFrames = &sonyaHitLowFrames;
	fighterSonya.hitHighFrames = &sonyaHitHighFrames;
	fighterSonya.hitBackFrames = &sonyaHitBackFrames;
	fighterSonya.hitFallFrames = &cageHitFallFrames;
/*
The formula (C-notation) to get a 16-bit color value from the red/green/blue parts is as follows:

color_16_bit = (red << 11) + (green << 5) + blue

where red and blue has a range of 0…31 and green has a range of 0…63, the maximum value for red/green/blue refers to 100% color intensity. Shifting red left by 11, shifting green left by 5 and adding the shifted red and green value and blue together delivers the 16-bit color value.
*/
	unsigned short bg_color = 0;
	
	//bg_color = (21 << 11) + (57 << 5) + 31;  //(red << 11) + (green << 5) + blue7

	*(volatile unsigned short*)(BG)=(volatile unsigned short)bg_color;		// Set Background colour.

rapDebugSetXY(5,20);
rapDebugInverse();

//rapDebugPrint "This is some debug text";
rapDebugSetMonitor(0, (char *)(sprite[BG1_BACKDROP].x));

rapSetClock(0);
rapClockMode = Clock_Countup;

//load cluts
for (int i = 0; i < 128; i++)
{
	BLACKPAL[i] = 0;
}

for (int i = 0; i < 8; i++)
{
	WHITEPAL[i] = (21 << 11) + (57 << 5) + 31;
}

jsfLoadClut((unsigned short *)(void *)(BLACKPAL),0,256);

//TO BE TURNED ON AFTER CLUT FADE AND SWITCH TO CURRENTSCREEN = 1 
//////jsfLoadClut((unsigned short *)(void *)(BMP_CHOOSEFIGHTER_clut),0,95);
//////jsfLoadClut((unsigned short *)(void *)(BMP_LIGHTNING_clut),13,3);
//jsfLoadClut((unsigned short *)(void *)(BMPSCORPION_clut),14,16);
//jsfLoadClut((unsigned short *)(void *)(BMPCAGE_clut),14,16);
//jsfLoadClut((unsigned short *)(void *)(BMPKANG_clut),14,16);
//jsfLoadClut((unsigned short *)(void *)(BMPRAIDEN_clut),14,16);
//////jsfLoadClut((unsigned short *)(void *)(BMPSUBZERO_clut),15,16);
//jsfLoadClut((unsigned short *)(void *)(BMPSONYA_clut),14,16);
//////jsfLoadClut((unsigned short *)(void *)(BMPKANO_clut),14,16);


//TODO initialize fighter after they are selected
//fighterInitialize(&fighterScorpion, true);
//fighterInitialize(&fighterCage, true);
//fighterInitialize(&fighterKang, true);
//fighterInitialize(&fighterRaiden, true);
//fighterInitialize(&fighterSubzero, true);
//fighterInitialize(&fighterSonya, true);
//fighterInitialize(&fighterKano, false);
rapSetActiveList(0);  //0 = attract mode sprites, 1 = In game sprites

bool fadedIn = false;
bool fadedOut = false;
int gameStartTicks = rapTicks;
	//Main Loop
	for(;;)
	{
		int delta = rapTicks - lastTicks;
		lastTicks = rapTicks;

		if (onTitleScreen)
		{
			/////////////////////////////////////////
			// Attract Mode
			/////////////////////////////////////////
			if (!fadedIn)
			{
				fadedIn = true;

				for (int i = 0; i < 60; i++)
				{
					rapFadeClut(0,256,(int *)(void *)(BMP_TITLESCREEN_clut));
					jsfVsync(0);
				}

				sfxIntro(&soundHandler);
			}

			if (fadedIn && !fadedOut)
			{
				if (rapTicks > gameStartTicks + 240)
				{
					for (int i = 0; i < 60; i++)
					{
						rapFadeClut(0,256,BLACKPAL);
						jsfVsync(0);
					}

					fadedOut = true;
					switchScreenChooseFighter();
					sfxGong(&soundHandler);
					//u235StopModule();
					//u235Silence();
					//jsfVsync(0);
					//u235PlayModule((int)STRPTR(MK_TITLE),MOD_MONO);
					//u235PlayModule(MOD_TITLE,MOD_STEREO);
				}
			}
		}
		else if (onScreenChooseFighter)//(currentScreen == 1)
		{
			/////////////////////////////////////////
			// Choose Your Fighter
			/////////////////////////////////////////

			//Animated shutter effect
			if (shutterTicks == 0)
			{
				shutterTicks = rapTicks;
			}

			if (shutterTicks > 0)
			{
				if (rapTicks >= shutterTicks + 0 + 0)
				{
					updateSpriteAnimator(&shutter1Animator, shutterFrames, 15, true, false);
				}

				if (rapTicks >= shutterTicks + 0 + 5)
				{
					updateSpriteAnimator(&shutter2Animator, shutterFrames, 15, true, false);
				}
				
				if (rapTicks >= shutterTicks + 0 + 10)
				{
					updateSpriteAnimator(&shutter3Animator, shutterFrames, 15, true, false);
				}	

				if (rapTicks >= shutterTicks + 0 + 20)
				{
					updateSpriteAnimator(&shutter4Animator, shutterFrames, 15, true, false);
				}
					
				if (rapTicks >= shutterTicks + 0 + 30)
				{
					updateSpriteAnimator(&shutter5Animator, shutterFrames, 15, true, false);
				}
			}

			pad1 = jsfGetPadPressed(LEFT_PAD);
			pad2 = jsfGetPadPressed(RIGHT_PAD);

			bool p1CursorChanged = false;

			if (p1Selected == -1)
			{
				if (pad1 & JAGPAD_LEFT)
				{
					p1CursorChanged = true;
					p1Cursor--;

					if (p1Cursor < 0)
						p1Cursor = 3;
					else if (p1Cursor == 3)
						p1Cursor = 6;
				}
				else if (pad1 & JAGPAD_RIGHT)
				{
					p1CursorChanged = true;
					p1Cursor++;

					if (p1Cursor == 4)
						p1Cursor = 0;
					else if (p1Cursor == 7)
						p1Cursor = 4;
				}
				else if (pad1 & JAGPAD_UP)
				{
					p1CursorChanged = true;
					if (p1Cursor == 4)
						p1Cursor = 1;
					else if (p1Cursor == 6)
						p1Cursor = 2;
				}
				else if (pad1 & JAGPAD_DOWN)
				{
					p1CursorChanged = true;
					if (p1Cursor == 1)
						p1Cursor = 4;
					else if (p1Cursor == 2)
						p1Cursor = 6;
				}
			}

			if (p1CursorChanged)
			{
				sfxP1Cursor(&soundHandler);
				//cursor changed, so let's move the cursor and show the fighter
				fighterHide(&fighterCage);
				fighterHide(&fighterKano);
				fighterHide(&fighterSubzero);
				fighterHide(&fighterSonya);
				fighterHide(&fighterRaiden);
				fighterHide(&fighterKang);
				fighterHide(&fighterScorpion);
				sprite[LIGHTNING].active = R_is_inactive;

				SetPlayerPalettes();
			}

			switch (p1Cursor)
			{
				case 0:
					//Johnny Cage
					fighterUpdateIdle(delta, &fighterCage, &cageAnimator, cageIdleFrames);
					break;
				case 1:
					//Kano
					fighterUpdateIdle(delta, &fighterKano, &kanoAnimator, kanoIdleFrames);
					break;
				case 2:
					//Sub-Zero
					fighterUpdateIdle(delta, &fighterSubzero, &subzeroAnimator, subzeroIdleFrames);
					break;
				case 3:
					//Sonya
					fighterUpdateIdle(delta, &fighterSonya, &sonyaAnimator, sonyaIdleFrames);
					break;
				case 4:
					//Raiden
					fighterUpdateIdle(delta, &fighterRaiden, &raidenAnimator, raidenIdleFrames);
					updateSpriteAnimator(&lightningAnimator, lightningFrames, 30, true, true);
					break;
				case 5:
					//Liu Kang
					fighterUpdateIdle(delta, &fighterKang, &kangAnimator, kangIdleFrames);
					break;
				case 6:
					//Scorpion
					fighterUpdateIdle(delta, &fighterScorpion, &scorpionAnimator, scorpionIdleFrames);
					break;
			}

			bool p2CursorChanged = false;

			if (p2Selected == -1)
			{
				if (pad2 & JAGPAD_LEFT)
				{
					p2CursorChanged = true;
					p2Cursor--;

					if (p2Cursor < 0)
						p2Cursor = 3;
					else if (p2Cursor == 3)
						p2Cursor = 6;
				}
				else if (pad2 & JAGPAD_RIGHT)
				{
					p2CursorChanged = true;
					p2Cursor++;

					if (p2Cursor == 4)
						p2Cursor = 0;
					else if (p2Cursor == 7)
						p2Cursor = 4;
				}
				else if (pad2 & JAGPAD_UP)
				{
					p2CursorChanged = true;
					if (p2Cursor == 4)
						p2Cursor = 1;
					else if (p2Cursor == 6)
						p2Cursor = 2;
				}
				else if (pad2 & JAGPAD_DOWN)
				{
					p2CursorChanged = true;
					if (p2Cursor == 1)
						p2Cursor = 4;
					else if (p2Cursor == 2)
						p2Cursor = 6;
				}
			}

			if (p2CursorChanged)
			{
				sfxP2Cursor(&soundHandler);
				//cursor changed, so let's move the cursor and show the fighter
				fighterHide(&fighterCage2);
				fighterHide(&fighterKano2);
				fighterHide(&fighterSubzero2);
				fighterHide(&fighterSonya2);
				fighterHide(&fighterRaiden2);
				fighterHide(&fighterKang2);
				fighterHide(&fighterScorpion2);
				sprite[LIGHTNING2].active = R_is_inactive;

				SetPlayerPalettes();
			}

			switch (p2Cursor)
			{
				case 0:
					//Johnny Cage
					fighterUpdateIdle(delta, &fighterCage2, &cageAnimator2, cageIdleFrames);
					break;
				case 1:
					//Kano
					fighterUpdateIdle(delta, &fighterKano2, &kanoAnimator2, kanoIdleFrames);
					break;
				case 2:
					//Sub-Zero
					fighterUpdateIdle(delta, &fighterSubzero2, &subzeroAnimator2, subzeroIdleFrames);
					break;
				case 3:
					//Sonya
					fighterUpdateIdle(delta, &fighterSonya2, &sonyaAnimator2, sonyaIdleFrames);
					break;
				case 4:
					//Raiden
					fighterUpdateIdle(delta, &fighterRaiden2, &raidenAnimator2, raidenIdleFrames);
					updateSpriteAnimator(&lightning2Animator, lightningFrames, 30, true, true);
					break;
				case 5:
					//Liu Kang
					fighterUpdateIdle(delta, &fighterKang2, &kangAnimator2, kangIdleFrames);
					break;
				case 6:
					//Scorpion
					fighterUpdateIdle(delta, &fighterScorpion2, &scorpionAnimator2, scorpionIdleFrames);
					break;
			}

			if (pad1 & JAGPAD_C || pad1 & JAGPAD_B || pad1 & JAGPAD_A)
			{
				p1Selected = p1Cursor;
				sprite[P1_CURSOR].active = R_is_inactive;

				switch (p1Cursor)
				{
					case 0:
						sfxJohnnyCage(&soundHandler, true);
						fighter1Ptr = &fighterCage;
						break;
					case 1:
						sfxKano(&soundHandler, true);
						fighter1Ptr = &fighterKano;
						break;
					case 2:
						sfxSubzero(&soundHandler, true);
						fighter1Ptr = &fighterSubzero;
						break;
					case 3:
						sfxSonya(&soundHandler, true);
						fighter1Ptr = &fighterSonya;
						break;
					case 4:
						sfxRaiden(&soundHandler, true);
						fighter1Ptr = &fighterRaiden;
						break;
					case 5:
						sfxLiuKang(&soundHandler, true);
						fighter1Ptr = &fighterKang;
						break;
					case 6:
						sfxScorpion(&soundHandler, true);
						fighter1Ptr = &fighterScorpion;
						break;
				}
			}

			if (pad2 & JAGPAD_C || pad2 & JAGPAD_B || pad2 & JAGPAD_A)
			{
				p2Selected = p2Cursor;
				sprite[P2_CURSOR].active = R_is_inactive;

				switch (p2Cursor)
				{
					case 0:
						sfxJohnnyCage(&soundHandler, false);
						fighter2Ptr = &fighterCage2;
						break;
					case 1:
						sfxKano(&soundHandler, false);
						fighter2Ptr = &fighterKano2;
						break;
					case 2:
						sfxSubzero(&soundHandler, false);
						fighter2Ptr = &fighterSubzero2;
						break;
					case 3:
						sfxSonya(&soundHandler, false);
						fighter2Ptr = &fighterSonya2;
						break;
					case 4:
						sfxRaiden(&soundHandler, false);
						fighter2Ptr = &fighterRaiden2;
						break;
					case 5:
						sfxLiuKang(&soundHandler, false);
						fighter2Ptr = &fighterKang2;
						break;
					case 6:
						sfxScorpion(&soundHandler, false);
						fighter2Ptr = &fighterScorpion2;
						break;
				}
			}

			if (!chooseFighterDone && p1Selected > -1 && p2Selected > -1)
			{
				chooseFighterDone = true;
				myTicks = rapTicks;
			}
			
			if (chooseFighterDone && rapTicks > myTicks + 120)
			{
				for (int i = 0; i < 60; i++)
				{
					rapFadeClut(0,256,BLACKPAL);
					jsfVsync(0);
				}

				switchScreenVsBattle(p1Cursor, p2Cursor);
				sfxIntro(&soundHandler);
				myTicks = rapTicks;
			}
		}
		else if (onScreenVsBattle)
		{
			if (rapTicks > myTicks + 240)
			{
				for (int i = 0; i < 60; i++)
				{
					rapFadeClut(0,256,BLACKPAL);
					jsfVsync(0);
				}

				roundFightSequenceComplete = false;
				myTicks = rapTicks;
				bloodInit();
				spriteDelayInit();
				switchScreenFight(p1Cursor, p2Cursor);
			}
		}
		else if (onScreenFight)
		{
			/////////////////////////////////////////
			// Fight!
			/////////////////////////////////////////
			pad1=jsfGetPad(LEFT_PAD);
			pad2=jsfGetPad(RIGHT_PAD);

			if (roundFightSequenceComplete == false)
			{
				if (rapTicks >= myTicks + ticksPerSec)
				{
					sprite[ROUND1].active = R_is_inactive;
					sprite[FIGHT].active = R_is_active;

					if (fightScale <= 32)
					{
						sprite[FIGHT].scale_x = fightScale;
						sprite[FIGHT].scale_y = fightScale;
						sprite[FIGHT].x_ -= 4;
						sprite[FIGHT].y_ -= 2;

						fightScale += 2;
					}
					else
					{
						sfxFight(&soundHandler);
						roundFightSequenceComplete = true;
						myTicks = rapTicks;
						fightScale = 32;
					}
				}
			}

			if (sprite[FIGHT].active == R_is_active && roundFightSequenceComplete)
			{
				updateSpriteAnimator(&fightAnimator, fightFlashFrames, 2, true, true);

				if (rapTicks >= myTicks + ticksPerSec)
				{
					fightAnimator.currentFrame = 0;

					updateSpriteAnimator(&fightAnimator, fightIdleFrames, 1, true, true);

					if (fightScale > 0)
					{
						sprite[FIGHT].scale_x = fightScale;
						sprite[FIGHT].scale_y = fightScale;
						sprite[FIGHT].x_ += 4;
						sprite[FIGHT].y_ += 2;
						fightScale -= 2;
					}
					else
					{
						sprite[FIGHT].active = R_is_inactive;
					}
				}
			}

			//////////////////////////////////////
			// Player 1 fighter
			/////////////////////////////////////
			switch (p1Cursor)
			{
				case 0:
					//Johnny Cage
					fighterUpdate(delta, &fighterCage, &cageAnimator, false);
					break;
				case 1:
					//Kano
					fighterUpdate(delta, &fighterKano, &kanoAnimator, false);
					break;
				case 2:
					//Sub-Zero
					fighterUpdate(delta, &fighterSubzero, &subzeroAnimator, false);
					break;
				case 3:
					//Sonya
					fighterUpdate(delta, &fighterSonya, &sonyaAnimator, false);
					break;
				case 4:
					//Raiden
					sprite[LIGHTNING].x_ = sprite[RAIDEN].x_;
					fighterUpdate(delta, &fighterRaiden, &raidenAnimator, false);
					updateSpriteAnimator(&lightningAnimator, lightningFrames, 30, true, true);
					break;
				case 5:
					//Liu Kang
					fighterUpdate(delta, &fighterKang, &kangAnimator, false);
					break;
				case 6:
					//Scorpion
					fighterUpdate(delta, &fighterScorpion, &scorpionAnimator, false);
					break;
			}
			
			//////////////////////////////////////
			// Player 2 fighter
			/////////////////////////////////////
			switch (p2Cursor)
			{
				case 0:
					//Johnny Cage
					fighterUpdate(delta, &fighterCage2, &cageAnimator2, true);
					break;
				case 1:
					//Kano
					fighterUpdate(delta, &fighterKano2, &kanoAnimator2, true);
					break;
				case 2:
					//Sub-Zero
					fighterUpdate(delta, &fighterSubzero2, &subzeroAnimator2, true);
					break;
				case 3:
					//Sonya
					fighterUpdate(delta, &fighterSonya2, &sonyaAnimator2, true);
					break;
				case 4:
					//Raiden
					sprite[LIGHTNING2].x_ = sprite[RAIDEN2].x_;
					fighterUpdate(delta, &fighterRaiden2, &raidenAnimator2, true);
					updateSpriteAnimator(&lightning2Animator, lightningFrames, 30, true, true);
					break;
				case 5:
					//Liu Kang
					fighterUpdate(delta, &fighterKang2, &kangAnimator2, true);
					break;
				case 6:
					//Scorpion
					fighterUpdate(delta, &fighterScorpion2, &scorpionAnimator2, true);
					break;
			}

			fighterImpactCheck(fighter1Ptr, fighter2Ptr);
			bgUpdate(fighter1Ptr, fighter2Ptr);
			bloodUpdate(&soundHandler);
			spriteDelayUpdate();
		}
		

		pad1=jsfGetPadPressed(LEFT_PAD);
		
		if(pad1 & JAGPAD_STAR)
		{
			setFrame(P1_HB_BODY, 32, 64, 0, 0, 0.5f, BMP_HITBOX);
			setFrame(P1_HB_DUCK, 32, 64, 0, 0, 0.5f, BMP_HITBOX);
			setFrame(P2_HB_BODY, 32, 64, 0, 0, 0.5f, BMP_HITBOX);
			setFrame(P2_HB_DUCK, 32, 64, 0, 0, 0.5f, BMP_HITBOX);
			setFrame(P1_HB_ATTACK, 48, 32, 0, 0, 0.5f, BMP_HITBOX_ATTACK);
			setFrame(P2_HB_ATTACK, 48, 32, 0, 0, 0.5f, BMP_HITBOX_ATTACK);
			//rapDebugSetVisible(DEBUG_SHOW);
		}
		else if (pad1 & JAGPAD_HASH)
		{
			setFrame(P1_HB_BODY, 32, 64, 0, 0, 0.5f, BMP_HITBOX_OFF);
			setFrame(P1_HB_DUCK, 32, 64, 0, 0, 0.5f, BMP_HITBOX_OFF);
			setFrame(P2_HB_BODY, 32, 64, 0, 0, 0.5f, BMP_HITBOX_OFF);
			setFrame(P2_HB_DUCK, 32, 64, 0, 0, 0.5f, BMP_HITBOX_OFF);
			setFrame(P1_HB_ATTACK, 48, 32, 0, 0, 0.5f, BMP_HITBOX_ATTACK_OFF);
			setFrame(P2_HB_ATTACK, 48, 32, 0, 0, 0.5f, BMP_HITBOX_ATTACK_OFF);
			//rapDebugSetVisible(DEBUG_HIDE);
		}

		rapDebugUpdate();
		jsfVsync(0);
	}
}


// ************************************
//       User Subs and Functions
// ************************************
void switchScreenChooseFighter()
{
	jsfLoadClut((unsigned short *)(void *)(BMP_CHOOSEFIGHTER_clut),0,95);
	jsfLoadClut((unsigned short *)(void *)(BMP_LIGHTNING_clut),13,3);
	jsfLoadClut((unsigned short *)(void *)(BMPSUBZERO_clut),15,16);
	jsfLoadClut((unsigned short *)(void *)(BMPKANO_clut),14,16);	
	
	//Hide Player 1 and Player 2 fighters on the character select screen
	fighterHide(&fighterCage);
	fighterHide(&fighterKano);
	fighterHide(&fighterSubzero);
	fighterHide(&fighterSonya);
	fighterHide(&fighterRaiden);
	fighterHide(&fighterKang);
	fighterHide(&fighterScorpion);
	fighterHide(&fighterCage2);
	fighterHide(&fighterKano2);
	fighterHide(&fighterSubzero2);
	fighterHide(&fighterSonya2);
	fighterHide(&fighterRaiden2);
	fighterHide(&fighterKang2);
	fighterHide(&fighterScorpion2);

	//Show Kano and Sub-Zero by default
	fighterShow(&fighterKano);
	fighterShow(&fighterSubzero2);
	fighterMakeSelectable(&fighterKano, true);
	fighterMakeSelectable(&fighterSubzero2, false);
	
	rapSetActiveList(1);
	//currentScreen = 1;
	onTitleScreen = false;
	onScreenChooseFighter = true;
}

void switchScreenVsBattle(int p1Cursor, int p2Cursor)
{
	jsfLoadClut((unsigned short *)(void *)(BMP_BATTLE_clut),0,16);
	jsfLoadClut((unsigned short *)(void *)(BMP_BG_STONE_clut),1,16);

	//hide all of the portraits
	sprite[P1_PT_CAGE].active = R_is_inactive;
	sprite[P1_PT_KANO].active = R_is_inactive;
	sprite[P1_PT_KANG].active = R_is_inactive;
	sprite[P1_PT_SONYA].active = R_is_inactive;
	sprite[P1_PT_SUBZERO].active = R_is_inactive;
	sprite[P1_PT_SCORPION].active = R_is_inactive;
	sprite[P1_PT_RAIDEN].active = R_is_inactive;
	sprite[P2_PT_CAGE].active = R_is_inactive;
	sprite[P2_PT_KANO].active = R_is_inactive;
	sprite[P2_PT_KANG].active = R_is_inactive;
	sprite[P2_PT_SONYA].active = R_is_inactive;
	sprite[P2_PT_SUBZERO].active = R_is_inactive;
	sprite[P2_PT_SCORPION].active = R_is_inactive;
	sprite[P2_PT_RAIDEN].active = R_is_inactive;

	switch (p1Cursor)
	{
		case 0:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_CAGE_clut),4,16);
			sprite[P1_PT_CAGE].active = R_is_active;
			break;
		case 1:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_KANO_clut),4,16);
			sprite[P1_PT_KANO].active = R_is_active;
			break;
		case 2:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_SUBZERO_clut),4,16);
			sprite[P1_PT_SUBZERO].active = R_is_active;
			break;
		case 3:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_SONYA_clut),4,16);
			sprite[P1_PT_SONYA].active = R_is_active;
			break;
		case 4:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_RAIDEN_clut),4,16);
			sprite[P1_PT_RAIDEN].active = R_is_active;
			break;
		case 5:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_KANG_clut),4,16);
			sprite[P1_PT_KANG].active = R_is_active;
			break;
		case 6:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_SCORPION_clut),4,16);
			sprite[P1_PT_SCORPION].active = R_is_active;
			break;
	}

	switch (p2Cursor)
	{
		case 0:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_CAGE_clut),5,16);
			sprite[P2_PT_CAGE].active = R_is_active;
			break;
		case 1:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_KANO_clut),5,16);
			sprite[P2_PT_KANO].active = R_is_active;
			break;
		case 2:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_SUBZERO_clut),5,16);
			sprite[P2_PT_SUBZERO].active = R_is_active;
			break;
		case 3:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_SONYA_clut),5,16);
			sprite[P2_PT_SONYA].active = R_is_active;
			break;
		case 4:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_RAIDEN_clut),5,16);
			sprite[P2_PT_RAIDEN].active = R_is_active;
			break;
		case 5:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_KANG_clut),5,16);
			sprite[P2_PT_KANG].active = R_is_active;
			break;
		case 6:
			jsfLoadClut((unsigned short *)(void *)(BMP_PT_SCORPION_clut),5,16);
			sprite[P2_PT_SCORPION].active = R_is_active;
			break;
	}
	
	//sprite[TITLE_SCREEN].active = R_is_inactive;
	rapSetActiveList(2);
	onScreenChooseFighter = false;
	onScreenVsBattle = true;
}

void switchScreenFight(int p1Cursor, int p2Cursor)
{
	unsigned short bg = (21 << 11) + (57 << 5) + 31;  //(red << 11) + (green << 5) + blue=
	*(volatile unsigned short*)(BG)=(volatile unsigned short)bg;
	
	jsfLoadClut((unsigned short *)(void *)(BMP_PG_0_clut),0,112);
	jsfLoadClut((unsigned short *)(void *)(BMP_FLAME_clut),7,16);
	jsfLoadClut((unsigned short *)(void *)(BMP_CLOUD1_clut),8,16);
	jsfLoadClut((unsigned short *)(void *)(BMP_TEMPLE_clut),9,16);
	jsfLoadClut((unsigned short *)(void *)(BMP_MOUNTAINS_clut),10,16);
	jsfLoadClut((unsigned short *)(void *)(BMP_BUSH_clut),11,16);
	jsfLoadClut((unsigned short *)(void *)(BMP_ROUND1_clut),12,16);
	//jsfLoadClut((unsigned short *)(void *)(BMP_LIGHTNING_clut),13,3);
	jsfLoadClut((unsigned short *)(void *)(BMP_BLOOD_clut),13,16);

	switch (p1Cursor)
	{
		case 0:
			//Johnny Cage
			jsfLoadClut((unsigned short *)(void *)(BMPCAGE_clut),14,16);
			fighterInitialize(&fighterCage, true, &soundHandler, &cageImpactFrameLowPunch, &cageImpactFrameHighPunch, &cageImpactFrameLowKick, &cageImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterCage);
			break;
		case 1:
			//Kano
			jsfLoadClut((unsigned short *)(void *)(BMPKANO_clut),14,16);
			fighterInitialize(&fighterKano, true, &soundHandler, &kanoImpactFrameLowPunch, &kanoImpactFrameHighPunch, &kanoImpactFrameLowKick, &kanoImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterKano);
			break;
		case 2:
			//Sub-Zero
			jsfLoadClut((unsigned short *)(void *)(BMPSUBZERO_clut),14,16);
			fighterInitialize(&fighterSubzero, true, &soundHandler, &subzeroImpactFrameLowPunch, &subzeroImpactFrameHighPunch, &subzeroImpactFrameLowKick, &subzeroImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterSubzero);
			break;
		case 3:
			//Sonya
			jsfLoadClut((unsigned short *)(void *)(BMPSONYA_clut),14,16);
			fighterInitialize(&fighterSonya, true, &soundHandler, &sonyaImpactFrameLowPunch, &sonyaImpactFrameHighPunch, &sonyaImpactFrameLowKick, &sonyaImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterSonya);
			break;
		case 4:
			//Raiden
			jsfLoadClut((unsigned short *)(void *)(BMPRAIDEN_clut),14,16);
			fighterInitialize(&fighterRaiden, true, &soundHandler, &raidenImpactFrameLowPunch, &raidenImpactFrameHighPunch, &raidenImpactFrameLowKick, &raidenImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterRaiden);
			sprite[LIGHTNING].active = R_is_active;
			break;
		case 5:
			//Liu Kang
			jsfLoadClut((unsigned short *)(void *)(BMPKANG_clut),14,16);
			fighterInitialize(&fighterKang, true, &soundHandler, &kangImpactFrameLowPunch, &kangImpactFrameHighPunch, &kangImpactFrameLowKick, &kangImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterKang);
			break;
		case 6:
			//Scorpion
			jsfLoadClut((unsigned short *)(void *)(PAL_SCORPION_clut),14,16);
			fighterInitialize(&fighterScorpion, true, &soundHandler, &subzeroImpactFrameLowPunch, &subzeroImpactFrameHighPunch, &subzeroImpactFrameLowKick, &subzeroImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterScorpion);
			break;
	}

	switch (p2Cursor)
	{
		case 0:
			//Johnny Cage
			jsfLoadClut((unsigned short *)(void *)(BMPCAGE_clut),15,16);
			fighterInitialize(&fighterCage2, false, &soundHandler, &cageImpactFrameLowPunch, &cageImpactFrameHighPunch, &cageImpactFrameLowKick, &cageImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterCage2);
			break;
		case 1:
			//Kano
			jsfLoadClut((unsigned short *)(void *)(BMPKANO_clut),15,16);
			fighterInitialize(&fighterKano2, false, &soundHandler, &kanoImpactFrameLowPunch, &kanoImpactFrameHighPunch, &kanoImpactFrameLowKick, &kanoImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterKano2);
			break;
		case 2:
			//Sub-Zero
			jsfLoadClut((unsigned short *)(void *)(BMPSUBZERO_clut),15,16);
			fighterInitialize(&fighterSubzero2, false, &soundHandler, &subzeroImpactFrameLowPunch, &subzeroImpactFrameHighPunch, &subzeroImpactFrameLowKick, &subzeroImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterSubzero2);
			break;
		case 3:
			//Sonya
			jsfLoadClut((unsigned short *)(void *)(BMPSONYA_clut),15,16);
			fighterInitialize(&fighterSonya2, false, &soundHandler, &sonyaImpactFrameLowPunch, &sonyaImpactFrameHighPunch, &sonyaImpactFrameLowKick, &sonyaImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterSonya2);
			break;
		case 4:
			//Raiden
			jsfLoadClut((unsigned short *)(void *)(BMPRAIDEN_clut),15,16);
			fighterInitialize(&fighterRaiden2, false, &soundHandler, &raidenImpactFrameLowPunch, &raidenImpactFrameHighPunch, &raidenImpactFrameLowKick, &raidenImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterRaiden2);
			sprite[LIGHTNING2].active = R_is_active;
			break;
		case 5:
			//Liu Kang
			jsfLoadClut((unsigned short *)(void *)(BMPKANG_clut),15,16);
			fighterInitialize(&fighterKang2, false, &soundHandler, &kangImpactFrameLowPunch, &kangImpactFrameHighPunch, &kangImpactFrameLowKick, &kangImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterKang2);
			break;
		case 6:
			//Scorpion
			jsfLoadClut((unsigned short *)(void *)(PAL_SCORPION_clut),15,16);
			fighterInitialize(&fighterScorpion2, false, &soundHandler, &subzeroImpactFrameLowPunch, &subzeroImpactFrameHighPunch, &subzeroImpactFrameLowKick, &subzeroImpactFrameHighKick, &cageImpactFrameUppercut);
			fighterShow(&fighterScorpion2);
			break;
	}

	sprite[CHOOSE_FIGHTER_SCREEN].active = R_is_inactive;
	sprite[BG1_BACKDROP].active = R_is_active;
	sprite[BG1_MOUNTAIN].active = R_is_active;
	sprite[BG1_CLOUD1].active = R_is_active;
	sprite[BG1_CLOUD2].active = R_is_active;
	sprite[BG1_CLOUD3].active = R_is_active;
	sprite[BG1_TEMPLE_LEFT].active = R_is_active;
	sprite[BG1_TEMPLE_RIGHT].active = R_is_active;
	sprite[BG1_BUSH_1].active = R_is_active;
	sprite[BG1_BUSH_2].active = R_is_active;
	sprite[BG1_BUSH_3].active = R_is_active;
	sprite[BG1_BUSH_4].active = R_is_active;
	sprite[BG1_FLAME1].active = R_is_active;
	sprite[BG1_FLAME2].active = R_is_active;
	sprite[ROUND1].active = R_is_active;
	sprite[FIGHT].active = R_is_active;
	sprite[HUD].active = R_is_active;
	sprite[HEALTHBAR_P1].active = R_is_active;
	sprite[HEALTHBAR_P2].active = R_is_active;
	sprite[NAME_SCORPION_P1].active = R_is_active;
	sprite[NAME_KANO_P2].active = R_is_active;

	rapSetActiveList(1);
	onScreenVsBattle = false;
	onScreenFight = true;
}

void SetPlayerPalettes()
{
	switch (p1Cursor)
	{
		case 0:
			//Johnny Cage
			jsfLoadClut((unsigned short *)(void *)(BMPCAGE_clut),14,16);
			fighterMakeSelectable(&fighterCage, true);
			fighterShow(&fighterCage);
			sprite[P1_CURSOR].x_ = 12;
			sprite[P1_CURSOR].y_ = 43;
			break;
		case 1:
			//Kano
			jsfLoadClut((unsigned short *)(void *)(BMPKANO_clut),14,16);
			fighterMakeSelectable(&fighterKano, true);
			fighterShow(&fighterKano);
			sprite[P1_CURSOR].x_ = 73;
			sprite[P1_CURSOR].y_ = 43;
			break;
		case 2:
			//Sub-Zero
			jsfLoadClut((unsigned short *)(void *)(BMPSUBZERO_clut),14,16);
			fighterMakeSelectable(&fighterSubzero, true);
			fighterShow(&fighterSubzero);
			sprite[P1_CURSOR].x_ = 194;
			sprite[P1_CURSOR].y_ = 43;
			break;
		case 3:
			//Sonya
			jsfLoadClut((unsigned short *)(void *)(BMPSONYA_clut),14,16);
			fighterMakeSelectable(&fighterSonya, true);
			fighterShow(&fighterSonya);
			sprite[P1_CURSOR].x_ = 255;
			sprite[P1_CURSOR].y_ = 43;
			break;
		case 4:
			//Raiden
			jsfLoadClut((unsigned short *)(void *)(BMPRAIDEN_clut),14,16);
			fighterMakeSelectable(&fighterRaiden, true);
			fighterShow(&fighterRaiden);
			sprite[P1_CURSOR].x_ = 73;
			sprite[P1_CURSOR].y_ = 117;
			sprite[LIGHTNING].active = R_is_active;
			break;
		case 5:
			//Liu Kang
			jsfLoadClut((unsigned short *)(void *)(BMPKANG_clut),14,16);
			fighterMakeSelectable(&fighterKang, true);
			fighterShow(&fighterKang);
			sprite[P1_CURSOR].x_ = 134;
			sprite[P1_CURSOR].y_ = 117;
			break;
		case 6:
			//Scorpion
			jsfLoadClut((unsigned short *)(void *)(PAL_SCORPION_clut),14,16);
			fighterMakeSelectable(&fighterScorpion, true);
			fighterShow(&fighterScorpion);
			sprite[P1_CURSOR].x_ = 194;
			sprite[P1_CURSOR].y_ = 117;
			break;
	}

	switch (p2Cursor)
	{
		case 0:
			//Johnny Cage
			jsfLoadClut((unsigned short *)(void *)(BMPCAGE_clut),15,16);
			fighterMakeSelectable(&fighterCage2, false);
			fighterShow(&fighterCage2);
			sprite[P2_CURSOR].x_ = 12;
			sprite[P2_CURSOR].y_ = 43;
			break;
		case 1:
			//Kano
			jsfLoadClut((unsigned short *)(void *)(BMPKANO_clut),15,16);
			fighterMakeSelectable(&fighterKano2, false);
			fighterShow(&fighterKano2);
			sprite[P2_CURSOR].x_ = 73;
			sprite[P2_CURSOR].y_ = 43;
			break;
		case 2:
			//Sub-Zero
			jsfLoadClut((unsigned short *)(void *)(BMPSUBZERO_clut),15,16);
			fighterMakeSelectable(&fighterSubzero2, false);
			fighterShow(&fighterSubzero2);
			sprite[P2_CURSOR].x_ = 194;
			sprite[P2_CURSOR].y_ = 43;
			break;
		case 3:
			//Sonya
			jsfLoadClut((unsigned short *)(void *)(BMPSONYA_clut),15,16);
			fighterMakeSelectable(&fighterSonya2, false);
			fighterShow(&fighterSonya2);
			sprite[P2_CURSOR].x_ = 255;
			sprite[P2_CURSOR].y_ = 43;
			break;
		case 4:
			//Raiden
			jsfLoadClut((unsigned short *)(void *)(BMPRAIDEN_clut),15,16);
			fighterMakeSelectable(&fighterRaiden2, false);
			fighterShow(&fighterRaiden2);
			sprite[LIGHTNING2].active = R_is_active;
			sprite[P2_CURSOR].x_ = 73;
			sprite[P2_CURSOR].y_ = 117;
			break;
		case 5:
			//Liu Kang
			jsfLoadClut((unsigned short *)(void *)(BMPKANG_clut),15,16);
			fighterMakeSelectable(&fighterKang2, false);
			fighterShow(&fighterKang2);
			sprite[P2_CURSOR].x_ = 134;
			sprite[P2_CURSOR].y_ = 117;
			break;
		case 6:
			//Scorpion
			jsfLoadClut((unsigned short *)(void *)(PAL_SCORPION_clut),15,16);
			fighterMakeSelectable(&fighterScorpion2, false);
			fighterShow(&fighterScorpion2);
			sprite[P2_CURSOR].x_ = 194;
			sprite[P2_CURSOR].y_ = 117;
			break;
	}

	if (p1Cursor == p2Cursor)
	{
		for (int j = 0; j < 24; j++)
			rapFadeClut(15,16,BLACKPAL);
	}
}