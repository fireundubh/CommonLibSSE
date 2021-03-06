#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/BSShader/BSShaderMaterial/BSShaderMaterial.h"
#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiTexture/NiSourceTexture.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class BSTextureSet;
	class NiStream;


	class BSLightingShaderMaterialBase : public BSShaderMaterial
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterialBase;


		virtual ~BSLightingShaderMaterialBase();  // 00

		// override (BSShaderMaterial)
		virtual BSShaderMaterial* Create() override = 0;							// 01
		virtual void			  CopyMembers(BSShaderMaterial* a_other) override;	// 02
		virtual bool			  DoIsCopy(BSShaderMaterial* a_other) override;		// 03
		virtual std::uint32_t	  ComputeCRC32(void) override;						// 04
		virtual BSShaderMaterial* GetDefault() override;							// 05
		virtual Feature			  GetFeature() const override;						// 06 - { return Feature::kDefault; }
		virtual Type			  GetType() const override;							// 07 - { return Type::kLighting; }

		// add
		virtual void OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet);													   // 08
		virtual void ClearTextures();																										   // 09
		virtual void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN);  // 0A
		virtual void GetTextures(void);																										   // 0B
		virtual void SaveBinary(NiStream& a_stream);																						   // 0C
		virtual void LoadBinary(NiStream& a_stream);																						   // 0D

		static BSLightingShaderMaterialBase* CreateMaterial(Feature a_feature);

		void					CopyBaseMembers(BSLightingShaderMaterialBase* a_other);
		NiPointer<BSTextureSet> GetTextureSet() const;
		void					SetTextureSet(BSTextureSet* a_textureSet);


		// members
		NiColor					   specularColor;					// 38
		std::uint32_t			   pad44;							// 44
		NiPointer<NiSourceTexture> diffuseTexture;					// 48
		std::int32_t			   diffuseRenderTargetSourceIndex;	// 50
		std::uint32_t			   pad54;							// 54
		NiPointer<NiSourceTexture> normalTexture;					// 58
		NiPointer<NiSourceTexture> rimSoftLightingTexture;			// 60
		NiPointer<NiSourceTexture> specularBackLightingTexture;		// 68
		std::int32_t			   textureClampMode;				// 70
		std::int32_t			   pad74;							// 70
		NiPointer<BSTextureSet>	   textureSet;						// 78
		float					   materialAlpha;					// 80
		float					   refractionPower;					// 84
		float					   specularPower;					// 88
		float					   specularColorScale;				// 8C
		float					   subSurfaceLightRolloff;			// 90
		float					   rimLightPower;					// 94
		mutable BSSpinLock		   unk98;							// 98 - lock?
	};
	static_assert(sizeof(BSLightingShaderMaterialBase) == 0xA0);
}
