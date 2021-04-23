#include "RE/Misc/BSTaskPool.h"


namespace RE
{
	BSTaskPool* BSTaskPool::GetSingleton()
	{
		REL::Relocation<BSTaskPool**> singleton{ Offset::BSTaskPool::Singleton };
		return *singleton;
	}
	
	
	bool BSTaskPool::ShouldUseTaskPool()
	{
		using func_t = decltype(&BSTaskPool::ShouldUseTaskPool);
		REL::Relocation<func_t> func{ REL::ID(38079) };
		return func();
	}


	std::uint32_t BSTaskPool::QueueBulletWaterDisplacementTask(float a_scale, const RE::NiPoint3& a_pos)
	{
		using func_t = decltype(&BSTaskPool::QueueBulletWaterDisplacementTask);
		REL::Relocation<func_t> func{ REL::ID(35978) };
		return func(this, a_scale, a_pos);
	}
}
