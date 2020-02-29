#include "RE/BSTaskPool.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTaskPool* BSTaskPool::GetSingleton()
	{
		REL::Offset<BSTaskPool**> singleton(Offset::BSTaskPool::Singleton);
		return *singleton;
	}
}
