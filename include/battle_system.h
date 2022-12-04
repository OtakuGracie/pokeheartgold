#ifndef POKEHEARTGOLD_BATTLE_SYSTEM_H
#define POKEHEARTGOLD_BATTLE_SYSTEM_H

#include "battle.h"
#include "player_data.h"
#include "sav_chatot.h"

u32 BattleSys_GetBattleType(BattleSystem *bsys);
u32 BattleSys_GetFieldSide(BattleSystem *bsys, int battlerId);
int BattleSys_GetMaxBattlers(BattleSystem *bsys);
int BattleSys_Random(BattleSystem *bsys);
PLAYERPROFILE *BattleSys_GetPlayerProfile(BattleSystem *bsys, int a1);
PARTY *BattleSys_GetParty(BattleSystem *bsys, int battlerId);
int BattleSys_GetPartySize(BattleSystem *bsys, int battlerId);
POKEMON *BattleSystem_GetPartyMon(BattleSystem *bsys, int battlerId, int index);
int BattleSys_GetTerrainId(BattleSystem *bsys);
int ov12_0223ABB8(BattleSystem *bsys, int battlerId, int a2);
void BattleSys_RecoverStatus(BattleSystem *bsys, int battlerIdA, int battlerIdB, int a2, int itemWork);
void ov12_0223BDDC(BattleSystem *bsys, int battlerId, u8 a2);
void PokedexSetBattlerSeen(BattleSystem *bsys, int battlerId);
OpponentData *BattleSys_GetOpponentDataByBattlerId(BattleSystem *bsys, int battlerId);
SOUND_CHATOT *BattleSys_GetChatotVoice(BattleSystem *bsys, int battlerId);
int BattleSys_GetChatotVoiceParam(BattleSystem *bsys, int battlerId);
int BattleSys_GetBattlerIdPartner(BattleSystem *bsys, int battlerId);

#endif