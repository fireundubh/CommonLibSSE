#include "RE/ExtraDataList.h"

#include "skse64/GameReferences.h"

#include "RE/BGSKeyword.h"
#include "RE/BSExtraData.h"
#include "RE/ExtraAshPileRef.h"
#include "RE/ExtraCount.h"
#include "RE/ExtraEncounterZone.h"
#include "RE/ExtraHealth.h"
#include "RE/ExtraLinkedRef.h"
#include "RE/ExtraMissingLinkedRefIDs.h"
#include "RE/ExtraOwnership.h"
#include "RE/ExtraReferenceHandle.h"
#include "RE/ExtraSoul.h"
#include "RE/ExtraTextDisplayData.h"
#include "RE/GameSettingCollection.h"
#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"
#include "RE/TESForm.h"
#include "REL/Relocation.h"


namespace RE
{
	ExtraDataList::ExtraDataList() :
		_data(0),
		_presence(0),
		_lock()
	{}


	ExtraDataList::~ExtraDataList()
	{
		while (_data) {
			auto xData = _data;
			_data = xData->next;
			delete xData;
		}
		_data = 0;

		free(_presence);
		_presence = 0;
	}


	ExtraDataList::iterator ExtraDataList::begin()
	{
		return iterator(_data);
	}


	ExtraDataList::const_iterator ExtraDataList::cbegin() const
	{
		return const_iterator(_data);
	}


	ExtraDataList::const_iterator ExtraDataList::begin() const
	{
		return cbegin();
	}


	ExtraDataList::iterator ExtraDataList::end()
	{
		return iterator(0);
	}


	ExtraDataList::const_iterator ExtraDataList::cend() const
	{
		return const_iterator(0);
	}


	ExtraDataList::const_iterator ExtraDataList::end() const
	{
		return cend();
	}


	bool ExtraDataList::HasType(ExtraDataType a_type) const
	{
		BSReadLockGuard locker(_lock);
		return _presence ? _presence->HasType(static_cast<UInt32>(a_type)) : false;
	}


	BSExtraData* ExtraDataList::GetByType(ExtraDataType a_type)
	{
		const ExtraDataList* thisPtr = this;
		auto xData = thisPtr->GetByType(a_type);
		return const_cast<BSExtraData*>(xData);
	}


	const BSExtraData* ExtraDataList::GetByType(ExtraDataType a_type) const
	{
		BSReadLockGuard locker(_lock);

		if (!HasType(a_type)) {
			return 0;
		}

		for (auto iter = _data; iter; iter = iter->next) {
			if (iter->GetType() == a_type) {
				return iter;
			}
		}

		return 0;
	}


	bool ExtraDataList::Remove(ExtraDataType a_type, BSExtraData* a_toRemove)
	{
		BSWriteLockGuard locker(_lock);

		if (!a_toRemove) {
			return false;
		}

		bool removed = false;

		if (_data == a_toRemove) {
			_data = _data->next;
			removed = true;
		} else {
			for (auto iter = _data; iter; iter = iter->next) {
				if (iter->next == a_toRemove) {
					iter->next = a_toRemove->next;
					removed = true;
					break;
				}
			}
		}

		if (removed) {
			MarkType(a_type, true);
		}

		return removed;
	}


	bool ExtraDataList::RemoveByType(ExtraDataType a_type)
	{
		BSWriteLockGuard locker(_lock);

		if (!_data) {
			return false;
		}

		bool removed = false;

		while (_data->GetType() == a_type) {
			auto tmp = _data;
			_data = _data->next;
			delete tmp;
			removed = true;
		}

		auto prev = _data;
		for (auto cur = _data->next; cur; cur = cur->next) {
			if (cur->GetType() == a_type) {
				prev->next = cur->next;
				delete cur;
				cur = prev;
				removed = true;
			}
			prev = cur;
		}

		MarkType(a_type, true);
		return removed;
	}


	BSExtraData* ExtraDataList::Add(BSExtraData* a_toAdd)
	{
		using func_t = function_type_t<decltype(&ExtraDataList::Add)>;
		REL::Offset<func_t*> func(Offset::ExtraDataList::Add);
		return func(this, a_toAdd);
	}


	const char* ExtraDataList::GenerateName(TESForm* a_form)
	{
		const char* result = 0;
		float health = 1.0;

		auto xHealth = GetByType<ExtraHealth>();
		if (xHealth) {
			health = xHealth->health;
		}

		auto xText = GetExtraTextDisplayData();
		bool dfHealth = health <= 1.0 ? (1.0 - health) < 0.001 : (health - 1.0) < 0.001;	// check for health == 1.0
		if (!xText && !dfHealth) {
			xText = new ExtraTextDisplayData();
			Add(xText);
		}

		if (xText) {
			result = xText->GenerateName(a_form, health);
		} else {
			result = a_form->GetName();
		}

		if (!result || result[0] == '\0') {
			auto gmst = GameSettingCollection::GetSingleton();
			auto sMissingName = gmst->GetSetting("sMissingName");
			result = sMissingName->GetString();
		}

		return result;
	}


	bool ExtraDataList::GetAshPileRefHandle(RefHandle& a_refHandle)
	{
		auto xAshRef = GetByType<ExtraAshPileRef>();
		if (xAshRef) {
			a_refHandle = xAshRef->refHandle;
		} else {
			a_refHandle = *g_invalidRefHandle;
		}
		return a_refHandle != *g_invalidRefHandle;
	}


	SInt32 ExtraDataList::GetCount() const
	{
		auto xCount = GetByType<ExtraCount>();
		return xCount ? xCount->count : 1;
	}


	BGSEncounterZone* ExtraDataList::GetEncounterZone()
	{
		auto xZone = GetByType<ExtraEncounterZone>();
		return xZone ? xZone->encounterZone : 0;
	}



	ExtraTextDisplayData* ExtraDataList::GetExtraTextDisplayData()
	{
		auto xRef = GetByType<ExtraReferenceHandle>();
		if (!xRef) {
			return 0;
		}

		auto ref = xRef->GetReference();
		if (!ref || !ref->IsDeleted()) {
			return GetByType<ExtraTextDisplayData>();
		} else {
			return 0;
		}
	}


	TESObjectREFR* ExtraDataList::GetLinkedRef(BGSKeyword* a_keyword)
	{
		BSReadLockGuard locker(_lock);

		auto xLinkedRef = GetByType<ExtraLinkedRef>();
		if (!xLinkedRef) {
			return 0;
		}

		TESObjectREFR* linkedRef = 0;
		for (auto& entry : xLinkedRef->entries) {
			if (entry.keyword == a_keyword) {
				linkedRef = entry.linkedRef;
				if (!linkedRef && HasType(ExtraDataType::kEditorID)) {
					auto xMissingLinkedRefIDs = GetByType<ExtraMissingLinkedRefIDs>();
					linkedRef = xMissingLinkedRefIDs->GetLinkedRef(a_keyword);
				}
			}

			if (linkedRef) {
				break;
			}
		}

		return linkedRef;
	}


	TESForm* ExtraDataList::GetOwner()
	{
		auto xOwner = GetByType<ExtraOwnership>();
		return xOwner ? xOwner->owner : 0;
	}


	SOUL_LEVEL ExtraDataList::GetSoulLevel() const
	{
		auto xSoul = GetByType<ExtraSoul>();
		return xSoul ? xSoul->containedSoul : SOUL_LEVEL::kNone;
	}


	void ExtraDataList::SetExtraFlags(ExtraFlags::Flag a_flags, bool a_enable)
	{
		using func_t = function_type_t<decltype(&ExtraDataList::SetExtraFlags)>;
		REL::Offset<func_t*> func(Offset::ExtraDataList::SetExtraFlags);
		return func(this, a_flags, a_enable);
	}


	void ExtraDataList::SetInventoryChanges(InventoryChanges* a_changes)
	{
		using func_t = function_type_t<decltype(&ExtraDataList::SetInventoryChanges)>;
		REL::Offset<func_t*> func(Offset::ExtraDataList::SetInventoryChanges);
		return func(this, a_changes);
	}


	void ExtraDataList::SetOwner(TESForm* a_owner)
	{
		if (a_owner && a_owner->IsDynamicForm()) {
			return;
		}

		auto xOwner = GetByType<ExtraOwnership>();
		if (xOwner) {
			if (a_owner) {
				xOwner->owner = a_owner;
			} else {
				Remove(xOwner);
			}
		} else if (a_owner) {
			xOwner = new ExtraOwnership(a_owner);
			Add(xOwner);
		}
	}


	bool ExtraDataList::PresenceBitfield::HasType(UInt32 a_type) const
	{
		UInt32 index = (a_type >> 3);
		if (index >= 0x18) {
			return false;
		}
		UInt8 bitMask = 1 << (a_type % 8);
		return (bits[index] & bitMask) != 0;
	}


	void ExtraDataList::PresenceBitfield::MarkType(UInt32 a_type, bool a_cleared)
	{
		UInt32 index = (a_type >> 3);
		UInt8 bitMask = 1 << (a_type % 8);
		auto& flag = bits[index];
		if (a_cleared) {
			flag &= ~bitMask;
		} else {
			flag |= bitMask;
		}
	}


	void ExtraDataList::MarkType(UInt32 a_type, bool a_cleared)
	{
		_presence->MarkType(a_type, a_cleared);
	}


	void ExtraDataList::MarkType(ExtraDataType a_type, bool a_cleared)
	{
		MarkType(static_cast<UInt32>(a_type), a_cleared);
	}
}
