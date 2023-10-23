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
static int currentScreen = 0;  //0 = Attract Mode, 1 = Choose Your Fighter, 2 = Fight
int p1Cursor = 1;
int p2Cursor = 2; 
bool onScreenChooseFighter = false;
bool onScreenVsBattle = false;
static int BLACKPAL[128];


//Scorpion animation frames
static SpriteAnimator cageAnimator = {
	CAGE, 0.5f, BMPCAGE, 0, 0
};

static SpriteAnimator cageAnimator2 = {
	CAGE2, 0.5f, BMPCAGE, 0, 0
};

static AnimationFrame cageIdleFrames[] = {
	{ 96, 144, 0, 0, 6 },
	{ 96, 144, 96, 0, 6 },
	{ 96, 144, 192, 0, 6 },
	{ 96, 144, 288, 0, 6 },
	{ 96, 144, 384, 0, 6 },
	{ 96, 144, 480, 0, 6 },
	{ 96, 144, 576, 0, 6 }
};
static AnimationFrame cageWalkFrames[] = {
	{ 96, 144, 672, 0, 6 },
	{ 96, 144, 768, 0, 6 },
	{ 96, 144, 864, 0, 6 },
	{ 96, 144, 0, 144, 6 },
	{ 96, 144, 96, 144, 6 },
	{ 96, 144, 192, 144, 6 },
	{ 96, 144, 288, 144, 6 },
	{ 96, 144, 384, 144, 6 },
	{ 96, 144, 480, 144, 6 }
};
static AnimationFrame cageDuckFrames[] = {
	{ 96, 144, 576, 144, 3 },
	{ 96, 144, 672, 144, 3 },
	{ 96, 144, 768, 144, 3 }
};
static AnimationFrame cageBlockFrames[] = {
	{ 96, 144, 864, 144, 3 },
	{ 96, 144, 0, 288, 3 },
	{ 96, 144, 96, 288, 3 }
};
static AnimationFrame cageBlockDuckFrames[] = {
	{ 80, 144, 192, 288, 3 },
	{ 80, 144, 288, 288, 3 }
};

//Liu Kang animation frames
static SpriteAnimator kangAnimator = {
	KANG, 0.5f, BMPKANG, 0, 0
};

static SpriteAnimator kangAnimator2 = {
	KANG2, 0.5f, BMPKANG, 0, 0
};

static AnimationFrame kangIdleFrames[] = {
	{ 80, 144, 0, 0, 7 },
	{ 80, 144, 80, 0, 7 },
	{ 80, 144, 160, 0, 7 },
	{ 80, 144, 240, 0, 7 },
	{ 80, 144, 320, 0, 7 },
	{ 80, 144, 400, 0, 7 },
	{ 80, 144, 480, 0, 7 },
	{ 80, 144, 560, 0, 7 }
};
static AnimationFrame kangWalkFrames[] = {
	{ 80, 144, 640, 0, 6 },
	{ 80, 144, 720, 0, 6 },
	{ 80, 144, 800, 0, 6 },
	{ 80, 144, 880, 0, 6 },
	{ 80, 144, 0, 144, 6 },
	{ 80, 144, 80, 144, 6 },
	{ 80, 144, 160, 144, 6 },
	{ 80, 144, 240, 144, 6 },
	{ 80, 144, 320, 144, 6 }
};
static AnimationFrame kangDuckFrames[] = {
	{ 80, 144, 400, 144, 3 },
	{ 80, 144, 480, 144, 3 },
	{ 80, 144, 560, 144, 3 }
};
static AnimationFrame kangBlockFrames[] = {
	{ 80, 144, 640, 144, 3 },
	{ 80, 144, 720, 144, 3 },
	{ 80, 144, 800, 144, 3 }
};
static AnimationFrame kangBlockDuckFrames[] = {
	{ 80, 144, 880, 144, 3 },
	{ 80, 144, 0, 288, 3 }
};

//Raiden animation frames
static SpriteAnimator raidenAnimator = {
	RAIDEN, 0.5f, BMPRAIDEN, 0, 0
};

static SpriteAnimator raidenAnimator2 = {
	RAIDEN2, 0.5f, BMPRAIDEN, 0, 0
};

static AnimationFrame raidenIdleFrames[] = {
	{ 80, 144, 0, 0, 6 },
	{ 80, 144, 80, 0, 6 },
	{ 80, 144, 160, 0, 6 },
	{ 80, 144, 240, 0, 6 },
	{ 80, 144, 320, 0, 6 },
	{ 80, 144, 400, 0, 6 },
	{ 80, 144, 480, 0, 6 },
	{ 80, 144, 560, 0, 6 },
	{ 80, 144, 640, 0, 6 },
	{ 80, 144, 720, 0, 6 }
};
static AnimationFrame raidenWalkFrames[] = {
	{ 80, 144, 800, 0, 6 },
	{ 80, 144, 880, 0, 6 },
	{ 80, 144, 0, 144, 6 },
	{ 80, 144, 80, 144, 6 },
	{ 80, 144, 160, 144, 6 },
	{ 80, 144, 240, 144, 6 },
	{ 80, 144, 320, 144, 6 },
	{ 80, 144, 400, 144, 6 },
	{ 80, 144, 480, 144, 6 }
};
static AnimationFrame raidenDuckFrames[] = {
	{ 80, 144, 560, 144, 3 },
	{ 80, 144, 640, 144, 3 },
	{ 80, 144, 720, 144, 3 }
};
static AnimationFrame raidenBlockFrames[] = {
	{ 80, 144, 800, 144, 3 },
	{ 80, 144, 880, 144, 3 },
	{ 80, 144, 0, 288, 3 }
};
static AnimationFrame raidenBlockDuckFrames[] = {
	{ 80, 144, 80, 288, 3 },
	{ 80, 144, 160, 288, 3 }
};

//Subzero animation frames
static SpriteAnimator subzeroAnimator = {
	SUBZERO, 0.5f, BMPSUBZERO, 0, 0
};

static SpriteAnimator subzeroAnimator2 = {
	SUBZERO2, 0.5f, BMPSUBZERO, 0, 0
};

static AnimationFrame subzeroIdleFrames[] = {
	{ 80, 144, 0, 0, 6 },
	{ 80, 144, 80, 0, 6 },
	{ 80, 144, 160, 0, 6 },
	{ 80, 144, 240, 0, 6 },
	{ 80, 144, 320, 0, 6 },
	{ 80, 144, 400, 0, 6 },
	{ 80, 144, 480, 0, 6 },
	{ 80, 144, 560, 0, 6 },
	{ 80, 144, 640, 0, 6 },
	{ 80, 144, 720, 0, 6 },
	{ 80, 144, 800, 0, 6 },
	{ 80, 144, 880, 0, 6 }
};
static AnimationFrame subzeroWalkFrames[] = {
	{ 80, 144, 0, 144, 6 },
	{ 80, 144, 80, 144, 6 },
	{ 80, 144, 160, 144, 6 },
	{ 80, 144, 240, 144, 6 },
	{ 80, 144, 320, 144, 6 },
	{ 80, 144, 400, 144, 6 },
	{ 80, 144, 480, 144, 6 },
	{ 80, 144, 560, 144, 6 },
	{ 80, 144, 640, 144, 6 }
};
static AnimationFrame subzeroDuckFrames[] = {
	{ 80, 144, 720, 144, 3 },
	{ 80, 144, 800, 144, 3 },
	{ 80, 144, 880, 144, 3 }
};
static AnimationFrame subzeroBlockFrames[] = {
	{ 80, 144, 0, 288, 3 },
	{ 80, 144, 80, 288, 3 },
	{ 80, 144, 160, 288, 3 }
};
static AnimationFrame subzeroBlockDuckFrames[] = {
	{ 80, 144, 240, 288, 3 },
	{ 80, 144, 320, 288, 3 }
};

//Sonya animation frames
static SpriteAnimator sonyaAnimator = {
	SONYA, 0.5f, BMPSONYA, 0, 0
};

static SpriteAnimator sonyaAnimator2 = {
	SONYA2, 0.5f, BMPSONYA, 0, 0
};

static AnimationFrame sonyaIdleFrames[] = {
	{ 80, 144, 0, 0, 6 },
	{ 80, 144, 80, 0, 6 },
	{ 80, 144, 160, 0, 6 },
	{ 80, 144, 240, 0, 6 },
	{ 80, 144, 320, 0, 6 },
	{ 80, 144, 400, 0, 6 },
	{ 80, 144, 480, 0, 6 }
};
static AnimationFrame sonyaWalkFrames[] = {
	{ 80, 144, 560, 0, 6 },
	{ 80, 144, 640, 0, 6 },
	{ 80, 144, 720, 0, 6 },
	{ 80, 144, 800, 0, 6 },
	{ 80, 144, 880, 0, 6 },
	{ 80, 144, 0, 144, 6 },
	{ 80, 144, 80, 144, 6 }
};
static AnimationFrame sonyaDuckFrames[] = {
	{ 80, 144, 160, 144, 3 },
	{ 80, 144, 240, 144, 3 }
};
static AnimationFrame sonyaBlockFrames[] = {
	{ 80, 144, 320, 144, 3 },
	{ 80, 144, 400, 144, 3 },
	{ 80, 144, 480, 144, 3 }
};
static AnimationFrame sonyaBlockDuckFrames[] = {
	{ 80, 144, 560, 144, 3 },
	{ 80, 144, 640, 144, 3 }
};

//Scorpion animation frames
static SpriteAnimator scorpionAnimator = {
	SCORPION, 0.5f, BMPSCORPION, 0, 0
};

static SpriteAnimator scorpionAnimator2 = {
	SCORPION2, 0.5f, BMPSCORPION, 0, 0
};

static AnimationFrame scorpionIdleFrames[] = {
	{ 80, 144, 0, 0, 6 },
	{ 80, 144, 80, 0, 6 },
	{ 80, 144, 160, 0, 6 },
	{ 80, 144, 240, 0, 6 },
	{ 80, 144, 320, 0, 6 },
	{ 80, 144, 400, 0, 6 },
	{ 80, 144, 480, 0, 6 }
};
static AnimationFrame scorpionWalkFrames[] = {
	{ 80, 144, 560, 0, 6 },
	{ 80, 144, 640, 0, 6 },
	{ 80, 144, 720, 0, 6 },
	{ 80, 144, 800, 0, 6 },
	{ 80, 144, 880, 0, 6 },
	{ 80, 144, 0, 144, 6 },
	{ 80, 144, 80, 144, 6 },
	{ 80, 144, 160, 144, 6 },
	{ 80, 144, 240, 144, 6 },
	{ 80, 144, 320, 144, 6 }
};
static AnimationFrame scorpionDuckFrames[] = {
	{ 80, 144, 400, 144, 3 },
	{ 80, 144, 480, 144, 3 },
	{ 80, 144, 560, 144, 3 }
};
static AnimationFrame scorpionBlockFrames[] = {
	{ 80, 144, 640, 144, 3 },
	{ 80, 144, 720, 144, 3 },
	{ 80, 144, 800, 144, 3 }
};
static AnimationFrame scorpionBlockDuckFrames[] = {
	{ 80, 144, 880, 144, 3 },
	{ 80, 144, 0, 288, 3 }
};

//Kano animation frames
static SpriteAnimator kanoAnimator = {
	KANO, 0.5f, BMPKANO, 0, 0
};

static SpriteAnimator kanoAnimator2 = {
	KANO2, 0.5f, BMPKANO, 0, 0
};

static AnimationFrame kanoIdleFrames[] = {
	{ 80, 144, 0, 0, 5 },
	{ 80, 144, 80, 0, 5 },
	{ 80, 144, 160, 0, 5 },
	{ 80, 144, 240, 0, 5 },
	{ 80, 144, 320, 0, 5 },
	{ 80, 144, 400, 0, 5 },
	{ 80, 144, 480, 0, 5 }
};
static AnimationFrame kanoWalkFrames[] = {
	{ 80, 144, 560, 0, 6 },
	{ 80, 144, 640, 0, 6 },
	{ 80, 144, 720, 0, 6 },
	{ 80, 144, 800, 0, 6 },
	{ 80, 144, 880, 0, 6 },
	{ 80, 144, 0, 144, 6 },
	{ 80, 144, 80, 144, 6 },
	{ 80, 144, 160, 144, 6 },
	{ 80, 144, 240, 144, 6 }
};
static AnimationFrame kanoDuckFrames[] = {
	{ 80, 144, 320, 144, 3 },
	{ 80, 144, 400, 144, 3 },
	{ 80, 144, 480, 144, 3 }
};
static AnimationFrame kanoBlockFrames[] = {
	{ 80, 144, 560, 144, 3 },
	{ 80, 144, 640, 144, 3 },
	{ 80, 144, 720, 144, 3 }
};
static AnimationFrame kanoBlockDuckFrames[] = {
	{ 80, 144, 800, 144, 3 },
	{ 80, 144, 880, 144, 3 }
};

static SpriteAnimator lightningAnimator = {
	LIGHTNING, 0.5f, BMP_LIGHTNING, 0, 0
};

static SpriteAnimator lightning2Animator = {
	LIGHTNING2, 0.5f, BMP_LIGHTNING, 0, 0
};

static AnimationFrame lightningFrames[] = {
	{ 80, 144, 0, 0, 5 },
	{ 80, 144, 80, 0, 5 },
	{ 80, 144, 160, 0, 5 },
	{ 80, 144, 240, 0, 5 },
	{ 80, 144, 320, 0, 5 },
	{ 80, 144, 400, 0, 5 },
	{ 80, 144, 480, 0, 5 },
	{ 80, 144, 560, 0, 5 },
	{ 80, 144, 640, 0, 5 },
	{ 80, 144, 720, 0, 5 },
	{ 80, 144, 0, 144, 5 },
	{ 80, 144, 80, 144, 5 },
	{ 80, 144, 160, 144, 5 },
	{ 80, 144, 240, 144, 5 },
	{ 80, 144, 320, 144, 5 },
	{ 80, 144, 400, 144, 5 },
	{ 80, 144, 480, 144, 5 },
	{ 80, 144, 560, 144, 5 },
	{ 80, 144, 640, 144, 5 },
	{ 80, 144, 720, 144, 5 },
	{ 80, 144, 0, 288, 5 },
	{ 80, 144, 80, 288, 5 },
	{ 80, 144, 160, 288, 5 },
	{ 80, 144, 240, 288, 5 },
	{ 80, 144, 320, 288, 5 },
	{ 80, 144, 400, 288, 5 },
	{ 80, 144, 480, 288, 5 },
	{ 80, 144, 560, 288, 5 },
	{ 80, 144, 640, 288, 5 },
	{ 80, 144, 720, 288, 5 }
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
	SCORPION_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterKano = {
	KANO, BMPKANO,
	KANO_IDLE_FRAME_COUNT,
	KANO_WALK_FRAME_COUNT,
	KANO_DUCK_FRAME_COUNT,
	KANO_BLOCK_FRAME_COUNT,
	KANO_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterCage = {
	CAGE, BMPCAGE,
	CAGE_IDLE_FRAME_COUNT,
	CAGE_WALK_FRAME_COUNT,
	CAGE_DUCK_FRAME_COUNT,
	CAGE_BLOCK_FRAME_COUNT,
	CAGE_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterKang = {
	KANG, BMPKANG,
	KANG_IDLE_FRAME_COUNT,
	KANG_WALK_FRAME_COUNT,
	KANG_DUCK_FRAME_COUNT,
	KANG_BLOCK_FRAME_COUNT,
	KANG_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterRaiden = {
	RAIDEN, BMPRAIDEN,
	RAIDEN_IDLE_FRAME_COUNT,
	RAIDEN_WALK_FRAME_COUNT,
	RAIDEN_DUCK_FRAME_COUNT,
	RAIDEN_BLOCK_FRAME_COUNT,
	RAIDEN_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterSubzero = {
	SUBZERO, BMPSUBZERO,
	SUBZERO_IDLE_FRAME_COUNT,
	SUBZERO_WALK_FRAME_COUNT,
	SUBZERO_DUCK_FRAME_COUNT,
	SUBZERO_BLOCK_FRAME_COUNT,
	SUBZERO_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterSonya = {
	SONYA, BMPSONYA,
	SONYA_IDLE_FRAME_COUNT,
	SONYA_WALK_FRAME_COUNT,
	SONYA_DUCK_FRAME_COUNT,
	SONYA_BLOCK_FRAME_COUNT,
	SONYA_BLOCK_DUCK_FRAME_COUNT
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
	SCORPION_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterKano2 = {
	KANO2, BMPKANO,
	KANO_IDLE_FRAME_COUNT,
	KANO_WALK_FRAME_COUNT,
	KANO_DUCK_FRAME_COUNT,
	KANO_BLOCK_FRAME_COUNT,
	KANO_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterCage2 = {
	CAGE2, BMPCAGE,
	CAGE_IDLE_FRAME_COUNT,
	CAGE_WALK_FRAME_COUNT,
	CAGE_DUCK_FRAME_COUNT,
	CAGE_BLOCK_FRAME_COUNT,
	CAGE_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterKang2 = {
	KANG2, BMPKANG,
	KANG_IDLE_FRAME_COUNT,
	KANG_WALK_FRAME_COUNT,
	KANG_DUCK_FRAME_COUNT,
	KANG_BLOCK_FRAME_COUNT,
	KANG_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterRaiden2 = {
	RAIDEN2, BMPRAIDEN,
	RAIDEN_IDLE_FRAME_COUNT,
	RAIDEN_WALK_FRAME_COUNT,
	RAIDEN_DUCK_FRAME_COUNT,
	RAIDEN_BLOCK_FRAME_COUNT,
	RAIDEN_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterSubzero2 = {
	SUBZERO2, BMPSUBZERO,
	SUBZERO_IDLE_FRAME_COUNT,
	SUBZERO_WALK_FRAME_COUNT,
	SUBZERO_DUCK_FRAME_COUNT,
	SUBZERO_BLOCK_FRAME_COUNT,
	SUBZERO_BLOCK_DUCK_FRAME_COUNT
};

static Fighter fighterSonya2 = {
	SONYA2, BMPSONYA,
	SONYA_IDLE_FRAME_COUNT,
	SONYA_WALK_FRAME_COUNT,
	SONYA_DUCK_FRAME_COUNT,
	SONYA_BLOCK_FRAME_COUNT,
	SONYA_BLOCK_DUCK_FRAME_COUNT
};

// *************************************************


// *************************************************
//               User Prototypes
// *************************************************
void switchScreenChooseFighter();
void switchScreenVsBattle();
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
	bool enableSFX = false;
	int myTicks = 0;
	int p1Selected = -1;
	int p2Selected = -1;
	bool chooseFighterDone = false;
/*
The formula (C-notation) to get a 16-bit color value from the red/green/blue parts is as follows:

color_16_bit = (red << 11) + (green << 5) + blue

where red and blue has a range of 0…31 and green has a range of 0…63, the maximum value for red/green/blue refers to 100% color intensity. Shifting red left by 11, shifting green left by 5 and adding the shifted red and green value and blue together delivers the 16-bit color value.
*/
	unsigned short bg_color = 0;
	
	if (currentScreen == 0 || currentScreen == 1)
	{
		bg_color = 0;
	}
	else if (currentScreen == 2)
	{
		bg_color = (21 << 11) + (57 << 5) + 31;  //(red << 11) + (green << 5) + blue
	}

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

		if (currentScreen == 0)
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
			}

			if (fadedIn && !fadedOut)
			{
				if (rapTicks > gameStartTicks + 120)
				{
					for (int i = 0; i < 60; i++)
					{
						rapFadeClut(0,256,BLACKPAL);
						jsfVsync(0);
					}

					fadedOut = true;
					switchScreenChooseFighter();
				}
			}
		}
		
		if (onScreenChooseFighter)//(currentScreen == 1)
		{
			/////////////////////////////////////////
			// Choose Your Fighter
			/////////////////////////////////////////

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
				sfxSelect(enableSFX);
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
				sfxSelect(enableSFX);
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
						sfxJohnnyCage(enableSFX);
						break;
					case 1:
						sfxKano(enableSFX);
						break;
					case 2:
						sfxSubzero(enableSFX);
						break;
					case 3:
						sfxSonya(enableSFX);
						break;
					case 4:
						sfxRaiden(enableSFX);
						break;
					case 5:
						sfxLiuKang(enableSFX);
						break;
					case 6:
						sfxScorpion(enableSFX);
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
						sfxJohnnyCage(enableSFX);
						break;
					case 1:
						sfxKano(enableSFX);
						break;
					case 2:
						sfxSubzero(enableSFX);
						break;
					case 3:
						sfxSonya(enableSFX);
						break;
					case 4:
						sfxRaiden(enableSFX);
						break;
					case 5:
						sfxLiuKang(enableSFX);
						break;
					case 6:
						sfxScorpion(enableSFX);
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

				switchScreenVsBattle();
			}
		}
		else if (onScreenVsBattle)
		{

		}
		else if (currentScreen == 2)
		{
			/////////////////////////////////////////
			// Fight!
			/////////////////////////////////////////
			pad1=jsfGetPad(LEFT_PAD);
			pad2=jsfGetPad(RIGHT_PAD);



			fighterUpdate(delta, &fighterScorpion, &scorpionAnimator, scorpionIdleFrames, scorpionWalkFrames, scorpionDuckFrames, scorpionBlockFrames, scorpionBlockDuckFrames, false);
			//fighterUpdate(&fighterCage, &cageAnimator, cageIdleFrames, cageWalkFrames, cageDuckFrames, cageBlockFrames, cageBlockDuckFrames, false);
			//fighterUpdate(&fighterKang, &kangAnimator, kangIdleFrames, kangWalkFrames, kangDuckFrames, kangBlockFrames, kangBlockDuckFrames, false);
			//fighterUpdate(&fighterRaiden, &raidenAnimator, raidenIdleFrames, raidenWalkFrames, raidenDuckFrames, raidenBlockFrames, raidenBlockDuckFrames, false);
			//fighterUpdate(&fighterSubzero, &subzeroAnimator, subzeroIdleFrames, subzeroWalkFrames, subzeroDuckFrames, subzeroBlockFrames, subzeroBlockDuckFrames, false);
			//fighterUpdate(&fighterSonya, &sonyaAnimator, sonyaIdleFrames, sonyaWalkFrames, sonyaDuckFrames, sonyaBlockFrames, sonyaBlockDuckFrames, false);
			fighterUpdate(delta, &fighterKano, &kanoAnimator, kanoIdleFrames, kanoWalkFrames, kanoDuckFrames, kanoBlockFrames, kanoBlockDuckFrames, true);
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
			rapDebugSetVisible(DEBUG_SHOW);
		}
		else if (pad1 & JAGPAD_HASH)
		{
			sprite[P1_HB_BODY].active = R_is_inactive;
			sprite[P1_HB_DUCK].active = R_is_inactive;
			sprite[P1_HB_ATTACK].active = R_is_inactive;
			sprite[P2_HB_BODY].active = R_is_inactive;
			sprite[P2_HB_DUCK].active = R_is_inactive;
			sprite[P2_HB_ATTACK].active = R_is_inactive;
			rapDebugSetVisible(DEBUG_HIDE);
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
	onScreenChooseFighter = true;
}

void switchScreenVsBattle()
{
	jsfLoadClut((unsigned short *)(void *)(BMP_BATTLE_clut),0,16);
	jsfLoadClut((unsigned short *)(void *)(BMP_BG_STONE_clut),2,16);
	rapSetActiveList(2);
	onScreenChooseFighter = false;
	onScreenVsBattle = true;
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