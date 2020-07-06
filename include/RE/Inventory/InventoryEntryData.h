#pragma once

#include "RE/BSCore/BSTList.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/Enums/SoulLevels.h"
#include "RE/Memory/MemoryManager.h"


namespace RE
{
	class ExtraDataList;
	class TESBoundObject;


	class InventoryEntryData
	{
	public:
		InventoryEntryData();
		InventoryEntryData(const InventoryEntryData& a_rhs);
		InventoryEntryData(InventoryEntryData&& a_rhs);
		InventoryEntryData(TESBoundObject* a_object, SInt32 a_countDelta);
		~InventoryEntryData();

		InventoryEntryData& operator=(const InventoryEntryData& a_rhs);
		InventoryEntryData& operator=(InventoryEntryData&& a_rhs);

		void				  AddExtraList(ExtraDataList* a_extra);
		const char*			  GetDisplayName();
		std::optional<double> GetEnchantmentCharge() const;
		TESBoundObject*		  GetObject();
		const TESBoundObject* GetObject() const;
		TESForm*			  GetOwner();
		SOUL_LEVEL			  GetSoulLevel() const;
		SInt32				  GetValue();
		float				  GetWeight() const;
		bool				  GetWorn() const;
		bool				  IsEnchanted() const;
		bool				  IsOwnedBy(Actor* a_testOwner, bool a_defaultTo = true);
		bool				  IsOwnedBy(Actor* a_testOwner, TESForm* a_itemOwner, bool a_defaultTo = true);
		bool				  CanItemBeTaken(bool a_noEquipped, bool a_noFavourited, bool a_noQuestItem);

		TES_HEAP_REDEFINE_NEW();


		// members
		TESBoundObject*				  object;	   // 00
		BSSimpleList<ExtraDataList*>* extraLists;  // 08
		SInt32						  countDelta;  // 10
		UInt32						  pad14;	   // 14

	private:
		bool IsOwnedBy_Impl(Actor* a_testOwner, TESForm* a_itemOwner, bool a_defaultTo);
	};
	STATIC_ASSERT(sizeof(InventoryEntryData) == 0x18);
}
