#include "RE/NiAVObject.h"
#include "RE/NiNode.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	bool NiAVObject::SetMotionType(UInt32 a_motionType, bool a_arg2, bool a_arg3, bool a_allowActivate)
	{
		using func_t = function_type_t<decltype(&NiAVObject::SetMotionType)>;
		REL::Offset<func_t*> func(Offset::NiAVObject::SetMotionType);
		return func(this, a_motionType, a_arg2, a_arg3, a_allowActivate);
	}


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


	void NiAVObject::Update(NiUpdateData& a_data)
	{
		using func_t = function_type_t<decltype(&NiAVObject::Update)>;
		REL::Offset<func_t*> func(Offset::NiAVObject::Update);
		return func(this, a_data);
	}

	TESObjectREFR* NiAVObject::GetOwner()
	{
		if (userData)
		{
			return userData;
		}

		if (parent)
		{
			parent->GetOwner();
		}

		return nullptr;
	}
}
