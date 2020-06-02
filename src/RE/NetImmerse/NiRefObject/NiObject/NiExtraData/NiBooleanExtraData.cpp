#include "RE/NetImmerse/NiRefObject/NiObject/NiExtraData/NiBooleanExtraData.h"


namespace RE
{
	NiBooleanExtraData* NiBooleanExtraData::Create(const BSFixedString& name, bool value)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiBooleanExtraData::Vtbl);

		NiBooleanExtraData* data = static_cast<NiBooleanExtraData*>(NiExtraData::Create(sizeof(NiBooleanExtraData), vtbl.GetAddress()));
		if (data) {
			data->name = name;
			data->data = value;
		}

		return data;
	}
}