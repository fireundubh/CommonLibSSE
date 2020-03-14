#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/CombatAreaStandard.h"
#include "RE/CombatControllerData08.h"
#include "RE/CombatControllerData10.h"
#include "RE/CombatGroup.h"
#include "RE/CombatTargetSelectorStandard.h"
#include "RE/NiPoint3.h"
#include "RE/TESCombatStyle.h"


namespace RE
{
	class CombatController
	{
	public:
		typedef CombatControllerData08 Data08;
		typedef CombatControllerData10 Data10;


		struct Data18
		{};


		struct Data20
		{};


		// members
		CombatGroup*							combatGroup;			 // 00
		Data08*									data08;					 // 08
		Data10*									data10;					 // 10
		Data18*									data18;					 // 18
		Data20*									data20;					 // 20
		ActorHandle								actorHandle;			 // 28
		ActorHandle								currentTargetHandle;	 // 2C
		ActorHandle								target;					 // 30
		UInt8									unk34;					 // 34
		UInt8									unk35;					 // 34
		UInt8									unk36;					 // 36
		UInt8									unk37;					 // 37
		TESCombatStyle*							combatStyle;			 // 38
		bool									stoppedCombat;			 // 40
		bool									unk41;					 // 41
		bool									ignoringCombat;			 // 42
		bool									notInCombat;			 // 43
		AITimer									unk44;					 // 44
		float									unk4C;					 // 4C
		BSTArray<void*>							unk50;					 // 50
		UInt64									unk68;					 // 68
		UInt64									unk70;					 // 70
		BSTArray<CombatAreaStandard*>			areas;					 // 78
		CombatAreaStandard*						currentArea;			 // 90
		BSTArray<CombatTargetSelectorStandard*> targetSelectors;		 // 98
		CombatTargetSelectorStandard*			currentTargetSelector;	 // B0
		CombatTargetSelectorStandard*			previousTargetSelector;	 // B8
		UInt32									unkC0;					 // C0
		SInt32									unkC4;					 // C4
		NiPointer<Actor>						actor;					 // C8
		NiPointer<Actor>						currentTarget;			 // D0
	};
	STATIC_ASSERT(sizeof(CombatController) == 0xD8);
}
