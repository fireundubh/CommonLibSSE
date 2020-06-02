#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTSingleton.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class NiCamera;
	class BSShaderAccumulator;
	class BGSDecalNode;
	class BSTempEffect;
	class NiAVObject;


	class BGSDecalManager
	{
	public:
		static BGSDecalManager* GetSingleton();

		//members
		UInt32							unk00;				 // 00
		UInt32							unk04;				 // 04
		UInt32							unk08;				 // 08
		UInt32							unk0C;				 // 0C - simpleDecal count?
		UInt32							geometryDecalCount;	 // 10 
		UInt32							unk14;				 // 14
		BSTArray<BSTempEffect*>			decals;				 // 18
		BSTArray<void*>					unk30;				 // 30
		BSTArray<BGSDecalNode*>			decalNodes;			 // 48
		BSTArray<NiPointer<NiAVObject>> unk60;				 // 60
		NiCamera*						niCamera;			 // 78
		BSShaderAccumulator*			shaderAccumulator;	 // 80
		UInt32							unk88;				 // 88
	};
	STATIC_ASSERT(sizeof(BGSDecalManager) == 0x90);
};