#pragma once

#include "RE/DetectionListener.h"
#include "RE/CombatGroup.h"

namespace RE
{
	class CombatGroupDetectionListener : public DetectionListener
	{
	public:
		inline static const void* RTTI = RTTI_CombatGroupDetectionListener;


		virtual ~CombatGroupDetectionListener();	// 00

		// override (DetectionListener)
		virtual void	Unk_02(void) override;		// 01

		// add
		virtual void	Unk_05(void);				// 01 - { unk10 = 0; }


		// members
		CombatGroup* combatGroup;	// 10
	};
	STATIC_ASSERT(sizeof(CombatGroupDetectionListener) == 0x18);
}
