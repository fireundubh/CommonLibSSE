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
		UInt8  unk003[(0x08 - 0x003) / sizeof(UInt8)]; 
		bool   enableHighProcess;        // 008 
		bool   enableLowProcess;         // 009 
		bool   enableMiddleHighProcess;  // 00A 
		bool   enableMiddleLowProcess;   // 00B 
		bool   enableAISchedules;        // 00C 
		UInt8  unk00D[(0x010 - 0x00D) / sizeof(UInt8)]; 
		SInt32 numActorsInHighProcess;   // 010 // 
		UInt8  unk011[(0x2C - 0x011) / sizeof(UInt8)]; 
		UInt32 unk30;					// 030
		UInt8  unk034[(0x40 - 0x034) / sizeof(UInt8)];
		BSTArray<RefHandle>  actorsHigh; // 040 
		BSTArray<RefHandle>  actorsLow;  // 058  
		BSTArray<RefHandle>  actorsMiddleLow; // 070
		BSTArray<RefHandle>  actorsMiddleHigh; // 088
		UInt8  unkA0[(0x108 - 0xA0) / sizeof(UInt8)]; 
		BSTArray<ShaderReferenceEffect*> activeEffectShaders; // 108
		/*
		UInt32 unk10C;
		UInt32 unk110;
		UInt32 unk114;
		UInt32 unk118;
		bool   enableActorAI;        // 11C // if true, then all AI processing is on
		bool   enableActorMovement;  // 11D // if true, then all actor movement processing is on
		bool   enableActorAnimation; // 11E // if true, then all actor animation processing is on
		UInt8  unk11F;               // 11F // modified by opcode at 004A6BDE
		*/
	};
	static_assert(offsetof(Unk141EBEAD0, enableHighProcess) >= 0x08, "Unknown012E32E8::actorsHigh is too early!");
	static_assert(offsetof(Unk141EBEAD0, enableHighProcess) <= 0x08, "Unknown012E32E8::actorsHigh is too late!");

	static_assert(offsetof(Unk141EBEAD0, enableLowProcess) >= 0x09, "Unknown012E32E8::actorsHigh is too early!");
	static_assert(offsetof(Unk141EBEAD0, enableLowProcess) <= 0x09, "Unknown012E32E8::actorsHigh is too late!");

	static_assert(offsetof(Unk141EBEAD0, numActorsInHighProcess) >= 0x10, "Unknown012E32E8::actorsHigh is too early!");
	static_assert(offsetof(Unk141EBEAD0, numActorsInHighProcess) <= 0x10, "Unknown012E32E8::actorsHigh is too late!");

	static_assert(offsetof(Unk141EBEAD0, unk30) >= 0x30, "Unknown012E32E8::unk30 is too early!");
	static_assert(offsetof(Unk141EBEAD0, unk30) <= 0x30, "Unknown012E32E8::unk30 is too late!");

	static_assert(offsetof(Unk141EBEAD0, actorsHigh) >= 0x40, "Unknown012E32E8::actorsHigh is too early!");
	static_assert(offsetof(Unk141EBEAD0, actorsHigh) <= 0x40, "Unknown012E32E8::actorsHigh is too late!");

	static_assert(offsetof(Unk141EBEAD0, actorsLow) >= 0x58, "Unknown012E32E8::actorsLow is too early!");
	static_assert(offsetof(Unk141EBEAD0, actorsLow) <= 0x58, "Unknown012E32E8::actorsLow is too late!");

	static_assert(offsetof(Unk141EBEAD0, actorsMiddleLow) >= 0x070, "Unknown012E32E8::actorsMiddleLow is too early!");
	static_assert(offsetof(Unk141EBEAD0, actorsMiddleLow) <= 0x070, "Unknown012E32E8::actorsMiddleLow is too late!");

	static_assert(offsetof(Unk141EBEAD0, actorsMiddleHigh) >= 0x088, "Unknown012E32E8::actorsMiddleHigh is too early!");
	static_assert(offsetof(Unk141EBEAD0, actorsMiddleHigh) <= 0x088, "Unknown012E32E8::actorsMiddleHigh is too late!");

	static_assert(offsetof(Unk141EBEAD0, activeEffectShaders) >= 0x108, "Unknown012E32E8::actorsMiddleHigh is too early!");
	static_assert(offsetof(Unk141EBEAD0, activeEffectShaders) <= 0x108, "Unknown012E32E8::actorsMiddleHigh is too late!");

	// Refernces to enableActorAI:
	// 53B1B9 (ToggleAI)
	// 6D5FEE (Actor::Subroutine006D5B70)
	// 7480BB (PlayerCharacter::Subroutine00748010)
	// 75CBEF
	// 75D190 (constructor)
	// 75D280 (...::Subroutine0075D280)
	// 75D2C6 (...::Subroutine0075D2A0)
};


