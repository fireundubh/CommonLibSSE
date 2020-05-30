#include "RE/BGSImpactManager.h"


namespace RE
{
	BGSImpactManager* BGSImpactManager::GetSingleton()
	{
		REL::Offset<BGSImpactManager**> singleton(Offset::BGSImpactManager::Singleton);
		return *singleton;
	}


	bool BGSImpactManager::PlayImpactEffect(TESObjectREFR* ref, BGSImpactDataSet* impactData, const BSFixedString& nodeName, NiPoint3& dirVec, float pickLength, bool applyNodeRot, bool useNodeLocalRot)
	{
		using func_t = decltype(&BGSImpactManager::PlayImpactEffect);
		REL::Offset<func_t> func(Offset::BGSImpactManager::PlayImpactEffect);
		return func(this, ref, impactData, nodeName, dirVec, pickLength, applyNodeRot, useNodeLocalRot);
	}
}