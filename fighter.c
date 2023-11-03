#include "common.h"
#include "fighter.h"
#include "spriteanimator.h"
#include "spritemovements.h"

void fighterHide(struct Fighter *fighter)
{
    sprite[fighter->spriteIndex].active = R_is_inactive;
}

void fighterShow(struct Fighter *fighter)
{
    sprite[fighter->spriteIndex].active = R_is_active;
}

void fighterMakeSelectable(struct Fighter* fighter, bool isPlayer1)
{
    if (isPlayer1)
    {
        sprite[fighter->spriteIndex].x_ = 4;
        sprite[fighter->spriteIndex].flip = R_is_normal;
    }
    else
    {
        sprite[fighter->spriteIndex].x_ = 243;

        if (fighter->spriteIndex == CAGE2)
        {
            sprite[fighter->spriteIndex].x_ = 227;
        }

        sprite[fighter->spriteIndex].flip = R_is_flipped;
    }
}

void fighterInitialize(struct Fighter *fighter, bool isPlayer1)
{
    fighter->pad = 0;
    fighter->playerMoveForwardSpeed = 2;
    fighter->playerMoveBackwardSpeed = 2;

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
        sprite[fighter->spriteIndex].x_ = 50;
    }
    else
    {
        fighter->HB_ATTACK = P2_HB_ATTACK;
        fighter->HB_BODY = P2_HB_BODY;
        fighter->HB_DUCK = P2_HB_DUCK;
        fighter->PAD = RIGHT_PAD;
        sprite[fighter->spriteIndex].x_ = 210;
    }
}

void fighterUpdateIdle(float delta, struct Fighter *fighter, struct SpriteAnimator* animator, struct AnimationFrame idleFrames[])
{
    updateSpriteAnimator(animator, idleFrames, fighter->IDLE_FRAME_COUNT, true, true);
}

void fighterUpdate(float delta, struct Fighter *fighter, struct SpriteAnimator* animator, struct AnimationFrame idleFrames[], struct AnimationFrame walkFrames[], struct AnimationFrame duckFrames[], struct AnimationFrame blockFrames[], struct AnimationFrame blockDuckFrames[], struct AnimationFrame punchLowFrames[], bool walkForward)
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
        updateSpriteAnimator(animator, walkFrames, fighter->WALK_FRAME_COUNT, walkForward, true);
        fighter->playerWasWalking = true;
        fighter->playerWasDucking = false;
        fighter->playerWasBlocking  = false;

        if (sprite[fighter->spriteIndex].x_ > 0)
        {
            sprite[fighter->spriteIndex].x_ -= fighter->playerMoveBackwardSpeed * delta;
            sprite[fighter->HB_BODY].x_ -= fighter->playerMoveBackwardSpeed * delta;
            sprite[fighter->HB_DUCK].x_ -= fighter->playerMoveBackwardSpeed * delta;
            sprite[fighter->HB_ATTACK].x_ -= fighter->playerMoveBackwardSpeed * delta;
        }
        else
        {
            bgScrollLeft(delta);
        }
    }
    else if(fighter->pad & JAGPAD_RIGHT)
    {
        updateSpriteAnimator(animator, walkFrames, fighter->WALK_FRAME_COUNT, !walkForward, true);
        fighter->playerWasWalking = true;
        fighter->playerWasDucking = false;
        fighter->playerWasBlocking = false;
        
        if (sprite[fighter->spriteIndex].x_ < 260)
        {
            sprite[fighter->spriteIndex].x_ += fighter->playerMoveForwardSpeed * delta;
            sprite[fighter->HB_BODY].x_ += fighter->playerMoveForwardSpeed * delta;
            sprite[fighter->HB_DUCK].x_ += fighter->playerMoveForwardSpeed * delta;
            sprite[fighter->HB_ATTACK].x_ += fighter->playerMoveForwardSpeed * delta;
        }
        else
        {
            bgScrollRight(delta);
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