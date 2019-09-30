#include "RE/Unk141EBEAD0.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	Unk141EBEAD0* Unk141EBEAD0::GetSingleton()
	{
		REL::Offset<Unk141EBEAD0**> singleton(Offset::Unk141EBEAD0::Singleton);
		return *singleton;
	}

	void Unk141EBEAD0::StopArtObject(TESObjectREFR* ref, BGSArtObject* art)
	{
		using func_t = function_type_t<decltype(&Unk141EBEAD0::StopArtObject)>;
		REL::Offset<func_t*> func(Offset::Unk141EBEAD0::StopArtObject);
		return func(this, ref, art);
	}
};