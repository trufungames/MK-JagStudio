
#include "common.h"
#include "spritemovements.h"


void moveUp (void)
{
	//sprite[sprBugIndex].y_ -= 2;
}


void moveDown (void)
{
	//sprite[sprBugIndex].y_ += 2;
}


void moveRight (void)
{
	sprite[BG1_TEMPLE_LEFT].x_ -= 1.0f;
	sprite[BG1_TEMPLE_RIGHT].x_ -= 1.0f;
	sprite[BG1_BACKDROP].x_ -= 2.0f;
	sprite[BG1_FLAME1].x_ -= 2.0f;
	sprite[BG1_FLAME1].x_ -= 2.0f;
}


void moveLeft (void)
{
	sprite[BG1_TEMPLE_LEFT].x_ += 1.0f;
	sprite[BG1_TEMPLE_RIGHT].x_ += 1.0f;
	sprite[BG1_BACKDROP].x_ += 2.0f;
	sprite[BG1_FLAME1].x_ += 2.0f;
	sprite[BG1_FLAME1].x_ += 2.0f;
}
