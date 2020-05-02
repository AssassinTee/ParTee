/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_GAMEMODES_PARTEE_H
#define GAME_SERVER_GAMEMODES_PARTEE_H
#include <game/server/gamecontroller.h>
#include <game/server/minigames/minigame.h>

class CGameControllerPartee : public IGameController
{
public:
	CGameControllerPartee(class CGameContext *pGameServer);
	IMiniGame* GetMiniGame(){return m_pMiniGame;}
	void SetMiniGame(IMiniGame* pMiniGame){m_pMiniGame = pMiniGame;}

private:
    IMiniGame* m_pMiniGame;
};

#endif
