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
int lastTicks1 = 0;
int lastTicks2 = 0;
int lastTicks3 = 0;
int lastTicks4 = 0;
int lastTicks5 = 0;
int lastTicks6 = 0;
int lastTicks7 = 0;
int lastTicks8 = 0;
int lastTicks9 = 0;
int lastTicks10 = 0;
float bloodSpeed = 0.0f;
float gravity = 0.0f;
float bloodDropMomentumStart = 0.0f;
float bloodDrop1Momentum = 0;
float bloodDrop2Momentum = 0;
float bloodDrop3Momentum = 0;
float bloodDrop4Momentum = 0;
float bloodDrop5Momentum = 0;
float bloodDrop6Momentum = 0;
float bloodDrop7Momentum = 0;
float bloodDrop8Momentum = 0;
float bloodDrop9Momentum = 0;
float bloodDrop10Momentum = 0;
int bloodStayDelay = 0;
int poolYLocation = 0;
int bloodSpeedRnd = 0;

void bloodInit()
{
    bloodStayDelay = 120;
    updateTicks = 3;
    lastTicks1 = 0;
    lastTicks2 = 0;
    lastTicks3 = 0;
    lastTicks4 = 0;
    lastTicks5 = 0;
    lastTicks6 = 0;
    lastTicks7 = 0;
    lastTicks8 = 0;
    lastTicks9 = 0;
    lastTicks10 = 0;
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

        if (rapTicks - lastTicks1 >= updateTicks)
        {
            sprite[BLOOD_DROP].x_ -= bloodSpeedRnd * bloodDirection;
            sprite[BLOOD_DROP].y_ += bloodDrop1Momentum;

            if (sprite[BLOOD_DROP].y_ > poolYLocation)
            {
                bloodPool(sprite[BLOOD_DROP].x_, poolYLocation);
                sprite[BLOOD_DROP].active = R_is_inactive;
                bloodDrop1InUse  = false;
            }

            bloodDrop1Momentum += gravity;
            lastTicks1 = rapTicks;
        }
    }

    if (bloodDrop2InUse)
    {
        updateSpriteAnimator(&bloodDrop2Animator, bloodDropFrames, 8, bloodDirection == -1 ? true : false, true);

        if (rapTicks - lastTicks2 >= updateTicks)
        {
            sprite[BLOOD_DROP+1].x_ -= bloodSpeedRnd * bloodDirection;
            sprite[BLOOD_DROP+1].y_ += bloodDrop2Momentum;

            if (sprite[BLOOD_DROP+1].y_ > poolYLocation)
            {
                bloodPool(sprite[BLOOD_DROP+1].x_, poolYLocation);
                sprite[BLOOD_DROP+1].active = R_is_inactive;
                bloodDrop2InUse  = false;
            }

            bloodDrop2Momentum += gravity;
            lastTicks2 = rapTicks;
        }
    }

    if (bloodDrop3InUse)
    {
        updateSpriteAnimator(&bloodDrop3Animator, bloodDropFrames, 8, bloodDirection == -1 ? true : false, true);

        if (rapTicks - lastTicks3 >= updateTicks)
        {
            sprite[BLOOD_DROP+2].x_ -= bloodSpeedRnd * bloodDirection;
            sprite[BLOOD_DROP+2].y_ += bloodDrop3Momentum;

            if (sprite[BLOOD_DROP+2].y_ > poolYLocation)
            {
                bloodPool(sprite[BLOOD_DROP+2].x_, poolYLocation);
                sprite[BLOOD_DROP+2].active = R_is_inactive;
                bloodDrop3InUse  = false;
            }

            bloodDrop3Momentum += gravity;
            lastTicks3 = rapTicks;
        }
    }

    if (bloodDrop4InUse)
    {
        updateSpriteAnimator(&bloodDrop4Animator, bloodDropFrames, 8, bloodDirection == -1 ? true : false, true);

        if (rapTicks - lastTicks4 >= updateTicks)
        {
            sprite[BLOOD_DROP+3].x_ -= bloodSpeedRnd * bloodDirection;
            sprite[BLOOD_DROP+3].y_ += bloodDrop4Momentum;

            if (sprite[BLOOD_DROP+3].y_ > poolYLocation)
            {
                bloodPool(sprite[BLOOD_DROP+3].x_, poolYLocation);
                sprite[BLOOD_DROP+3].active = R_is_inactive;
                bloodDrop4InUse  = false;
            }

            bloodDrop4Momentum += gravity;
            lastTicks4 = rapTicks;
        }
    }

    if (bloodDrop5InUse)
    {
        updateSpriteAnimator(&bloodDrop5Animator, bloodDropFrames, 8, bloodDirection == -1 ? true : false, true);

        if (rapTicks - lastTicks5 >= updateTicks)
        {
            sprite[BLOOD_DROP+4].x_ -= bloodSpeedRnd * bloodDirection;
            sprite[BLOOD_DROP+4].y_ += bloodDrop5Momentum;

            if (sprite[BLOOD_DROP+4].y_ > poolYLocation)
            {
                bloodPool(sprite[BLOOD_DROP+4].x_, poolYLocation);
                sprite[BLOOD_DROP+4].active = R_is_inactive;
                bloodDrop5InUse  = false;
            }

            bloodDrop5Momentum += gravity;
            lastTicks5 = rapTicks;
        }
    }

    if (bloodDrop6InUse)
    {
        updateSpriteAnimator(&bloodDrop6Animator, bloodDropFrames, 8, bloodDirection == -1 ? true : false, true);

        if (rapTicks - lastTicks6 >= updateTicks)
        {
            sprite[BLOOD_DROP+5].x_ -= bloodSpeedRnd * bloodDirection;
            sprite[BLOOD_DROP+5].y_ += bloodDrop6Momentum;

            if (sprite[BLOOD_DROP+5].y_ > poolYLocation)
            {
                bloodPool(sprite[BLOOD_DROP+5].x_, poolYLocation);
                sprite[BLOOD_DROP+5].active = R_is_inactive;
                bloodDrop6InUse  = false;
            }

            bloodDrop6Momentum += gravity;
            lastTicks6 = rapTicks;
        }
    }

    if (bloodDrop7InUse)
    {
        updateSpriteAnimator(&bloodDrop7Animator, bloodDropFrames, 8, bloodDirection == -1 ? true : false, true);

        if (rapTicks - lastTicks7 >= updateTicks)
        {
            sprite[BLOOD_DROP+6].x_ -= bloodSpeedRnd * bloodDirection;
            sprite[BLOOD_DROP+6].y_ += bloodDrop7Momentum;

            if (sprite[BLOOD_DROP+6].y_ > poolYLocation)
            {
                bloodPool(sprite[BLOOD_DROP+6].x_, poolYLocation);
                sprite[BLOOD_DROP+6].active = R_is_inactive;
                bloodDrop7InUse  = false;
            }

            bloodDrop7Momentum += gravity;
            lastTicks7 = rapTicks;
        }
    }

    if (bloodDrop8InUse)
    {
        updateSpriteAnimator(&bloodDrop8Animator, bloodDropFrames, 8, bloodDirection == -1 ? true : false, true);

        if (rapTicks - lastTicks8 >= updateTicks)
        {
            sprite[BLOOD_DROP+7].x_ -= bloodSpeedRnd * bloodDirection;
            sprite[BLOOD_DROP+7].y_ += bloodDrop8Momentum;

            if (sprite[BLOOD_DROP+7].y_ > poolYLocation)
            {
                bloodPool(sprite[BLOOD_DROP+7].x_, poolYLocation);
                sprite[BLOOD_DROP+7].active = R_is_inactive;
                bloodDrop8InUse  = false;
            }

            bloodDrop8Momentum += gravity;
            lastTicks8 = rapTicks;
        }
    }

    if (bloodDrop9InUse)
    {
        updateSpriteAnimator(&bloodDrop9Animator, bloodDropFrames, 8, bloodDirection == -1 ? true : false, true);

        if (rapTicks - lastTicks9 >= updateTicks)
        {
            sprite[BLOOD_DROP+8].x_ -= bloodSpeedRnd * bloodDirection;
            sprite[BLOOD_DROP+8].y_ += bloodDrop9Momentum;

            if (sprite[BLOOD_DROP+8].y_ > poolYLocation)
            {
                bloodPool(sprite[BLOOD_DROP+8].x_, poolYLocation);
                sprite[BLOOD_DROP+8].active = R_is_inactive;
                bloodDrop9InUse  = false;
            }

            bloodDrop9Momentum += gravity;
            lastTicks9 = rapTicks;
        }
    }

    if (bloodDrop10InUse)
    {
        updateSpriteAnimator(&bloodDrop10Animator, bloodDropFrames, 8, bloodDirection == -1 ? true : false, true);

        if (rapTicks - lastTicks10 >= updateTicks)
        {
            sprite[BLOOD_DROP+9].x_ -= bloodSpeedRnd * bloodDirection;
            sprite[BLOOD_DROP+9].y_ += bloodDrop10Momentum;

            if (sprite[BLOOD_DROP+9].y_ > poolYLocation)
            {
                bloodPool(sprite[BLOOD_DROP+9].x_, poolYLocation);
                sprite[BLOOD_DROP+9].active = R_is_inactive;
                bloodDrop10InUse  = false;
            }

            bloodDrop10Momentum += gravity;
            lastTicks10 = rapTicks;
        }
    }

    if (bloodPool1InUse)
    {
        updateSpriteAnimator(&bloodPool1Animator, bloodPoolFrames, 2, true, false);        
    }
    if (bloodPool2InUse)
    {
        updateSpriteAnimator(&bloodPool2Animator, bloodPoolFrames, 2, true, false);
    }
    if (bloodPool3InUse)
    {
        updateSpriteAnimator(&bloodPool3Animator, bloodPoolFrames, 2, true, false);
    }
    if (bloodPool4InUse)
    {
        updateSpriteAnimator(&bloodPool4Animator, bloodPoolFrames, 2, true, false);
    }
    if (bloodPool5InUse)
    {
        updateSpriteAnimator(&bloodPool5Animator, bloodPoolFrames, 2, true, false);
    }
    if (bloodPool6InUse)
    {
        updateSpriteAnimator(&bloodPool6Animator, bloodPoolFrames, 2, true, false);
    }
    if (bloodPool7InUse)
    {
        updateSpriteAnimator(&bloodPool7Animator, bloodPoolFrames, 2, true, false);
    }
    if (bloodPool8InUse)
    {
        updateSpriteAnimator(&bloodPool8Animator, bloodPoolFrames, 2, true, false);
    }
    if (bloodPool9InUse)
    {
        updateSpriteAnimator(&bloodPool9Animator, bloodPoolFrames, 2, true, false);
    }
    if (bloodPool10InUse)
    {
        updateSpriteAnimator(&bloodPool10Animator, bloodPoolFrames, 2, true, false);
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
    else if (!bloodDrop2InUse)
    {
        bloodDrop2InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+1].x_ = x;
        sprite[BLOOD_DROP+1].y_ = y;
        sprite[BLOOD_DROP+1].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+1].active = R_is_active;
        bloodDrop2Animator.currentFrame = 0;
    }
    else if (!bloodDrop3InUse)
    {
        bloodDrop3InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+2].x_ = x;
        sprite[BLOOD_DROP+2].y_ = y;
        sprite[BLOOD_DROP+2].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+2].active = R_is_active;
        bloodDrop3Animator.currentFrame = 0;
    }
    else if (!bloodDrop4InUse)
    {
        bloodDrop4InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+3].x_ = x;
        sprite[BLOOD_DROP+3].y_ = y;
        sprite[BLOOD_DROP+3].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+3].active = R_is_active;
        bloodDrop4Animator.currentFrame = 0;
    }
    else if (!bloodDrop5InUse)
    {
        bloodDrop5InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+4].x_ = x;
        sprite[BLOOD_DROP+4].y_ = y;
        sprite[BLOOD_DROP+4].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+4].active = R_is_active;
        bloodDrop5Animator.currentFrame = 0;
    }
    else if (!bloodDrop6InUse)
    {
        bloodDrop6InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+5].x_ = x;
        sprite[BLOOD_DROP+5].y_ = y;
        sprite[BLOOD_DROP+5].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+5].active = R_is_active;
        bloodDrop6Animator.currentFrame = 0;
    }
    else if (!bloodDrop7InUse)
    {
        bloodDrop7InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+6].x_ = x;
        sprite[BLOOD_DROP+6].y_ = y;
        sprite[BLOOD_DROP+6].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+6].active = R_is_active;
        bloodDrop7Animator.currentFrame = 0;
    }
    else if (!bloodDrop8InUse)
    {
        bloodDrop8InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+7].x_ = x;
        sprite[BLOOD_DROP+7].y_ = y;
        sprite[BLOOD_DROP+7].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+7].active = R_is_active;
        bloodDrop8Animator.currentFrame = 0;
    }
    else if (!bloodDrop9InUse)
    {
        bloodDrop9InUse = true;
        bloodDirection = direction;
        sprite[BLOOD_DROP+8].x_ = x;
        sprite[BLOOD_DROP+8].y_ = y;
        sprite[BLOOD_DROP+8].flip = direction == 1 ? R_is_flipped : R_is_normal;
        sprite[BLOOD_DROP+8].active = R_is_active;
        bloodDrop9Animator.currentFrame = 0;
    }
    else if (!bloodDrop10InUse)
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
        spriteDelaySetInactive(BLOOD_POOL, rapTicks+bloodStayDelay, &bloodPool1InUse);
    }
    else if (!bloodPool2InUse)
    {
        bloodPool2InUse = true;
        sprite[BLOOD_POOL+1].x_ = x;
        sprite[BLOOD_POOL+1].y_ = y;
        sprite[BLOOD_POOL+1].active = R_is_active;
        bloodPool2Animator.currentFrame = 0;
        spriteDelaySetInactive(BLOOD_POOL+1, rapTicks+bloodStayDelay, &bloodPool2InUse);
    }
    else if (!bloodPool3InUse)
    {
        bloodPool3InUse = true;
        sprite[BLOOD_POOL+2].x_ = x;
        sprite[BLOOD_POOL+2].y_ = y;
        sprite[BLOOD_POOL+2].active = R_is_active;
        bloodPool3Animator.currentFrame = 0;
        spriteDelaySetInactive(BLOOD_POOL+2, rapTicks+bloodStayDelay, &bloodPool3InUse);
    }
    else if (!bloodPool4InUse)
    {
        bloodPool4InUse = true;
        sprite[BLOOD_POOL+3].x_ = x;
        sprite[BLOOD_POOL+3].y_ = y;
        sprite[BLOOD_POOL+3].active = R_is_active;
        bloodPool4Animator.currentFrame = 0;
        spriteDelaySetInactive(BLOOD_POOL+3, rapTicks+bloodStayDelay, &bloodPool4InUse);
    }
    else if (!bloodPool5InUse)
    {
        bloodPool5InUse = true;
        sprite[BLOOD_POOL+4].x_ = x;
        sprite[BLOOD_POOL+4].y_ = y;
        sprite[BLOOD_POOL+4].active = R_is_active;
        bloodPool5Animator.currentFrame = 0;
        spriteDelaySetInactive(BLOOD_POOL+4, rapTicks+bloodStayDelay, &bloodPool5InUse);
    }
    else if (!bloodPool6InUse)
    {
        bloodPool6InUse = true;
        sprite[BLOOD_POOL+5].x_ = x;
        sprite[BLOOD_POOL+5].y_ = y;
        sprite[BLOOD_POOL+5].active = R_is_active;
        bloodPool6Animator.currentFrame = 0;
        spriteDelaySetInactive(BLOOD_POOL+5, rapTicks+bloodStayDelay, &bloodPool6InUse);
    }
    else if (!bloodPool7InUse)
    {
        bloodPool7InUse = true;
        sprite[BLOOD_POOL+6].x_ = x;
        sprite[BLOOD_POOL+6].y_ = y;
        sprite[BLOOD_POOL+6].active = R_is_active;
        bloodPool7Animator.currentFrame = 0;
        spriteDelaySetInactive(BLOOD_POOL+6, rapTicks+bloodStayDelay, &bloodPool7InUse);
    }
    else if (!bloodPool8InUse)
    {
        bloodPool8InUse = true;
        sprite[BLOOD_POOL+7].x_ = x;
        sprite[BLOOD_POOL+7].y_ = y;
        sprite[BLOOD_POOL+7].active = R_is_active;
        bloodPool8Animator.currentFrame = 0;
        spriteDelaySetInactive(BLOOD_POOL+7, rapTicks+bloodStayDelay, &bloodPool8InUse);
    }
    else if (!bloodPool9InUse)
    {
        bloodPool9InUse = true;
        sprite[BLOOD_POOL+8].x_ = x;
        sprite[BLOOD_POOL+8].y_ = y;
        sprite[BLOOD_POOL+8].active = R_is_active;
        bloodPool9Animator.currentFrame = 0;
        spriteDelaySetInactive(BLOOD_POOL+8, rapTicks+bloodStayDelay, &bloodPool9InUse);
    }
    else if (!bloodPool10InUse)
    {
        bloodPool10InUse = true;
        sprite[BLOOD_POOL+9].x_ = x;
        sprite[BLOOD_POOL+9].y_ = y;
        sprite[BLOOD_POOL+9].active = R_is_active;
        bloodPool10Animator.currentFrame = 0;
        spriteDelaySetInactive(BLOOD_POOL+9, rapTicks+bloodStayDelay, &bloodPool10InUse);
    }
}