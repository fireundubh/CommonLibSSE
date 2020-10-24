#pragma once

#include "RE/BSCore/BSTEvent.h"


namespace RE
{
	class TESObjectREFR;


	struct SoulsTrapped
	{
	public:
		struct Event
		{
		public:
			// members
			TESObjectREFR* trapper;	 // 00
			TESObjectREFR* target;	 // 08
		};
		static_assert(sizeof(Event) == 0x10);


		static BSTEventSource<SoulsTrapped::Event>* GetEventSource();
	};
}
