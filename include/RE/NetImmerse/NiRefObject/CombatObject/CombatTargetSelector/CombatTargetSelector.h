#pragma once

#include "RE/NetImmerse/NiRefObject/CombatObject/CombatObject.h"


namespace RE
{
	class BGSLoadGameBuffer;
	class BGSSaveGameBuffer;


	class CombatTargetSelector : public CombatObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatTargetSelector;


		virtual ~CombatTargetSelector();  // 00

		// override
		virtual void Unk_02() override;							   // 02
		virtual void SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		virtual void LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		// add
		virtual void Unk_05();		// 05
		virtual void Unk_06() = 0;	// 06


		// members
		std::uint64_t unk10;  // 10
		std::uint32_t unk18;  // 18
		std::uint32_t unk1C;  // 1C
		std::uint32_t unk20;  // 20
	};
	static_assert(sizeof(CombatTargetSelector) == 0x28);
}