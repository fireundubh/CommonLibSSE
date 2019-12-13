#include "RE/NiFloatExtraData.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiFloatExtraData* NiFloatExtraData::Create(BSFixedString name, float value)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiFloatExtraData::Vtbl);
		
		NiFloatExtraData* data = (NiFloatExtraData*)NiExtraData::Create(sizeof(NiFloatExtraData), vtbl.GetAddress());
		data->name = const_cast<char*>(name.c_str());
		data->data = value;

		return data;
	}
}