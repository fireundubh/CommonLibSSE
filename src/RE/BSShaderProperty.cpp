#include "RE/BSShaderProperty.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"  

namespace RE
{
	UInt32 BSShaderProperty::SetMaterial(BSShaderMaterial* a_material, bool a_unk1)
	{
		using func_t = decltype(&BSShaderProperty::SetMaterial);
		REL::Offset<func_t> func(Offset::BSShaderProperty::SetMaterial);
		return func(this, a_material, a_unk1);			
	}


	UInt64 BSShaderProperty::SetFlags(UInt8 a_flag, UInt8 a_toggle)
	{
		using func_t = decltype(&BSShaderProperty::SetFlags);
		REL::Offset<func_t> func(Offset::BSShaderProperty::SetFlags);
		return func(this, a_flag, a_toggle);
	}


	bool BSShaderProperty::InvalidateMaterial()
	{
		using func_t = decltype(&BSShaderProperty::InvalidateMaterial);
		REL::Offset<func_t> func(Offset::BSShaderProperty::InvalidateMaterial);
		return func(this);
	}


	void BSShaderProperty::InvalidateTextures(UInt32 unk1)
	{
		using func_t = decltype(&BSShaderProperty::InvalidateTextures);
		REL::Offset<func_t> func(Offset::BSShaderProperty::InvalidateTextures);
		return func(this, unk1);
	}
}