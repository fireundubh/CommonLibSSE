#pragma once

#include "RE/BSHavok/hkpEntityListener/bhkEntityListener/bhkEntityListener.h"
#include "RE/BSHavok/hkpPhantomListener.h"


namespace RE
{
	class bhkTrapListener :
		public bhkEntityListener,  // 000
		public hkpPhantomListener  // 018
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkTrapListener;


		virtual ~bhkTrapListener();	 // 00
	};
	static_assert(sizeof(bhkTrapListener) == 0x20);
}
