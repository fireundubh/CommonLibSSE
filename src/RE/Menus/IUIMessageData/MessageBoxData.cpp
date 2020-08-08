#include "RE/Menus/IUIMessageData/MessageBoxData.h"


namespace RE
{
	void MessageBoxData::QueueMessage()
	{
		using func_t = decltype(&MessageBoxData::QueueMessage);
		REL::Relocation<func_t> func{ Offset::MessageBoxData::QueueMessage };
		return func(this);
	}
}
