#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/BSTSingleton.h"


namespace RE
{
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

		BSTArray<void*>		unk20;	// 28
	};
}