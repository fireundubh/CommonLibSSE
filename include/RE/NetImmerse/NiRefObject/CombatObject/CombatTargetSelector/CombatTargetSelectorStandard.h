#pragma once

#include "RE/NetImmerse/NiRefObject/CombatObject/CombatTargetSelector/CombatTargetSelector.h"


namespace RE
{
	class BGSLoadGameBuffer;
	class BGSSaveGameBuffer;


	class CombatTargetSelectorStandard : public CombatTargetSelector
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatTargetSelectorStandard;


		virtual ~CombatTargetSelectorStandard();  // 00

		// override
		virtual void Unk_02() override;							   // 02
		virtual void SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		virtual void LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04
		virtual void Unk_06() override;							   // 06


		// members
		UInt64 unk28;  // 028
	};
	STATIC_ASSERT(sizeof(CombatTargetSelectorStandard) == 0x30);
}