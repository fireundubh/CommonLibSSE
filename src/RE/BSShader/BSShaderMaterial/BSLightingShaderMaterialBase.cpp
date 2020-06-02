#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialBase.h"

#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterial.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialEnvmap.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialEye.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialFacegen.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialFacegenTint.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialGlowmap.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialHairTint.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialLODLandscape.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialLandscape.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialMultiLayerParallax.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialParallax.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialParallaxOcc.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialSnow.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTextureSet/BSTextureSet.h"


namespace RE
{
	void BSLightingShaderMaterialBase::CopyBaseMembers(BSLightingShaderMaterialBase* a_other)
	{
		texCoordOffset[0] = a_other->texCoordOffset[0];
		texCoordOffset[1] = a_other->texCoordOffset[1];
		texCoordScale[0] = a_other->texCoordScale[0];
		texCoordScale[1] = a_other->texCoordScale[1];

		if (a_other->diffuseTexture.get()) {
			diffuseTexture = a_other->diffuseTexture;
		}
		if (a_other->normalTexture.get()) {
			normalTexture = a_other->normalTexture;
		}
		if (a_other->rimSoftLightingTexture.get()) {
			rimSoftLightingTexture = a_other->rimSoftLightingTexture;
		}
		if (a_other->specularBackLightingTexture.get()) {
			specularBackLightingTexture = a_other->specularBackLightingTexture;
		}

		textureClampMode = a_other->textureClampMode;

		if (a_other->textureSet.get()) {
			textureSet = a_other->textureSet;
		}

		materialAlpha = a_other->materialAlpha;
		specularPower = a_other->specularPower;
		specularColor = a_other->specularColor;
		specularColorScale = a_other->specularColorScale;
		refractionPower = a_other->refractionPower;
		subSurfaceLightRolloff = a_other->subSurfaceLightRolloff;
		rimLightPower = a_other->rimLightPower;
	}


	BSLightingShaderMaterialBase* BSLightingShaderMaterialBase::CreateMaterial(Feature a_feature)
	{
		switch (a_feature) {
		case Feature::kDefault:
			return BSLightingShaderMaterial::CreateMaterial();
		case Feature::kEnvironmentMap:
			return BSLightingShaderMaterialEnvmap::CreateMaterial();
		case Feature::kGlowMap:
			return BSLightingShaderMaterialGlowmap::CreateMaterial();
		case Feature::kParallax:
			return BSLightingShaderMaterialParallax::CreateMaterial();
		case Feature::kFaceGen:
			return BSLightingShaderMaterialFacegen::CreateMaterial();
		case Feature::kFaceGenRGBTint:
			return BSLightingShaderMaterialFacegenTint::CreateMaterial();
		case Feature::kHairTint:
			return BSLightingShaderMaterialHairTint::CreateMaterial();
		case Feature::kParallaxOcc:
			return BSLightingShaderMaterialParallaxOcc::CreateMaterial();
		case Feature::kMultiTexLand:
		case Feature::kMultiTexLandLODBlend:
			return BSLightingShaderMaterialLandscape::CreateMaterial();
		case Feature::kLODLand:
		case Feature::kLODLandNoise:
			return BSLightingShaderMaterialLODLandscape::CreateMaterial();
		case Feature::kUnknown:
		case Feature::kMultiIndexTriShapeSnow:
			return BSLightingShaderMaterialSnow::CreateMaterial();
		case Feature::kMultilayerParallax:
			return BSLightingShaderMaterialMultiLayerParallax::CreateMaterial();
		case Feature::kEye:
			return BSLightingShaderMaterialEye::CreateMaterial();
		default:
			return nullptr;
		}
	}


	NiPointer<BSTextureSet> BSLightingShaderMaterialBase::GetTextureSet() const
	{
		return textureSet;
	}


	void BSLightingShaderMaterialBase::SetTextureSet(BSTextureSet* a_textureSet)
	{
		textureSet.reset(a_textureSet);
	}
}
