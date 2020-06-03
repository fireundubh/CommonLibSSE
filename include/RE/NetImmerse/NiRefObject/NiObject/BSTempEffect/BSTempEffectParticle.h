#pragma once

#include "RE/BSAudio/BSSoundHandle.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/NetImmerse/NiMatrix3.h"
#include "RE/NetImmerse/NiPoint3.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/BSTempEffect.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiTransform.h"


namespace RE
{
	class BGSParticleObjectCloneTask;
	class NiAVObject;
	class NiNode;


	class BSTempEffectParticle : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectParticle;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectParticle;


		virtual ~BSTempEffectParticle();  // 00

		virtual const NiRTTI*	 GetRTTI() const override;		 // 02
		virtual void			 Detach() override;				 // 27
		virtual bool			 Update(float a_arg1) override;	 // 28
		virtual TEMP_EFFECT_TYPE GetType() const override;		 // 2C - { return kParticle; }


		// members
		NiPointer<NiAVObject>						particle3D;	 // 30
		BSTSmartPointer<BGSParticleObjectCloneTask> cloneTask;	 // 38
		const char*									modelName;	 // 40
		NiPointer<NiNode>							unk48;		 // 48	- BSMultiBoundNiNode[4]
		NiTransform									transform;	 // 50
		UInt32										unk84;		 // 84
		NiPointer<NiAVObject>						unk88;		 // 88
		NiTransform									unk90;		 // 90
		UInt32										padC4;		 // C4
		UInt64										unkC8;		 // C8
		BSSoundHandle								unkD0;		 // D0
		BSSoundHandle								unkDC;		 // DC
		UInt8										unkE8;		 // E8
		UInt8										padE9;		 // E9
		UInt16										unkEA;		 // EA
		UInt32										unkEC;		 // EC
	};
	STATIC_ASSERT(sizeof(BSTempEffectParticle) == 0xF0);
};