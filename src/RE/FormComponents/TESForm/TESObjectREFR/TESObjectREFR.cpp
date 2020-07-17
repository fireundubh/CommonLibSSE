#include "RE/FormComponents/TESForm/TESObjectREFR/TESObjectREFR.h"

#include "RE/AI/ProcessLists.h"
#include "RE/BSCore/BSFixedString.h"
#include "RE/BSExtraData/ExtraCharge.h"
#include "RE/BSExtraData/ExtraContainerChanges.h"
#include "RE/BSExtraData/ExtraDroppedItemList.h"
#include "RE/BSExtraData/ExtraEnchantment.h"
#include "RE/BSExtraData/ExtraFlags.h"
#include "RE/BSExtraData/ExtraLock.h"
#include "RE/BSExtraData/ExtraOwnership.h"
#include "RE/BSExtraData/ExtraReferenceHandle.h"
#include "RE/BSExtraData/ExtraTextDisplayData.h"
#include "RE/FormComponents/Components/FormTraits.h"
#include "RE/FormComponents/TESContainer.h"
#include "RE/FormComponents/TESEnchantableForm.h"
#include "RE/FormComponents/TESForm/BGSDefaultObjectManager.h"
#include "RE/FormComponents/TESForm/BGSKeyword/BGSKeyword.h"
#include "RE/FormComponents/TESForm/TESFaction.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESActorBase/TESNPC.h"
#include "RE/Inventory/InventoryChanges.h"
#include "RE/Inventory/InventoryEntryData.h"
#include "RE/Misc/Misc.h"
#include "RE/NetImmerse/NiRTTI.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/ReferenceEffect/ReferenceEffect.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiControllerSequence.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiAVObject.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiTimeController/NiControllerManager.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiTimeController/NiTimeController.h"
#include "SKSE/Logger.h"


namespace RE
{
	NiPointer<TESObjectREFR> TESObjectREFR::LookupByHandle(RefHandle a_refHandle)
	{
		NiPointer<TESObjectREFR> ref;
		LookupReferenceByHandle(a_refHandle, ref);
		return ref;
	}


	bool TESObjectREFR::LookupByHandle(RefHandle a_refHandle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		return LookupReferenceByHandle(a_refHandle, a_refrOut);
	}


	TESObjectREFR* TESObjectREFR::FindReferenceFor3D(NiAVObject* a_object3D)
	{
		using func_t = decltype(&TESObjectREFR::FindReferenceFor3D);
		REL::Offset<func_t> func(Offset::TESObjectREFR::FindReferenceFor3D);
		return func(a_object3D);
	}


	ObjectRefHandle TESObjectREFR::CreateRefHandle()
	{
		return GetHandle();
	}


	RefHandle* TESObjectREFR::CreateRefHandle_Native(RefHandle* handle)
	{
		using func_t = decltype(&TESObjectREFR::CreateRefHandle_Native);
		REL::Offset<func_t> func(Offset::TESObjectREFR::CreateRefHandle_Native);
		return func(this, handle);
	}


	void TESObjectREFR::DoTrap(TrapData& a_data)
	{
		return DoTrap1(a_data);
	}


	void TESObjectREFR::DoTrap(TrapEntry* a_trap, TargetEntry* a_target)
	{
		return DoTrap2(a_trap, a_target);
	}


	NiAVObject* TESObjectREFR::Get3D() const
	{
		return Get3D2();
	}


	NiAVObject* TESObjectREFR::Get3D(bool a_firstPerson) const
	{
		return Get3D1(a_firstPerson);
	}


	TESNPC* TESObjectREFR::GetActorOwner()
	{
		auto xOwnership = extraList.GetByType<ExtraOwnership>();
		if (xOwnership && xOwnership->owner && xOwnership->owner->Is(FormType::ActorCharacter)) {
			return static_cast<TESNPC*>(xOwnership->owner);
		} else {
			return nullptr;
		}
	}


	NiPoint3 TESObjectREFR::GetAngle() const
	{
		return data.angle;
	}


	float TESObjectREFR::GetAngleX() const
	{
		return data.angle.x;
	}


	float TESObjectREFR::GetAngleY() const
	{
		return data.angle.y;
	}


	float TESObjectREFR::GetAngleZ() const
	{
		return data.angle.z;
	}


	float TESObjectREFR::GetBaseHeight() const
	{
		auto height = static_cast<float>(refScale) / 100.0F;
		auto obj = GetObjectReference();
		auto npc = obj ? obj->As<TESNPC>() : nullptr;
		if (npc) {
			height *= npc->GetHeight();
		}
		return height;
	}


	TESBoundObject* TESObjectREFR::GetBaseObject()
	{
		return data.objectReference;
	}


	const TESBoundObject* TESObjectREFR::GetBaseObject() const
	{
		return data.objectReference;
	}


	const BSTSmartPointer<BipedAnim>& TESObjectREFR::GetBiped() const
	{
		return GetBiped2();
	}


	const BSTSmartPointer<BipedAnim>& TESObjectREFR::GetBiped(bool a_firstPerson) const
	{
		return GetBiped1(a_firstPerson);
	}


	TESContainer* TESObjectREFR::GetContainer() const
	{
		auto obj = GetObjectReference();
		return obj ? obj->As<TESContainer>() : nullptr;
	}


	auto TESObjectREFR::GetDirection()
		-> Direction
	{
		float directionOut = 0.0;
		if (GetGraphVariableFloat(BSFixedString("Direction"), directionOut)) {
			switch (static_cast<UInt32>(directionOut * 1000)) {
			case 0:
				return Direction::kStanding;
			case 125:
				return Direction::kDiagonallyForwardRight;
			case 250:
				return Direction::kRight;
			case 375:
				return Direction::kDiagonallyRight;
			case 500:
				return Direction::kBack;
			case 625:
				return Direction::kDiagonallyLeft;
			case 750:
				return Direction::kLeft;
			case 875:
				return Direction::kFront;
			}
		}
		return Direction::kInvalid;
	}


	const char* TESObjectREFR::GetDisplayFullName()
	{
		using func_t = decltype(&TESObjectREFR::GetDisplayFullName);
		REL::Offset<func_t> func(Offset::TESObjectREFR::GetDisplayFullName);
		return func(this);
	}


	auto TESObjectREFR::GetDroppedInventory()
		-> InventoryDropMap
	{
		return GetDroppedInventory([]([[maybe_unused]] TESBoundObject*) -> bool {
			return true;
		});
	}


	auto TESObjectREFR::GetDroppedInventory(std::function<bool(TESBoundObject*)> a_filter)
		-> InventoryDropMap
	{
		using container_t = InventoryDropMap::mapped_type::second_type;

		InventoryDropMap results;

		auto xDrop = extraList.GetByType<ExtraDroppedItemList>();
		if (!xDrop) {
			return results;
		}

		for (auto& handle : xDrop->droppedItemList) {
			auto ref = handle.get();
			if (!ref) {
				continue;
			}

			auto object = ref->GetObjectReference();
			if (!object || !a_filter(object)) {
				continue;
			}

			auto count = ref->extraList.GetCount();
			auto it = results.find(object);
			if (it != results.end()) {
				it->second.first += count;
				it->second.second.push_back(handle);
			} else {
				auto mapped = std::make_pair(count, container_t());
				mapped.second.push_back(handle);
				auto insIt = results.emplace(object, std::move(mapped));
				assert(insIt.second);
			}
		}

		return results;
	}


	BGSLocation* TESObjectREFR::GetEditorLocation() const
	{
		return GetEditorLocation1();
	}


	bool TESObjectREFR::GetEditorLocation(NiPoint3& a_outPos, NiPoint3& a_outRot, TESForm*& a_outWorldOrCell, TESObjectCELL* a_fallback)
	{
		return GetEditorLocation2(a_outPos, a_outRot, a_outWorldOrCell, a_fallback);
	}


	std::optional<double> TESObjectREFR::GetEnchantmentCharge() const
	{
		std::optional<double> result;
		auto obj = GetObjectReference();
		auto ench = obj ? obj->As<TESEnchantableForm>() : nullptr;
		if (ench && ench->formEnchanting) {
			result.emplace(100.0);
		}

		auto xCharge = extraList.GetByType<ExtraCharge>();
		if (xCharge) {
			auto xEnch = extraList.GetByType<ExtraEnchantment>();
			if (xEnch && xEnch->enchantment) {
				result.emplace((static_cast<double>(xCharge->charge) /
								   static_cast<double>(xEnch->charge)) *
							   100.0);
			} else if (ench && ench->formEnchanting) {
				result.emplace((static_cast<double>(xCharge->charge) /
								   static_cast<double>(ench->amountofEnchantment)) *
							   100.0);
			}
		}

		return result;
	}


	TESFaction* TESObjectREFR::GetFactionOwner()
	{
		auto xOwnership = extraList.GetByType<ExtraOwnership>();
		if (xOwnership && xOwnership->owner && xOwnership->owner->Is(FormType::Faction)) {
			return static_cast<TESFaction*>(xOwnership->owner);
		} else {
			return nullptr;
		}
	}


	ObjectRefHandle TESObjectREFR::GetHandle()
	{
		return ObjectRefHandle(this);
	}


	auto TESObjectREFR::GetInventory()
		-> InventoryItemMap
	{
		return GetInventory([](TESBoundObject*) { return true; });
	}


	auto TESObjectREFR::GetInventory(std::function<bool(TESBoundObject*)> a_filter)
		-> InventoryItemMap
	{
		InventoryItemMap results;

		auto invChanges = GetInventoryChanges();
		if (invChanges && invChanges->entryList) {
			for (auto& entry : *invChanges->entryList) {
				if (entry && entry->object && a_filter(entry->object)) {
					[[maybe_unused]] auto it =
						results.emplace(
							entry->object,
							std::make_pair(
								entry->countDelta,
								std::make_unique<InventoryEntryData>(*entry)));
					assert(it.second);
				}
			}
		}

		auto container = GetContainer();
		if (container) {
			std::set<TESForm*> llForms;
			container->ForEachContainerObject([&](ContainerObject& a_entry) {
				auto ll = a_entry.obj ? a_entry.obj->As<TESLeveledList>() : nullptr;
				if (ll) {
					llForms.merge(ll->GetContainedForms());
				}
				return true;
			});

			const auto ignore = [&](TESForm* a_form) { return llForms.find(a_form) != llForms.end(); };

			container->ForEachContainerObject([&](ContainerObject& a_entry) {
				auto obj = a_entry.obj;
				if (obj && !ignore(obj) && a_filter(obj)) {
					auto it = results.find(obj);
					if (it == results.end()) {
						[[maybe_unused]] auto insIt =
							results.emplace(
								obj,
								std::make_pair(
									a_entry.count,
									std::make_unique<InventoryEntryData>(obj, 0)));
						assert(insIt.second);
					} else {
						it->second.first += a_entry.count;
					}
				}
				return true;
			});
		}

		return results;
	}


	SInt32 TESObjectREFR::GetInventoryCount()
	{
		auto counts = GetInventoryCounts();
		SInt32 total = 0;
		for (auto& elem : counts) {
			total += elem.second;
		}
		return total;
	}


	auto TESObjectREFR::GetInventoryCounts()
		-> InventoryCountMap
	{
		return GetInventoryCounts([](TESBoundObject*) { return true; });
	}


	auto TESObjectREFR::GetInventoryCounts(std::function<bool(TESBoundObject*)> a_filter)
		-> InventoryCountMap
	{
		auto itemMap = GetInventory(std::move(a_filter));
		InventoryCountMap results;
		for (const auto& [key, value] : itemMap) {
			results[key] = value.first;
		}
		return results;
	}


	InventoryChanges* TESObjectREFR::GetInventoryChanges()
	{
		if (!extraList.HasType<ExtraContainerChanges>()) {
			if (!InitInventoryIfRequired()) {
				ForceInitInventoryChanges();
			}
		}

		auto xContChanges = extraList.GetByType<ExtraContainerChanges>();
		return xContChanges ? xContChanges->changes : nullptr;
	}


	TESObjectREFR* TESObjectREFR::GetLinkedRef(BGSKeyword* a_keyword)
	{
		return extraList.GetLinkedRef(a_keyword);
	}


	REFR_LOCK* TESObjectREFR::GetLock() const
	{
		using func_t = decltype(&TESObjectREFR::GetLock);
		REL::Offset<func_t> func(Offset::TESObjectREFR::GetLock);
		return func(this);
	}


	LOCK_LEVEL TESObjectREFR::GetLockLevel() const
	{
		auto state = GetLock();
		return state ? state->GetLockLevel(this) : LOCK_LEVEL::kUnlocked;
	}


	const char* TESObjectREFR::GetName() const
	{
		auto obj = GetObjectReference();
		return obj ? obj->GetName() : "";
	}


	NiAVObject* TESObjectREFR::GetNodeByName(const BSFixedString& a_nodeName)
	{
		auto node = Get3D();
		return node ? node->GetObjectByName(a_nodeName) : nullptr;
	}


	TESBoundObject* TESObjectREFR::GetObjectReference() const
	{
		return data.objectReference;
	}


	TESForm* TESObjectREFR::GetOwner() const
	{
		using func_t = decltype(&TESObjectREFR::GetOwner);
		REL::Offset<func_t> func(Offset::TESObjectREFR::GetOwner);
		return func(this);
	}


	TESObjectCELL* TESObjectREFR::GetParentCell() const
	{
		return parentCell;
	}


	NiPoint3 TESObjectREFR::GetPosition() const
	{
		return data.location;
	}


	float TESObjectREFR::GetPositionX() const
	{
		return data.location.x;
	}


	float TESObjectREFR::GetPositionY() const
	{
		return data.location.y;
	}


	float TESObjectREFR::GetPositionZ() const
	{
		return data.location.z;
	}


	UInt32 TESObjectREFR::GetStealValue(const InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_useMult) const
	{
		using func_t = decltype(&TESObjectREFR::GetStealValue);
		REL::Offset<func_t> func(Offset::TESObjectREFR::GetStealValue);
		return func(this, a_entryData, a_numItems, a_useMult);
	}


	NiPoint3 TESObjectREFR::GetRotation() const
	{
		return data.angle;
	}

	float TESObjectREFR::GetRotationX() const
	{
		return data.angle.x;
	}


	float TESObjectREFR::GetRotationY() const
	{
		return data.angle.y;
	}


	float TESObjectREFR::GetRotationZ() const
	{
		return data.angle.z;
	}


	float TESObjectREFR::GetWeight() const
	{
		auto obj = GetObjectReference();
		return obj ? obj->GetWeight() : 0.0;
	}


	float TESObjectREFR::GetWeightInContainer()
	{
		using func_t = decltype(&Actor::GetWeightInContainer);
		REL::Offset<func_t> func = REL::ID(19277);
		return func(this);
	}


	TESWorldSpace* TESObjectREFR::GetWorldspace() const
	{
		auto cell = parentCell;
		if (!cell) {
			cell = GetSaveParentCell();
		}

		if (cell && cell->IsExteriorCell()) {
			return cell->worldSpace;
		} else {
			return nullptr;
		}
	}


	bool TESObjectREFR::HasCollision() const
	{
		return (formFlags & RecordFlags::kCollisionsDisabled) == 0;
	}


	bool TESObjectREFR::HasContainer() const
	{
		return GetContainer() != nullptr;
	}


	bool TESObjectREFR::HasKeyword(const BGSKeyword* a_keyword) const
	{
		return HasKeywordHelper(a_keyword);
	}


	bool TESObjectREFR::HasQuestObject() const
	{
		using func_t = decltype(&TESObjectREFR::HasQuestObject);
		REL::Offset<func_t> func = REL::ID(19201);
		return func(this);
	}


	void TESObjectREFR::InitChildActivates(TESObjectREFR* a_activator)
	{
		using func_t = decltype(&TESObjectREFR::InitChildActivates);
		REL::Offset<func_t> func(Offset::TESObjectREFR::InitChildActivates);
		return func(this, a_activator);
	}


	bool TESObjectREFR::InitInventoryIfRequired(bool a_ignoreContainerExtraData)
	{
		using func_t = decltype(&TESObjectREFR::InitInventoryIfRequired);
		REL::Offset<func_t> func(Offset::TESObjectREFR::InitInventoryIfRequired);
		return func(this, a_ignoreContainerExtraData);
	}


	bool TESObjectREFR::Is3DLoaded() const
	{
		return Get3D() != nullptr;
	}


	bool TESObjectREFR::IsActivationBlocked() const
	{
		auto xFlags = extraList.GetByType<ExtraFlags>();
		return xFlags && xFlags->IsActivationBlocked();
	}


	bool TESObjectREFR::IsAnOwner(const Actor* a_testOwner, bool a_useFaction, bool a_requiresOwner) const
	{
		using func_t = decltype(&TESObjectREFR::IsAnOwner);
		REL::Offset<func_t> func = REL::ID(19805);
		return func(this, a_testOwner, a_useFaction, a_requiresOwner);
	}


	bool TESObjectREFR::IsCrimeToActivate()
	{
		using func_t = decltype(&TESObjectREFR::IsCrimeToActivate);
		REL::Offset<func_t> func(Offset::TESObjectREFR::IsCrimeToActivate);
		return func(this);
	}


	bool TESObjectREFR::IsDisabled() const
	{
		return (formFlags & RecordFlags::kInitiallyDisabled) != 0;
	}


	bool TESObjectREFR::IsEnchanted() const
	{
		auto xEnch = extraList.GetByType<ExtraEnchantment>();
		if (xEnch && xEnch->enchantment) {
			return true;
		}

		auto obj = GetObjectReference();
		if (obj) {
			auto ench = obj->As<TESEnchantableForm>();
			if (ench && ench->formEnchanting) {
				return true;
			}
		}

		return false;
	}


	bool TESObjectREFR::IsHorse() const
	{
		auto dobj = BGSDefaultObjectManager::GetSingleton();
		if (!dobj) {
			return false;
		}

		auto keyword = dobj->GetObject<BGSKeyword>(DEFAULT_OBJECT::kKeywordHorse);
		return keyword ? HasKeyword(keyword) : false;
	}


	bool TESObjectREFR::IsInitiallyDisabled() const
	{
		return (formFlags & RecordFlags::kInitiallyDisabled) != 0;
	}


	bool TESObjectREFR::IsLocked() const
	{
		return GetLockLevel() != LOCK_LEVEL::kUnlocked;
	}


	bool TESObjectREFR::IsMarkedForDeletion() const
	{
		return (formFlags & RecordFlags::kDeleted) != 0;
	}


	bool TESObjectREFR::IsOffLimits()
	{
		return IsCrimeToActivate();
	}


	bool TESObjectREFR::MoveToNode(TESObjectREFR* a_target, const BSFixedString& a_nodeName)
	{
		assert(a_target);
		auto node = a_target->Get3D();
		if (!node) {
			SKSE::log::debug("Cannot move the target because it does not have 3D");
			return false;
		}

		auto object = node->GetObjectByName(a_nodeName);
		if (!object) {
			SKSE::log::debug("Target does not have a node named {}", a_nodeName.c_str());
			return false;
		}

		return MoveToNode(a_target, object);
	}


	bool TESObjectREFR::MoveToNode(TESObjectREFR* a_target, NiAVObject* a_node)
	{
		assert(a_target && a_node);
		auto& position = a_node->world.translate;
		NiPoint3 rotation;
		a_node->world.rotate.ToEulerAnglesXYZ(rotation);
		auto handle = a_target->GetHandle();
		MoveTo_Impl(handle, a_target->GetParentCell(), GetWorldspace(), position, rotation);
		return true;
	}


	void TESObjectREFR::PlayAnimation(std::string_view a_from, std::string_view a_to)
	{
		auto node = Get3D();
		if (!node) {
			return;
		}

		auto controller = node->GetControllers();
		if (!controller) {
			return;
		}

		auto manager = controller->AsNiControllerManager();
		if (!manager) {
			return;
		}

		auto fromSeq = manager->GetSequenceByName(a_from);
		auto toSeq = manager->GetSequenceByName(a_to);
		if (!fromSeq || !toSeq) {
			return;
		}

		PlayAnimation(manager, toSeq, fromSeq);
	}


	void TESObjectREFR::PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq)
	{
		PlayAnimation_Impl(a_manager, a_toSeq, a_fromSeq);
	}


	void TESObjectREFR::SetActivationBlocked(bool a_blocked)
	{
		extraList.SetExtraFlags(ExtraFlags::Flag::kBlockActivate, a_blocked);
	}


	void TESObjectREFR::SetCollision(bool a_enable)
	{
		if (a_enable) {
			formFlags &= ~RecordFlags::kCollisionsDisabled;
		} else {
			formFlags |= RecordFlags::kCollisionsDisabled;
		}
	}


	bool TESObjectREFR::SetDisplayName(const BSFixedString& a_name, bool a_force)
	{
		bool renamed = false;

		auto xTextData = extraList.GetByType<ExtraTextDisplayData>();
		if (xTextData) {
			bool inUse = xTextData->displayNameText || xTextData->ownerQuest;
			if (inUse && a_force) {
				xTextData->displayNameText = nullptr;
				xTextData->ownerQuest = nullptr;
			}
			renamed = !inUse || a_force;
			xTextData->SetName(a_name.c_str());
		} else {
			xTextData = new ExtraTextDisplayData(a_name.c_str());
			extraList.Add(xTextData);
			renamed = true;
		}

		return renamed;
	}


	bool TESObjectREFR::SetMotionType(MotionType a_motionType, bool a_allowActivate)
	{
		auto node = Get3D();
		if (!node) {
			SKSE::log::debug("Target does not have 3D");
			return false;
		}

		auto result = node->SetMotionType(static_cast<UInt32>(a_motionType), true, false, a_allowActivate);
		AddChange(ChangeFlags::kHavokMoved);
		return result;
	}


	void TESObjectREFR::SetPosition(float a_x, float a_y, float a_z)
	{
		return SetPosition(NiPoint3(a_x, a_y, a_z));
	}


	void TESObjectREFR::SetPosition(NiPoint3 a_pos)
	{
		MoveTo_Impl(ObjectRefHandle(), GetParentCell(), GetWorldspace(), a_pos, data.angle);
	}


	InventoryChanges* TESObjectREFR::ForceInitInventoryChanges()
	{
		auto changes = MakeInventoryChanges();
		if (changes) {
			changes->InitLeveledItems();
			changes->InitFromContainerExtra();
			changes->InitScripts();
		}
		return changes;
	}


	InventoryChanges* TESObjectREFR::MakeInventoryChanges()
	{
		using func_t = decltype(&TESObjectREFR::MakeInventoryChanges);
		REL::Offset<func_t> func = REL::ID(15802);
		return func(this);
	}


	void TESObjectREFR::MoveTo_Impl(const ObjectRefHandle& a_targetHandle, TESObjectCELL* a_targetCell, TESWorldSpace* a_selfWorldSpace, const NiPoint3& a_position, const NiPoint3& a_rotation)
	{
		using func_t = decltype(&TESObjectREFR::MoveTo_Impl);
		REL::Offset<func_t> func(Offset::TESObjectREFR::MoveTo);
		return func(this, a_targetHandle, a_targetCell, a_selfWorldSpace, a_position, a_rotation);
	}


	void TESObjectREFR::PlayAnimation_Impl(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_arg4)
	{
		using func_t = decltype(&TESObjectREFR::PlayAnimation_Impl);
		REL::Offset<func_t> func(Offset::TESObjectREFR::PlayAnimation);
		return func(this, a_manager, a_toSeq, a_fromSeq, a_arg4);
	}
}
