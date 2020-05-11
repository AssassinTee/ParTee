/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_GAMEMODES_PARTEE_H
#define GAME_SERVER_GAMEMODES_PARTEE_H
#include <game/server/gamecontroller.h>
#include <game/server/minigames/minigame.h>
#include <game/server/minigames/deathmatch.h>

template<typename T>
IMiniGame* CreateGame(class CGameContext* pGameServer) {return new T(pGameServer);}
		
typedef IMiniGame* (*RandomMiniGame)(class CGameContext* pGameServer);

class CGameControllerPartee : public IGameController
{
public:
	CGameControllerPartee(class CGameContext *pGameServer);
	~CGameControllerPartee();
	virtual IMiniGame* GetMiniGame() override {return m_pMiniGame;}
	void SetMiniGame(IMiniGame* pMiniGame){m_pMiniGame = pMiniGame;}

private:
	
    IMiniGame* m_pMiniGame;
};

namespace MiniGame
{
	const RandomMiniGame MiniGames[] =
	{
		&CreateGame<CDeathMatch>
	};
	const size_t numGames = 1;
	inline IMiniGame* CreateMiniGame(class CGameContext* pGameServer)
	{
		return MiniGames[random_int()%numGames](pGameServer);
	}
}

#endif
