#pragma once

#include "RE/NetImmerse/NiRefObject/NiRefObject.h"


namespace RE
{
	class BGSLoadGameBuffer;
	class BGSSaveGameBuffer;


	class CombatObject : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatObject;


		virtual ~CombatObject();  // 00

		// add
		virtual void Unk_02() = 0;						  // 02
		virtual void SaveGame(BGSSaveGameBuffer* a_buf);  // 03 - { return }
		virtual void LoadGame(BGSLoadGameBuffer* a_buf);  // 04 - { return }
	};
	static_assert(sizeof(CombatObject) == 0x10);
}