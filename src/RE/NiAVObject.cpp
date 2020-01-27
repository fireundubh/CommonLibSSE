#include "RE/NiAVObject.h"
#include "RE/NiNode.h"

#include <functional>

#include "RE/BSGeometry.h"
#include "RE/BSLightingShaderMaterialFacegenTint.h"
#include "RE/BSLightingShaderMaterialHairTint.h"
#include "RE/BSLightingShaderProperty.h"
#include "RE/BSShaderMaterial.h"
#include "RE/BSVisit.h"
#include "RE/NiColor.h"
#include "RE/NiNode.h"
#include "RE/NiProperty.h"
#include "RE/NiRTTI.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	bool NiAVObject::SetMotionType(UInt32 a_motionType, bool a_arg2, bool a_arg3, bool a_allowActivate)
	{
		using func_t = function_type_t<decltype(&NiAVObject::SetMotionType)>;
		REL::Offset<func_t*> func(Offset::NiAVObject::SetMotionType);
		return func(this, a_motionType, a_arg2, a_arg3, a_allowActivate);
	}


	void NiAVObject::Update(NiUpdateData& a_data)
	{
		using func_t = function_type_t<decltype(&NiAVObject::Update)>;
		REL::Offset<func_t*> func(Offset::NiAVObject::Update);
		return func(this, a_data);
	}


	void NiAVObject::UpdateBodyTint(const NiColor& a_color)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl
		{
			using State = BSGeometry::States;
			using Feature = BSShaderMaterial::Feature;

			auto effect = a_geometry->properties[State::kEffect].get();
			if (effect) {
				auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
				if (lightingShader) {
					auto material = lightingShader->material;
					if (material && material->GetFeature() == Feature::kFaceGenRGBTint) {
						auto facegenTint = static_cast<BSLightingShaderMaterialFacegenTint*>(material);
						facegenTint->tintColor = a_color;
					}
				}
			}

			return BSVisit::BSVisitControl::kStop;
		});
	}


	void NiAVObject::UpdateHairColor(const NiColor& a_color)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl
		{
			using State = BSGeometry::States;
			using Feature = BSShaderMaterial::Feature;

			auto effect = a_geometry->properties[State::kEffect].get();
			if (effect) {
				auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
				if (lightingShader) {
					auto material = lightingShader->material;
					if (material && material->GetFeature() == Feature::kHairTint) {
						auto hairTint = static_cast<BSLightingShaderMaterialHairTint*>(material);
						hairTint->tintColor = a_color;
					}
				}
			}

			return BSVisit::BSVisitControl::kStop;
		});
	}


	TESObjectREFR* NiAVObject::GetOwner()
	{
		if (userData)
		{
			return userData;
		}

		if (parent)
		{
			parent->GetOwner();
		}

		return nullptr;
	}
}
