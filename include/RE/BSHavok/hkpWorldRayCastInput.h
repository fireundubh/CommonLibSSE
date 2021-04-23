#pragma once

#include "RE/BSHavok/hkVector4.h"
#include "RE/BSHavok/hkpShapeRayCastCollectorOutput/hkpShapeRayCastOutput/hkpWorldRayCastOutput.h"


namespace RE
{
	class hkpRayHitCollector;


	struct hkpWorldRayCastInput
	{
	public:
		// members
		hkVector4	  from;									 // 00
		hkVector4	  to;									 // 10
		bool		  enableShapeCollectionFilter{ false };	 // 20
		std::uint32_t filterInfo{ 0 };						 // 24
		std::uint32_t pad28;								 // 28
	};
	static_assert(sizeof(hkpWorldRayCastInput) == 0x30);
}
