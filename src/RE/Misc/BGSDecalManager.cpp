#include "RE/Misc/BGSDecalManager.h"


namespace RE
{
	BGSDecalManager* BGSDecalManager::GetSingleton()
	{
		REL::Relocation<BGSDecalManager**> singleton{ Offset::BGSDecalManager::Singleton };
		return *singleton;
	}
}