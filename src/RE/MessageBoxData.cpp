#include "RE/MessageBoxData.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	void MessageBoxData::QueueMessage()
	{
		using func_t = decltype(&MessageBoxData::QueueMessage);
		REL::Offset<func_t> func(Offset::MessageBoxData::QueueMessage);
		return func(this);
	}
}
