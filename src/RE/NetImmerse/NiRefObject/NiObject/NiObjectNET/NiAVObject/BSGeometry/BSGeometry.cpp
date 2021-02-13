#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/BSGeometry/BSGeometry.h"

#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialFacegenTint.h"
#include "RE/NetImmerse/NiRTTI.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiProperty/NiShadeProperty/BSShaderProperty/BSLightingShaderProperty.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiSkinInstance/BSDismemberSkinInstance.h"


namespace RE
{
	bool BSGeometry::HasVertexFlag(NiSkinPartition::Vertex::Flags a_flag) const
	{
		return (NiSkinPartition::GetVertexFlags(vertexDesc) & a_flag) == a_flag;
	}


	void BSGeometry::SwitchToFaceTint()
	{
		using Feature = BSShaderMaterial::Feature;
		using Flag = BSShaderProperty::EShaderPropertyFlag8;

		auto effect = properties[States::kEffect];
		auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect.get());
		if (lightingShader) {
			auto material = static_cast<BSLightingShaderMaterialBase*>(lightingShader->material);
			if (material && material->GetFeature() == Feature::kFaceGen) {
				auto facegenTint = BSLightingShaderMaterialFacegenTint::CreateMaterial();
				if (facegenTint) {
					facegenTint->CopyBaseMembers(material);
					lightingShader->SetFlags(Flag::kFace, false);
					lightingShader->SetFlags(Flag::kFaceGenRGBTint, true);
					lightingShader->SetMaterial(facegenTint, true);
					lightingShader->InitializeShader(this);
					facegenTint->~BSLightingShaderMaterialFacegenTint();
					free(facegenTint);
				}
			}
		}
	}
}