#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkWorldObject/bhkWorldObject.h"
#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpWorld/ahkpWorld.h"
#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkWorld/bhkWorld.h"


namespace RE
{
	bhkWorld* bhkWorldObject::GetbhkWorld()
	{
		auto ahkpWorld = GetWorld2();
		return ahkpWorld ? ahkpWorld->physicsWorld : nullptr;
	}
}