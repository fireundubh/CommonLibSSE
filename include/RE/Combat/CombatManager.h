#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/Combat/CombatGroup.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiTArray.h"


namespace RE
{
	class CombatManager
	{
	public:
		static CombatManager* GetSingleton();


		struct CombatThreats
		{
			std::uint64_t			unk00;		// 00
			std::uint32_t			unk08;		// 08
			std::uint32_t			unk0C;		// 0C
			std::uint32_t			pad10;		// 10
			std::uint32_t			unk14;		// 14
			std::uint64_t			unk18;		// 18
			std::uint64_t			unk20;		// 20
			std::uint64_t			unk28;		// 28
			mutable BSReadWriteLock lock;		// 30
			AITimeStamp				timeStamp;	// 38
		};
		static_assert(sizeof(CombatThreats) == 0x40);


		// members
		NiTPrimitiveArray<CombatGroup*> combatGroups;	   // 00
		mutable BSReadWriteLock			lock;			   // 18
		std::uint64_t					unk20;			   // 20
		CombatThreats*					combatThreats;	   // 28
		std::uint64_t					unk30;			   // 30
		std::uint64_t					unk38;			   // 38
		std::uint64_t					unk40;			   // 40
		float							unk48;			   // 48
		AITimer							musicStopTimer;	   // 4C
		AITimer							musicUpdateTimer;  // 54
		std::uint32_t					combatCount;	   // 5C
		std::uint32_t					groupCount;		   // 60
		std::uint32_t					unk64;			   // 64
	};
	static_assert(sizeof(CombatManager) == 0x68);
}