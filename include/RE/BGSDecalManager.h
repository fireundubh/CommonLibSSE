#pragma once

#include "RE/BSTArray.h"
#include "RE/BSTSingleton.h"


namespace RE
{
	class NiCamera;
	class BSShaderAccumulator;
	class BGSDecalNode;
	class BSTempEffect;


	class BGSDecalManager : public BSTSingletonSDM<BGSDecalManager>
	{
	public:
		static BGSDecalManager* GetSingleton();

		//members
		UInt8					pad01;				// 01
		UInt8					pad02;				// 02
		UInt8					pad03;				// 03
		UInt32					unk04;				// 04
		UInt8					pad08;				// 08
		UInt8					pad09;				// 09
		UInt8					pad0A;				// 0A
		UInt32					unk0C;				// 0C - simpleDecal count?
		UInt32					unk10;				// 10 - count?
		UInt32					unk14;				// 14
		BSTArray<BSTempEffect*> decals;				// 18
		BSTArray<void*>			unk30;				// 30
		BSTArray<BGSDecalNode*> decalNodes;			// 48
		BSTArray<void*>			unk60;				// 60
		NiCamera*				niCamera;			// 78
		BSShaderAccumulator*	shaderAccumulator;	// 80
		UInt32					unk88;				// 88
	};
	STATIC_ASSERT(sizeof(BGSDecalManager) == 0x90);
};