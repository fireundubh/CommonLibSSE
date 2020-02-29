#pragma once

#include "RE/BSTempEffect.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiAVObject;


	class BSTempEffectSPG: public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectSPG;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectSPG;


		virtual ~BSTempEffectSPG();														// 00

		virtual const NiRTTI*		GetRTTI() const override;							// 02
		virtual void				Detach() override;									// 27
		virtual bool				Update(float a_arg1) override;						// 28
		virtual TEMP_EFFECT_TYPE	GetType() const override;							// 2C - { return kSPG; }
		virtual void				SaveGame(BGSSaveGameBuffer* a_buf) override;		// 2D
		virtual void				LoadGame(BGSLoadGameBuffer* a_buf) override;		// 2E
		virtual void				FinishLoadGame(BGSLoadGameBuffer* a_buf) override;	// 2F 


		// members;
		UInt64					unk30;								// 030
		NiPointer<NiAVObject>	unk38;								// 038
		UInt64					unk40;								// 040
		UInt8					unk48;								// 048
	};
	STATIC_ASSERT(sizeof(BSTempEffectSPG) == 0x50);
}
