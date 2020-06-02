#pragma once

#include "RE/NiPoint3.h"
#include "RE/TESForm.h"


namespace RE
{
	struct CombatLocation
	{
		NiPoint3 pos;				// 00
		TESForm* cellOrWorldSpace;	// 0C
	};
	STATIC_ASSERT(sizeof(CombatLocation) == 0x18);
}
