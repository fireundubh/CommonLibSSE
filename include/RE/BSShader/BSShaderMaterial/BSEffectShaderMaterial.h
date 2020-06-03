#pragma once

#include "RE/BSShader/BSShaderMaterial/BSShaderMaterial.h"
#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class NiSourceTexture;


	class BSEffectShaderMaterial : public BSShaderMaterial
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSEffectShaderMaterial;


		virtual ~BSEffectShaderMaterial();	// 00

		// override (BSShaderMaterial)
		virtual BSShaderMaterial* Create() override = 0;							// 01
		virtual void			  CopyMembers(BSShaderMaterial* a_other) override;	// 02
		virtual bool			  DoIsCopy(BSShaderMaterial* a_other) override;		// 03
		virtual UInt32			  ComputeCRC32(void) override;						// 04
		virtual BSShaderMaterial* GetDefault() override;							// 05
		virtual Type			  GetType() const override;							// 07 - { return Type::kEffect; }


		// members
		float					   falloffStartAngle;	  // 38
		float					   falloffStopAngle;	  // 3C
		float					   falloffStartOpacity;	  // 40
		float					   falloffStopOpacity;	  // 44
		NiColorA				   baseColor;			  // 48
		NiPointer<NiSourceTexture> sourceTexture;		  // 58
		NiPointer<NiSourceTexture> greyscaleTexture;	  // 60
		float					   softFalloffDepth;	  // 68
		float					   baseColorScale;		  // 6C
		BSFixedString			   sourceTexturePath;	  // 70
		BSFixedString			   greyscaleTexturePath;  // 78
		UInt8					   effectClampMode;		  // 80
		UInt8					   unk81;				  // 81
	};
	STATIC_ASSERT(sizeof(BSEffectShaderMaterial) == 0x88);
}
