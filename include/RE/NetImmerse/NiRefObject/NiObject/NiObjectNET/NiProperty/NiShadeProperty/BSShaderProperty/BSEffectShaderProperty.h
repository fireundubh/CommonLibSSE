#pragma once

#include "RE/BSShaderProperty.h"


namespace RE
{
	class NiColor;


	class BSEffectShaderProperty : public BSShaderProperty
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSEffectShaderProperty;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSEffectShaderProperty;


		virtual ~BSEffectShaderProperty();	// 00

		// override (BSShaderProperty)
		virtual const NiRTTI*	 GetRTTI() const override;							   // 02
		virtual NiObject*		 CreateClone(NiCloningProcess& a_cloning) override;	   // 17 - { return 0; }
		virtual void			 LoadBinary(NiStream& a_stream) override;			   // 18
		virtual void			 LinkObject(NiStream& a_stream) override;			   // 19 - { NiShadeProperty::LinkObject(a_stream); }
		virtual void			 SaveBinary(NiStream& a_stream) override;			   // 1B
		virtual void			 PostLinkObject(NiStream& a_stream) override;		   // 1E - { NiObjectNET::PostLinkObject(a_stream); }
		virtual bool			 InitializeGeometry(BSGeometry* a_geometry) override;  // 27 - { return 1; }
		virtual void			 Unk_2A(void) override;								   // 2A
		virtual void			 Unk_2B(void) override;								   // 2B - { return 0; }
		virtual void			 SetMaterialAlpha(float a_alpha) override;			   // 31 - { baseColor->alpha = a_alpha }
		virtual float			 GetMaterialAlpha() override;						   // 32 - { baseColor->alpha }
		virtual void			 Unk_33(void) override;								   // 33
		virtual void			 Unk_35(void) override;								   // 35 - { return 1; }
		virtual NiSourceTexture* GetPrimaryTexture() override;						   // 37 - { return unk58 }
		virtual void			 Unk_3B(void) override;								   // 3B - { return; }
		virtual void			 Unk_3C(void) override;								   // 3C - { return 1; }
		virtual void			 Unk_3E(void) override;								   // 3E - { return 1; }


		// members
		NiColor* unk88;	 // 88
		UInt64	 unk90;	 // 90
		UInt64	 unk98;	 // 98
	};
	STATIC_ASSERT(sizeof(BSEffectShaderProperty) == 0xA0);
}
