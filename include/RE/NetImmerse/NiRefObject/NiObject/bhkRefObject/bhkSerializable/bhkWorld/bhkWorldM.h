#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkWorld/bhkWorld.h"


namespace RE
{
	class bhkWorldM : public bhkWorld
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkWorldM;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkWorldM;


		virtual ~bhkWorldM();  // 00

		// override (bhkWorld)
		virtual const NiRTTI* GetRTTI() const override;	 // 02


		// members
		hkVector4 unkC600;				   // C600
		hkVector4 unkC610;				   // C610
		hkVector4 broadPhaseWorldAabbMax;  // C620
	};
	static_assert(sizeof(bhkWorldM) == 0xC630);
}
