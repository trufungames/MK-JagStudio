#include "common.h"
#include "fighter.h"
#include "sound.h"
#include "spriteanimator.h"

SpriteAnimator bloodSpray1Animator = {
	BLOOD_SPRAY_1, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodSpray2Animator = {
	BLOOD_SPRAY_2, 0.5f, BMP_BLOOD, 0, 0
};

AnimationFrame bloodSprayFrames[] = {
	{ 64, 32, 0, 0, 0, 0, 5 },
	{ 64, 32, 64, 0, 0, 0, 4 },
	{ 64, 32, 128, 0, 0, 0, 4 },
	{ 64, 32, 192, 0, 0, 0, 4 },
	{ 64, 32, 256, 0, 0, 0, 4 }
};

SpriteAnimator bloodGlobAnimator = {
	BLOOD_GLOB, 0.5f, BMP_BLOOD, 0, 0
};

AnimationFrame bloodGlobFrames[] = {
	{ 64, 32, 0, 32, 0, 0, 5 },
	{ 64, 32, 64, 32, 0, 0, 4 },
	{ 64, 32, 128, 32, 0, 0, 4 },
	{ 64, 32, 192, 32, 0, 0, 4 },
	{ 64, 32, 256, 32, 0, 0, 4 },
    { 64, 32, 320, 32, 0, 0, 4 }
};

bool bloodSpray1InUse = false;
bool bloodSpray2InUse = false;
bool bloodGlobInUse = false;
int bloodDirection = 1;

void bloodUpdate()
{
    if (bloodSpray1InUse)
    {
        updateSpriteAnimator(&bloodSpray1Animator, bloodSprayFrames, 5, true, true);

        if (bloodSpray1Animator.currentFrame == 3 && !bloodSpray2InUse)
        {
            bloodSpray2InUse = true;
            sprite[BLOOD_SPRAY_2].x_ = sprite[BLOOD_SPRAY_1].x_ - (12 * bloodDirection);
            sprite[BLOOD_SPRAY_2].y_ = sprite[BLOOD_SPRAY_1].y_ - (4 * bloodDirection);
            sprite[BLOOD_SPRAY_2].flip = bloodDirection == 1 ? R_is_flipped : R_is_normal;
            sprite[BLOOD_SPRAY_2].active = R_is_active;
            bloodSpray2Animator.currentFrame = 0;
        }

        if (animationIsComplete(&bloodSpray1Animator, 5))
        {
            bloodSpray1InUse = false;
            sprite[BLOOD_SPRAY_1].active = R_is_inactive;
        }
    }
    
    if (bloodSpray2InUse)
    {
        updateSpriteAnimator(&bloodSpray2Animator, bloodSprayFrames, 5, true, true);
        if (animationIsComplete(&bloodSpray2Animator, 5))
        {
            bloodSpray2InUse = false;
            sprite[BLOOD_SPRAY_2].active = R_is_inactive;
        }
    }

    if (bloodGlobInUse)
    {
        updateSpriteAnimator(&bloodGlobAnimator, bloodGlobFrames, 6, true, true);
        if (animationIsComplete(&bloodGlobAnimator, 6))
        {
            bloodGlobInUse = false;
            sprite[BLOOD_GLOB].active = R_is_inactive;
        }
    }
}

void bloodSpray(int x, int y, int direction)
{
    if (!bloodSpray1InUse)
    {
        bloodSpray1InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_SPRAY_1].x_ = x;
        sprite[BLOOD_SPRAY_1].y_ = y;
        sprite[BLOOD_SPRAY_1].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_SPRAY_1].active = R_is_active;
        bloodSpray1Animator.currentFrame = 0;
    }
}

void bloodGlob(int x, int y, int direction)
{
    if (!bloodGlobInUse)
    {
        bloodGlobInUse = true;
        bloodDirection = direction;
        sprite[BLOOD_GLOB].x_ = x;
        sprite[BLOOD_GLOB].y_ = y;
        sprite[BLOOD_GLOB].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_GLOB].active = R_is_active;
        bloodGlobAnimator.currentFrame = 0;
    }
}