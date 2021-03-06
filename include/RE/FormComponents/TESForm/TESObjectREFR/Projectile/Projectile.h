#pragma once

#include "RE/BSAudio/BSSoundHandle.h"
#include "RE/BSCore/BSAtomic.h"
#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTList.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/Enums/ImpactResults.h"
#include "RE/FormComponents/Enums/MagicSystem.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/TESObjectREFR.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/NetImmerse/NiTransform.h"


namespace RE
{
	class BGSExplosion;
	class BGSMaterialType;
	class bhkCollisionObject;
	class bhkSimpleShapePhantom;
	class bhkSphereShape;
	class EffectSetting;
	class hkpCollidable;
	class MagicItem;
	class QueuedFile;


	class Projectile : public TESObjectREFR
	{
	public:
		inline static constexpr auto RTTI = RTTI_Projectile;


		enum class Flags
		{
			kNone = 0,
			kHasTrails = 1 << 18,
			kDisabled = 1 << 25,
			kUsesDualCastImpactDataSet = 1 << 28
		};


		struct ImpactData
		{
		public:
			// members
			NiPoint3					  desiredTargetLoc;	   // 00
			NiPoint3					  negativeVelocity;	   // 0C
			ObjectRefHandle				  collidee;			   // 18
			NiPointer<bhkCollisionObject> colObj;			   // 20
			BGSMaterialType*			  material;			   // 28
			std::int32_t				  damageRootNodeType;  // 30
			std::uint32_t				  unk34;			   // 34
			NiNode*						  damageRootNode;	   // 38
			ImpactResult				  impactResult;		   // 40
			std::uint16_t				  unk44;			   // 44
			std::uint16_t				  unk46;			   // 46
			std::uint8_t				  unk48;			   // 48
			std::uint8_t				  unk49;			   // 49
		};
		static_assert(sizeof(ImpactData) == 0x50);


		virtual ~Projectile();	// 00

		// override (TESObjectREFR)
		virtual bool		 Load(TESFile* a_mod) override;											// 06 - { return TESObjectREFR::Load(a_mod); }
		virtual void		 SaveGame(BGSSaveFormBuffer* a_buf) override;							// 0E
		virtual void		 LoadGame(BGSLoadFormBuffer* a_buf) override;							// 0F
		virtual void		 InitLoadGame(BGSLoadFormBuffer* a_buf) override;						// 10
		virtual void		 FinishLoadGame(BGSLoadFormBuffer* a_buf) override;						// 11
		virtual void		 Revert(BGSLoadFormBuffer* a_buf) override;								// 12
		virtual bool		 GetAllowPromoteToPersistent() const override;							// 47 - { return false; }
		virtual bool		 HasKeywordHelper(const BGSKeyword* a_keyword) const override;			// 48
		virtual void		 SetActorCause(ActorCause* a_cause) override;							// 50 - { actorCause = a_cause; }
		virtual ActorCause*	 GetActorCause() const override;										// 51 - { return actorCause; }
		virtual MagicCaster* GetMagicCaster(MagicSystem::CastingSource a_source) override;			// 5C
		virtual bool		 DetachHavok(NiAVObject* a_obj3D) override;								// 65
		virtual void		 InitHavok() override;													// 66
		virtual NiAVObject*	 Load3D(bool a_backgroundLoading) override;								// 6A
		virtual void		 Set3D(NiAVObject* a_object, bool a_queue3DTasks = true) override;		// 6C
		virtual void		 MoveHavok(bool a_forceRec) override;									// 85 - { return; }
		virtual void		 GetLinearVelocity(NiPoint3& a_velocity) const override;				// 86
		virtual NiNode*		 GetWeaponBone() override;												// 8B
		virtual Projectile*	 AsProjectile() override;												// 8F - { return this; }
		virtual bool		 OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const override;	// 90 - { return false; }

		// add
		virtual void			Unk_A2(void);																																							  // A2 - { return 0; }
		virtual void			Unk_A3(void);																																							  // A3 - { return 0; }
		virtual void			Unk_A4(void);																																							  // A4 - { return 0; }
		virtual void			Unk_A5(void);																																							  // A5 - { return 0; }
		virtual void			Unk_A6(void);																																							  // A6 - { return 0; }
		virtual void			Unk_A7(void);																																							  // A7 - { return 0; }
		virtual void			Unk_A8(void);																																							  // A8 - { return; }
		virtual void			Unk_A9(void);																																							  // A9 - { return; }
		virtual void			Unk_AA(void);																																							  // AA
		virtual void			UpdateImpl(float a_delta) = 0;																																			  // AB
		virtual void			Unk_AC(void);																																							  // AC
		virtual void			Unk_AD(void);																																							  // AD
		virtual bool			CanExplode() const;																																						  // AE - { return 0; }
		virtual float			GetPower() const;																																						  // AF - { if (unk158) return 1.0; else return unk188; } - "float GetSpeed()"?
		virtual void			Unk_B0(void);																																							  // B0 - { return 1.0; }
		virtual void			Unk_B1(void);																																							  // B1 - { return 0; }
		virtual void			Unk_B2(void);																																							  // B2 - { return; }
		virtual void			Unk_B3(void);																																							  // B3
		virtual bool			IsNotGeneratedForm() const;																																				  // B4 - { return TESDataHandler::GetSingleton()->IsGeneratedFormID(formID) == 0; }
		virtual float			GetGravity() const;																																						  // B5 - { BGSProjectile* var = objectReference; if ((var->flags >> 17) & 1) return 1.0; else return var->gravity; }
		virtual void			ClearData(void);																																						  // B6
		virtual void			Unk_B7(void);																																							  // B7
		virtual void			Unk_B8(void);																																							  // B8 - { return 1; }
		virtual void			Unk_B9(void);																																							  // B9 - { return 0; }
		virtual void			Unk_BA(void);																																							  // BA - { return 0; }
		virtual std::uint32_t	GetCollisionFilter() const;																																				  // BB
		virtual bhkSphereShape* GetCollisionShape() const;																																				  // BC
		virtual void			CreateImpactData(TESObjectREFR* a_ref, const NiPoint3& a_targetLoc, const NiPoint3& a_velocity, hkpCollidable* a_collidable, std::int32_t a_arg6, std::uint32_t a_arg7);  // BD
		virtual void			ProcessHit(std::uint64_t a_arg1);																																		  // BE
		virtual void			Unk_BF(void);																																							  // BF - { return; }
		virtual void			Handle3DLoaded();																																						  // C0 - { return; }
		virtual bool			GetPlayerIsShooter() const;																																				  // C1 - { return 0; }

		float GetHeight() const;


		// members
		BSSimpleList<ImpactData*>			   impacts;			   // 098
		NiTransform							   unk0A8;			   // 0A8
		float								   unk0DC;			   // 0DC
		bhkSimpleShapePhantom*				   unk0E0;			   // 0E0 - smart ptr
		mutable BSSpinLock					   lock;			   // 0E8
		NiPoint3							   velocity;		   // 0F0
		NiPoint3							   linearVelocity;	   // 0FC
		void*								   unk108;			   // 108 - smart ptr
		void*								   unk110;			   // 110 - smart ptr
		NiPointer<ActorCause>				   actorCause;		   // 118
		ObjectRefHandle						   shooter;			   // 120
		ObjectRefHandle						   desiredTarget;	   // 124
		BSSoundHandle						   sndHandle;		   // 128
		BSSoundHandle						   sndCountdown;	   // 134
		std::uint32_t*						   unk140;			   // 140
		InventoryEntryData*					   unk148;			   // 148
		BGSExplosion*						   explosion;		   // 150
		MagicItem*							   spell;			   // 158
		MagicSystem::CastingSource			   castingSource;	   // 160
		std::uint32_t						   pad164;			   // 164
		EffectSetting*						   avEffect;		   // 168
		NiPointer<QueuedFile>				   projectileDBFiles;  // 170
		std::uint64_t						   unk178;			   // 178
		std::uint64_t						   unk180;			   // 180
		float								   power;			   // 188
		float								   unk18C;			   // 18C
		float								   range;			   // 190
		float								   lifeRemaining;	   // 194
		float								   unk198;			   // 198
		float								   unk19C;			   // 19C
		float								   explosionTimer;	   // 1A0
		float								   minesBlinkRate;	   // 1A4
		std::uint32_t						   unk1A8;			   // 1A8
		std::uint32_t						   unk1AC;			   // 1AC
		TESObjectWEAP*						   weaponSource;	   // 1B0
		TESAmmo*							   ammoSource;		   // 1B8
		float								   distanceMoved;	   // 1C0
		std::uint32_t						   unk1C4;			   // 1C4
		float								   unk1C8;			   // 1C8
		stl::enumeration<Flags, std::uint32_t> flags;			   // 1CC
		std::uint64_t						   unk1D0;			   // 1D0
	};
	static_assert(sizeof(Projectile) == 0x1D8);
}
