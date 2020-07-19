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

		// override ( bhkSphereRepShape)
		virtual const NiRTTI* GetRTTI() const override;					// 02
		virtual void		  LoadBinary(NiStream& a_stream) override;	// 18
		virtual void		  SaveBinary(NiStream& a_stream) override;	// 1B
	};
	static_assert(sizeof(bhkConvexShape) == 0x28);
}
