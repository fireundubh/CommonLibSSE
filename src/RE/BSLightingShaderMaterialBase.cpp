#include "RE/BSLightingShaderMaterialBase.h"

#include "skse64/NiMaterial.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"  // Offset

namespace RE
{
	void BSLightingShaderMaterialBase::CopyFrom(BSLightingShaderMaterialBase* otherMaterial)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderMaterialBase::CopyFrom)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSLightingShaderMaterial, CopyFrom, func_t*);
		return func(this, otherMaterial);
	}

	void BSLightingShaderMaterialBase::SetTextureSet(BSTextureSet* newSet)
	{
		textureSet.reset();
		textureSet.reset(newSet);
	}
}