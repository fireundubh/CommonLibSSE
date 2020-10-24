#include "RE/Events/BGSStoryEvent/SoulsTrapped.h"


namespace RE
{
	BSTEventSource<SoulsTrapped::Event>* SoulsTrapped::GetEventSource()
	{
		using func_t = decltype(&SoulsTrapped::GetEventSource);
		REL::Relocation<func_t> func{ REL::ID(37916) };
		return func();
	}
}
