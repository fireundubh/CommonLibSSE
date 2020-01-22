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

		virtual ~BSTempEffectDebris();											// 00

		virtual const NiRTTI*		GetRTTI() const override;					// 02
		virtual bool				Update(float a_arg1) override;				// 28
		virtual NiAVObject*			Get3D() const override;						// 29
		virtual TEMP_EFFECT_TYPE	GetType() const;;							// 2C - { return kDebris; }

		// members;
		NiPointer<NiAVObject> 	unk30;					// 030
		const char *			unk38;					// 038
		UInt8					unk40;					// 040
		UInt8					unk41;					// 041
	};
	STATIC_ASSERT(sizeof(BSTempEffectDebris) == 0x48);
}