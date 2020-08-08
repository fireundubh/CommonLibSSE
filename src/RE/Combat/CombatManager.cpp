#include "RE/Combat/CombatManager.h"


namespace RE
{
	CombatManager* CombatManager::GetSingleton()
	{
		REL::Relocation<CombatManager**> singleton{ Offset::CombatManager::Singleton };
		return *singleton;
	}
}
