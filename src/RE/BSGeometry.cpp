#include "RE/BSGeometry.h"

#include "RE/BSLightingShaderMaterialFacegenTint.h"
#include "RE/BSLightingShaderProperty.h"
#include "RE/BSShaderMaterial.h"
#include "RE/NiRTTI.h"


namespace RE
{
	void BSGeometry::MakeFaceGenTintable()
	{
		using Feature = BSShaderMaterial::Feature;
		using Flag = BSShaderProperty::EShaderPropertyFlag8;

		auto effect = properties[States::kEffect].get();
		if (effect) {
			auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
			if (lightingShader) {
				auto material = lightingShader->material;
				if (material) {
					if (material->GetFeature() == Feature::kFaceGen) {
						auto facegenTint = BSLightingShaderMaterialFacegenTint::CreateMaterial();
						if (facegenTint) {
							facegenTint->CopyBaseMaterial(static_cast<BSLightingShaderMaterialBase*>(material));
							lightingShader->SetFlags(Flag::kFace, false);
							lightingShader->SetFlags(Flag::kFaceGenRGBTint, true);
							lightingShader->SetMaterial(facegenTint, true);
							lightingShader->InitializeGeometry(this);
							lightingShader->InitializeShader(this);
							facegenTint->~BSLightingShaderMaterialFacegenTint();
							free(facegenTint);
						}
					}
				}
			}
		}
	}

}