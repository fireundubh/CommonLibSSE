#pragma once

#include "RE/BSHavok/hkpBroadPhaseHandle/hkpBroadPhaseHandle.h"


namespace RE
{
	class hkpBroadPhaseHandlePair
	{
	public:
		hkpBroadPhaseHandle* a;	 // 0
		hkpBroadPhaseHandle* b;	 // 8
	};
	static_assert(sizeof(hkpBroadPhaseHandlePair) == 0x10);
}
