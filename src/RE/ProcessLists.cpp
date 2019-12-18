#include "RE/ProcessLists.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ProcessLists* ProcessLists::GetSingleton()
	{
		REL::Offset<ProcessLists**> singleton(Offset::ProcessLists::Singleton);
		return *singleton;
	}


	void ProcessLists::SetCombatAlarmState(Actor* a_actor, bool a_enabled)
	{
		using func_t = function_type_t<decltype(&ProcessLists::SetCombatAlarmState)>;
		REL::Offset<func_t*> func(Offset::ProcessLists::SetCombatAlarmState);
		return func(this, a_actor, a_enabled);
	}

	void ProcessLists::StopArtObject(TESObjectREFR* a_ref, BGSArtObject * a_art)
	{
		using func_t = function_type_t<decltype(&ProcessLists::StopArtObject)>;
		REL::Offset<func_t*> func(Offset::ProcessLists::StopArtObject);
		return func(this, a_ref, a_art);
	}

}
