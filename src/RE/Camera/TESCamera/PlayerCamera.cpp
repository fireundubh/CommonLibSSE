#include "RE/Camera/TESCamera/PlayerCamera.h"

#include "RE/Camera/TESCameraState/ThirdPersonState/ThirdPersonState.h"


namespace RE
{
	PlayerCamera* PlayerCamera::GetSingleton()
	{
		REL::Relocation<PlayerCamera**> singleton{ Offset::PlayerCamera::Singleton };
		return *singleton;
	}


	void PlayerCamera::EnterFirstPerson()
	{
		using func_t = decltype(&PlayerCamera::EnterFirstPerson);
		REL::Relocation<func_t> func{ REL::ID(49858) };
		return func(this);
	}


	void PlayerCamera::EnterThirdPerson()
	{
		auto currState = currentState.get();
		if (!currState || currState->id < 9) {
			if (auto state = static_cast<ThirdPersonState*>(cameraStates[CameraState::kThirdPerson].get()); state) {
				state->UpdateOffsets(false, false);
				SetState(state);
			}
		}
	}


	void PlayerCamera::EnterFreeCameraState(bool a_freezeTime)
	{
		using func_t = decltype(&PlayerCamera::EnterFreeCameraState);
		REL::Relocation<func_t> func{ REL::ID(49876) };
		return func(this, a_freezeTime);
	}


	void PlayerCamera::UpdateThirdPerson(bool a_weaponDrawn)
	{
		using func_t = decltype(&PlayerCamera::UpdateThirdPerson);
		REL::Relocation<func_t> func{ Offset::PlayerCamera::UpdateThirdPerson };
		return func(this, a_weaponDrawn);
	}
}
