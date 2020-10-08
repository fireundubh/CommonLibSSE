#pragma once


namespace RE
{
	struct TESQuestStartStop
	{
	public:
		// members
		std::uint32_t questFormID;	// 00
		bool		  unk04;		// 04
		std::uint8_t  unk05;		// 05
		std::uint16_t pad06;		// 06
	};
	static_assert(sizeof(TESQuestStartStop) == 0x8);
}