
#include "common.h"
#include "spritemovements.h"


void moveUp (void)
{
	sprite[sprBugIndex].y_ -= 2;
}


void moveDown (void)
{
	sprite[sprBugIndex].y_ += 2;
}


void moveRight (void)
{
	sprite[sprBugIndex].x_ += 2;
}


void moveLeft (void)
{
	sprite[sprBugIndex].x_ -= 2;
}
