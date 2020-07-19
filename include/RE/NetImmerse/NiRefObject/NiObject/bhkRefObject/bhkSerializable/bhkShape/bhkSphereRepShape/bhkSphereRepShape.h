#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkShape/bhkShape.h"


namespace RE
{
	class bhkSphereRepShape : public bhkShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkSphereRepShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkSphereRepShape;


		virtual ~bhkSphereRepShape();  // 00

		// override (bhkShape)
		virtual const NiRTTI* GetRTTI() const override;	 // 02
	};
	static_assert(sizeof(bhkSphereRepShape) == 0x28);
}
