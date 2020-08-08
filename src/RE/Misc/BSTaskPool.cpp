#include "RE/Misc/BSTaskPool.h"


namespace RE
{
	BSTaskPool* BSTaskPool::GetSingleton()
	{
		REL::Relocation<BSTaskPool**> singleton{ Offset::BSTaskPool::Singleton };
		return *singleton;
	}
}
