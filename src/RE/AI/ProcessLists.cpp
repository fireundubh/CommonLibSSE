#include "RE/AI/ProcessLists.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/TESObjectREFR.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/ReferenceEffect/ReferenceEffect.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/TempEffectTraits.h"


namespace RE
{
	ProcessLists* ProcessLists::GetSingleton()
	{
		REL::Relocation<ProcessLists**> singleton{ REL::ID(514167) };
		return *singleton;
	}


	void ProcessLists::ClearCachedFactionFightReactions() const
	{
		using func_t = decltype(&ProcessLists::ClearCachedFactionFightReactions);
		REL::Relocation<func_t> func{ REL::ID(40396) };
		return func(this);
	}


	void ProcessLists::GetMagicEffects(std::function<bool(BSTempEffect* a_tempEffect)> a_fn)
	{
		BSSpinLockGuard locker(magicEffectsLock);

		for (auto& tempEffectPtr : magicEffects) {
			auto tempEffect = tempEffectPtr.get();
			if (tempEffect && !a_fn(tempEffect)) {
				break;
			}
		}
	}


	void ProcessLists::StopCombatAndAlarmOnActor(Actor* a_actor, bool a_notAlarm)
	{
		using func_t = decltype(&ProcessLists::StopCombatAndAlarmOnActor);
		REL::Relocation<func_t> func{ REL::ID(40330) };
		return func(this, a_actor, a_notAlarm);
	}


	void ProcessLists::StopAllShaders(TESObjectREFR* a_ref)
	{
		GetMagicEffects([&](BSTempEffect* a_tempEffect) {
			auto referenceEffect = a_tempEffect->As<ReferenceEffect>();
			if (referenceEffect) {
				auto handle = a_ref->CreateRefHandle();
				if (referenceEffect->target == handle) {
					referenceEffect->finished = true;
					referenceEffect->Clear();
				}
			}
			return true;
		});
	}

}
