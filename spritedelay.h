struct SpriteDelay
{
    unsigned int spriteIndex;
    unsigned int ticks;
    bool inUse;
    bool* inUseFlag;
};

void spriteDelayInit();

void spriteDelayUpdate();

void spriteDelaySetInactive(int spriteIndex, int ticks, bool* inUseFlag);