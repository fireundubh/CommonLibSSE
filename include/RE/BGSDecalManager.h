#pragma once

#include "RE/BSTArray.h"
#include "RE/BSTSingleton.h"


namespace RE
{
	class NiCamera;
	class BSShaderAccumulator;
	class BGSDecalNode;
	class BSTempEffectSimpleDecal;

	class BGSDecalManager : public BSTSingletonSDM<BGSDecalManager>
	{
	public:
		static BGSDecalManager* GetSingleton();

		UInt16								pad02;
		UInt32								unk04;
		UInt32								unk08;
		UInt32								unk0C;
		UInt32								unk10;
		UInt32								pad14;
		BSTArray<BSTempEffectSimpleDecal*>	simpleDecals;
		BSTArray<void*>						unk30;
		BSTArray<BGSDecalNode*>				decalNodes;
		BSTArray<void*>						unk60;
		NiCamera*							niCamera;
		BSShaderAccumulator*				shaderAccumulator;
		UInt32								unk88;
	};
	static_assert(offsetof(BGSDecalManager, simpleDecals) >= 0x18, "simple decals too early");
	static_assert(offsetof(BGSDecalManager, simpleDecals) <= 0x18, "simple decals too late");
};