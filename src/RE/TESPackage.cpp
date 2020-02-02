#include "RE/TESPackage.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"

namespace RE
{

	TESPackage* CreatePackage(PACKAGE_PROCEDURE_TYPE a_type)
	{
		using func_t = function_type_t<decltype(&TESPackage::CreatePackage)>;
		REL::Offset<func_t*> func(Offset::TESPackage::CreatePackage);
		return func(a_type);
	}
}