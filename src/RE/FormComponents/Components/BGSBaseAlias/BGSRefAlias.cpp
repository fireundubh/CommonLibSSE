#include "RE/FormComponents/Components/BGSBaseAlias/BGSRefAlias.h"

#include "RE/FormComponents/TESForm/BGSStoryManagerTreeForm/TESQuest.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Actor/Actor.h"


namespace RE
{
	TESObjectREFR* BGSRefAlias::GetReference()
	{
		TESObjectREFR* ref = nullptr;
		
		auto owner = owningQuest;
		if (owner) {
			ObjectRefHandle handle{};
			owner->CreateRefHandleByAliasID(handle, aliasID);
			
			auto refPtr = handle.get();
			ref = refPtr.get();
		}

		return ref;
	}
	
	
	Actor* BGSRefAlias::GetActorReference()
	{
		auto ref = GetReference();
		return ref ? ref->As<Actor>() : nullptr;
	}
}
