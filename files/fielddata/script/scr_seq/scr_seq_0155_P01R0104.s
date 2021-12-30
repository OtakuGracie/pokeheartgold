#include "constants/scrcmd.h"
	.include "asm/macros/script.inc"

	.rodata

	scrdef scr_seq_0155_P01R0104_00A4 ; 000
	scrdef scr_seq_0155_P01R0104_0053 ; 001
	scrdef scr_seq_0155_P01R0104_0036 ; 002
	scrdef scr_seq_0155_P01R0104_0012 ; 003
	scrdef_end

scr_seq_0155_P01R0104_0012:
	checkflag FLAG_UNK_168
	gotoif TRUE, scr_seq_0155_P01R0104_0021
	setflag FLAG_UNK_998
scr_seq_0155_P01R0104_0021:
	scrcmd_804 2
	setflag FLAG_UNK_168
	setflag FLAG_UNK_9B5
	scrcmd_582 54, 1309, 340
	end

scr_seq_0155_P01R0104_0036:
	comparevartovalue VAR_UNK_40E1, 1
	gotoif eq, scr_seq_0155_P01R0104_0045
	end

scr_seq_0155_P01R0104_0045:
	move_person 0, 24, 0, 19, 2
	end

scr_seq_0155_P01R0104_0053:
	scrcmd_609
	lockall
	scrcmd_602 0
	scrcmd_603
	scrcmd_604 55
	apply_movement 255, scr_seq_0155_P01R0104_0090
	wait_movement
	apply_movement 0, scr_seq_0155_P01R0104_0098
	wait_movement
	scrcmd_603
	scrcmd_602 1
	scrcmd_604 48
	setvar VAR_UNK_40E1, 0
	clearflag FLAG_UNK_092
	releaseall
	end

scr_seq_0155_P01R0104_008D:
	.byte 0x00, 0x00, 0x00

scr_seq_0155_P01R0104_0090:
	step 13, 3
	step_end

scr_seq_0155_P01R0104_0098:
	step 14, 1
	step 33, 1
	step_end
scr_seq_0155_P01R0104_00A4:
	play_se SEQ_SE_DP_SELECT
	lockall
	faceplayer
	checkflag FLAG_UNK_0EB
	gotoif TRUE, scr_seq_0155_P01R0104_0144
	npc_msg 0
	closemsg
	scrcmd_602 0
	scrcmd_603
	scrcmd_604 55
	scrcmd_386 VAR_TEMP_x4000
	comparevartovalue VAR_TEMP_x4000, 2
	gotoif ne, scr_seq_0155_P01R0104_00EF
	apply_movement 0, scr_seq_0155_P01R0104_0150
	wait_movement
	apply_movement 255, scr_seq_0155_P01R0104_0180
	goto scr_seq_0155_P01R0104_0126

scr_seq_0155_P01R0104_00EF:
	comparevartovalue VAR_TEMP_x4000, 3
	gotoif ne, scr_seq_0155_P01R0104_0114
	apply_movement 0, scr_seq_0155_P01R0104_0160
	wait_movement
	apply_movement 255, scr_seq_0155_P01R0104_0190
	goto scr_seq_0155_P01R0104_0126

scr_seq_0155_P01R0104_0114:
	apply_movement 0, scr_seq_0155_P01R0104_0170
	wait_movement
	apply_movement 255, scr_seq_0155_P01R0104_01A0
scr_seq_0155_P01R0104_0126:
	wait_movement
	scrcmd_603
	scrcmd_602 1
	scrcmd_604 48
	play_se SEQ_SE_DP_KAIDAN2
	scrcmd_723 1, 0, 307, 24, 19
	releaseall
	end

scr_seq_0155_P01R0104_0144:
	npc_msg 1
	waitbutton
	closemsg
	releaseall
	end

scr_seq_0155_P01R0104_014F:
	.byte 0x00

scr_seq_0155_P01R0104_0150:
	step 2, 1
	step 14, 1
	step 35, 1
	step_end

scr_seq_0155_P01R0104_0160:
	step 3, 1
	step 15, 1
	step 34, 1
	step_end

scr_seq_0155_P01R0104_0170:
	step 3, 1
	step 15, 1
	step 34, 1
	step_end

scr_seq_0155_P01R0104_0180:
	step 14, 1
	step 0, 1
	step 12, 2
	step_end

scr_seq_0155_P01R0104_0190:
	step 15, 1
	step 0, 1
	step 12, 2
	step_end

scr_seq_0155_P01R0104_01A0:
	step 12, 2
	step_end
	.balign 4, 0
