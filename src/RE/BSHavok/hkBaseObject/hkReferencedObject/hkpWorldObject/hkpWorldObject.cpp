#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpWorldObject/hkpWorldObject.h"
#include "RE/BSHavok/TESHavokUtilities.h"


namespace RE
{
	const hkpCollidable* hkpWorldObject::GetCollidable() const
	{
		return &collidable;
	}


	hkpCollidable* hkpWorldObject::GetCollidableRW()
	{
		return &collidable;
	}


	const hkpShape* hkpWorldObject::GetShape() const
	{
		auto hkpCollidable = GetCollidable();
		if (hkpCollidable) {
			return hkpCollidable->GetShape();
		}
		return nullptr;
	}


	TESObjectREFR* hkpWorldObject::GetUserData() const
	{
		auto hkpCollidable = GetCollidable();
		if (hkpCollidable) {
			return TESHavokUtilities::FindCollidableRef(*hkpCollidable);
		}
		return nullptr;
	}
}
