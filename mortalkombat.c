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
#include "sound.h"



// *************************************************
//            User Global Variables
// *************************************************
static int     pad1;

// *************************************************



// *************************************************
//               User Prototypes
// *************************************************
void fireButton (void);


void basicmain()
{
	pad1=0;
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
jsfLoadClut((unsigned short *)(void *)(BMPSCORPION_clut),0,16);
jsfLoadClut((unsigned short *)(void *)(BMPKANO_clut),1,16);

//Scorpion animation frames
SpriteAnimator scorpionShadowAnimator = {
	SCORPION_SHADOW, 0.125f, BMPSCORPIONSHADOW, 0, 0
};
AnimationFrame scorpionShadowFrames[] = {
	{ 80, 32, 0, 0, 6 },
	{ 80, 32, 80, 0, 6 },
	{ 80, 32, 160, 0, 6 },
	{ 80, 32, 240, 0, 6 },
	{ 80, 32, 320, 0, 6 },
	{ 80, 32, 400, 0, 6 },
	{ 80, 32, 480, 0, 6 }
};

SpriteAnimator scorpionAnimator = {
	SCORPION, 0.5f, BMPSCORPION, 0, 0
};
AnimationFrame scorpionFrames[] = {
	{ 80, 144, 0, 0, 6 },
	{ 80, 144, 80, 0, 6 },
	{ 80, 144, 160, 0, 6 },
	{ 80, 144, 240, 0, 6 },
	{ 80, 144, 320, 0, 6 },
	{ 80, 144, 400, 0, 6 },
	{ 80, 144, 480, 0, 6 }
};

//Kano animation frames
SpriteAnimator kanoAnimator = {
	KANO, 0.5f, BMPKANO, 0, 0
};
AnimationFrame kanoFrames[] = {
	{ 80, 144, 0, 0, 5 },
	{ 80, 144, 80, 0, 5 },
	{ 80, 144, 160, 0, 5 },
	{ 80, 144, 240, 0, 5 },
	{ 80, 144, 320, 0, 5 },
	{ 80, 144, 400, 0, 5 },
	{ 80, 144, 480, 0, 5 }
};

	//Main Loop
	for(;;)
	{
		pad1=jsfGetPad(LEFT_PAD);
		
		if(pad1 & JAGPAD_LEFT)
		{
			bgScrollLeft();
		}
		else if(pad1 & JAGPAD_RIGHT)
		{
			bgScrollRight();
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

		//updateSpriteAnimator(&scorpionShadowAnimator, scorpionShadowFrames, SCORPION_IDLE_FRAME_COUNT, true, true);
		updateSpriteAnimator(&scorpionAnimator, scorpionFrames, SCORPION_IDLE_FRAME_COUNT, true, true);
		
		updateSpriteAnimator(&kanoAnimator, kanoFrames, KANO_IDLE_FRAME_COUNT, true, true);

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




