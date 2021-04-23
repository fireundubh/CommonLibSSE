#include "RE/Misc/BGSWaterSystemManager.h"


namespace RE
{
	BGSWaterSystemManager* BGSWaterSystemManager::GetSingleton()
	{
		REL::Relocation<BGSWaterSystemManager**> singleton{ REL::ID(514290) };
		return *singleton;
	}


	void BGSWaterSystemManager::CreateBulletWaterDisplacement(const RE::NiPoint3& a_pos, float a_scale)
	{
		using func_t = decltype(&BGSWaterSystemManager::CreateBulletWaterDisplacement);
		REL::Relocation<func_t> func{ REL::ID(31410) };
		return func(this, a_pos, a_scale);
	}
}