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
static int lastTicks = 0;
static int currrentScreen = 0;  //0 = Choose Your Fighter, 1 = Fight
static int p1Cursor = 1;
static int p2Cursor = 2; 

// *************************************************



// *************************************************
//               User Prototypes
// *************************************************
void fireButton (void);

void basicmain()
{
	pad1=0;
	pad2=0;
	if (!rapNTSCFlag)
	{
		ticksPerSec = 50;
	}
	lastTicks = 0;
/*
The formula (C-notation) to get a 16-bit color value from the red/green/blue parts is as follows:

color_16_bit = (red << 11) + (green << 5) + blue

where red and blue has a range of 0…31 and green has a range of 0…63, the maximum value for red/green/blue refers to 100% color intensity. Shifting red left by 11, shifting green left by 5 and adding the shifted red and green value and blue together delivers the 16-bit color value.
*/
	unsigned short bg_color = 0;
	
	if (currrentScreen == 0)
	{
		bg_color = 0;
	}
	else if (currrentScreen == 1)
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
jsfLoadClut((unsigned short *)(void *)(BMP_CHOOSEFIGHTER_clut),0,95);

//jsfLoadClut((unsigned short *)(void *)(BMPSCORPION_clut),14,16);
//jsfLoadClut((unsigned short *)(void *)(BMPCAGE_clut),14,16);
//jsfLoadClut((unsigned short *)(void *)(BMPKANG_clut),14,16);
//jsfLoadClut((unsigned short *)(void *)(BMPRAIDEN_clut),14,16);
jsfLoadClut((unsigned short *)(void *)(BMPSUBZERO_clut),15,16);
//jsfLoadClut((unsigned short *)(void *)(BMPSONYA_clut),14,16);
jsfLoadClut((unsigned short *)(void *)(BMPKANO_clut),14,16);

//Scorpion animation frames
SpriteAnimator cageAnimator = {
	CAGE, 0.5f, BMPCAGE, 0, 0
};

AnimationFrame cageIdleFrames[] = {
	{ 96, 144, 0, 0, 6 },
	{ 96, 144, 96, 0, 6 },
	{ 96, 144, 192, 0, 6 },
	{ 96, 144, 288, 0, 6 },
	{ 96, 144, 384, 0, 6 },
	{ 96, 144, 480, 0, 6 },
	{ 96, 144, 576, 0, 6 }
};
AnimationFrame cageWalkFrames[] = {
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
AnimationFrame cageDuckFrames[] = {
	{ 96, 144, 576, 144, 3 },
	{ 96, 144, 672, 144, 3 },
	{ 96, 144, 768, 144, 3 }
};
AnimationFrame cageBlockFrames[] = {
	{ 96, 144, 864, 144, 3 },
	{ 96, 144, 0, 288, 3 },
	{ 96, 144, 96, 288, 3 }
};
AnimationFrame cageBlockDuckFrames[] = {
	{ 80, 144, 192, 288, 3 },
	{ 80, 144, 288, 288, 3 }
};

//Liu Kang animation frames
SpriteAnimator kangAnimator = {
	KANG, 0.5f, BMPKANG, 0, 0
};

AnimationFrame kangIdleFrames[] = {
	{ 80, 144, 0, 0, 6 },
	{ 80, 144, 80, 0, 6 },
	{ 80, 144, 160, 0, 6 },
	{ 80, 144, 240, 0, 6 },
	{ 80, 144, 320, 0, 6 },
	{ 80, 144, 400, 0, 6 },
	{ 80, 144, 480, 0, 6 },
	{ 80, 144, 560, 0, 6 }
};
AnimationFrame kangWalkFrames[] = {
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
AnimationFrame kangDuckFrames[] = {
	{ 80, 144, 400, 144, 3 },
	{ 80, 144, 480, 144, 3 },
	{ 80, 144, 560, 144, 3 }
};
AnimationFrame kangBlockFrames[] = {
	{ 80, 144, 640, 144, 3 },
	{ 80, 144, 720, 144, 3 },
	{ 80, 144, 800, 144, 3 }
};
AnimationFrame kangBlockDuckFrames[] = {
	{ 80, 144, 880, 144, 3 },
	{ 80, 144, 0, 288, 3 }
};

//Raiden animation frames
SpriteAnimator raidenAnimator = {
	RAIDEN, 0.5f, BMPRAIDEN, 0, 0
};

AnimationFrame raidenIdleFrames[] = {
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
AnimationFrame raidenWalkFrames[] = {
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
AnimationFrame raidenDuckFrames[] = {
	{ 80, 144, 560, 144, 3 },
	{ 80, 144, 640, 144, 3 },
	{ 80, 144, 720, 144, 3 }
};
AnimationFrame raidenBlockFrames[] = {
	{ 80, 144, 800, 144, 3 },
	{ 80, 144, 880, 144, 3 },
	{ 80, 144, 0, 288, 3 }
};
AnimationFrame raidenBlockDuckFrames[] = {
	{ 80, 144, 80, 288, 3 },
	{ 80, 144, 160, 288, 3 }
};

//Subzero animation frames
SpriteAnimator subzeroAnimator = {
	SUBZERO, 0.5f, BMPSUBZERO, 0, 0
};

AnimationFrame subzeroIdleFrames[] = {
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
AnimationFrame subzeroWalkFrames[] = {
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
AnimationFrame subzeroDuckFrames[] = {
	{ 80, 144, 720, 144, 3 },
	{ 80, 144, 800, 144, 3 },
	{ 80, 144, 880, 144, 3 }
};
AnimationFrame subzeroBlockFrames[] = {
	{ 80, 144, 0, 288, 3 },
	{ 80, 144, 80, 288, 3 },
	{ 80, 144, 160, 288, 3 }
};
AnimationFrame subzeroBlockDuckFrames[] = {
	{ 80, 144, 240, 288, 3 },
	{ 80, 144, 320, 288, 3 }
};

//Sonya animation frames
SpriteAnimator sonyaAnimator = {
	SONYA, 0.5f, BMPSONYA, 0, 0
};

AnimationFrame sonyaIdleFrames[] = {
	{ 80, 144, 0, 0, 6 },
	{ 80, 144, 80, 0, 6 },
	{ 80, 144, 160, 0, 6 },
	{ 80, 144, 240, 0, 6 },
	{ 80, 144, 320, 0, 6 },
	{ 80, 144, 400, 0, 6 },
	{ 80, 144, 480, 0, 6 }
};
AnimationFrame sonyaWalkFrames[] = {
	{ 80, 144, 560, 0, 6 },
	{ 80, 144, 640, 0, 6 },
	{ 80, 144, 720, 0, 6 },
	{ 80, 144, 800, 0, 6 },
	{ 80, 144, 880, 0, 6 },
	{ 80, 144, 0, 144, 6 },
	{ 80, 144, 80, 144, 6 }
};
AnimationFrame sonyaDuckFrames[] = {
	{ 80, 144, 160, 144, 3 },
	{ 80, 144, 240, 144, 3 }
};
AnimationFrame sonyaBlockFrames[] = {
	{ 80, 144, 320, 144, 3 },
	{ 80, 144, 400, 144, 3 },
	{ 80, 144, 480, 144, 3 }
};
AnimationFrame sonyaBlockDuckFrames[] = {
	{ 80, 144, 560, 144, 3 },
	{ 80, 144, 640, 144, 3 }
};

//Scorpion animation frames
SpriteAnimator scorpionAnimator = {
	SCORPION, 0.5f, BMPSCORPION, 0, 0
};

AnimationFrame scorpionIdleFrames[] = {
	{ 80, 144, 0, 0, 6 },
	{ 80, 144, 80, 0, 6 },
	{ 80, 144, 160, 0, 6 },
	{ 80, 144, 240, 0, 6 },
	{ 80, 144, 320, 0, 6 },
	{ 80, 144, 400, 0, 6 },
	{ 80, 144, 480, 0, 6 }
};
AnimationFrame scorpionWalkFrames[] = {
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
AnimationFrame scorpionDuckFrames[] = {
	{ 80, 144, 400, 144, 3 },
	{ 80, 144, 480, 144, 3 },
	{ 80, 144, 560, 144, 3 }
};
AnimationFrame scorpionBlockFrames[] = {
	{ 80, 144, 640, 144, 3 },
	{ 80, 144, 720, 144, 3 },
	{ 80, 144, 800, 144, 3 }
};
AnimationFrame scorpionBlockDuckFrames[] = {
	{ 80, 144, 880, 144, 3 },
	{ 80, 144, 0, 288, 3 }
};

//Kano animation frames
SpriteAnimator kanoAnimator = {
	KANO, 0.5f, BMPKANO, 0, 0
};
AnimationFrame kanoIdleFrames[] = {
	{ 80, 144, 0, 0, 5 },
	{ 80, 144, 80, 0, 5 },
	{ 80, 144, 160, 0, 5 },
	{ 80, 144, 240, 0, 5 },
	{ 80, 144, 320, 0, 5 },
	{ 80, 144, 400, 0, 5 },
	{ 80, 144, 480, 0, 5 }
};
AnimationFrame kanoWalkFrames[] = {
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
AnimationFrame kanoDuckFrames[] = {
	{ 80, 144, 320, 144, 3 },
	{ 80, 144, 400, 144, 3 },
	{ 80, 144, 480, 144, 3 }
};
AnimationFrame kanoBlockFrames[] = {
	{ 80, 144, 560, 144, 3 },
	{ 80, 144, 640, 144, 3 },
	{ 80, 144, 720, 144, 3 }
};
AnimationFrame kanoBlockDuckFrames[] = {
	{ 80, 144, 800, 144, 3 },
	{ 80, 144, 880, 144, 3 }
};

Fighter fighterScorpion = {
	SCORPION, BMPSCORPION,
	SCORPION_IDLE_FRAME_COUNT,
	SCORPION_WALK_FRAME_COUNT,
	SCORPION_DUCK_FRAME_COUNT,
	SCORPION_BLOCK_FRAME_COUNT,
	SCORPION_BLOCK_DUCK_FRAME_COUNT
};

Fighter fighterKano = {
	KANO, BMPKANO,
	KANO_IDLE_FRAME_COUNT,
	KANO_WALK_FRAME_COUNT,
	KANO_DUCK_FRAME_COUNT,
	KANO_BLOCK_FRAME_COUNT,
	KANO_BLOCK_DUCK_FRAME_COUNT
};

Fighter fighterCage = {
	CAGE, BMPCAGE,
	CAGE_IDLE_FRAME_COUNT,
	CAGE_WALK_FRAME_COUNT,
	CAGE_DUCK_FRAME_COUNT,
	CAGE_BLOCK_FRAME_COUNT,
	CAGE_BLOCK_DUCK_FRAME_COUNT
};

Fighter fighterKang = {
	KANG, BMPKANG,
	KANG_IDLE_FRAME_COUNT,
	KANG_WALK_FRAME_COUNT,
	KANG_DUCK_FRAME_COUNT,
	KANG_BLOCK_FRAME_COUNT,
	KANG_BLOCK_DUCK_FRAME_COUNT
};

Fighter fighterRaiden = {
	RAIDEN, BMPRAIDEN,
	RAIDEN_IDLE_FRAME_COUNT,
	RAIDEN_WALK_FRAME_COUNT,
	RAIDEN_DUCK_FRAME_COUNT,
	RAIDEN_BLOCK_FRAME_COUNT,
	RAIDEN_BLOCK_DUCK_FRAME_COUNT
};

Fighter fighterSubzero = {
	SUBZERO, BMPSUBZERO,
	SUBZERO_IDLE_FRAME_COUNT,
	SUBZERO_WALK_FRAME_COUNT,
	SUBZERO_DUCK_FRAME_COUNT,
	SUBZERO_BLOCK_FRAME_COUNT,
	SUBZERO_BLOCK_DUCK_FRAME_COUNT
};

Fighter fighterSonya = {
	SONYA, BMPSONYA,
	SONYA_IDLE_FRAME_COUNT,
	SONYA_WALK_FRAME_COUNT,
	SONYA_DUCK_FRAME_COUNT,
	SONYA_BLOCK_FRAME_COUNT,
	SONYA_BLOCK_DUCK_FRAME_COUNT
};

//TODO initialize fighter after they are selected
//fighterInitialize(&fighterScorpion, true);
//fighterInitialize(&fighterCage, true);
//fighterInitialize(&fighterKang, true);
//fighterInitialize(&fighterRaiden, true);
//fighterInitialize(&fighterSubzero, true);
//fighterInitialize(&fighterSonya, true);
//fighterInitialize(&fighterKano, false);

fighterMakeSelectable(&fighterKano, true);
fighterMakeSelectable(&fighterSubzero, false);

	//Main Loop
	for(;;)
	{
		float delta = (float)(rapTicks - lastTicks) / (float)ticksPerSec;
		lastTicks = rapTicks;


		if (currrentScreen == 0)
		{
			pad1 = jsfGetPadPressed(LEFT_PAD);
			pad2 = jsfGetPadPressed(LEFT_PAD);

			bool cursorChanged = false;

			if (pad1 & JAGPAD_LEFT)
			{
				cursorChanged = true;
				p1Cursor--;

				if (p1Cursor < 0)
					p1Cursor = 3;
				else if (p1Cursor == 3)
					p1Cursor = 6;
			}
			else if (pad1 & JAGPAD_RIGHT)
			{
				cursorChanged = true;
				p1Cursor++;

				if (p1Cursor == 4)
					p1Cursor = 0;
				else if (p1Cursor == 7)
					p1Cursor = 4;
			}
			else if (pad1 & JAGPAD_UP)
			{
				cursorChanged = true;
				if (p1Cursor == 4)
					p1Cursor = 1;
				else if (p1Cursor == 6)
					p1Cursor = 2;
			}
			else if (pad1 & JAGPAD_DOWN)
			{
				cursorChanged = true;
				if (p1Cursor == 1)
					p1Cursor = 4;
				else if (p1Cursor == 2)
					p1Cursor = 6;
			}

			if (cursorChanged)
			{
				//cursor changed, so let's move the cursor and show the fighter
				fighterHide(&fighterCage);
				fighterHide(&fighterKano);
				fighterHide(&fighterSubzero);
				fighterHide(&fighterSonya);
				fighterHide(&fighterRaiden);
				fighterHide(&fighterKang);
				fighterHide(&fighterScorpion);

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
						sprite[P1_CURSOR].x_ = 201;
						sprite[P1_CURSOR].y_ = 43;
						break;
					case 3:
						//Sonya
						jsfLoadClut((unsigned short *)(void *)(BMPSONYA_clut),14,16);
						fighterMakeSelectable(&fighterSonya, true);
						fighterShow(&fighterSonya);
						sprite[P1_CURSOR].x_ = 265;
						sprite[P1_CURSOR].y_ = 43;
						break;
					case 4:
						//Raiden
						jsfLoadClut((unsigned short *)(void *)(BMPRAIDEN_clut),14,16);
						fighterMakeSelectable(&fighterRaiden, true);
						fighterShow(&fighterRaiden);
						sprite[P1_CURSOR].x_ = 73;
						sprite[P1_CURSOR].y_ = 123;
						break;
					case 5:
						//Liu Kang
						jsfLoadClut((unsigned short *)(void *)(BMPKANG_clut),14,16);
						fighterMakeSelectable(&fighterKang, true);
						fighterShow(&fighterKang);
						sprite[P1_CURSOR].x_ = 137;
						sprite[P1_CURSOR].y_ = 123;
						break;
					case 6:
						//Scorpion
						jsfLoadClut((unsigned short *)(void *)(BMPSCORPION_clut),14,16);
						fighterMakeSelectable(&fighterScorpion, true);
						fighterShow(&fighterScorpion);
						sprite[P1_CURSOR].x_ = 201;
						sprite[P1_CURSOR].y_ = 123;
						break;
				}
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
		}
		else if (currrentScreen == 1)
		{
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

void fireButton (void)
{
	sfxShoot();
}