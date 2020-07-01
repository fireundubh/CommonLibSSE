#include "RE/AI/ProcessLists.h"


namespace RE
{
	ProcessLists* ProcessLists::GetSingleton()
	{
		REL::Offset<ProcessLists**> singleton(Offset::ProcessLists::Singleton);
		return *singleton;
	}


	void ProcessLists::GetMagicEffects(std::function<bool(RE::BSTempEffect* a_tempEffect)> a_fn)
	{
		magicEffectsLock.Lock();
		for (auto& tempEffectPtr : magicEffects) {
			auto tempEffect = tempEffectPtr.get();
			if (tempEffect) {
				if (!a_fn(tempEffect)) {
					break;
				}
			}
		}
		magicEffectsLock.Unlock();
	}


	void ProcessLists::StopCombatAndAlarmOnActor(Actor* a_actor, bool a_dontEndAlarm)
	{
		using func_t = decltype(&ProcessLists::StopCombatAndAlarmOnActor);
		REL::Offset<func_t> func(Offset::ProcessLists::StopCombatAndAlarmOnActor);
		return func(this, a_actor, a_dontEndAlarm);
	}

}
