#include "RE/CombatManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	CombatManager* CombatManager::GetSingleton()
	{
		REL::Offset<CombatManager**> singleton(Offset::CombatManager::Singleton);
		return *singleton;
	}

}
