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


	void ProcessLists::ClearTempEffect(BSTempEffect* a_tempEffect)
	{
		using func_t = decltype(&ProcessLists::ClearTempEffect);
		REL::Relocation<func_t> func{ REL::ID(40373) };
		return func(this, a_tempEffect);
	}


	void ProcessLists::GetMagicEffects(std::function<bool(BSTempEffect& a_tempEffect)> a_fn)
	{
		BSSpinLockGuard locker(magicEffectsLock);

		for (auto& tempEffectPtr : magicEffects) {
			const auto& tempEffect = tempEffectPtr.get();
			if (tempEffect && !a_fn(*tempEffect)) {
				break;
			}
		}
	}


	void ProcessLists::GetGlobalEffects(std::function<bool(BSTempEffect& a_tempEffect)> a_fn)
	{
		BSSpinLockGuard locker(globalEffectsLock);

		for (auto& tempEffectPtr : globalTempEffects) {
			const auto& tempEffect = tempEffectPtr.get();
			if (tempEffect && !a_fn(*tempEffect)) {
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


	void ProcessLists::StopAllShaders(TESObjectREFR& a_ref)
	{
		auto handle = a_ref.CreateRefHandle();
		GetMagicEffects([&](RE::BSTempEffect& a_tempEffect) {
			auto referenceEffect = a_tempEffect.As<ReferenceEffect>();
			if (referenceEffect && referenceEffect->target == handle) {
				referenceEffect->finished = true;
			}
			return true;
		});
	}
}
