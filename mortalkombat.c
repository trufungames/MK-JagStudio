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
	
	jsfSetFontIndx(1);
	jsfSetFontSize(1);
	rapLocate(0,20);
	js_r_textbuffer=(char *)"        JagStudio C Template";
	rapPrint();
	
	jsfSetFontIndx(0);
	jsfSetFontSize(0);
	rapLocate(16,50);
	js_r_textbuffer=(char *)"DPAD to Move";
	rapPrint();
	
	rapLocate(16,60);
	js_r_textbuffer=(char *)"B to Make a Sound";
	rapPrint();

	*(volatile unsigned short*)(BG)=(volatile unsigned short)2047;		// Set Background colour.


	//Main Loop
	for(;;)
	{
		pad1=jsfGetPad(LEFT_PAD);
		
		if(pad1 & JAGPAD_UP)
		{
			moveUp();
		}
		else if(pad1 & JAGPAD_DOWN)
		{
			moveDown();
		}
		if(pad1 & JAGPAD_LEFT)
		{
			moveLeft();
		}
		else if(pad1 & JAGPAD_RIGHT)
		{
			moveRight();
		}
		
		
		pad1=jsfGetPadPressed(LEFT_PAD);
		
		if(pad1 & JAGPAD_B)
		{
			fireButton();
		}
		
		
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




