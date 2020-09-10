#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkWorld/bhkWorld.h"


namespace RE
{
	void bhkWorld::LockWorldForRead()
	{
		worldLock.LockForRead();
	}

	void bhkWorld::LockWorldForWrite()
	{
		worldLock.LockForWrite();
	}


	void bhkWorld::UnlockWorldForRead()
	{
		worldLock.UnlockForRead();
	}


	void bhkWorld::UnlockWorldForWrite()
	{
		worldLock.UnlockForWrite();
	}
}
