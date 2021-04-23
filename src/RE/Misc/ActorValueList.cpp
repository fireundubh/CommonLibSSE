#include "RE/Misc/ActorValueList.h"

#include "RE/FormComponents/TESForm/ActorValueInfo.h"
#include "SKSE/Utilities.h"


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


	ActorValue ActorValueList::LookupActorValueByName(std::string_view a_enumName)
	{
		namespace STRING = SKSE::UTIL::STRING;

		ActorValue av = ActorValue::kNone;

		if (actorValues) {
			for (auto i = ActorValue::kAggression; i < ActorValue::kTotal; i++) {
				if (STRING::insenstiveStringCompare(actorValues[to_underlying(i)]->enumName, a_enumName)) {
					av = i;
					break;
				}
			}
		}

		return av;
	}
}
