#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTList.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/FormComponents/Components/EffectArchetypes.h"
#include "RE/FormComponents/Enums/MagicSystem.h"
#include "RE/NetImmerse/NiPoint3.h"


namespace RE
{
	class Actor;
	class ActiveEffect;
	struct Effect;
	class EffectItem;
	class EffectSetting;
	class MagicItem;
	class TESBoundObject;
	class TESObjectREFR;


	class MagicTarget
	{
	public:
		inline static constexpr auto RTTI = RTTI_MagicTarget;


		using Archetype = EffectArchetypes::ArchetypeID;


		class ForEachActiveEffectVisitor
		{
		public:
			inline static constexpr auto RTTI = RTTI_MagicTarget__ForEachActiveEffectVisitor;


			virtual ~ForEachActiveEffectVisitor();	// 00

			// add
			virtual bool Accept(ActiveEffect* a_effect) = 0;  // 01
		};
		static_assert(sizeof(ForEachActiveEffectVisitor) == 0x8);


		struct SpellDispelData
		{
			MagicItem*					  spell;		 // 00
			BSPointerHandle<Actor>		  caster;		 // 08
			std::uint32_t				  pad0C;		 // 0C
			BSTSmartPointer<ActiveEffect> activeEffect;	 // 10
			SpellDispelData*			  next;			 // 18
		};
		static_assert(sizeof(SpellDispelData) == 0x20);


		struct CreationData
		{
			TESObjectREFR*			   caster;			// 00
			MagicItem*				   magicItem;		// 08
			Effect*					   effect;			// 10
			TESBoundObject*			   source;			// 18
			std::uint64_t			   unk20;			// 20 - MagicCaster::PostCreationCallback
			std::uint64_t			   unk28;			// 28 - MagicTarget**
			NiPoint3				   explosionPoint;	// 30
			float					   magnitude;		// 3C
			float					   unk40;			// 40
			MagicSystem::CastingSource castingSource;	// 44
			std::uint8_t			   unk48;			// 48
			bool					   dualCasted;		// 49
			std::uint16_t			   pad4A;			// 4A
			std::uint32_t			   pad4C;			// 4C
		};
		static_assert(sizeof(CreationData) == 0x50);


		virtual ~MagicTarget();	 // 00

		// add
		virtual void						 Unk_01(void);																		   // 01
		virtual TESObjectREFR*				 GetTargetStatsObject();															   // 02 - { return false; }
		virtual bool						 MagicTargetIsActor() const;														   // 03 - { return false; }
		virtual bool						 IsInvulnerable();																	   // 04 - { return false; }
		virtual void						 InvalidateCommandedActorEffect(ActiveEffect* a_effect);							   // 05 - { return; }
		virtual bool						 CanAddActiveEffect() = 0;															   // 06
		virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList() = 0;															   // 07
		virtual void						 Unk_08(void);																		   // 08 - { return; }
		virtual void						 Unk_09(void);																		   // 09 - { return; }
		virtual float						 CheckResistance(MagicItem* a_magicItem, Effect* a_effect, TESBoundObject* a_object);  // 0A - { return 1.0; }
		virtual void						 CheckAbsorb(Actor* a_actor, MagicItem* a_magicItem, const Effect* a_effect);		   // 0B - { return false; }

		void DispelEffectsWithArchetype(Archetype a_type, bool a_force);
		bool HasEffectWithArchetype(Archetype a_type);
		bool HasMagicEffect(EffectSetting* a_effect);


		// members
		SpellDispelData* postUpdateDispelList;	// 08
		std::uint8_t	 flags;					// 10
		std::uint8_t	 pad11;					// 11
		std::uint16_t	 pad12;					// 12
		std::uint32_t	 pad14;					// 14
	};
	static_assert(sizeof(MagicTarget) == 0x18);
}
