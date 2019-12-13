#pragma once

#include "RE/NiSmartPointer.h"  

namespace RE
{
	class Actor;
	
	struct TESSwitchRaceCompleteEvent
	{
		NiPointer<Actor> subject; // 00
	};
	STATIC_ASSERT(sizeof(TESSwitchRaceCompleteEvent) == 0x8);
}