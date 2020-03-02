#include "RE/BSTrishape.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BSTriShape* BSTriShape::Create()
	{
		using func_t = decltype(&BSTriShape::Create);
		REL::Offset<func_t> func(Offset::BSTriShape::Create);
		return func();
	}
}