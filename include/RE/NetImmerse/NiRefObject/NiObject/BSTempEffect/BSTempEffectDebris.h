#pragma once

#include "RE/BSTempEffect.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiAVObject;


	class BSTempEffectDebris : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectDebris;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectDebris;


		virtual ~BSTempEffectDebris();	// 00

		virtual const NiRTTI*	 GetRTTI() const override;		 // 02
		virtual bool			 Update(float a_arg1) override;	 // 28
		virtual NiAVObject*		 Get3D() const override;		 // 29
		virtual TEMP_EFFECT_TYPE GetType() const;				 // 2C - { return kDebris; }


		// members;
		NiPointer<NiAVObject> debris3D;		   // 030
		const char*			  debrisFileName;  // 038
		UInt8				  unk40;		   // 040
		UInt8				  unk41;		   // 041
		UInt8				  pad42;		   // 042
		UInt8				  pad43;		   // 043
		UInt32				  pad44;		   // 044
	};
	STATIC_ASSERT(sizeof(BSTempEffectDebris) == 0x48);
}