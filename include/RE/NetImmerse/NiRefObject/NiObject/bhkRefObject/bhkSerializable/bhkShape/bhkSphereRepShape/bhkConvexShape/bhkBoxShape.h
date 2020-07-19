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

		// override (bhkConvexShape)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual void		  Unk_2B(void) override;							  // 2B
		virtual void		  Unk_2C(void) override;							  // 2C
		virtual void		  Unk_2E(void) override;							  // 2B
		virtual void		  Unk_2F(void) override;							  // 2C
		virtual void		  Unk_32(void) override;							  // 2C
	};
	static_assert(sizeof(bhkBoxShape) == 0x28);
}
