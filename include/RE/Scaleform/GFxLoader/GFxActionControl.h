#pragma once

#include "RE/Scaleform/GFxLoader/GFxState.h"


namespace RE
{
	class GFxActionControl : public GFxState
	{
	public:
		enum class ActionControlFlags
		{
			kNone = 0,
			kVerbose = 1 << 0,
			kSuppressErrors = 1 << 1,
			kLogRootFilenames = 1 << 2,	  // Display filename for root movie
			kLogChildFilenames = 1 << 3,  // Display filename for child movie
			kLongFilenames = 1 << 4		  // Display full path
		};


		inline GFxActionControl(ActionControlFlags a_actionFlags = ActionControlFlags::kLogChildFilenames) :
			GFxState(StateType::kActionControl),
			actionFlags(a_actionFlags),
			pad1C(0)
		{}


		constexpr ActionControlFlags GetFlags() const { return *actionFlags; }
		constexpr void				 SetFlags(ActionControlFlags a_actionFlags) { actionFlags = a_actionFlags; }

		constexpr void SetVerboseLogging() { actionFlags |= ActionControlFlags::kVerbose; }
		constexpr void UnsetVerboseLogging() { actionFlags &= ~ActionControlFlags::kVerbose; }

		constexpr void SetErrorSuppression() { actionFlags |= ActionControlFlags::kSuppressErrors; }
		constexpr void UnsetErrorSuppression() { actionFlags &= ~ActionControlFlags::kSuppressErrors; }

		constexpr void SetRootFilenameLogging() { actionFlags |= ActionControlFlags::kLogRootFilenames; }
		constexpr void UnsetRootFilenameLogging() { actionFlags &= ~ActionControlFlags::kLogRootFilenames; }

		constexpr void SetChildFilenameLogging() { actionFlags |= ActionControlFlags::kLogChildFilenames; }
		constexpr void UnsetChildFilenameLogging() { actionFlags &= ~ActionControlFlags::kLogChildFilenames; }

		constexpr void SetAllFilenameLogging() { actionFlags |= (ActionControlFlags::kLogRootFilenames | ActionControlFlags::kLogChildFilenames); }
		constexpr void UnsetAllFilenameLogging() { actionFlags &= ~(ActionControlFlags::kLogRootFilenames | ActionControlFlags::kLogChildFilenames); }

		constexpr void SetLongFilenameLogging() { actionFlags |= ActionControlFlags::kLongFilenames; }
		constexpr void UnsetLongFilenameLogging() { actionFlags &= ~ActionControlFlags::kLongFilenames; }


		// members
		stl::enumeration<ActionControlFlags, std::uint32_t> actionFlags;  // 18
		std::uint32_t										pad1C;		  // 1C
	};
	static_assert(sizeof(GFxActionControl) == 0x20);
}
