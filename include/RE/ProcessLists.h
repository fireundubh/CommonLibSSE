#pragma once

#include "RE/BSTArray.h"
#include "RE/BSTSingleton.h"
#include "RE/BSPointerHandle.h"


namespace RE
{
	class Actor;
	class BSTempEffect;
	class ReferenceEffect;
	class TESObjectREFR;
	class BGSArtObject;

	class ProcessLists : public BSTSingletonSDM<ProcessLists>
	{
	public:
		class GetActorsFilter
		{
		public:
			inline static const void* RTTI = RTTI_ProcessLists__GetActorsFilter;


			virtual ~GetActorsFilter();		// 00

			// add
			virtual void Unk_01(void) = 0;	// 01
		};
		STATIC_ASSERT(sizeof(GetActorsFilter) == 0x8);


		static ProcessLists* GetSingleton();

		void StopCombatAndAlarmOnActor(Actor* a_actor, bool a_dontEndAlarm);
		void StopArtObject(TESObjectREFR* a_ref, BGSArtObject* a_art);

		// members
		bool						enableDetection;				// 001
		bool						enableDetectionStats;			// 002
		UInt8						pad003;							// 003
		ActorHandle					trackedDetectionHandle;			// 004
		bool						enableHighProcessing;			// 008
		bool						enableLowProcessing;			// 009
		bool						enableMiddleHighProcessing;		// 00A
		bool						enableMiddleLowProcessing;		// 00B
		UInt16						unk00C;							// 00C
		UInt8						unk00E;							// 00E
		UInt8						pad00F;							// 00F
		SInt32						numActorsInHighProcess;			// 010
		float						unk014;							// 014
		UInt32						unk018;							// 018
		float						removeExcessComplexDeadTime;	// 01C
		HANDLE						semaphore;						// 020
		UInt32						unk028;							// 028
		UInt32						pad02C;							// 02C
		BSTArray<ActorHandle>		highProcesses;					// 030
		BSTArray<ActorHandle>		lowProcesses;					// 048
		BSTArray<ActorHandle>		middleLowProcesses;				// 060
		BSTArray<ActorHandle>		middleHighProcesses;			// 078
		BSTArray<ActorHandle>*		highProcessesPtr;				// 090
		BSTArray<ActorHandle>*		lowProcessesPtr;				// 098
		BSTArray<ActorHandle>*		middleLowProcessesPtr;			// 0A0
		BSTArray<ActorHandle>*		middleHighProcessesPtr;			// 0A8
		UInt64						unk0B0;							// 0B0
		UInt64						unk0B8;							// 0B8
		UInt64						unk0C0;							// 0C0
		UInt64						unk0C8;							// 0C8
		UInt64						unk0D0;							// 0D0
		UInt64						unk0D8;							// 0D8
		UInt64						unk0E0;							// 0E0
		BSTArray<BSTempEffect*>		tempEffects;					// 0E8
		mutable BSUniqueLock		tempEffectsLock;				// 100
		BSTArray<ReferenceEffect*>	referenceEffects;				// 108
		mutable BSUniqueLock		referenceEffectsLock;			// 120
		BSTArray<void*>				unk128;							// 128
		mutable BSUniqueLock		unk128Lock;						// 140
		UInt64						unk148;							// 148
		UInt64						unk150;							// 150
		BSTArray<ActorHandle>		unk158;							// 158
		UInt32						unk170;							// 170
		UInt32						pad174;							// 174
		UInt64						unk178;							// 178
		BSTArray<void*>				unk180;							// 180
		mutable BSUniqueLock		unk198;							// 198
		BSTArray<ActorHandle>		unk1A0;							// 1A0
		BSTArray<void*>				unk1B8;							// 1B8
		float						unk1D0;							// 1D0
		float						unk1D4;							// 1D4
		UInt64						unk1D8;							// 1D8
		UInt32						unk1E0;							// 1E0
		bool						enableAIProcessing;				// 1E4
		bool						enableMovementProcessing;		// 1E5
		bool						enableAnimationProcessing;		// 1E6
		UInt8						unk1E7;							// 1E7
		UInt64						unk1E8;							// 1E8
	};
	STATIC_ASSERT(sizeof(ProcessLists) == 0x1F0);
}

