#pragma once

#include "RE/BSTempEffect.h"
#include "RE/NiSmartPointer.h"

class NiAVObject;

namespace RE
{

	class BSTempEffectDebris: public BSTempEffect
	{
	public:
		inline static const void* RTTI = RTTI_BSTempEffectDebris;
		inline static const void* Ni_RTTI = NiRTTI_BSTempEffectDebris;

		virtual ~BSTempEffectDebris();												// 00

		virtual const NiRTTI*	GetRTTI() const override;						// 02
		virtual void			Unk_28(void) override;							// 28
		virtual void			Unk_29(void) override;							// 29
		virtual void			Unk_2C(void) override;							// 2C - { return 5; }

		// members;
		NiPointer<NiAVObject> 	unk30;					// 030
		const char *			unk38;					// 038
		UInt8					unk40;					// 040
		UInt8					unk41;					// 041
	};
	STATIC_ASSERT(sizeof(BSTempEffectDebris) == 0x48);
}