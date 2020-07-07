#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSDevices/Enums/InputDevices.h"


namespace RE
{
	enum class INPUT_EVENT_TYPE : UInt32
	{
		kButton = 0,
		kMouseMove,
		kChar,
		kThumbstick,
		kDeviceConnect,
		kKinect
	};


	class ButtonEvent;
	class IDEvent;


	class InputEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_InputEvent;


		virtual ~InputEvent();	// 00

		virtual bool				 HasIDCode() const;	  // 01 - { return false; }
		virtual const BSFixedString& QUserEvent() const;  // 02 - { return ""; }

		[[nodiscard]] constexpr INPUT_EVENT_TYPE GetEventType() const noexcept { return eventType; }
		[[nodiscard]] constexpr INPUT_DEVICE	 GetDevice() const noexcept { return device; }

		[[nodiscard]] ButtonEvent*		 AsButtonEvent();
		[[nodiscard]] const ButtonEvent* AsButtonEvent() const;

		[[nodiscard]] IDEvent*		 AsIDEvent();
		[[nodiscard]] const IDEvent* AsIDEvent() const;


		// members
		INPUT_DEVICE	 device;	 // 08
		INPUT_EVENT_TYPE eventType;	 // 0C
		InputEvent*		 next;		 // 10
	};
	STATIC_ASSERT(sizeof(InputEvent) == 0x18);
}
