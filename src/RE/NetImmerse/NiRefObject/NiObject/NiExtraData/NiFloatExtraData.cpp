#include "RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiFloatExtraData.h"


namespace RE
{
	NiFloatExtraData* NiFloatExtraData::Create(const BSFixedString& a_name, float a_value)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiFloatExtraData::Vtbl);

		auto data = NiExtraData::Create<NiFloatExtraData>(vtbl.address());
		if (data) {
			data->name = a_name;
			data->data = a_value;
		}

		return data;
	}
}