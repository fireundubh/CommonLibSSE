#include "RE/BGSDecalManager.h"


namespace RE
{
	BGSDecalManager* BGSDecalManager::GetSingleton()
	{
		REL::Offset<BGSDecalManager**> singleton(Offset::BGSDecalManager::Singleton);
		return *singleton;
	}
}