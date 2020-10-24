#pragma once

#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkReferencedObject.h"
#include "RE/BSHavok/hkSmallArray.h"
#include "RE/BSHavok/hkStringPtr.h"


namespace RE
{
	class hkpConstraintData;
	class hkpConstraintInternal;
	class hkpConstraintListener;
	class hkpConstraintOwner;
	class hkpEntity;
	class hkpModifierConstraintAtom;
	struct hkConstraintInternal;


	class hkpConstraintInstance : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpConstraintInstance;


		enum class ConstraintPriority
		{
			kInvalid = 0,
			kPSI = 1,
			kSimplifiedTOIUnused = 2,
			kTOI = 3,
			kTOIHigher = 4,
			kTOIForced = 5,
			kTotal = 6
		};


		enum class InstanceType
		{
			kNormal = 0,
			kChain = 1,
			kDisableSPU = 2
		};


		enum class OnDestructionRemapInfo
		{
			kRemap = 0,
			kRemove = 1,
			kResetRemove = 2
		};


		virtual ~hkpConstraintInstance();  // 00

		// add
		virtual void Unk_03(void);	// 03
		virtual void Unk_04(void);	// 04
		virtual void Unk_05(void);	// 05
		virtual void Unk_06(void);	// 06


		// members
		hkpConstraintOwner*									   owner;				  // 10
		hkpConstraintData*									   data;				  // 18
		hkpModifierConstraintAtom*							   constraintModifiers;	  // 20
		hkpEntity*											   entities[2];			  // 28
		stl::enumeration<ConstraintPriority, std::uint8_t>	   priority;			  // 38
		bool												   wantRuntime;			  // 39
		stl::enumeration<OnDestructionRemapInfo, std::uint8_t> destructionRemapInfo;  // 3A
		std::uint8_t										   pad3B[5];			  // 3B
		hkSmallArray<hkpConstraintListener>					   listeners;			  // 40
		hkStringPtr											   name;				  // 50
		std::uint64_t										   userData;			  // 58
		hkConstraintInternal*								   internal;			  // 60
		std::uint32_t										   uid;					  // 68
		std::uint8_t										   pad6C[4];			  // 6C
	};
	static_assert(sizeof(hkpConstraintInstance) == 0x70);
}
