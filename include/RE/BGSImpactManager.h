#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTSingleton.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class TESObjectREFR;
	class BGSImpactDataSet;
	
	struct BGSFootstepEvent;
	struct BGSCombatImpactEvent;
	struct BGSCollisionSoundEvent;

	class BGSImpactManager : 
		public BSTEventSink<BGSFootstepEvent>,			// 00
		public BSTEventSink<BGSCombatImpactEvent>,		// 08
		public BSTEventSink<BGSCollisionSoundEvent>,	// 10
		public BSTSingletonSDM<BGSImpactManager>		// 18
	{
	public:
		static BGSImpactManager* GetSingleton();

		bool PlayImpactEffect(TESObjectREFR* ref, BGSImpactDataSet* impactData, const char* nodeName, NiPoint3* dirVec, float pickLength, bool applyNodeRot, bool useNodeLocalRot);

		BSTArray<void*>		unk20;	// 28
	};
}