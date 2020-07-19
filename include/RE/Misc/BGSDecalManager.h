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


		// members
		std::uint32_t					unk00;				 // 00
		std::uint32_t					unk04;				 // 04
		std::uint32_t					unk08;				 // 08
		std::uint32_t					unk0C;				 // 0C - simpleDecal count?
		std::uint32_t					geometryDecalCount;	 // 10
		std::uint32_t					unk14;				 // 14
		BSTArray<BSTempEffect*>			decals;				 // 18
		BSTArray<void*>					unk30;				 // 30
		BSTArray<BGSDecalNode*>			decalNodes;			 // 48
		BSTArray<NiPointer<NiAVObject>> unk60;				 // 60
		NiCamera*						niCamera;			 // 78
		BSShaderAccumulator*			shaderAccumulator;	 // 80
		std::uint32_t					unk88;				 // 88
	};
	static_assert(sizeof(BGSDecalManager) == 0x90);
};