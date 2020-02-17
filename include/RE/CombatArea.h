#pragma once

#include "RE/CombatObject.h"
#include "RE/CombatHandler.h"

namespace RE
{
	class BGSLoadGameBuffer;
	class BGSSaveGameBuffer;
	
	class CombatArea : public CombatObject
	{
	public:
		inline static const void* RTTI = RTTI_CombatArea;

		virtual ~CombatArea();											// 00

		// override
		virtual void	SaveGame(BGSSaveGameBuffer* a_buf) override;	// 03
		virtual void	LoadGame(BGSLoadGameBuffer* a_buf) override;	// 04
		// add
		virtual void	Unk_05() = 0;									// 05
		virtual void	Unk_06() = 0;									// 06
		virtual void	Unk_07() = 0;									// 07
		virtual void	Unk_08() = 0;									// 08
		virtual void	Unk_09() = 0;									// 09
		virtual void	Unk_0A() = 0;									// 0A
		virtual void	Unk_0B();										// 0B


		//members
		CombatHandler*	unk10;	// 10
		UInt64			unk18;	// 18
		UInt64			unk20;	// 20
		UInt32			unk28;	// 28
		UInt16			unk2C;	// 2C

	};
	STATIC_ASSERT(sizeof(CombatArea) == 0x30);
}
