#pragma once

#include "RE/DetectionListener.h"

namespace RE
{
	class CombatGroup;
	
	class CombatGroupDetectionListener : public DetectionListener
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatGroupDetectionListener;


		virtual ~CombatGroupDetectionListener();  // 00

		// override (DetectionListener)
		virtual void Unk_02(void) override;	 // 01
		virtual void Unk_05(void);	// 01 - { unk10 = 0; }


		// members
		CombatGroup* combatGroup;	// 10
	};
	STATIC_ASSERT(sizeof(CombatGroupDetectionListener) == 0x18);
}
