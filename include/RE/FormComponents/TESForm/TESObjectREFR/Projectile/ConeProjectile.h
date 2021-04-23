#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/BSHavok/hkRefPtr/hkRefPtr.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/Enums/ImpactResults.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Projectile/Projectile.h"
#include "RE/NetImmerse/NiPoint3.h"


namespace RE
{
	class hkpSphereShape;


	class ConeProjectile : public Projectile
	{
	public:
		inline static constexpr auto RTTI = RTTI_ConeProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileCone;


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};


		virtual ~ConeProjectile();	// 00

		// override (Projectile)
		virtual void			SaveGame(BGSSaveFormBuffer* a_buf) override;																															  // 0E
		virtual void			LoadGame(BGSLoadFormBuffer* a_buf) override;																															  // 0F
		virtual void			InitLoadGame(BGSLoadFormBuffer* a_buf) override;																														  // 10
		virtual void			FinishLoadGame(BGSLoadFormBuffer* a_buf) override;																														  // 11
		virtual void			Revert(BGSLoadFormBuffer* a_buf) override;																																  // 12
		virtual void			Unk_A9(void) override;																																					  // A9
		virtual void			UpdateImpl(float a_delta) override;																																		  // AB
		virtual void			Unk_AC(void) override;																																					  // AC
		virtual void			Unk_B8(void) override;																																					  // B8 - { return 0; }
		virtual bhkSphereShape* GetCollisionShape();																																					  // BC
		virtual void			CreateImpactData(TESObjectREFR* a_ref, const NiPoint3& a_targetLoc, const NiPoint3& a_velocity, hkpCollidable* a_collidable, std::int32_t a_arg6, std::uint32_t a_arg7);  // BD
		virtual void			ProcessHit(std::uint64_t a_arg1);																																		  // BE
		virtual void			Handle3DLoaded() override;																																				  // C0

		// add
		virtual void Unk_C2(void);	// C2 - { return 1; }

		float GetHeight() const;


		// members
		ImpactResult			 impactResult;					// 1D8
		float					 environmentTimer;				// 1DC
		float					 coneAngleTangent;				// 1E0
		float					 initialCollisionSphereRadius;	// 1E4
		NiPoint3				 origin;						// 1E8
		std::uint32_t			 pad1F4;						// 1F4
		hkRefPtr<hkpSphereShape> collisionShape;				// 1F8
		BSTArray<void*>			 collisions;					// 200
	};
	static_assert(sizeof(ConeProjectile) == 0x218);
}
