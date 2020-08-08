#include "RE/NetImmerse/NiRefObject/NiObject/NiTexture/NiSourceTexture.h"


namespace RE
{
	NiSourceTexture* NiSourceTexture::Create(const BSFixedString& a_name)
	{
		using func_t = decltype(&NiSourceTexture::Create);
		REL::Relocation<func_t> func{ Offset::NiSourceTexture::Create };
		return func(a_name);
	}
}
