#include "RE/FormComponents/Components/Effect.h"


namespace RE
{
	Effect::EffectItem::EffectItem() :
		magnitude(0.0),
		area(0),
		duration(0)
	{}


	Effect::Effect() :
		effectItem(),
		pad0C(0),
		baseEffect(nullptr),
		cost(0.0),
		pad1C(0),
		conditions()
	{}


	inline bool essentiallyEqual(const float a, const float b)
	{
		return std::fabs(a - b) <= ((std::fabs(a) > std::fabs(b) ? std::fabs(b) : std::fabs(a)) * std::numeric_limits<float>::epsilon());
	}


	bool Effect::IsMatch(EffectSetting* a_base, float a_mag, std::uint32_t a_area, std::uint32_t a_dur, float a_cost)
	{
		return baseEffect == a_base && essentiallyEqual(effectItem.magnitude, a_mag) && effectItem.area == a_area && effectItem.duration == a_dur && essentiallyEqual(cost, a_cost);
	}
}
