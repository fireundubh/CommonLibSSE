#pragma once

#include "RE/CombatAreaRadius.h"


namespace RE
{
	class BGSLoadGameBuffer;
	class BGSSaveGameBuffer;


	class CombatAreaStandard : public CombatAreaRadius
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatAreaStandard;


		virtual ~CombatAreaStandard();									// 00

		// override
		virtual void	Unk_02() override;								// 02
		virtual void	Unk_0B() override;								// 0B

	};
	STATIC_ASSERT(sizeof(CombatAreaStandard) == 0x50);
}