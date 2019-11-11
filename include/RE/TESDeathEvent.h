#pragma once

#include "RE/NiSmartPointer.h"  // NiPointer

namespace RE
{
	class TESObjectREFR;

	struct TESDeathEvent
	{
		// OnDying, OnDeath
		//
	    // This fires TWICE for an actor's death: once when they are fated to die, and 
	    // again when they're actually dead; this is the distinction between Papyrus 
	    // OnDying and OnDeath. The (isDead) bool indicates whether the actor is dying 
	    // (false) or dead (true). Calls to victim->IsDead(0) should return the same 
	    // result.
	    //
		NiPointer<TESObjectREFR> victim; // 00
		NiPointer<TESObjectREFR> killer; // 08
		bool					 isDead; // 10
	};
	STATIC_ASSERT(sizeof(TESDeathEvent) == 0x18);
}

