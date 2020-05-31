#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/BSGeometry/BSTriShape/BSTriShape.h"


namespace RE
{
	BSTriShape* BSTriShape::Create()
	{
		using func_t = decltype(&BSTriShape::Create);
		REL::Offset<func_t> func(Offset::BSTriShape::Create);
		return func();
	}
}