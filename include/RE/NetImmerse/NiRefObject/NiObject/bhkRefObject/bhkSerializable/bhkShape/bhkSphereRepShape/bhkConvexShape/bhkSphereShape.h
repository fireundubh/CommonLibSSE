#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkShape/bhkSphereRepShape/bhkConvexShape/bhkConvexShape.h"


namespace RE
{
	class bhkSphereShape : public bhkConvexShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkSphereShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkSphereShape;


		virtual ~bhkSphereShape();	// 00

		// override (bhkShape)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  Unk_2B(void) override;							  // 2B
		virtual void		  Unk_2C(void) override;							  // 2C
		virtual void		  Unk_2E(void) override;							  // 2E
		virtual void		  Unk_2F(void) override;							  // 2F
		virtual void		  Unk_32(void) override;							  // 32
	};
	static_assert(sizeof(bhkSphereShape) == 0x28);
}
