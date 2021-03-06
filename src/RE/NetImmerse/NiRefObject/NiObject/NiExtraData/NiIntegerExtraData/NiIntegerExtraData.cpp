#include "RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiIntegerExtraData/NiIntegerExtraData.h"


namespace RE
{
	NiIntegerExtraData* NiIntegerExtraData::Create(const BSFixedString& a_name, std::int32_t a_value)
	{
		REL::Relocation<std::uintptr_t> vtbl{ RE::Offset::NiIntegerExtraData::Vtbl };

		auto data = NiExtraData::Create<NiIntegerExtraData>(vtbl.address());
		if (data) {
			data->name = a_name;
			data->value = a_value;
		}

		return data;
	}
}