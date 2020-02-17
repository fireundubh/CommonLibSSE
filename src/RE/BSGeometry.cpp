#include "RE/BSGeometry.h"

#include <functional>

#include "RE/BSLightingShaderMaterialFacegenTint.h"
#include "RE/BSLightingShaderProperty.h"
#include "RE/BSShaderMaterial.h"
#include "RE/BSShaderTextureSet.h"
#include "RE/BSVisit.h"
#include "RE/NiColor.h"
#include "RE/NiProperty.h"
#include "RE/NiRTTI.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"

namespace RE
{
	using Feature = BSShaderMaterial::Feature;

	void BSGeometry::MakeFaceTintable()
	{
		auto effect = properties[States::kEffect].get();
		if (effect) {
			auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
			if (lightingShader) {
				auto material = lightingShader->material;
				if (material && material->GetFeature() == Feature::kFaceGen) {
					auto tintedMaterial = BSLightingShaderMaterialFacegenTint::CreateFacegenTintMaterial();

					tintedMaterial->CopyBaseMaterial(static_cast<BSLightingShaderMaterialBase*>(material));

					lightingShader->SetFlags(BSShaderProperty::EShaderPropertyFlag::kFace, false);
					lightingShader->SetFlags(BSShaderProperty::EShaderPropertyFlag::kFaceGenRGBTint, true);

					lightingShader->SetMaterial(tintedMaterial, true);
					lightingShader->InitializeShader(this);

					tintedMaterial->~BSLightingShaderMaterialFacegenTint();
					free(tintedMaterial);
				}
			}
		}
	}


	void BSGeometry::SetMaterialAlpha(float a_alpha, bool a_skin)
	{
		auto effect = properties[States::kEffect].get();
		if (effect) {
			auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
			if (lightingShader) {
				auto material = static_cast<BSLightingShaderMaterialBase*>(lightingShader->material);
				if (material) {
					if (a_skin) {
						auto feature = material->GetFeature();
						if (feature == Feature::kFaceGen || feature == Feature::kFaceGenRGBTint) {
							material->materialAlpha = a_alpha;
						}
					}
					else {
						material->materialAlpha = a_alpha;
					}
				}
			}
		}
	}


	void BSGeometry::SetShaderType(BSGeometry* a_geometry)
	{
		if (!a_geometry) {
			return;
		}

		auto effect = properties[States::kEffect].get();
		auto templateEffect = a_geometry->properties[States::kEffect].get();

		if (effect && templateEffect) {
			auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
			auto templateLightingShader = netimmerse_cast<BSLightingShaderProperty*>(templateEffect);

			if (lightingShader && templateLightingShader) {
				auto material = static_cast<BSLightingShaderMaterialBase*>(lightingShader->material);
				auto templateMaterial = static_cast<BSLightingShaderMaterialBase*>(templateLightingShader->material);

				if (material && templateMaterial) {
					auto newMaterial = static_cast<BSLightingShaderMaterialBase*>(templateMaterial->Create());

					newMaterial->CopyMembers(templateMaterial);
					lightingShader->flags = templateLightingShader->flags;

					newMaterial->ClearTextures();
					newMaterial->SetTextureSet(templateMaterial->textureSet.get());

					lightingShader->SetMaterial(newMaterial, 1);
					lightingShader->InvalidateTextures(0);
					lightingShader->InitializeShader(this);
					newMaterial->~BSLightingShaderMaterialBase();
					free(newMaterial);
				}
			}
		}
	}
}