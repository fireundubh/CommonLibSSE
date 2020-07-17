#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpShape/hkpSphereRepShape/hkpConvexShape/hkpBoxShape.h"

namespace RE
{
	void hkpBoxShape::SetHalfExtents(const hkVector4& a_halfExtents)
	{
		halfExtents = a_halfExtents;
	}
}

