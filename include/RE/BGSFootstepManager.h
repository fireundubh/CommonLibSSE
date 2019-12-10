#pragma once

#include "RE/BSTSingleton.h"  // BSTSingletonSDM
#include "RE/BGSFootstepEvent.h"

namespace RE
{
	class BGSFootstepManager :
		public BSTEventSource<BGSFootstepEvent>,
		public BSTSingletonSDM<BGSFootstepManager>
	{
	public:

		static BGSFootstepManager* GetSingleton();

		BSTArray<UInt32>	unk60;
	};
}
