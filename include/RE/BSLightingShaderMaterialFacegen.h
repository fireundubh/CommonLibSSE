#pragma once

#include "RE/BSLightingShaderMaterialBase.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiSourceTexture;


	class BSLightingShaderMaterialFacegen : public BSLightingShaderMaterialBase
	{
	public:
		inline static const void* RTTI = RTTI_BSLightingShaderMaterialFacegen;


		virtual ~BSLightingShaderMaterialFacegen();										// 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial*	Create() override;									// 01
		virtual void				CopyMembers(BSShaderMaterial* a_other) override;	// 02
		virtual UInt32				ComputeCRC32(void) override;						// 04
		virtual Feature				GetFeature() const override;						// 06 - { return Feature::kFaceGen; }
		virtual void				OnLoadTextureSet(void) override;					// 08
		virtual void				ClearTextures(void) override;						// 09
		virtual void				ReceiveValuesFromRootMaterial(void) override;		// 0A
		virtual void				GetTextures(void) override;							// 0B


		// members
		NiPointer<NiSourceTexture>	tintTexture;		// A0
		NiPointer<NiSourceTexture>	detailTexture;		// A8
		NiPointer<NiSourceTexture>	subsurfaceTexture;	// B0
	};
	STATIC_ASSERT(sizeof(BSLightingShaderMaterialFacegen) == 0xB8);
}
