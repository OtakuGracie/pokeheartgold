#include "roamer.h"
#include "math_util.h"
#include "constants/roamer.h"

u32 Save_Roamers_sizeof(void) {
    return sizeof(ROAMER_SAVE);
}

void Save_Roamers_init(ROAMER_SAVE *roamer) {
    memset(roamer, 0, sizeof(ROAMER_SAVE));
    roamer->loc[0] = MTRandom();
    roamer->loc[1] = MTRandom();
    roamer->unk_64 = 0;
    roamer->unk_65 = 0;
    roamer->unk_66 = 0;
    roamer->unk_67 = 0;
}

void Roamers_SetLocationParam(ROAMER_SAVE *roamer, u32 param) {
    roamer->loc[0] = param;
    roamer->loc[1] = param;
}

u32 Roamers_GetLocationParam(ROAMER_SAVE *roamer, u32 which) {
    switch (which) {
    case 1:
        return roamer->loc[0];
    case 2:
        return roamer->loc[1];
    default:
        GF_ASSERT(0);
        return 0;
    }
}

ROAMER_SAVE *Save_Roamers_get(SAVEDATA *saveData) {
    return SavArray_get(saveData, SAVE_ROAMER);
}

void sub_0202D9D0(SAVEDATA *saveData) {
    ROAMER_SAVE *roamer = Save_Roamers_get(saveData);
    roamer->unk_64 = 1;
}

u8 sub_0202D9E0(ROAMER_SAVE *roamerSave) {
    return roamerSave->unk_64;
}

void sub_0202D9E8(ROAMER_SAVE *roamerSave, u32 a1) {
    if (roamerSave->unk_8[0] != a1) {
        roamerSave->unk_8[1] = roamerSave->unk_8[0];
        roamerSave->unk_8[0] = a1;
    }
}

u32 sub_0202D9F4(ROAMER_SAVE *roamerSave) {
    return roamerSave->unk_8[1];
}

u8 sub_0202D9F8(ROAMER_SAVE *roamerSave, u32 a1) {
    GF_ASSERT(a1 < ROAMER_MAX);
    return roamerSave->unk_60[a1];
}

void sub_0202DA10(ROAMER_SAVE *roamerSave, u32 a1, u8 a2) {
    GF_ASSERT(a1 < ROAMER_MAX);
    roamerSave->unk_60[a1] = a2;
}

u8 sub_0202DA28(ROAMER_SAVE *roamerSave, u32 a1) {
    GF_ASSERT(a1 < ROAMER_MAX);
    return roamerSave->data[a1].unk_12;
}

void RoamerMon_init(ROAMER ** roamer_p) {
    memset(*roamer_p, 0, sizeof(ROAMER));
}

ROAMER *Roamers_GetRoamMonStats(ROAMER_SAVE *roamerSave, u32 a1) {
    GF_ASSERT(a1 < ROAMER_MAX);
    return &roamerSave->data[a1];
}

int GetRoamerData(ROAMER *roamer, int a1) {
    switch (a1) {
    case ROAMER_DATA_UNK1:
        return roamer->unk_0;
    case ROAMER_DATA_IVS:
        return roamer->ivs;
    case ROAMER_DATA_PERSONALITY:
        return roamer->personality;
    case ROAMER_DATA_SPECIES:
        return roamer->species;
    case ROAMER_DATA_HP:
        return roamer->hp;
    case ROAMER_DATA_LEVEL:
        return roamer->level;
    case ROAMER_DATA_STATUS:
        return roamer->status;
    case ROAMER_DATA_UNK8:
        return roamer->unk_12;
    default:
        GF_ASSERT(0);
        return 0;
    }
}

void SetRoamerData(ROAMER *roamer, int a1, int val) {
    switch (a1) {
    case ROAMER_DATA_UNK1:
        roamer->unk_0 = val;
        break;
    case ROAMER_DATA_IVS:
        roamer->ivs = val;
        break;
    case ROAMER_DATA_PERSONALITY:
        roamer->personality = val;
        break;
    case ROAMER_DATA_SPECIES:
        roamer->species = val;
        break;
    case ROAMER_DATA_HP:
        roamer->hp = val;
        break;
    case ROAMER_DATA_LEVEL:
        roamer->level = val;
        break;
    case ROAMER_DATA_STATUS:
        roamer->status = val;
        break;
    case ROAMER_DATA_UNK8:
        roamer->unk_12 = val;
        break;
    default:
        GF_ASSERT(0);
        break;
    }
}

u8 *sub_0202DB04(ROAMER_SAVE *roamerSave) {
    return &roamerSave->unk_65;
}

BOOL sub_0202DB08(ROAMER_SAVE *roamerSave) {
    return roamerSave->unk_65 == 0;
}

void sub_0202DB18(ROAMER_SAVE *roamerSave, u8 a1) {
    GF_ASSERT(a1 <= 2);
    roamerSave->unk_67 = a1;
}

u8 sub_0202DB2C(ROAMER_SAVE *roamerSave) {
    return roamerSave->unk_67;
}
