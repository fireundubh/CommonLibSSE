#pragma once

#include "RE/BSTempEffect.h"

class NiAVObject;

namespace RE
{

	class BSTempEffectWeaponBlood : public BSTempEffect
	{
	public:
		inline static const void* RTTI = RTTI_BSTempEffectWeaponBlood;

		virtual ~BSTempEffectWeaponBlood();							// 00

		virtual bool				Update(float a_arg1) override;	// 28
		virtual TEMP_EFFECT_TYPE	GetType() const override;		// 2C - { return 1; }

		// members;
		NiAVObject*		weapon;								// 030
		float			alphaThreshold;						// 038
	};
	STATIC_ASSERT(sizeof(BSTempEffectWeaponBlood) == 0x40);
}
