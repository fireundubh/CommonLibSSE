#pragma once

#include "RE/BSCore/BSTEvent.h"


namespace RE
{
	struct DragonSoulsGained
	{
	public:
		struct Event
		{
		public:
			// members
			float		  souls;  // 00
			std::uint32_t pad04;  // 04
		};
		static_assert(sizeof(Event) == 0x08);


		static BSTEventSource<DragonSoulsGained::Event>* GetEventSource();
	};
}
