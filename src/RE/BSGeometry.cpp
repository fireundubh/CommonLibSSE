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
	void BSGeometry::SetMaterialAlpha(float a_alpha, bool a_skin)
	{
		using Feature = BSShaderMaterial::Feature;

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
					} else {
						material->materialAlpha = a_alpha;
					}
				}
			}
		}
	}


	void BSGeometry::UpdateFaceGenTint(const NiColor& a_color)
	{
		using Feature = BSShaderMaterial::Feature;
		using Flag = BSShaderProperty::EShaderPropertyFlag;

		auto effect = properties[States::kEffect].get();
		if (effect) {
			auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
			if (lightingShader) {
				auto material = lightingShader->material;
				if (material) {
					if (material->GetFeature() == Feature::kFaceGen) {
						auto facegenTint = BSLightingShaderMaterialFacegenTint::CreateMaterial();
						facegenTint->CopyBaseMaterial(static_cast<BSLightingShaderMaterialBase*>(material));
						lightingShader->SetFlags(0x0A, false);
						lightingShader->SetFlags(0x15, true);
						facegenTint->tintColor = a_color;
						lightingShader->SetMaterial(facegenTint, true);
						lightingShader->InitializeGeometry(this);
						lightingShader->InitializeShader(this);
						facegenTint->~BSLightingShaderMaterialFacegenTint();
						free(facegenTint);
					} else if (material->GetFeature() == Feature::kFaceGenRGBTint) {
						auto facegenTint = static_cast<BSLightingShaderMaterialFacegenTint*>(material);
						facegenTint->tintColor = a_color;
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