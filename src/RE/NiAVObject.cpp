#include "RE/NiAVObject.h"

#include "skse64/NiObjects.h"  // NiAVObject

#include "skse64/GameData.h"


namespace RE
{
	void NiAVObject::UpdateNode(ControllerUpdateContext* a_ctx)
	{
		using func_t = function_type_t<decltype(&NiAVObject::UpdateNode)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::NiAVObject, UpdateNode, func_t*);
		return func(this, a_ctx);
	}

	UInt32 NiAVObject::UpdateModelHair(NiColorA** hairColor)
	{
		using func_t = function_type_t<decltype(&NiAVObject::UpdateModelHair)>;
		func_t* func = unrestricted_cast<func_t*>(::UpdateModelHair.GetUIntPtr());
		return func(this, hairColor);
	}

	UInt32 NiAVObject::UpdateModelSkin(NiColorA** hairColor)
	{
		using func_t = function_type_t<decltype(&NiAVObject::UpdateModelSkin)>;
		func_t* func = unrestricted_cast<func_t*>(::UpdateModelSkin.GetUIntPtr());
		return func(this, hairColor);
	}
}
