#include "RE/BSShaderProperty.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"  

namespace RE
{
	UInt32 BSShaderProperty::InitializeMaterial(BSGeometry* geometry)
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::InitializeMaterial)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::InitializeMaterial);
		return func(this, geometry);
	}
	
	
	UInt32 BSShaderProperty::InitializeShader(BSGeometry* geometry)
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::InitializeShader)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::InitializeShader);
		return func(this, geometry);
	}

	UInt32 BSShaderProperty::SetMaterial(BSLightingShaderMaterialBase* otherMaterial, bool unk1)
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::SetMaterial)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::SetMaterial);
		return func(this, otherMaterial, unk1);			
	}

	UInt64 BSShaderProperty::SetFlags(UInt8 flag, UInt8 set)
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::SetFlags)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::SetFlags);
		return func(this, flag, set);
	}

	bool BSShaderProperty::InvalidateMaterial()
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::InvalidateMaterial)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::InvalidateMaterial);
		return func(this);
	}

	void BSShaderProperty::InvalidateTextures(UInt32 unk1)
	{
		using func_t = function_type_t<decltype(&BSShaderProperty::InvalidateTextures)>;
		REL::Offset<func_t*> func(Offset::BSShaderProperty::InvalidateTextures);
		return func(this, unk1);
	}
}