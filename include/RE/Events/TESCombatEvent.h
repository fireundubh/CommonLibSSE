#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESCombatEvent
	{
		enum class State : UInt32
		{
			kNotInCombat = 0,
			kInCombat = 1,
			kSearching = 2
		};


		// members
		NiPointer<TESObjectREFR>	source;	// 00
		NiPointer<TESObjectREFR>	target;	// 08
		State						state;	// 10
		UInt32						pad14;	// 14
	};
	STATIC_ASSERT(sizeof(TESCombatEvent) == 0x18);
}
