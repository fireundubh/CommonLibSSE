#pragma once

#include "RE/TESObjectREFR.h"
#include "RE/TESEffectShader.h"
#include "RE/ShaderReferenceEffect.h"

#include <RE/NiRefObject.h>

namespace RE
{
	class BGSLoadGameBuffer;
	class BGSSaveFormBuffer;

	class Unk141EBEAD0
	{
	public:
		static Unk141EBEAD0* GetSingleton();

		void StopArtObject(TESObjectREFR* ref, BGSArtObject* art);

		UInt8  unk000;                   // 008
		bool   enableDetection;          // 001 
		bool   unk002;                   // 002 
		UInt8  unk003;                   // 003
		UInt32 unk004;                   // 004
		bool   enableHighProcess;        // 008 
		bool   enableLowProcess;         // 009 
		bool   enableMiddleHighProcess;  // 00A 
		bool   enableMiddleLowProcess;   // 00B 
		bool   enableAISchedules;        // 00C 
		UInt8  unk00D;                   // 00D
		UInt8  unk00E;                   // 00E
		UInt8  unk00F;                   // 00F
		SInt32 numActorsInHighProcess;   // 010
		UInt32 unk014[(0x30 - 0x014) / sizeof(UInt32)];
		BSTArray<RefHandle>  actorsHigh; // 030 
		BSTArray<RefHandle>  actorsLow;  // 048 
		BSTArray<RefHandle>  actorsMiddleLow; // 060
		BSTArray<RefHandle>  actorsMiddleHigh; // 078
		UInt32  unk90[(0xF0 - 0x7C) / sizeof(UInt32)]; 
		BSTArray<ShaderReferenceEffect*> activeEffectShaders; // 108
		mutable BSReadWriteLock	 activeEffectShadersLock; // 120
	};
	static_assert(offsetof(Unk141EBEAD0, numActorsInHighProcess) >= 0x10, "Unknown012E32E8::actorsHigh is too early!");
	static_assert(offsetof(Unk141EBEAD0, numActorsInHighProcess) <= 0x10, "Unknown012E32E8::actorsHigh is too late!");

	static_assert(offsetof(Unk141EBEAD0, actorsHigh) >= 0x030, "Unknown012E32E8::actorsHigh is too early!");
	static_assert(offsetof(Unk141EBEAD0, actorsHigh) <= 0x039, "Unknown012E32E8::actorsHigh is too late!");

	static_assert(offsetof(Unk141EBEAD0, actorsLow) >= 0x048, "Unknown012E32E8::actorsLow is too early!");
	static_assert(offsetof(Unk141EBEAD0, actorsLow) <= 0x048, "Unknown012E32E8::actorsLow is too late!");

	static_assert(offsetof(Unk141EBEAD0, actorsMiddleLow) >= 0x060, "Unknown012E32E8::actorsMiddleLow is too early!");
	static_assert(offsetof(Unk141EBEAD0, actorsMiddleLow) <= 0x060, "Unknown012E32E8::actorsMiddleLow is too late!");

	static_assert(offsetof(Unk141EBEAD0, actorsMiddleHigh) >= 0x078, "Unknown012E32E8::actorsMiddleHigh is too early!");
	static_assert(offsetof(Unk141EBEAD0, actorsMiddleHigh) <= 0x078, "Unknown012E32E8::actorsMiddleHigh is too late!");

	static_assert(offsetof(Unk141EBEAD0, activeEffectShaders) >= 0x108, "Unknown012E32E8::activeEffectShaders is too early!");
	static_assert(offsetof(Unk141EBEAD0, activeEffectShaders) <= 0x108, "Unknown012E32E8::activeEffectShaders is too late!");
};


