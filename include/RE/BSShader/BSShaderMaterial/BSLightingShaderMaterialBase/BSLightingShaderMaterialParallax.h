#pragma once

#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialBase.h"


namespace RE
{
	class NiSourceTexture;


	class BSLightingShaderMaterialParallax : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialParallax;


		virtual ~BSLightingShaderMaterialParallax();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;																												 // 01
		virtual void			  CopyMembers(BSShaderMaterial* a_src) override;																					 // 02
		virtual std::uint32_t	  ComputeCRC32(void) override;																										 // 04
		virtual Feature			  GetFeature() const override;																										 // 06 - { return Type::kParallax; }
		virtual void			  OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet) override;														 // 08
		virtual void			  ClearTextures() override;																											 // 09
		virtual void			  ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN) override;	 // 0A
		virtual void			  GetTextures(void) override;																										 // 0B

		static BSLightingShaderMaterialParallax* CreateMaterial();


		// members
		NiPointer<NiSourceTexture> heightTexture;  // A0


	private:
		BSLightingShaderMaterialParallax* ctor();
	};
	static_assert(sizeof(BSLightingShaderMaterialParallax) == 0xA8);
}
