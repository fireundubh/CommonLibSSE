#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/Combat/Components/CombatLocation.h"
#include "RE/FormComponents/Components/AITimeStamp.h"
#include "RE/FormComponents/Components/AITimer.h"
#include "RE/FormComponents/Components/DetectionListener/CombatGroupDetectionListener.h"


namespace RE
{
	class BSPathingLOSGridMap;


	class CombatGroup
	{
	public:
		struct TargetData
		{
			ActorHandle	   target;						   // 00
			SInt32		   detectLevel;					   // 04 //-1000
			float		   stealthPoints;				   // 08 //fCombatStealthPointMax - 1.0
			float		   unk0C;						   // 0C
			CombatLocation unk10;						   // 10
			CombatLocation unk28;						   // 28
			CombatLocation unk40;						   // 40
			CombatLocation unk58;						   // 58
			CombatLocation unk70;						   // 70
			AITimeStamp	   unk88;						   // 88
			AITimeStamp	   unk8C;						   // 8C
			AITimeStamp	   unk90;						   // 9C
			AITimeStamp	   unk94;						   // 94
			AITimeStamp	   stealthPointRegenAttackedTime;  // 98
			AITimeStamp	   stealthPointRegenDetectTime;	   // 9C
			ActorHandle	   attackedMember;				   // A0
			UInt16		   unkA4;						   // A4 //target count
			UInt16		   unkA6;						   // A6 //flags
		};
		STATIC_ASSERT(sizeof(TargetData) == 0xA8);


		struct MemberData
		{
			ActorHandle member;	 // 00
			float		unk04;	 // 04
			float		unk08;	 // 08
		};
		STATIC_ASSERT(sizeof(MemberData) == 0x0C);


		struct Data120
		{
			CombatLocation unk00;  // 10
			AITimeStamp	   unk18;  // 18
			float		   unk20;  // 20
		};
		STATIC_ASSERT(sizeof(Data120) == 0x20);


		struct Data138
		{
			ObjectRefHandle unk00;	// 00
			ObjectRefHandle unk04;	// 04
			UInt8			unk08;	// 08
			UInt8			unk09;	// 09
			UInt8			unk0A;	// 0A
		};
		STATIC_ASSERT(sizeof(Data138) == 0xC);


		// members
		UInt32						  unk00;					 // 000
		UInt32						  groupIndex;				 // 004
		BSTArray<TargetData>		  targets;					 // 008
		BSTArray<MemberData>		  members;					 // 020
		CombatGroupDetectionListener* detectionListener;		 // 038
		AITimer						  allyKilledDialogueTimer;	 // 040
		AITimer						  avoidThreatDialogueTimer;	 // 048
		AITimer						  groupStrengthUpdateTimer;	 // 050
		AITimer						  dialogues[11];			 // 058
		AITimer						  unkB0;					 // 0B0
		AITimer						  musicThreatRatioTimer;	 // 0B8
		AITimer						  unkC0;					 // 0C0 // -1.0
		float						  unkC8;					 // 0C8 // -1.0
		float						  unkCC;					 // 0CC // -1.0
		float						  unkD0;					 // 0D0 // -1.0
		float						  unkD4;					 // 0D4 // -1.0
		UInt32						  searchStatus;				 // 0D8
		UInt32						  padDC;					 // 0DC
		BSPathingLOSGridMap*		  gridMap;					 // 0E0
		AITimer						  searchUpdateTimer;		 // 0E8
		AITimer						  searchAreaUpdateTimer;	 // 0F0
		AITimeStamp					  unkF8;					 // 0F8
		ActorHandle					  targetToSearchFor;		 // 0FC
		CombatLocation				  searchLocation;			 // 100
		float						  searchRadius;				 // 118
		UInt32						  unk11C;					 // 11C
		BSTArray<Data120>			  unk120;					 // 120
		BSTArray<Data138>			  unk138;					 // 138
		UInt32						  unk150;					 // 150 // count
		UInt32						  unk154;					 // 154 // count
		UInt32						  unk158;					 // 158 // count
		SInt8						  unk15C;					 // 15C
		UInt8						  unk15D;					 // 15D
		UInt8						  unk15E;					 // 15E
		UInt8						  unk15F;					 // 15F
		mutable BSReadWriteLock		  unk160;					 // 160
	};
	STATIC_ASSERT(sizeof(CombatGroup) == 0x168);
}