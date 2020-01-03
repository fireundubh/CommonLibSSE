#include "RE/TESWorldSpace.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"

namespace RE
{
	bool TESWorldSpace::HasMaxHeightData() const
	{
		return maxHeightData != 0;
	}

	TESObjectCELL* TESWorldSpace::GetOrCreateUnk0F8Cell()
	{
		using func_t = function_type_t<decltype(&TESWorldSpace::GetOrCreateUnk0F8Cell)>;
		REL::Offset<func_t*> func(Offset::TESWorldSpace::GetOrCreateUnk0F8Cell);
		return func(this);
	}
}
