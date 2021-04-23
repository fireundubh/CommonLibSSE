#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiProperty/NiAlphaProperty.h"


namespace RE
{
	NiAlphaProperty* NiAlphaProperty::ctor()
	{
		using func_t = decltype(&NiAlphaProperty::ctor);
		REL::Relocation<func_t> func{ REL::ID(15225) };
		return func(this);		
	}


	NiAlphaProperty* NiAlphaProperty::Create()
	{
		auto alphaProp = malloc<NiAlphaProperty>();
		alphaProp->ctor();
		return alphaProp;
	}
}
