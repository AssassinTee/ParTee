#ifndef GAME_SERVER_MINIGAME_DEATHMATCH_H
#define GAME_SERVER_MINIGAME_DEATHMATCH_H
#include <game/server/gamecontroller.h>
#include "minigame.h"

class CDeathMatch : public IMiniGame
{
public:
	CDeathMatch(class CGameContext *pGameServer) : IMiniGame(pGameServer){}
	bool IsTeam() override {return false;}
	bool GameEnd() override;
	void DoScoring() override;
	//virtual void Tune(){};
};

#endif

