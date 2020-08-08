#include "RE/FormComponents/TESForm/TESPackage/TESPackage.h"


namespace RE
{
	TESPackage* CreatePackage(PACKAGE_PROCEDURE_TYPE a_type)
	{
		using func_t = decltype(&TESPackage::CreatePackage);
		REL::Relocation<func_t> func{ Offset::TESPackage::CreatePackage };
		return func(a_type);
	}
}