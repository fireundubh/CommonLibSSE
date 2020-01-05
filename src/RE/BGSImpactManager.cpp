#include "RE/BGSImpactManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BGSImpactManager* BGSImpactManager::GetSingleton()
	{
		REL::Offset<BGSImpactManager**> singleton(Offset::BGSImpactManager::Singleton);
		return *singleton;
	}

	bool BGSImpactManager::PlayImpactEffect(TESObjectREFR* ref, BGSImpactDataSet* impactData, const char* nodeName, NiPoint3* dirVec, float pickLength, bool applyNodeRot, bool useNodeLocalRot)
	{
		using func_t = function_type_t<decltype(&BGSImpactManager::PlayImpactEffect)>;
		REL::Offset<func_t*> func(Offset::BGSImpactManager::PlayImpactEffect);
		return func(this, ref, impactData, nodeName, dirVec, pickLength, applyNodeRot, useNodeLocalRot);
	}
}