#pragma once

#include "RE/FormComponents/Enums/ActorValues.h"


namespace RE
{
	class ActorValueInfo;


	class ActorValueList
	{
	public:
		static ActorValueList* GetSingleton();

		ActorValueInfo* GetActorValue(ActorValue a_actorValue);
		ActorValue		LookupActorValueByName(std::string_view a_enumName);


		// members
		std::uint32_t	unk00;											 // 00
		std::uint32_t	pad04;											 // 04
		ActorValueInfo* actorValues[to_underlying(ActorValue::kTotal)];	 // 08
	};
}