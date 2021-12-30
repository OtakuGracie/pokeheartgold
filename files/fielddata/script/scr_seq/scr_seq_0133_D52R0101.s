#include "constants/scrcmd.h"
	.include "asm/macros/script.inc"

	.rodata

	scrdef scr_seq_0133_D52R0101_0099 ; 000
	scrdef scr_seq_0133_D52R0101_000E ; 001
	scrdef scr_seq_0133_D52R0101_007E ; 002
	scrdef_end

scr_seq_0133_D52R0101_000E:
	comparevartovalue VAR_UNK_40F9, 4
	gotoif ge, scr_seq_0133_D52R0101_007C
	scrcmd_495 VAR_TEMP_x4000
	comparevartovalue VAR_TEMP_x4000, 7
	gotoif ne, scr_seq_0133_D52R0101_0038
	goto scr_seq_0133_D52R0101_0040

scr_seq_0133_D52R0101_0032:
	.byte 0x16, 0x00, 0x06, 0x00, 0x00, 0x00
scr_seq_0133_D52R0101_0038:
	goto scr_seq_0133_D52R0101_004A

scr_seq_0133_D52R0101_003E:
	.byte 0x02, 0x00
scr_seq_0133_D52R0101_0040:
	setflag FLAG_UNK_2D0
	setflag FLAG_UNK_2D3
	end

scr_seq_0133_D52R0101_004A:
	checkflag FLAG_UNK_18B
	gotoif TRUE, scr_seq_0133_D52R0101_007C
	hasitem ITEM_RED_ORB, 1, VAR_TEMP_x4000
	comparevartovalue VAR_TEMP_x4000, 1
	gotoif ge, scr_seq_0133_D52R0101_0072
	goto scr_seq_0133_D52R0101_0040

scr_seq_0133_D52R0101_0070:
	.byte 0x02, 0x00
scr_seq_0133_D52R0101_0072:
	setflag FLAG_UNK_2D3
	clearflag FLAG_UNK_2D0
	end

scr_seq_0133_D52R0101_007C:
	end

scr_seq_0133_D52R0101_007E:
	checkflag FLAG_UNK_0A4
	gotoif TRUE, scr_seq_0133_D52R0101_008B
	end

scr_seq_0133_D52R0101_008B:
	setflag FLAG_UNK_2D0
	hide_person 0
	clearflag FLAG_UNK_0A4
	end

scr_seq_0133_D52R0101_0099:
	play_se SEQ_SE_DP_SELECT
	lockall
	faceplayer
	scrcmd_076 383, 0
	npc_msg 0
	scrcmd_077
	closemsg
	setflag FLAG_UNK_0A4
	scrcmd_589 383, 50, 0
	clearflag FLAG_UNK_0A4
	check_battle_won VAR_SPECIAL_x800C
	comparevartovalue VAR_SPECIAL_x800C, 0
	gotoif eq, scr_seq_0133_D52R0101_019D
	scrcmd_683 16386
	comparevartovalue VAR_TEMP_x4002, 3
	gotoif eq, scr_seq_0133_D52R0101_00EC
	comparevartovalue VAR_TEMP_x4002, 4
	gotoif eq, scr_seq_0133_D52R0101_00FB
scr_seq_0133_D52R0101_00EC:
	npc_msg 1
	waitbutton
	closemsg
	setflag FLAG_UNK_18B
	releaseall
	end

scr_seq_0133_D52R0101_00FB:
	setvar VAR_UNK_40F9, 4
	setflag FLAG_UNK_179
	clearflag FLAG_UNK_2D3
	show_person 1
	scrcmd_602 0
	scrcmd_603
	scrcmd_604 55
	scrcmd_386 VAR_TEMP_x4001
	comparevartovalue VAR_TEMP_x4001, 0
	gotoif ne, scr_seq_0133_D52R0101_0142
	apply_movement 1, scr_seq_0133_D52R0101_01A4
	wait_movement
	apply_movement 255, scr_seq_0133_D52R0101_01B0
	wait_movement
	goto scr_seq_0133_D52R0101_0156

scr_seq_0133_D52R0101_0142:
	apply_movement 1, scr_seq_0133_D52R0101_01BC
	wait_movement
	apply_movement 255, scr_seq_0133_D52R0101_01C8
	wait_movement
scr_seq_0133_D52R0101_0156:
	scrcmd_603
	scrcmd_602 1
	scrcmd_604 48
	npc_msg 2
	closemsg
	apply_movement 1, scr_seq_0133_D52R0101_01D0
	wait_movement
	npc_msg 3
	closemsg
	apply_movement 1, scr_seq_0133_D52R0101_01E0
	wait_movement
	npc_msg 4
	closemsg
	apply_movement 1, scr_seq_0133_D52R0101_01EC
	wait_movement
	hide_person 1
	setflag FLAG_UNK_2D3
	setflag FLAG_UNK_2CF
	releaseall
	end

scr_seq_0133_D52R0101_019D:
	white_out
	releaseall
	end

scr_seq_0133_D52R0101_01A3:
	.byte 0x00

scr_seq_0133_D52R0101_01A4:
	step 12, 8
	step 32, 1
	step_end

scr_seq_0133_D52R0101_01B0:
	step 33, 1
	step 13, 1
	step_end

scr_seq_0133_D52R0101_01BC:
	step 12, 10
	step 32, 1
	step_end

scr_seq_0133_D52R0101_01C8:
	step 33, 1
	step_end

scr_seq_0133_D52R0101_01D0:
	step 33, 1
	step 9, 2
	step 32, 1
	step_end

scr_seq_0133_D52R0101_01E0:
	step 12, 2
	step 32, 1
	step_end

scr_seq_0133_D52R0101_01EC:
	step 13, 8
	step_end
	.balign 4, 0
