
#include "jstudio.h"
#include "romassets.h"

#define P1_CURSOR 3
#define P2_CURSOR 2
#define BG1_TEMPLE_LEFT 8
#define BG1_TEMPLE_RIGHT BG1_TEMPLE_LEFT + 1
#define BG1_BACKDROP BG1_TEMPLE_RIGHT + 1
#define BG1_FLAME1 BG1_BACKDROP + 1
#define BG1_FLAME2 BG1_FLAME1 + 1
#define P1_HB_BODY 33
#define P1_HB_DUCK P1_HB_BODY + 1
#define P1_HB_ATTACK P1_HB_DUCK + 1
#define P2_HB_BODY P1_HB_ATTACK + 1
#define P2_HB_DUCK P2_HB_BODY + 1
#define P2_HB_ATTACK P2_HB_DUCK + 1
#define SCORPION 16
#define KANO SCORPION + 1
#define CAGE KANO + 1
#define KANG CAGE + 1
#define RAIDEN KANG + 1
#define LIGHTNING RAIDEN + 1
#define SUBZERO LIGHTNING + 1
#define SONYA SUBZERO + 1
#define SCORPION2 SONYA + 1
#define KANO2 SCORPION2 + 1
#define CAGE2 KANO2 + 1
#define KANG2 CAGE2 + 1
#define RAIDEN2 KANG2 + 1
#define LIGHTNING2 RAIDEN2 + 1
#define SUBZERO2 LIGHTNING2 + 1
#define SONYA2 SUBZERO2 + 1
#define P1_PT_CAGE 62
#define P1_PT_KANO P1_PT_CAGE + 1
#define P1_PT_SUBZERO P1_PT_KANO + 1
#define P1_PT_SONYA P1_PT_SUBZERO + 1
#define P1_PT_RAIDEN P1_PT_SONYA + 1
#define P1_PT_KANG P1_PT_RAIDEN + 1
#define P1_PT_SCORPION P1_PT_KANG + 1
#define P2_PT_CAGE P1_PT_SCORPION + 1
#define P2_PT_KANO P2_PT_CAGE + 1
#define P2_PT_SUBZERO P2_PT_KANO + 1
#define P2_PT_SONYA P2_PT_SUBZERO + 1
#define P2_PT_RAIDEN P2_PT_SONYA + 1
#define P2_PT_KANG P2_PT_RAIDEN + 1
#define P2_PT_SCORPION P2_PT_KANG + 1

#define SCORPION_IDLE_FRAME_COUNT 7
#define SCORPION_WALK_FRAME_COUNT 9
#define SCORPION_DUCK_FRAME_COUNT 2
#define SCORPION_BLOCK_FRAME_COUNT 2
#define SCORPION_BLOCK_DUCK_FRAME_COUNT 1
#define KANO_IDLE_FRAME_COUNT 7
#define KANO_WALK_FRAME_COUNT 9
#define KANO_DUCK_FRAME_COUNT 2
#define KANO_BLOCK_FRAME_COUNT 2
#define KANO_BLOCK_DUCK_FRAME_COUNT 1
#define CAGE_IDLE_FRAME_COUNT 7
#define CAGE_WALK_FRAME_COUNT 9
#define CAGE_DUCK_FRAME_COUNT 2
#define CAGE_BLOCK_FRAME_COUNT 2
#define CAGE_BLOCK_DUCK_FRAME_COUNT 1
#define KANG_IDLE_FRAME_COUNT 7
#define KANG_WALK_FRAME_COUNT 9
#define KANG_DUCK_FRAME_COUNT 2
#define KANG_BLOCK_FRAME_COUNT 2
#define KANG_BLOCK_DUCK_FRAME_COUNT 1
#define RAIDEN_IDLE_FRAME_COUNT 10
#define RAIDEN_WALK_FRAME_COUNT 9
#define RAIDEN_DUCK_FRAME_COUNT 2
#define RAIDEN_BLOCK_FRAME_COUNT 2
#define RAIDEN_BLOCK_DUCK_FRAME_COUNT 1
#define SUBZERO_IDLE_FRAME_COUNT 12
#define SUBZERO_WALK_FRAME_COUNT 9
#define SUBZERO_DUCK_FRAME_COUNT 2
#define SUBZERO_BLOCK_FRAME_COUNT 2
#define SUBZERO_BLOCK_DUCK_FRAME_COUNT 1
#define SONYA_IDLE_FRAME_COUNT 7
#define SONYA_WALK_FRAME_COUNT 7
#define SONYA_DUCK_FRAME_COUNT 1
#define SONYA_BLOCK_FRAME_COUNT 2
#define SONYA_BLOCK_DUCK_FRAME_COUNT 1