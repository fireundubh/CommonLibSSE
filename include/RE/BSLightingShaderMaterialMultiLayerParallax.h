#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSLightingShaderMaterialHairTint
#include "RE/BSTextureSet.h"  // NiSourceTexture
#include "RE/BSLightingShaderMaterialBase.h"  // BSLightingShaderMaterialBase


namespace RE
{
	class BSLightingShaderMaterialMultiLayerParallax : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialMultiLayerParallax;


		virtual ~BSLightingShaderMaterialMultiLayerParallax();						// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*   Create() override;						// 01
		virtual void				Copy(BSShaderMaterial* a_src) override;	// 02
		virtual void				Unk_04(void) override;					// 04
		virtual Type				GetType() const override;				// 06 - { return Type::kHairTint; }
		virtual void				Unk_0C(void) override;					// 0C
		virtual void				Unk_0D(void) override;					// 0D


		// members
		NiPointer<NiSourceTexture> spLayerTexture;		// A0
		NiPointer<NiSourceTexture> spEnvTexture;		// A8
		NiPointer<NiSourceTexture> spEnvMaskTexture;	// B0
		float fParallaxLayerThickness;					// B8
		float fParallaxRefractionScale;					// BC
		float fParallaxInnerLayerUScale;				// C0
		float fParallaxInnerLayerVScale;				// C4
		float fEnvmapScale;								// C8
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialMultiLayerParallax) == 0xD0);
}
