#pragma once

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"


namespace RE
{
	struct CombatStyleGeneralData  // CSGD
	{
		float offensiveMult;	   // 00
		float defensiveMult;	   // 04
		float groupOffensiveMult;  // 08
		float meleeScoreMult;	   // 0C
		float magicScoreMult;	   // 10
		float rangedScoreMult;	   // 14
		float shoutScoreMult;	   // 18
		float unarmedScoreMult;	   // 1C
		float staffScoreMult;	   // 20
		float avoidThreatChance;   // 24
	};
	STATIC_ASSERT(sizeof(CombatStyleGeneralData) == 0x28);


	struct CombatStyleMeleeData	 // CSME
	{
		float attackIncapacitatedMult;		 // 00
		float powerAttackIncapacitatedMult;	 // 04
		float powerAttackBlockingMult;		 // 08
		float bashMult;						 // 0C
		float bashRecoilMult;				 // 10
		float bashAttackMult;				 // 14
		float bashPowerAttackMult;			 // 18
		float specialAttackMult;			 // 1C
	};
	STATIC_ASSERT(sizeof(CombatStyleMeleeData) == 0x20);


	struct CombatStyleCloseRangeData  // CSCR
	{
		float circleMult;		  // 00
		float fallbackMult;		  // 04
		float flankDistanceMult;  // 08
		float stalkTimeMult;	  // 0C
	};
	STATIC_ASSERT(sizeof(CombatStyleCloseRangeData) == 0x10);


	struct CombatStyleLongRangeData	 // CSLR
	{
		float strafeMult;  // 0
	};
	STATIC_ASSERT(sizeof(CombatStyleLongRangeData) == 0x4);


	struct CombatStyleFlightData  // CSFL
	{
		float hoverChance;			 // 00
		float diveBombChance;		 // 04
		float groundAttackChance;	 // 08
		float hoverTimeMult;		 // 0C
		float groundAttackTimeMult;	 // 10
		float perchAttackChance;	 // 14
		float perchAttackTimeMult;	 // 18
		float flyingAttackChance;	 // 1C
	};
	STATIC_ASSERT(sizeof(CombatStyleFlightData) == 0x20);


	class TESCombatStyle : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESCombatStyle;
		inline static constexpr auto FORMTYPE = FormType::CombatStyle;


		enum class FLAG : UInt32  // DATA
		{
			kNone = 0,
			kDuelingStyle = 1 << 0,
			kFlankingStyle = 1 << 1,
			kAllowDualWielding = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kAllowDualWielding = 1 << 19
			};
		};


		virtual ~TESCombatStyle();	// 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		CombatStyleGeneralData	  generalData;	   // 20 - CSGD
		CombatStyleMeleeData	  meleeData;	   // 48 - CSME
		CombatStyleCloseRangeData closeRangeData;  // 68 - CSCR
		CombatStyleLongRangeData  longRangeData;   // 78 - CSLR
		CombatStyleFlightData	  flightData;	   // 7C - CSFL
		FLAG					  flags;		   // 9C - DATA
	};
	STATIC_ASSERT(sizeof(TESCombatStyle) == 0xA0);
}
