#pragma once

#include "RE/BSTextureSet.h"

namespace RE
{
	class BSShaderTextureSet : public BSTextureSet
	{
	public:
		inline static const void* RTTI = RTTI_BSShaderTextureSet;
		inline static const void* Ni_RTTI = NiRTTI_BSShaderTextureSet;

		static BSShaderTextureSet* Create();
		
		const char* textures[9];
	};
	STATIC_ASSERT(sizeof(BSShaderTextureSet) == 0x58);
}
