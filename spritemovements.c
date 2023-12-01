#include "common.h"
#include "fighter.h"
#include "spritemovements.h"

bool IsScrollingUp = false;
bool IsScrollingDown = false;
bool IsShaking = false;
int LastTicks = 0;
int ShakeTicks = 40;
int bgYOffset = 0;

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
		sprite[BG1_BUSH_1].x_ -= 1.5f * delta;
		sprite[BG1_BUSH_2].x_ -= 1.5f * delta;
		sprite[BG1_BUSH_3].x_ -= 1.5f * delta;
		sprite[BG1_BUSH_4].x_ -= 1.5f * delta;
		sprite[BG1_BACKDROP].x_ -= 2.0f * delta;
		sprite[BG1_FLAME1].x_ -= 2.0f * delta;
		sprite[BG1_FLAME2].x_ -= 2.0f * delta;

		for (int i = 0; i < TOTAL_BLOOD_COUNT; i++)
		{
			sprite[BLOOD_DROP+i].x_ -= 2.0f * delta;
			sprite[BLOOD_POOL+i].x_ -= 2.0f * delta;
		}
	}
}


void bgScrollLeft (float delta)
{
	if (sprite[BG1_BACKDROP].x_ <= -2.0f)
	{
		sprite[BG1_TEMPLE_LEFT].x_ += 1.0f * delta;
		sprite[BG1_TEMPLE_RIGHT].x_ += 1.0f * delta;
		sprite[BG1_BUSH_1].x_ += 1.5f * delta;
		sprite[BG1_BUSH_2].x_ += 1.5f * delta;
		sprite[BG1_BUSH_3].x_ += 1.5f * delta;
		sprite[BG1_BUSH_4].x_ += 1.5f * delta;
		sprite[BG1_BACKDROP].x_ += 2.0f * delta;
		sprite[BG1_FLAME1].x_ += 2.0f * delta;
		sprite[BG1_FLAME2].x_ += 2.0f * delta;

		for (int i = 0; i < TOTAL_BLOOD_COUNT; i++)
		{
			sprite[BLOOD_DROP+i].x_ += 2.0f * delta;
			sprite[BLOOD_POOL+i].x_ += 2.0f * delta;
		}
	}
}

void bgUpdate(struct Fighter* fighter1, struct Fighter* fighter2)
{
	if (rapTicks >= LastTicks + 2)
	{
		if (IsScrollingUp)
		{
			sprite[BG1_BACKDROP].y_ += bgYOffset;
			sprite[BG1_FLAME1].y_ += bgYOffset;
			sprite[BG1_FLAME2].y_ += bgYOffset;
			sprite[fighter1->spriteIndex].y_ += bgYOffset;
			sprite[fighter2->spriteIndex].y_ += bgYOffset;
		}
		else if (IsScrollingDown)
		{

		}
		else if (IsShaking)
		{

		}
	}
}

void bgScrollUp()
{
	IsScrollingUp = true;
	IsScrollingDown = false;
	LastTicks = rapTicks;
}

void bgScrollDown()
{
	IsScrollingUp = false;
	IsScrollingDown = true;
	LastTicks = rapTicks;
}

void bgShake()
{
	IsScrollingUp = false;
	IsScrollingDown = false;
	IsShaking = true;
	LastTicks = rapTicks;
}