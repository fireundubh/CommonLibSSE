#pragma once

#include "RE/BSHavok/hkpEntityListener/hkpEntityListener.h"


namespace RE
{
	class bhkEntityListener : public hkpEntityListener
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkEntityListener;


		virtual ~bhkEntityListener();  // 00

		// override (hkpEntityListener)
		virtual void EntityAddedCallback(hkpEntity* a_entity) override;	   // 01
		virtual void EntityRemovedCallback(hkpEntity* a_entity) override;  // 02
		virtual void EntityDeletedCallback(hkpEntity* a_entity) override;  // 05 - { return; }

		// add
		virtual void Unk_06(void) = 0;	// 06
		virtual void Unk_07(void);		// 07 - { return 0; }
		virtual void Unk_08(void);		// 08 - { return 0; }
		virtual void Unk_09(void);		// 09


		// members
		std::uint32_t unk08; // 08
		std::uint32_t unk0C; // 0C
		std::uint64_t unk10; // 10

	};
	static_assert(sizeof(bhkEntityListener) == 0x18);
}