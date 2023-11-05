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

    fighter->IsWalking = false;
    fighter->IsDucking = false;
    fighter->IsBlocking = false;
    fighter->IsLowPunching = false;
    fighter->ButtonReleased = true;
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

    if (fighter->pad & JAGPAD_C || fighter->IsLowPunching)
    {
        if (!fighter->IsLowPunching && fighter->ButtonReleased)
        {
            fighter->ButtonReleased = false;
            fighter->IsLowPunching = true;
            animator->currentFrame = 0;
        }

        updateSpriteAnimator(animator, punchLowFrames, fighter->LOW_PUNCH_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY);

        if (animationIsComplete(animator, fighter->LOW_PUNCH_FRAME_COUNT))
        {
            fighter->IsLowPunching = false;
        }
    }
    else if (fighter->pad & JAGPAD_B)
    {
        if (!fighter->IsBlocking)
        {
            fighter->IsBlocking = true;
            animator->currentFrame = 0;
        }

        if (fighter->pad & JAGPAD_DOWN)
        {
            if (!fighter->IsDucking)
            {
                fighter->IsDucking = true;
                animator->currentFrame = 0;
            }

            updateSpriteAnimator(animator, blockDuckFrames, fighter->BLOCK_DUCK_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY);
        }
        else
        {
            if (fighter->IsDucking)
            {
                fighter->IsDucking = false;
            }
            
            updateSpriteAnimator(animator, blockFrames, fighter->BLOCK_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY);
        }
    }
    else if(fighter->pad & JAGPAD_LEFT)
    {
        updateSpriteAnimator(animator, walkFrames, fighter->WALK_FRAME_COUNT, walkForward, true, fighter->positionX, fighter->positionY);
        fighter->IsWalking = true;
        fighter->IsDucking = false;
        fighter->IsBlocking  = false;
        fighter->IsLowPunching = false;

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

       fighter->positionX = sprite[fighter->spriteIndex].x_;
       fighter->positionY = sprite[fighter->spriteIndex].y_;
    }
    else if(fighter->pad & JAGPAD_RIGHT)
    {
        updateSpriteAnimator(animator, walkFrames, fighter->WALK_FRAME_COUNT, !walkForward, true, fighter->positionX, fighter->positionY);
        fighter->IsWalking = true;
        fighter->IsDucking = false;
        fighter->IsBlocking = false;
        fighter->IsLowPunching = false;
        
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

       fighter->positionX = sprite[fighter->spriteIndex].x_;
       fighter->positionY = sprite[fighter->spriteIndex].y_;
    }
    else if (fighter->pad & JAGPAD_DOWN)
    {
        if (!fighter->IsDucking)
        {
            fighter->IsDucking = true;
            animator->currentFrame = 0;
        }
        updateSpriteAnimator(animator, duckFrames, fighter->DUCK_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY);
        sprite[fighter->HB_BODY].active = R_is_inactive;
    }
    else
    {
        if (fighter->IsDucking)
        {
            updateSpriteAnimator(animator, duckFrames, fighter->DUCK_FRAME_COUNT, false, false, fighter->positionX, fighter->positionY);
            
            if (animator->currentFrame == 0)
            {
                fighter->IsDucking = false;

                if (sprite[fighter->HB_DUCK].active == R_is_active)
                {
                    sprite[fighter->HB_BODY].active = R_is_active;
                }
            }
        }
        else if (fighter->IsBlocking)
        {
            updateSpriteAnimator(animator, blockFrames, fighter->BLOCK_FRAME_COUNT, false, false, fighter->positionX, fighter->positionY);
            
            if (animator->currentFrame == 0)
            {
                fighter->IsBlocking = false;
            }
        }
        else
        {
            if (fighter->IsWalking)
            {
                fighter->IsWalking = false;
                animator->currentFrame = 0;
            }

            updateSpriteAnimator(animator, idleFrames, fighter->IDLE_FRAME_COUNT, true, true, fighter->positionX, fighter->positionY);

           fighter->positionX = sprite[fighter->spriteIndex].x_;
           fighter->positionY = sprite[fighter->spriteIndex].y_;
        }
    }

    if (!(fighter->pad & JAGPAD_C))
    {
        fighter->ButtonReleased = true;
    }
}