#include "RE/FormComponents/TESForm/TESWorldSpace.h"


namespace RE
{
	bool TESWorldSpace::HasMaxHeightData() const
	{
		return maxHeightData != nullptr;
	}

	TESObjectCELL* TESWorldSpace::GetOrCreateSkyCell()
	{
		using func_t = decltype(&TESWorldSpace::GetOrCreateSkyCell);
		REL::Offset<func_t> func(Offset::TESWorldSpace::GetOrCreateSkyCell);
		return func(this);
	}
}
