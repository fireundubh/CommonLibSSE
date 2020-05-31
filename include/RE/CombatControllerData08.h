#pragma once

#include "RE/AITimeStamp.h"
#include "RE/AITimer.h"
#include "RE/BSTArray.h"
#include "RE/CombatLocation.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class CombatController;


	class CombatControllerData08
	{
	public:
		struct Data80
		{
			CombatLocation unk00;  // 10
			AITimeStamp	   unk18;  // 18
			float		   unk20;  // 20
		};
		STATIC_ASSERT(sizeof(Data80) == 0x20);


		// members
		float			  unk00;						 // 00
		bool			  unk04;						 // 04
		UInt8			  unk05;						 // 05
		UInt8			  unk06;						 // 06
		UInt8			  unk07;						 // 07
		UInt8			  unk08;						 // 08
		UInt8			  unk09;						 // 09
		UInt8			  unk0A;						 // 0A
		UInt8			  unk0B;						 // 0B
		UInt32			  unk0C;						 // 0C
		NiPoint3		  unk10;						 // 10
		AITimeStamp		  activeCombatantLastSeenTimer;	 // 1C
		AITimeStamp		  unk20;						 // 20
		AITimeStamp		  unk24;						 // 24
		AITimeStamp		  unk28;						 // 28
		AITimer			  attackDialogueTimer;			 // 2C
		AITimer			  tauntDialogueTimer;			 // 34
		AITimer			  bleedOutDialogueTimer;		 // 3C
		AITimer			  fleeDialogueTimer;			 // 44
		UInt32			  unk4C;						 // 4C
		BSTArray<void*>	  unk50;						 // 50
		AITimeStamp		  unk68;						 // 68
		UInt8			  unk6C;						 // 6C
		UInt8			  unk6D;						 // 6D
		float			  confidence;					 // 70
		float			  unk74;						 // 74
		float			  unk78;						 // 78
		UInt32			  unk7C;						 // 7C
		BSTArray<Data80>  unk80;						 // 80
		CombatController* unk98;						 // 98
		UInt8			  unkA0;						 // A0
		AITimer			  strengthUpdateTimer;			 // A4
		AITimer			  threatRatioUpdateTimer;		 // AC
		AITimer			  threatUpdateTimer;			 // B4
	};
	STATIC_ASSERT(sizeof(CombatControllerData08) == 0xC0);
}