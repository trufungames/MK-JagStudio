#include "common.h"
#include "spriteanimator.h"

void animateFrame(unsigned int spriteIndex, unsigned int frame, struct AnimationFrame animationFrames[], float mulFactor, unsigned int base, int idleFrameWidth)
{
    animateFrame(spriteIndex, frame, animationFrames, mulFactor, base, idleFrameWidth, 0, 0, 1);
}

void animateFrame(unsigned int spriteIndex, unsigned int frame, struct AnimationFrame animationFrames[], float mulFactor, unsigned int base, int idleFrameWidth, int positionX, int positionY, int direction) {

    if (positionX == 0)
    {
        positionX = sprite[spriteIndex].x_;
    }

    if (positionY == 0)
    {
        positionY = sprite[spriteIndex].y_;
    }

    sprite[spriteIndex].width = animationFrames[frame].width;
    sprite[spriteIndex].height = animationFrames[frame].height;
    sprite[spriteIndex].bytewid = animationFrames[frame].width * mulFactor;
    sprite[spriteIndex].framesz = animationFrames[frame].width * animationFrames[frame].height * mulFactor;
    sprite[spriteIndex].gfxbase = base + (animationFrames[frame].x * mulFactor) + (animationFrames[frame].y * sprite[spriteIndex].gwidth);
    sprite[spriteIndex].x_ = positionX + (animationFrames[frame].offsetX * direction);
    sprite[spriteIndex].y_ = positionY + (animationFrames[frame].offsetY * direction);

    if (direction == -1)
    {
        //player 2, so we have to factor the idleFrameWidth into the offset
        sprite[spriteIndex].x_ -= animationFrames[frame].width - idleFrameWidth;
    }
}

void setFrame(unsigned int spriteIndex, int width, int height, int x, int y, float mulFactor, unsigned int base)
{
    sprite[spriteIndex].width = width;
    sprite[spriteIndex].height =  height;
    sprite[spriteIndex].bytewid = width * mulFactor;
    sprite[spriteIndex].framesz = width * height * mulFactor;
    sprite[spriteIndex].gfxbase = base + (x * mulFactor) + (y * sprite[spriteIndex].gwidth);
}

bool animationIsComplete(struct SpriteAnimator *animator, int totalFrames)
{
    if (animator->currentFrame >= totalFrames - 1)
        return true;
    else
        return false;
}

void updateSpriteAnimator(struct SpriteAnimator *animator, struct AnimationFrame animationFrames[], int totalFrames, bool playForward, bool loop)
{
    updateSpriteAnimator(animator, animationFrames, totalFrames, playForward, loop, 0, 0, 1);
}

void updateSpriteAnimator(struct SpriteAnimator *animator, struct AnimationFrame animationFrames[], int totalFrames, bool playForward, bool loop, int positionX, int positionY, int direction)
{
    animateFrame(animator->spriteIndex, animator->currentFrame, animationFrames, animator->mulFactor, animator->base, animator->idleFrameWidth, positionX, positionY, direction);

    if (rapTicks >= animator->lastTick + animationFrames[animator->currentFrame].ticks)
    {
        if (!playForward)
        {
            animator->currentFrame--;

            if (animator->currentFrame < 0)
            {
                if (loop)
                {
                    animator->currentFrame = totalFrames - 1;
                }
                else
                {
                    animator->currentFrame = 0;
                }
            }
        }
        else
        {
            animator->currentFrame++;

            if (animator->currentFrame >= totalFrames)
            {
                if (loop)
                {
                    animator->currentFrame = 0;
                }
                else
                {
                    animator->currentFrame = totalFrames;
                }
                
                // js_r_textbuffer = (char *)"Restart animation!";
                // jsfDebugMessage();
            }
        }

        animator->lastTick = rapTicks;
    }
}