#define BMP_PG_0 0x8022B0
#define BMP_PG_0_clut 0x83E2B0
#define BMP_MOUNTAINS 0x83E4B0
#define BMP_TEMPLE 0x8438B0
#define BMP_CLOUD1 0x847EB0
#define BMP_CLOUD2 0x84BDB0
#define BMP_HUD 0x850730
#define BMP_HUD_BAR 0x855530
#define BMP_HUD_KANO 0x855FB0
#define BMP_HUD_SCORPION 0x8564B0
#define BMP_FLAME 0x856DB0
#define BMP_HITBOX_BODY 0x859DB0
#define BMP_HITBOX_DUCK 0x85B5B0
#define BMP_HITBOX_ATTACK 0x85C1B0
#define BMPSCORPION 0x85C3B0
#define BMPSCORPION_clut 0x8DC3B0
#define BMPKANO 0x8DC3D0
#define BMPKANO_clut 0x95C3D0
extern void *explode_sam asm("explode_sam");
extern void *explode_sam_end asm("explode_sam_end");
extern void *fight_sam asm("fight_sam");
extern void *fight_sam_end asm("fight_sam_end");
