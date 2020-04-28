#pragma once

#include "RE/BSTArray.h"


namespace RE
{
	class BSLight;


	class BSShaderPropertyLightData
	{
		BSTArray<BSLight*> lights;	// 00
		UInt32			   unk18;	// 18
		UInt32			   unk1C;	// 1C
		UInt8			   unk20;	// 20
	};
	STATIC_ASSERT(sizeof(BSShaderPropertyLightData) == 0x28);
}
