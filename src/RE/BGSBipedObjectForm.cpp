#include "RE/BGSBipedObjectForm.h"


namespace RE
{
	auto BGSBipedObjectForm::AddSlotToMask(BipedObjectSlot a_slot)
		-> BipedObjectSlot
	{
		bipedModelData.bipedObjectSlots |= a_slot;
		return bipedModelData.bipedObjectSlots;
	}


	auto BGSBipedObjectForm::GetArmorType() const
		-> ArmorType
	{
		return bipedModelData.armorType;
	}


	auto BGSBipedObjectForm::GetSlotMask() const
		-> BipedObjectSlot
	{
		return bipedModelData.bipedObjectSlots;
	}


	bool BGSBipedObjectForm::HasPartOf(BipedObjectSlot a_flag) const
	{
		return (bipedModelData.bipedObjectSlots & a_flag) != BipedObjectSlot::kNone;
	}


	bool BGSBipedObjectForm::IsClothing() const
	{
		return bipedModelData.armorType == ArmorType::kClothing;
	}


	bool BGSBipedObjectForm::IsHeavyArmor() const
	{
		return bipedModelData.armorType == ArmorType::kHeavyArmor;
	}


	bool BGSBipedObjectForm::IsLightArmor() const
	{
		return bipedModelData.armorType == ArmorType::kLightArmor;
	}


	bool BGSBipedObjectForm::IsShield() const
	{
		return (bipedModelData.bipedObjectSlots & BipedObjectSlot::kShield) != BipedObjectSlot::kNone;
	}


	auto BGSBipedObjectForm::RemoveSlotFromMask(BipedObjectSlot a_slot)
		-> BipedObjectSlot
	{
		if (a_slot != BipedObjectSlot::kNone) {
			bipedModelData.bipedObjectSlots &= ~a_slot;
		}
		return bipedModelData.bipedObjectSlots;
	}


	void BGSBipedObjectForm::SetSlotMask(BipedObjectSlot a_mask)
	{
		bipedModelData.bipedObjectSlots = a_mask;
	}
}
