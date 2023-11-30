#include "common.h"
#include "fighter.h"
#include "sound.h"
#include "spriteanimator.h"
#include "spritemovements.h"
#include "impactFrame.h"
#include "blood.h"

int collision = 0;

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
        fighter->direction = 1;
    }
    else
    {
        sprite[fighter->spriteIndex].x_ = 243;

        if (fighter->spriteIndex == CAGE2)
        {
            sprite[fighter->spriteIndex].x_ -= 16;
        }
        else if (fighter->spriteIndex == SUBZERO2)
        {
            sprite[fighter->spriteIndex].x_ += 16;
        }

        sprite[fighter->spriteIndex].flip = R_is_flipped;
        fighter->direction = -1;
    }

    fighter->positionX = sprite[fighter->spriteIndex].x_;
    fighter->positionY = sprite[fighter->spriteIndex].y_;
}

void fighterInitialize(struct Fighter *fighter, bool isPlayer1, struct SoundHandler* soundHandler, struct ImpactFrame* impactFrameLowPunch, struct ImpactFrame* impactFrameHighPunch, struct ImpactFrame* impactFrameLowKick, struct ImpactFrame* impactFrameHighKick, struct ImpactFrame* impactFrameUppercut)
{
    //defaults
    fighter->gravity = 2.6f;
    fighter->momentumY = 0.0f;
    fighter->uppercutMomentumYStart = -30.0f;
    fighter->floorLocationY = 188;

    //assignments
    fighter->soundHandler = soundHandler;
    fighter->impactFrameLowPunch = impactFrameLowPunch;
    fighter->impactFrameHighPunch = impactFrameHighPunch;
    fighter->impactFrameLowKick = impactFrameLowKick;
    fighter->impactFrameHighKick = impactFrameHighKick;
    fighter->impactFrameUppercut = impactFrameUppercut;
    fighter->pad = 0;
    fighter->playerMoveForwardSpeed = 2;
    fighter->playerMoveBackwardSpeed = 2;
    fighter->playerKnockbackSpeed = 4.5f;
    fighter->damageTicks = 1;
    fighter->IsWalking = false;
    fighter->IsDucking = false;
    fighter->IsBlocking = false;
    fighter->IsLowPunching = false;
    fighter->IsHighPunching = false;
    fighter->IsLowKicking = false;
    fighter->IsHighKicking = false;
    fighter->IsUppercutting = false;
    fighter->ButtonReleased = true;
    fighter->IsHitLow = false;
    fighter->IsHitHigh = false;
    fighter->IsHitBack = false;
    fighter->IsHitFall = false;
    fighter->IsFalling = false;
    fighter->IsLayingDown = false;
    fighter->IsBeingDamaged = false;
    fighter->isPlayer1 = isPlayer1;
    sprite[fighter->spriteIndex].active = R_is_active;

    if (isPlayer1)
    {
        fighter->HB_ATTACK = P1_HB_ATTACK;
        fighter->HB_BODY = P1_HB_BODY;
        fighter->HB_DUCK = P1_HB_DUCK;
        fighter->PAD = LEFT_PAD;
        sprite[fighter->spriteIndex].x_ = 50;
        fighter->direction = 1;
    }
    else
    {
        fighter->HB_ATTACK = P2_HB_ATTACK;
        fighter->HB_BODY = P2_HB_BODY;
        fighter->HB_DUCK = P2_HB_DUCK;
        fighter->PAD = RIGHT_PAD;
        sprite[fighter->spriteIndex].x_ = 210;

        if (fighter->spriteIndex == CAGE2)
        {
            sprite[fighter->spriteIndex].x_ -= 16;
        }
        else if (fighter->spriteIndex == SUBZERO2)
        {
            sprite[fighter->spriteIndex].x_ += 16;
        }

        fighter->direction = -1;
    }

    fighter->positionX = sprite[fighter->spriteIndex].x_;
    fighter->positionY = sprite[fighter->spriteIndex].y_;
    impactFrameReset(fighter);
}

void fighterUpdateIdle(float delta, struct Fighter *fighter, struct SpriteAnimator* animator, struct AnimationFrame idleFrames[])
{
    updateSpriteAnimator(animator, idleFrames, fighter->IDLE_FRAME_COUNT, true, true, fighter->positionX, fighter->positionY, fighter->direction);
}

void fighterUpdate(float delta, struct Fighter *fighter, struct SpriteAnimator* animator, bool walkForward)
{
    //**************************************
    //Impact Damage Checks
    //**************************************
    if (!fighter->IsBeingDamaged)
    {
        if (fighter->IsHitLow || fighter->IsHitHigh || fighter->IsHitBack || fighter->IsHitFall)
        {
            fighter->IsBeingDamaged = true;
            fighter->lastTicks = rapTicks;
            animator->currentFrame = 0;
            fighter->momentumY = fighter->uppercutMomentumYStart;

            if (fighter->IsHitLow || fighter->IsHitHigh)
            {
                fighterPlayGroan(fighter->spriteIndex, fighter->soundHandler, fighter->isPlayer1);
            }
            else if (fighter->IsHitBack || fighter->IsHitFall)
            {
                sfxImpact(fighter->soundHandler);
            }

            if (fighter->IsHitHigh || fighter->IsHitBack)
            {
                int bloodX = sprite[fighter->spriteIndex].x_;

                if (fighter->direction == -1)
                {
                    bloodX += 40;
                }
                else if (fighter->direction == 1)
                {
                    bloodX -= 40;
                }

                if (fighter->IsHitHigh)
                {
                    bloodSpray(bloodX, sprite[fighter->spriteIndex].y_ - 10, fighter->direction);
                }
                else if (fighter->IsHitBack)
                {
                    bloodGlob(bloodX, sprite[fighter->spriteIndex].y_ + 20, fighter->direction);
                    bloodDrop(bloodX + (40 * fighter->direction), sprite[fighter->spriteIndex].y_ - 30, fighter->direction);
                }
            }
        }
    }

    if (fighter->IsHitLow && fighter->IsBeingDamaged)
    {
        updateSpriteAnimator(animator, *fighter->hitLowFrames, fighter->HIT_LOW_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);

        if (animationIsComplete(animator, fighter->HIT_LOW_FRAME_COUNT))
        {
            fighter->IsHitLow = false;
            fighter->IsBeingDamaged = false;
        }
    }
    else if (fighter->IsHitHigh && fighter->IsBeingDamaged)
    {
        updateSpriteAnimator(animator, *fighter->hitHighFrames, fighter->HIT_HIGH_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);

        if (animationIsComplete(animator, fighter->HIT_HIGH_FRAME_COUNT))
        {
            fighter->IsHitHigh = false;
            fighter->IsBeingDamaged = false;
        }
    }
    else if (fighter->IsHitBack && fighter->IsBeingDamaged)
    {
        if (rapTicks >= fighter->lastTicks + fighter->damageTicks)
        {
            //sprite[fighter->spriteIndex].x_ += fighter->playerKnockbackSpeed * -fighter->direction;
            sprite[fighter->HB_BODY].x_ += fighter->playerKnockbackSpeed * -fighter->direction;
            sprite[fighter->HB_DUCK].x_ += fighter->playerKnockbackSpeed * -fighter->direction;
            sprite[fighter->HB_ATTACK].x_ += fighter->playerKnockbackSpeed * -fighter->direction;
            fighter->positionX += fighter->playerKnockbackSpeed * -fighter->direction;
            fighter->lastTicks = rapTicks;
        }     

        updateSpriteAnimator(animator, *fighter->hitBackFrames, fighter->HIT_BACK_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);

        if (animationIsComplete(animator, fighter->HIT_BACK_FRAME_COUNT))
        {
            fighter->IsHitBack = false;
            fighter->IsBeingDamaged = false;
        }
    }
    else if (fighter->IsHitFall && fighter->IsBeingDamaged)
    {
        if (fighter->IsLayingDown)
        {
            if (rapTicks >= fighter->lastTicks + 300)
            {
                fighter->IsHitFall = false;
                fighter->IsBeingDamaged = false;
                fighter->IsLayingDown = false;
            }
        }
        else if (rapTicks >= fighter->lastTicks + 2)
        {
            sprite[fighter->spriteIndex].y_ += fighter->momentumY;

            if (fighter->momentumY >= fighter->uppercutMomentumYStart && fighter->momentumY < -20.0f)
            {
                animateFrame(fighter->spriteIndex, 0, *fighter->hitFallFrames, animator->mulFactor, animator->base, animator->idleFrameWidth, fighter->positionX, sprite[fighter->spriteIndex].y_, fighter->direction);
                animator->currentFrame = 0;
            }
            else if (fighter->momentumY >= -20.0f && fighter->momentumY < -15.0f)
            {
                animateFrame(fighter->spriteIndex, 1, *fighter->hitFallFrames, animator->mulFactor, animator->base, animator->idleFrameWidth, fighter->positionX, sprite[fighter->spriteIndex].y_, fighter->direction);
                animator->currentFrame = 1;
            }
            else if (fighter->momentumY >= -15.0f && fighter->momentumY < 0.0f)
            {
                animateFrame(fighter->spriteIndex, 2, *fighter->hitFallFrames, animator->mulFactor, animator->base, animator->idleFrameWidth, fighter->positionX, sprite[fighter->spriteIndex].y_, fighter->direction);
                animator->currentFrame = 2;
            }
            else if (!fighter->IsFalling)
            {
                //once we've reached the apex of the uppercut hit, finish the animation (-1 frame), then complete the fall
                updateSpriteAnimator(animator, *fighter->hitBackFrames, fighter->HIT_BACK_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);

                if (animationIsComplete(animator, fighter->HIT_FALL_FRAME_COUNT-1))
                {
                    fighter->IsFalling = true;
                }
            }
            else
            {
                if (sprite[fighter->spriteIndex].y_ > fighter->floorLocationY)
                {
                    //show last frame of HitFall animation
                    animateFrame(fighter->spriteIndex, 5, *fighter->hitFallFrames, animator->mulFactor, animator->base, animator->idleFrameWidth, fighter->positionX, sprite[fighter->spriteIndex].y_, fighter->direction);

                    fighter->IsLayingDown = true;
                    fighter->lastTicks = rapTicks;
                    sprite[fighter->spriteIndex].y_ = fighter->floorLocationY;
                    //play thud
                    //shake screen
                    //set ticks, so the fighter gets back up after 60 ticks
                }

                fighter->momentumY += fighter->gravity;

                if (fighter->momentumY > 1.0f)
                {
                    fighter->momentumY = 1.0f;
                }
            }

            fighter->lastTicks = rapTicks;
        }
    }

    //**************************************
    //Player Input Handling
    //**************************************
    if (!fighter->IsBeingDamaged)
    {
        fighter->pad = jsfGetPad(fighter->PAD);

        if ((fighter->pad & JAGPAD_C || fighter->pad & JAGPAD_9) && fighter->IsDucking && fighter->ButtonReleased || fighter->IsUppercutting)
        {
            if (!fighter->IsUppercutting && fighter->ButtonReleased)
            {
                fighter->ButtonReleased = false;
                fighter->IsUppercutting = true;
                fighter->IsDucking = false;
                sprite[fighter->HB_BODY].active = R_is_active;
                animator->currentFrame = 0;
                sfxSwing(fighter->soundHandler);
            }

            impactFrameUpdate(animator, fighter, fighter->impactFrameUppercut);
            updateSpriteAnimator(animator, *fighter->uppercutFrames, fighter->UPPERCUT_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);

            if (animationIsComplete(animator, fighter->UPPERCUT_FRAME_COUNT))
            {
                fighter->IsUppercutting = false;
            }
        }
        else if (fighter->pad & JAGPAD_C && fighter->ButtonReleased || fighter->IsLowPunching)
        {
            if (!fighter->IsLowPunching && fighter->ButtonReleased)
            {
                fighter->ButtonReleased = false;
                fighter->IsLowPunching = true;
                animator->currentFrame = 0;
                fighterPlayHiya(fighter->spriteIndex, fighter->soundHandler, fighter->isPlayer1);
                sfxSwing(fighter->soundHandler);
            }

            impactFrameUpdate(animator, fighter, fighter->impactFrameLowPunch);
            updateSpriteAnimator(animator, *fighter->punchLowFrames, fighter->LOW_PUNCH_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);

            if (animationIsComplete(animator, fighter->LOW_PUNCH_FRAME_COUNT))
            {
                fighter->IsLowPunching = false;
            }
        }
        else if (fighter->pad & JAGPAD_9 && fighter->ButtonReleased || fighter->IsHighPunching)
        {
            if (!fighter->IsHighPunching && fighter->ButtonReleased)
            {
                fighter->ButtonReleased = false;
                fighter->IsHighPunching = true;
                animator->currentFrame = 0;
                fighterPlayHiya(fighter->spriteIndex, fighter->soundHandler, fighter->isPlayer1);
                sfxSwing(fighter->soundHandler);
            }

            impactFrameUpdate(animator, fighter, fighter->impactFrameHighPunch);
            updateSpriteAnimator(animator, *fighter->punchHighFrames, fighter->HIGH_PUNCH_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);

            if (animationIsComplete(animator, fighter->HIGH_PUNCH_FRAME_COUNT))
            {
                fighter->IsHighPunching = false;
            }
        }
        else if (fighter->pad & JAGPAD_A && fighter->ButtonReleased || fighter->IsLowKicking)
        {
            if (!fighter->IsLowKicking && fighter->ButtonReleased)
            {
                fighter->ButtonReleased = false;
                fighter->IsLowKicking = true;
                animator->currentFrame = 0;
                fighterPlayHiya(fighter->spriteIndex, fighter->soundHandler, fighter->isPlayer1);
                sfxSwing(fighter->soundHandler);
            }

            impactFrameUpdate(animator, fighter, fighter->impactFrameLowKick);
            updateSpriteAnimator(animator, *fighter->kickLowFrames, fighter->LOW_KICK_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);

            if (animationIsComplete(animator, fighter->LOW_KICK_FRAME_COUNT))
            {
                fighter->IsLowKicking = false;
            }
        }
        else if (fighter->pad & JAGPAD_7 && fighter->ButtonReleased || fighter->IsHighKicking)
        {
            if (!fighter->IsHighKicking && fighter->ButtonReleased)
            {
                fighter->ButtonReleased = false;
                fighter->IsHighKicking = true;
                animator->currentFrame = 0;
                fighterPlayHiya(fighter->spriteIndex, fighter->soundHandler, fighter->isPlayer1);
                sfxSwing(fighter->soundHandler);
            }

            impactFrameUpdate(animator, fighter, fighter->impactFrameHighKick);
            updateSpriteAnimator(animator, *fighter->kickHighFrames, fighter->HIGH_KICK_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);

            if (animationIsComplete(animator, fighter->HIGH_KICK_FRAME_COUNT))
            {
                fighter->IsHighKicking = false;
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

                updateSpriteAnimator(animator, *fighter->blockDuckFrames, fighter->BLOCK_DUCK_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);
            }
            else
            {
                if (fighter->IsDucking)
                {
                    fighter->IsDucking = false;
                    sprite[fighter->HB_BODY].active = R_is_active;
                }
                
                updateSpriteAnimator(animator, *fighter->blockFrames, fighter->BLOCK_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);
            }
        }
        else if(fighter->pad & JAGPAD_LEFT)
        {
            updateSpriteAnimator(animator, *fighter->walkFrames, fighter->WALK_FRAME_COUNT, walkForward, true, fighter->positionX, fighter->positionY, fighter->direction);
            fighter->IsWalking = true;
            fighter->IsDucking = false;
            fighter->IsBlocking  = false;
            fighter->IsLowPunching = false;
            fighter->IsHighPunching = false;

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

            if (fighter->direction == -1)
            {
                //player 2, so we have to factor the idleFrameWidth into the offset
                //fighter->positionX += (*fighter->walkFrames[animator->currentFrame]).width - animator->idleFrameWidth;
                fighter->positionX += 80 - animator->idleFrameWidth;
            }
        }
        else if(fighter->pad & JAGPAD_RIGHT)
        {
            updateSpriteAnimator(animator, *fighter->walkFrames, fighter->WALK_FRAME_COUNT, !walkForward, true, fighter->positionX, fighter->positionY, fighter->direction);
            fighter->IsWalking = true;
            fighter->IsDucking = false;
            fighter->IsBlocking = false;
            fighter->IsLowPunching = false;
            fighter->IsHighPunching = false;
            
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

            if (fighter->direction == -1)
            {
                //player 2, so we have to factor the idleFrameWidth into the offset
                //fighter->positionX += (*fighter->walkFrames[animator->currentFrame]).width - animator->idleFrameWidth;
                fighter->positionX += 80 - animator->idleFrameWidth;
            }
        }
        else if (fighter->pad & JAGPAD_DOWN)
        {
            if (!fighter->IsDucking)
            {
                fighter->IsDucking = true;
                animator->currentFrame = 0;
            }
            updateSpriteAnimator(animator, *fighter->duckFrames, fighter->DUCK_FRAME_COUNT, true, false, fighter->positionX, fighter->positionY, fighter->direction);
            sprite[fighter->HB_BODY].active = R_is_inactive;
        }
        else
        {
            if (fighter->IsDucking)
            {
                updateSpriteAnimator(animator, *fighter->duckFrames, fighter->DUCK_FRAME_COUNT, false, false, fighter->positionX, fighter->positionY, fighter->direction);
                
                if (animator->currentFrame == 0)
                {
                    fighter->IsDucking = false;
                    sprite[fighter->HB_BODY].active = R_is_active;
                }
            }
            else if (fighter->IsBlocking)
            {
                updateSpriteAnimator(animator, *fighter->blockFrames, fighter->BLOCK_FRAME_COUNT, false, false, fighter->positionX, fighter->positionY, fighter->direction);
                
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
                    impactFrameReset(fighter);
                }

                updateSpriteAnimator(animator, *fighter->idleFrames, fighter->IDLE_FRAME_COUNT, true, true, fighter->positionX, fighter->positionY, fighter->direction);

            //fighter->positionX = sprite[fighter->spriteIndex].x_;
            //fighter->positionY = sprite[fighter->spriteIndex].y_;
            }
        }

        if (!(fighter->pad & JAGPAD_C)
            && !(fighter->pad & JAGPAD_9)
            && !(fighter->pad & JAGPAD_A)
            && !(fighter->pad & JAGPAD_7))
        {
            fighter->ButtonReleased = true;
        }
    }
}

void fighterPlayHiya(int fighter, struct SoundHandler* soundHandler, bool isPlayer1)
{
    switch (fighter)
    {
        case SONYA:
        case SONYA2:
            sfxHiyaFemale(soundHandler, isPlayer1);
            break;
        case SUBZERO:
        case SUBZERO2:
            sfxHiyaNinja(soundHandler, isPlayer1);
            break;
        case KANG:
        case KANG2:
            sfxHiyaKang(soundHandler, isPlayer1);
            break;
        default:
            sfxHiyaMale(soundHandler, isPlayer1);
    }
}

void fighterPlayGroan(int fighter, struct SoundHandler* soundHandler, bool isPlayer1)
{
    switch (fighter)
    {
        case SONYA:
        case SONYA2:
            sfxGroanFemale(soundHandler, isPlayer1);
            break;
        default:
            sfxGroanMale(soundHandler, isPlayer1);
    }
}

void fighterImpactCheck(struct Fighter* fighter1, struct Fighter* fighter2)
{
    collision = rapCollide(P1_HB_BODY-1,P2_HB_ATTACK-1,P1_HB_BODY-1,P2_HB_ATTACK-1);

    if (collision > -1)
    {
        int i = 0;
        int collisionSprAddr = 0;
        int collisionSprAddr2 = 0;

        while (collisionSprAddr2 >= 0)
        {
            collisionSprAddr = colliders[i].objectSourceHitAddr;
            collisionSprAddr2 = colliders[i].objectHitAddr;

            if (collisionSprAddr > -1)
            {
                int collisionSprIndex = jsfGetSpriteIndex(collisionSprAddr);
                int collisionSprIndex2 = jsfGetSpriteIndex(collisionSprAddr2);
                sprite[collisionSprIndex].was_hit = -1;
                sprite[collisionSprIndex2].was_hit = -1;

                if (collisionSprIndex == P1_HB_ATTACK && collisionSprIndex2 == P2_HB_BODY)
                {
                    if (!fighter2->IsBeingDamaged && !fighter2->IsBlocking)
                    {
                        if (fighter1->IsLowPunching)
                        {
                            fighter2->IsHitLow = true;
                        }
                        else if (fighter1->IsHighPunching)
                        {
                            fighter2->IsHitHigh = true;
                        }
                        else if (fighter1->IsLowKicking)
                        {
                            fighter2->IsHitLow = true;
                        }
                        else if (fighter1->IsHighKicking)
                        {
                            fighter2->IsHitBack = true;
                        }
                        else if (fighter1->IsUppercutting)
                        {
                            fighter2->IsHitFall = true;
                        }
                    }
                }

                if (collisionSprIndex == P2_HB_ATTACK && collisionSprIndex2 == P1_HB_BODY)
                {
                    if (!fighter1->IsBeingDamaged && !fighter1->IsBlocking)
                    {
                        if (fighter2->IsLowPunching)
                        {
                            fighter1->IsHitLow = true;
                        }
                        else if (fighter2->IsHighPunching)
                        {
                            fighter1->IsHitHigh = true;
                        }
                        else if (fighter2->IsLowKicking)
                        {
                            fighter1->IsHitLow = true;
                        }
                        else if (fighter2->IsHighKicking)
                        {
                            fighter1->IsHitBack = true;
                        }
                        else if (fighter2->IsUppercutting)
                        {
                            fighter1->IsHitFall = true;
                        }
                    }
                }
            }
            i++;
        }
    }
}