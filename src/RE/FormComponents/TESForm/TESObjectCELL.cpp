#include "RE/FormComponents/TESForm/TESObjectCELL.h"

#include "RE/BSExtraData/ExtraNorthRotation.h"
#include "RE/FormComponents/TESForm/BGSEncounterZone.h"
#include "RE/FormComponents/TESForm/TESFaction.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESActorBase/TESNPC.h"
#include "RE/FormComponents/TESForm/TESWorldSpace.h"
#include "RE/NetImmerse/NiMath.h"
#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkWorld/bhkWorld.h"


namespace RE
{
	TESNPC* TESObjectCELL::GetActorOwner()
	{
		auto owner = GetOwner();
		return owner && owner->Is(FormType::NPC) ? static_cast<TESNPC*>(owner) : nullptr;
	}


	EXTERIOR_DATA* TESObjectCELL::GetCoordinates()
	{
		return IsExteriorCell() ? cellData.exterior : nullptr;
	}


	TESFaction* TESObjectCELL::GetFactionOwner()
	{
		auto owner = GetOwner();
		return owner && owner->Is(FormType::Faction) ? static_cast<TESFaction*>(owner) : nullptr;
	}


	INTERIOR_DATA* TESObjectCELL::GetLighting()
	{
		return IsInteriorCell() ? cellData.interior : nullptr;
	}


	BGSLocation* TESObjectCELL::GetLocation() const
	{
		using func_t = decltype(&TESObjectCELL::GetLocation);
		REL::Relocation<func_t> func{ REL::ID(18474) };
		return func(this);
	}


	float TESObjectCELL::GetNorthRotation()
	{
		if (IsExteriorCell()) {
			return worldSpace->northRotation;
		} else {
			auto xNorth = extraList.GetByType<ExtraNorthRotation>();
			return xNorth ? xNorth->northRot : static_cast<float>(0.0);
		}
	}


	TESForm* TESObjectCELL::GetOwner()
	{
		auto owner = extraList.GetOwner();
		if (owner) {
			return owner;
		}

		BGSEncounterZone* zone = nullptr;
		if (loadedData) {
			zone = loadedData->encounterZone;
		} else {
			zone = extraList.GetEncounterZone();
			if (!zone && IsExteriorCell()) {
				zone = worldSpace ? worldSpace->encounterZone : nullptr;
			}
		}

		return zone ? zone->data.zoneOwner : nullptr;
	}


	float TESObjectCELL::GetWaterHeight() const
	{
		auto height = -NI_INFINITY;
		
		if (cellFlags.none(Flag::kHasWater) || cellFlags.any(Flag::kIsInteriorCell)) {
			return height;
		}

		if (waterHeight < 2147483600.0f) {
			return waterHeight;
		}

		return worldSpace ? worldSpace->GetWaterHeight() : height;
	}


	void TESObjectCELL::ForEachReference(std::function<bool(RE::TESObjectREFR&)> a_callback) const
	{
		BSSpinLockGuard locker(spinLock);
		for (const auto& refPtr : references) {
			auto ref = refPtr.get();
			if (ref) {
				if (!a_callback(*ref)) {
					break;
				}
			}
		}
	}


	void TESObjectCELL::ForEachReferenceInRange(const NiPoint3& a_origin, float a_radius, std::function<bool(TESObjectREFR&)> a_callback) const
	{
		ForEachReference([&](TESObjectREFR& ref) {
			const auto distance = a_origin.GetSquaredDistance(ref.GetPosition());
			return distance <= a_radius ?
						 a_callback(ref) :
						 true;
		});
	}


	bool TESObjectCELL::IsAttached() const
	{
		return cellState == CellState::kAttached;
	}


	bool TESObjectCELL::IsExteriorCell() const
	{
		return !IsInteriorCell();
	}


	bool TESObjectCELL::IsInteriorCell() const
	{
		return cellFlags.all(Flag::kIsInteriorCell);
	}


	BSTempEffectParticle* TESObjectCELL::PlaceParticleEffect(float a_lifetime, const char* a_modelName, const RE::NiMatrix3& a_normal, const RE::NiPoint3& a_pos, float a_scale, std::uint32_t a_flags, RE::NiAVObject* a_target)
	{
		using func_t = decltype(&TESObjectCELL::PlaceParticleEffect);
		REL::Relocation<func_t> func{ REL::ID(29219) };
		return func(this, a_lifetime, a_modelName, a_normal, a_pos, a_scale, a_flags, a_target);
	}


	void TESObjectCELL::SetActorOwner(TESNPC* a_owner)
	{
		SetOwner(a_owner);
	}


	void TESObjectCELL::SetFactionOwner(TESFaction* a_owner)
	{
		SetOwner(a_owner);
	}


	void TESObjectCELL::SetFogColor(Color a_near, Color a_far)
	{
		if (!UsesSkyLighting()) {
			auto lighting = GetLighting();
			if (lighting) {
				lighting->fogColorNear = a_near;
				lighting->fogColorFar = a_far;
			}
		}
	}


	void TESObjectCELL::SetFogPlanes(float a_near, float a_far)
	{
		if (!UsesSkyLighting()) {
			auto lighting = GetLighting();
			if (lighting) {
				lighting->fogNear = a_near;
				lighting->fogFar = a_far;
			}
		}
	}


	void TESObjectCELL::SetFogPower(float a_power)
	{
		if (!UsesSkyLighting()) {
			auto lighting = GetLighting();
			if (lighting) {
				lighting->fogPower = a_power;
			}
		}
	}


	void TESObjectCELL::SetHandChanged(bool a_changed)
	{
		if (a_changed) {
			cellFlags.set(Flag::kHandChanged);
		} else {
			cellFlags.reset(Flag::kHandChanged);
		}
		AddChange(ChangeFlags::kFlags);
	}


	void TESObjectCELL::SetOwner(TESForm* a_owner)
	{
		extraList.SetOwner(a_owner);
		AddChange(ChangeFlags::kOwnership);
	}


	void TESObjectCELL::SetPublic(bool a_public)
	{
		if (a_public) {
			cellFlags.set(Flag::kPublicArea);
		} else {
			cellFlags.reset(Flag::kPublicArea);
		}
		AddChange(ChangeFlags::kFlags);
	}


	bool TESObjectCELL::UsesSkyLighting() const
	{
		return cellFlags.all(Flag::kUseSkyLighting);
	}
	BSTempEffectParticle* CreateParticleEffect(RE::TESObjectCELL* a_cell, float a_lifetime, const char* a_modelName, const RE::NiMatrix3& a_rot, const RE::NiPoint3& a_pos, float a_scale, std::uint32_t a_flags, RE::NiAVObject* a_unk88)
	{
		return nullptr;
	}
}
