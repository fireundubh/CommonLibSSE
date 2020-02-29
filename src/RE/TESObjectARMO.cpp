#include "RE/TESObjectARMO.h"

#include "RE/TESObjectARMA.h"


namespace RE
{
	float TESObjectARMO::GetArmorRating()
	{
		return armorRating / 100;
	}


	TESObjectARMA* TESObjectARMO::GetArmorAddonByMask(TESRace* a_race, BGSBipedObjectForm::BipedObjectSlot a_slot)
	{
		for (auto& currentAddon : armorAddons) {
			if (currentAddon && currentAddon->IsValidRace(a_race) && (currentAddon->GetSlotMask() & a_slot) == a_slot) {
				return currentAddon;
			}
		}

		return nullptr;
	}
}
