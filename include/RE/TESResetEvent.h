#pragma once

#include "RE/FormTypes.h"  // TESObjectCELL

namespace RE
{
	struct TESResetEvent
	{
		TESObjectREFR* ref;
	};
	STATIC_ASSERT(sizeof(TESResetEvent) == 0x8);
}
