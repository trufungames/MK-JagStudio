struct Fighter {
    unsigned int spriteIndex;
    unsigned int spriteBase;
    unsigned int IDLE_FRAME_COUNT;
    unsigned int WALK_FRAME_COUNT;
    unsigned int DUCK_FRAME_COUNT;
    unsigned int BLOCK_FRAME_COUNT;
    unsigned int BLOCK_DUCK_FRAME_COUNT;

    bool playerWasWalking;
    bool playerWasDucking;
    bool playerWasBlocking;
    unsigned int HB_BODY;
    unsigned int HB_DUCK;
    unsigned int HB_ATTACK;
    int pad;
    unsigned int PAD;
    int playerMoveForwardSpeed;
    int playerMoveBackwardSpeed;
};

void fighterHide(struct Fighter* fighter);

void fighterShow(struct Fighter* fighter);

void fighterMakeSelectable(struct Fighter* fighter, bool isPlayer1);

void fighterInitialize(struct Fighter* fighter, bool isPlayer1);

void fighterUpdateIdle(float delta, struct Fighter *fighter, struct SpriteAnimator* animator, struct AnimationFrame idleFrames[]);

void fighterUpdate(float delta, struct Fighter* fighter, struct SpriteAnimator* animator, struct AnimationFrame idleFrames[], struct AnimationFrame walkFrames[], struct AnimationFrame duckFrames[], struct AnimationFrame blockFrames[], struct AnimationFrame blockDuckFrames[], struct AnimationFrame punchLowFrames[], bool walkForward);