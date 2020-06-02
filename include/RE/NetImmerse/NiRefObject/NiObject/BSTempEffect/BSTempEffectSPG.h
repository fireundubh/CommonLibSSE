#pragma once

#include "RE/BSTempEffect.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BGSShaderParticleGeometryData;
	class NiAVObject;


	class BSTempEffectSPG : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectSPG;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectSPG;


		virtual ~BSTempEffectSPG();	 // 00

		virtual const NiRTTI*	 GetRTTI() const override;							 // 02
		virtual void			 Detach() override;									 // 27
		virtual bool			 Update(float a_arg1) override;						 // 28
		virtual TEMP_EFFECT_TYPE GetType() const override;							 // 2C - { return kSPG; }
		virtual void			 SaveGame(BGSSaveGameBuffer* a_buf) override;		 // 2D
		virtual void			 LoadGame(BGSLoadGameBuffer* a_buf) override;		 // 2E
		virtual void			 FinishLoadGame(BGSLoadGameBuffer* a_buf) override;	 // 2F


		// members;
		BGSShaderParticleGeometryData* data;   // 30
		NiPointer<NiAVObject>		   unk38;  // 38
		float						   unk40;  // 40
		UInt32						   unk44;  // 40
		UInt8						   unk48;  // 45
		UInt8						   pad49;  // 49
		UInt16						   pad4A;  // 4A
		UInt32						   pad4C;  // 4C
	};
	STATIC_ASSERT(sizeof(BSTempEffectSPG) == 0x50);
}
