#pragma once

#include "RE/BSDevices/PlayerInputHandler/HeldStateHandler/HeldStateHandler.h"


namespace RE
{
	struct AttackBlockHandler : public HeldStateHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_AttackBlockHandler;


		virtual ~AttackBlockHandler();	// 00

		// override (PlayerInputHandler)
		virtual bool CanProcess(InputEvent* a_event) override;									// 01
		virtual void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_data) override;	// 04
		virtual void UpdateHeldStateActive(const ButtonEvent* a_event) override;				// 05
		virtual void SetHeldStateActive(bool a_flag) override;									// 06


		// members
		UInt64 unk18;  // 18
		UInt64 unk20;  // 20
		UInt64 unk28;  // 28
		UInt64 unk30;  // 30
		UInt64 unk38;  // 38
		UInt64 unk40;  // 40
	};
	STATIC_ASSERT(sizeof(AttackBlockHandler) == 0x48);
}
