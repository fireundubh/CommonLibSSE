#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkShape/bhkSphereRepShape/bhkConvexShape/bhkConvexShape.h"


namespace RE
{
	class bhkBoxShape : public bhkConvexShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkBoxShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkBoxShape;


		virtual ~bhkBoxShape();	 // 00

	};
	STATIC_ASSERT(sizeof(bhkBoxShape) == 0x28);
}
