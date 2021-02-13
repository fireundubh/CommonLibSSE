#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraTerminalState : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraTerminalState;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kTerminalState;

		
		ExtraTerminalState();
		explicit ExtraTerminalState(std::uint8_t a_state);
		virtual ~ExtraTerminalState() = default;	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kTerminalState; }


		// members
		std::int8_t	  unk10;  // 10
		std::uint8_t  unk11;  // 11
		std::uint16_t pad12;  // 12
		std::uint32_t pad14;  // 14
	};
	static_assert(sizeof(ExtraTerminalState) == 0x18);
}
