#ifndef GAME_SERVER_MINIGAME_MINIGAME_H
#define GAME_SERVER_MINIGAME_MINIGAME_H
#include <game/server/gamecontroller.h>

class IMiniGame
{
public:
	IMiniGame(class CGameContext *pGameServer){m_pGameServer = pGameServer;}
	virtual bool IsTeam()=0;
	virtual bool GameEnd()=0;
	virtual void DoScoring()=0;
	//virtual void Tune(){};
protected:
    class CGameContext* m_pGameServer;
};

#endif

