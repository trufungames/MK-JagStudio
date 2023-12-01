struct AnimationFrame {
    unsigned int width;
    unsigned int height;
    unsigned int x;
    unsigned int y;
    unsigned int offsetX;
    unsigned int offsetY;
    unsigned int ticks;
};

void animateFrame(unsigned int spriteIndex, unsigned int frame, struct AnimationFrame animationFrames[], float mulFactor, unsigned int base, int idleFrameWidth);

void animateFrame(unsigned int spriteIndex, unsigned int frame, struct AnimationFrame animationFrames[], float mulFactor, unsigned int base, int idleFrameWidth, int positionX, int positionY, int direction);

struct SpriteAnimator {
    unsigned int spriteIndex;
    float mulFactor;
    unsigned int base;
    int lastTick;
    int currentFrame;
    int idleFrameWidth;
};

void setFrame(unsigned int spriteIndex, int width, int height, int x, int y, float mulFactor, unsigned int base);

void setAnimationFrame(unsigned int spriteIndex, SpriteAnimator* animator, struct AnimationFrame* animationFrame);

int getAnimationFrameWidth(struct AnimationFrame animationFrames[], int currentFrame);

bool animationIsComplete(struct SpriteAnimator *animator, int totalFrames);

void updateSpriteAnimator(struct SpriteAnimator *animator, struct AnimationFrame animationFrames[], int totalFrames, bool playForward, bool loop);

void updateSpriteAnimator(struct SpriteAnimator *animator, struct AnimationFrame animationFrames[], int totalFrames, bool playForward, bool loop, int positionX, int positionY, int direction);