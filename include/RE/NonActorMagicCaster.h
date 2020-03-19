#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/ExtraMagicCaster.h"


namespace RE
{
	class TESObjectREFR;


	class NonActorMagicCaster : public ExtraMagicCaster
	{
	public:
		inline static constexpr auto RTTI = RTTI_NonActorMagicCaster;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMagicCaster;


		virtual ~NonActorMagicCaster();	 // 00

		// override (MagicCaster)
		virtual void		   Unk_01(void);						// 01
		virtual void		   Unk_07(void);						// 07 - { return; }
		virtual TESObjectREFR* Unk_0B();							// 0B - { return 0; }
		virtual Actor*		   GetCaster();							// 0C - { return 0; }
		virtual void		   Unk_0D(void);						// 0D
		virtual NiNode*		   GetMagicNode();						// 0E - { return 0; }
		virtual void		   SaveGame(BGSSaveGameBuffer* a_buf);	// 18
		virtual void		   LoadGame(BGSLoadGameBuffer* a_buf);	// 19


		// members
		TESObjectREFR* unk58;  // 58
		ActorHandle	   unk60;  // 60
		UInt32		   unk64;  // 64
	};
	STATIC_ASSERT(sizeof(NonActorMagicCaster) == 0x68);
}