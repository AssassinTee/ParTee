/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "partee.h"

CGameControllerPartee::CGameControllerPartee(CGameContext *pGameServer)
: IGameController(pGameServer)
{
	m_pGameType = "Partee";
	m_pMiniGame = MiniGame::CreateMiniGame(pGameServer);//new CDeathMatch(pGameServer);
}

CGameControllerPartee::~CGameControllerPartee()
{
	if(m_pMiniGame != nullptr)
		delete m_pMiniGame;
}
