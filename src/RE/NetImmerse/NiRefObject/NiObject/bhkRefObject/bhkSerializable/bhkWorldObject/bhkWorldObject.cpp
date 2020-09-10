#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkWorldObject/bhkWorldObject.h"
#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpWorld/ahkpWorld.h"
#include "RE/NetImmerse/NiRefObject/NiObject/bhkRefObject/bhkSerializable/bhkWorld/bhkWorld.h"


namespace RE
{
	void bhkWorldObject::EnterCriticalOperationRead()
	{
		auto ahkpWorld = GetWorld2();
		if (ahkpWorld) {
			auto bhkWorld = ahkpWorld->unk430;
			if (bhkWorld) {
				bhkWorld->LockWorldForRead();
			}
		}
	}


	void bhkWorldObject::EnterCriticalOperationWrite()
	{
		auto ahkpWorld = GetWorld2();
		if (ahkpWorld) {
			auto bhkWorld = ahkpWorld->unk430;
			if (bhkWorld) {
				bhkWorld->LockWorldForWrite();
			}
		}
	}


	void bhkWorldObject::ExitCriticalOperationRead()
	{
		auto ahkpWorld = GetWorld2();
		if (ahkpWorld) {
			auto bhkWorld = ahkpWorld->unk430;
			if (bhkWorld) {
				bhkWorld->UnlockWorldForRead();
			}
		}
	}


	void bhkWorldObject::ExitCriticalOperationWrite()
	{
		auto ahkpWorld = GetWorld2();
		if (ahkpWorld) {
			auto bhkWorld = ahkpWorld->unk430;
			if (bhkWorld) {
				bhkWorld->UnlockWorldForWrite();
			}
		}
	}
}