#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiAVObject.h"

#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/BSGraphics/State.h"
#include "RE/BSShader/BSEffectShaderData.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialFacegenTint.h"
#include "RE/BSShader/BSShaderMaterial/BSLightingShaderMaterialBase/BSLightingShaderMaterialHairTint.h"
#include "RE/BSShader/BSShaderMaterial/BSShaderMaterial.h"
#include "RE/NetImmerse/BSVisit.h"
#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiRTTI.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/BSGeometry/BSGeometry.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiNode/NiNode.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiProperty/NiProperty.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiProperty/NiShadeProperty/BSShaderProperty/BSLightingShaderProperty.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiProperty/NiShadeProperty/BSShaderProperty/BSShaderProperty.h"
#include "SKSE/Logger.h"


namespace RE
{
	bool NiAVObject::GetAppCulled() const
	{
		return flags.all(Flag::kHidden);
	}


	BSGeometry* NiAVObject::GetFirstGeometryOfShaderType(BSShaderMaterial::Feature a_type)
	{
		BSGeometry* firstGeometry = nullptr;

		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			if (a_type == BSShaderMaterial::Feature::kNone) {
				firstGeometry = a_geometry;
				return BSVisit::BSVisitControl::kStop;
			}

			auto effect = a_geometry->properties[BSGeometry::States::kEffect].get();
			if (effect) {
				auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
				if (lightingShader) {
					const auto material = lightingShader->material;
					if (material && material->GetFeature() == a_type) {
						firstGeometry = a_geometry;
						return BSVisit::BSVisitControl::kStop;
					}
				}
			}

			return BSVisit::BSVisitControl::kContinue;
		});

		return firstGeometry;
	}


	TESObjectREFR* NiAVObject::GetUserData() const
	{
		if (userData) {
			return userData;
		}

		if (parent) {
			return parent->GetUserData();
		}

		return nullptr;
	}


	bool NiAVObject::HasShaderType(BSShaderMaterial::Feature a_type)
	{
		bool hasShaderType = false;

		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			auto effect = a_geometry->properties[BSGeometry::States::kEffect].get();
			if (effect) {
				auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
				if (lightingShader) {
					const auto material = lightingShader->material;
					if (material && material->GetFeature() == a_type) {
						hasShaderType = true;
						return BSVisit::BSVisitControl::kStop;
					}
				}
			}

			return BSVisit::BSVisitControl::kContinue;
		});

		return hasShaderType;
	}


	void NiAVObject::SetAppCulled(bool cull)
	{
		if (cull) {
			flags.set(Flag::kHidden);
		} else {
			flags.reset(Flag::kHidden);
		}
	}


	bool NiAVObject::SetMotionType(std::uint32_t a_motionType, bool a_arg2, bool a_arg3, bool a_allowActivate)
	{
		using func_t = decltype(&NiAVObject::SetMotionType);
		REL::Relocation<func_t> func{ Offset::NiAVObject::SetMotionType };
		return func(this, a_motionType, a_arg2, a_arg3, a_allowActivate);
	}


	void NiAVObject::SetRigidConstraints(bool a_enable, std::uint8_t a_arg2, std::uint32_t a_arg3)
	{
		using func_t = decltype(&NiAVObject::SetRigidConstraints);
		REL::Relocation<func_t> func{ REL::ID(76271) };
		return func(this, a_enable, a_arg2, a_arg3);
	}


	void NiAVObject::SetStiffSpringConstraints(std::uint8_t a_arg2)
	{
		using func_t = decltype(&NiAVObject::SetStiffSpringConstraints);
		REL::Relocation<func_t> func{ REL::ID(76167) };
		return func(this, a_arg2);
	}


	void NiAVObject::TintScenegraph(const NiColorA& a_color)
	{
		auto gState = RE::BSGraphics::State::GetSingleton();
		BSTSmartPointer<BSEffectShaderData> newShaderData(new RE::BSEffectShaderData());
		newShaderData->fillColor = a_color;
		newShaderData->baseTexture = gState->defaultTextureWhite;

		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			auto effect = a_geometry->properties[BSGeometry::States::kEffect];
			auto shaderProp = netimmerse_cast<BSShaderProperty*>(effect.get());
			if (shaderProp && shaderProp->AcceptsEffectData()) {
				auto shaderData = shaderProp->effectData;
				if (!shaderData || shaderData->baseTexture == gState->defaultTextureWhite) {
					shaderProp->SetEffectShaderData(newShaderData);
				}
			}

			return BSVisit::BSVisitControl::kContinue;
		});
	}


	void NiAVObject::ToggleNode(bool a_hide)
	{
		BSVisit::TraverseScenegraphObjects(this, [&](NiAVObject* a_object) -> BSVisit::BSVisitControl {
			a_object->SetAppCulled(a_hide);

			return BSVisit::BSVisitControl::kContinue;
		});
	}


	void NiAVObject::ToggleWeaponBlood(bool a_enable)
	{
		using func_t = decltype(&NiAVObject::ToggleWeaponBlood);
		REL::Relocation<func_t> func{ REL::ID(99792) };
		return func(this, a_enable);
	}


	void NiAVObject::Update(NiUpdateData& a_data)
	{
		using func_t = decltype(&NiAVObject::Update);
		REL::Relocation<func_t> func{ Offset::NiAVObject::Update };
		return func(this, a_data);
	}


	void NiAVObject::UpdateMaterialAlpha(float a_alpha, bool a_onlySkin)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			using State = BSGeometry::States;
			using Feature = BSShaderMaterial::Feature;

			auto effect = a_geometry->properties[State::kEffect].get();
			if (effect) {
				auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
				if (lightingShader) {
					auto material = static_cast<BSLightingShaderMaterialBase*>(lightingShader->material);
					if (material) {
						if (a_onlySkin) {
							auto const feature = material->GetFeature();
							if (feature != Feature::kFaceGen && feature != Feature::kFaceGenRGBTint) {
								return BSVisit::BSVisitControl::kContinue;
							}
						}
						material->materialAlpha = a_alpha;
					}
				}
			}

			return BSVisit::BSVisitControl::kContinue;
		});
	}


	void NiAVObject::UpdateBodyTint(const NiColor& a_color)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
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
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
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


	void NiAVObject::UpdateRigidBodySettings(std::uint32_t a_type, std::uint32_t a_arg2)
	{
		using func_t = decltype(&NiAVObject::UpdateRigidBodySettings);
		REL::Relocation<func_t> func{ REL::ID(76171) };
		return func(this, a_type, a_arg2);
	}
}
