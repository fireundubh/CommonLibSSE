#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/BSCore/BSPointerHandle.h"


namespace RE
{
	class ActorPackageData
	{
	public:
		virtual ~ActorPackageData();   // 00
		virtual void Unk01(void) = 0;  // 01
		virtual void Unk02(void);	   // 02
		virtual void Unk03(void);	   // 03
		virtual void Unk04(void);	   // 04
		virtual void Unk05(void) = 0;  // 05
		virtual void Unk06(void) = 0;  // 06
		virtual void Unk07(void);	   // 07
		virtual void Unk08(void);	   // 08
	};
	static_assert(sizeof(ActorPackageData) == 0x08);


	class TESPackage;


	class ActorPackage
	{
	public:
		enum class ACTOR_PACKAGE_FLAG
		{
			kNone = 0,
			kSaveLoadSharedPackage = 1 << 0
		};


		// members
		mutable BSSpinLock								  packageLock;			  // 00
		TESPackage*										  package;				  // 08
		ActorPackageData*								  data;					  // 10
		ObjectRefHandle									  target;				  // 18
		std::int32_t									  currentProcedureIndex;  // 1C
		float											  packageStartTime;		  // 20
		std::uint32_t									  modifiedPackageFlag;	  // 24
		std::uint16_t									  modifiedInterruptFlag;  // 28
		stl::enumeration<ACTOR_PACKAGE_FLAG, std::int8_t> actorPackageFlags;	  // 2A
		std::int8_t										  preferredSpeed;		  // 2B
		std::uint32_t									  pad2C;				  // 2C
	};
	static_assert(sizeof(ActorPackage) == 0x30);
}
