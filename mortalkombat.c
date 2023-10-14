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
static int     pad1;
static int 	   pad2;

// *************************************************



// *************************************************
//               User Prototypes
// *************************************************
void fireButton (void);

void basicmain()
{
	pad1=0;
	pad2=0;
/*
The formula (C-notation) to get a 16-bit color value from the red/green/blue parts is as follows:

color_16_bit = (red << 11) + (green << 5) + blue

where red and blue has a range of 0…31 and green has a range of 0…63, the maximum value for red/green/blue refers to 100% color intensity. Shifting red left by 11, shifting green left by 5 and adding the shifted red and green value and blue together delivers the 16-bit color value.
*/
	unsigned short bg_color = (21 << 11) + (57 << 5) + 31;  //(red << 11) + (green << 5) + blue
	*(volatile unsigned short*)(BG)=(volatile unsigned short)bg_color;		// Set Background colour.

rapDebugSetXY(5,20);
rapDebugInverse();

//rapDebugPrint "This is some debug text";
rapDebugSetMonitor(0, (char *)(sprite[BG1_BACKDROP].x));

rapSetClock(0);
rapClockMode = Clock_Countup;

//load cluts
jsfLoadClut((unsigned short *)(void *)(BMP_PG_0_clut),0,112);
jsfLoadClut((unsigned short *)(void *)(BMPSCORPION_clut),14,16);
jsfLoadClut((unsigned short *)(void *)(BMPKANO_clut),15,16);

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
	{ 80, 144, 480, 0, 6 },
	{ 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0}
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

fighterInitialize(&fighterScorpion, true);
fighterInitialize(&fighterKano, false);

	//Main Loop
	for(;;)
	{
		pad1=jsfGetPad(LEFT_PAD);
		pad2=jsfGetPad(RIGHT_PAD);
		
		fighterUpdate(&fighterScorpion, &scorpionAnimator, scorpionIdleFrames, scorpionWalkFrames, scorpionDuckFrames, scorpionBlockFrames, scorpionBlockDuckFrames);
		fighterUpdate(&fighterKano, &kanoAnimator, kanoIdleFrames, kanoWalkFrames, kanoDuckFrames, kanoBlockFrames, kanoBlockDuckFrames);
		
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