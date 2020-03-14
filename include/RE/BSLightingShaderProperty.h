#pragma once

#include "RE/BSShaderProperty.h"
#include "RE/BSTArray.h"


namespace RE
{
	class NiColor;
	class BSLightingShaderMaterialBase;


	class BSLightingShaderProperty : public BSShaderProperty
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderProperty;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSLightingShaderProperty;


		struct Data
		{
			UInt64 unk00;  // 00
			UInt64 unk08;  // 08
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);


		virtual ~BSLightingShaderProperty();  // 00

		// override (BSShaderProperty)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C - { return false; }
		virtual void		  PostLinkObject(NiStream& a_stream) override;		  // 1E
		virtual UInt8				InitializeGeometry(BSGeometry* a_geometry) override;	// 27 
		virtual UInt8				InitializeShader(BSGeometry* a_geometry) override;		// 28 
		virtual void		  Unk_2A(void) override;							  // 2A
		virtual void		  Unk_2B(void) override;							  // 2B
		virtual void		  Unk_2C(void) override;							  // 2C
		virtual void		  Unk_2D(void) override;							  // 2D
		virtual void		  Unk_2F(void) override;							  // 2F
		virtual bool				DoIsCopy(BSShaderProperty* a_other) override;			// 30
		virtual void				SetMaterialAlpha(float a_alpha) override;				// 31
		virtual float				GetMaterialAlpha() override;							// 32
		virtual void		  Unk_33(void) override;							  // 33
		virtual void		  Unk_34(void) override;							  // 34
		virtual void		  Unk_35(void) override;							  // 35 - { return 11; }
		virtual NiSourceTexture*	GetPrimaryTexture() override;							// 37 - { return diffuseTexture }
		virtual bool		  AcceptsEffectData() const override;				  // 39 - { return !(flags & kRefraction) && !(flags & kTempRefraction); }
		virtual void		  Unk_3B(void) override;							  // 3B
		virtual void		  Unk_3D(void) override;							  // 3D
		virtual void		  Unk_3E(void) override;							  // 3E - { return 2; }

		void	InvalidateTextures(UInt32 a_unk1);


		// members
		Data			unk088[3];		// 088
		Data			unk0B8;			// 0B8
		Data			unk0C8;			// 0C8
		Data			unk0D8;			// 0D8
		UInt64			unk0E8;			// 0E8
		NiColor*		emissiveColor;	// 0F0
		float			emissiveMult;	// 0F8
		UInt32			unk0FC;			// 0FC
		float			unk100;			// 100
		float			unk104;			// 100
		UInt32			unk108;			// 108
		UInt32			unk10C;			// 10C
		UInt64			unk110;			// 110
		UInt64			unk118;			// 118
		UInt64			unk120;			// 120
		UInt64			unk128;			// 128
		UInt64			unk130;			// 130
		BSTArray<void*> unk138;			// 138
		UInt64			unk150;			// 150
		UInt8			unk158;			// 158
	};
	STATIC_ASSERT(sizeof(BSLightingShaderProperty) == 0x160);
}
