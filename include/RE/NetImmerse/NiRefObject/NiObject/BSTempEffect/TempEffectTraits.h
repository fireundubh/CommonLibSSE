#pragma once

#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/BSTempEffect.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/BSTempEffectDebris.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/BSTempEffectGeometryDecal.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/BSTempEffectParticle.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/BSTempEffectSPG.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/BSTempEffectSimpleDecal.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/BSTempEffectWeaponBlood.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/ReferenceEffect/ModelReferenceEffect.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/ReferenceEffect/ReferenceEffect.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/ReferenceEffect/ShaderReferenceEffect.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/ReferenceEffect/SummonPlacementEffect.h"


namespace RE
{
	template <class T, typename std::enable_if_t<Impl::is_valid_as_expr<T>::value, int>>
	constexpr T* BSTempEffect::As()
	{
		switch (GetType()) {
		case TEMP_EFFECT_TYPE::kTerrain:
			if constexpr (std::is_convertible<BSTempEffect*, T*>::value) {
				return static_cast<BSTempEffect*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kWeaponBlood:
			if constexpr (std::is_convertible<BSTempEffectWeaponBlood*, T*>::value) {
				return static_cast<BSTempEffectWeaponBlood*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kDecal:
			if constexpr (std::is_convertible<BSTempEffectSimpleDecal*, T*>::value) {
				return static_cast<BSTempEffectSimpleDecal*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kGeometryDecal:
			if constexpr (std::is_convertible<BSTempEffectGeometryDecal*, T*>::value) {
				return static_cast<BSTempEffectGeometryDecal*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kParticle:
			if constexpr (std::is_convertible<BSTempEffectParticle*, T*>::value) {
				return static_cast<BSTempEffectParticle*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kDebris:
			if constexpr (std::is_convertible<BSTempEffectDebris*, T*>::value) {
				return static_cast<BSTempEffectDebris*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kSPG:
			if constexpr (std::is_convertible<BSTempEffectSPG*, T*>::value) {
				return static_cast<BSTempEffectSPG*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kDefault:
			if constexpr (std::is_convertible<BSTempEffect*, T*>::value) {
				return static_cast<BSTempEffect*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kRefDefault:
			if constexpr (std::is_convertible<ReferenceEffect*, T*>::value) {
				return static_cast<ReferenceEffect*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kRefModel:
			if constexpr (std::is_convertible<ModelReferenceEffect*, T*>::value) {
				return static_cast<ModelReferenceEffect*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kRefShader:
			if constexpr (std::is_convertible<ShaderReferenceEffect*, T*>::value) {
				return static_cast<ShaderReferenceEffect*>(this);
			}
			break;
		case TEMP_EFFECT_TYPE::kMagicSummon:
			if constexpr (std::is_convertible<SummonPlacementEffect*, T*>::value) {
				return static_cast<SummonPlacementEffect*>(this);
			}
			break;
		}
		return nullptr;
	}


	template <class T, typename std::enable_if_t<Impl::is_valid_as_expr<T>::value, int>>
	constexpr const T* BSTempEffect::As() const
	{
		return const_cast<BSTempEffect*>(this)->As<T>();
	}
}