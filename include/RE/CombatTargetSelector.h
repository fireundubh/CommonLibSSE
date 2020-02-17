#pragma once

#include "RE/CombatObject.h"

namespace RE
{
	class BGSLoadGameBuffer;
	class BGSSaveGameBuffer;

	class CombatTargetSelector : public CombatObject
	{
	public:
		inline static const void* RTTI = RTTI_CombatTargetSelector;

		virtual ~CombatTargetSelector();								// 00

		// override
		virtual void	Unk_02() override;								// 02
		virtual void	SaveGame(BGSSaveGameBuffer* a_buf) override;	// 03
		virtual void	LoadGame(BGSLoadGameBuffer* a_buf) override;	// 04
		// add
		virtual void	Unk_05();										// 05
		virtual void	Unk_06() = 0;									// 06


		//members
		UInt64	unk10;	// 10
		UInt32	unk18;	// 18
		UInt32	unk1C;	// 1C
		UInt32	unk20;	// 20

	};
	STATIC_ASSERT(sizeof(CombatTargetSelector) == 0x28);
}