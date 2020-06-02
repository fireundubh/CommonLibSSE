#include "RE/NetImmerse/NiRefObject/NiObject/BSTextureSet/BSShaderTextureSet.h"


namespace RE
{
	BSShaderTextureSet* BSShaderTextureSet::ctor()
	{
		using func_t = decltype(&BSShaderTextureSet::ctor);
		REL::Offset<func_t> func(Offset::BSShaderTextureSet::Ctor);
		return func(this);
	}

	BSShaderTextureSet* BSShaderTextureSet::Create()
	{
		auto textureset = malloc<BSShaderTextureSet>();
		textureset->ctor();
		return textureset;
	}
}