#include "RE/FormComponents/TESForm/BGSMaterialType.h"


namespace RE
{
	BGSMaterialType* BGSMaterialType::GetMaterialType(MATERIAL_ID a_matID)
	{
		using func_t = decltype(&BGSMaterialType::GetMaterialType);
		REL::Relocation<func_t> func{ REL::ID(20529) };
		return func(a_matID);
	}
}

