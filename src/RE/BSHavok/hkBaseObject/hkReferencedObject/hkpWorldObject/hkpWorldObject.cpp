#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpWorldObject/hkpWorldObject.h"


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
		return GetCollidable() ? GetCollidable()->GetShape() : nullptr;
	}


	TESObjectREFR* hkpWorldObject::GetUserData() const
	{
		return GetCollidable() ? GetCollidable()->GetUserData() : nullptr;
	}
}
