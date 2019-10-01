#include "RE/BSLightingShaderProperty.h"

#include "skse64/NiProperties.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"  // Offset

namespace RE
{
	UInt32 BSLightingShaderProperty::InitializeShader(BSGeometry* geometry)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderProperty::InitializeShader)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSLightingShaderProperty, InitializeShader, func_t*);
		return func(this, geometry);
	}

	UInt32 BSLightingShaderProperty::SetMaterial(BSLightingShaderMaterialBase* material, bool unk1))
	{
		using func_t = function_type_t<decltype(&BSLightingShaderProperty::SetMaterial)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSLightingShaderProperty, SetMaterial, func_t*);
		return func(this, material, unk1);
	}

	UInt64 BSLightingShaderProperty::SetFlags(UInt8 unk1, UInt8 unk2)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderProperty::SetFlags)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSLightingShaderProperty, SetFlags, func_t*);
		return func(this, unk1, unk2);
	}

	bool BSLightingShaderProperty::InvalidateMaterial()
	{
		using func_t = function_type_t<decltype(&BSLightingShaderProperty::InvalidateMaterial)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSLightingShaderProperty, InvalidateMaterial, func_t*);
		return func(this);
	}

	bool BSLightingShaderProperty::InvalidateMaterial()
	{
		using func_t = function_type_t<decltype(&BSLightingShaderProperty::InvalidateMaterial)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSLightingShaderProperty, InvalidateMaterial, func_t*);
		return func(this);
	}

	void BSLightingShaderProperty::InvalidateTextures(UInt32 unk1)
	{
		using func_t = function_type_t<decltype(&BSLightingShaderProperty::InvalidateTextures)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSLightingShaderProperty, InvalidateTextures, func_t*);
		return func(this, unk1);
	}
}