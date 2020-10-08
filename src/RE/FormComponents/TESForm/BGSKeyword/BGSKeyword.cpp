#include "RE\FormComponents\TESForm\BGSKeyword\BGSKeyword.h"


namespace RE
{
	BGSKeyword* BGSKeyword::CreateKeyword(const BSFixedString& a_formEditorID)
	{
		auto keyword = malloc<BGSKeyword>();
		keyword->ctor();
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
