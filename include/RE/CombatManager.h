#pragma once

#include "RE/BSLock.h"
#include "RE/BSTArray.h"
#include "RE/CombatGroup.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTArray.h"


namespace RE
{
	class CombatManager
	{
	public:
		static CombatManager* GetSingleton();


		// members
		NiTPrimitiveArray<CombatGroup*> combatGroups;	   // 00
		BSReadWriteLock					lock;			   // 18
		UInt64							unk20;			   // 20
		UInt64							unk28;			   // 28
		UInt64							unk30;			   // 30
		UInt64							unk38;			   // 38
		UInt64							unk40;			   // 40
		float							unk48;			   // 48
		AITimer							musicStopTimer;	   // 4C
		AITimer							musicUpdateTimer;  // 54
		UInt32							combatCount;	   // 5C
		UInt32							groupCount;		   // 60
		UInt32							unk64;			   // 64
	};
	STATIC_ASSERT(sizeof(CombatManager) == 0x68);
}