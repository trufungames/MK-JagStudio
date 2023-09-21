
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
	sprite[sprTempleLeft].x_ -= 1.0f;
	sprite[sprTempleRight].x_ -= 1.0f;
	sprite[sprPG_Backdrop].x_ -= 2.0f;
}


void moveLeft (void)
{
	sprite[sprTempleLeft].x_ += 1.0f;
	sprite[sprTempleRight].x_ += 1.0f;
	sprite[sprPG_Backdrop].x_ += 2.0f;
}
