#include "RE/BSDevices/ControlMap.h"

#include "RE/Events/UserEventEnabled.h"


namespace RE
{
	ControlMap* ControlMap::GetSingleton()
	{
		REL::Offset<ControlMap**> singleton(Offset::ControlMap::Singleton);
		return *singleton;
	}


	SInt8 ControlMap::AllowTextInput(bool a_allow)
	{
		if (a_allow) {
			if (textEntryCount != -1) {
				++textEntryCount;
			}
		} else {
			if (textEntryCount != 0) {
				--textEntryCount;
			}
		}

		return textEntryCount;
	}


	bool ControlMap::AreControlsEnabled(UEFlag a_flags) const
	{
		return (enabledControls & a_flags) == a_flags;
	}


	UInt32 ControlMap::GetMappedKey(const std::string_view& a_eventID, INPUT_DEVICE a_device, InputContextID a_context) const
	{
		assert(a_device < INPUT_DEVICE::kTotal);
		assert(a_context < InputContextID::kTotal);

		auto mappings =
			controlMap[a_context] ?
				std::addressof(controlMap[a_context]->deviceMappings[a_device]) :
				nullptr;

		if (mappings) {
			BSFixedString eventID = a_eventID;
			for (auto& mapping : *mappings) {
				if (mapping.eventID == eventID) {
					return mapping.inputKey;
				}
			}
		}

		return kInvalid;
	}


	std::string_view ControlMap::GetUserEventName(UInt32 a_buttonID, INPUT_DEVICE a_device, InputContextID a_context) const
	{
		assert(a_device < INPUT_DEVICE::kTotal);
		assert(a_context < InputContextID::kTotal);

		auto mappings =
			controlMap ?
				std::addressof(controlMap[a_context]->deviceMappings[a_device]) :
				nullptr;

		if (mappings) {
			for (auto& mapping : *mappings) {
				if (mapping.inputKey == a_buttonID) {
					return mapping.eventID;
				}
			}
		}

		return "";
	}


	bool ControlMap::IsActivateControlsEnabled() const
	{
		return (enabledControls & UEFlag::kActivate) != UEFlag::kNone;
	}


	bool ControlMap::IsConsoleControlsEnabled() const
	{
		return (enabledControls & UEFlag::kConsole) != UEFlag::kNone;
	}


	bool ControlMap::IsFightingControlsEnabled() const
	{
		return (enabledControls & UEFlag::kFighting) != UEFlag::kNone;
	}


	bool ControlMap::IsLookingControlsEnabled() const
	{
		return (enabledControls & UEFlag::kLooking) != UEFlag::kNone;
	}


	bool ControlMap::IsMenuControlsEnabled() const
	{
		return (enabledControls & UEFlag::kMenu) != UEFlag::kNone;
	}


	bool ControlMap::IsMainFourControlsEnabled() const
	{
		return (enabledControls & UEFlag::kMainFour) != UEFlag::kNone;
	}


	bool ControlMap::IsMovementControlsEnabled() const
	{
		return (enabledControls & UEFlag::kMovement) != UEFlag::kNone;
	}


	bool ControlMap::IsPOVSwitchControlsEnabled() const
	{
		return (enabledControls & UEFlag::kPOVSwitch) != UEFlag::kNone;
	}


	bool ControlMap::IsSneakingControlsEnabled() const
	{
		return (enabledControls & UEFlag::kSneaking) != UEFlag::kNone;
	}


	bool ControlMap::IsVATSControlsEnabled() const
	{
		return (enabledControls & UEFlag::kVATS) != UEFlag::kNone;
	}


	bool ControlMap::IsWheelZoomControlsEnabled() const
	{
		return (enabledControls & UEFlag::kWheelZoom) != UEFlag::kNone;
	}


	void ControlMap::ToggleControls(UEFlag a_flags, bool a_enable)
	{
		auto oldState = enabledControls;

		if (a_enable) {
			enabledControls |= a_flags;
			if (unk11C != UEFlag::kInvalid) {
				unk11C |= a_flags;
			}
		} else {
			enabledControls &= ~a_flags;
			if (unk11C != UEFlag::kInvalid) {
				unk11C &= ~a_flags;
			}
		}

		UserEventEnabled event(oldState, enabledControls);
		SendEvent(&event);
	}
}
