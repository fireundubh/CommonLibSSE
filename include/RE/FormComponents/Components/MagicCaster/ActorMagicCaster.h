#pragma once

#include "RE/Animation/IAnimationGraphManagerHolder/SimpleAnimationGraphManagerHolder/SimpleAnimationGraphManagerHolder.h"
#include "RE/BSCore/BSTEvent.h"
#include "RE/FormComponents/Components/MagicCaster/MagicCaster.h"
#include "RE/FormComponents/Enums/MagicSystem.h"
#include "RE/NetImmerse/Components/AttachTechniqueInput/RefAttachTechniqueInput.h"


namespace RE
{
	struct BSAnimationGraphEvent;
	class Actor;
	class BGSArtObject;
	class NiNode;
	class ReferenceEffectController;
	class TESObjectREFR;


	class ActorMagicCaster :
		public MagicCaster,							// 00
		public SimpleAnimationGraphManagerHolder,	// 48
		public BSTEventSink<BSAnimationGraphEvent>	// 60
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActorMagicCaster;


		virtual ~ActorMagicCaster();  // 00

		// override
		virtual void		   Unk_03(void) override;						 // 03
		virtual void		   Unk_04(void) override;						 // 04
		virtual void		   Unk_05(void) override;						 // 05
		virtual void		   Unk_06(void) override;						 // 06
		virtual void		   Unk_07(void) override;						 // 07 - { return; }
		virtual void		   Unk_08(void) override;						 // 08 - { return; }
		virtual void		   Unk_09(void) override;						 // 09 - { return; }
		virtual void		   Unk_0A(void) override;						 // 0A
		virtual TESObjectREFR* Unk_0B() override;							 // 0B - { return actor; }
		virtual Actor*		   GetCaster() override;						 // 0C - { return actor; }
		virtual NiNode*		   GetMagicNode() override;						 // 0E - { return magicNode; }
		virtual void		   ClearMagicNode() override;					 // 0F - { magicNode = 0; }
		virtual void		   Unk_10(void) override;						 // 10 - { return; }
		virtual void		   Unk_11(void) override;						 // 11 - { return; }
		virtual void		   Unk_12(void) override;						 // 12 - { return; }
		virtual void		   Unk_13(void) override;						 // 13 - { return; }
		virtual void		   CalculateMagickaCost() override;				 // 14
		virtual CastingSource  GetCastingSource() override;					 // 15 - { return castingSource; }
		virtual void		   Unk_16(void) override;						 // 16 - { return 0; }
		virtual void		   Unk_17(void) override;						 // 17 - { return; }
		virtual void		   SaveGame(BGSSaveGameBuffer* a_buf) override;	 // 18
		virtual void		   LoadGame(BGSLoadGameBuffer* a_buf) override;	 // 19
		virtual void		   Unk_1A(void) override;						 // 1A
		virtual void		   Unk_1B(void) override;						 // 1B
		virtual void		   Unk_1C(void) override;						 // 1C

		//add
		virtual void Unk_1D(void);	// 1D


		// members
		RefAttachTechniqueInput	   unk64;		   // 64
		UInt64					   unkB0;		   // B0
		Actor*					   actor;		   // B8
		NiNode*					   magicNode;	   // C0
		UInt64					   unkC8;		   // C8
		UInt64					   unkD0;		   // D0
		UInt64					   unkD8;		   // D8
		BGSArtObject*			   unkE0;		   // E0
		ReferenceEffectController* unkE8;		   // E8
		UInt32					   unkF0;		   // F0
		MagicSystem::CastingSource castingSource;  // F4
		UInt32					   unkF8;		   // F8
	};
	STATIC_ASSERT(sizeof(ActorMagicCaster) == 0x100);
}