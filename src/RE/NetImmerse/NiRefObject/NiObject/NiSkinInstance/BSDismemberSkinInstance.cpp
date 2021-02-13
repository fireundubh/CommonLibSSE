#include "RE/NetImmerse/NiRefObject/NiObject/NiSkinInstance/BSDismemberSkinInstance.h"


namespace RE
{
	void BSDismemberSkinInstance::UpdateDismemberPartion(std::uint16_t a_slot, bool a_enable) const
	{
		using func_t = decltype(&BSDismemberSkinInstance::UpdateDismemberPartion);
		REL::Relocation<func_t> func{ REL::ID(15576) };
		return func(this, a_slot, a_enable);
	}
}
