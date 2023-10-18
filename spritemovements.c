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


void bgScrollRight (float delta)
{
	if (sprite[BG1_BACKDROP].x_ >= -692.0f)
	{
		sprite[BG1_TEMPLE_LEFT].x_ -= 1.0f * delta;
		sprite[BG1_TEMPLE_RIGHT].x_ -= 1.0f * delta;
		sprite[BG1_BACKDROP].x_ -= 2.0f * delta;
		sprite[BG1_FLAME1].x_ -= 2.0f * delta;
		sprite[BG1_FLAME2].x_ -= 2.0f * delta;
	}
}


void bgScrollLeft (float delta)
{
	if (sprite[BG1_BACKDROP].x_ <= -2.0f)
	{
		sprite[BG1_TEMPLE_LEFT].x_ += 1.0f * delta;
		sprite[BG1_TEMPLE_RIGHT].x_ += 1.0f * delta;
		sprite[BG1_BACKDROP].x_ += 2.0f * delta;
		sprite[BG1_FLAME1].x_ += 2.0f * delta;
		sprite[BG1_FLAME2].x_ += 2.0f * delta;
	}
}
