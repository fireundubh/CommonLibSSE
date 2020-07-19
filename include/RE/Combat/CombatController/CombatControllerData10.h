#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/FormComponents/Components/AITimeStamp.h"
#include "RE/FormComponents/Components/AITimer.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class BGSEquipSlot;
	class CombatController;
	class TESObjectWEAP;
	class TESForm;


	class CombatControllerData10
	{
	public:
		struct UnkStruct
		{
			BSTArray<void*> unk00;
			std::uint32_t	unk18;
			float			unk1C;
			float			unk20;
			float			unk24;
			std::uint32_t	unk28;
		};
		static_assert(sizeof(UnkStruct) == 0x30);


		struct Data178
		{
			std::uint64_t unk00;
			AITimeStamp	  unk08;
		};
		static_assert(sizeof(Data178) == 0x10);


		// members
		CombatController*		 unk000;
		BSTArray<void*>			 unk008[7];
		BSTArray<TESForm*>		 unk0B0;
		BSTArray<TESForm*>		 unk0C8;
		BSTArray<BGSEquipSlot*>* unk0E0;
		std::uint64_t			 unk0E8;
		std::uint32_t			 unk0F0;
		std::uint32_t			 unk0F4;
		std::uint32_t			 unk0F8;
		std::uint32_t			 unk0FC;
		std::uint64_t			 unk100;
		std::uint64_t			 unk108;
		std::uint64_t			 unk110;
		UnkStruct				 unk118;
		UnkStruct				 unk148;
		BSTArray<Data178>		 unk178;
		std::int32_t			 unk190;
		AITimer					 unk194;
		std::uint32_t			 unk19C;
		std::uint32_t			 unk1A0;
		std::uint32_t			 unk1A4;
		float					 unk1A8;
		float					 unk1AC;
		float					 unk1B0;
		std::uint32_t			 unk1B4;
		float					 unk1B8;
		float					 unk1BC;
		float					 unk1C0;
		std::uint8_t			 unk1C4;
	};
	static_assert(sizeof(CombatControllerData10) == 0x1C8);
}