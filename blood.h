struct BloodDrop {
    unsigned int SpriteIndex;
    struct SpriteAnimator* Animator;
    bool InUse;
    int LastTicks;
    int Direction;
    float Momentum;
};

struct BloodPool {
    unsigned int SpriteIndex;
    struct SpriteAnimator* Animator;
    bool InUse;
};

void bloodInit();

void bloodUpdate();

void bloodSpray(int x, int y, int direction);

void bloodGlob(int x, int y, int direction);

void bloodDrop(int x, int y, int direction);

void bloodPool(int x, int y);