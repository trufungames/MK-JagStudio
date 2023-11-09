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
		1,  //sound on/off
		1,  //music on/off
		1,  //sound volume
		1   //music volume
	};
//Scorpion animation frames
static SpriteAnimator cageAnimator = {
	CAGE, 0.5f, BMPCAGE, 0, 0
};

static SpriteAnimator cageAnimator2 = {
	CAGE2, 0.5f, BMPCAGE, 0, 0
};

static AnimationFrame cageIdleFrames[] = {
	{ 96, 144, 0, 0, 0, 0, 6 },
	{ 96, 144, 96, 0, 0, 0, 6 },
	{ 96, 144, 192, 0, 0, 0, 6 },
	{ 96, 144, 288, 0, 0, 0, 6 },
	{ 96, 144, 384, 0, 0, 0, 6 },
	{ 96, 144, 480, 0, 0, 0, 6 },
	{ 96, 144, 576, 0, 0, 0, 6 }
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
	{ 96, 144, 576, 144, 0, 0, 3 },
	{ 96, 144, 672, 144, 0, 0, 3 },
	{ 96, 144, 768, 144, 0, 0, 3 }
};
static AnimationFrame cageBlockFrames[] = {
	{ 96, 144, 864, 144, 0, 0, 3 },
	{ 96, 144, 0, 288, 0, 0, 3 },
	{ 96, 144, 96, 288, 0, 0, 3 }
};
static AnimationFrame cageBlockDuckFrames[] = {
	{ 80, 144, 192, 288, 0, 0, 3 },
	{ 80, 144, 288, 288, 0, 0, 3 }
};

//Liu Kang animation frames
static SpriteAnimator kangAnimator = {
	KANG, 0.5f, BMPKANG, 0, 0
};

static SpriteAnimator kangAnimator2 = {
	KANG2, 0.5f, BMPKANG, 0, 0
};

static AnimationFrame kangIdleFrames[] = {
	{ 80, 144, 0, 0, 0, 0, 7 },
	{ 80, 144, 80, 0, 0, 0, 7 },
	{ 80, 144, 160, 0, 0, 0, 7 },
	{ 80, 144, 240, 0, 0, 0, 7 },
	{ 80, 144, 320, 0, 0, 0, 7 },
	{ 80, 144, 400, 0, 0, 0, 7 },
	{ 80, 144, 480, 0, 0, 0, 7 },
	{ 80, 144, 560, 0, 0, 0, 7 }
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
	{ 80, 144, 80, 288, 8, 0, 4 }
};
static AnimationFrame kangPunchHighFrames[] = {
	{ 80, 144, 80, 288, 8, 0, 4 },
	{ 80, 144, 160, 288, 11, 0, 4 },
	{ 112, 144, 640, 288, 12, 0, 8 },
	{ 80, 144, 80, 288, 8, 0, 4 }
};
static AnimationFrame kangKickLowFrames[] = {
	{ 80, 144, 864, 288, 17, 0, 4 },
	{ 80, 144, 944, 288, 11, 0, 4 },
	{ 112, 144, 0, 432, 0, 0, 8 },
	{ 80, 144, 944, 288, 11, 0, 4 },
	{ 80, 144, 864, 288, 17, 0, 4 }
};
static AnimationFrame kangKickHighFrames[] = {
	{ 80, 144, 864, 288, 17, 0, 4 },
	{ 80, 144, 944, 288, 11, 0, 4 },
	{ 80, 144, 112, 432, 8, 0, 5 },
	{ 112, 144, 192, 432, 2, 0, 8 },
	{ 80, 144, 112, 432, 8, 0, 5 },
	{ 80, 144, 944, 288, 11, 0, 4 },
	{ 80, 144, 864, 288, 17, 0, 4 }
};
//Raiden animation frames
static SpriteAnimator raidenAnimator = {
	RAIDEN, 0.5f, BMPRAIDEN, 0, 0
};

static SpriteAnimator raidenAnimator2 = {
	RAIDEN2, 0.5f, BMPRAIDEN, 0, 0
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
	{ 80, 144, 720, 0, 0, 0, 6 }
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
	{ 80, 144, 240, 288, 3, 0, 5 },
	{ 80, 144, 320, 288, 4, 0, 5 },
	{ 112, 144, 400, 288, 5, 0, 12 },
	{ 80, 144, 320, 288, 4, 0, 5 },
	{ 80, 144, 240, 288, 3, 0, 5 }
};
static AnimationFrame raidenPunchHighFrames[] = {
	{ 80, 144, 240, 288, 3, 0, 5 },
	{ 80, 144, 320, 288, 4, 0, 5 },
	{ 112, 144, 736, 288, 6, 0, 12 },
	{ 80, 144, 320, 288, 4, 0, 5 },
	{ 80, 144, 240, 288, 3, 0, 5 }
};
static AnimationFrame raidenKickLowFrames[] = {
	{ 80, 144, 848, 288, 0, 0, 5 },
	{ 96, 144, 928, 288, 0, 0, 5 },
	{ 112, 144, 0, 432, 0, 0, 12 },
	{ 96, 144, 928, 288, 0, 0, 5 },
	{ 80, 144, 848, 288, 0, 0, 5 },
};
static AnimationFrame raidenKickHighFrames[] = {
	{ 80, 144, 848, 288, 0, 0, 5 },
	{ 96, 144, 928, 288, 0, 0, 5 },
	{ 112, 144, 112, 432, 0, 0, 12 },
	{ 96, 144, 928, 288, 0, 0, 5 },
	{ 80, 144, 848, 288, 0, 0, 5 },
};

//Subzero animation frames
static SpriteAnimator subzeroAnimator = {
	SUBZERO, 0.5f, BMPSUBZERO, 0, 0
};

static SpriteAnimator subzeroAnimator2 = {
	SUBZERO2, 0.5f, BMPSUBZERO, 0, 0
};

static AnimationFrame subzeroIdleFrames[] = {
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
	{ 80, 144, 800, 0, 0, 0, 6 },
	{ 80, 144, 880, 0, 0, 0, 6 }
};
static AnimationFrame subzeroWalkFrames[] = {
	{ 80, 144, 0, 144, 0, 0, 6 },
	{ 80, 144, 80, 144, 0, 0, 6 },
	{ 80, 144, 160, 144, 0, 0, 6 },
	{ 80, 144, 240, 144, 0, 0, 6 },
	{ 80, 144, 320, 144, 0, 0, 6 },
	{ 80, 144, 400, 144, 0, 0, 6 },
	{ 80, 144, 480, 144, 0, 0, 6 },
	{ 80, 144, 560, 144, 0, 0, 6 },
	{ 80, 144, 640, 144, 0, 0, 6 }
};
static AnimationFrame subzeroDuckFrames[] = {
	{ 80, 144, 720, 144, 0, 0, 3 },
	{ 80, 144, 800, 144, 0, 0, 3 },
	{ 80, 144, 880, 144, 0, 0, 3 }
};
static AnimationFrame subzeroBlockFrames[] = {
	{ 80, 144, 0, 288, 0, 0, 3 },
	{ 80, 144, 80, 288, 0, 0, 3 },
	{ 80, 144, 160, 288, 0, 0, 3 }
};
static AnimationFrame subzeroBlockDuckFrames[] = {
	{ 80, 144, 240, 288, 0, 0, 3 },
	{ 80, 144, 320, 288, 0, 0, 3 }
};

//Sonya animation frames
static SpriteAnimator sonyaAnimator = {
	SONYA, 0.5f, BMPSONYA, 0, 0
};

static SpriteAnimator sonyaAnimator2 = {
	SONYA2, 0.5f, BMPSONYA, 0, 0
};

static AnimationFrame sonyaIdleFrames[] = {
	{ 80, 144, 0, 0, 0, 0, 6 },
	{ 80, 144, 80, 0, 0, 0, 6 },
	{ 80, 144, 160, 0, 0, 0, 6 },
	{ 80, 144, 240, 0, 0, 0, 6 },
	{ 80, 144, 320, 0, 0, 0, 6 },
	{ 80, 144, 400, 0, 0, 0, 6 },
	{ 80, 144, 480, 0, 0, 0, 6 }
};
static AnimationFrame sonyaWalkFrames[] = {
	{ 80, 144, 560, 0, 0, 0, 6 },
	{ 80, 144, 640, 0, 0, 0, 6 },
	{ 80, 144, 720, 0, 0, 0, 6 },
	{ 80, 144, 800, 0, 0, 0, 6 },
	{ 80, 144, 880, 0, 0, 0, 6 },
	{ 80, 144, 0, 144, 0, 0, 6 },
	{ 80, 144, 80, 144, 0, 0, 6 }
};
static AnimationFrame sonyaDuckFrames[] = {
	{ 80, 144, 160, 144, 0, 0, 3 },
	{ 80, 144, 240, 144, 0, 0, 3 }
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
	{ 80, 144, 720, 144, 8, 0, 5 },
	{ 80, 144, 800, 144, 8, 0, 5 },
	{ 112, 144, 880, 144, 11, 0, 12 },
	{ 80, 144, 800, 144, 8, 0, 5 },
	{ 80, 144, 720, 144, 8, 0, 5 }
};
static AnimationFrame sonyaPunchHighFrames[] = {
	{ 80, 144, 720, 144, 8, 0, 5 },
	{ 80, 144, 800, 144, 8, 0, 5 },
	{ 112, 144, 192, 288, 12, 0, 12 },
	{ 80, 144, 800, 144, 8, 0, 5 },
	{ 80, 144, 720, 144, 8, 0, 5 }
};
static AnimationFrame sonyaKickLowFrames[] = {
	{ 80, 144, 416, 288, 8, 0, 5 },
	{ 80, 144, 496, 288, 27, 0, 5 },
	{ 80, 144, 576, 288, 27, 0, 5 },
	{ 112, 144, 656, 288, 19, 0, 12 },
	{ 80, 144, 576, 288, 27, 0, 5 },
	{ 80, 144, 496, 288, 27, 0, 5 },
	{ 80, 144, 416, 288, 8, 0, 5 }
};
static AnimationFrame sonyaKickHighFrames[] = {
	{ 80, 144, 416, 288, 8, 0, 5 },
	{ 80, 144, 496, 288, 27, 0, 5 },
	{ 80, 144, 576, 288, 27, 0, 5 },
	{ 112, 144, 768, 288, 19, 0, 12 },
	{ 80, 144, 576, 288, 27, 0, 5 },
	{ 80, 144, 496, 288, 27, 0, 5 },
	{ 80, 144, 416, 288, 8, 0, 5 }
};

//Scorpion animation frames
static SpriteAnimator scorpionAnimator = {
	SCORPION, 0.5f, BMPSCORPION, 0, 0
};

static SpriteAnimator scorpionAnimator2 = {
	SCORPION2, 0.5f, BMPSCORPION, 0, 0
};

static AnimationFrame scorpionIdleFrames[] = {
	{ 80, 144, 0, 0, 0, 0, 6 },
	{ 80, 144, 80, 0, 0, 0, 6 },
	{ 80, 144, 160, 0, 0, 0, 6 },
	{ 80, 144, 240, 0, 0, 0, 6 },
	{ 80, 144, 320, 0, 0, 0, 6 },
	{ 80, 144, 400, 0, 0, 0, 6 },
	{ 80, 144, 480, 0, 0, 0, 6 }
};
static AnimationFrame scorpionWalkFrames[] = {
	{ 80, 144, 560, 0, 0, 0, 6 },
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
static AnimationFrame scorpionDuckFrames[] = {
	{ 64, 144, 320, 144, 13, 0, 3 },
	{ 64, 144, 384, 144, 13, 0, 3 },
	{ 64, 144, 448, 144, 13, 0, 3 }
};
static AnimationFrame scorpionBlockFrames[] = {
	{ 64, 144, 512, 144, 15, 0, 3 },
	{ 64, 144, 576, 144, 15, 0, 3 },
	{ 64, 144, 640, 144, 15, 0, 3 }
};
static AnimationFrame scorpionBlockDuckFrames[] = {
	{ 64, 144, 704, 144, 10, 0, 3 },
	{ 64, 144, 768, 144, 10, 0, 3 }
};
static AnimationFrame scorpionPunchLowFrames[] = {
	{ 80, 144, 832, 144, 7, 0, 4 },
	{ 96, 144, 912, 144, 12, 0, 5 },
	{ 112, 144, 0, 288, 12, 0, 12 },
	{ 96, 144, 912, 144, 12, 0, 5 },
	{ 80, 144, 832, 144, 7, 0, 4 }
};
static AnimationFrame scorpionPunchHighFrames[] = {
	{ 80, 144, 832, 144, 7, 0, 4 },
	{ 96, 144, 912, 144, 12, 0, 5 },
	{ 112, 144, 384, 288, 12, 0, 12 },
	{ 96, 144, 912, 144, 12, 0, 5 },
	{ 80, 144, 832, 144, 7, 0, 4 }
};
static AnimationFrame scorpionKickLowFrames[] = {
	{ 80, 144, 0, 432, 0, 0, 5 },
	{ 80, 144, 80, 432, 0, 0, 5 },
	{ 112, 144, 160, 432, 0, 0, 5 },
	{ 112, 144, 880, 288, 0, 0, 12 },
	{ 80, 144, 160, 432, 0, 0, 5 },
	{ 80, 144, 80, 432, 0, 0, 5 },
	{ 80, 144, 0, 432, 0, 0, 5 }
};
static AnimationFrame scorpionKickHighFrames[] = {
	{ 80, 144, 0, 432, 0, 0, 5 },
	{ 80, 144, 80, 432, 0, 0, 5 },
	{ 112, 144, 160, 432, 0, 0, 5 },
	{ 112, 144, 272, 432, 0, 0, 12 },
	{ 80, 144, 160, 432, 0, 0, 5 },
	{ 80, 144, 80, 432, 0, 0, 5 },
	{ 80, 144, 0, 432, 0, 0, 5 }
};

//Kano animation frames
static SpriteAnimator kanoAnimator = {
	KANO, 0.5f, BMPKANO, 0, 0
};

static SpriteAnimator kanoAnimator2 = {
	KANO2, 0.5f, BMPKANO, 0, 0
};

static AnimationFrame kanoIdleFrames[] = {
	{ 80, 144, 0, 0, 0, 0, 5 },
	{ 80, 144, 80, 0, 0, 0, 5 },
	{ 80, 144, 160, 0, 0, 0, 5 },
	{ 80, 144, 240, 0, 0, 0, 5 },
	{ 80, 144, 320, 0, 0, 0, 5 },
	{ 80, 144, 400, 0, 0, 0, 5 },
	{ 80, 144, 480, 0, 0, 0, 5 }
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
	{ 80, 144, 160, 288, 3, 0, 5 },
	{ 80, 144, 240, 288, 15, 0, 5 },
	{ 112, 144, 320, 288, 6, 0, 12 },
	{ 80, 144, 240, 288, 15, 0, 5 },
	{ 80, 144, 160, 288, 3, 0, 5 }
};
static AnimationFrame kanoPunchHighFrames[] = {
	{ 80, 144, 160, 288, 3, 0, 5 },
	{ 80, 144, 240, 288, 15, 0, 5 },
	{ 112, 144, 656, 288, 17, 0, 12 },
	{ 80, 144, 240, 288, 15, 0, 5 },
	{ 80, 144, 160, 288, 3, 0, 5 }
};
static AnimationFrame kanoKickLowFrames[] = {
	{ 80, 144, 0, 432, 0, 0, 5 },
	{ 80, 144, 80, 432, 0, 0, 5 },
	{ 112, 144, 160, 432, 0, 0, 5 },
	{ 112, 144, 880, 288, 0, 0, 12 },
	{ 80, 144, 160, 432, 0, 0, 5 },
	{ 80, 144, 80, 432, 0, 0, 5 },
	{ 80, 144, 0, 432, 0, 0, 5 }
};
static AnimationFrame kanoKickHighFrames[] = {
	{ 80, 144, 0, 432, 0, 0, 5 },
	{ 80, 144, 80, 432, 0, 0, 5 },
	{ 112, 144, 160, 432, 0, 0, 5 },
	{ 112, 144, 272, 432, 0, 0, 12 },
	{ 80, 144, 160, 432, 0, 0, 5 },
	{ 80, 144, 80, 432, 0, 0, 5 },
	{ 80, 144, 0, 432, 0, 0, 5 }
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
	SCORPION, BMPSCORPION,
	SCORPION_IDLE_FRAME_COUNT,
	SCORPION_WALK_FRAME_COUNT,
	SCORPION_DUCK_FRAME_COUNT,
	SCORPION_BLOCK_FRAME_COUNT,
	SCORPION_BLOCK_DUCK_FRAME_COUNT,
	SCORPION_LOW_PUNCH_FRAME_COUNT,
	SCORPION_HIGH_PUNCH_FRAME_COUNT,
	SCORPION_LOW_KICK_FRAME_COUNT,
	SCORPION_HIGH_KICK_FRAME_COUNT
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
	KANO_HIGH_KICK_FRAME_COUNT
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
	CAGE_HIGH_KICK_FRAME_COUNT
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
	KANG_HIGH_KICK_FRAME_COUNT
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
	RAIDEN_HIGH_KICK_FRAME_COUNT
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
	SUBZERO_HIGH_KICK_FRAME_COUNT
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
	SONYA_HIGH_KICK_FRAME_COUNT
};

///////////////////////////////
// Player 2 Fighters
///////////////////////////////
static Fighter fighterScorpion2 = {
	SCORPION2, BMPSCORPION,
	SCORPION_IDLE_FRAME_COUNT,
	SCORPION_WALK_FRAME_COUNT,
	SCORPION_DUCK_FRAME_COUNT,
	SCORPION_BLOCK_FRAME_COUNT,
	SCORPION_BLOCK_DUCK_FRAME_COUNT,
	SCORPION_LOW_PUNCH_FRAME_COUNT,
	SCORPION_HIGH_PUNCH_FRAME_COUNT,
	SCORPION_LOW_KICK_FRAME_COUNT,
	SCORPION_HIGH_KICK_FRAME_COUNT
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
	KANO_HIGH_KICK_FRAME_COUNT
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
	CAGE_HIGH_KICK_FRAME_COUNT
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
	KANG_HIGH_KICK_FRAME_COUNT
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
	RAIDEN_HIGH_KICK_FRAME_COUNT
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
	SUBZERO_HIGH_KICK_FRAME_COUNT
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
	SONYA_HIGH_KICK_FRAME_COUNT
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
						break;
					case 1:
						sfxKano(&soundHandler, true);
						break;
					case 2:
						sfxSubzero(&soundHandler, true);
						break;
					case 3:
						sfxSonya(&soundHandler, true);
						break;
					case 4:
						sfxRaiden(&soundHandler, true);
						break;
					case 5:
						sfxLiuKang(&soundHandler, true);
						break;
					case 6:
						sfxScorpion(&soundHandler, true);
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
						break;
					case 1:
						sfxKano(&soundHandler, false);
						break;
					case 2:
						sfxSubzero(&soundHandler, false);
						break;
					case 3:
						sfxSonya(&soundHandler, false);
						break;
					case 4:
						sfxRaiden(&soundHandler, false);
						break;
					case 5:
						sfxLiuKang(&soundHandler, false);
						break;
					case 6:
						sfxScorpion(&soundHandler, false);
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
					fighterUpdate(delta, &fighterCage, &cageAnimator, cageIdleFrames, cageWalkFrames, cageDuckFrames, cageBlockFrames, cageBlockDuckFrames, sonyaPunchLowFrames, sonyaPunchHighFrames, sonyaKickLowFrames, sonyaKickHighFrames, false);
					break;
				case 1:
					//Kano
					fighterUpdate(delta, &fighterKano, &kanoAnimator, kanoIdleFrames, kanoWalkFrames, kanoDuckFrames, kanoBlockFrames, kanoBlockDuckFrames, kanoPunchLowFrames, kanoPunchHighFrames, kanoKickLowFrames, kanoKickHighFrames, false);
					break;
				case 2:
					//Sub-Zero
					fighterUpdate(delta, &fighterSubzero, &subzeroAnimator, subzeroIdleFrames, subzeroWalkFrames, subzeroDuckFrames, subzeroBlockFrames, subzeroBlockDuckFrames, sonyaPunchLowFrames, sonyaPunchHighFrames, sonyaKickLowFrames, sonyaKickHighFrames, false);
					break;
				case 3:
					//Sonya
					fighterUpdate(delta, &fighterSonya, &sonyaAnimator, sonyaIdleFrames, sonyaWalkFrames, sonyaDuckFrames, sonyaBlockFrames, sonyaBlockDuckFrames, sonyaPunchLowFrames, sonyaPunchHighFrames, sonyaKickLowFrames, sonyaKickHighFrames, false);
					break;
				case 4:
					//Raiden
					sprite[LIGHTNING].x_ = sprite[RAIDEN].x_;
					fighterUpdate(delta, &fighterRaiden, &raidenAnimator, raidenIdleFrames, raidenWalkFrames, raidenDuckFrames, raidenBlockFrames, raidenBlockDuckFrames, raidenPunchLowFrames, raidenPunchHighFrames, raidenKickLowFrames, raidenKickHighFrames, false);
					updateSpriteAnimator(&lightningAnimator, lightningFrames, 30, true, true);
					break;
				case 5:
					//Liu Kang
					fighterUpdate(delta, &fighterKang, &kangAnimator, kangIdleFrames, kangWalkFrames, kangDuckFrames, kangBlockFrames, kangBlockDuckFrames, kangPunchLowFrames, kangPunchHighFrames, kangKickLowFrames, kangKickHighFrames, false);
					break;
				case 6:
					//Scorpion
					fighterUpdate(delta, &fighterScorpion, &scorpionAnimator, scorpionIdleFrames, scorpionWalkFrames, scorpionDuckFrames, scorpionBlockFrames, scorpionBlockDuckFrames, scorpionPunchLowFrames, scorpionPunchHighFrames, scorpionKickLowFrames, scorpionKickHighFrames, false);
					break;
			}
			
			//////////////////////////////////////
			// Player 2 fighter
			/////////////////////////////////////
			switch (p2Cursor)
			{
				case 0:
					//Johnny Cage
					fighterUpdate(delta, &fighterCage2, &cageAnimator2, cageIdleFrames, cageWalkFrames, cageDuckFrames, cageBlockFrames, cageBlockDuckFrames, sonyaPunchLowFrames, sonyaPunchHighFrames, sonyaKickLowFrames, sonyaKickHighFrames, true);
					break;
				case 1:
					//Kano
					fighterUpdate(delta, &fighterKano2, &kanoAnimator2, kanoIdleFrames, kanoWalkFrames, kanoDuckFrames, kanoBlockFrames, kanoBlockDuckFrames, kanoPunchLowFrames, kanoPunchHighFrames, kanoKickLowFrames, kanoKickHighFrames, true);
					break;
				case 2:
					//Sub-Zero
					fighterUpdate(delta, &fighterSubzero2, &subzeroAnimator2, subzeroIdleFrames, subzeroWalkFrames, subzeroDuckFrames, subzeroBlockFrames, subzeroBlockDuckFrames, sonyaPunchLowFrames, sonyaPunchHighFrames, sonyaKickLowFrames, sonyaKickHighFrames, true);
					break;
				case 3:
					//Sonya
					fighterUpdate(delta, &fighterSonya2, &sonyaAnimator2, sonyaIdleFrames, sonyaWalkFrames, sonyaDuckFrames, sonyaBlockFrames, sonyaBlockDuckFrames, sonyaPunchLowFrames, sonyaPunchHighFrames, sonyaKickLowFrames, sonyaKickHighFrames, true);
					break;
				case 4:
					//Raiden
					sprite[LIGHTNING2].x_ = sprite[RAIDEN2].x_;
					fighterUpdate(delta, &fighterRaiden2, &raidenAnimator2, raidenIdleFrames, raidenWalkFrames, raidenDuckFrames, raidenBlockFrames, raidenBlockDuckFrames, raidenPunchLowFrames, raidenPunchHighFrames, raidenKickLowFrames, raidenKickHighFrames, true);
					updateSpriteAnimator(&lightning2Animator, lightningFrames, 30, true, true);
					break;
				case 5:
					//Liu Kang
					fighterUpdate(delta, &fighterKang2, &kangAnimator2, kangIdleFrames, kangWalkFrames, kangDuckFrames, kangBlockFrames, kangBlockDuckFrames, kangPunchLowFrames, kangPunchHighFrames, kangKickLowFrames, kangKickHighFrames, true);
					break;
				case 6:
					//Scorpion
					fighterUpdate(delta, &fighterScorpion2, &scorpionAnimator2, scorpionIdleFrames, scorpionWalkFrames, scorpionDuckFrames, scorpionBlockFrames, scorpionBlockDuckFrames, scorpionPunchLowFrames, scorpionPunchHighFrames, scorpionKickLowFrames, scorpionKickHighFrames, true);
					break;
			}
		}
		
		pad1=jsfGetPadPressed(LEFT_PAD);
		
		if(pad1 & JAGPAD_STAR)
		{
			sprite[P1_HB_BODY].active = R_is_active;
			sprite[P1_HB_DUCK].active = R_is_active;
			sprite[P1_HB_ATTACK].active = R_is_active;
			sprite[P2_HB_BODY].active = R_is_active;
			sprite[P2_HB_DUCK].active = R_is_active;
			sprite[P2_HB_ATTACK].active = R_is_active;
			//rapDebugSetVisible(DEBUG_SHOW);
		}
		else if (pad1 & JAGPAD_HASH)
		{
			sprite[P1_HB_BODY].active = R_is_inactive;
			sprite[P1_HB_DUCK].active = R_is_inactive;
			sprite[P1_HB_ATTACK].active = R_is_inactive;
			sprite[P2_HB_BODY].active = R_is_inactive;
			sprite[P2_HB_DUCK].active = R_is_inactive;
			sprite[P2_HB_ATTACK].active = R_is_inactive;
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
	jsfLoadClut((unsigned short *)(void *)(BMP_LIGHTNING_clut),13,3);

	switch (p1Cursor)
	{
		case 0:
			//Johnny Cage
			jsfLoadClut((unsigned short *)(void *)(BMPCAGE_clut),14,16);
			fighterInitialize(&fighterCage, true, &soundHandler);
			fighterShow(&fighterCage);
			break;
		case 1:
			//Kano
			jsfLoadClut((unsigned short *)(void *)(BMPKANO_clut),14,16);
			fighterInitialize(&fighterKano, true, &soundHandler);
			fighterShow(&fighterKano);
			break;
		case 2:
			//Sub-Zero
			jsfLoadClut((unsigned short *)(void *)(BMPSUBZERO_clut),14,16);
			fighterInitialize(&fighterSubzero, true, &soundHandler);
			fighterShow(&fighterSubzero);
			break;
		case 3:
			//Sonya
			jsfLoadClut((unsigned short *)(void *)(BMPSONYA_clut),14,16);
			fighterInitialize(&fighterSonya, true, &soundHandler);
			fighterShow(&fighterSonya);
			break;
		case 4:
			//Raiden
			jsfLoadClut((unsigned short *)(void *)(BMPRAIDEN_clut),14,16);
			fighterInitialize(&fighterRaiden, true, &soundHandler);
			fighterShow(&fighterRaiden);
			sprite[LIGHTNING].active = R_is_active;
			break;
		case 5:
			//Liu Kang
			jsfLoadClut((unsigned short *)(void *)(BMPKANG_clut),14,16);
			fighterInitialize(&fighterKang, true, &soundHandler);
			fighterShow(&fighterKang);
			break;
		case 6:
			//Scorpion
			jsfLoadClut((unsigned short *)(void *)(BMPSCORPION_clut),14,16);
			fighterInitialize(&fighterScorpion, true, &soundHandler);
			fighterShow(&fighterScorpion);
			break;
	}

	switch (p2Cursor)
	{
		case 0:
			//Johnny Cage
			jsfLoadClut((unsigned short *)(void *)(BMPCAGE_clut),15,16);
			fighterInitialize(&fighterCage2, false, &soundHandler);
			fighterShow(&fighterCage2);
			break;
		case 1:
			//Kano
			jsfLoadClut((unsigned short *)(void *)(BMPKANO_clut),15,16);
			fighterInitialize(&fighterKano2, false, &soundHandler);
			fighterShow(&fighterKano2);
			break;
		case 2:
			//Sub-Zero
			jsfLoadClut((unsigned short *)(void *)(BMPSUBZERO_clut),15,16);
			fighterInitialize(&fighterSubzero2, false, &soundHandler);
			fighterShow(&fighterSubzero2);
			break;
		case 3:
			//Sonya
			jsfLoadClut((unsigned short *)(void *)(BMPSONYA_clut),15,16);
			fighterInitialize(&fighterSonya2, false, &soundHandler);
			fighterShow(&fighterSonya2);
			break;
		case 4:
			//Raiden
			jsfLoadClut((unsigned short *)(void *)(BMPRAIDEN_clut),15,16);
			fighterInitialize(&fighterRaiden2, false, &soundHandler);
			fighterShow(&fighterRaiden2);
			sprite[LIGHTNING2].active = R_is_active;
			break;
		case 5:
			//Liu Kang
			jsfLoadClut((unsigned short *)(void *)(BMPKANG_clut),15,16);
			fighterInitialize(&fighterKang2, false, &soundHandler);
			fighterShow(&fighterKang2);
			break;
		case 6:
			//Scorpion
			jsfLoadClut((unsigned short *)(void *)(BMPSCORPION_clut),15,16);
			fighterInitialize(&fighterScorpion2, false, &soundHandler);
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
			jsfLoadClut((unsigned short *)(void *)(BMPSCORPION_clut),14,16);
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
			jsfLoadClut((unsigned short *)(void *)(BMPSCORPION_clut),15,16);
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