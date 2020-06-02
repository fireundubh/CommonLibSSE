#include "RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiFloatExtraData.h"


namespace RE
{
	NiFloatExtraData* NiFloatExtraData::Create(const BSFixedString& name, float value)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiFloatExtraData::Vtbl);

		auto data = static_cast<NiFloatExtraData*>(NiExtraData::Create(sizeof(NiFloatExtraData), vtbl.address()));
		if (data) {
			data->name = name;
			data->data = value;
		}

		return data;
	}
}