#include "RE/BSLightingShaderProperty.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"  

namespace RE
{
	UInt32 BSLightingShaderProperty::InitializeShader(BSGeometry* geometry)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderProperty::InitializeShader)>;
		REL::Offset<func_t*> func(Offset::BSLightingShaderProperty::InitializeShader);
		return func(this, geometry);
	}

	UInt32 BSLightingShaderProperty::SetMaterial(BSLightingShaderMaterialBase* otherMaterial, bool unk1)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderProperty::SetMaterial)>;
		REL::Offset<func_t*> func(Offset::BSLightingShaderProperty::SetMaterial);
		return func(this, otherMaterial, unk1);			
	}

	UInt64 BSLightingShaderProperty::SetFlags(UInt8 unk1, UInt8 unk2)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderProperty::SetFlags)>;
		REL::Offset<func_t*> func(Offset::BSLightingShaderProperty::SetFlags);
		return func(this, unk1, unk2);
	}

	bool BSLightingShaderProperty::InvalidateMaterial()
	{
		using func_t = function_type_t<decltype(&BSLightingShaderProperty::InvalidateMaterial)>;
		REL::Offset<func_t*> func(Offset::BSLightingShaderProperty::InvalidateMaterial);
		return func(this);
	}

	void BSLightingShaderProperty::InvalidateTextures(UInt32 unk1)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderProperty::InvalidateTextures)>;
		REL::Offset<func_t*> func(Offset::BSLightingShaderProperty::InvalidateTextures);
		return func(this, unk1);
	}
}