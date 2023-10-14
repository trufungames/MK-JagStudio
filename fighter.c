#include "common.h"
#include "fighter.h"
#include "spriteanimator.h"
#include "spritemovements.h"

void fighterHide(struct Fighter *fighter)
{

}

void fighterInitialize(struct Fighter *fighter, bool isPlayer1)
{
    fighter->pad = 0;
    fighter->playerMoveForwardSpeed = 4;
    fighter->playerMoveBackwardSpeed = 4;

    fighter->playerWasWalking = false;
    fighter->playerWasDucking = false;
    fighter->playerWasBlocking = false;
    sprite[fighter->spriteIndex].active = R_is_active;

    if (isPlayer1)
    {
        fighter->HB_ATTACK = P1_HB_ATTACK;
        fighter->HB_BODY = P1_HB_BODY;
        fighter->HB_DUCK = P1_HB_DUCK;
        fighter->PAD = LEFT_PAD;
    }
    else
    {
        fighter->HB_ATTACK = P2_HB_ATTACK;
        fighter->HB_BODY = P2_HB_BODY;
        fighter->HB_DUCK = P2_HB_DUCK;
        fighter->PAD = RIGHT_PAD;
    }
}

void fighterUpdate(struct Fighter *fighter, struct SpriteAnimator* animator, struct AnimationFrame idleFrames[], struct AnimationFrame walkFrames[], struct AnimationFrame duckFrames[], struct AnimationFrame blockFrames[], struct AnimationFrame blockDuckFrames[])
{
    fighter->pad = jsfGetPad(fighter->PAD);
    
    if (fighter->pad & JAGPAD_B)
    {
        if (!fighter->playerWasBlocking)
        {
            fighter->playerWasBlocking = true;
            animator->currentFrame = 0;
        }

        if (fighter->pad & JAGPAD_DOWN)
        {
            if (!fighter->playerWasDucking)
            {
                fighter->playerWasDucking = true;
                animator->currentFrame = 0;
            }

            updateSpriteAnimator(animator, blockDuckFrames, fighter->BLOCK_DUCK_FRAME_COUNT, true, false);
        }
        else
        {
            if (fighter->playerWasDucking)
            {
                fighter->playerWasDucking = false;
            }
            
            updateSpriteAnimator(animator, blockFrames, fighter->BLOCK_FRAME_COUNT, true, false);
        }
    }
    else if(fighter->pad & JAGPAD_LEFT)
    {
        updateSpriteAnimator(animator, walkFrames, fighter->WALK_FRAME_COUNT, true, true);
        fighter->playerWasWalking = true;
        fighter->playerWasDucking = false;
        fighter->playerWasBlocking  = false;

        if (sprite[fighter->spriteIndex].x_ > 0)
        {
            sprite[fighter->spriteIndex].x_ -= fighter->playerMoveBackwardSpeed;
            sprite[fighter->HB_BODY].x_ -= fighter->playerMoveBackwardSpeed;
            sprite[fighter->HB_DUCK].x_ -= fighter->playerMoveBackwardSpeed;
            sprite[fighter->HB_ATTACK].x_ -= fighter->playerMoveBackwardSpeed;
        }
        else
        {
            bgScrollLeft();
        }
    }
    else if(fighter->pad & JAGPAD_RIGHT)
    {
        updateSpriteAnimator(animator, walkFrames, fighter->WALK_FRAME_COUNT, false, true);
        fighter->playerWasWalking = true;
        fighter->playerWasDucking = false;
        fighter->playerWasBlocking = false;
        
        if (sprite[fighter->spriteIndex].x_ < 260)
        {
            sprite[fighter->spriteIndex].x_ += fighter->playerMoveForwardSpeed;
            sprite[fighter->HB_BODY].x_ += fighter->playerMoveForwardSpeed;
            sprite[fighter->HB_DUCK].x_ += fighter->playerMoveForwardSpeed;
            sprite[fighter->HB_ATTACK].x_ += fighter->playerMoveForwardSpeed;
        }
        else
        {
            bgScrollRight();
        }
    }
    else if (fighter->pad & JAGPAD_DOWN)
    {
        if (!fighter->playerWasDucking)
        {
            fighter->playerWasDucking = true;
            animator->currentFrame = 0;
        }
        updateSpriteAnimator(animator, duckFrames, fighter->DUCK_FRAME_COUNT, true, false);
        sprite[fighter->HB_BODY].active = R_is_inactive;
    }
    else
    {
        if (fighter->playerWasDucking)
        {
            updateSpriteAnimator(animator, duckFrames, fighter->DUCK_FRAME_COUNT, false, false);
            
            if (animator->currentFrame == 0)
            {
                fighter->playerWasDucking = false;

                if (sprite[fighter->HB_DUCK].active == R_is_active)
                {
                    sprite[fighter->HB_BODY].active = R_is_active;
                }
            }
        }
        else if (fighter->playerWasBlocking)
        {
            updateSpriteAnimator(animator, blockFrames, fighter->BLOCK_FRAME_COUNT, false, false);
            
            if (animator->currentFrame == 0)
            {
                fighter->playerWasBlocking = false;
            }
        }
        else
        {
            if (fighter->playerWasWalking)
            {
                fighter->playerWasWalking = false;
                animator->currentFrame = 0;
            }
            updateSpriteAnimator(animator, idleFrames, fighter->IDLE_FRAME_COUNT, true, true);
        }
    }
}