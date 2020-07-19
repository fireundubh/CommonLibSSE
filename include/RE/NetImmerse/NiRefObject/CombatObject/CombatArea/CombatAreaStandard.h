#pragma once

#include "RE/NetImmerse/NiRefObject/CombatObject/CombatArea/CombatAreaRadius.h"


namespace RE
{
	class CombatAreaStandard : public CombatAreaRadius
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatAreaStandard;


		virtual ~CombatAreaStandard();	// 00

		// override
		virtual void Unk_02() override;	 // 02
		virtual void Unk_0B() override;	 // 0B
	};
	static_assert(sizeof(CombatAreaStandard) == 0x50);
}