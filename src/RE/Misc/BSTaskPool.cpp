#include "RE/Misc/BSTaskPool.h"


namespace RE
{
	BSTaskPool* BSTaskPool::GetSingleton()
	{
		REL::Offset<BSTaskPool**> singleton(Offset::BSTaskPool::Singleton);
		return *singleton;
	}
}
