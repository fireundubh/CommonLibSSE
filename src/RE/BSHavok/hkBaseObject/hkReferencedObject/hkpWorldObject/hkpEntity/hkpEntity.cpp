#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpWorldObject/hkpEntity/hkpEntity.h"


namespace RE
{
	void hkpEntity::Activate()
	{
		using func_t = decltype(&hkpEntity::Activate);
		REL::Relocation<func_t> func{ REL::ID(60096) };
		return func(this);
	}


	void hkpEntity::Deactivate()
	{
		using func_t = decltype(&hkpEntity::Activate);
		REL::Relocation<func_t> func{ REL::ID(60097) };
		return func(this);
	}
}
