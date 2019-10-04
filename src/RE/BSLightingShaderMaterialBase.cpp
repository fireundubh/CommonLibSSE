#include "RE/BSLightingShaderMaterialBase.h"

#include "skse64/NiMaterial.h"  // CreateShaderMaterial

#include "RE/BSTextureSet.h"  // BSTextureSet


namespace RE
{
	BSLightingShaderMaterialBase* BSLightingShaderMaterialBase::CreateMaterial(Type a_type)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderMaterialBase::CreateMaterial)>;
		func_t* func = unrestricted_cast<func_t*>(CreateShaderMaterial.GetUIntPtr());
		return func(a_type);
	}

	
	NiPointer<BSTextureSet> BSLightingShaderMaterialBase::GetTextureSet() const
	{
		return textureSet;
	}


	void BSLightingShaderMaterialBase::SetTextureSet(BSTextureSet * a_textureSet)
	{
		textureSet.reset();
		textureSet.reset(a_textureSet);
	}


	void BSLightingShaderMaterialBase::CopyFrom(BSLightingShaderMaterialBase* otherMaterial)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderMaterialBase::CopyFrom)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSLightingShaderMaterial, CopyFrom, func_t*);
		return func(this, otherMaterial);
	}
}
