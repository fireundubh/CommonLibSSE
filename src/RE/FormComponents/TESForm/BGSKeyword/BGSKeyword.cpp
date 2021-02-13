#include "RE\FormComponents\TESForm\BGSKeyword\BGSKeyword.h"

#include "RE\BSSystem\IFormFactory\ConcreteFormFactory\ConcreteFormFactory.h"


namespace RE
{
	BGSKeyword* BGSKeyword::CreateKeyword(const BSFixedString& a_formEditorID)
	{
		auto factory = IFormFactory::GetConcreteFormFactoryByType<BGSKeyword>();
		auto keyword = factory->Create();
		keyword->formEditorID = a_formEditorID;
		return keyword;
	}


	BGSKeyword* BGSKeyword::ctor()
	{
		using func_t = decltype(&BGSKeyword::ctor);
		REL::Relocation<func_t> func{ Offset::BGSKeyword::Ctor };
		return func(this);
	}
}
