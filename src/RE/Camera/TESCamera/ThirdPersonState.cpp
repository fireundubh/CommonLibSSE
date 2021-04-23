#include "RE/Camera/TESCameraState/ThirdPersonState/ThirdPersonState.h"


namespace RE
{
	void ThirdPersonState::UpdateOffsets(bool a_savedZoom, bool a_noTargetZoom)
	{
		using func_t = decltype(&ThirdPersonState::UpdateOffsets);
		REL::Relocation<func_t> func{ REL::ID(49964) };
		return func(this, a_savedZoom, a_noTargetZoom);
	}
}

