#pragma once

#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class Actor;


	enum class ACTOR_COMBAT_STATE
	{
		kNone = 0,
		kCombat = 1,
		kSearching = 2
	};


	struct TESCombatEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR>							actor;		  // 00
		NiPointer<TESObjectREFR>							targetActor;  // 08
		stl::enumeration<ACTOR_COMBAT_STATE, std::uint32_t> state;		  // 10
		std::uint32_t										pad14;		  // 14
	};
	static_assert(sizeof(TESCombatEvent) == 0x18);
}
