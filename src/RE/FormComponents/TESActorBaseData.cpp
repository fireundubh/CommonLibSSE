#include "RE/FormComponents/TESActorBaseData.h"

#include "RE/FormComponents/TESForm/TESFaction.h"


namespace RE
{
	bool TESActorBaseData::IsInFaction(TESFaction* a_faction) const
	{
		for (const auto& faction : factions) {
			if (faction.faction && faction.faction == a_faction) {
				return true;
			}
		}
		return false;
	}
}
