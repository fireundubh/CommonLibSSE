#include "RE/FormComponents/TESActorBaseData.h"

#include "RE/FormComponents/TESForm/TESFaction.h"


namespace RE
{
	bool TESActorBaseData::IsInFaction(TESFaction* a_faction) const
	{
		return std::any_of(factions.begin(), factions.end(), [&a_faction](const auto& faction) {
			return faction.faction == a_faction;
		});
	}
}
