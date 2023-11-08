#define BMP_PG_0 0x8022B0
#define BMP_PG_0_clut 0x83E2B0
#define BMP_MOUNTAINS 0x83E4B0
#define BMP_MOUNTAINS_clut 0x83F9B0
#define BMP_TEMPLE 0x83F9D0
#define BMP_TEMPLE_clut 0x840B50
#define BMP_CLOUD1 0x840B70
#define BMP_CLOUD1_clut 0x841B30
#define BMP_CLOUD2 0x841B50
#define BMP_CLOUD2_clut 0x843150
#define BMP_BUSH 0x843170
#define BMP_BUSH_clut 0x843770
#define BMP_HUD 0x843790
#define BMP_HUD_BAR 0x848590
#define BMP_HUD_KANO 0x849010
#define BMP_HUD_SCORPION 0x849510
#define BMP_FLAME 0x849E10
#define BMP_FLAME_clut 0x84AA10
#define BMP_HITBOX_BODY 0x84AA30
#define BMP_HITBOX_DUCK 0x84C230
#define BMP_HITBOX_ATTACK 0x84CE30
#define BMPCAGE 0x84D030
#define BMPCAGE_clut 0x8CD030
#define BMPKANG 0x8CD050
#define BMPKANG_clut 0x94D050
#define BMPRAIDEN 0x94D070
#define BMPRAIDEN_clut 0x9CD070
#define BMPSUBZERO 0x9CD090
#define BMPSUBZERO_clut 0xA4D090
#define BMPSONYA 0xA4D0B0
#define BMPSONYA_clut 0xACD0B0
#define BMPSCORPION 0xACD0D0
#define BMPSCORPION_clut 0xB4D0D0
#define BMPKANO 0xB4D0F0
#define BMPKANO_clut 0xBCD0F0
#define BMP_TITLESCREEN 0xBCD110
#define BMP_TITLESCREEN_clut 0xBE1B10
#define BMP_CHOOSEFIGHTER 0xBE1D10
#define BMP_CHOOSEFIGHTER_clut 0xBF6710
#define BMP_P1_SELECTOR 0xBF6910
#define BMP_P2_SELECTOR 0xBFB910
#define BMP_DOTLAST 0xC00910
#define BMP_LIGHTNING 0xC00920
#define BMP_LIGHTNING_clut 0xC2AC20
#define BMP_BG_STONE 0xC2AC40
#define BMP_BG_STONE_clut 0xC2B440
#define BMP_BATTLE 0xC2B460
#define BMP_BATTLE_clut 0xC30F60
#define BMP_PT_CAGE 0xC30F80
#define BMP_PT_CAGE_clut 0xC31980
#define BMP_PT_KANO 0xC319A0
#define BMP_PT_KANO_clut 0xC323A0
#define BMP_PT_KANG 0xC323C0
#define BMP_PT_KANG_clut 0xC32DC0
#define BMP_PT_RAIDEN 0xC32DE0
#define BMP_PT_RAIDEN_clut 0xC337E0
#define BMP_PT_SCORPION 0xC33800
#define BMP_PT_SCORPION_clut 0xC34200
#define BMP_PT_SONYA 0xC34220
#define BMP_PT_SONYA_clut 0xC34C20
#define BMP_PT_SUBZERO 0xC34C40
#define BMP_PT_SUBZERO_clut 0xC35640
#define BMP_SHUTTER 0xC35660
#define BMP_ROUND1 0xC390E0
#define BMP_ROUND1_clut 0xC394A0
#define BMP_FIGHT 0xC394C0
#define BMP_FIGHT_clut 0xC3B2C0
extern void *explode_sam asm("explode_sam");
extern void *explode_sam_end asm("explode_sam_end");
extern void *fight_sam asm("fight_sam");
extern void *fight_sam_end asm("fight_sam_end");
extern void *johnnycage_sam asm("johnnycage_sam");
extern void *johnnycage_sam_end asm("johnnycage_sam_end");
extern void *kano_sam asm("kano_sam");
extern void *kano_sam_end asm("kano_sam_end");
extern void *raiden_sam asm("raiden_sam");
extern void *raiden_sam_end asm("raiden_sam_end");
extern void *liukang_sam asm("liukang_sam");
extern void *liukang_sam_end asm("liukang_sam_end");
extern void *scorpion_sam asm("scorpion_sam");
extern void *scorpion_sam_end asm("scorpion_sam_end");
extern void *subzero_sam asm("subzero_sam");
extern void *subzero_sam_end asm("subzero_sam_end");
extern void *sonya_sam asm("sonya_sam");
extern void *sonya_sam_end asm("sonya_sam_end");
extern void *p1cursor_sam asm("p1cursor_sam");
extern void *p1cursor_sam_end asm("p1cursor_sam_end");
extern void *p2cursor_sam asm("p2cursor_sam");
extern void *p2cursor_sam_end asm("p2cursor_sam_end");
extern void *gong_sam asm("gong_sam");
extern void *gong_sam_end asm("gong_sam_end");
extern void *intro_sam asm("intro_sam");
extern void *intro_sam_end asm("intro_sam_end");
extern void *hiya_female1_sam asm("hiya_female1_sam");
extern void *hiya_female1_sam_end asm("hiya_female1_sam_end");
extern void *hiya_female2_sam asm("hiya_female2_sam");
extern void *hiya_female2_sam_end asm("hiya_female2_sam_end");
extern void *hiya_male1_sam asm("hiya_male1_sam");
extern void *hiya_male1_sam_end asm("hiya_male1_sam_end");
extern void *hiya_male2_sam asm("hiya_male2_sam");
extern void *hiya_male2_sam_end asm("hiya_male2_sam_end");
extern void *hiya_kang1_sam asm("hiya_kang1_sam");
extern void *hiya_kang1_sam_end asm("hiya_kang1_sam_end");
extern void *hiya_kang2_sam asm("hiya_kang2_sam");
extern void *hiya_kang2_sam_end asm("hiya_kang2_sam_end");
extern void *hiya_ninja1_sam asm("hiya_ninja1_sam");
extern void *hiya_ninja1_sam_end asm("hiya_ninja1_sam_end");
extern void *hiya_ninja2_sam asm("hiya_ninja2_sam");
extern void *hiya_ninja2_sam_end asm("hiya_ninja2_sam_end");
