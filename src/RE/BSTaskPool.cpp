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

	UInt32 BSTaskPool::func5C1AF0() //EE - Frame Hook
	{
		using func_t = decltype(&BSTaskPool::func5C1AF0);
		REL::Offset<func_t> func(Offset::BSTaskPool::func5C1AF0);
		return func(this);
	}
}
