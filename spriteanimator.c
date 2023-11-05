#include "common.h"
#include "spriteanimator.h"

void animateFrame(unsigned int spriteIndex, unsigned int frame, struct AnimationFrame animationFrames[], float mulFactor, unsigned int base)
{
    animateFrame(spriteIndex, frame, animationFrames, mulFactor, base, 0, 0);
}

void animateFrame(unsigned int spriteIndex, unsigned int frame, struct AnimationFrame animationFrames[], float mulFactor, unsigned int base, int positionX, int positionY) {

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
    sprite[spriteIndex].gfxbase = base + (animationFrames[frame].x * mulFactor) + (animationFrames[frame].y * sprite[spriteIndex].gwidth );
    sprite[spriteIndex].x_ = positionX + animationFrames[frame].offsetX;
    sprite[spriteIndex].y_ = positionY + animationFrames[frame].offsetY;
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
    updateSpriteAnimator(animator, animationFrames, totalFrames, playForward, loop, 0, 0);
}

void updateSpriteAnimator(struct SpriteAnimator *animator, struct AnimationFrame animationFrames[], int totalFrames, bool playForward, bool loop, int positionX, int positionY)
{
    animateFrame(animator->spriteIndex, animator->currentFrame, animationFrames, animator->mulFactor, animator->base, positionX, positionY);

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