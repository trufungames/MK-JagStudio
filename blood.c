#include "common.h"
#include "fighter.h"
#include "sound.h"
#include "spriteanimator.h"
#include "blood.h"
#include "spritedelay.h"

SpriteAnimator bloodSpray1Animator = {
	BLOOD_SPRAY, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodSpray2Animator = {
	BLOOD_SPRAY+1, 0.5f, BMP_BLOOD, 0, 0
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

SpriteAnimator bloodDrop1Animator = {
	BLOOD_DROP, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodDrop2Animator = {
	BLOOD_DROP+1, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodDrop3Animator = {
	BLOOD_DROP+2, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodDrop4Animator = {
	BLOOD_DROP+3, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodDrop5Animator = {
	BLOOD_DROP+4, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodDrop6Animator = {
	BLOOD_DROP+5, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodDrop7Animator = {
	BLOOD_DROP+6, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodDrop8Animator = {
	BLOOD_DROP+7, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodDrop9Animator = {
	BLOOD_DROP+8, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodDrop10Animator = {
	BLOOD_DROP+9, 0.5f, BMP_BLOOD, 0, 0
};

AnimationFrame bloodDropFrames[] = {
	{ 48, 48, 288, 128, 0, 0, 1 },
	{ 48, 48, 336, 128, 0, 0, 1 },
	{ 48, 48, 0, 176, 0, 0, 1 },
	{ 48, 48, 48, 176, 0, 0, 1 },
	{ 48, 48, 96, 176, 0, 0, 1 },
    { 48, 48, 144, 176, 0, 0, 1 },
    { 48, 48, 192, 176, 0, 0, 1 },
    { 48, 48, 240, 176, 0, 0, 1 }
};

SpriteAnimator bloodPool1Animator = {
	BLOOD_POOL, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodPool2Animator = {
	BLOOD_POOL+1, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodPool3Animator = {
	BLOOD_POOL+2, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodPool4Animator = {
	BLOOD_POOL+3, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodPool5Animator = {
	BLOOD_POOL+4, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodPool6Animator = {
	BLOOD_POOL+5, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodPool7Animator = {
	BLOOD_POOL+6, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodPool8Animator = {
	BLOOD_POOL+7, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodPool9Animator = {
	BLOOD_POOL+8, 0.5f, BMP_BLOOD, 0, 0
};

SpriteAnimator bloodPool10Animator = {
	BLOOD_POOL+9, 0.5f, BMP_BLOOD, 0, 0
};

AnimationFrame bloodPoolFrames[] = {
	{ 48, 48, 144, 128, 0, 0, 6 },
	{ 48, 48, 192, 128, 0, 0, 4 },
    { 48, 48, 240, 128, 0, 0, 4 }
};

BloodDrop bloodDrops[] = {
    { BLOOD_DROP, &bloodDrop1Animator, false, 0, 0, 0 },
    { BLOOD_DROP+1, &bloodDrop2Animator, false, 0, 0, 0 },
    { BLOOD_DROP+2, &bloodDrop3Animator, false, 0, 0, 0 },
    { BLOOD_DROP+3, &bloodDrop4Animator, false, 0, 0, 0 },
    { BLOOD_DROP+4, &bloodDrop5Animator, false, 0, 0, 0 },
    { BLOOD_DROP+5, &bloodDrop6Animator, false, 0, 0, 0 },
    { BLOOD_DROP+6, &bloodDrop7Animator, false, 0, 0, 0 },
    { BLOOD_DROP+7, &bloodDrop8Animator, false, 0, 0, 0 },
    { BLOOD_DROP+8, &bloodDrop9Animator, false, 0, 0, 0 },
    { BLOOD_DROP+9, &bloodDrop10Animator, false, 0, 0, 0 }
};

BloodPool bloodPools[] = {
    { BLOOD_POOL, &bloodPool1Animator, false },
    { BLOOD_POOL, &bloodPool2Animator, false },
    { BLOOD_POOL, &bloodPool3Animator, false },
    { BLOOD_POOL, &bloodPool4Animator, false },
    { BLOOD_POOL, &bloodPool5Animator, false },
    { BLOOD_POOL, &bloodPool6Animator, false },
    { BLOOD_POOL, &bloodPool7Animator, false },
    { BLOOD_POOL, &bloodPool8Animator, false },
    { BLOOD_POOL, &bloodPool9Animator, false },
    { BLOOD_POOL, &bloodPool10Animator, false }
};

bool bloodSpray1InUse = false;
bool bloodSpray2InUse = false;
bool bloodGlobInUse = false;
int bloodDirection = 1;
int updateTicks = 0;
float bloodSpeed = 0.0f;
float gravity = 0.0f;
float bloodDropMomentumStart = 0.0f;
int bloodStayDelay = 0;
int poolYLocation = 0;
int bloodSpeedRnd = 0;

void bloodInit()
{
    bloodStayDelay = 180;
    updateTicks = 3;
    bloodSpeed = 7.0f;
    gravity = 4.0f;
    bloodDropMomentumStart = -20.0f;
    bloodSpray1InUse = false;
    bloodSpray2InUse = false;
    bloodGlobInUse = false;
    bloodDirection = 1;
}

void bloodUpdate(struct SoundHandler* soundHandler)
{
    if (bloodSpray1InUse)
    {
        updateSpriteAnimator(&bloodSpray1Animator, bloodSprayFrames, 5, true, true);

        if (bloodSpray1Animator.currentFrame == 3 && !bloodSpray2InUse)
        {
            bloodSpray2InUse = true;
            sprite[BLOOD_SPRAY+1].x_ = sprite[BLOOD_SPRAY].x_ - (12 * bloodDirection);
            sprite[BLOOD_SPRAY+1].y_ = sprite[BLOOD_SPRAY].y_ - (4 * bloodDirection);
            sprite[BLOOD_SPRAY+1].flip = bloodDirection == 1 ? R_is_flipped : R_is_normal;
            sprite[BLOOD_SPRAY+1].active = R_is_active;
            bloodSpray2Animator.currentFrame = 0;
        }

        if (animationIsComplete(&bloodSpray1Animator, 5))
        {
            bloodSpray1InUse = false;
            sprite[BLOOD_SPRAY].active = R_is_inactive;
        }
    }
    
    if (bloodSpray2InUse)
    {
        updateSpriteAnimator(&bloodSpray2Animator, bloodSprayFrames, 5, true, true);
        if (animationIsComplete(&bloodSpray2Animator, 5))
        {
            bloodSpray2InUse = false;
            sprite[BLOOD_SPRAY+1].active = R_is_inactive;
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

    for (int i = 0; i < TOTAL_BLOOD_COUNT; i++)
    {
        if (bloodDrops[i].InUse)
        {
            updateSpriteAnimator(bloodDrops[i].Animator, bloodDropFrames, 8, bloodDrops[i].Direction == -1 ? true : false, true);

            if (rapTicks - bloodDrops[i].LastTicks >= updateTicks)
            {
                sprite[bloodDrops[i].SpriteIndex].x_ -= bloodSpeedRnd * bloodDrops[i].Direction;
                sprite[bloodDrops[i].SpriteIndex].y_ += bloodDrops[i].Momentum;

                if (sprite[bloodDrops[i].SpriteIndex].y_ > poolYLocation)
                {
                    bloodPool(sprite[bloodDrops[i].SpriteIndex].x_, poolYLocation);
                    sfxBlood(soundHandler);
                    sprite[bloodDrops[i].SpriteIndex].active = R_is_inactive;
                    bloodDrops[i].InUse  = false;
                }

                bloodDrops[i].Momentum += gravity;
                bloodDrops[i].LastTicks = rapTicks;
            }
        }
    }

    for (int i = 0; i < TOTAL_BLOOD_COUNT; i++)
    {
        if (bloodPools[i].InUse)
        {
            updateSpriteAnimator(bloodPools[i].Animator, bloodPoolFrames, 2, true, false);     
        }
    }
}

void bloodSpray(int x, int y, int direction)
{
    if (!bloodSpray1InUse)
    {
        bloodSpray1InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_SPRAY].x_ = x;
        sprite[BLOOD_SPRAY].y_ = y;
        sprite[BLOOD_SPRAY].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_SPRAY].active = R_is_active;
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

void bloodDrop(int x, int y, int direction)
{
    poolYLocation = 186 + (rapRND() & 8);

    if (rapRND() & 500 < 150)
    {
        bloodSpeedRnd = bloodSpeed + 0.4f;
    }
    else if (rapRND() & 500 < 350)
    {
        bloodSpeedRnd = bloodSpeed - 0.4f;
    }
    else
    {
        bloodSpeedRnd = bloodSpeed + 0.0f;
    }

    for (int i = 0; i < TOTAL_BLOOD_COUNT; i++)
    {
        if (!bloodDrops[i].InUse)
        {
            bloodDrops[i].InUse = true;
            bloodDrops[i].Direction = direction;
            sprite[bloodDrops[i].SpriteIndex].x_ = x;
            sprite[bloodDrops[i].SpriteIndex].y_ = y;
            sprite[bloodDrops[i].SpriteIndex].flip = direction == 1 ? R_is_flipped : R_is_normal;
            sprite[bloodDrops[i].SpriteIndex].active = R_is_active;
            bloodDrops[i].Animator->currentFrame = 0;
            bloodDrops[i].Momentum = bloodDropMomentumStart;
            break;
        }
    }
}

void bloodPool(int x, int y)
{
    for (int i = 0; i < TOTAL_BLOOD_COUNT; i++)
    {
        if (!bloodPools[i].InUse)
        {
            bloodPools[i].InUse = true;
            sprite[bloodPools[i].SpriteIndex].x_ = x;
            sprite[bloodPools[i].SpriteIndex].y_ = y;
            sprite[bloodPools[i].SpriteIndex].active = R_is_active;
            bloodPools[i].Animator->currentFrame = 0;
            spriteDelaySetInactive(bloodPools[i].SpriteIndex, rapTicks+bloodStayDelay, &bloodPools[i].InUse);
            break;
        }
    }
}