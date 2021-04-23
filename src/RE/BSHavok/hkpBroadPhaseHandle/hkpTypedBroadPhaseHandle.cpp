#include "RE/BSHavok/hkpBroadPhaseHandle/hkpTypedBroadPhaseHandle.h"


namespace RE
{
	void* hkpTypedBroadPhaseHandle::GetOwner() const
	{
		assert(ownerOffset != kInvalidOffset);
		return const_cast<void*>(adjust_pointer<const void>(this, ownerOffset));
	}
}