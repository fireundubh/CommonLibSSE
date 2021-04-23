#pragma once

#include "RE/NetImmerse/NiPoint3.h"


namespace RE
{
	class BSTaskPool
	{
	public:
		static BSTaskPool* GetSingleton();

		static bool ShouldUseTaskPool();

		std::uint32_t QueueBulletWaterDisplacementTask(float a_scale, const RE::NiPoint3& a_pos); // 45
	};
};