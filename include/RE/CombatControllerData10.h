#pragma once

#include "RE/BSTArray.h"
#include "RE/AITimer.h"
#include "RE/AITimeStamp.h"
#include "RE/NiSmartPointer.h"


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
			UInt32          unk18;
			float			unk1C;
			float           unk20;
			float           unk24;
			UInt32          unk28;
		};
		STATIC_ASSERT(sizeof(UnkStruct) == 0x30);


		struct Data178
		{
			UInt64		unk00;
			AITimeStamp	unk08;
		};
		STATIC_ASSERT(sizeof(Data178) == 0x10);


		// members
		CombatController*			unk000;
		BSTArray<void*>             unk008[7];	
		BSTArray<TESForm*>          unk0B0;
		BSTArray<TESForm*>          unk0C8;
		BSTArray<BGSEquipSlot*>*	unk0E0;
		UInt64						unk0E8;
		UInt32						unk0F0;
		UInt32						unk0F4;
		UInt32						unk0F8;
		UInt32						unk0FC;
		UInt64						unk100;
		UInt64						unk108;
		UInt64						unk110;
		UnkStruct					unk118;
		UnkStruct					unk148;
		BSTArray<Data178>			unk178;
		SInt32						unk190;
		AITimer						unk194;
		UInt32						unk19C;
		UInt32						unk1A0;
		UInt32						unk1A4;
		float						unk1A8;
		float						unk1AC;
		float						unk1B0;
		UInt32						unk1B4;
		float						unk1B8;
		float						unk1BC;
		float						unk1C0;
		UInt8						unk1C4;
	};
	STATIC_ASSERT(sizeof(CombatControllerData10) == 0x1C8);
}