#include "RE/FormComponents/TESForm/TESRace.h"


namespace RE
{
	bool TESRace::AllowsPCDialogue() const
	{
		return data.flags.all(RACE_DATA::Flag::kAllowPCDialogue);
	}


	bool TESRace::AllowsPickpocket() const
	{
		return data.flags.all(RACE_DATA::Flag::kAllowPickpocket);
	}


	TESSpellList::SpellData* TESRace::GetOrCreateSpellList()
	{
		if (!actorEffects) {
			actorEffects = new TESSpellList::SpellData();
		}
		return actorEffects;
	}
}
