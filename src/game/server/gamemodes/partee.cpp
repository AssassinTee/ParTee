/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "partee.h"

CGameControllerPartee::CGameControllerPartee(CGameContext *pGameServer)
: IGameController(pGameServer)
{
	m_pGameType = "Partee";
	m_pMiniGame = MiniGame::CreateMiniGame(pGameServer, random_int()%MiniGame::numGames);//new CDeathMatch(pGameServer);
	m_MiniGameID = 0;
	m_PrevMiniGameID = 0;
	m_pGameServer = pGameServer;
}

CGameControllerPartee::~CGameControllerPartee()
{
	if(m_pMiniGame != nullptr)
		delete m_pMiniGame;
}

void CGameControllerPartee::ChooseMiniGame()
{
	int MiniGame = m_MiniGameID;
	
	//Give it 100 tries, should be enough
	for(int i = 0; i < 100; ++i)
	{
		MiniGame = random_int()%MiniGame::numGames;
		
		//Not the Last and the Last Last Game
		if(MiniGame != m_MiniGameID && MiniGame != m_PrevMiniGameID)
			break;
	}
	
	m_PrevMiniGameID = m_MiniGameID;
	m_MiniGameID = MiniGame;
	
	if(m_pMiniGame != nullptr)
		delete m_pMiniGame;
	m_pMiniGame = MiniGame::CreateMiniGame(m_pGameServer, m_MiniGameID);
}
