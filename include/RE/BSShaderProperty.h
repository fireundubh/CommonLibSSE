#pragma once

#include "RE/NiShadeProperty.h"


namespace RE
{
	class BSLightingShaderMaterialBase;


	class BSShaderProperty : public NiShadeProperty
	{
	public:
		inline static const void* RTTI = RTTI_BSShaderProperty;
		inline static const void* Ni_RTTI = NiRTTI_BSShaderProperty;


		enum class ShaderFlag : UInt64
		{
			kSpecular = 0x0,
			kSkinned = 0x1,
			kTempRefraction = 0x2,
			kVertexAlpha = 0x3,
			kGrayscaleToPaletteColor = 0x4,
			kGrayscaleToPaletteAlpha = 0x5,
			kFalloff = 0x6,
			kEnvironmentMapping = 0x7,
			kReceiveShadows = 0x8,
			kCastShadows = 0x9,
			kFacegenDetailMap = 0xA,
			kParallax = 0xB,
			kModelSpaceNormals = 0xC,
			kNonProjectiveShadows = 0xD,
			kLandscape = 0xE,
			kRefraction = 0xF,
			kRefractionFire = 0x10,
			kEyeEnvironmentMapping = 0x11,
			kHairSoftLighting = 0x12,
			kScreendoorAlphaFade = 0x13,
			kLocalmapHideSecret = 0x14,
			kFaceGenRGBTint = 0x15,
			kOwnEmit = 0x16,
			kProjectedUV = 0x17,
			kMultipleTextures = 0x18,
			kRemappableTextures = 0x19,
			kDecal = 0x1A,
			kDynamicDecal = 0x1B,
			kParallaxOcclusion = 0x1C,
			kExternalEmittance = 0x1D,
			kSoftEffect = 0x1E,
			kZBufferTest = 0x1F,
			kZBufferWrite = 0x20,
			kLODLandscape = 0x21,
			kLODObjects = 0x22,
			kNoFade = 0x23,
			kTwoSided = 0x24,
			kVertexColors = 0x25,
			kGlowMap = 0x26,
			kAssumeShadowmask = 0x27,
			kCharacterLighting = 0x28,
			kMultiIndexSnow = 0x29,
			kVertexLighting = 0x2A,
			kUniformScale = 0x2B,
			kFitSlope = 0x2C,
			kBillboard = 0x2D,
			kNoLODLandBlend = 0x2E,
			kEnvmapLightFade = 0x2F,
			kWireframe = 0x30,
			kWeaponBlood = 0x31,
			kHideOnLocalMap = 0x32,
			kPremultAlpha = 0x33,
			kCloudLOD = 0x34,
			kAnisotropicLighting = 0x35,
			kNoTransparencyMultisampling = 0x36,
			kUnused01 = 0x37,
			kMultiLayerParallax = 0x38,
			kSoftLighting = 0x39,
			kRimLighting = 0x3A,
			kBackLighting = 0x3B,
			kSnow = 0x3C,
			kTreeAnim = 0x3D,
			kEffectLighting = 0x3E,
			kHDLODObjects = 0x3F,

			kCount = 0x40
		};


		virtual ~BSShaderProperty();	// 00

		// override (NiShadeProperty)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning) override;	// 17 - { return 0; }
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18
		virtual void			LinkObject(NiStream& a_stream) override;			// 19 - { NiShadeProperty::LinkObject(a_stream); }
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A - { return NiShadeProperty::RegisterStreamables(a_stream); }
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B
		virtual bool			IsEqual(NiObject* a_object) override;				// 1C - { return false; }
		virtual void			PostLinkObject(NiStream& a_stream) override;		// 1E - { NiObjectNET::PostLinkObject(a_stream); }
		virtual void			Unk_27(void) override;								// 27 - { return 1; }
		virtual void			Unk_29(void) override;								// 29

		// add
		virtual void			Unk_2A(void) = 0;									// 2A
		virtual void			Unk_2B(void);										// 2B - { return 0; }
		virtual void			Unk_2C(void);										// 2C - { return 0; }
		virtual void			Unk_2D(void);										// 2D - { return 0; }
		virtual void			Unk_2E(void);										// 2E - { return 1; }
		virtual void			Unk_2F(void);										// 2F - { return 0; }
		virtual void			Unk_30(void);										// 30
		virtual void			Unk_31(void);										// 31 - { return; }
		virtual void			Unk_32(void);										// 32 - { return 1.0; }
		virtual void			Unk_33(void);										// 33 - { return 1; }
		virtual void			Unk_34(void);										// 34
		virtual void			Unk_35(void);										// 35 - { return 0; }
		virtual void			Unk_36(void);										// 36 - { return 0; }
		virtual void			Unk_37(void);										// 37 - { return 0; }
		virtual void			Unk_38(void);										// 38 - { return 0; }
		virtual void			Unk_39(void);										// 39 - { return 0; }
		virtual void			Unk_3A(void);										// 3A - { return; }
		virtual void			Unk_3B(void);										// 3B - { return; }
		virtual void			Unk_3C(void);										// 3C - { return 0; }
		virtual void			Unk_3D(void);										// 3D - { return 0; }
		virtual void			Unk_3E(void);										// 3E - { return 0; }


		// members
		float							unk30;			// 30 - 1.0f
		UInt32							unk34;			// 34
		ShaderFlag						shaderFlags;	// 38
		void*							unk40;			// 40
		UInt64							unk48;			// 48
		void*							unk50;			// 50
		UInt64							unk58;			// 58
		UInt64							unk60;			// 60
		void*							unk68;			// 68 - smart ptr
		UInt64							unk70;			// 70
		BSLightingShaderMaterialBase*	material;		// 78
		UInt64							unk80;			// 80
	};
	STATIC_ASSERT(sizeof(BSShaderProperty) == 0x88);
}
