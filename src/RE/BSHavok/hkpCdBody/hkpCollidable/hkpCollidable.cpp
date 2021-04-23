#include "RE/BSHavok/hkpCdBody/hkpCollidable/hkpCollidable.h"


namespace RE
{
	void* hkpCollidable::GetOwner() const
	{
		return const_cast<void*>(adjust_pointer<const void>(this, ownerOffset));
	}


	NiAVObject* hkpCollidable::GetUserNode()
	{
		using func_t = decltype(&hkpCollidable::GetUserNode);
		REL::Relocation<func_t> func{ REL::ID(15644) };
		return func(this);
	}
}
