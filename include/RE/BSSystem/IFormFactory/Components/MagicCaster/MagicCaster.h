#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/BSSoundHandle.h"


namespace RE
{
	class MagicItem;
	class BGSSaveGameBuffer;
	class BGSLoadGameBuffer;
	class NiNode;
	class TESObjectREFR;


	class MagicCaster
	{
	public:
		inline static constexpr auto RTTI = RTTI_MagicCaster;


		enum class State : UInt32
		{
		};

		using CastingSource = MagicSystem::CastingSource;

		virtual ~MagicCaster();	 // 00

		// add
		virtual void		   Unk_01(void);						// 01
		virtual void		   Unk_02(void);						// 02
		virtual void		   Unk_03(void);						// 03
		virtual void		   Unk_04(void);						// 04
		virtual void		   Unk_05(void);						// 05
		virtual void		   Unk_06(void);						// 06
		virtual void		   Unk_07(void);						// 07 - { return; }
		virtual void		   Unk_08(void);						// 08 - { return; }
		virtual void		   Unk_09(void);						// 09 - { return; }
		virtual void		   Unk_0A(void);						// 0A
		virtual TESObjectREFR* Unk_0B();							// 0B - { return 0; }
		virtual Actor*		   GetCaster();							// 0C - { return 0; }
		virtual void		   Unk_0D(void);						// 0D
		virtual NiNode*		   GetMagicNode();						// 0E - { return 0; }
		virtual void		   ClearMagicNode();					// 0F - { return; }
		virtual void		   Unk_10(void);						// 10 - { return; }
		virtual void		   Unk_11(void);						// 11 - { return; }
		virtual void		   Unk_12(void);						// 12 - { return; }
		virtual void		   Unk_13(void);						// 13 - { return; }
		virtual void		   CalculateMagickaCost();				// 14
		virtual CastingSource  GetCastingSource();					// 15 - { return 0; }
		virtual void		   Unk_16(void);						// 16 - { return 0; }
		virtual void		   Unk_17(void);						// 17 - { return; }
		virtual void		   SaveGame(BGSSaveGameBuffer* a_buf);	// 18
		virtual void		   LoadGame(BGSLoadGameBuffer* a_buf);	// 19
		virtual void		   Unk_1A(void);						// 1A
		virtual void		   Unk_1B(void);						// 1B
		virtual void		   Unk_1C(void);						// 1C


		// members
		BSTArray<BSSoundHandle> sounds;				// 08
		ObjectRefHandle			desiredTarget;		// 20
		UInt32					pad24;				// 24
		MagicItem*				currentSpell;		// 28
		State					state;				// 30
		float					castingTimer;		// 34
		float					currentSpellCost;	// 38
		float					magnitudeOverride;	// 3C
		float					nextTargetUpdate;	// 40
		float					projectileTimer;	// 44
	};
	STATIC_ASSERT(sizeof(MagicCaster) == 0x48);
}