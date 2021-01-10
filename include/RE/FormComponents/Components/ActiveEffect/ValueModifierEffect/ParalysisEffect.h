#pragma once

#include "RE/FormComponents/Components/ActiveEffect/ValueModifierEffect/ValueModifierEffect.h"


namespace RE
{
	class ParalysisEffect : public ValueModifierEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_AbsorbEffect;

		// override (ValueModifierEffect)
		virtual void Unk_04(void) override;	 // 04

		virtual ~ParalysisEffect();  // 13

		virtual void Unk_14(void) override;	 // 14
		virtual void Unk_15(void) override;	 // 15
	};
	static_assert(sizeof(ParalysisEffect) == 0x98);
}
