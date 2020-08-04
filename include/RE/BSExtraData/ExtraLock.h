#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/FormComponents/Enums/FormTypes.h"


namespace RE
{
	enum class LOCK_LEVEL
	{
		kUnlocked = static_cast<std::underlying_type_t<LOCK_LEVEL>>(-1),
		kVeryEasy = 0,
		kEasy = 1,
		kAverage = 2,
		kHard = 3,
		kVeryHard = 4,
		kRequiresKey = 5
	};


	struct REFR_LOCK
	{
		enum class BaseLevel
		{
			kNovice = 1,
			kApprentice = 25,
			kAdept = 50,
			kExpert = 75,
			kMaster = 100,
			kRequiresKey = 255
		};


		enum class Flag
		{
			kNone = 0,
			kLocked = 1 << 0,
			kLeveled = 1 << 2
		};

		REFR_LOCK();
		REFR_LOCK(BaseLevel a_lockType);
		~REFR_LOCK() = default;

		TES_HEAP_REDEFINE_NEW();

		LOCK_LEVEL	   GetLockLevel(const TESObjectREFR* a_containerRef) const;
		constexpr bool IsLocked() const noexcept { return flags.all(Flag::kLocked); }
		void		   SetLocked(bool a_locked);
		void		   SetBaseLevel(LOCK_LEVEL a_lockLevel);


		// members
		stl::enumeration<BaseLevel, std::uint8_t> baseLevel;  // 00
		std::uint8_t							  pad01;	  // 01
		std::uint16_t							  pad02;	  // 02
		std::uint32_t							  pad04;	  // 04
		TESKey*									  key;		  // 08
		stl::enumeration<Flag, std::uint8_t>	  flags;	  // 10
		std::uint8_t							  pad11;	  // 11
		std::uint16_t							  pad12;	  // 12
		std::uint32_t							  numTries;	  // 14
		std::uint32_t							  unk18;	  // 18
		std::uint32_t							  pad1C;	  // 1C
	};
	static_assert(sizeof(REFR_LOCK) == 0x20);


	class ExtraLock : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLock;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLock;


		ExtraLock();
		virtual ~ExtraLock() = default;	 // 00

		TES_HEAP_REDEFINE_NEW();

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kLock; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		REFR_LOCK* lock;  // 10
	};
	static_assert(sizeof(ExtraLock) == 0x18);
}
