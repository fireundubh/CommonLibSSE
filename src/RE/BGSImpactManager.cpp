#include "RE/BGSImpactManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BGSImpactManager* BGSImpactManager::GetSingleton()
	{
		REL::Offset<BGSImpactManager**> singleton(Offset::BGSImpactManager::Singleton);
		return *singleton;
	}
}