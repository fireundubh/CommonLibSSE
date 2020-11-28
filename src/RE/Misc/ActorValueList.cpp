#include "RE/Misc/ActorValueList.h"

#include "RE/FormComponents/TESForm/ActorValueInfo.h"


namespace RE
{
	ActorValueList* ActorValueList::GetSingleton()
	{
		REL::Relocation<ActorValueList**> singleton{ Offset::ActorValueList::Singleton };
		return *singleton;
	}


	ActorValueInfo* ActorValueList::GetActorValue(ActorValue a_actorValue)
	{
		return actorValues && (a_actorValue < ActorValue::kTotal) ? actorValues[to_underlying(a_actorValue)] : nullptr;
	}
}
