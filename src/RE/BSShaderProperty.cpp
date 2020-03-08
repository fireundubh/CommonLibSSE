#include "RE/BSShaderProperty.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"  


namespace RE
{
	bool BSShaderProperty::InvalidateMaterial()
	{
		using func_t = decltype(&BSShaderProperty::InvalidateMaterial);
		REL::Offset<func_t> func(Offset::BSShaderProperty::InvalidateMaterial);
		return func(this);
	}


	void BSShaderProperty::SetMaterial(BSShaderMaterial* a_material, bool a_unk1)
	{
		using func_t = decltype(&BSShaderProperty::SetMaterial);
		REL::Offset<func_t> func(Offset::BSShaderProperty::SetMaterial);
		return func(this, a_material, a_unk1);
	}


	void BSShaderProperty::SetFlags(UInt8 a_flag, UInt8 a_toggle)
	{
		using func_t = decltype(&BSShaderProperty::SetFlags);
		REL::Offset<func_t> func(Offset::BSShaderProperty::SetFlags);
		return func(this, a_flag, a_toggle);
	}
}