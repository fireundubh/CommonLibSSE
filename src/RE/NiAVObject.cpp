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
	bool NiAVObject::GetAppCulled() const
	{
		return (flags & Flag::kHidden) != Flag::kNone;
	}


	void NiAVObject::SetAppCulled(bool cull)
	{
		cull ? flags |= Flag::kHidden : flags &= ~Flag::kHidden;
	}


	bool NiAVObject::SetMotionType(UInt32 a_motionType, bool a_arg2, bool a_arg3, bool a_allowActivate)
	{
		using func_t = decltype(&NiAVObject::SetMotionType);
		REL::Offset<func_t> func(Offset::NiAVObject::SetMotionType);
		return func(this, a_motionType, a_arg2, a_arg3, a_allowActivate);
	}


	void NiAVObject::Update(NiUpdateData& a_data)
	{
		using func_t = decltype(&NiAVObject::Update);
		REL::Offset<func_t> func(Offset::NiAVObject::Update);
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

			return BSVisit::BSVisitControl::kContinue;
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

			return BSVisit::BSVisitControl::kContinue;
		});
	}


	TESObjectREFR* NiAVObject::GetOwner()
	{
		if (userData) {
			return userData;
		}
		if (parent) {
			parent->GetOwner();
		}
		return nullptr;
	}


	void NiAVObject::UpdateVisibility(bool a_visible)
	{
		auto node = AsNode();
		if (node) {
			for (auto& child : node->children) {
				if (child.get()) {
					child->SetAppCulled(a_visible);
				}
			}
			node->SetAppCulled(a_visible);
		}
		SetAppCulled(a_visible);
	}


	void NiAVObject::UpdateMaterialAlpha(float a_alpha, bool a_skin)
	{
		auto node = AsNode();
		if (node) {
			for (auto& child : node->children) {
				if (child.get()) {
					child->UpdateMaterialAlpha(a_alpha, a_skin);
				}
			}
		}
		else {
			auto geometry = AsGeometry();
			if (geometry) {
				geometry->SetMaterialAlpha(a_alpha, a_skin);
			}
		}
	}


	bool NiAVObject::HasShaderType(BSShaderMaterial::Feature a_type)
	{
		auto node = AsNode();
		if (node) {
			for (auto& child : node->children) {
				if (child.get()) {
					if (child->HasShaderType(a_type)) {
						return true;
					}
				}
			}
		}
		else {
			auto geometry = AsGeometry();
			if (geometry) {
				auto effect = geometry->properties[BSGeometry::States::kEffect].get();
				if (effect) {
					auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
					if (lightingShader) {
						auto material = lightingShader->material;
						if (material && material->GetFeature() == a_type) {
							return true;
						}
					}
				}
			}
		}

		return false;
	}


	BSGeometry* NiAVObject::GetFirstGeometryOfShaderType(BSShaderMaterial::Feature a_type)
	{
		auto node = AsNode();
		if (node) {
			for (auto& child : node->children) {
				if (child.get()) {
					auto geometry = child->GetFirstGeometryOfShaderType(a_type);
					if (geometry) {
						return geometry;
					}
				}
			}
		}
		else {
			auto geometry = AsGeometry();
			if (geometry) {
				auto effect = geometry->properties[BSGeometry::States::kEffect].get();
				if (effect) {
					auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
					if (lightingShader) {
						if (a_type == BSShaderMaterial::Feature::kNone) {
							return geometry;
						}
						auto material = lightingShader->material;
						if (material && material->GetFeature() == a_type) {
							return geometry;
						}
					}
				}
			}
		}

		return nullptr;
	}

}
