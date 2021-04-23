#pragma once

#include "RE/BSHavok/hkpBroadPhaseHandlePair/hkpBroadPhaseHandlePair.h"


namespace RE
{
	class hkpTypedBroadPhaseHandle;


	class hkpTypedBroadPhaseHandlePair : public hkpBroadPhaseHandlePair
	{
	public:
		hkpTypedBroadPhaseHandle* GetElementA() const;
		hkpTypedBroadPhaseHandle* GetElementB() const;
		hkpTypedBroadPhaseHandle* GetOther(hkpTypedBroadPhaseHandle* a_elem) const;
	};
	static_assert(sizeof(hkpBroadPhaseHandlePair) == 0x10);
}