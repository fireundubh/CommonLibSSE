#pragma once

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpShape/hkpShapeCollection/hkpMeshShape/hkpMeshMaterial.h"
#include "RE/FormComponents/TESForm/BGSMaterialType.h"


namespace RE
{
	class bhkMeshMaterial : public hkpMeshMaterial
	{
	public:
		
		//members
		MATERIAL_ID materialID;  // 04
	};
	static_assert(sizeof(bhkMeshMaterial) == 0x8);
}
