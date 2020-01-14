#include "RE/ExtraLock.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	REFR_LOCK::REFR_LOCK() :
		baseLevel(0),
		pad01(0),
		pad02(0),
		pad04(0),
		key(nullptr),
		flags(Flag::kLocked),
		pad11(0),
		pad12(0),
		numTries(0),
		unk18(0),
		pad1C(0)
	{}


	ExtraLock::ExtraLock() :
		BSExtraData(),
		lock()
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraLock::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.GetAddress();
	}
	

	ExtraDataType ExtraLock::GetType() const
	{
		return ExtraDataType::kLock;
	}


	bool ExtraLock::IsNotEqual(const BSExtraData* a_rhs) const
	{
		return true;
	}
	

	SInt32 REFR_LOCK::GetLockLevel(const TESObjectREFR* a_containerRef) const
	{
		using func_t = function_type_t<decltype(&REFR_LOCK::GetLockLevel)>;
		REL::Offset<func_t*> func(Offset::REFR_LOCK::GetLockLevel);
		return func(this, a_containerRef);
	}


	void REFR_LOCK::SetLocked(bool a_locked)
	{
		if (a_locked) {
			flags |= Flag::kLocked;
		} else {
			flags &= ~Flag::kLocked;
			numTries = 0;
		}
	}

}
