#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectARMO.h"

#include "RE/FormComponents/TESForm/TESObject/TESObjectARMA.h"


namespace RE
{
	TESObjectARMA* TESObjectARMO::GetArmorAddon(TESRace* a_race)
	{
		if (a_race) {
			for (auto& currentAddon : armorAddons) {
				if (currentAddon && currentAddon->IsValidRace(a_race)) {
					return currentAddon;
				}
			}
		}

		return nullptr;
	}
	
	
	TESObjectARMA* TESObjectARMO::GetArmorAddonByMask(TESRace* a_race, BipedObjectSlot a_slot)
	{
		if (a_race) {
			for (auto& currentAddon : armorAddons) {
				if (currentAddon && currentAddon->IsValidRace(a_race) && currentAddon->HasPartOf(a_slot)) {
					return currentAddon;
				}
			}
		}

		return nullptr;
	}


	float TESObjectARMO::GetArmorRating()
	{
		return static_cast<float>(armorRating) / static_cast<float>(100.0);
	}
}
