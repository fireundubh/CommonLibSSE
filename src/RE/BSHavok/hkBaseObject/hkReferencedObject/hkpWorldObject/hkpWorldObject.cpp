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
		auto collidable = GetCollidable();
		if (collidable) {
			return collidable->GetShape();
		}
		return nullptr;
	}


	TESObjectREFR* hkpWorldObject::GetUserData() const
	{
		auto collidable = GetCollidable();
		if (collidable) {
			return collidable->GetUserData();
		}
		return nullptr;
	}
}
