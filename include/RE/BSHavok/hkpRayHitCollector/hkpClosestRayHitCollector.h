#pragma once

#include "RE/BSHavok/hkpRayHitCollector/hkpRayHitCollector.h"
#include "RE/BSHavok/hkpShapeRayCastCollectorOutput/hkpShapeRayCastOutput/hkpWorldRayCastOutput.h"


namespace RE
{
	class hkpClosestRayHitCollector : public hkpRayHitCollector
	{
	public:
		hkpClosestRayHitCollector() noexcept :
			hkpRayHitCollector(Offset::hkpClosestRayHitCollector::Vtbl.address()){};


		// members
		hkpWorldRayCastOutput rayHit;  // 10
	};
	static_assert(sizeof(hkpClosestRayHitCollector) == 0x70);
}