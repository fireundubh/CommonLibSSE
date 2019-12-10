#include "RE/MagicItem.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	float MagicItem::CalculateMagickaCost(Actor* a_caster) const
	{
		return CalculateCost(a_caster);
	}


	float MagicItem::CalculateTotalGoldValue(Actor* a_caster) const
	{
		return CalculateCost(a_caster);
	}


	Effect* MagicItem::GetCostliestEffectItem(UInt32 a_arg1, bool a_arg2)
	{
		using func_t = function_type_t<decltype(&MagicItem::GetCostliestEffectItem)>;
		REL::Offset<func_t*> func(Offset::MagicItem::GetCostliestEffectItem);
		return func(this, a_arg1, a_arg2);
	}


	float MagicItem::CalculateCost(Actor* a_caster) const
	{
		using func_t = function_type_t<decltype(&MagicItem::CalculateTotalGoldValue)>;
		REL::Offset<func_t*> func(Offset::MagicItem::CalculateCost);
		return func(this, a_caster);
	}
}
