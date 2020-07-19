#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkShape/bhkSphereRepShape/bhkSphereRepShape.h"


namespace RE
{
	class bhkConvexShape : public bhkSphereRepShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkConvexShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkConvexShape;


		virtual ~bhkConvexShape();	// 00
	};
	static_assert(sizeof(bhkConvexShape) == 0x28);
}
