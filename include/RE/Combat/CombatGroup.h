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
			ActorHandle	   targetHandle;				   // 00
			std::int32_t   detectLevel;					   // 04
			float		   stealthPoints;				   // 08
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
			std::uint16_t  unkA4;						   // A4 - target count
			std::uint16_t  unkA6;						   // A6 - flags
		};
		static_assert(sizeof(TargetData) == 0xA8);


		struct AllyData
		{
			ActorHandle allyHandle;	 // 00
			float		unk04;		 // 04
			float		unk08;		 // 08
		};
		static_assert(sizeof(AllyData) == 0x0C);


		struct Data120
		{
			CombatLocation unk00;  // 10
			AITimeStamp	   unk18;  // 18
			float		   unk20;  // 20
		};
		static_assert(sizeof(Data120) == 0x20);


		struct Data138
		{
			ObjectRefHandle unk00;	// 00
			ObjectRefHandle unk04;	// 04
			std::uint8_t	unk08;	// 08
			std::uint8_t	unk09;	// 09
			std::uint8_t	unk0A;	// 0A
		};
		static_assert(sizeof(Data138) == 0xC);


		// members
		std::uint32_t				  unk00;					 // 000
		std::uint32_t				  groupIndex;				 // 004
		BSTArray<TargetData>		  targets;					 // 008
		BSTArray<AllyData>			  allies;					 // 020
		CombatGroupDetectionListener* detectionListener;		 // 038
		AITimer						  allyKilledDialogueTimer;	 // 040
		AITimer						  avoidThreatDialogueTimer;	 // 048
		AITimer						  groupStrengthUpdateTimer;	 // 050
		AITimer						  dialogues[11];			 // 058
		AITimer						  unkB0;					 // 0B0
		AITimer						  musicThreatRatioTimer;	 // 0B8
		AITimer						  unkC0;					 // 0C0
		float						  unkC8;					 // 0C8
		float						  unkCC;					 // 0CC
		float						  unkD0;					 // 0D0
		float						  unkD4;					 // 0D4
		std::uint32_t				  searchStatus;				 // 0D8
		std::uint32_t				  padDC;					 // 0DC
		BSPathingLOSGridMap*		  gridMap;					 // 0E0
		AITimer						  searchUpdateTimer;		 // 0E8
		AITimer						  searchAreaUpdateTimer;	 // 0F0
		AITimeStamp					  unkF8;					 // 0F8
		ActorHandle					  targetToSearchFor;		 // 0FC
		CombatLocation				  searchLocation;			 // 100
		float						  searchRadius;				 // 118
		std::uint32_t				  unk11C;					 // 11C
		BSTArray<Data120>			  unk120;					 // 120
		BSTArray<Data138>			  unk138;					 // 138
		std::uint32_t				  unk150;					 // 150 - count
		std::uint32_t				  unk154;					 // 154 - count
		std::uint32_t				  unk158;					 // 158 - count
		std::int8_t					  unk15C;					 // 15C
		std::uint8_t				  unk15D;					 // 15D
		std::uint8_t				  unk15E;					 // 15E
		std::uint8_t				  unk15F;					 // 15F
		mutable BSReadWriteLock		  unk160;					 // 160
	};
	static_assert(sizeof(CombatGroup) == 0x168);
}