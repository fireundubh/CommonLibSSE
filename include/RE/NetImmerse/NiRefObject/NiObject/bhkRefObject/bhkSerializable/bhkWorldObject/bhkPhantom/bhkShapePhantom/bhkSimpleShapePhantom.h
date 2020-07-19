#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkWorldObject/bhkPhantom/bhkShapePhantom/bhkShapePhantom.h"


namespace RE
{
	class bhkSimpleShapePhantom : public bhkShapePhantom
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkSimpleShapePhantom;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkSimpleShapePhantom;


		virtual ~bhkSimpleShapePhantom();  // 00

		// override (bhkShapePhantom)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
	};
	static_assert(sizeof(bhkSimpleShapePhantom) == 0x30);
}