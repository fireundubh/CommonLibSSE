#pragma once

#include "RE/BSTArray.h"
#include "RE/ReferenceEffect.h"


namespace RE
{
	class TESBoundObject;
	class TESEffectShader;
	class BSEffectShaderData;

	class ShaderReferenceEffect : public ReferenceEffect
	{
	public:
		inline static const void* RTTI = RTTI_ShaderReferenceEffect;
		inline static const void* Ni_RTTI = NiRTTI_ShaderReferenceEffect;


		struct Data048
		{
			UInt64	unk00;	// 00
			UInt64	unk08;	// 08
		};
		STATIC_ASSERT(sizeof(Data048) == 0x10);


		struct Data090
		{
			UInt64	unk00;	// 00 - smart ptr
			UInt64	unk08;	// 08 - smart ptr
		};
		STATIC_ASSERT(sizeof(Data090) == 0x10);


		virtual ~ShaderReferenceEffect();										// 00

		// override (ReferenceEffect)
		virtual const NiRTTI*	GetRTTI() const override;						// 02
		virtual void			Unk_28(void) override;							// 28
		virtual void			Unk_29(void) override;							// 29 - { return unk0F8; }
		virtual void			Unk_2C(void) override;							// 2C - { return 10; }
		virtual void			SaveEffect(BGSSaveGameBuffer* a_buf) override;	// 2D
		virtual void			LoadEffect(BGSLoadGameBuffer* a_buf) override;	// 2E
		virtual void			Unk_2F(void) override;							// 2F - { return ReferenceEffect::Unk_2F(); }
		virtual void			Unk_30(void) override;							// 30 - { return (unk130 >> 1) & 1; }
		virtual void			Unk_31(void) override;							// 31
		virtual void			Unk_32(void) override;							// 32 - { return 1; }
		virtual void			Unk_33(void) override;							// 33
		virtual void			Unk_34(void) override;							// 34 - { if (unk110) ++unk134; }
		virtual void			Unk_35(void) override;							// 35
		virtual void			Unk_36(void) override;							// 36
		virtual void			Unk_37(void) override;							// 37
		virtual void			Unk_38(void) override;							// 38
		virtual void			Unk_39(void) override;							// 39
		virtual void			Unk_3B(void) override;							// 3B
		virtual void			Unk_3C(void) override;							// 3C
		virtual void			Unk_3E(void) override;							// 3E


		// members
		BSTArray<Data048>			unk048;					// 048
		BSTArray<void*>				unk060;					// 060 - smart ptrs
		BSTArray<void*>				unk078;					// 078
		BSTArray<Data090>			unk090;					// 090
		BSTArray<void*>				unk0A8;					// 0A8 - smart ptrs
		BSSoundHandle				soundHandle;			// 0C0
		UInt32						unk0C8;					// 0C8
		NiPointer<NiTexture>		particleShaderTexture;	// 0D0 - smart ptr
		NiPointer<NiTexture>		particlePaletteTexture;	// 0D8 - smart ptr
		NiPointer<NiTexture>		fillTexture;			// 0E0
		NiPointer<NiTexture>		holesTexture;			// 0E8
		NiPointer<NiTexture>		paletteTexture;			// 0F0
		NiNode*						particleShaderGeometry; // 0F8 - smart ptr
		TESBoundObject*				unk100;					// 100
		TESEffectShader*			effectShader;			// 108
		BSEffectShaderData*			effectShaderData;		// 110 
		void*						unk118;					// 118 - smart ptr
		float						unk120;					// 120
		float						unk124;					// 124 - 1.0f
		float						unk128;					// 128 - 1.0f
		UInt32						unk12C;					// 12C 
		UInt32						unk130;					// 130 - flags
		UInt32						unk134;					// 134
	};
	STATIC_ASSERT(sizeof(ShaderReferenceEffect) == 0x138);

	static_assert(offsetof(ShaderReferenceEffect, effectShader) >= 0x0108, "shader is too early!");
	static_assert(offsetof(ShaderReferenceEffect, effectShader) <= 0x0108, "shader is too late!");
}
