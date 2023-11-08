struct Fighter {
    unsigned int spriteIndex;
    unsigned int spriteBase;
    unsigned int IDLE_FRAME_COUNT;
    unsigned int WALK_FRAME_COUNT;
    unsigned int DUCK_FRAME_COUNT;
    unsigned int BLOCK_FRAME_COUNT;
    unsigned int BLOCK_DUCK_FRAME_COUNT;
    unsigned int LOW_PUNCH_FRAME_COUNT;
    unsigned int HIGH_PUNCH_FRAME_COUNT;
    unsigned int LOW_KICK_FRAME_COUNT;
    unsigned int HIGH_KICK_FRAME_COUNT;

    bool IsWalking;
    bool IsDucking;
    bool IsBlocking;
    bool IsLowPunching;
    bool IsHighPunching;
    bool IsLowKicking;
    bool IsHighKicking;
    bool ButtonReleased;
    unsigned int HB_BODY;
    unsigned int HB_DUCK;
    unsigned int HB_ATTACK;
    int pad;
    unsigned int PAD;
    int playerMoveForwardSpeed;
    int playerMoveBackwardSpeed;
    int positionX;
    int positionY;
    struct SoundHandler* soundHandler;
    int direction;
    bool isPlayer1;
};

void fighterHide(struct Fighter* fighter);

void fighterShow(struct Fighter* fighter);

void fighterMakeSelectable(struct Fighter* fighter, bool isPlayer1);

void fighterInitialize(struct Fighter* fighter, bool isPlayer1, struct SoundHandler* soundHandler);

void fighterUpdateIdle(float delta, struct Fighter *fighter, struct SpriteAnimator* animator, struct AnimationFrame idleFrames[]);

void fighterUpdate(float delta, struct Fighter* fighter, struct SpriteAnimator* animator, struct AnimationFrame idleFrames[], struct AnimationFrame walkFrames[], struct AnimationFrame duckFrames[], struct AnimationFrame blockFrames[], struct AnimationFrame blockDuckFrames[], struct AnimationFrame punchLowFrames[], struct AnimationFrame punchHighFrames[], struct AnimationFrame kickLowFrames[], struct AnimationFrame kickHighFrames[], bool walkForward);

void fighterPlayHiya(int fighter, struct SoundHandler* soundHandler, bool isPlayer1);