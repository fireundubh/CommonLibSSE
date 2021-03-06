#pragma once

#include "RE/FormComponents/TESForm/TESForm.h"
#include "RE/NetImmerse/NiPoint3.h"


namespace RE
{
	struct CombatLocation
	{
		NiPoint3 pos;				// 00
		TESForm* cellOrWorldSpace;	// 0C
	};
	static_assert(sizeof(CombatLocation) == 0x18);
}
