#include "RE/Misc/VATSManager.h"


namespace RE
{
	VATSManager* VATSManager::GetSingleton()
	{
		REL::Relocation<VATSManager**> singleton{ REL::ID(514725) };
		return *singleton;
	}
	
	
	void VATSManager::SetGameTimeMult(float a_npcMult, float a_pcMult)
	{
		using func_t = decltype(&VATSManager::SetGameTimeMult);
		REL::Relocation<func_t> func{ REL::ID(43103) };
		return func(this, a_npcMult, a_pcMult);
	}
}