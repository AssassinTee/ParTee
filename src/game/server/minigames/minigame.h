#ifndef GAME_SERVER_MINIGAME_MINIGAME_H
#define GAME_SERVER_MINIGAME_MINIGAME_H
#include <game/server/gamecontroller.h>
#include <game/server/entities/character.h>

class IMiniGame
{
public:
	IMiniGame(class CGameContext *pGameServer){m_pGameServer = pGameServer;}
	virtual ~IMiniGame(){}
	virtual bool IsTeam()=0;
	virtual bool GameEnd()=0;
	virtual void DoScoring()=0;
	
	//Character interface
	virtual void Die(CCharacter* pCharacter, int Killer, int Weapon){pCharacter->Die(Killer, Weapon);}
	virtual void OnLeftClick(CCharacter* pCharacter){}
	virtual void OnHook(CCharacter* pCharacter){}
	virtual void OnCrosshair(CCharacter* pCharacter, int TargetX, int TargetY){}
	virtual void OnHoldLeftClick(CCharacter* pCharacter){}
	virtual void OnFireWeapon(CCharacter* pCharacter, int WeaponID, int FullAuto){}
	virtual void OnWeaponSwitch(CCharacter* pCharacter, int PrevWeaponID, int NextWeaponID){}
	virtual void OnMovement(CCharacter* pCharacter, int Direction){}
	virtual void OnJump(CCharacter* pCharacter){}
	virtual void OnCharacterTick(CCharacter* pCharacter){}
	virtual void OnPlayerHook(CCharacter* pCharacter, int HookedPlayerID){}
	
	virtual int GetMaxHealth(){return 10;}
	virtual int GetMaxArmor(){return 10;}
	
	//virtual void Tune(){};
protected:
    class CGameContext* m_pGameServer;
};

#endif

