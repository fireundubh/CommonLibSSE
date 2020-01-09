#pragma once

#include "RE/BSTempEffect.h"

class NiAVObject;

namespace RE
{

	class BSTempEffectSPG: public BSTempEffect
	{
	public:
		inline static const void* RTTI = RTTI_BSTempEffectSPG;
		inline static const void* Ni_RTTI = NiRTTI_BSTempEffectSPG;

		virtual ~BSTempEffectSPG();												// 00

		virtual const NiRTTI*	GetRTTI() const override;						// 02
		virtual void			Unk_27(void) override;							// 27
		virtual void			Unk_28(void) override;							// 28
		virtual void			Unk_2C(void) override;							// 2C - { return 6; }
		virtual void			SaveEffect(BGSSaveGameBuffer* a_buf) override;	// 2D
		virtual void			LoadEffect(BGSLoadGameBuffer* a_buf) override;	// 2E
		virtual void			Unk_2F(void) override;							// 2F 

		// members;
		UInt64			unk30;								// 030
		NiAVObject*		unk38;								// 038
		UInt64			unk40;								// 040
		UInt8			unk48;								// 048
	};
	STATIC_ASSERT(sizeof(BSTempEffectSPG) == 0x50);
}
