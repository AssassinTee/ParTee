#ifndef GAME_SERVER_MINIGAME_SIMPLECATCH_H
#define GAME_SERVER_MINIGAME_SIMPLECATCH_H
#include <game/server/gamecontroller.h>
#include "minigame.h"

class CSimpleCatch : public IMiniGame
{
public:
	CSimpleCatch(class CGameContext *pGameServer) : IMiniGame(pGameServer){}
	bool IsTeam() override {return false;}
	bool GameEnd() override;
	void DoScoring() override;
	const char* GetName() override {return "HookCatch";}
	//virtual void Tune(){};
};

#endif

