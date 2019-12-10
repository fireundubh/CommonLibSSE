#include "RE/NiAVObject.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"

#include "skse64/GameData.h"


namespace RE
{
	void NiAVObject::UpdateModelHair(NiColorA** a_color)
	{
		using func_t = function_type_t<decltype(&NiAVObject::UpdateModelHair)>;
		REL::Offset<func_t*> func(Offset::NiAVObject::UpdateModelHair);
		return func(this, a_color);
	}


	void NiAVObject::UpdateModelSkin(NiColorA** a_color)
	{
		using func_t = function_type_t<decltype(&NiAVObject::UpdateModelSkin)>;
		REL::Offset<func_t*> func(Offset::NiAVObject::UpdateModelSkin);
		return func(this, a_color);
	}


	void NiAVObject::UpdateNode(ControllerUpdateContext* a_ctx)
	{
		using func_t = function_type_t<decltype(&NiAVObject::UpdateNode)>;
		REL::Offset<func_t*> func(Offset::NiAVObject::UpdateNode);
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
