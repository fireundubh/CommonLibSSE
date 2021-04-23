#include "RE/BSHavok/hkpBroadPhaseHandlePair/hkpTypedBroadPhaseHandlePair.h"

#include "RE/BSHavok/hkpBroadPhaseHandle/hkpTypedBroadPhaseHandle.h"


namespace RE
{
	hkpTypedBroadPhaseHandle* hkpTypedBroadPhaseHandlePair::GetElementA() const
	{
		return static_cast<hkpTypedBroadPhaseHandle*>(a);
	}
	
	
	hkpTypedBroadPhaseHandle* hkpTypedBroadPhaseHandlePair::GetElementB() const
	{
		return static_cast<hkpTypedBroadPhaseHandle*>(b);
	}
	
	
	hkpTypedBroadPhaseHandle* hkpTypedBroadPhaseHandlePair::GetOther(hkpTypedBroadPhaseHandle* a_elem) const
	{
		auto a_a = std::uint64_t(a);
		auto a_b = std::uint64_t(b);
		auto a_e = std::uint64_t(a_elem);
		return reinterpret_cast<hkpTypedBroadPhaseHandle*>(a_a ^ a_b ^ a_e);
	}
}