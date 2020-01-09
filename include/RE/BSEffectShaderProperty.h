#pragma once

#include "RE/BSShaderProperty.h"


namespace RE
{
	class BSEffectShaderProperty : public BSShaderProperty
	{
	public:
		inline static const void* RTTI = RTTI_BSEffectShaderProperty;
		inline static const void* Ni_RTTI = NiRTTI_BSEffectShaderProperty;


		virtual ~BSEffectShaderProperty();											// 00

		// override (BSShaderProperty)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning) override;	// 17 - { return 0; }
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18
		virtual void			LinkObject(NiStream& a_stream) override;			// 19 - { NiShadeProperty::LinkObject(a_stream); }
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B
		virtual void			PostLinkObject(NiStream& a_stream) override;		// 1E - { NiObjectNET::PostLinkObject(a_stream); }
		virtual void			Unk_27(void) override;								// 27 - { return 1; }

		// add
		virtual void			Unk_2A(void);										// 2A
		virtual void			Unk_2B(void);										// 2B - { return 0; }
		virtual void			Unk_31(void);										// 31 - { return; }
		virtual void			Unk_32(void);										// 32 - { return 1.0; }
		virtual void			Unk_33(void);										// 33 - { return 1; }
		virtual void			Unk_35(void);										// 35 - { return 0; }
		virtual void			Unk_37(void);										// 37 - { return 0; }
		virtual void			Unk_3B(void);										// 3B - { return; }
		virtual void			Unk_3C(void);										// 3C - { return 1; }
		virtual void			Unk_3E(void);										// 3E - { return 1; }


		// members
		UInt64	unk88;	// 88
		UInt64	unk90;	// 90
		UInt64	unk98;	// 98
	};
	STATIC_ASSERT(sizeof(BSEffectShaderProperty) == 0xA0);
}
