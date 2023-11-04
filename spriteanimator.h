struct AnimationFrame {
    unsigned int width;
    unsigned int height;
    unsigned int x;
    unsigned int y;
    unsigned int offsetX;
    unsigned int offsetY;
    unsigned int ticks;
};

void animateFrame(unsigned int spriteIndex, unsigned int frame, struct AnimationFrame animationFrames[], float mulFactor, unsigned int base);

void animateFrame(unsigned int spriteIndex, unsigned int frame, struct AnimationFrame animationFrames[], float mulFactor, unsigned int base, int positionX, int positionY);

struct SpriteAnimator {
    unsigned int spriteIndex;
    float mulFactor;
    unsigned int base;
    int lastTick;
    int currentFrame;
};

void updateSpriteAnimator(struct SpriteAnimator *animator, struct AnimationFrame animationFrames[], int totalFrames, bool playForward, bool loop);

void updateSpriteAnimator(struct SpriteAnimator *animator, struct AnimationFrame animationFrames[], int totalFrames, bool playForward, bool loop, int positionX, int positionY);