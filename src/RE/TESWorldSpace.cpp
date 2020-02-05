#include "RE/TESWorldSpace.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"

namespace RE
{
	bool TESWorldSpace::HasMaxHeightData() const
	{
		return maxHeightData != 0;
	}

	TESObjectCELL* TESWorldSpace::GetOrCreateSkyCell()
	{
		using func_t = decltype(&TESWorldSpace::GetOrCreateSkyCell);
		REL::Offset<func_t> func(Offset::TESWorldSpace::GetOrCreateSkyCell);
		return func(this);
	}
}
