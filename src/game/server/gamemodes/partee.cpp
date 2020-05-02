/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include "partee.h"


CGameControllerPartee::CGameControllerPartee(CGameContext *pGameServer)
: IGameController(pGameServer)
{
	m_pGameType = "Partee";
}
