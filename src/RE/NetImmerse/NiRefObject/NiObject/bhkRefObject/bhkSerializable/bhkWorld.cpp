#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkWorld/bhkWorld.h"


namespace RE
{
	void bhkWorld::LockWorld()
	{
		worldLock.LockForWrite();
	}


	void bhkWorld::UnlockWorld()
	{
		worldLock.UnlockForWrite();
	}
}
