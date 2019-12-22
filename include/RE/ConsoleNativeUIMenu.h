#pragma once

#include <string_view>

#include "RE/IMenu.h"


namespace RE
{
	class ConsoleNativeUIMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_ConsoleNativeUIMenu;
		constexpr static std::string_view MENU_NAME = "Console Native UI Menu";


		virtual ~ConsoleNativeUIMenu();									// 00

		// override (IMenu)
		virtual Result ProcessMessage(UIMessage* a_message) override;	// 04


		// members
		UInt8	unk30;	// 30
		UInt8	pad31;	// 31
		UInt16	pad32;	// 32
		UInt32	pad34;	// 34
	};
	STATIC_ASSERT(sizeof(ConsoleNativeUIMenu) == 0x38);
}
