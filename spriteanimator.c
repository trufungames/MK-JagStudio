#include "common.h"
#include "spriteanimator.h"

void animateFrame(unsigned int spriteIndex, unsigned int frame, struct AnimationFrame animationFrames[], float mulFactor, unsigned int base) {
    sprite[spriteIndex].width = animationFrames[frame].width;
    sprite[spriteIndex].height = animationFrames[frame].height;  
    sprite[spriteIndex].bytewid = animationFrames[frame].width * mulFactor;
    sprite[spriteIndex].framesz = animationFrames[frame].width * animationFrames[frame].height * mulFactor;
    sprite[spriteIndex].gfxbase = base + (animationFrames[frame].x * mulFactor) + (animationFrames[frame].y * sprite[spriteIndex].gwidth );
}

void updateSpriteAnimator(struct SpriteAnimator *animator, struct AnimationFrame animationFrames[], int totalFrames, bool playForward, bool loop)
{
    animateFrame(animator->spriteIndex, animator->currentFrame, animationFrames, animator->mulFactor, animator->base);

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