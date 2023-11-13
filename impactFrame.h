struct ImpactFrame {
    int Frame;
    int RelativePositionX;
    int RelativePositionY;
};

void impactFrameReset(struct Fighter* fighter);

void impactFrameUpdate(struct SpriteAnimator* animator, struct Fighter* fighter, struct ImpactFrame* impactFrame);