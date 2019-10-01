#include "RE/BSShaderTextureSet.h"

#include "skse64/GameObjects.h"  // PlayerControls


namespace RE
{
	BSShaderTextureSet* BSShaderTextureSet::Ctor()
	{
		using func_t = function_type_t<decltype(&BSShaderTextureSet::Ctor)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSShaderTextureSet, ctor, func_t*);
		return func(this);
	}

	BSShaderTextureSet* BSShaderTextureSet::Create()
	{
		using func_t = function_type_t<decltype(&BSShaderTextureSet::Create)>;
		func_t* func = unrestricted_cast<func_t*>(&::BSShaderTextureSet::Create);
		return func();
	}
}