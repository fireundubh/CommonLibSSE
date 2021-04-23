#pragma once

#include "RE/BSHavok/hkVector4.h"


namespace RE
{
	class hkAabb
	{
	public:
		hkAabb() = default;
		hkAabb(const hkVector4& a_min, const hkVector4& a_max) :
			min(a_min),
			max(a_max)
		{
		}

		// members
		hkVector4 min;	// 00
		hkVector4 max;	// 10
	};
	static_assert(sizeof(hkAabb) == 0x20);
}
