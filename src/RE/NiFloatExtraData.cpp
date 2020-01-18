#include "RE/NiFloatExtraData.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiFloatExtraData* NiFloatExtraData::Create(const BSFixedString& name, float value)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiFloatExtraData::Vtbl);
		
		NiFloatExtraData* data = static_cast<NiFloatExtraData*>(NiExtraData::Create(sizeof(NiFloatExtraData), vtbl.GetAddress()));
		if (data)
		{
			data->name = name;
			data->data = value;
		}

		return data;
	}
}