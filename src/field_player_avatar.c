#include "field_player_avatar.h"
#include "assert.h"
#include "field_map_object.h"
#include "heap.h"
#include "overlay_00_thumb.h"
#include "overlay_01.h"
#include "player_data.h"
#include "unk_02034354.h"
#include "unk_02035900.h"
#include "unk_0205FD20.h"
#include "constants/global.fieldmap.h"
#include "constants/sprites.h"

int sub_0205C268(u32 unkA) {
    if (unkA < 100) {
        return 255;
    }
    return ov00_021E6EBC();
}

u8 sub_0205C278(void) {
    PLAYERPROFILE* profile = sub_02034818(sub_0203769C() ^ 1);
    if (!profile) {
        GF_ASSERT(FALSE);
    }
    return PlayerProfile_GetVersion(profile);
}

u8 sub_0205C298(SAVEDATA* savedata) {
    u8 ver = PlayerProfile_GetVersion(Sav2_PlayerData_GetProfileAddr(savedata));
    if (ver == 0) {
        return 1;
    }
    if (sub_0205C278() == 0) {
        return 1;
    }
    return 0;
}

u8 sub_0205C2C0(u32 unkA) {
    switch (unkA) {
    case 0:
        return 95;
    case 1:
        return 97;
    case 2:
        return 99;
    case 3:
        return 143;
    }
}

u8 sub_0205C2E8(u32 unkA) {
    switch (unkA) {
    case 0:
        return 94;
    case 1:
        return 96;
    case 2:
        return 98;
    case 3:
        return 142;
    }
}

u8 sub_0205C310(u32 unkA) {
    u8 ret;
    switch (unkA) {
    case 0:
        ret = 1;
        break;
    case 1:
        ret = 3;
        break;
    case 2:
        ret = 5;
        break;
    case 3:
        ret = 7;
        break;
    case 4:
        ret = 9;
        break;
    case 6:
        ret = 113;
        break;
    case 5:
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return ret;
}

u8 sub_0205C350(u32 unkA) {
    u8 ret;
    switch (unkA) {
    case 0:
        ret = 0;
        break;
    case 1:
        ret = 2;
        break;
    case 2:
        ret = 4;
        break;
    case 3:
        ret = 6;
        break;
    case 4:
        ret = 8;
        break;
    case 6:
        ret = 112;
        break;
    default:
    case 5:
        GF_ASSERT(FALSE);
        break;
    }
    return ret;
}

FIELD_PLAYER_AVATAR* sub_0205C390(MapObjectMan *man, int x, int y, int direction, int state, int gender, int a6, struct FlypointsPlayerSub *a7) {
    FIELD_PLAYER_AVATAR* avatar = sub_0205C4E0();
    sub_0205C500(avatar, state, gender, a7);
    int sprite;
    if (a6 == 2) {
        sprite = PlayerAvatar_GetSpriteByStateAndGender(state, gender);
    }
    else if (a6 == 0) {
        if (gender == 0) {
            sprite = SPRITE_PL_BOY01C;
        }
        else {
            sprite = SPRITE_PL_GIRL01C;
        }
    }
    else if (a6 == 1) {
        if (gender == 0) {
            sprite = SPRITE_HERO_2;
        }
        else {
            sprite = SPRITE_HEROINE_2;
        }
    }
    else {
        GF_ASSERT(FALSE);
        sprite = PlayerAvatar_GetSpriteByStateAndGender(state, gender);
    }
    CreatePlayerAvatarMapObject(avatar, man, sprite, direction, x, y);
    return avatar;
}

FIELD_PLAYER_AVATAR* sub_0205C408(MapObjectMan* man, FIELD_PLAYER_AVATAR_SUB* avatar_sub, int gender) {
    FIELD_PLAYER_AVATAR* avatar = sub_0205C4E0();
    int state = sub_0205C7EC(avatar_sub);
    sub_0205C500(avatar, state, gender, avatar_sub);
    LocalMapObject* mapObj = sub_0205C640(man);
    MapObject_SetGfxID(mapObj, PlayerAvatar_GetSpriteByStateAndGender(state, gender));
    MapObject_SetFlagsBits(mapObj, MAPOBJECTFLAG_UNK13 | MAPOBJECTFLAG_UNK10);
    MapObject_ClearFlagsBits(mapObj, MAPOBJECTFLAG_UNK8 | MAPOBJECTFLAG_UNK7);
    MapObject_SetFlag29(mapObj, TRUE);
    sub_0205C6D8(avatar, mapObj);
    return avatar;
}

void sub_0205C46C(FIELD_PLAYER_AVATAR* avatar) {
    LocalMapObject* mapObj = PlayerAvatar_GetMapObject(avatar);
    if (!mapObj) {
        GF_ASSERT(FALSE);
    }
    MapObject_GetManager(mapObj);
    ov01_022008B4(avatar);
    if (PlayerAvatar_GetState(avatar) == PLAYER_STATE_SURFING) {
        int x = GetPlayerXCoord(avatar);
        int y = GetPlayerYCoord(avatar);
        int dir = PlayerAvatar_GetFacingDirection(avatar);
        sub_0205C78C(avatar, ov01_021FE7DC(mapObj, x, y, dir, 1));
    }
}

void PlayerAvatar_FreeToHeap(FIELD_PLAYER_AVATAR* avatar) {
    FreeToHeap(avatar);
}

void PlayerAvatar_DeleteFromMap(FIELD_PLAYER_AVATAR* avatar) {
    MapObject_Remove(PlayerAvatar_GetMapObject(avatar));
    PlayerAvatar_FreeToHeap(avatar);
}

FIELD_PLAYER_AVATAR* sub_0205C4E0() {
    FIELD_PLAYER_AVATAR* avatar = AllocFromHeap(11, sizeof(FIELD_PLAYER_AVATAR));
    if (!avatar) {
        GF_ASSERT(FALSE);
    }
    memset(avatar, 0, sizeof(FIELD_PLAYER_AVATAR));
    return avatar;
}

void sub_0205C500(FIELD_PLAYER_AVATAR* avatar, int state, u32 gender, FIELD_PLAYER_AVATAR_SUB* avatar_sub) {
    sub_0205C794(avatar, avatar_sub);
    sub_0205C6C8(avatar, 0);
    sub_0205C6D0(avatar, 0);
    PlayerAvatar_SetState(avatar, state);
    PlayerAvatar_SetGender(avatar, gender);
    PlayerAvatar_SetTransitionFlags(avatar, 0);
    sub_0205C74C(avatar);
    sub_0205C768(avatar, -1);
    sub_0205C770(avatar, -1);
    sub_0205C79C(avatar, 255);
    sub_0205CA4C(avatar, TRUE);
}

void CreatePlayerAvatarMapObject(FIELD_PLAYER_AVATAR* avatar, MapObjectMan* man, u32 sprite, u32 direction, u32 x, u32 y) {
    LocalMapObject* mapObj = CreateSpecialFieldObject(man, x, y, direction, sprite, 1, 1);
    if (!mapObj) {
        GF_ASSERT(FALSE);
    }
    MapObject_SetID(mapObj, 255);
    MapObject_SetType(mapObj, 0);
    MapObject_SetFlagID(mapObj, 0);
    MapObject_SetScript(mapObj, 0);
    MapObject_SetParam(mapObj, 0, 0);
    MapObject_SetParam(mapObj, 0, 1);
    MapObject_SetParam(mapObj, 0, 2);
    MapObject_SetXRange(mapObj, -1);
    MapObject_SetYRange(mapObj, -1);
    MapObject_SetFlagsBits(mapObj, MAPOBJECTFLAG_UNK13 | MAPOBJECTFLAG_UNK10);
    MapObject_ClearFlagsBits(mapObj, MAPOBJECTFLAG_UNK8 | MAPOBJECTFLAG_UNK7);
    MapObject_SetFlag29(mapObj, TRUE);
    sub_0205C6D8(avatar, mapObj);
}

LocalMapObject* sub_0205C600(MapObjectMan* man) {
    int y = 0;
    LocalMapObject* mapObj = 0;
    while (sub_0205EEF4(man, &mapObj, &y, MAPOBJECTFLAG_ACTIVE)) {
        if (MapObject_GetMovement(mapObj) == TRUE) {
            break;
        }
    }
    return mapObj;
}

LocalMapObject* sub_0205C640(MapObjectMan* man) {
    LocalMapObject* mapObj = sub_0205C600(man);
    if (!mapObj) {
        GF_ASSERT(FALSE);
    }
    return mapObj;
}

int PlayerAvatar_GetFacingDirection(FIELD_PLAYER_AVATAR* avatar) {
    return MapObject_GetFacingDirection(PlayerAvatar_GetMapObject(avatar));
}

void PlayerAvatar_SetFacingDirection(FIELD_PLAYER_AVATAR* avatar, int direction) {
    MapObject_SetFacingDirection(PlayerAvatar_GetMapObject(avatar), direction);
}

u32 PlayerAvatar_GetNextFacing(FIELD_PLAYER_AVATAR* avatar) {
    return MapObject_GetNextFacing(PlayerAvatar_GetMapObject(avatar));
}

int GetPlayerXCoord(FIELD_PLAYER_AVATAR* avatar) {
    return MapObject_GetCurrentX(PlayerAvatar_GetMapObject(avatar));
}

int GetPlayerYCoord(FIELD_PLAYER_AVATAR* avatar) {
    return MapObject_GetCurrentY(PlayerAvatar_GetMapObject(avatar));
}

int GetPlayerLastXCoord(FIELD_PLAYER_AVATAR* avatar) {
    return MapObject_GetPrevX(PlayerAvatar_GetMapObject(avatar));
}

int GetPlayerLastYCoord(FIELD_PLAYER_AVATAR* avatar) {
    return MapObject_GetPrevY(PlayerAvatar_GetMapObject(avatar));
}

void PlayerAvatar_GetPositionVec(FIELD_PLAYER_AVATAR* avatar, VecFx32* vec) {
    MapObject_GetPositionVec(PlayerAvatar_GetMapObject(avatar), vec);
}

VecFx32* PlayerAvatar_GetPositionVecConst(FIELD_PLAYER_AVATAR* avatar) {
    return MapObject_GetPositionVecPtr(PlayerAvatar_GetMapObjectConst(avatar));
}

void sub_0205C6C8(FIELD_PLAYER_AVATAR* avatar, u32 unkA) {
    avatar->unk10 = unkA;
}

u32 sub_0205C6CC(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->unk10;
}

void sub_0205C6D0(FIELD_PLAYER_AVATAR* avatar, u32 unkA) {
    avatar->unk14 = unkA;
}

u32 sub_0205C6D4(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->unk14;
}

void sub_0205C6D8(FIELD_PLAYER_AVATAR* avatar, LocalMapObject* obj) {
    avatar->mapObject = obj;
}

LocalMapObject* PlayerAvatar_GetMapObject(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->mapObject;
}

LocalMapObject* PlayerAvatar_GetMapObjectConst(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->mapObject;
}

void PlayerAvatar_SetState(FIELD_PLAYER_AVATAR* avatar, int state) {
    if(state >= PLAYER_STATE_UNK_SP) {
        GF_ASSERT(FALSE);
    }
    avatar->state = state;
    sub_0205C800(avatar, state);
}

int PlayerAvatar_GetState(FIELD_PLAYER_AVATAR* avatar) {
    if(!avatar) {
        GF_ASSERT(FALSE);
    }
    return avatar->state;
}

void PlayerAvatar_OrrTransitionFlags(FIELD_PLAYER_AVATAR* avatar, u32 flag) {
    avatar->transFlag = avatar->transFlag | flag;
}

void PlayerAvatar_SetTransitionFlags(FIELD_PLAYER_AVATAR* avatar, u32 flag) {
    avatar->transFlag = flag;
}

u32 PlayerAvatar_GetTransitionFlags(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->transFlag;
}

void PlayerAvatar_SetGender(FIELD_PLAYER_AVATAR* avatar, u32 gender) {
    avatar->gender = gender;
}

int PlayerAvatar_GetGender(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->gender;
}

void sub_0205C728(FIELD_PLAYER_AVATAR* avatar, u32 unkA) {
    avatar->unk0 = avatar->unk0 | unkA;
}

void sub_0205C730(FIELD_PLAYER_AVATAR* avatar, u32 unkA) {
    avatar->unk0 = avatar->unk0 & ~unkA;
}

u32 sub_0205C73C(FIELD_PLAYER_AVATAR* avatar, u32 unkA) {
    return avatar->unk0 & unkA;
}

u32 sub_0205C744(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->unk24;
}

void sub_0205C748(FIELD_PLAYER_AVATAR* avatar, u32 unkA) {
    avatar->unk24 = unkA;
}

void sub_0205C74C(FIELD_PLAYER_AVATAR* avatar) {
    avatar->unk24 = 0;
    sub_0205CA78(avatar, FALSE);
}

int sub_0205C758(FIELD_PLAYER_AVATAR* avatar, int unkB, int unkC) {
    int var = avatar->unk24 + unkB;
    avatar->unk24 = var;
    if (var > unkC) {
        avatar->unk24 = unkC;
    }
    return avatar->unk24;
}

void sub_0205C768(FIELD_PLAYER_AVATAR* avatar, int unkA) {
    avatar->unk28 = unkA;
}

int sub_0205C76C(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->unk28;
}

void sub_0205C770(FIELD_PLAYER_AVATAR* avatar, int unkA) {
    avatar->unk2c = unkA;
}

int sub_0205C774(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->unk2c;
}

void sub_0205C778(FIELD_PLAYER_AVATAR* avatar, int unkB, int unkC) {
    sub_0205C768(avatar, unkB);
    sub_0205C770(avatar, unkC);
}

void sub_0205C78C(FIELD_PLAYER_AVATAR* avatar, u32 unkA) {
    avatar->unk34 = unkA;
}

u32 sub_0205C790(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->unk34;
}

void sub_0205C794(FIELD_PLAYER_AVATAR* avatar, FIELD_PLAYER_AVATAR_SUB* unkA) {
    avatar->unk38 = unkA;
}

FIELD_PLAYER_AVATAR_SUB* sub_0205C798(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->unk38;
}

void sub_0205C79C(FIELD_PLAYER_AVATAR* avatar, u32 unkA) {
    avatar->unk8 = unkA;
}

u32 sub_0205C7A0(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->unk8;
}

u32 sub_0205C7A4(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->unkc;
}

void sub_0205C7A8(FIELD_PLAYER_AVATAR* avatar) {
    avatar->unkc = (avatar->unkc + 1) & TRUE;
}

void sub_0205C7B4(FIELD_PLAYER_AVATAR* avatar) {
    avatar->unkc = 0;
}

void FlypointsPlayerSub_init(struct FlypointsPlayerSub* fpsub) {
    fpsub->hasRunningShoes = 0;
    fpsub->unk2 = 0;
    fpsub->unk4 = 0;
}

BOOL FlypointsPlayerSub_CheckRunningShoes(struct FlypointsPlayerSub* fpsub) {
    if (fpsub) {
        if (fpsub->hasRunningShoes == TRUE) {
            return TRUE;
        }
    }
    return FALSE;
}

void FlypointsPlayerSub_SetRunningShoesFlag(struct FlypointsPlayerSub* fpsub, BOOL unkB) {
    if (unkB == TRUE) {
        fpsub->hasRunningShoes = TRUE;
    }
    else {
        fpsub->hasRunningShoes = FALSE;
    }
}

int sub_0205C7EC(FIELD_PLAYER_AVATAR_SUB* avatar) {
    if (!avatar) {
        return 0;
    }
    return avatar->unk4;
}

void sub_0205C7F8(FIELD_PLAYER_AVATAR_SUB* unkPtr, int state) {
    if (!unkPtr) {
        return;
    }
    unkPtr->unk4 = state;
}

void sub_0205C800(FIELD_PLAYER_AVATAR* avatar, int state) {
    sub_0205C7F8(sub_0205C798(avatar), state);
}

void sub_0205C810(FIELD_PLAYER_AVATAR* avatar, u32 unkA, u32 unkB) {
    sub_0205FBC0(PlayerAvatar_GetMapObject(avatar), unkA, unkB);
    sub_0205C6C8(avatar, 0);
    sub_0205C6D0(avatar, 0);
}

void sub_0205C838(FIELD_PLAYER_AVATAR* avatar, int unkA) {
    LocalMapObject* mapObj = PlayerAvatar_GetMapObject(avatar);
    VecFx32 vec;
    MapObject_GetPositionVec(mapObj, &vec);
    vec.y = unkA;
    MapObject_SetPositionVec(mapObj, &vec);
}

void PlayerAvatar_ToggleAutomaticHeightUpdating(FIELD_PLAYER_AVATAR* avatar, u8 state) {
    LocalMapObject* mapObj = PlayerAvatar_GetMapObject(avatar);
    if (state == TRUE) {
        MapObject_SetFlag23(mapObj, FALSE);
    }
    else {
        MapObject_SetFlag23(mapObj, TRUE);
    }
}

void PlayerAvatar_ToggleAutomaticHeightUpdating_NowApply(FIELD_PLAYER_AVATAR* avatar, BOOL state) {
    LocalMapObject* mapObj = PlayerAvatar_GetMapObject(avatar);
    if (state == TRUE) {
        MapObject_SetFlag23(mapObj, FALSE);
        sub_02061070(mapObj);
    }
    else {
        MapObject_SetFlag23(mapObj, TRUE);
    }
}

u32 PlayerAvatar_GetSpriteByStateAndGender(u32 state, int gender) {
    if(!gender) {
        switch (state) {
        case PLAYER_STATE_WALKING:
            return SPRITE_HERO;
        case PLAYER_STATE_CYCLING:
            return SPRITE_CYCLEHERO;
        case PLAYER_STATE_SURFING:
            return SPRITE_SWIMHERO;
        case PLAYER_STATE_UNK_SP:
            return SPRITE_SPHERO;
        case PLAYER_STATE_UNK_WATER:
            return SPRITE_WATERHERO;
        case PLAYER_STATE_FISHING:
            return SPRITE_FISHINGHERO;
        case PLAYER_STATE_UNK_POKE:
            return SPRITE_POKEHERO;
        case PLAYER_STATE_SAVING:
            return SPRITE_SAVEHERO;
        case PLAYER_STATE_HEAL:
            return SPRITE_BANZAIHERO;
        case PLAYER_STATE_LADDER:
            return SPRITE_LADDERHERO;
        case PLAYER_STATE_ROCKET:
            return SPRITE_RHERO;
        case PLAYER_STATE_ROCKET_HEAL:
            return SPRITE_RBANZAIHERO;
        case PLAYER_STATE_POKEATHLON:
            return SPRITE_PKTHHERO;
        case PLAYER_STATE_APRICORN_SHAKE:
            return SPRITE_SHAKEHERO;
        case PLAYER_STATE_ROCKET_SAVING:
            return SPRITE_SAVERHERO;
        }
    }
    else {
        switch (state) {
        case PLAYER_STATE_WALKING:
            return SPRITE_HEROINE;
        case PLAYER_STATE_CYCLING:
            return SPRITE_CYCLEHEROINE;
        case PLAYER_STATE_SURFING:
            return SPRITE_SWIMHEROINE;
        case PLAYER_STATE_UNK_SP:
            return SPRITE_SPHEROINE;
        case PLAYER_STATE_UNK_WATER:
            return SPRITE_WATERHEROINE;
        case PLAYER_STATE_FISHING:
            return SPRITE_FISH_HEROINE;
        case PLAYER_STATE_UNK_POKE:
            return SPRITE_POKEHEROINE;
        case PLAYER_STATE_SAVING:
            return SPRITE_SAVEHEROINE;
        case PLAYER_STATE_HEAL:
            return SPRITE_BANZAIHEROINE;
        case PLAYER_STATE_LADDER:
            return SPRITE_LADDERHEROINE;
        case PLAYER_STATE_ROCKET:
            return SPRITE_RHEROINE;
        case PLAYER_STATE_ROCKET_HEAL:
            return SPRITE_RBANZAIINE;
        case PLAYER_STATE_POKEATHLON:
            return SPRITE_PKTHHEROINE;
        case PLAYER_STATE_APRICORN_SHAKE:
            return SPRITE_SHAKEHEROINE;
        case PLAYER_STATE_ROCKET_SAVING:
            return SPRITE_SAVERHEROINE;
        }
    }
    GF_ASSERT(FALSE);
    return 0;
}

u32 PlayerAvatar_GetTransitionBits(u32 unkA) {
    switch (unkA) {
    case PLAYER_STATE_WALKING:
        return PLAYER_TRANSITION_WALKING;
    case PLAYER_STATE_CYCLING:
        return PLAYER_TRANSITION_CYCLING;
    case PLAYER_STATE_SURFING:
        return PLAYER_TRANSITION_SURFING;
    case PLAYER_STATE_UNK_WATER:
        return PLAYER_TRANSITION_x0010;
    case PLAYER_STATE_FISHING:
        return PLAYER_TRANSITION_x0020;
    case PLAYER_STATE_UNK_POKE:
        return PLAYER_TRANSITION_x0040;
    case PLAYER_STATE_SAVING:
        return PLAYER_TRANSITION_x0080;
    case PLAYER_STATE_HEAL:
        return PLAYER_TRANSITION_HEAL;
    case PLAYER_STATE_LADDER:
        return PLAYER_TRANSITION_x0200;
    case PLAYER_STATE_ROCKET:
        return PLAYER_TRANSITION_ROCKET;
    case PLAYER_STATE_ROCKET_HEAL:
        return PLAYER_TRANSITION_ROCKET_HEAL;
    case PLAYER_STATE_POKEATHLON:
        return PLAYER_TRANSITION_POKEATHLON;
    case PLAYER_STATE_APRICORN_SHAKE:
        return PLAYER_TRANSITION_x2000;
    case PLAYER_STATE_ROCKET_SAVING:
        return PLAYER_TRANSITION_x4000;
    case PLAYER_STATE_UNK_SP:
    default:
        GF_ASSERT(FALSE);
        return PLAYER_TRANSITION_WALKING;
    }
}

FIELD_PLAYER_AVATAR* FieldSys_GetPlayerAvatar(FieldSystem* fsys) {
    return fsys->playerAvatar;
}

void sub_0205CA20(FIELD_PLAYER_AVATAR* avatar, BOOL unkA) {
    if (unkA == TRUE) {
        sub_0205C728(avatar, 1);
    }
    else {
        sub_0205C730(avatar, 1);
    }
}

BOOL sub_0205CA38(FIELD_PLAYER_AVATAR* avatar) {
    if (sub_0205C73C(avatar, 1)) {
        return TRUE;
    }
    return FALSE;
}

void sub_0205CA4C(FIELD_PLAYER_AVATAR* avatar, BOOL unkA) {
    if (unkA == TRUE) {
        sub_0205C728(avatar, 2);
    }
    else {
        sub_0205C730(avatar, 2);
    }
}

BOOL sub_0205CA64(FIELD_PLAYER_AVATAR* avatar) {
    if (sub_0205C73C(avatar, 2)) {
        return TRUE;
    }
    return FALSE;
}

void sub_0205CA78(FIELD_PLAYER_AVATAR* avatar, BOOL unkB) {
    if (unkB == TRUE) {
        sub_0205C728(avatar, 4);
    }
    else {
        sub_0205C730(avatar, 4);
    }
}

BOOL sub_0205CA90(FIELD_PLAYER_AVATAR* avatar) {
    if (sub_0205C73C(avatar, 4)) {
        return TRUE;
    }
    return FALSE;
}

void sub_0205CAA4(FIELD_PLAYER_AVATAR* avatar, u8 unkA) {
    if (unkA == 1) {
        sub_0205C728(avatar, 8);
    }
    else { 
        sub_0205C730(avatar, 8);
    }
}

BOOL sub_0205CABC(FIELD_PLAYER_AVATAR* avatar) {
    if (sub_0205C73C(avatar, 8)) {
        return TRUE;
    }
    return FALSE;
}

void sub_0205CAD0(FIELD_PLAYER_AVATAR* avatar, BOOL unkA) {
    if (unkA == TRUE) {
        sub_0205C728(avatar, 32);
    }
    else {
        sub_0205C730(avatar, 32);
    }
}

void sub_0205CAE8(FIELD_PLAYER_AVATAR* avatar) {
    sub_0205C728(avatar, 64);
}

void sub_0205CAF4(FIELD_PLAYER_AVATAR* avatar) {
    sub_0205C730(avatar, 64);
}

BOOL sub_0205CB00(FIELD_PLAYER_AVATAR* avatar) {
    if (sub_0205C73C(avatar, 64)) {
        return TRUE;
    }
    return FALSE;
}

void sub_0205CB14(FIELD_PLAYER_AVATAR* avatar, BOOL unkA) {
    if (unkA == TRUE) {
        sub_0205C728(avatar, 128);
    }
    else {
        sub_0205C730(avatar, 128);
    }
}

u32 sub_0205CB2C(FIELD_PLAYER_AVATAR* avatar) {
    return sub_0205C73C(avatar, 128);
}

u16 sub_0205CB38(FIELD_PLAYER_AVATAR* avatar) {
    return avatar->unk38->unk2;
}

void sub_0205CB40(FIELD_PLAYER_AVATAR* avatar, u16 unkA) {
    avatar->unk38->unk2 = unkA;
}
