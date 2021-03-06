#include "RE/FormComponents/TESForm/TESObjectREFR/Actor/Actor.h"

#include "RE/AI/AIProcess.h"
#include "RE/AI/HighProcessData.h"
#include "RE/AI/MiddleHighProcessData.h"
#include "RE/AI/ProcessLists.h"
#include "RE/BSExtraData/ExtraCanTalkToPlayer.h"
#include "RE/BSExtraData/ExtraFactionChanges.h"
#include "RE/FormComponents/Components/FormTraits.h"
#include "RE/FormComponents/TESForm/BGSColorForm.h"
#include "RE/FormComponents/TESForm/BGSDefaultObjectManager.h"
#include "RE/FormComponents/TESForm/TESFaction.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESActorBase/TESNPC.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectMISC/TESObjectMISC.h"
#include "RE/FormComponents/TESForm/TESRace.h"
#include "RE/FormComponents/TESForm/TESWorldSpace.h"
#include "RE/Inventory/InventoryChanges.h"
#include "RE/Inventory/InventoryEntryData.h"
#include "RE/Misc/Misc.h"
#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiPoint3.h"
#include "RE/NetImmerse/NiRefObject/BGSAttackData.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiExtraData/BSFaceGenAnimationData.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/BSGeometry/BSGeometry.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiNode/BSFaceGenNiNode.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiNode/NiNode.h"
#include "RE/NetImmerse/NiRefObject/bhkCharacterController.h"
#include <RE/NetImmerse/NiMath.h>


namespace RE
{
	NiPointer<Actor> Actor::LookupByHandle(RefHandle a_refHandle)
	{
		NiPointer<Actor> ref;
		LookupReferenceByHandle(a_refHandle, ref);
		return ref;
	}


	bool Actor::LookupByHandle(RefHandle a_refHandle, NiPointer<Actor>& a_refrOut)
	{
		return LookupReferenceByHandle(a_refHandle, a_refrOut);
	}


	bool Actor::AddSpell(SpellItem* a_spell)
	{
		using func_t = decltype(&Actor::AddSpell);
		REL::Relocation<func_t> func{ Offset::Actor::AddSpell };
		return func(this, a_spell);
	}


	void Actor::AddToFaction(TESFaction* a_faction, std::int8_t a_rank)
	{
		using func_t = decltype(&Actor::AddToFaction);
		REL::Relocation<func_t> func{ REL::ID(36678) };
		return func(this, a_faction, a_rank);
	}


	bool Actor::ApplySpell(SpellItem* a_spell)
	{
		using func_t = decltype(&Actor::AddSpell);
		REL::Relocation<func_t> func{ REL::ID(37817) };
		return func(this, a_spell);
	}


	void Actor::AllowBleedoutDialogue(bool a_canTalk)
	{
		if (a_canTalk) {
			boolFlags.set(BOOL_FLAGS::kCanSpeakToEssentialDown);
		} else {
			boolFlags.reset(BOOL_FLAGS::kCanSpeakToEssentialDown);
		}
	}


	void Actor::AllowPCDialogue(bool a_talk)
	{
		auto xTalk = extraList.GetByType<ExtraCanTalkToPlayer>();
		if (!xTalk) {
			xTalk = new ExtraCanTalkToPlayer();
			extraList.Add(xTalk);
		}

		xTalk->talk = a_talk;
	}


	bool Actor::CanFlyHere() const
	{
		const auto* worldSpace = GetWorldspace();
		return worldSpace && worldSpace->HasMaxHeightData();
	}


	bool Actor::CanPickpocket() const
	{
		if (!race) {
			return false;
		}

		return race->AllowsPickpocket() && !IsPlayerTeammate();
	}


	bool Actor::CanTalkToPlayer() const
	{
		auto xTalk = extraList.GetByType<ExtraCanTalkToPlayer>();
		if (xTalk) {
			return xTalk->talk;
		} else {
			return race ? race->AllowsPCDialogue() : false;
		}
	}


	void Actor::ClearArrested()
	{
		if (currentProcess && currentProcess->IsArrested()) {
			currentProcess->SetArrested(false);
			EvaluatePackage(false, false);
			auto procManager = ProcessLists::GetSingleton();
			if (procManager) {
				procManager->StopCombatAndAlarmOnActor(this, true);
			}
		}
	}


	void Actor::ClearExpressionOverride()
	{
		auto faceGen = GetFaceGenAnimationData();
		if (faceGen) {
			faceGen->ClearExpressionOverride();
		}
	}


	ActorHandle Actor::CreateRefHandle()
	{
		return GetHandle();
	}


	bool Actor::Decapitate()
	{
		using func_t = decltype(&Actor::Decapitate);
		REL::Relocation<func_t> func{ Offset::Actor::Decapitate };
		return func(this);
	}


	bool Actor::Dismount()
	{
		using func_t = decltype(&Actor::Dismount);
		REL::Relocation<func_t> func{ REL::ID(36882) };
		return func(this);
	}


	void Actor::DispelWornItemEnchantments()
	{
		using func_t = decltype(&Actor::DispelWornItemEnchantments);
		REL::Relocation<func_t> func{ Offset::Actor::DispelWornItemEnchantments };
		return func(this);
	}


	void Actor::DoReset3D(bool a_updateWeight)
	{
		using func_t = decltype(&Actor::DoReset3D);
		REL::Relocation<func_t> func{ Offset::Actor::DoReset3D };
		return func(this, a_updateWeight);
	}


	void Actor::EnableAI(bool a_enable)
	{
		if (a_enable) {
			boolBits.set(Actor::BOOL_BITS::kProcessMe);
		} else {
			boolBits.reset(Actor::BOOL_BITS::kProcessMe);
			auto controller = GetCharController();
			if (controller) {
				controller->SetLinearVelocityImpl(0.0f);
			}
		}
	}


	void Actor::EvaluatePackage(bool a_arg1, bool a_arg2)
	{
		using func_t = decltype(&Actor::EvaluatePackage);
		REL::Relocation<func_t> func{ Offset::Actor::EvaluatePackage };
		return func(this, a_arg1, a_arg2);
	}


	TESNPC* Actor::GetActorBase()
	{
		auto obj = GetBaseObject();
		return obj ? obj->As<TESNPC>() : nullptr;
	}


	const TESNPC* Actor::GetActorBase() const
	{
		auto obj = GetBaseObject();
		return obj ? obj->As<TESNPC>() : nullptr;
	}


	TESObjectARMO* Actor::GetArmor(BGSBipedObjectForm::BipedObjectSlot a_slot)
	{
		auto inv = GetInventory([](TESBoundObject& a_object) -> bool {
			return a_object.IsArmor();
		});

		for (auto& [item, invData] : inv) {
			auto& [count, entry] = invData;
			if (count > 0) {
				auto armor = static_cast<TESObjectARMO*>(item);
				if (armor && armor->HasPartOf(a_slot)) {
					return armor;
				}
			}
		}

		return nullptr;
	}


	InventoryEntryData* Actor::GetAttackingWeapon()
	{
		if (!currentProcess || !currentProcess->high || !currentProcess->high->attackData || !currentProcess->middleHigh) {
			return nullptr;
		}

		auto attackData = currentProcess->high->attackData;
		auto proc = currentProcess->middleHigh;

		return attackData->IsLeftAttack() ? proc->leftHand : proc->rightHand;
	}


	const InventoryEntryData* Actor::GetAttackingWeapon() const
	{
		if (!currentProcess || !currentProcess->high || !currentProcess->high->attackData || !currentProcess->middleHigh) {
			return nullptr;
		}

		auto attackData = currentProcess->high->attackData;
		auto proc = currentProcess->middleHigh;

		return attackData->IsLeftAttack() ? proc->leftHand : proc->rightHand;
	}


	bhkCharacterController* Actor::GetCharController() const
	{
		return currentProcess ? currentProcess->GetCharController() : nullptr;
	}


	ActorHandle Actor::GetCommandingActor() const
	{
		return currentProcess ? currentProcess->GetCommandingActor() : ActorHandle{};
	}


	TESFaction* Actor::GetCrimeFaction()
	{
		return GetCrimeFactionImpl();
	}


	const TESFaction* Actor::GetCrimeFaction() const
	{
		return GetCrimeFactionImpl();
	}


	auto Actor::GetDirection() const -> Direction
	{
		float directionOut = 0.0f;
		if (GetGraphVariableFloat("Direction", directionOut)) {
			if (directionOut == 0.0f || directionOut == 1.0f) {
				return Direction::kForward;
			} else if (directionOut == 0.125f) {
				return Direction::kForwardRightDiagonal;
			} else if (directionOut == 0.25f) {
				return Direction::kRight;
			} else if (directionOut == 0.375f) {
				return Direction::kBackwardRightDiagonal;
			} else if (directionOut == 0.5f) {
				return Direction::kBackward;
			} else if (directionOut == 0.625f) {
				return Direction::kBackwardLeftDiagonal;
			} else if (directionOut == 0.75f) {
				return Direction::kLeft;
			} else if (directionOut == 0.875f) {
				return Direction::kForwardLeftDiagonal;
			}
		}

		return Direction::kInvalid;
	}


	InventoryEntryData* Actor::GetEquippedEntryData(bool a_leftHand) const
	{
		if (!currentProcess || !currentProcess->middleHigh) {
			return nullptr;
		}

		auto proc = currentProcess->middleHigh;
		if (proc->bothHands) {
			return proc->bothHands;
		} else {
			return a_leftHand ? proc->leftHand : proc->rightHand;
		}
	}


	TESForm* Actor::GetEquippedObject(bool a_leftHand) const
	{
		if (currentProcess) {
			if (a_leftHand) {
				return currentProcess->GetEquippedLeftHand();
			} else {
				return currentProcess->GetEquippedRightHand();
			}
		}
		return nullptr;
	}


	std::int32_t Actor::GetGoldAmount()
	{
		const auto inv = GetInventory([](TESBoundObject& a_object) -> bool {
			return a_object.IsGold();
		});

		const auto dobj = BGSDefaultObjectManager::GetSingleton();
		if (!dobj) {
			return 0;
		}

		const auto gold = dobj->GetObject<TESObjectMISC>(DEFAULT_OBJECT::kGold);
		const auto it = inv.find(gold);
		return it != inv.end() ? it->second.first : 0;
	}


	ActorHandle Actor::GetHandle()
	{
		return ActorHandle(this);
	}


	NiAVObject* Actor::GetHeadPartObject(BGSHeadPart::HeadPartType a_type)
	{
		const auto actorBase = GetActorBase();
		const auto faceNode = GetFaceNodeSkinned();
		const auto facePart = actorBase ? actorBase->GetCurrentHeadPartByType(a_type) : nullptr;
		return faceNode && facePart ? faceNode->GetObjectByName(facePart->formEditorID) : nullptr;
	}


	float Actor::GetHeight()
	{
		const auto min = GetBoundMin();
		const auto max = GetBoundMax();
		const auto diff = max.z - min.z;
		const auto height = GetBaseHeight() * diff;

		if (!currentProcess || !currentProcess->InHighProcess()) {
			return height;
		}

		const auto cachedHeight = currentProcess->GetCachedHeight();
		if (cachedHeight == 0.0) {
			currentProcess->SetCachedHeight(height);
			return height;
		} else {
			return cachedHeight;
		}
	}


	Actor* Actor::GetKiller() const
	{
		const auto killerPtr = myKiller.get();
		return killerPtr.get();
	}


	std::uint16_t Actor::GetLevel() const
	{
		using func_t = decltype(&Actor::GetLevel);
		REL::Relocation<func_t> func{ Offset::Actor::GetLevel };
		return func(this);
	}


	ObjectRefHandle Actor::GetOccupiedFurniture() const
	{
		if (currentProcess) {
			return currentProcess->GetOccupiedFurniture();
		} else {
			return {};
		}
	}


	TESRace* Actor::GetRace() const
	{
		auto base = GetActorBase();
		return base ? base->race : nullptr;
	}


	SEX Actor::GetSex() const
	{
		const auto npc = GetActorBase();
		return npc ? npc->GetSex() : SEX::kMale;
	}


	RE::TESObjectARMO* Actor::GetSkin() const
	{
		const auto npc = GetActorBase();
		return npc ? npc->GetSkin() : nullptr;
	}


	TESObjectARMO* Actor::GetSkin(BIPED_MODEL::BipedObjectSlot a_slot)
	{
		auto equipped = GetWornArmor(a_slot);
		if (!equipped) {
			equipped = GetSkin();
		}

		return equipped;
	}


	SOUL_LEVEL Actor::GetSoulLevel() const
	{
		using func_t = decltype(&Actor::GetSoulLevel);
		REL::Relocation<func_t> func{ Offset::Actor::GetSoulLevel };
		return func(this);
	}


	TESObjectARMO* Actor::GetWornArmor(BGSBipedObjectForm::BipedObjectSlot a_slot)
	{
		auto inv = GetInventory([a_slot](TESBoundObject& a_object) -> bool {
			auto armor = a_object.As<RE::TESObjectARMO>();
			return armor && armor->HasPartOf(a_slot);
		});

		for (auto& [item, invData] : inv) {
			auto& [count, entry] = invData;
			if (count > 0 && entry->GetWorn()) {
				return static_cast<TESObjectARMO*>(item);
			}
		}

		return nullptr;
	}


	TESObjectARMO* Actor::GetWornArmor(FormID id)
	{
		auto inv = GetInventory([id](TESBoundObject& a_object) -> bool {
			return a_object.IsArmor() && a_object.GetFormID() == id;
		});

		for (auto& [item, invData] : inv) {
			auto& [count, entry] = invData;
			if (count > 0 && entry->GetWorn()) {
				return static_cast<TESObjectARMO*>(item);
			}
		}

		return nullptr;
	}


	bool Actor::HasLOS(TESObjectREFR* a_ref, std::uint8_t* a_unk02)
	{
		using func_t = decltype(&Actor::HasLOS);
		REL::Relocation<func_t> func{ REL::ID(53029) };
		return func(this, a_ref, a_unk02);
	}


	bool Actor::HasKeyword(const BGSKeyword* a_keyword) const
	{
		return HasKeywordHelper(a_keyword);
	}


	bool Actor::HasKeyword(std::string_view a_formEditorID) const
	{
		auto base = GetActorBase();
		return base ? base->HasKeyword(a_formEditorID) : false;
	}


	bool Actor::HasPerk(BGSPerk* a_perk) const
	{
		using func_t = decltype(&Actor::HasPerk);
		REL::Relocation<func_t> func{ Offset::Actor::HasPerk };
		return func(this, a_perk);
	}


	bool Actor::HasSpell(SpellItem* a_spell) const
	{
		using func_t = decltype(&Actor::HasSpell);
		REL::Relocation<func_t> func{ Offset::Actor::HasSpell };
		return func(this, a_spell);
	}


	bool Actor::IsAIEnabled() const
	{
		return boolBits.all(BOOL_BITS::kProcessMe);
	}


	bool Actor::IsAMount() const
	{
		return boolFlags.all(BOOL_FLAGS::kIsAMount);
	}


	bool Actor::IsAnimationDriven() const
	{
		bool result = false;
		return GetGraphVariableBool("bAnimationDriven", result) && result;
	}


	bool Actor::IsBeingRidden() const
	{
		return IsAMount() && extraList.HasType(ExtraDataType::kInteraction);
	}


	bool Actor::IsCommandedActor() const
	{
		return boolFlags.all(BOOL_FLAGS::kIsCommandedActor);
	}


	bool Actor::IsEssential() const
	{
		return boolFlags.all(BOOL_FLAGS::kEssential);
	}


	bool Actor::IsProtected() const
	{
		return boolFlags.all(BOOL_FLAGS::kProtected);
	}


	bool Actor::IsFactionInCrimeGroup(const TESFaction* a_faction) const
	{
		auto crimFac = GetCrimeFaction();
		if (!crimFac) {
			return false;
		}

		if (crimFac == a_faction) {
			return true;
		} else {
			return crimFac->IsFactionInCrimeGroup(a_faction);
		}
	}


	bool Actor::IsGhost() const
	{
		using func_t = decltype(&Actor::IsGhost);
		REL::Relocation<func_t> func{ Offset::Actor::GetGhost };
		return func(this);
	}


	bool Actor::IsGuard() const
	{
		return boolBits.all(BOOL_BITS::kGuard);
	}


	bool Actor::IsHostileToActor(Actor* a_actor)
	{
		using func_t = decltype(&Actor::IsHostileToActor);
		REL::Relocation<func_t> func{ Offset::Actor::GetHostileToActor };
		return func(this, a_actor);
	}


	bool Actor::IsLimbGone(std::uint32_t a_limb)
	{
		using func_t = decltype(&Actor::IsLimbGone);
		REL::Relocation<func_t> func{ REL::ID(19338) };
		return func(this, a_limb);
	}


	bool Actor::IsOnMount() const
	{
		return !IsAMount() && extraList.HasType(ExtraDataType::kInteraction);
	}


	bool Actor::IsPlayerTeammate() const
	{
		return boolBits.all(BOOL_BITS::kPlayerTeammate);
	}


	bool Actor::IsRunning() const
	{
		using func_t = decltype(&Actor::IsRunning);
		REL::Relocation<func_t> func{ Offset::Actor::IsRunning };
		return func(this);
	}


	bool Actor::IsSneaking() const
	{
		if (!ActorState::IsSneaking()) {
			return false;
		}

		if (ActorState::IsSwimming()) {
			return false;
		}

		if (IsOnMount()) {
			return false;
		}

		return true;
	}


	bool Actor::IsSummoned() const noexcept
	{
		return currentProcess && currentProcess->GetIsSummonedCreature();
	}


	bool Actor::IsTrespassing() const
	{
		return boolFlags.all(BOOL_FLAGS::kIsTrespassing);
	}


	void Actor::KillImmediate()
	{
		using func_t = decltype(&Actor::KillImmediate);
		REL::Relocation<func_t> func{ REL::ID(36723) };
		return func(this);
	}


	void Actor::RemoveExtraArrows3D()
	{
		extraList.RemoveByType(ExtraDataType::kAttachedArrows3D);
	}


	void Actor::RemoveFromFaction(TESFaction* a_faction)
	{
		using func_t = decltype(&Actor::RemoveFromFaction);
		REL::Relocation<func_t> func{ REL::ID(36680) };
		return func(this, a_faction);
	}


	void Actor::RemoveSelectedSpell(SpellItem* a_spell)
	{
		using func_t = decltype(&Actor::RemoveSelectedSpell);
		REL::Relocation<func_t> func{ REL::ID(37820) };
		return func(this, a_spell);
	}


	bool Actor::RemoveSpell(SpellItem* a_spell)
	{
		using func_t = decltype(&Actor::RemoveSpell);
		REL::Relocation<func_t> func{ REL::ID(37772) };
		return func(this, a_spell);
	}


	std::int32_t Actor::RequestDetectionLevel(Actor* a_target, DETECTION_PRIORITY a_priority)

	{
		using func_t = decltype(&Actor::RequestDetectionLevel);
		REL::Relocation<func_t> func{ Offset::Actor::RequestDetectionLevel };
		return func(this, a_target, a_priority);
	}


	void Actor::StealAlarm(TESObjectREFR* a_ref, TESForm* a_object, std::int32_t a_num, std::int32_t a_total, TESForm* a_owner, bool a_allowWarning)
	{
		using func_t = decltype(&Actor::StealAlarm);
		REL::Relocation<func_t> func{ REL::ID(36427) };
		return func(this, a_ref, a_object, a_num, a_total, a_owner, a_allowWarning);
	}


	void Actor::StopSelectedSpells()
	{
		using func_t = decltype(&Actor::StopSelectedSpells);
		REL::Relocation<func_t> func{ REL::ID(37808) };
		return func(this);
	}


	void Actor::SwitchRace(TESRace* a_race, bool a_player)
	{
		using func_t = decltype(&Actor::SwitchRace);
		REL::Relocation<func_t> func{ Offset::Actor::SwitchRace };
		return func(this, a_race, a_player);
	}


	void Actor::UpdateArmorAbility(TESForm* a_armor, ExtraDataList* a_extraData)
	{
		using func_t = decltype(&Actor::UpdateArmorAbility);
		REL::Relocation<func_t> func{ Offset::Actor::UpdateArmorAbility };
		return func(this, a_armor, a_extraData);
	}


	void Actor::Update3DModel()
	{
		if (currentProcess) {
			currentProcess->Update3DModel(this);
		}
	}


	void Actor::UpdateHairColor()
	{
		const auto* npc = GetActorBase();
		if (npc && npc->headRelatedData) {
			const auto hairColor = npc->headRelatedData->hairColor;
			if (hairColor) {
				NiColor color;
				color.red = hairColor->color.red / static_cast<float>(128.0);
				color.green = hairColor->color.green / static_cast<float>(128.0);
				color.blue = hairColor->color.blue / static_cast<float>(128.0);

				auto model = Get3D(false);
				if (model) {
					model->UpdateHairColor(color);
				}
			}
		}
	}


	void Actor::UpdateLifeState(ACTOR_LIFE_STATE a_lifeState)
	{
		using func_t = decltype(&Actor::UpdateLifeState);
		REL::Relocation<func_t> func{ REL::ID(36604) };
		return func(this, a_lifeState);
	}


	void Actor::UpdateSkinColor()
	{
		const auto* npc = GetActorBase();
		if (npc) {
			NiColor color;
			color.red = npc->bodyTintColor.red / static_cast<float>(255.0);
			color.green = npc->bodyTintColor.green / static_cast<float>(255.0);
			color.blue = npc->bodyTintColor.blue / static_cast<float>(255.0);

			auto thirdPerson = Get3D(false);
			if (thirdPerson) {
				thirdPerson->UpdateBodyTint(color);
			}

			auto firstPerson = Get3D(true);
			if (firstPerson) {
				firstPerson->UpdateBodyTint(color);
			}
		}
	}


	void Actor::UpdateWeaponAbility(TESForm* a_weapon, ExtraDataList* a_extraData, bool a_leftHand)
	{
		using func_t = decltype(&Actor::UpdateWeaponAbility);
		REL::Relocation<func_t> func{ Offset::Actor::UpdateWeaponAbility };
		return func(this, a_weapon, a_extraData, a_leftHand);
	}


	bool Actor::VisitAddedFactions(std::function<bool(TESFaction* a_faction, std::int8_t a_rank)> a_visitor)
	{
		auto base = GetActorBase();
		if (base && base->IsUnique()) {
			for (auto& factionInfo : base->factions) {
				if (a_visitor(factionInfo.faction, factionInfo.rank)) {
					return true;
				}
			}
		} else {
			auto factionChanges = extraList.GetByType<ExtraFactionChanges>();
			if (factionChanges) {
				for (auto& change : factionChanges->factionChanges) {
					if (a_visitor(change.faction, change.rank)) {
						return true;
					}
				}
			}
		}

		return false;
	}


	NiAVObject* Actor::VisitArmorAddon(TESObjectARMO* a_armor, TESObjectARMA* a_arma)
	{
		char addonString[MAX_PATH]{ '\0' };
		a_arma->GetNodeName(addonString, this, a_armor, -1);

		std::array<NiAVObject*, 2> skeletonRoot{ Get3D(false), Get3D(true) };

		if (skeletonRoot[1] == skeletonRoot[0]) {
			skeletonRoot[1] = nullptr;
		}

		for (std::size_t i = 0; i < skeletonRoot.size(); i++) {
			if (skeletonRoot[i]) {
				const auto obj = skeletonRoot[i]->GetObjectByName(addonString);
				if (obj) {
					return obj;
				}
			}
		}

		return nullptr;
	}


	bool Actor::VisitFactions(std::function<bool(TESFaction* a_faction, std::int8_t a_rank)> a_visitor)
	{
		auto base = GetActorBase();
		if (base) {
			for (auto& factionInfo : base->factions) {
				if (a_visitor(factionInfo.faction, factionInfo.rank)) {
					return true;
				}
			}

			auto factionChanges = extraList.GetByType<ExtraFactionChanges>();
			if (factionChanges) {
				for (auto& change : factionChanges->factionChanges) {
					if (a_visitor(change.faction, change.rank)) {
						return true;
					}
				}
			}
		}

		return false;
	}


	bool Actor::WouldBeStealing(const TESObjectREFR* a_target) const
	{
		return a_target ? !a_target->IsAnOwner(this, true, false) : false;
	}


	TESFaction* Actor::GetCrimeFactionImpl() const
	{
		if (IsCommandedActor()) {
			return nullptr;
		}

		auto xFac = extraList.GetByType<ExtraFactionChanges>();
		if (xFac && (xFac->crimeFaction || xFac->removeCrimeFaction)) {
			return xFac->crimeFaction;
		}

		auto base = GetActorBase();
		return base ? base->crimeFaction : nullptr;
	}
}
