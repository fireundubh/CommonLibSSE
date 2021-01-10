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
	
	
	BGSHeadPart* TESRace::GetHeadPartByType(HeadPartType a_type, SEX a_sex)
	{
		auto faceData = faceRelatedData[a_sex];
		if (faceData && faceData->headParts) {
			for (auto& headpart : *faceData->headParts) {
				if (headpart && headpart->type == a_type) {
					return headpart;
				}
			}
		}

		return nullptr;
	}
}
