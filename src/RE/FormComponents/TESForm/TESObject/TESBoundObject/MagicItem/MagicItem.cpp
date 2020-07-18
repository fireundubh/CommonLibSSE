#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/MagicItem/MagicItem.h"

#include "RE/FormComponents/Components/Effect.h"


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


	Effect* MagicItem::GetCostliestEffectItem(std::uint32_t a_arg1, bool a_arg2)
	{
		using func_t = decltype(&MagicItem::GetCostliestEffectItem);
		REL::Offset<func_t> func(Offset::MagicItem::GetCostliestEffectItem);
		return func(this, a_arg1, a_arg2);
	}


	float MagicItem::CalculateCost(Actor* a_caster) const
	{
		using func_t = decltype(&MagicItem::CalculateTotalGoldValue);
		REL::Offset<func_t> func(Offset::MagicItem::CalculateCost);
		return func(this, a_caster);
	}


	auto MagicItem::GetData()
		-> Data*
	{
		return GetData2();
	}


	auto MagicItem::GetData() const
		-> const Data*
	{
		return GetData1();
	}


	Effect* MagicItem::GetMatchingEffect(EffectSetting* a_base, float a_mag, UInt32 a_area, UInt32 a_dur, float a_cost)
	{
		for (auto& effect : effects) {
			if (effect->IsMatch(a_base, a_mag, a_area, a_dur, a_cost)) {
				return effect;
			}
		}
		return nullptr;
	}
}
