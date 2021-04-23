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
		REL::Relocation<func_t> func{ Offset::TESWorldSpace::GetOrCreateSkyCell };
		return func(this);
	}
	
	
	float TESWorldSpace::GetWaterHeight() const
	{
		auto world = this;		
		while (world->parentWorld && world->parentUseFlags.any(ParentUseFlag::kUseLandData)) {
			world = world->parentWorld;
		}					
		return world->defaultWaterHeight;
	}
}
