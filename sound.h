struct SoundHandler {
    bool EnableSFX;
    bool EnableMusic;
    int VolumeSFX;
    int VolumeMusic;
};

void sfxFight(struct SoundHandler* soundHandler);
void sfxJohnnyCage(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxKano(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxRaiden(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxLiuKang(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxScorpion(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxSubzero(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxSonya(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxP1Cursor(struct SoundHandler* soundHandler);
void sfxP2Cursor(struct SoundHandler* soundHandler);
void sfxGong(struct SoundHandler* soundHandler);
void sfxIntro(struct SoundHandler* soundHandler);
void sfxHiyaMale(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxHiyaFemale(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxHiyaKang(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxHiyaNinja(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxBlock(struct SoundHandler* soundHandler);
void sfxGroanMale(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxGroanFemale(struct SoundHandler* soundHandler, bool isPlayer1);
void sfxHit(struct SoundHandler* soundHandler);
void sfxImpact(struct SoundHandler* soundHandler);
void sfxBlood(struct SoundHandler* soundHandler);
void sfxSwing(struct SoundHandler* soundHandler);