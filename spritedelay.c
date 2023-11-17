#include "common.h"
#include "spritedelay.h"

struct SpriteDelay sprites[] = {
    { 0, 0, false },
    { 0, 0, false },
    { 0, 0, false },
    { 0, 0, false },
    { 0, 0, false },
    { 0, 0, false },
    { 0, 0, false },
    { 0, 0, false },
    { 0, 0, false },
    { 0, 0, false }
};

int spriteCount = 0;

void spriteDelayInit()
{
    spriteCount = 10;
    for (int i = 0; i < spriteCount; i++)
    {
        sprites[i].inUse = false;
    }
}

void spriteDelayUpdate()
{
    for (int i = 0; i < spriteCount; i++)
    {
        if (sprites[i].inUse && rapTicks >= sprites[i].ticks)
        {
            sprites[i].inUse = false;
            sprite[sprites[i].spriteIndex].active = R_is_inactive;
            (*sprites[i].inUseFlag) = false;
        }
    }
}

void spriteDelaySetInactive(int spriteIndex, int ticks, bool* inUseFlag)
{
    for (int i = 0; i < spriteCount; i++)
    {
        if (!sprites[i].inUse)
        {
            sprites[i].spriteIndex = spriteIndex;
            sprites[i].ticks = ticks;
            sprites[i].inUse = true;
            sprites[i].inUseFlag = inUseFlag;
            break;
        }
    }
}