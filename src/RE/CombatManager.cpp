#include "RE/CombatManager.h"


namespace RE
{
	CombatManager* CombatManager::GetSingleton()
	{
		REL::Offset<CombatManager**> singleton(Offset::CombatManager::Singleton);
		return *singleton;
	}
}
