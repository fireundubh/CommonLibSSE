#include "RE/BSExtraData/ExtraTerminalState.h"


namespace RE
{
	ExtraTerminalState::ExtraTerminalState() :
		ExtraTerminalState(0)
	{}


	ExtraTerminalState::ExtraTerminalState(std::uint8_t a_state) :
		BSExtraData(),
		unk10(-1),
		unk11(a_state),
		pad12(0),
		pad14(0)
	{
		REL::Relocation<std::uintptr_t> vtbl{ REL::ID(229598) };
		((std::uintptr_t*)this)[0] = vtbl.address();
	}


	ExtraDataType ExtraTerminalState::GetType() const
	{
		return ExtraDataType::kTerminalState;
	}
}
