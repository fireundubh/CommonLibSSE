#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/BSGeometry/BSGeometry.h"

#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialFacegenTint.h"
#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiRTTI.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiProperty/NiShadeProperty/BSShaderProperty/BSLightingShaderProperty.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiSkinInstance/BSDismemberSkinInstance.h"


namespace RE
{
	bool BSGeometry::HasVertexFlag(NiSkinPartition::Vertex::Flags a_flag)
	{
		return (NiSkinPartition::GetVertexFlags(vertexDesc) & a_flag) == a_flag;
	}


	void BSGeometry::SwitchToFaceTint()
	{
		using Feature = BSShaderMaterial::Feature;
		using Flag = BSShaderProperty::EShaderPropertyFlag8;

		auto effect = properties[States::kEffect].get();
		if (effect) {
			auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
			if (lightingShader) {
				auto material = static_cast<BSLightingShaderMaterialBase*>(lightingShader->material);
				if (material && material->GetFeature() == Feature::kFaceGen) {
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


	void BSGeometry::UpdateDismemberPartion(bool a_enable)
	{
		if (auto skin = skinInstance.get(); skin) {
			auto dismemberSkin = netimmerse_cast<RE::BSDismemberSkinInstance*>(skin);
			if (dismemberSkin) {
				dismemberSkin->UpdateDismemberPartion(a_enable);
			}
		}
	}


	void BSGeometry::UpdateDismemberPartion(std::uint16_t a_slot, bool a_enable)
	{
		if (auto skin = skinInstance.get(); skin) {
			auto dismemberSkin = netimmerse_cast<RE::BSDismemberSkinInstance*>(skin);
			if (dismemberSkin) {
				dismemberSkin->UpdateDismemberPartion(a_slot, a_enable);
			}
		}
	}
}