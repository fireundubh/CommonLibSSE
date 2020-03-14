#include "RE/BSLightingShaderMaterialBase.h"

#include "RE/BSTextureSet.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSLightingShaderMaterialBase* BSLightingShaderMaterialBase::CreateMaterial(Feature a_feature)
	{
		using func_t = decltype(&BSLightingShaderMaterialBase::CreateMaterial);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialBase::CreateMaterial);
		return func(a_feature);
	}


	NiPointer<BSTextureSet> BSLightingShaderMaterialBase::GetTextureSet() const
	{
		return textureSet;
	}


	void BSLightingShaderMaterialBase::SetTextureSet(BSTextureSet * a_textureSet)
	{
		textureSet.reset(a_textureSet);
	}


	void BSLightingShaderMaterialBase::CopyBaseMaterial(BSLightingShaderMaterialBase* otherMaterial)
	{
		using func_t = decltype(&BSLightingShaderMaterialBase::CopyBaseMaterial);
		REL::Offset<func_t> func(Offset::BSLightingShaderMaterialBase::CopyBaseMaterial);
		return func(this, otherMaterial);
	}
}
