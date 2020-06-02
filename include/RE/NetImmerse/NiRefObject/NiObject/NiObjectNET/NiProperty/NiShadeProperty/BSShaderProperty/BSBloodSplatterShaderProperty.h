#pragma once

#include "RE/BSShaderProperty.h"
#include "RE/BSTArray.h"
#include "RE/NiColor.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class NiSourceTexture;


	class BSBloodSplatterShaderProperty : public BSShaderProperty
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSBloodSplatterShaderProperty;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSBloodSplatterShaderProperty;


		enum : UInt32
		{
			kBloodColor = 0,
			kBloodAlpha,
			kFlareColor,

			kTotal
		};


		virtual ~BSBloodSplatterShaderProperty();  // 00

		// override (BSShaderProperty)
		virtual const NiRTTI*	 GetRTTI() const override;							 // 02
		virtual NiObject*		 CreateClone(NiCloningProcess& a_cloning) override;	 // 17
		virtual void			 Unk_2A(void) override;								 // 2A
		virtual void			 Unk_33(void) override;								 // 33
		virtual void			 Unk_35(void) override;								 // 35 - { return 12 }
		virtual NiSourceTexture* GetPrimaryTexture() override;						 // 37 - { return bloodColorTexture; }


		// members
		NiPointer<NiSourceTexture> bloodTextures[kTotal];  // 088
		SInt32					   textureClampMode;	   // 0A0
		float*					   alphaSource;			   // 0A8
	};
	STATIC_ASSERT(sizeof(BSBloodSplatterShaderProperty) == 0xB0);
}