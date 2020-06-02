#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/BSGeometry/BSGeometry.h"

#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialFacegenTint.h"
#include "RE/BSShader/BSShaderMaterial/BSShaderMaterial.h"
#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiRTTI.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiProperty/NiShadeProperty/BSShaderProperty/BSLightingShaderProperty.h"


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
				auto material = static_cast<BSLightingShaderMaterialBase*>(lightingShader->material);
				if (material) {
					if (material->GetFeature() == Feature::kFaceGen) {
						auto facegenTint = BSLightingShaderMaterialFacegenTint::CreateMaterial();
						if (facegenTint) {
							facegenTint->CopyBaseMembers(material);
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