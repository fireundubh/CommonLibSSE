#pragma once

#include "RE/CombatArea.h"

#include "RE/CombatLocation.h"


namespace RE
{
	class BGSLoadGameBuffer;
	class BGSSaveGameBuffer;


	class CombatAreaRadius : public CombatArea
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatAreaRadius;


		virtual ~CombatAreaRadius();  // 00

		// override
		virtual void Unk_02() override;							   // 02
		virtual void SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		virtual void LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04
		virtual void Unk_05() override;							   // 05
		virtual void Unk_06() override;							   // 06
		virtual void Unk_07() override;							   // 07
		virtual void Unk_08() override;							   // 08
		virtual void Unk_09() override;							   // 09
		virtual void Unk_0A() override;							   // 0A


		//members
		CombatLocation pos;		// 30
		float		   radius;	// 48
	};
	STATIC_ASSERT(sizeof(CombatAreaRadius) == 0x50);
}