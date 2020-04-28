#include "RE/BSLightingShaderProperty.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	void BSLightingShaderProperty::CopyMembers(BSLightingShaderProperty* a_other)
	{
		flags = a_other->flags;
		alpha = a_other->alpha;
		emissiveColor = a_other->emissiveColor;
		projectedUVParams = a_other->projectedUVParams;
		projectedUVColor = a_other->projectedUVColor;
		emissiveMult = a_other->emissiveMult;
	}


	void BSLightingShaderProperty::InvalidateTextures(UInt32 unk1)
	{
		using func_t = decltype(&BSLightingShaderProperty::InvalidateTextures);
		REL::Offset<func_t> func(Offset::BSLightingShaderProperty::InvalidateTextures);
		return func(this, unk1);
	}
}