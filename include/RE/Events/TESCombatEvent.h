#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class Actor;


	enum class ACTOR_COMBAT_STATE : UInt32
	{
		kNone = 0,
		kCombat = 1,
		kSearching = 2
	};


	struct TESCombatEvent
	{
		// members
		NiPointer<Actor>			actor;			// 00
		NiPointer<Actor>			targetActor;	// 08
		ACTOR_COMBAT_STATE			state;			// 10
		UInt32						pad14;			// 14
	};
	STATIC_ASSERT(sizeof(TESCombatEvent) == 0x18);
}
