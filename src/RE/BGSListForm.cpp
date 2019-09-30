#include "RE/BGSListForm.h"

#include "skse64/GameForms.h"  // Form

#include "RE/Offsets.h"
#include "REL/Relocation.h"

namespace RE
{
	void BGSListForm::AddFormToList(TESForm * form)
	{
		using func_t = function_type_t<decltype(&BGSListForm::AddFormToList)>;
		REL::Offset<func_t*> func(Offset::BGSListForm::AddFormToList);
		return func(this, form);
	}
}
