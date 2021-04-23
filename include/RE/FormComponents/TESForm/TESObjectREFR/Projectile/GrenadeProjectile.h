#pragma once

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Projectile/Projectile.h"


namespace RE
{
	struct BGSDecalGroup;


	class GrenadeProjectile : public Projectile
	{
	public:
		inline static constexpr auto RTTI = RTTI_GrenadeProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileGrenade;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};


		virtual ~GrenadeProjectile();  // 00

		// override (Projectile)
		virtual void		   SaveGame(BGSSaveFormBuffer* a_buf) override;																																 // 0E
		virtual void		   LoadGame(BGSLoadFormBuffer* a_buf) override;																																 // 0F
		virtual void		   InitLoadGame(BGSLoadFormBuffer* a_buf) override;																															 // 10
		virtual void		   FinishLoadGame(BGSLoadFormBuffer* a_buf) override;																														 // 11
		virtual void		   Revert(BGSLoadFormBuffer* a_buf) override;																																 // 12
		virtual BGSDecalGroup* GetDecalGroup() const override;																																			 // 9F - { return decalGroup; }
		virtual void		   Unk_A3(void) override;																																					 // A3 - { return 1; }
		virtual void		   Unk_A8(void) override;																																					 // A8
		virtual void		   Unk_A9(void) override;																																					 // A9
		virtual void		   UpdateImpl(float a_delta) override;																																		 // AB
		virtual bool		   CanExplode() const override;																																				 // AE
		virtual void		   Unk_B2(void) override;																																					 // B2
		virtual void		   Unk_B3(void) override;																																					 // B3
		virtual bool		   IsNotGeneratedForm() const override;																																		 // B4
		virtual void		   Unk_BA(void) override;																																					 // BA - { return 1; }
		virtual std::uint32_t  GetCollisionFilter();																																					 // BB
		virtual void		   CreateImpactData(TESObjectREFR* a_ref, const NiPoint3& a_targetLoc, const NiPoint3& a_velocity, hkpCollidable* a_collidable, std::int32_t a_arg6, std::uint32_t a_arg7);	 // BD
		virtual void		   Unk_BF(void) override;																																					 // BF - { flags |= 1 << 30; }
		virtual void		   Handle3DLoaded() override;																																				 // C0


		// members
		BGSDecalGroup* decalGroup;			 // 1D8
		bool		   collisionGroupReset;	 // 1E0
		std::uint8_t   pad1E1;				 // 1E1
		std::uint16_t  pad1E2;				 // 1E2
		std::uint32_t  pad1E4;				 // 1E4
	};
	static_assert(sizeof(GrenadeProjectile) == 0x1E8);
}
