#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTEvent.h"
#include "RE/BSCore/BSTSingleton.h"
#include "RE/NetImmerse/NiPoint3.h"


namespace RE
{
	class TESObjectREFR;
	class BGSImpactDataSet;

	struct BGSFootstepEvent;
	struct BGSCombatImpactEvent;
	struct BGSCollisionSoundEvent;


	class BGSImpactManager :
		public BSTEventSink<BGSFootstepEvent>,		  // 00
		public BSTEventSink<BGSCombatImpactEvent>,	  // 08
		public BSTEventSink<BGSCollisionSoundEvent>,  // 10
		public BSTSingletonSDM<BGSImpactManager>	  // 18
	{
	public:
		static BGSImpactManager* GetSingleton();

		bool PlayImpactEffect(TESObjectREFR* ref, BGSImpactDataSet* impactData, const BSFixedString& nodeName, NiPoint3& dirVec, float pickLength, bool applyNodeRot, bool useNodeLocalRot);


		BSTArray<void*> unk20;	// 28
	};
}