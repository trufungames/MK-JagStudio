struct Fighter {
    unsigned int spriteIndex;
    unsigned int spriteBase;
    struct AnimationFrame idleFrames[12];
    struct AnimationFrame walkFrames[10];
    struct AnimationFrame duckFrames[3];
    struct AnimationFrame blockFrames[3];
    struct AnimationFrame blockDuckFrames[2];
};

void fighterInitialize(struct Fighter fighter, bool player1);

void fighterHandleInput(struct Fighter fighter, )