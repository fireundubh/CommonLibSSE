#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/FormComponents/Components/AITimer.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class CombatAreaStandard;
	class CombatControllerData08;
	class CombatControllerData10;
	class CombatGroup;
	class CombatTargetSelectorStandard;
	class TESCombatStyle;


	class CombatController
	{
	public:
		using Data08 = CombatControllerData08;
		using Data10 = CombatControllerData10;

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
