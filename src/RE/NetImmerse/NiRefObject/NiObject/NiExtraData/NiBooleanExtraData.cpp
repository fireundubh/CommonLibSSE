#include "RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiBooleanExtraData.h"


namespace RE
{
	NiBooleanExtraData* NiBooleanExtraData::Create(const BSFixedString& a_name, bool a_value)
	{
		REL::Relocation<std::uintptr_t> vtbl{ RE::Offset::NiBooleanExtraData::Vtbl };

		auto data = NiExtraData::Create<NiBooleanExtraData>(vtbl.address());
		if (data) {
			data->name = a_name;
			data->data = a_value;
		}

		return data;
	}
}