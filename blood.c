#include "common.h"
#include "fighter.h"
#include "sound.h"
#include "spriteanimator.h"
#include "blood.h"

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
	{ 48, 48, 288, 128, 0, 0, 2 },
	{ 48, 48, 336, 128, 0, 0, 2 },
	{ 48, 48, 0, 176, 0, 0, 2 },
	{ 48, 48, 48, 176, 0, 0, 2 },
	{ 48, 48, 96, 176, 0, 0, 2 },
    { 48, 48, 144, 176, 0, 0, 2 },
    { 48, 48, 192, 176, 0, 0, 2 },
    { 48, 48, 240, 176, 0, 0, 2 }
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

bool bloodSpray1InUse = false;
bool bloodSpray2InUse = false;
bool bloodGlobInUse = false;
bool bloodDrop1InUse = false;
bool bloodDrop2InUse = false;
bool bloodDrop3InUse = false;
bool bloodDrop4InUse = false;
bool bloodDrop5InUse = false;
bool bloodDrop6InUse = false;
bool bloodDrop7InUse = false;
bool bloodDrop8InUse = false;
bool bloodDrop9InUse = false;
bool bloodDrop10InUse = false;
bool bloodPool1InUse = false;
bool bloodPool2InUse = false;
bool bloodPool3InUse = false;
bool bloodPool4InUse = false;
bool bloodPool5InUse = false;
bool bloodPool6InUse = false;
bool bloodPool7InUse = false;
bool bloodPool8InUse = false;
bool bloodPool9InUse = false;
bool bloodPool10InUse = false;
int bloodDirection = 1;
int updateTicks = 0;
int lastTicks = 0;
float bloodSpeed = 0.0f;
float gravity = 0.0f;
float bloodDropMomentumStart = 0.0f;
float bloodDrop1Momentum = 0;

void bloodInit()
{
    updateTicks = 3;
    lastTicks = 0;
    bloodSpeed = 7.0f;
    gravity = 4.0f;
    bloodDropMomentumStart = -20.0f;
    bloodSpray1InUse = false;
    bloodSpray2InUse = false;
    bloodGlobInUse = false;
    bloodDrop1InUse = false;
    bloodDrop2InUse = false;
    bloodDrop3InUse = false;
    bloodDrop4InUse = false;
    bloodDrop5InUse = false;
    bloodDrop6InUse = false;
    bloodDrop7InUse = false;
    bloodDrop8InUse = false;
    bloodDrop9InUse = false;
    bloodDrop10InUse = false;
    bloodPool1InUse = false;
    bloodPool2InUse = false;
    bloodPool3InUse = false;
    bloodPool4InUse = false;
    bloodPool5InUse = false;
    bloodPool6InUse = false;
    bloodPool7InUse = false;
    bloodPool8InUse = false;
    bloodPool9InUse = false;
    bloodPool10InUse = false;
    bloodDirection = 1;
}

void bloodUpdate()
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

    if (bloodDrop1InUse)
    {
        updateSpriteAnimator(&bloodDrop1Animator, bloodDropFrames, 8, bloodDirection == -1 ? true : false, true);

        if (rapTicks - lastTicks >= updateTicks)
        {
            sprite[BLOOD_DROP].x_ -= bloodSpeed * bloodDirection;
            sprite[BLOOD_DROP].y_ += bloodDrop1Momentum;

            if (sprite[BLOOD_DROP].y_ > 185)
            {
                bloodPool(sprite[BLOOD_DROP].x_, 185);
                sprite[BLOOD_DROP].active = R_is_inactive;
                bloodDrop1InUse  = false;
            }

            bloodDrop1Momentum += gravity;
            lastTicks = rapTicks;
        }
    }

    if (bloodPool1InUse)
    {
        updateSpriteAnimator(&bloodPool1Animator, bloodPoolFrames, 2, true, false);

        //keep the blood!?
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
    if (!bloodDrop1InUse)
    {
        bloodDrop1InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP].x_ = x;
        sprite[BLOOD_DROP].y_ = y;
        sprite[BLOOD_DROP].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP].active = R_is_active;
        bloodDrop1Animator.currentFrame = 0;
        bloodDrop1Momentum = bloodDropMomentumStart;
    }

    if (!bloodDrop2InUse)
    {
        bloodDrop2InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+1].x_ = x;
        sprite[BLOOD_DROP+1].y_ = y;
        sprite[BLOOD_DROP+1].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+1].active = R_is_active;
        bloodDrop2Animator.currentFrame = 0;
    }

    if (!bloodDrop3InUse)
    {
        bloodDrop3InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+2].x_ = x;
        sprite[BLOOD_DROP+2].y_ = y;
        sprite[BLOOD_DROP+2].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+2].active = R_is_active;
        bloodDrop3Animator.currentFrame = 0;
    }

    if (!bloodDrop4InUse)
    {
        bloodDrop4InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+3].x_ = x;
        sprite[BLOOD_DROP+3].y_ = y;
        sprite[BLOOD_DROP+3].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+3].active = R_is_active;
        bloodDrop4Animator.currentFrame = 0;
    }

    if (!bloodDrop5InUse)
    {
        bloodDrop5InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+4].x_ = x;
        sprite[BLOOD_DROP+4].y_ = y;
        sprite[BLOOD_DROP+4].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+4].active = R_is_active;
        bloodDrop5Animator.currentFrame = 0;
    }

    if (!bloodDrop6InUse)
    {
        bloodDrop6InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+5].x_ = x;
        sprite[BLOOD_DROP+5].y_ = y;
        sprite[BLOOD_DROP+5].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+5].active = R_is_active;
        bloodDrop6Animator.currentFrame = 0;
    }

    if (!bloodDrop7InUse)
    {
        bloodDrop7InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+6].x_ = x;
        sprite[BLOOD_DROP+6].y_ = y;
        sprite[BLOOD_DROP+6].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+6].active = R_is_active;
        bloodDrop7Animator.currentFrame = 0;
    }

    if (!bloodDrop8InUse)
    {
        bloodDrop8InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+7].x_ = x;
        sprite[BLOOD_DROP+7].y_ = y;
        sprite[BLOOD_DROP+7].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+7].active = R_is_active;
        bloodDrop8Animator.currentFrame = 0;
    }

    if (!bloodDrop9InUse)
    {
        bloodDrop9InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+8].x_ = x;
        sprite[BLOOD_DROP+8].y_ = y;
        sprite[BLOOD_DROP+8].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+8].active = R_is_active;
        bloodDrop9Animator.currentFrame = 0;
    }

    if (!bloodDrop10InUse)
    {
        bloodDrop10InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+9].x_ = x;
        sprite[BLOOD_DROP+9].y_ = y;
        sprite[BLOOD_DROP+9].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+9].active = R_is_active;
        bloodDrop10Animator.currentFrame = 0;
    }
}

void bloodPool(int x, int y)
{
    if (!bloodPool1InUse)
    {
        bloodPool1InUse = true;
        sprite[BLOOD_POOL].x_ = x;
        sprite[BLOOD_POOL].y_ = y;
        sprite[BLOOD_POOL].active = R_is_active;
        bloodPool1Animator.currentFrame = 0;
    }
}