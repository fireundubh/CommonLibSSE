#pragma once

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpShape/hkpShapeCollection/hkpMeshShape/hkpMeshMaterial.h"
#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkShape/Enums/HAVOK_MATERIAL.h"


namespace RE
{
	class bhkMeshMaterial : public hkpMeshMaterial
	{
	public:
		//members
		HAVOK_MATERIAL material;  // 04
	};
	static_assert(sizeof(bhkMeshMaterial) == 0x8);
}
