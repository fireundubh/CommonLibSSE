#include "RE/TESForm.h"

#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/ExtraEnchantment.h"
#include "RE/FormTraits.h"
#include "RE/GlobalLookupInfo.h"
#include "RE/MagicItem.h"
#include "RE/TESFullName.h"
#include "RE/TESModel.h"
#include "RE/TESObjectREFR.h"
#include "RE/TESValueForm.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	TESForm* TESForm::LookupByID(FormID a_formID)
	{
		auto lookup = GlobalLookupInfo::GetSingleton();
		RE::BSReadLockGuard locker(lookup->formIDsLock);
		if (!lookup->formIDs) {
			return 0;
		}

		auto& formIDs = *lookup->formIDs;
		auto it = formIDs.find(a_formID);
		return it != formIDs.end() ? it->second : 0;
	}


	TESForm* TESForm::LookupByEditorID(const std::string_view& a_editorID)
	{
		auto lookup = GlobalLookupInfo::GetSingleton();
		RE::BSReadLockGuard locker(lookup->editorIDsLock);
		if (!lookup->editorIDs) {
			return 0;
		}

		auto& editorIDs = *lookup->editorIDs;
		auto it = editorIDs.find(a_editorID);
		return it != editorIDs.end() ? it->second : 0;
	}


	bool TESForm::Is(FormType a_type) const
	{
		return formType == a_type;
	}


	bool TESForm::IsNot(FormType a_type) const
	{
		return formType != a_type;
	}


	FormID TESForm::GetFormID() const
	{
		return formID;
	}


	FormType TESForm::GetFormType() const
	{
		return formType;
	}


	SInt32 TESForm::GetGoldValue() const
	{
		SInt32 value = 0;
		auto form = this;
		auto objRef = As<TESObjectREFR>();
		if (objRef) {
			form = objRef->GetBaseObject();
			auto xEnch = objRef->extraList.GetByType<ExtraEnchantment>();
			if (xEnch && xEnch->enchantment) {
				value += xEnch->enchantment->CalculateTotalGoldValue();
			}
		}

		auto valueForm = form->As<TESValueForm>();
		if (valueForm) {
			value += valueForm->value;
		} else {
			auto magicItem = form->As<MagicItem>();
			if (magicItem) {
				value += magicItem->CalculateTotalGoldValue();
			} else {
				value = -1;
			}
		}

		return value;
	}


	const char* TESForm::GetName() const
	{
		auto fullName = As<TESFullName>();
		if (fullName) {
			auto str = fullName->GetFullName();
			return str ? str : "";
		} else {
			return "";
		}
	}


	float TESForm::GetWeight() const
	{
		auto ref = As<TESObjectREFR>();
		auto baseObj = ref ? ref->GetBaseObject() : 0;
		auto form = baseObj ? baseObj : this;
		auto weightForm = form->As<TESWeightForm>();
		if (weightForm) {
			return weightForm->weight;
		} else if (form->Is(FormType::NPC)) {
			auto npc = static_cast<const TESNPC*>(form);
			return npc->weight;
		} else {
			return -1.0;
		}
	}


	bool TESForm::HasVMAD() const
	{
		auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
		if (!vm) {
			return false;
		}

		auto policy = vm->GetObjectHandlePolicy();
		if (!policy) {
			return false;
		}

		auto handle = policy->GetHandleForObject(formType, this);
		return handle != policy->EmptyHandle();
	}


	bool TESForm::HasWorldModel() const
	{
		return As<TESModel>() != 0;
	}


	bool TESForm::IsAmmo() const
	{
		return Is(FormType::Ammo);
	}


	bool TESForm::IsArmor() const
	{
		return Is(FormType::Armor);
	}


	bool TESForm::IsDeleted() const
	{
		return (formFlags & RecordFlags::kDeleted) != 0;
	}


	bool TESForm::IsDynamicForm() const
	{
		return formID >= 0xFF000000;
	}


	bool TESForm::IsGold() const
	{
		return formID == 0x0000000F;
	}


	bool TESForm::IsIgnored() const
	{
		return (formFlags & RecordFlags::kIgnored) != 0;
	}


	bool TESForm::IsKey() const
	{
		return Is(FormType::KeyMaster);
	}


	bool TESForm::IsLockpick() const
	{
		return formID == 0x0000000A;
	}


	bool TESForm::IsPlayer() const
	{
		return formID == 0x00000007;
	}


	bool TESForm::IsPlayerRef() const
	{
		return formID == 0x00000014;
	}


	bool TESForm::IsSoulGem() const
	{
		return Is(FormType::SoulGem);
	}


	bool TESForm::IsWeapon() const
	{
		return Is(FormType::Weapon);
	}
}
