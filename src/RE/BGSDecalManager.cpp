#include "RE/BGSDecalManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BGSDecalManager* BGSDecalManager::GetSingleton()
	{
		REL::Offset<BGSDecalManager**> singleton(Offset::BGSDecalManager::Singleton);
		return *singleton;
	}
}