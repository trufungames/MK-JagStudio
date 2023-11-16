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
#define BMP_HITBOX 0x84AA30
#define BMP_HITBOX_ATTACK 0x84AE30
#define BMP_HITBOX_OFF 0x84AFB0
#define BMP_HITBOX_ATTACK_OFF 0x84B3B0
#define BMPCAGE 0x84B530
#define BMPCAGE_clut 0x8CB530
#define BMPKANG 0x8CB550
#define BMPKANG_clut 0x94B550
#define BMPRAIDEN 0x94B570
#define BMPRAIDEN_clut 0x9CB570
#define BMPSUBZERO 0x9CB590
#define BMPSUBZERO_clut 0xA4B590
#define BMPSONYA 0xA4B5B0
#define BMPSONYA_clut 0xACB5B0
#define BMPKANO 0xACB5D0
#define BMPKANO_clut 0xB4B5D0
#define BMP_TITLESCREEN 0xB4B5F0
#define BMP_TITLESCREEN_clut 0xB5FFF0
#define BMP_CHOOSEFIGHTER 0xB601F0
#define BMP_CHOOSEFIGHTER_clut 0xB74BF0
#define BMP_P1_SELECTOR 0xB74DF0
#define BMP_P2_SELECTOR 0xB79DF0
#define BMP_DOTLAST 0xB7EDF0
#define BMP_LIGHTNING 0xB7EE00
#define BMP_LIGHTNING_clut 0xBA9100
#define BMP_BG_STONE 0xBA9120
#define BMP_BG_STONE_clut 0xBA9920
#define BMP_BATTLE 0xBA9940
#define BMP_BATTLE_clut 0xBAF440
#define BMP_PT_CAGE 0xBAF460
#define BMP_PT_CAGE_clut 0xBAFE60
#define BMP_PT_KANO 0xBAFE80
#define BMP_PT_KANO_clut 0xBB0880
#define BMP_PT_KANG 0xBB08A0
#define BMP_PT_KANG_clut 0xBB12A0
#define BMP_PT_RAIDEN 0xBB12C0
#define BMP_PT_RAIDEN_clut 0xBB1CC0
#define BMP_PT_SCORPION 0xBB1CE0
#define BMP_PT_SCORPION_clut 0xBB26E0
#define BMP_PT_SONYA 0xBB2700
#define BMP_PT_SONYA_clut 0xBB3100
#define BMP_PT_SUBZERO 0xBB3120
#define BMP_PT_SUBZERO_clut 0xBB3B20
#define BMP_SHUTTER 0xBB3B40
#define BMP_ROUND1 0xBB75C0
#define BMP_ROUND1_clut 0xBB7980
#define BMP_FIGHT 0xBB79A0
#define BMP_FIGHT_clut 0xBB97A0
#define PAL_SCORPION 0xBB97C0
#define PAL_SCORPION_clut 0xBB97D0
#define PAL_REPTILE 0xBB97F0
#define PAL_REPTILE_clut 0xBB9800
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
extern void *block_sam asm("block_sam");
extern void *block_sam_end asm("block_sam_end");
extern void *groan_male01_sam asm("groan_male01_sam");
extern void *groan_male01_sam_end asm("groan_male01_sam_end");
extern void *groan_male02_sam asm("groan_male02_sam");
extern void *groan_male02_sam_end asm("groan_male02_sam_end");
extern void *groan_female01_sam asm("groan_female01_sam");
extern void *groan_female01_sam_end asm("groan_female01_sam_end");
extern void *groan_female02_sam asm("groan_female02_sam");
extern void *groan_female02_sam_end asm("groan_female02_sam_end");
extern void *hit_01_sam asm("hit_01_sam");
extern void *hit_01_sam_end asm("hit_01_sam_end");
extern void *hit_02_sam asm("hit_02_sam");
extern void *hit_02_sam_end asm("hit_02_sam_end");
extern void *hit_impact_sam asm("hit_impact_sam");
extern void *hit_impact_sam_end asm("hit_impact_sam_end");
extern void *swing_01_sam asm("swing_01_sam");
extern void *swing_01_sam_end asm("swing_01_sam_end");
extern void *swing_02_sam asm("swing_02_sam");
extern void *swing_02_sam_end asm("swing_02_sam_end");
