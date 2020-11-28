#pragma once

#include "RE/FormComponents/Components/ActiveEffect/ActiveEffect.h"


namespace RE
{
	class SummonPlacementEffect;


	class SummonCreatureEffect : public ActiveEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_SummonCreatureEffect;


		// override (ActiveEffect)
		virtual void Unk_04(void) override;						   // 04
		virtual void Unk_07(void) override;						   // 07
		virtual void LoadGame(BGSSaveFormBuffer* a_buf) override;  // 08
		virtual void SaveGame(BGSLoadFormBuffer* a_buf) override;  // 09
		virtual void Unk_0A(void) override;						   // 0A
		virtual void Unk_0D(void) override;						   // 0D
		virtual void Unk_12(void) override;						   // 12

		virtual ~SummonCreatureEffect();  // 13

		virtual void Unk_14(void) override;	 // 14
		virtual void Unk_15(void) override;	 // 15


		// members
		NiPoint3			   location;			   // 90
		NiPoint3			   angle;				   // 9C
		ActorHandle			   summonedActor;		   // A8
		std::uint32_t		   unkAC;				   // AC
		SummonPlacementEffect* summonPlacementEffect;  // B0
		std::uint8_t		   unkB8;				   // B8
		std::uint8_t		   unkB9;				   // B9
		std::uint8_t		   unkBA;				   // BA
		std::uint8_t		   padBB;				   // BB
	};
	static_assert(sizeof(SummonCreatureEffect) == 0xC0);
}
