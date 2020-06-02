#include "RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiIntegerExtraData/NiIntegerExtraData.h"


namespace RE
{
	NiIntegerExtraData* NiIntegerExtraData::Create(const BSFixedString& name, SInt32 value)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiIntegerExtraData::Vtbl);

		auto data = static_cast<NiIntegerExtraData*>(NiExtraData::Create(sizeof(NiIntegerExtraData), vtbl.address()));
		if (data) {
			data->name = name;
			data->value = value;
		}

		return data;
	}
}