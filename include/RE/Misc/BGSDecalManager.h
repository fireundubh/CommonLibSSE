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


	class BGSDecalManager : public BSTSingletonSDM<BGSDecalManager>
	{
	public:
		static BGSDecalManager* GetSingleton();


		// members
		//std::uint32_t					  unk00;					// 00
		std::uint32_t					  decalsPerFrameCount;		// 04
		std::uint32_t					  skinDecalsPerFrameCount;	// 08
		std::uint32_t					  decalCount;				// 0C
		std::uint32_t					  skinDecalCount;			// 10
		std::uint8_t					  unk14;					// 14
		BSTArray<NiPointer<BSTempEffect>> decals;					// 18
		BSTArray<void*>					  unk30;					// 30
		BSTArray<NiPointer<BGSDecalNode>> decalNodes;				// 48
		BSTArray<NiPointer<BSTempEffect>> unk60;					// 60
		NiPointer<NiCamera>				  camera;					// 78
		NiPointer<BSShaderAccumulator>	  shaderAccumulator;		// 80
		std::uint32_t					  unk88;					// 88
	};
	static_assert(sizeof(BGSDecalManager) == 0x90);
};