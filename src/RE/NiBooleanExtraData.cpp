#include "RE/NiBooleanExtraData.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	NiBooleanExtraData* NiBooleanExtraData::Create(const BSFixedString& name, bool value)
	{
		REL::Offset<std::uintptr_t> vtbl(RE::Offset::NiBooleanExtraData::Vtbl);
		
		NiBooleanExtraData* data = (NiBooleanExtraData*)NiExtraData::Create(sizeof(NiBooleanExtraData), vtbl.GetAddress());
		data->name = name;
		data->data = value;

		return data;
	}
}