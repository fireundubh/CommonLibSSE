#include "RE/Misc/FixedStrings.h"


namespace RE
{
	FixedStrings* FixedStrings::GetSingleton()
	{
		using func_t = decltype(&FixedStrings::GetSingleton);
		REL::Relocation<func_t> func{ REL::ID(11308) };
		return func();
	}
}