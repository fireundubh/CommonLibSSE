#include "RE/BSHavok/hkpCdBody/hkpCollidable/hkpCollidable.h"


namespace RE
{
	void* hkpCollidable::GetOwner() const
	{
		return const_cast<void*>(adjust_pointer<const void>(this, ownerOffset));
	}
	
	
	TESObjectREFR* hkpCollidable::GetUserData() const
	{
		using func_t = decltype(&hkpCollidable::GetUserData);
		REL::Relocation<func_t> func{ REL::ID(25466) };
		return func(this);
	}
}
