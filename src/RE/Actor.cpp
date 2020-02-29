#include "RE/Actor.h"

#include <type_traits>

#include "RE/AIProcess.h"
#include "RE/BGSAttackData.h"
#include "RE/BGSColorForm.h"
#include "RE/BGSDefaultObjectManager.h"
#include "RE/BSFaceGenAnimationData.h"
#include "RE/BSFaceGenNiNode.h"
#include "RE/BSGeometry.h"
#include "RE/ExtraCanTalkToPlayer.h"
#include "RE/ExtraFactionChanges.h"
#include "RE/FormTraits.h"
#include "RE/HighProcessData.h"
#include "RE/InventoryChanges.h"
#include "RE/InventoryEntryData.h"
#include "RE/MiddleHighProcessData.h"
#include "RE/Misc.h"
#include "RE/NiColor.h"
#include "RE/NiNode.h"
#include "RE/NiPoint3.h"
#include "RE/Offsets.h"
#include "RE/ProcessLists.h"
#include "RE/TESFaction.h"
#include "RE/TESNPC.h"
#include "RE/TESObjectMISC.h"
#include "RE/TESRace.h"
#include "RE/TESWorldSpace.h"
#include "REL/Relocation.h"


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
		REL::Offset<func_t> func(Offset::Actor::AddSpell);
		return func(this, a_spell);
	}


	void Actor::AllowBleedoutDialogue(bool a_canTalk)
	{
		if (a_canTalk) {
			boolFlags |= BOOL_FLAGS::kCanSpeakToEssentialDown;
		}
		else {
			boolFlags &= ~BOOL_FLAGS::kCanSpeakToEssentialDown;
		}
	}


	void Actor::AllowPCDialogue(bool a_talk)
	{
		auto xTalk = extraList.GetByType<ExtraCanTalkToPlayer>();
		if (xTalk) {
			xTalk = new ExtraCanTalkToPlayer();
			extraList.Add(xTalk);
		}

		xTalk->talk = a_talk;
	}


	bool Actor::CanFlyHere() const
	{
		auto worldSpace = GetWorldspace();
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
		}
		else {
			return race ? race->AllowsPCDialogue() : false;
		}
	}


	void Actor::ClearArrested()
	{
		if (currentProcess && currentProcess->IsArrested()) {
			currentProcess->SetArrested(false);
			EvaluatePackage(false, false);
			auto procManager = ProcessLists::GetSingleton();
			procManager->StopCombatAndAlarmOnActor(this, true);
		}
	}


	void Actor::ClearExpressionOverride()
	{
		auto faceGen = GetFaceGenAnimationData();
		if (faceGen) {
			faceGen->ClearExpressionOverride();
		}
	}


	void Actor::ClearExtraArrows()
	{
		extraList.RemoveByType(ExtraDataType::kAttachedArrows3D);
	}


	ActorHandle Actor::CreateRefHandle()
	{
		return ActorHandle(this);
	}


	void Actor::Decapitate()
	{
		using func_t = decltype(&Actor::Decapitate);
		REL::Offset<func_t> func(Offset::Actor::Decapitate);
		return func(this);
	}


	void Actor::DispelWornItemEnchantments()
	{
		using func_t = decltype(&Actor::DispelWornItemEnchantments);
		REL::Offset<func_t> func(Offset::Actor::DispelWornItemEnchantments);
		return func(this);
	}


	void Actor::DoReset3D(bool a_updateWeight)
	{
		using func_t = decltype(&Actor::DoReset3D);
		REL::Offset<func_t> func(Offset::Actor::DoReset3D);
		return func(this, a_updateWeight);
	}


	void Actor::EnableAI(bool a_enabled)
	{
		using func_t = decltype(&Actor::EnableAI);
		REL::Offset<func_t> func(Offset::Actor::EnableAI);
		return func(this, a_enabled);
	}


	void Actor::EvaluatePackage(bool a_arg1, bool a_arg2)
	{
		using func_t = decltype(&Actor::EvaluatePackage);
		REL::Offset<func_t> func(Offset::Actor::EvaluatePackage);
		return func(this, a_arg1, a_arg2);
	}


	TESNPC* Actor::GetActorBase()
	{
		auto obj = GetBaseObject();
		return obj ? obj->As<TESNPC>() : 0;
	}


	const TESNPC* Actor::GetActorBase() const
	{
		auto obj = GetBaseObject();
		return obj ? obj->As<TESNPC>() : 0;
	}


	InventoryEntryData* Actor::GetAttackingWeapon()
	{
		if (!currentProcess || !currentProcess->high || !currentProcess->high->attackData || !currentProcess->middleHigh) {
			return 0;
		}

		auto attackData = currentProcess->high->attackData;
		auto proc = currentProcess->middleHigh;

		return attackData->IsLeftAttack() ? proc->leftHand : proc->rightHand;
	}


	const InventoryEntryData* Actor::GetAttackingWeapon() const
	{
		if (!currentProcess || !currentProcess->high || !currentProcess->high->attackData || !currentProcess->middleHigh) {
			return 0;
		}

		auto attackData = currentProcess->high->attackData;
		auto proc = currentProcess->middleHigh;

		return attackData->IsLeftAttack() ? proc->leftHand : proc->rightHand;
	}


	bhkCharacterController* Actor::GetCharController() const
	{
		return currentProcess ? currentProcess->GetCharController() : 0;
	}


	TESFaction* Actor::GetCrimeFaction()
	{
		auto thisPtr = const_cast<const Actor*>(this);
		auto fac = thisPtr->GetCrimeFaction();
		return const_cast<TESFaction*>(fac);
	}


	const TESFaction* Actor::GetCrimeFaction() const
	{
		if (IsCommandedActor()) {
			return 0;
		}

		auto xFac = extraList.GetByType<ExtraFactionChanges>();
		if (xFac && (xFac->crimeFaction || xFac->removeCrimeFaction)) {
			return xFac->crimeFaction;
		}

		auto base = GetActorBase();
		return base ? base->crimeFaction : 0;
	}


	InventoryEntryData* Actor::GetEquippedEntryData(bool a_leftHand)
	{
		if (!currentProcess || !currentProcess->middleHigh) {
			return 0;
		}

		auto proc = currentProcess->middleHigh;
		return a_leftHand ? proc->leftHand : proc->rightHand;
	}


	const InventoryEntryData* Actor::GetEquippedEntryData(bool a_leftHand) const
	{
		if (!currentProcess || !currentProcess->middleHigh) {
			return 0;
		}

		auto proc = currentProcess->middleHigh;
		return a_leftHand ? proc->leftHand : proc->rightHand;
	}


	TESForm* Actor::GetEquippedObject(bool a_leftHand) const
	{
		if (currentProcess) {
			if (a_leftHand) {
				return currentProcess->GetEquippedLeftHand();
			}
			else {
				return currentProcess->GetEquippedRightHand();
			}
		}
		else {
			return 0;
		}
	}


	SInt32 Actor::GetGoldAmount()
	{
		auto inv = GetInventory([](TESBoundObject* a_object) -> bool
		{
			return a_object->IsGold();
		});

		auto dobj = BGSDefaultObjectManager::GetSingleton();
		auto gold = dobj->GetObject<TESObjectMISC>(DEFAULT_OBJECT::kGold);
		auto it = inv.find(gold);
		return it != inv.end() ? it->second.first : 0;
	}


	BSGeometry* Actor::GetHeadPartGeometry(BGSHeadPart::HeadPartType a_type)
	{
		auto faceNode = GetFaceNodeSkinned();
		auto actorBase = GetActorBase();

		if (faceNode && actorBase) {
			auto facePart = actorBase->GetCurrentHeadPartByType(a_type);
			if (facePart) {
				auto headNode = faceNode->GetObjectByName(facePart->formEditorID);
				if (headNode) {
					auto geometry = headNode->AsGeometry();
					if (geometry) {
						return geometry;
					}
				}
			}
		}

		return nullptr;
	}


	float Actor::GetHeight()
	{
		auto min = GetBoundMin();
		auto max = GetBoundMax();
		auto diff = max.z - min.z;
		auto height = GetBaseHeight() * diff;

		if (!currentProcess || !currentProcess->InHighProcess()) {
			return height;
		}

		auto cachedHeight = currentProcess->GetCachedHeight();
		if (cachedHeight == 0.0) {
			currentProcess->SetCachedHeight(height);
			return height;
		}
		else {
			return cachedHeight;
		}
	}


	UInt16 Actor::GetLevel() const
	{
		using func_t = decltype(&Actor::GetLevel);
		REL::Offset<func_t> func(Offset::Actor::GetLevel);
		return func(this);
	}


	TESRace* Actor::GetRace() const
	{
		auto base = GetActorBase();
		return base ? base->race : 0;
	}


	TESObjectARMO* Actor::GetSkin(BGSBipedObjectForm::BipedObjectSlot a_slot)
	{
		TESObjectARMO* equipped = nullptr;

		equipped = GetWornArmor(a_slot);
		if (!equipped) {
			auto actorBase = GetActorBase();
			if (actorBase) {
				equipped = actorBase->skin;
				auto baseRace = actorBase->race;
				if (!equipped && baseRace) {
					equipped = baseRace->skin;
				}
			}
		}

		return equipped;
	}


	SOUL_LEVEL Actor::GetSoulLevel() const
	{
		using func_t = decltype(&Actor::GetSoulLevel);
		REL::Offset<func_t> func(Offset::Actor::GetSoulLevel);
		return func(this);
	}


	TESObjectARMO* Actor::GetWornArmor(BGSBipedObjectForm::BipedObjectSlot a_slot)
	{
		auto changes = GetInventoryChanges();

		if (changes && changes->entryList) {
			for (auto& entry : *changes->entryList) {
				if (!entry || !entry->extraLists) {
					continue;
				}
				for (auto& xList : *entry->extraLists) {
					if (!xList || !xList->GetWorn()) {
						continue;
					}
					auto object = entry->object;
					if (!object || !object->IsArmor()) {
						continue;
					}
					auto armor = static_cast<TESObjectARMO*>(object);
					for (auto& armorAddon : armor->armorAddons) {
						if (armorAddon->HasPartOf(a_slot)) {
							return armor;
						}
					}
				}
			}
		}

		return nullptr;
	}


	TESObjectARMO* Actor::GetWornArmor(FormID id)
	{
		auto changes = GetInventoryChanges();

		if (changes && changes->entryList) {
			for (auto& entry : *changes->entryList) {
				if (!entry || !entry->extraLists) {
					continue;
				}
				for (auto& xList : *entry->extraLists) {
					if (!xList || !xList->GetWorn()) {
						continue;
					}
					auto object = entry->object;
					if (!object || !object->IsArmor() || object->formID != id) {
						continue;
					}
					return static_cast<TESObjectARMO*>(object);		
				}
			}
		}

		return nullptr;
	}


	bool Actor::HasPerk(BGSPerk* a_perk) const
	{
		using func_t = decltype(&Actor::HasPerk);
		REL::Offset<func_t> func(Offset::Actor::HasPerk);
		return func(this, a_perk);
	}


	bool Actor::HasSpell(SpellItem* a_spell) const
	{
		using func_t = decltype(&Actor::HasSpell);
		REL::Offset<func_t> func(Offset::Actor::HasSpell);
		return func(this, a_spell);
	}


	bool Actor::InstantKill()
	{
		using func_t = decltype(&Actor::InstantKill);
		REL::Offset<func_t> func(Offset::Actor::InstantKill);;
		return func(this);
	}


	bool Actor::IsAIEnabled() const
	{
		return (boolBits & BOOL_BITS::kProcessMe) != BOOL_BITS::kNone;
	}


	bool Actor::IsAMount() const
	{
		return (boolFlags & BOOL_FLAGS::kIsAMount) != BOOL_FLAGS::kNone;
	}


	bool Actor::IsBeingRidden() const
	{
		return IsAMount() && extraList.HasType(ExtraDataType::kInteraction);
	}


	bool Actor::IsCommandedActor() const
	{
		return (boolFlags & BOOL_FLAGS::kIsCommandedActor) != BOOL_FLAGS::kNone;
	}


	bool Actor::IsEssential() const
	{
		return (boolFlags & BOOL_FLAGS::kEssential) != BOOL_FLAGS::kNone;
	}


	bool Actor::IsProtected() const
	{
		return (boolFlags & BOOL_FLAGS::kProtected) != BOOL_FLAGS::kNone;
	}


	bool Actor::IsFactionInCrimeGroup(const TESFaction* a_faction) const
	{
		auto crimFac = GetCrimeFaction();
		if (!crimFac) {
			return false;
		}

		if (crimFac == a_faction) {
			return true;
		}
		else {
			return crimFac->IsFactionInCrimeGroup(a_faction);
		}
	}


	bool Actor::IsGhost() const
	{
		using func_t = decltype(&Actor::IsGhost);
		REL::Offset<func_t> func(Offset::Actor::GetGhost);
		return func(this);
	}


	bool Actor::IsGuard() const
	{
		return (boolBits & BOOL_BITS::kGuard) != BOOL_BITS::kNone;
	}


	bool Actor::IsHorse() const
	{
		auto dobj = BGSDefaultObjectManager::GetSingleton();
		auto horseKeyword = dobj->GetObject<BGSKeyword>(DEFAULT_OBJECT::kKeywordHorse);
		return horseKeyword && HasKeyword(horseKeyword);
	}


	bool Actor::IsHostileToActor(Actor* a_actor)
	{
		using func_t = decltype(&Actor::IsHostileToActor);
		REL::Offset<func_t> func(Offset::Actor::GetHostileToActor);
		return func(this, a_actor);
	}


	bool Actor::IsInKillMove() const
	{
		return (boolFlags & BOOL_FLAGS::kIsInKillMove) != BOOL_FLAGS::kNone;
	}


	bool Actor::IsOnMount() const
	{
		return !IsAMount() && extraList.HasType(ExtraDataType::kInteraction);
	}


	bool Actor::IsPlayerTeammate() const
	{
		return (boolBits & BOOL_BITS::kPlayerTeammate) != BOOL_BITS::kNone;
	}


	bool Actor::IsRunning() const
	{
		using func_t = decltype(&Actor::IsRunning);
		REL::Offset<func_t> func(Offset::Actor::IsRunning);
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


	bool Actor::IsSummoned() const
	{
		auto base = GetActorBase();
		return base ? base->IsSummonable() : false;
	}


	bool Actor::IsTrespassing() const
	{
		return (boolFlags & BOOL_FLAGS::kIsTrespassing) != BOOL_FLAGS::kNone;
	}


	bool Actor::RemoveSpell(SpellItem* a_spell)
	{
		using func_t = decltype(&Actor::RemoveSpell);
		REL::Offset<func_t> func(Offset::Actor::RemoveSpell);;
		return func(this, a_spell);
	}


	SInt32 Actor::RequestDetectionLevel(Actor* a_target, DETECTION_PRIORITY a_priority)
	{
		using func_t = decltype(&Actor::RequestDetectionLevel);
		REL::Offset<func_t> func(Offset::Actor::RequestDetectionLevel);
		return func(this, a_target, a_priority);
	}


	void Actor::StealAlarm(TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, SInt32 a_numItems, SInt32 a_value, TESForm* a_owner, bool a_allowGetBackStolenItemPackage)
	{
		using func_t = decltype(&Actor::StealAlarm);
		REL::Offset<func_t> func(Offset::Actor::StealAlarm);
		return func(this, a_refItemOrContainer, a_stolenItem, a_numItems, a_value, a_owner, a_allowGetBackStolenItemPackage);
	}


	void Actor::SwitchRace(TESRace* a_race, bool a_player)
	{
		using func_t = decltype(&Actor::SwitchRace);
		REL::Offset<func_t> func(Offset::Actor::SwitchRace);
		return func(this, a_race, a_player);
	}


	void Actor::UpdateArmorAbility(TESForm* a_armor, ExtraDataList* a_extraData)
	{
		using func_t = decltype(&Actor::UpdateArmorAbility);
		REL::Offset<func_t> func(Offset::Actor::UpdateArmorAbility);
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
		auto npc = GetActorBase();
		if (npc && npc->headRelatedData) {
			auto hairColor = npc->headRelatedData->hairColor;
			if (hairColor) {
				NiColor color;
				color.red = hairColor->color.red / 128.0;
				color.green = hairColor->color.green / 128.0;
				color.blue = hairColor->color.blue / 128.0;

				auto model = Get3D(false);
				if (model) {
					model->UpdateHairColor(color);
				}
			}
		}
	}


	void Actor::UpdateSkinColor()
	{
		auto npc = GetActorBase();
		if (npc) {
			NiColor color;
			color.red = npc->bodyTintColor.red / 255.0;
			color.green = npc->bodyTintColor.green / 255.0;
			color.blue = npc->bodyTintColor.blue / 255.0;

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
		REL::Offset<func_t> func(Offset::Actor::UpdateWeaponAbility);
		return func(this, a_weapon, a_extraData, a_leftHand);
	}


	NiAVObject* Actor::VisitArmorAddon(TESObjectARMO* a_armor, TESObjectARMA* a_arma)
	{
		char addonString[MAX_PATH];
		memset(addonString, 0, MAX_PATH);
		a_arma->GetNodeName(addonString, this, a_armor, -1);

		NiNode* skeletonRoot[2];
		skeletonRoot[0] = Get3D(0)->AsNode();
		skeletonRoot[1] = Get3D(1)->AsNode();

		if (skeletonRoot[1] == skeletonRoot[0]) {
			skeletonRoot[1] = nullptr;
		}

		for (UInt32 i = 0; i <= 1; i++) {
			if (skeletonRoot[i]) {
				BSFixedString addonName(addonString);
				auto armorObject = skeletonRoot[i]->GetObjectByName(addonName);
				if (armorObject) {
					return armorObject;
				}
			}
		}

		return nullptr;
	}


	bool Actor::VisitFactions(llvm::function_ref<bool(TESFaction * a_faction, SInt8 a_rank)> a_visitor)
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
}
