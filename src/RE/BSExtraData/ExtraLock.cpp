#include "RE/BSExtraData/ExtraLock.h"


namespace RE
{
	REFR_LOCK::REFR_LOCK() :
		baseLevel(BaseLevel::kNovice),
		pad01(0),
		pad02(0),
		pad04(0),
		key(nullptr),
		flags(Flag::kNone),
		pad11(0),
		pad12(0),
		numTries(0),
		unk18(0),
		pad1C(0)
	{}


	REFR_LOCK::REFR_LOCK(BaseLevel a_lockType) :
		baseLevel(a_lockType),
		pad01(0),
		pad02(0),
		pad04(0),
		key(nullptr),
		flags(Flag::kNone),
		pad11(0),
		pad12(0),
		numTries(0),
		unk18(0),
		pad1C(0)
	{}


	ExtraLock::ExtraLock() :
		BSExtraData(),
		lock(nullptr)
	{
		REL::Offset<std::uintptr_t> vtbl(Offset::ExtraLock::Vtbl);
		((std::uintptr_t*)this)[0] = vtbl.address();
	}


	ExtraDataType ExtraLock::GetType() const
	{
		return ExtraDataType::kLock;
	}


	bool ExtraLock::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraLock*>(a_rhs);
		return lock->baseLevel != rhs->lock->baseLevel ||
			   lock->key != rhs->lock->key ||
			   lock->flags != rhs->lock->flags ||
			   lock->numTries != rhs->lock->numTries ||
			   lock->unk18 != rhs->lock->unk18;
	}


	LOCK_LEVEL REFR_LOCK::GetLockLevel(const TESObjectREFR* a_containerRef) const
	{
		if (IsLocked()) {
			using func_t = decltype(&REFR_LOCK::GetLockLevel);
			REL::Offset<func_t> func = REL::ID(12272);
			return func(this, a_containerRef);
		} else {
			return LOCK_LEVEL::kUnlocked;
		}
	}


	void REFR_LOCK::SetLocked(bool a_locked)
	{
		if (a_locked) {
			flags.set(Flag::kLocked);
		} else {
			flags.reset(Flag::kLocked);
			numTries = 0;
		}
	}


	void REFR_LOCK::SetBaseLevel(LOCK_LEVEL a_lockLevel)
	{
		auto lockLevel = BaseLevel::kNovice;

		switch (a_lockLevel) {
		case RE::LOCK_LEVEL::kVeryEasy:
			lockLevel = BaseLevel::kNovice;
			break;
		case RE::LOCK_LEVEL::kEasy:
			lockLevel = BaseLevel::kApprentice;
			break;
		case RE::LOCK_LEVEL::kAverage:
			lockLevel = BaseLevel::kAdept;
			break;
		case RE::LOCK_LEVEL::kHard:
			lockLevel = BaseLevel::kExpert;
			break;
		case RE::LOCK_LEVEL::kVeryHard:
			lockLevel = BaseLevel::kMaster;
			break;
		case RE::LOCK_LEVEL::kRequiresKey:
			lockLevel = BaseLevel::kRequiresKey;
			break;
		}

		baseLevel = lockLevel;
	}
}
