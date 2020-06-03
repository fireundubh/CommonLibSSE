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
		virtual void Unk_04(void) override;	 // 04
		virtual void Unk_07(void) override;	 // 07
		virtual void Unk_08(void) override;	 // 08
		virtual void Unk_09(void) override;	 // 09
		virtual void Unk_0A(void) override;	 // 0A
		virtual void Unk_0D(void) override;	 // 0D
		virtual void Unk_12(void) override;	 // 12

		virtual ~SummonCreatureEffect();  // 13

		virtual void Unk_14(void) override;	 // 14
		virtual void Unk_15(void) override;	 // 15


		// members
		NiPoint3			   location;			   // 90
		NiPoint3			   angle;				   // 9C
		ActorHandle			   summonedActor;		   // A8
		UInt32				   unkAC;				   // AC
		SummonPlacementEffect* summonPlacementEffect;  // B0
		UInt8				   unkB8;				   // B8
		UInt8				   unkB9;				   // B9
		UInt8				   unkBA;				   // BA
		UInt8				   padBB;				   // BB
	};
	STATIC_ASSERT(sizeof(SummonCreatureEffect) == 0xC0);
}
