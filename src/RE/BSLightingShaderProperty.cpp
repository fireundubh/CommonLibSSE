#include "RE/BSLightingShaderProperty.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"  


namespace RE
{
	void BSLightingShaderProperty::InvalidateTextures(UInt32 unk1)
	{
		using func_t = decltype(&BSLightingShaderProperty::InvalidateTextures);
		REL::Offset<func_t> func(Offset::BSLightingShaderProperty::InvalidateTextures);
		return func(this, unk1);
	}
}